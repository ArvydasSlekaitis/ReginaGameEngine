///////////////////////////////////////////////////////////
//  CollisionObject_ParticlePhisics.h
//  Created on:      30-07-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_COLLISIONOBJECT_PARTICLEPHISICS_H
#define REGINA_COLLISIONOBJECT_PARTICLEPHISICS_H

#include <ParticlePhisics.h>
#include <BaseEntity.h>
#include <CollisionObject_ParticlePhisics_Data.h>

namespace Regina
{

class CCollisionDetectionManager;
class CCollisionObject_ParticlePhisics
{
	CCollisionObject_ParticlePhisics_Data* data;	

public:
	CCollisionObject_ParticlePhisics(CCollisionObject_ParticlePhisics_Data* iData);

	D3DXVECTOR3 Position()		const { return data->Position(); }
	D3DXVECTOR3 Velocity()		const { return data->Velocity(); }
	float		Radius()		const { return data->Radius(); }
	float		Restitution()	const { return data->Restitution(); }
	unsigned	EntityID()		const { return data->EntityID(); }

	bool		EntityExist()	const { return data->EntityExist(); }	
	bool		CanSendMessageToEntity() const { return data->CanSendMessageToEntity(); } // return true if you can send message to entity
	bool		SendMessageToEntity(CTelegram* iTelegram) { return data->SendMessageToEntity(iTelegram); } // return true if message was send

	friend CCollisionDetectionManager;
};

}

#endif