///////////////////////////////////////////////////////////
//  PhisicalLink_Rod_Particle_Particle.h
//  Created on:      12-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PHISICALLINK_ROD_PARTICLE_PARTICLE_H
#define REGINA_PHISICALLINK_ROD_PARTICLE_PARTICLE_H

#include <assert.h>
#include <vector>
using namespace std;

#include <ParticlePhisics.h>
#include <ContactData.h>
#include <ContactData_ParticleParticle.h>
#include <PhisicalLink.h>
#include <PhisicsManager.h>
#include <ContactResolver.h>

namespace Regina
{

class CPhisicalLink_Rod_Particle_Particle : public CPhisicalLink
{
protected:
CParticlePhisics*	particle[2];
float length;

public:
CPhisicalLink_Rod_Particle_Particle(CParticlePhisics* iParticle1 = NULL, CParticlePhisics* iParticle2 = NULL, float iLength = 0.0);

void Update(float iTime);
void Load(string iDefinition);
void FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys);

float CurrentLength() { return D3DXVec3Length(&(particle[0]->Position() - particle[1]->Position())); }

float Length()	const { return length; }

void SetLength(float iLength) { length = iLength; }
};

}

#endif
