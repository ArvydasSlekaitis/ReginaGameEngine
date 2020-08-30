///////////////////////////////////////////////////////////
//  ParticlePhisicsManager.cpp
//  Created on:      12-03-2008
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <ParticlePhisicsManager.h>
using namespace Regina;


//******************************************************************************

CParticlePhisicsManager::CParticlePhisicsManager(unsigned iMinID, unsigned iMaxID) : TFastAccessManager(iMinID, iMaxID)
{
}

//******************************************************************************

CParticlePhisics* CParticlePhisicsManager::ParticleFromID(unsigned iID)
{
CSpritePhisics* sp = ObjectFromID(iID);
if(sp==NULL) return NULL;

	if(sp->type!=CSpritePhisics::Sprite)
	return (CParticlePhisics*)(sp);
	else
	throw bad_cast("Cannot cast from sprite to particle");

return NULL;
}

//******************************************************************************

CRotatingParticlePhisics* CParticlePhisicsManager::RotatingParticleFromID(unsigned iID)
{
CSpritePhisics* sp = ObjectFromID(iID);
if(sp==NULL) return NULL;

	switch(sp->type)
		{
		case(CSpritePhisics::RotatingParticle) : return (CRotatingParticlePhisics*)(sp);  break;
		case(CSpritePhisics::Particle)		   : throw bad_cast("Cannot cast from particle to rotating particle"); break;
		case(CSpritePhisics::Sprite)		   : throw bad_cast("Cannot cast from sprite to rotating particle"); break;
		}

return NULL;
}


//******************************************************************************
