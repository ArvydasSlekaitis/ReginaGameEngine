///////////////////////////////////////////////////////////
//  CollisionObject_Static.h
//  Created on:      07-09-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_COLLISIONOBJECT_STATIC_H
#define REGINA_COLLISIONOBJECT_STATIC_H

#include <CollisionMesh.h>
#include <BaseEntity.h>
#include <CollisionObject_Static_Data.h>

namespace Regina
{

class CCollisionDetectionManager;
class CCollisionObject_Static
{
	CCollisionObject_Static_Data* data;
	
public:
	CCollisionObject_Static(CCollisionObject_Static_Data* iData);
	
	D3DXVECTOR3 Position()		const { return data->Position(); }
	D3DXVECTOR2 PositionXZ()	const { return data->PositionXZ(); }
	float		Radius()		{ return data->Radius(); }

	unsigned	EntityID()		const { return data->EntityID(); }

	bool		EntityExist()	const { return data->EntityExist(); }	
	bool		CanSendMessageToEntity() const { return data->CanSendMessageToEntity(); } // return true if you can send message to entity
	bool		SendMessageToEntity(CTelegram* iTelegram) { return data->SendMessageToEntity(iTelegram); } // return true if message was send

	
friend CCollisionDetectionManager;
};

}

#endif