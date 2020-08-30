///////////////////////////////////////////////////////////
//  SteeringBehavior_Separation.cpp
//  Created on:      11-10-2009
//  Last modified:   11-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Separation.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Separation::CSteeringBehavior_Separation(Regina::CMovingEntity *const iMovingEntity, const float& iNeighborhoodRadius) : CSteeringBehavior("Separation", 9, 0.9, iMovingEntity), neighborhoodRadius(iNeighborhoodRadius)
	{
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Separation::CalculateForce()
	{
	D3DXVECTOR2 force(0, 0);

	vector<CCollisionObject_Dynamic>	dynamics;
	AIManager->DetectCollision_WithDynamic(Entity()->Position(), neighborhoodRadius, dynamics);

	for(unsigned i=0; i<dynamics.size(); i++)
		if(dynamics[i].EntityID()!=Entity()->ID())
			{
			D3DXVECTOR2 dir = Entity()->PositionXZ() - dynamics[i].PositionXZ();
			float dist = D3DXVec2Length(&dir);
			if(dist!=0)
			force+= *D3DXVec2Normalize(&dir, &dir)/dist;
			}

	return force;
	}

//*****************************************************************************
