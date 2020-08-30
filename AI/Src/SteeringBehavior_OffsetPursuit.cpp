///////////////////////////////////////////////////////////
//  SteeringBehavior_OffsetPursuit.cpp
//  Created on:      11-10-2009
//  Last modified:   11-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_OffsetPursuit.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_OffsetPursuit::CSteeringBehavior_OffsetPursuit(CMovingEntity* const iMovingEntity, const CMovingEntity* iLeader, const D3DXVECTOR2& iOffset) : CSteeringBehavior("OffsetPursuit", 6, 0.9, iMovingEntity), leader(iLeader), offset(iOffset)
	{
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_OffsetPursuit::CalculateForce()
	{
	D3DXVECTOR3 worldOffset;
	D3DXVec3TransformCoord(&worldOffset, &D3DXVECTOR3(Offset().x, 0, Offset().y), &(Leader()->Transformation()));
	float lookAheadTime = Distance(worldOffset.x, worldOffset.y, Entity()->PositionXZ().x, Entity()->PositionXZ().y) / ( Entity()->MaxSpeed() + Leader()->Speed());
	CSteeringBehavior_Arrive arrive(Entity(), D3DXVECTOR2(worldOffset.x, worldOffset.z), 1);
	return arrive.CalculateForce();
	}

//*****************************************************************************
