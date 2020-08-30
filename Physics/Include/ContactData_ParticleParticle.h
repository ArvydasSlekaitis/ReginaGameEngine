///////////////////////////////////////////////////////////
//  ContactData_ParticleParticle.h
//  Created on:      12-03-2009
//  Last modified:   29-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_CONTACTDATA_PARTICLE_PARTICLE_H
#define REGINA_CONTACTDATA_PARTICLE_PARTICLE_H

#include <d3dx9.h>
#include <assert.h>

#include <ContactData.h>
#include <ParticlePhisics.h>
#include <ContactData_ParticleImmovable.h>

namespace Regina
{

class CContactData_ParticleParticle : public CContactData
{
CParticlePhisics*	particle[2];
D3DXVECTOR3			initialPosition[2];

public:
CContactData_ParticleParticle(CParticlePhisics* iParticle1, CParticlePhisics* iParticle2, D3DXVECTOR3 iContactNormal = D3DXVECTOR3(), float iPenetration = 0.0, float iRestitution = 0.0);
CContactData_ParticleParticle(CParticlePhisics* iParticle1, CParticlePhisics* iParticle2, const CBasicContactData& iBasicContactData);

void Resolve(float iDuration);
void ResolveVelocity(float iDuration);
void ResolveInterpenetration(float iDuration);
float CalculateSeparatingVelocity();
float CalculateIterpenetration();
void FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys) { oAdditionalDependencys.push_back(particle[0]->ID()); oAdditionalDependencys.push_back(particle[1]->ID()); }
CContactData* GetImmovableVersion(const unsigned iExludedID);
};

}

#endif
