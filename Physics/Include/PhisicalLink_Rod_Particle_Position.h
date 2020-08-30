///////////////////////////////////////////////////////////
//  PhisicalLink_Rod_Particle_Position.h
//  Created on:      26-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PHISICALLINK_ROD_PARTICLE_POSITION_H
#define REGINA_PHISICALLINK_ROD_PARTICLE_POSITION_H

#include <assert.h>
#include <vector>
using namespace std;

#include <ParticlePhisics.h>
#include <ContactData.h>
#include <ContactData_ParticleImmovable.h>
#include <PhisicalLink.h>
#include <PhisicsManager.h>

namespace Regina
{

class CPhisicalLink_Rod_Particle_Position : public CPhisicalLink
{
protected:
CParticlePhisics*	particle;
D3DXVECTOR3			otherEnd;
float length;

public:
CPhisicalLink_Rod_Particle_Position(CParticlePhisics* iParticle = NULL, D3DXVECTOR3 iOtherEnd = D3DXVECTOR3(0, 0, 0), float iLength = 0.0);

void Update(float iTime);
void Load(string iDefinition);
void FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys);

float CurrentLength() { return D3DXVec3Length(&(particle->Position() - otherEnd)); }

float Length()	const { return length; }

void SetLength(float iLength) { length = iLength; }
};

}

#endif
