///////////////////////////////////////////////////////////
//  ContactData_ParticleImmovable.h
//  Created on:      12-03-2009
//  Last modified:   29-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_CONTACTDATA_PARTICLE_IMMOVABLE_H
#define REGINA_CONTACTDATA_PARTICLE_IMMOVABLE_H

#include <d3dx9.h>

#include <ContactData.h>
#include <ParticlePhisics.h>

namespace Regina
{

class CContactData_ParticleImmovable : public CContactData
{
CParticlePhisics*	particle;
D3DXVECTOR3			initialPosition;

public:
CContactData_ParticleImmovable(CParticlePhisics* iParticle, D3DXVECTOR3 iContactNormal = D3DXVECTOR3(), float iPenetration = 0.0, float iRestitution = 0.0);
CContactData_ParticleImmovable(CParticlePhisics* iParticle, const CBasicContactData& iBasicContactData);

void Resolve(float iDuration);
void ResolveVelocity(float iDuration);
void ResolveInterpenetration(float iDuration);
float CalculateSeparatingVelocity();
float CalculateIterpenetration();
void FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys) { oAdditionalDependencys.push_back(particle->ID()); }
};

}

#endif
