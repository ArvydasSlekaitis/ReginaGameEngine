///////////////////////////////////////////////////////////
//  SimpleMovingEntity.cpp
//  Created on:      23-09-2009
//  Last modified:   23-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SimpleMovingEntity.h>
using namespace Regina;

//*****************************************************************************

CSimpleMovingEntity::CSimpleMovingEntity(const std::string &iCollisionMeshName, const std::string iClassName, const unsigned int iType) : collisionDetectionEnabled(false)
	{
	D3DXMatrixIdentity(&transformation);
	D3DXMatrixIdentity(&inverseTransformation);
	collisionMesh = new CCollisionMesh(iCollisionMeshName, transformation);
	}

//*****************************************************************************

void CSimpleMovingEntity::SetTransform(const D3DXMATRIXA16& iTransformation)
	{
	transformation = iTransformation;
	D3DXMatrixInverse(&inverseTransformation, NULL, &transformation);
	collisionMesh->SetTransform(transformation, inverseTransformation);
	}

//*****************************************************************************

void CSimpleMovingEntity::SetTransform(const D3DXMATRIXA16& iTransformation, const D3DXMATRIXA16& iInverseTransformation)
	{
	transformation = iTransformation;
	inverseTransformation = iInverseTransformation;
	collisionMesh->SetTransform(transformation, inverseTransformation);
	}

//*****************************************************************************

void CSimpleMovingEntity::SetTransform(const D3DXVECTOR3& iPosition)
	{
	transformation._41 = iPosition.x;
	transformation._42 = iPosition.y;
	transformation._43 = iPosition.z;
	inverseTransformation._41 = -iPosition.x;
	inverseTransformation._42 = -iPosition.y;
	inverseTransformation._43 = -iPosition.z;
	collisionMesh->SetTransform(transformation, inverseTransformation);
	}

//*****************************************************************************

void CSimpleMovingEntity::SetTransform(const D3DXVECTOR3& iPosition, const D3DXVECTOR2& iHeading)
	{
	float rot =  VectorToRotation(iHeading);
	transformation = Transform(iPosition, 1, rot);
	D3DXMatrixInverse(&inverseTransformation, NULL, &transformation);
	collisionMesh->SetTransform(transformation, inverseTransformation);
	}

//*****************************************************************************

void CSimpleMovingEntity::EnableCollisionDetection(const bool iMessageSendingEnabled)
	{
	if(!collisionDetectionEnabled)
		{
		AIManager->AddCollisionObject_Dynamic(CollisionMesh(), this, iMessageSendingEnabled); 
		collisionDetectionEnabled = true;
		}
	}

//*****************************************************************************

void CSimpleMovingEntity::DisableCollisionDetection(const bool iMessageSendingEnabled)
	{
	if(collisionDetectionEnabled)
		{
		AIManager->RemoveCollisionObject_Dynamic(CollisionMesh(), this);
		collisionDetectionEnabled = false;
		}
	}

//*****************************************************************************

CSimpleMovingEntity::~CSimpleMovingEntity()
	{
	DisableCollisionDetection();
	delete collisionMesh;
	collisionMesh = NULL;
	}

//*****************************************************************************
