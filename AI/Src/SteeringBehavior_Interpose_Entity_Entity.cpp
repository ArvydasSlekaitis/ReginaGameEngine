///////////////////////////////////////////////////////////
//  SteeringBehavior_Interpose_Entity_Entity.cpp
//  Created on:      09-10-2009
//  Last modified:   09-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Interpose_Entity_Entity.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Interpose_Entity_Entity::CSteeringBehavior_Interpose_Entity_Entity(Regina::CMovingEntity *const iMovingEntity, Regina::CMovingEntity *const iTarget1, Regina::CMovingEntity *const iTarget2) : CSteeringBehavior("Interpose_Entity_Entity", 7, 0.9, iMovingEntity), target1(iTarget1), target2(iTarget2)
	{
	if(iTarget1 == NULL)
		throw invalid_argument("CSteeringBehavior_Interpose_Entity_Entity::CSteeringBehavior_Interpose_Entity_Entity - argument iTarget1==NULL");

	if(iTarget2 == NULL)
		throw invalid_argument("CSteeringBehavior_Interpose_Entity_Entity::CSteeringBehavior_Interpose_Entity_Entity - argument iTarget2==NULL");
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Interpose_Entity_Entity::CalculateForce()
	{
	if(Entity()->MaxSpeed()==0.0f)
		return D3DXVECTOR2(0, 0);

	D3DXVECTOR2 midPoint = (Target1()->PositionXZ() + Target2()->PositionXZ())/2;
	float lookAheadTime = Distance(midPoint, Entity()->PositionXZ()) / Entity()->MaxSpeed();
	D3DXVECTOR2 target1FuturePosition = Target1()->PositionXZ() + Target1()->VelocityXZ()*lookAheadTime;
	D3DXVECTOR2 target2FuturePosition = Target2()->PositionXZ() + Target2()->VelocityXZ()*lookAheadTime;
	
	midPoint = (target1FuturePosition + target2FuturePosition)/2;

	CSteeringBehavior_Arrive arrive(Entity(), midPoint, 1);
	return arrive.CalculateForce();
	}

//*****************************************************************************
