///////////////////////////////////////////////////////////
//  Entity_Sphere.cpp
//  Created on:      20-08-2009
//  Last modified:   20-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Entity_Sphere.h>
using namespace Regina;

//*****************************************************************************

CEntity_Sphere::CEntity_Sphere(const D3DXVECTOR3& iPosition, const float& iRadius) : CBaseEntity("Entity_Sphere", 1)
	{
	particle = new CParticlePhisics();
	particle->SetPosition(iPosition);
	//particle->SetAcceleration(D3DXVECTOR3(0, -10, 0));
	particle->SetMass(1); 
	particle->SetDamping(0.99995);
	PhisicsManager->AddParticle(particle);
	AIManager->AddCollisionObject_ParticlePhisics(particle, iRadius, 1.0);
	}

//*****************************************************************************

CEntity_Sphere::CEntity_Sphere() : CBaseEntity("Entity_Sphere", 1) 
	{
	particle = new CParticlePhisics();
	particle->SetPosition(D3DXVECTOR3(0, 0, 0));
	particle->SetMass(1); 
	particle->SetDamping(0.99995);
	PhisicsManager->AddParticle(particle);
	AIManager->AddCollisionObject_ParticlePhisics(particle, 1.0, 1.0);
	}

//*****************************************************************************

CEntity_Sphere::~CEntity_Sphere()
	{
	AIManager->RemoveCollisionObject_ParticlePhisics(particle);
	PhisicsManager->RemoveParticle(particle->ID());
	}

//*****************************************************************************

void CEntity_Sphere::Update(float duration) 
	{
	}

//*****************************************************************************

void CEntity_Sphere::Load(const vector<string>& iText) 
	{
	}

//*****************************************************************************