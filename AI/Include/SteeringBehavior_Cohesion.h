///////////////////////////////////////////////////////////
//  SteeringBehavior_Cohesion.h
//  Created on:      11-10-2009
//  Last modified:   11-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_COHESION_H
#define REGINA_STEERINGBEHAVIOR_COHESION_H

#include <SteeringBehavior.h>
#include <SteeringBehavior_Arrive.h>
#include <AIManager.h>
#include <Settings.h>
#include <CollisionObject_Dynamic.h>


namespace Regina
{

class CSteeringBehavior_Cohesion : public CSteeringBehavior
{
	float neighborhoodRadius;

protected:
	float NeighborhoodRadius() const { return neighborhoodRadius; }

public:
	CSteeringBehavior_Cohesion(CMovingEntity* const iMovingEntity, const float& iNeighborhoodRadius);
	D3DXVECTOR2 CalculateForce();

	void SetNeighborhoodRadius(const float& iNeighborhoodRadius) { neighborhoodRadius = iNeighborhoodRadius; }
};

}

#endif
