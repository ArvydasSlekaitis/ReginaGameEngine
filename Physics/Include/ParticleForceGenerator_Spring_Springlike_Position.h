///////////////////////////////////////////////////////////
//  ParticleForceGenerator_Spring_Springlike_Position.h
//  Created on:      10-03-2009
//  Last modified:   10-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PARTICLEFORCEGENERATOR_SPRING_SPRINGLIKE_POSITION_H
#define REGINA_PARTICLEFORCEGENERATOR_SPRING_SPRINGLIKE_POSITION_H

#include <ParticlePhisics.h>
#include <ParticleForceGenerator.h>
#include <PhisicsManager.h>

namespace Regina
{

class CParticleForceGenerator_Spring_Springlike_Position : public CParticleForceGenerator
{
D3DXVECTOR3 otherEnd; // Other end of spring
float		restLenght;
float		springConstant;

public:

CParticleForceGenerator_Spring_Springlike_Position(CParticlePhisics* iOwner = NULL, D3DXVECTOR3 iOtherEnd=D3DXVECTOR3(0, 0, 0), float iRestLenght=0, float iSpringConstant=0, string iName = "Spring_Springlike_Position") : CParticleForceGenerator(iOwner, iName), restLenght(iRestLenght), springConstant(iSpringConstant), otherEnd(iOtherEnd) {}
virtual void Update(float iDuration);
virtual void Load(string iDefinition);
};


}

#endif





