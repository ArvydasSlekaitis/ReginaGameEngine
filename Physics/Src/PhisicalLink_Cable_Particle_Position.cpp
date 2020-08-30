///////////////////////////////////////////////////////////
//  PhisicalLink_Cable_Particle_Position.cpp
//  Created on:      26-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <PhisicalLink_Cable_Particle_Position.h>
using namespace Regina;


//*****************************************************************************

CPhisicalLink_Cable_Particle_Position::CPhisicalLink_Cable_Particle_Position(CParticlePhisics* iParticle1, D3DXVECTOR3 iOtherEnd, float iMaxLength, float iRestitution) : CPhisicalLink(), maxLength(iMaxLength), restitution(iRestitution)
{
particle = iParticle1;
otherEnd = iOtherEnd;
}

//*****************************************************************************

void CPhisicalLink_Cable_Particle_Position::Load(string iDefinition)
{
istringstream def(iDefinition);
string		type;
unsigned 	particle1ID;

def >> type >> particle1ID >> otherEnd.x >> otherEnd.y >> otherEnd.z >> maxLength >> restitution;

particle = PhisicsManager->ParticleFromID(particle1ID);
if(particle == NULL)
	{
	ostringstream os;
	os << "Phisical link particle id (" << particle1ID << ") does not exist";
	throw CParticlePhisicsManager::ID_Error(os.str());
	}
}

//*****************************************************************************

void CPhisicalLink_Cable_Particle_Position::FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys)
{
assert(particle!=NULL);

oAdditionalDependencys.push_back(particle->ID());
}

//*****************************************************************************

void CPhisicalLink_Cable_Particle_Position::Update(float iTime)
{
assert(particle!=NULL);

float curLength = CurrentLength();
if(curLength < maxLength) return;

CContactData* contact = new CContactData_ParticleImmovable(particle);

D3DXVECTOR3 contactNormal = otherEnd - particle->Position();
D3DXVec3Normalize(&contactNormal, &contactNormal);

contact->SetContactNormal(contactNormal);
contact->SetPenetration(curLength-maxLength);
contact->SetRestitution(restitution);

PhisicsManager->AddContact(contact);
}

//*****************************************************************************
