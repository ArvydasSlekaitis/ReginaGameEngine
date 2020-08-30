///////////////////////////////////////////////////////////
//  CollisionObject_Dynamic_Data.cpp
//  Created on:      07-09-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CollisionObject_Dynamic_Data.h>
using namespace Regina;

//*****************************************************************************

CCollisionObject_Dynamic_Data::CCollisionObject_Dynamic_Data(const string& iCollisionMeshName, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled) : movingEntity(iMovingEntity), messageSendingEnabled(iMessageSendingEnabled)
	{
	if(movingEntity == NULL)
		throw invalid_argument("CCollisionObject_Dynamic_Data::CCollisionObject_Dynamic_Data - argument iMovingEntity==NULL");

	collisionMesh = new CCollisionMesh(iCollisionMeshName, movingEntity->Transformation());
	collisionMeshOwner = true;
	}

//*****************************************************************************

CCollisionObject_Dynamic_Data::CCollisionObject_Dynamic_Data(CCollisionMesh* iCollisionMesh, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled) : movingEntity(iMovingEntity), messageSendingEnabled(iMessageSendingEnabled)
	{
	if(movingEntity == NULL)
		throw invalid_argument("CCollisionObject_Dynamic_Data::CCollisionObject_Dynamic_Data - argument iMovingEntity==NULL");

	collisionMesh = iCollisionMesh;
	collisionMeshOwner = false;
	}

//*****************************************************************************

bool CCollisionObject_Dynamic_Data::SendMessageToEntity(Regina::CTelegram *iTelegram)
	{
	if(iTelegram == NULL)
		throw invalid_argument("CCollisionObject_Dynamic_Data::SendMessageToEntity - argument iTelegram==NULL");

	if(CanSendMessageToEntity() == true)
		{
		Entity()->HandleMsg(iTelegram);
		return true;
		}
	else
		return false;
	}

//*****************************************************************************

float CCollisionObject_Dynamic_Data::Radius()
	{
	if(collisionMeshOwner)
	if(collisionMesh->Transformation() != Entity()->Transformation())
		collisionMesh->SetTransform(Entity()->Transformation());

	return collisionMesh->RadiusXZ();
	}

//*****************************************************************************

CCollisionMesh*	CCollisionObject_Dynamic_Data::CollisionMesh()
	{
	if(collisionMeshOwner)
	if(collisionMesh->Transformation() != Entity()->Transformation())
		collisionMesh->SetTransform(Entity()->Transformation(), Entity()->InverseTransformation());

	return collisionMesh;
	}
	
//*****************************************************************************

CCollisionObject_Dynamic_Data::~CCollisionObject_Dynamic_Data()
	{
	if(collisionMeshOwner==true)
		delete collisionMesh;

	collisionMesh=NULL;
	}	

//*****************************************************************************

