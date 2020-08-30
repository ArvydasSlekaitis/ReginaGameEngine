///////////////////////////////////////////////////////////
//  ParticleForceGenerator_Drag.cpp
//  Created on:      28-10-2008
//  Last modified:   05-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <ParticleForceGenerator_Drag.h>
using namespace Regina;


//*****************************************************************************

void CParticleForceGenerator_Drag::Update(float iDuration)
{
assert(owner!=NULL); 

D3DXVECTOR3 force = owner->Velocity();
D3DXVec3Normalize(&force, &force);

float speed = owner->Speed();

force*= - (k1*speed + k2*speed*speed);

owner->AddForce(force);
}

//*****************************************************************************

void CParticleForceGenerator_Drag::Load(string iDefinition)
{
istringstream is(iDefinition);
string		type;
unsigned	ownerID;

is >> type >> ownerID >> k1 >> k2 >> name;

owner = PhisicsManager->ParticleFromID(ownerID);
if(owner == NULL)
	{
	ostringstream os;
	os << "Force owner id (" << ownerID << ") does not exist";
	throw CParticlePhisicsManager::ID_Error(os.str());
	}

}

//*****************************************************************************



