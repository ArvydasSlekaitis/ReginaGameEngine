///////////////////////////////////////////////////////////
//  CollisionObject_Static_Data.h
//  Created on:      07-09-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_COLLISIONOBJECT_STATIC_DATA_H
#define REGINA_COLLISIONOBJECT_STATIC_DATA_H

#include <CollisionMesh.h>
#include <BaseEntity.h>

namespace Regina
{

class CCollisionObject_Static_Data
{
	CCollisionMesh*			collisionMesh;
	CBaseEntity*	const 	baseEntity;
	bool					messageSendingEnabled;

	CBaseEntity*			Entity() { return baseEntity; }
	
public:
	CCollisionObject_Static_Data(const string& iCollisionMeshName, const D3DXMATRIXA16& iTransformation, CBaseEntity* iBaseEntity = NULL, const bool iMessageSendingEnabled = false);

	D3DXVECTOR3		Position()						{ return collisionMesh->Position() ; }
	D3DXVECTOR2		PositionXZ()					{ return D3DXVECTOR2(collisionMesh->Position().x, collisionMesh->Position().z); }
	float			Radius()						{ return collisionMesh->RadiusXZ(); } //RadiusXZ
	CCollisionMesh*	CollisionMesh()					{ return collisionMesh; }
	bool			MessageSendingEnabled() const	{ return messageSendingEnabled; }

	unsigned			EntityID();

	bool				CanSendMessageToEntity()	const	{ return messageSendingEnabled; }
	bool				EntityExist()				const	{ return baseEntity!=NULL; }	

	bool				SendMessageToEntity(CTelegram* iTelegram);
};

}

#endif