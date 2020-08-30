///////////////////////////////////////////////////////////
//  Entity_Sphere.h
//  Created on:      20-08-2009
//  Last modified:   20-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef ENTITY_SPHERE_H
#define ENTITY_SPHERE_H

#include <exception>
using namespace std;

#include <BaseEntity.h>
#include <ParticlePhisics.h>
#include <PhisicsManager.h>
#include <AIManager.h>
using namespace Regina;


class CEntity_Sphere : public CBaseEntity
{
	CParticlePhisics*	particle;

public:
	CEntity_Sphere(const D3DXVECTOR3& iPosition, const float& iRadius);
	CEntity_Sphere();
	virtual ~CEntity_Sphere();

	virtual void Update(float duration);
	virtual void HandleMsg(CTelegram* iTelegram) { delete iTelegram; }
	virtual void Load(const vector<string>& iText);

	D3DXVECTOR3 Position() { return particle->Position(); }
	CParticlePhisics*	Particle() { return particle; }
};

#endif