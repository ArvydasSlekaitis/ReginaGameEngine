///////////////////////////////////////////////////////////
//  ParticleForceGenerator_Drag.h
//  Created on:      28-10-2008
//  Last modified:   05-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PARTICLEFORCEGENERATOR_DRAG_H
#define REGINA_PARTICLEFORCEGENERATOR_DRAG_H

#include <ParticlePhisics.h>
#include <ParticleForceGenerator.h>
#include <PhisicsManager.h>

namespace Regina
{

class CParticleForceGenerator_Drag : public CParticleForceGenerator
{
float k1;
float k2;

public:

CParticleForceGenerator_Drag(CParticlePhisics* iOwner = NULL, float iK1=0, float iK2=0, string iName = "Drag") : CParticleForceGenerator(iOwner, iName), k1(iK1), k2(iK2) {}
virtual void Update(float iDuration);
virtual void Load(string iDefinition);
};


}

#endif


