///////////////////////////////////////////////////////////
//  CollisionObject_ParticlePhisics_Data.cpp
//  Created on:      22-07-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CollisionObject_ParticlePhisics_Data.h>
using namespace Regina;

//*****************************************************************************
	
CCollisionObject_ParticlePhisics_Data::CCollisionObject_ParticlePhisics_Data(CParticlePhisics* iParticlePhisics, const float& iRadius, const float& iRestitution, CBaseEntity* iBaseEntity,  const bool iMessageSendingEnabled) : radius(iRadius), restitution(iRestitution), baseEntity(iBaseEntity)
	{
	if(iParticlePhisics == NULL)
		throw invalid_argument("CCollisionObject_ParticlePhisics_Data::CCollisionObject_ParticlePhisics_Data - argument iParticlePhisics==NULL");
	else
		particlePhisics = iParticlePhisics;

	messageSendingEnabled = iMessageSendingEnabled && baseEntity!=NULL;
	}


//*****************************************************************************

bool CCollisionObject_ParticlePhisics_Data::SendMessageToEntity(Regina::CTelegram *iTelegram)
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

unsigned CCollisionObject_ParticlePhisics_Data::EntityID()
	{
	if(EntityExist())
		{
		return Entity()->ID();
		}
	else
		return 0;
	}

//*****************************************************************************

