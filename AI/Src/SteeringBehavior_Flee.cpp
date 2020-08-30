///////////////////////////////////////////////////////////
//  SteeringBehavior_Flee.cpp
//  Created on:      11-09-2009
//  Last modified:   11-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Flee.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Flee::CSteeringBehavior_Flee(Regina::CMovingEntity *const iMovingEntity, const D3DXVECTOR2 &iTargetPosition) : CSteeringBehavior("Flee", 2, 0.9, iMovingEntity), targetPosition(iTargetPosition)
	{
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Flee::CalculateForce()
	{
	D3DXVECTOR2 targetDir = Entity()->PositionXZ() - TargetPosition();
	D3DXVec2Normalize(&targetDir, &targetDir);
	targetDir *= Entity()->MaxSpeed();
	return targetDir - Entity()->VelocityXZ();
	}

//*****************************************************************************
