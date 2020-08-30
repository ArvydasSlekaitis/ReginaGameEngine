///////////////////////////////////////////////////////////
//  ParticleForceGenerator_Spring_Springlike_Position.h
//  Created on:      10-03-2009
//  Last modified:   10-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <ParticleForceGenerator_Spring_Springlike_Position.h>
using namespace Regina;


//*****************************************************************************

void CParticleForceGenerator_Spring_Springlike_Position::Update(float iDuration)
{
assert(owner!=NULL); 

D3DXVECTOR3 force = owner->Position() - otherEnd;

float magn = -springConstant*(restLenght - D3DXVec3Length(&force));
D3DXVec3Normalize(&force, &force);
force *= magn;

owner->AddForce(-force);
}

//*****************************************************************************

void CParticleForceGenerator_Spring_Springlike_Position::Load(string iDefinition)
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




