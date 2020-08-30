///////////////////////////////////////////////////////////
//  ParticleForceGenerator_Buoyancy.cpp
//  Created on:      26-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <ParticleForceGenerator_Buoyancy.h>
using namespace Regina;


//*****************************************************************************

void CParticleForceGenerator_Buoyancy::Update(float iDuration)
{
assert(owner!=NULL); 
assert(owner->InverseMass()!=0.0);

float depth = owner->Position().y;
if( depth >= waterHeight + maxDepth ) return;

D3DXVECTOR3 force(0, 0, 0);

if( depth <= waterHeight - maxDepth )
{ 
force.y = objectVolume * liquedDensity;
owner->AddForce(force);
return;
}

force.y =  objectVolume * liquedDensity * (depth - maxDepth - waterHeight) / 2 * maxDepth; // Y is down

owner->AddForce(force);
}

//*****************************************************************************

void CParticleForceGenerator_Buoyancy::Load(string iDefinition)
{
istringstream is(iDefinition);
string		type;
unsigned	ownerID;

is >> type >> ownerID >> liquedDensity >> objectVolume >> maxDepth >> waterHeight >> name;

owner = PhisicsManager->ParticleFromID(ownerID);
if(owner == NULL)
	{
	ostringstream os;
	os << "Force owner id (" << ownerID << ") does not exist";
	throw CParticlePhisicsManager::ID_Error(os.str());
	}

}

//*****************************************************************************
