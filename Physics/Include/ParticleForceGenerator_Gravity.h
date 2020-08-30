///////////////////////////////////////////////////////////
//  ParticleForceGenerator_Gravity.h
//  Created on:      14-08-2008
//  Last modified:   25-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PARTICLEFORCEGENERATOR_GRAVITY_H
#define REGINA_PARTICLEFORCEGENERATOR_GRAVITY_H

#include <ParticlePhisics.h>
#include <ParticleForceGenerator.h>
#include <PhisicsManager.h>

namespace Regina
{

class CParticleForceGenerator_Gravity : public CParticleForceGenerator
{
D3DXVECTOR3 gravity;

public:
CParticleForceGenerator_Gravity(CParticlePhisics* iOwner = NULL, string iName = "Gravity", D3DXVECTOR3 iGravity = D3DXVECTOR3(0, -10, 0)) : CParticleForceGenerator(iOwner, iName), gravity(iGravity) {}
virtual void Update(float iDuration);
virtual void Load(string iDefinition);
};

}

#endif
