///////////////////////////////////////////////////////////
//  Entity_DarkSmile.h
//  Created on:      26-08-2009
//  Last modified:   26-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef ENTITY_DARKSMILE_H
#define ENTITY_DARKSMILE_H

#include <exception>
using namespace std;

#include <SimpleMovingEntity.h>
#include <AIManager.h>
#include <CollisionMesh.h>
#include <ParticlePhisics.h>
#include <PhisicsManager.h>
#include <BasicMessageEnumaration.h>
#include <SteeringBehaviorManager.h>
using namespace Regina;


class CEntity_DarkSmile : public CSimpleMovingEntity
{
	CParticlePhisics*			particle;
	CSteeringBehaviorManager*	steeringBehaviorManager;

public:
	CEntity_DarkSmile(const D3DXVECTOR3& iPosition);
	CEntity_DarkSmile();
	virtual ~CEntity_DarkSmile();

	virtual void Update(float duration);
	virtual void HandleMsg(CTelegram* iTelegram);
	virtual void Load(const vector<string>& iText);

	D3DXVECTOR3 Position() const { return particle->Position(); }
	D3DXVECTOR3	Velocity() const { return particle->Velocity(); }
	D3DXVECTOR2	Heading() const { D3DXVECTOR2 normvel; D3DXVec2Normalize(&normvel, &D3DXVECTOR2(particle->Velocity().x, particle->Velocity().z)); return normvel;  }
	float		Speed() const { return particle->Speed(); }
	
	void SetPosition(const D3DXVECTOR3& iPosition);
};

#endif