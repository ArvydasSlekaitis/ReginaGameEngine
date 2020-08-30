///////////////////////////////////////////////////////////
//  SteeringBehavior_Wander.h
//  Created on:      14-09-2009
//  Last modified:   14-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_WANDER_H
#define REGINA_STEERINGBEHAVIOR_WANDER_H

#include <SteeringBehavior.h>

namespace Regina
{

class CSteeringBehavior_Wander : public CSteeringBehavior
{
	float		wanderDistance;
	float		wanderRadius;
	float		wanderJitter;

	D3DXVECTOR2 wanderTarget;
	
protected:
	float WanderDistance()	const { return wanderDistance; }
	float WanderRadius()	const { return wanderRadius; }
	float WanderJitter()	const { return wanderJitter; }

public:
	CSteeringBehavior_Wander(CMovingEntity* const iMovingEntity, const float& iWanderDistance, const float& iWanderRadius, const float& iWanderJitter);
	D3DXVECTOR2 CalculateForce();

	void SetWanderDistance(const float& iWanderDistance) { wanderDistance = iWanderDistance; }
	void SetWanderRadius(const float& iWanderRadius) { wanderRadius = iWanderRadius; }
	void SetWanderJitter(const float& iWanderJitter) { wanderJitter = iWanderJitter; }
};

}

#endif
