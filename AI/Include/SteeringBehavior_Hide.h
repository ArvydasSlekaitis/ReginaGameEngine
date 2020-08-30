///////////////////////////////////////////////////////////
//  SteeringBehavior_Hide.h
//  Created on:      23-09-2009
//  Last modified:   23-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_HIDE_H
#define REGINA_STEERINGBEHAVIOR_HIDE_H

#include <SteeringBehavior.h>
#include <AIManager.h>
#include <Settings.h>
#include <CollisionObject_Static.h>
#include <SteeringBehavior_Flee.h>
#include <SteeringBehavior_Arrive.h>

namespace Regina
{

class CSteeringBehavior_Hide : public CSteeringBehavior
{
	CMovingEntity*	target;
	float			obstacleSearchRadius;

	D3DXVECTOR2		GetHidingPosition(const D3DXVECTOR2& iObstaclePosition, const float& iObstacleRadius, const D3DXVECTOR2& iTargetPosition);
	
	CMovingEntity*	Target() { return target; }
	float			ObstacleSearchRadius() const { return obstacleSearchRadius; }

public:
	CSteeringBehavior_Hide(CMovingEntity* const iMovingEntity, CMovingEntity* iTarget, const float& iObstacleSearchRadius);
	D3DXVECTOR2 CalculateForce();

	void SetTarget(CMovingEntity* iTarget) { target = iTarget; }
	void SetObstacleSearchRadius(const float& iObstacleSearchRadius) { obstacleSearchRadius = iObstacleSearchRadius; }
};

}

#endif
