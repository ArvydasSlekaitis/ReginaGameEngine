///////////////////////////////////////////////////////////
//  ForceGenerator_Spring_Springlike_Particle_Particle.cpp
//  Created on:      10-03-2009
//  Last modified:   25-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <ForceGenerator_Spring_Springlike_Particle_Particle.h>
using namespace Regina;


//*****************************************************************************

void CForceGenerator_Spring_Springlike_Particle_Particle::Update(float iDuration)
{
assert(owner!=NULL); 
assert(otherEnd!=NULL);

D3DXVECTOR3 force = owner->Position() - otherEnd->Position();

float magn = -springConstant*(restLenght - D3DXVec3Length(&force));
D3DXVec3Normalize(&force, &force);
force *= magn;

owner->AddForce(-force);
}

//*****************************************************************************

void CForceGenerator_Spring_Springlike_Particle_Particle::Load(string iDefinition)
{
istringstream is(iDefinition);
string		type;
unsigned 	ownerID;
unsigned	otherEndID;

is >> type >> ownerID >> otherEndID >> restLenght >> springConstant >> name;


otherEnd = PhisicsManager->ParticleFromID(otherEndID);
if(otherEnd == NULL)
	{
	ostringstream os;
	os << "Force other end id (" << otherEndID << ") does not exist";
	throw CParticlePhisicsManager::ID_Error(os.str());
	}

owner = PhisicsManager->ParticleFromID(ownerID);
if(owner == NULL)
	{
	ostringstream os;
	os << "Force owner id (" << ownerID << ") does not exist";
	throw CParticlePhisicsManager::ID_Error(os.str());
	}

}

//*****************************************************************************




