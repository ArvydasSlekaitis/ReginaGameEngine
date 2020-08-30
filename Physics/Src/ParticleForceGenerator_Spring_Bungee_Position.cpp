///////////////////////////////////////////////////////////
//  ParticleForceGenerator_Spring_Bungee_Position.h
//  Created on:      27-10-2008
//  Last modified:   05-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <ParticleForceGenerator_Spring_Bungee_Position.h>
using namespace Regina;


//*****************************************************************************

void CParticleForceGenerator_Spring_Bungee_Position::Update(float iDuration)
{
assert(owner!=NULL); 

D3DXVECTOR3 force = owner->Position() - otherEnd;

if(D3DXVec3Length(&force) <= restLenght) return;

float magn = -springConstant*(restLenght - D3DXVec3Length(&force));
D3DXVec3Normalize(&force, &force);
force *= magn;

owner->AddForce(-force);
}

//*****************************************************************************

void CParticleForceGenerator_Spring_Bungee_Position::Load(string iDefinition)
{
istringstream is(iDefinition);
string		type;
unsigned 	ownerID;

is >> type >> ownerID >> otherEnd.x >> otherEnd.y >> otherEnd.z >> restLenght >> springConstant >> name;

owner = PhisicsManager->ParticleFromID(ownerID);
if(owner == NULL)
	{
	ostringstream os;
	os << "Force owner id (" << ownerID << ") does not exist";
	throw CParticlePhisicsManager::ID_Error(os.str());
	}

}

//*****************************************************************************




