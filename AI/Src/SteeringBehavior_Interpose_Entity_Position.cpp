///////////////////////////////////////////////////////////
//  SteeringBehavior_Interpose_Entity_Position.cpp
//  Created on:      09-10-2009
//  Last modified:   09-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Interpose_Entity_Position.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Interpose_Entity_Position::CSteeringBehavior_Interpose_Entity_Position(Regina::CMovingEntity *const iMovingEntity, Regina::CMovingEntity *const iTarget1, const D3DXVECTOR2& iTarget2) : CSteeringBehavior("Interpose_Entity_Position", 7, 0.9, iMovingEntity), target1(iTarget1), target2(iTarget2)
	{
	if(iTarget1 == NULL)
		throw invalid_argument("CSteeringBehavior_Interpose_Entity_Entity::CSteeringBehavior_Interpose_Entity_Entity - argument iTarget1==NULL");
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Interpose_Entity_Position::CalculateForce()
	{
	if(Entity()->MaxSpeed()==0.0f)
		return D3DXVECTOR2(0, 0);

	D3DXVECTOR2 midPoint = (Target1()->PositionXZ() + Target2())/2;
	float lookAheadTime = Distance(midPoint, Entity()->PositionXZ()) / Entity()->MaxSpeed();
	D3DXVECTOR2 target1FuturePosition = Target1()->PositionXZ() + Target1()->VelocityXZ()*lookAheadTime;
	
	midPoint = (target1FuturePosition + Target2())/2;

	CSteeringBehavior_Arrive arrive(Entity(), midPoint, 1);
	return arrive.CalculateForce();
	}

//*****************************************************************************
