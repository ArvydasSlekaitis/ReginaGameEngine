///////////////////////////////////////////////////////////
//  ParticleForceGenerator_Gravity.cpp
//  Created on:      14-08-2008
//  Last modified:   05-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <ParticleForceGenerator_Gravity.h>
using namespace Regina;


//*****************************************************************************

void CParticleForceGenerator_Gravity::Update(float iDuration)
{
assert(owner!=NULL); 
assert(owner->InverseMass()!=0.0);

owner->AddForce(gravity*owner->Mass());
}

//*****************************************************************************

void CParticleForceGenerator_Gravity::Load(string iDefinition)
{
istringstream is(iDefinition);
string		type;
unsigned	ownerID;

is >> type >> ownerID >> gravity.x >> gravity.y >> gravity.z >> name;

owner = PhisicsManager->ParticleFromID(ownerID);
if(owner == NULL)
	{
	ostringstream os;
	os << "Force owner id (" << ownerID << ") does not exist";
	throw CParticlePhisicsManager::ID_Error(os.str());
	}

}

//*****************************************************************************

