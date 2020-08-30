///////////////////////////////////////////////////////////
//  CollisionObject_Dynamic_Data.h
//  Created on:      07-09-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_COLLISIONOBJECT_DYNAMIC_DATA_H
#define REGINA_COLLISIONOBJECT_DYNAMIC_DATA_H

#include <CollisionMesh.h>
#include <MovingEntity.h>

namespace Regina
{

class CCollisionObject_Dynamic_Data
{
	CCollisionMesh*			collisionMesh;
	CMovingEntity*	const 	movingEntity;
	bool					messageSendingEnabled;
	
	CMovingEntity* Entity() { return movingEntity; }	

	bool					collisionMeshOwner;
	
public:
	CCollisionObject_Dynamic_Data(const string& iCollisionMeshName, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled = false);
	CCollisionObject_Dynamic_Data(CCollisionMesh* iCollisionMesh, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled = false);
	~CCollisionObject_Dynamic_Data();

	D3DXVECTOR3		Position()						{ return movingEntity->Position() ; }
	D3DXVECTOR2		PositionXZ()					{ return D3DXVECTOR2(movingEntity->Position().x, movingEntity->Position().z); }
	D3DXVECTOR2		Heading()						{ return movingEntity->Heading(); }
	float			Radius();
	CCollisionMesh*	CollisionMesh();
	bool			MessageSendingEnabled() const	{ return messageSendingEnabled; }
	unsigned		EntityID()						{ return Entity()->ID(); }

	void			SetPosition(const D3DXVECTOR3& iPosition) { movingEntity->SetPosition(iPosition); }

	bool			CanSendMessageToEntity()	const	{ return messageSendingEnabled; }
	bool			SendMessageToEntity(CTelegram* iTelegram);
};

}

#endif