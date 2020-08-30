///////////////////////////////////////////////////////////
//  ParticleForceGenerator_Buoyancy.h
//  Created on:      26-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PARTICLEFORCEGENERATOR_BUOYANCY_H
#define REGINA_PARTICLEFORCEGENERATOR_BUOYANCY_H

#include <ParticlePhisics.h>
#include <ParticleForceGenerator.h>
#include <PhisicsManager.h>

namespace Regina
{

class CParticleForceGenerator_Buoyancy : public CParticleForceGenerator
{
float liquedDensity;
float objectVolume;
float maxDepth;
float waterHeight;

public:
CParticleForceGenerator_Buoyancy(CParticlePhisics* iOwner = NULL, string iName = "Buoyancy", float iWaterHeight = 0.0f, float iObjectVolume = 0.0f, float iMaxDepth = 0.0f, float iLiquedDensity = 1000.0f) : CParticleForceGenerator(iOwner, iName), waterHeight(iWaterHeight), objectVolume(iObjectVolume), maxDepth(iMaxDepth), liquedDensity(iLiquedDensity) {}
virtual void Update(float iDuration);
virtual void Load(string iDefinition);
};

}

#endif
