///////////////////////////////////////////////////////////
//  SteeringBehavior_Flee_Distanced.cpp
//  Created on:      11-09-2009
//  Last modified:   11-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Flee_Distanced.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Flee_Distanced::CSteeringBehavior_Flee_Distanced(Regina::CMovingEntity *const iMovingEntity, const D3DXVECTOR2 &iTargetPosition, const float& iPanicDistance) : CSteeringBehavior("Flee_Distanced", 2, 0.9, iMovingEntity), targetPosition(iTargetPosition), sqPanicDistance(iPanicDistance*iPanicDistance)
	{
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Flee_Distanced::CalculateForce()
	{
	D3DXVECTOR2 targetDir = Entity()->PositionXZ() - TargetPosition();
	float dist = D3DXVec2LengthSq(&targetDir);
	if(dist < sqPanicDistance)
		{
		if(dist==0)
			{
			targetDir = D3DXVECTOR2(1, 0);
			}
		else
			{
			targetDir/=sqrt(dist);
			}

		targetDir *= Entity()->MaxSpeed();
		return targetDir - Entity()->VelocityXZ();
		}
	return D3DXVECTOR2(0, 0);
	}

//*****************************************************************************
