///////////////////////////////////////////////////////////
//  SteeringBehavior_Seek.cpp
//  Created on:      11-09-2009
//  Last modified:   11-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Seek.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Seek::CSteeringBehavior_Seek(Regina::CMovingEntity *const iMovingEntity, const D3DXVECTOR2 &iTargetPosition) : CSteeringBehavior("Seek", 1, 0.9, iMovingEntity), targetPosition(iTargetPosition)
	{
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Seek::CalculateForce()
	{
	D3DXVECTOR2 targetDir = TargetPosition() - Entity()->PositionXZ();
	D3DXVec2Normalize(&targetDir, &targetDir);
	targetDir *= Entity()->MaxSpeed();
	return targetDir - Entity()->VelocityXZ();
	}

//*****************************************************************************
