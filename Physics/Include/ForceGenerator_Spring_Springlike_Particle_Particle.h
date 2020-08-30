///////////////////////////////////////////////////////////
//  ForceGenerator_Spring_Springlike_Particle_Particle.h
//  Created on:      10-03-2009
//  Last modified:   25-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_FORCEGENERATOR_SPRING_SPRINGLIKE_PARTICLE_PARTICLE_H
#define REGINA_FORCEGENERATOR_SPRING_SPRINGLIKE_PARTICLE_PARTICLE_H

#include <ParticlePhisics.h>
#include <ParticleForceGenerator.h>

#include <PhisicsManager.h>

namespace Regina
{

class CForceGenerator_Spring_Springlike_Particle_Particle : public CParticleForceGenerator
{
CParticlePhisics*	otherEnd; // Other end of spring
float				restLenght;
float				springConstant;

public:

CForceGenerator_Spring_Springlike_Particle_Particle(CParticlePhisics* iOwner = NULL, CParticlePhisics* iOtherEnd=NULL, float iRestLenght=0, float iSpringConstant=0, string iName = "Spring_Springlike_Particle") : CParticleForceGenerator(iOwner, iName), restLenght(iRestLenght), springConstant(iSpringConstant), otherEnd(iOtherEnd) {}
virtual void Update(float iDuration);
virtual void Load(string iDefinition);
virtual void FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys) {  assert(owner!=NULL); assert(otherEnd!=NULL); oAdditionalDependencys.push_back(owner->ID());  oAdditionalDependencys.push_back(otherEnd->ID());}
};


}

#endif





