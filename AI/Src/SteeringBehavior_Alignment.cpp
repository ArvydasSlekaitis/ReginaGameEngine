///////////////////////////////////////////////////////////
//  SteeringBehavior_Alignment.cpp
//  Created on:      11-10-2009
//  Last modified:   11-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Alignment.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Alignment::CSteeringBehavior_Alignment(Regina::CMovingEntity *const iMovingEntity, const float& iNeighborhoodRadius) : CSteeringBehavior("Alignment", 9, 0.9, iMovingEntity), neighborhoodRadius(iNeighborhoodRadius)
	{
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Alignment::CalculateForce()
	{
	D3DXVECTOR2 totalHeading(0, 0);
	unsigned	numDynamics(0);

	vector<CCollisionObject_Dynamic>	dynamics;
	AIManager->DetectCollision_WithDynamic(Entity()->Position(), neighborhoodRadius, dynamics);

	for(unsigned i=0; i<dynamics.size(); i++)
		if(dynamics[i].EntityID()!=Entity()->ID())
			{
			numDynamics++;
			totalHeading+=dynamics[i].Heading();
			}

	if(numDynamics>0)
		{
		totalHeading/=numDynamics;
		totalHeading-=Entity()->Heading();
		}

	return totalHeading;
	}

//*****************************************************************************
