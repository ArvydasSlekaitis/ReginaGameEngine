///////////////////////////////////////////////////////////
//  CollisionObject_Dynamic.h
//  Created on:      07-09-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_COLLISIONOBJECT_DYNAMIC_H
#define REGINA_COLLISIONOBJECT_DYNAMIC_H

#include <CollisionMesh.h>
#include <MovingEntity.h>
#include <CollisionObject_Dynamic_Data.h>

namespace Regina
{

class CCollisionDetectionManager;
class CCollisionObject_Dynamic
{
	CCollisionObject_Dynamic_Data* data;
	
public:
	CCollisionObject_Dynamic(CCollisionObject_Dynamic_Data* iData);
	
	D3DXVECTOR3 Position()		const { return data->Position(); }
	D3DXVECTOR2 PositionXZ()	const { return data->PositionXZ(); }
	D3DXVECTOR2	Heading()		const { return data->Heading(); }
	unsigned	EntityID()		const { return data->EntityID(); }
	float		Radius()		{ return data->Radius(); }

	bool		CanSendMessageToEntity() const { return data->CanSendMessageToEntity(); } // return true if you can send message to entity
	bool		SendMessageToEntity(CTelegram* iTelegram) { return data->SendMessageToEntity(iTelegram); } // return true if message was send
	
friend CCollisionDetectionManager;
};

}

#endif