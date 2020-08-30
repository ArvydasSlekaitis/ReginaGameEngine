///////////////////////////////////////////////////////////
//  SteeringBehavior_Wander.cpp
//  Created on:      14-09-2009
//  Last modified:   14-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Wander.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Wander::CSteeringBehavior_Wander(Regina::CMovingEntity *const iMovingEntity, const float& iWanderDistance, const float& iWanderRadius, const float& iWanderJitter) : CSteeringBehavior("Wander", 1, 0.9, iMovingEntity), wanderTarget(0, 0), wanderDistance(iWanderDistance), wanderRadius(iWanderRadius), wanderJitter(iWanderJitter)
	{
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Wander::CalculateForce()
	{
	wanderTarget.x += ((float(rand()%100)-50.0f)/50.0f)*wanderJitter;
	wanderTarget.y += ((float(rand()%100)-50.0f)/50.0f)*wanderJitter;
	
	D3DXVec2Normalize(&wanderTarget, &wanderTarget);

	D3DXVECTOR2 force = Entity()->Heading()*wanderRadius + wanderTarget;
	D3DXVec2Normalize(&force, &force);
	force*=Entity()->MaxSpeed();

	return force;
	}

//*****************************************************************************
