///////////////////////////////////////////////////////////
//  ContactResolverGroup.cpp
//  Created on:      26-03-2009
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <ContactResolverGroup.h>
using namespace Regina;


//*****************************************************************************

CContactResolverGroup::~CContactResolverGroup()
{
for(unsigned i=0; i<contact.size(); i++)
delete contact[i];

for(unsigned i=0; i<immovableContact.size(); i++)
delete immovableContact[i];
}

//*****************************************************************************

void CContactResolverGroup::Add(CContactData* iContact)
{
vector<unsigned> vec;
iContact->FillAdditionalDependencys(vec); 
for(unsigned i=0; i<vec.size(); i++)
id.insert(vec[i]);

if(iContact->Immovable() == true) immovableContact.push_back(iContact);
else							  contact.push_back(iContact);
}

//*****************************************************************************

void CContactResolverGroup::Transfer(CContactResolverGroup* iContactResolverGroup)
{
for(unsigned i=0; i<iContactResolverGroup->contact.size(); i++)
contact.push_back(iContactResolverGroup->contact[i]);

for(unsigned i=0; i<iContactResolverGroup->immovableContact.size(); i++)
immovableContact.push_back(iContactResolverGroup->immovableContact[i]);

set<unsigned>::iterator it = iContactResolverGroup->id.begin();
while(it!=iContactResolverGroup->id.end())
	{
	id.insert(*it);
	it++;
	}

iContactResolverGroup->contact.clear();
iContactResolverGroup->immovableContact.clear();
iContactResolverGroup->id.clear();
}

//*****************************************************************************

bool CContactResolverGroup::ExistID(unsigned iID)
{
if(id.size()>0)
if(id.find(iID) == id.end()) return false;
return true;
}

//*****************************************************************************

void CContactResolverGroup::Resolve(float iDuration)
{
ResolveImmovable(iDuration);
ResolveVelocity(iDuration);
ResolveInterpenetration(iDuration);
}

//*****************************************************************************

void CContactResolverGroup::ResolveInterpenetration(float iDuration)
{
unsigned penPerGroup=0;
unsigned maxPerGroup = min(maxPenetrationIterations, maxPenetrationIterationsPerObject*(contact.size()/* + immovableContact.size()*/));
if(contact.size() == 1)
	maxPerGroup = 1;

while(penPerGroup < maxPerGroup )
	{
	float highestInter = 0;
	int highestInterID = -1;

	for(unsigned i=0; i<contact.size(); i++)
		{
		float tInter = contact[i]->CalculateIterpenetration();
		if(tInter > highestInter)
			{
			highestInter = tInter;
			highestInterID = i;
			}
		}

	if(highestInter < 0.000001f ||  highestInterID == -1) return;
	contact[highestInterID]->ResolveInterpenetration(iDuration);

	penPerGroup++;
	}
}

//*****************************************************************************

void CContactResolverGroup::ResolveVelocity(float iDuration)
{
unsigned velPerGroup=0;
unsigned maxPerGroup = min(maxVelocityIterations, maxVelocityIterationsPerObject*(contact.size()/* + immovableContact.size()*/));
if(contact.size() == 1)
	maxPerGroup = 1;

while(velPerGroup < maxPerGroup)
	{
	float lowestSepVel = 0;
	int lowestSepVelID = -1;

	for(unsigned i=0; i<contact.size(); i++)
		{
		float tSepVelo = contact[i]->CalculateSeparatingVelocity();
		if(tSepVelo < lowestSepVelID)
			{
			lowestSepVel = tSepVelo;
			lowestSepVelID = i;
			}
		}

    if(lowestSepVel >= -0.000001f ||  lowestSepVelID == -1) return;
	contact[lowestSepVelID]->ResolveVelocity(iDuration);
	velPerGroup++;
	}
}

//*****************************************************************************

void CContactResolverGroup::ResolveImmovable(float iDuration)
{
RemoveDuplicatesInRemovible();

for(unsigned i=0; i<immovableContact.size(); i++)
	{
	immovableContact[i]->Resolve(iDuration);

	vector<unsigned> vec1;
	immovableContact[i]->FillAdditionalDependencys(vec1); 
	assert(vec1.size()==1);

	for(unsigned ii=0; ii<contact.size(); ii++)
		{
		CContactData* imm = contact[ii]->GetImmovableVersion(vec1[0]);
		if(imm!=NULL)
			{
			delete contact[ii];
			contact[ii] = imm;
			}
		}
	}
}

//*****************************************************************************

void CContactResolverGroup::RemoveDuplicatesInRemovible()
{
for(unsigned i=0; i<immovableContact.size(); i++)
for(unsigned ii=i+1; ii<immovableContact.size(); ii++)
	{
	vector<unsigned> vec1;
	immovableContact[i]->FillAdditionalDependencys(vec1); 
	assert(vec1.size()==1);

	vector<unsigned> vec2;
	immovableContact[ii]->FillAdditionalDependencys(vec2); 
	assert(vec2.size()==1);

	if(vec1[0] == vec2[0])
		{
		if(immovableContact[i]->CalculateIterpenetration()>immovableContact[ii]->CalculateIterpenetration())
			{
			delete immovableContact[ii];
			immovableContact[ii] = immovableContact[immovableContact.size()-1];
			immovableContact.pop_back();
			continue;
			}
		else
			{
			delete immovableContact[i];
			immovableContact[i] = immovableContact[immovableContact.size()-1];
			immovableContact.pop_back();
			i--; 
			break;
			}
		}
	}

}

//*****************************************************************************