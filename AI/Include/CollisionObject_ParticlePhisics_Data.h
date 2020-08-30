///////////////////////////////////////////////////////////
//  CollisionObject_ParticlePhisics_Data.h
//  Created on:      22-07-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_COLLISIONOBJECT_PARTICLEPHISICS_DATA_H
#define REGINA_COLLISIONOBJECT_PARTICLEPHISICS_DATA_H

#include <ParticlePhisics.h>
#include <BaseEntity.h>

namespace Regina
{

class CCollisionObject_ParticlePhisics_Data
{
	CParticlePhisics*			particlePhisics;
	CBaseEntity*		const	baseEntity;

	const float					radius;
	const float					restitution;

	bool						messageSendingEnabled;

	CBaseEntity*				Entity() { return baseEntity; }

public:
	CCollisionObject_ParticlePhisics_Data(CParticlePhisics* iParticlePhisics, const float& iRadius, const float& iRestitution, CBaseEntity* iBaseEntity = NULL, const bool iMessageSendingEnabled = false);

	D3DXVECTOR3			Position()			const	{ return particlePhisics->Position() ; }
	D3DXVECTOR2			PositionXZ()		const	{ return D3DXVECTOR2(particlePhisics->Position().x, particlePhisics->Position().z); }
	D3DXVECTOR3			Velocity()			const	{ return particlePhisics->Velocity(); }
	float				Radius()			const	{ return radius; }
	float				Restitution()		const	{ return restitution; }
	CParticlePhisics*	ParticlePhisics()			{ return particlePhisics; }
	unsigned			EntityID();

	bool				CanSendMessageToEntity()	const	{ return messageSendingEnabled; }
	bool				EntityExist()				const	{ return baseEntity!=NULL; }	

	bool				SendMessageToEntity(CTelegram* iTelegram);

};

}

#endif