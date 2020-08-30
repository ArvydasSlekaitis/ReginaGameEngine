///////////////////////////////////////////////////////////
//  ContactResolver.cpp
//  Created on:      12-03-2009
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <ContactResolver.h>
using namespace Regina;



//*****************************************************************************
void CContactResolver::Resolve(float iDuration)
{
HANDLE resovleImmovableHandler;

if(singleImmovableContact.size()>0)
	resovleImmovableHandler = CreateThread(this, &CContactResolver::ResolveSingleImmovableContacts, iDuration);

for(unsigned ii = 0; ii<group.size(); ii++)
	if(group[ii]==NULL)
	{
	assert(ii<group.size());
	group[ii]=group[group.size()-1];
	group.pop_back();

	if(group.size()==0) return;
	ii--;
	}

for(unsigned ii = 0; ii<group.size(); ii++)
	{
	unsigned maxVelocityIterations = Settings->GetParameter("MaxContactResolverVelocityIterations");
	unsigned maxPenetrationIterations = Settings->GetParameter("MaxContactResolverPenetrationIterations");
	group[ii]->SetMaxVelocityIterations(max(1, maxVelocityIterations/group.size()));
	group[ii]->SetMaxPenetrationIterations(max(1, maxPenetrationIterations/group.size()));
	}

unsigned i=0;
if(group.size()%2 != 0)
	{
	group[0]->Resolve(iDuration);
	i=1;
	}

for(; i<group.size(); i+=2)
	{
	assert(group[i]!=NULL);
	assert(group[i+1]!=NULL);
	assert(i<group.size());
	assert(i+1<group.size());
	HANDLE th1 = CreateThread(group[i], &CContactResolverGroup::Resolve, iDuration);
	group[i+1]->Resolve(iDuration);
	WaitForSingleObject( th1, INFINITE );
	CloseHandle(th1);
	}

if(singleImmovableContact.size()>0)
	{
	WaitForSingleObject( resovleImmovableHandler, INFINITE );
	CloseHandle(resovleImmovableHandler);
	}

Clear();
}

//*****************************************************************************

void CContactResolver::Clear()
{
for(unsigned i=0; i<group.size(); i++)
if(group[i]!=NULL)
delete group[i];

for(unsigned i=0; i<singleImmovableContact.size(); i++)
delete singleImmovableContact[i];

group.clear();
singleImmovableContact.clear();
}

//*****************************************************************************

void CContactResolver::AddContact(CContactData* iContact)
{
unsigned maxPenetrationIterationsPerObject = Settings->GetParameter("MaxContactResolverPenetrationIterationsPerObject");
unsigned maxVelocityIterationsPerObject = Settings->GetParameter("MaxContactResolverVelocityIterationsPerObject");

assert(iContact!=NULL);

vector<unsigned> depend;

iContact->FillAdditionalDependencys(depend);

set<unsigned> positions; // Finds in which group particular id are
for(unsigned i=0; i<depend.size(); i++)
GetPositionList(depend[i], positions);

if(positions.size() == 0)
	{
	if(iContact->Immovable() == false)
		{
		CContactResolverGroup* tGroup = new CContactResolverGroup(maxPenetrationIterationsPerObject, maxVelocityIterationsPerObject);
		tGroup->Add(iContact);
		group.push_back(tGroup);

		set<unsigned> immovablePositions; // Finds in where particular id are
		for(unsigned i=0; i<depend.size(); i++)
		GetSingleImmovableContactPositionList(depend[i], immovablePositions);
		
		set<unsigned>::iterator it= immovablePositions.begin();

		while(it!=immovablePositions.end())
			{
			tGroup->Add(singleImmovableContact[*it]);
			singleImmovableContact[*it] = singleImmovableContact[singleImmovableContact.size()-1];
			singleImmovableContact.pop_back();
			it++;
			}

		}
	else
		{
		singleImmovableContact.push_back(iContact);
		}


	}
else
	{
	set<unsigned>::iterator it= positions.begin();

	assert(group[*it]!=NULL);
	group[*it]->Add(iContact);

	it++;

	while(it!=positions.end())
		{
		group[*positions.begin()]->Transfer(group[*it]);
		delete group[*it];
		group[*it] = NULL;
		it++;
		}
	
	}

RegisterID(depend.begin(), depend.end());
}

//*****************************************************************************

void CContactResolver::AddContact(vector<CContactData*>::iterator iBegin, vector<CContactData*>::iterator iEnd)
	{
	while(iBegin!=iEnd)
		{
		AddContact(*iBegin);
		iBegin++;
		}
	}

//*****************************************************************************

void CContactResolver::GetPositionList(const unsigned& iID, set<unsigned>& oPositionInGroup)
	{
	if(registeredID.find(iID) == registeredID.end()) return;

	for(unsigned i=0; i<group.size(); i++)
	if(group[i]!=NULL)
		{
		if(group[i]->ExistID(iID)) oPositionInGroup.insert(i);
		}
	}

//*****************************************************************************

void CContactResolver::GetSingleImmovableContactPositionList(const unsigned& iID, set<unsigned>& oPositions)
	{
	if(registeredID.find(iID) == registeredID.end()) return;

	for(unsigned i=0; i<singleImmovableContact.size(); i++)
		{
		assert(singleImmovableContact[i]->GetAdditionalDependencysSize() == 1);
		if(iID == singleImmovableContact[i]->GetAdditionalDependencys(0))
			oPositions.insert(i);
		}
	}

//*****************************************************************************

void CContactResolver::RegisterID(const unsigned& iID)
	{
	registeredID.insert(iID);
	}

//*****************************************************************************

void CContactResolver::RegisterID(vector<unsigned>::iterator iBegin, vector<unsigned>::iterator iEnd)
	{
	while(iBegin!=iEnd)
		{
		RegisterID(*iBegin);
		iBegin++;
		}
	}

//*****************************************************************************

void CContactResolver::ResolveSingleImmovableContacts(float iDuration)
	{
	for(unsigned i = 0; i<singleImmovableContact.size(); i++)
		{
		singleImmovableContact[i]->Resolve(iDuration);
		}
	}
