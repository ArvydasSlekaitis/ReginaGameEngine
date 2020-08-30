///////////////////////////////////////////////////////////
//  SteeringBehavior_Cohesion.h
//  Created on:      11-10-2009
//  Last modified:   11-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Cohesion.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Cohesion::CSteeringBehavior_Cohesion(Regina::CMovingEntity *const iMovingEntity, const float& iNeighborhoodRadius) : CSteeringBehavior("Cohesion", 9, 0.9, iMovingEntity), neighborhoodRadius(iNeighborhoodRadius)
	{
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Cohesion::CalculateForce()
	{
	D3DXVECTOR2 totalPosition(0, 0);
	unsigned	numDynamics(0);

	vector<CCollisionObject_Dynamic>	dynamics;
	AIManager->DetectCollision_WithDynamic(Entity()->Position(), neighborhoodRadius, dynamics);

	for(unsigned i=0; i<dynamics.size(); i++)
		{
		numDynamics++;
		totalPosition+=dynamics[i].PositionXZ();
		}

	if(numDynamics>0)
		{
		totalPosition/=numDynamics;

		CSteeringBehavior_Arrive arrive(Entity(), totalPosition, 2);
		return arrive.CalculateForce();				
		}

	return totalPosition;
	}

//*****************************************************************************
