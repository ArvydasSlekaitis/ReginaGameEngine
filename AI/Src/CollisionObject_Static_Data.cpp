///////////////////////////////////////////////////////////
//  CollisionObject_Static_Data.cpp
//  Created on:      07-09-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CollisionObject_Static_Data.h>
using namespace Regina;

//*****************************************************************************

CCollisionObject_Static_Data::CCollisionObject_Static_Data(const string& iCollisionMeshName, const D3DXMATRIXA16& iTransformation, CBaseEntity* iBaseEntity, const bool iMessageSendingEnabled) : baseEntity(iBaseEntity)
	{
	collisionMesh = new CCollisionMesh(iCollisionMeshName, iTransformation);
	messageSendingEnabled = iMessageSendingEnabled && baseEntity!=NULL;
	}

//*****************************************************************************

bool CCollisionObject_Static_Data::SendMessageToEntity(Regina::CTelegram *iTelegram)
	{
	if(iTelegram == NULL)
		throw invalid_argument("CCollisionObject_ParticlePhisics_Data::SendMessageToEntity - argument iTelegram==NULL");

	if(CanSendMessageToEntity() == true)
		{
		Entity()->HandleMsg(iTelegram);
		return true;
		}
	else
		return false;
	}

//*****************************************************************************

unsigned CCollisionObject_Static_Data::EntityID()
	{
	if(EntityExist())
		{
		return Entity()->ID();
		}
	else
		return 0;
	}

//*****************************************************************************

