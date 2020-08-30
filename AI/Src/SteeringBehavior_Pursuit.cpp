///////////////////////////////////////////////////////////
//  SteeringBehavior_Pursuit.cpp
//  Created on:      15-09-2009
//  Last modified:   15-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Pursuit.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Pursuit::CSteeringBehavior_Pursuit(Regina::CMovingEntity *const iMovingEntity, const Regina::CMovingEntity* iTarget) : CSteeringBehavior("Pursuit", 4, 0.9, iMovingEntity), target(iTarget)
	{
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Pursuit::CalculateForce()
	{
	D3DXVECTOR2 targetDir = Target()->PositionXZ() - Entity()->PositionXZ();
	float dist = D3DXVec2Length(&targetDir);
	
	if(dist <= 0) return D3DXVECTOR2(0, 0);

	float lookAheadTime = dist / ( Entity()->MaxSpeed() + Target()->MaxSpeed());

	D3DXVECTOR2 tnormvel;
	D3DXVec2Normalize(&tnormvel, &Target()->VelocityXZ());

	D3DXVECTOR2 newTargetPos = Target()->PositionXZ() + tnormvel*lookAheadTime;
	D3DXVECTOR2 newTargetDir = newTargetPos  - Entity()->PositionXZ();

	D3DXVec2Normalize(&newTargetDir, &newTargetDir);
	newTargetDir *= Entity()->MaxSpeed();
	return newTargetDir - Entity()->VelocityXZ();
	}

//*****************************************************************************
