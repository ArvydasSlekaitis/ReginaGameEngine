///////////////////////////////////////////////////////////
//  PhisicalLink_Rod_Particle_Particle.cpp
//  Created on:      12-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <PhisicalLink_Rod_Particle_Particle.h>
using namespace Regina;


//*****************************************************************************

CPhisicalLink_Rod_Particle_Particle::CPhisicalLink_Rod_Particle_Particle(CParticlePhisics* iParticle1, CParticlePhisics* iParticle2, float iLength) : length(iLength)
{
particle[0] = iParticle1;
particle[1] = iParticle2;
}

//*****************************************************************************

void CPhisicalLink_Rod_Particle_Particle::Load(string iDefinition)
{
istringstream def(iDefinition);
string		type;
unsigned 	particle1ID;
unsigned	particle2ID;

def >> type >> particle1ID >> particle2ID >> length;

particle[0] = PhisicsManager->ParticleFromID(particle1ID);
if(particle[0] == NULL)
	{
	ostringstream os;
	os << "Phisical link first particle id (" << particle1ID << ") does not exist";
	throw CParticlePhisicsManager::ID_Error(os.str());
	}

particle[1] = PhisicsManager->ParticleFromID(particle2ID);
if(particle[1] == NULL)
	{
	ostringstream os;
	os << "Phisical link second particle id (" << particle2ID << ") does not exist";
	throw CParticlePhisicsManager::ID_Error(os.str());
	}
}

//*****************************************************************************

void CPhisicalLink_Rod_Particle_Particle::FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys)
{
assert(particle[0]!=NULL);
assert(particle[1]!=NULL);

oAdditionalDependencys.push_back(particle[0]->ID());
oAdditionalDependencys.push_back(particle[1]->ID());
}

//*****************************************************************************

void CPhisicalLink_Rod_Particle_Particle::Update(float iTime)
{
float curLength = CurrentLength();
if(curLength == length) return;

CContactData* contact = new CContactData_ParticleParticle(particle[0], particle[1]);

D3DXVECTOR3 contactNormal = particle[1]->Position() - particle[0]->Position();
D3DXVec3Normalize(&contactNormal, &contactNormal);

if(curLength > length)
	{
	contact->SetContactNormal(contactNormal);
	contact->SetPenetration(curLength-length);
	}
else
	{
	contact->SetContactNormal(-contactNormal);
	contact->SetPenetration(length-curLength);
	}

contact->SetRestitution(0);

PhisicsManager->AddContact(contact);
}

//*****************************************************************************
