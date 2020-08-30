///////////////////////////////////////////////////////////
//  ParticleForceGenerator_Spring_Bungee_Position.h
//  Created on:      27-10-2008
//  Last modified:   05-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PARTICLEFORCEGENERATOR_SPRING_BUNGEE_POSITION_H
#define REGINA_PARTICLEFORCEGENERATOR_SPRING_BUNGEE_POSITION_H

#include <ParticlePhisics.h>
#include <ParticleForceGenerator.h>
#include <PhisicsManager.h>

namespace Regina
{

class CParticleForceGenerator_Spring_Bungee_Position : public CParticleForceGenerator
{
D3DXVECTOR3 otherEnd; // Other end of spring
float		restLenght;
float		springConstant;

public:

CParticleForceGenerator_Spring_Bungee_Position(CParticlePhisics* iOwner = NULL, D3DXVECTOR3 iOtherEnd=D3DXVECTOR3(0, 0, 0), float iRestLenght=0, float iSpringConstant=0, string iName = "Spring_Bungee_Position") : CParticleForceGenerator(iOwner, iName), restLenght(iRestLenght), springConstant(iSpringConstant), otherEnd(iOtherEnd) {}
virtual void Update(float iDuration);
virtual void Load(string iDefinition);
};


}

#endif





