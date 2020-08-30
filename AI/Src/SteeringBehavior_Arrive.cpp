///////////////////////////////////////////////////////////
//  SteeringBehavior_Arrive.cpp
//  Created on:      14-09-2009
//  Last modified:   14-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Arrive.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Arrive::CSteeringBehavior_Arrive(Regina::CMovingEntity *const iMovingEntity, const D3DXVECTOR2 &iTargetPosition, const unsigned& iTargetSpeed) : CSteeringBehavior("Arrive", 1, 0.9, iMovingEntity), targetPosition(iTargetPosition), targetSpeed(iTargetSpeed)
	{
	assert(targetSpeed!=0);
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Arrive::CalculateForce()
	{
	D3DXVECTOR2 targetDir = TargetPosition() - Entity()->PositionXZ();
	const float dist = D3DXVec2Length(&targetDir);
	if(dist > 0)
		{
		const float decelerationTweaker = 0.3;
		float speed = dist / (float(TargetSpeed())*decelerationTweaker);
		speed = min(speed, Entity()->MaxSpeed());
		D3DXVECTOR2 desiredVelocity = targetDir * speed / dist; 
		return desiredVelocity - Entity()->VelocityXZ();
		}
	else
	return D3DXVECTOR2(0, 0);
	}

//*****************************************************************************
