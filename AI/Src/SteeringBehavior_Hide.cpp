///////////////////////////////////////////////////////////
//  SteeringBehavior_Hide.h
//  Created on:      23-09-2009
//  Last modified:   23-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_Hide.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_Hide::CSteeringBehavior_Hide(Regina::CMovingEntity *const iMovingEntity, Regina::CMovingEntity *iTarget, const float& iObstacleSearchRadius) : CSteeringBehavior("Hide", 8, 0.9, iMovingEntity), target(iTarget)
	{
	if(iTarget == NULL)
		throw invalid_argument("CSteeringBehavior_Hide::CSteeringBehavior_Hide - argument iTarget==NULL");
	}

//*****************************************************************************

D3DXVECTOR2	CSteeringBehavior_Hide::GetHidingPosition(const D3DXVECTOR2& iObstaclePosition, const float& iObstacleRadius, const D3DXVECTOR2& iTargetPosition)
	{
	const float awayFromBoundary = 10;
	const float awayFromObstacle = awayFromBoundary*iObstacleRadius;
	D3DXVECTOR2 dir;
	D3DXVec2Normalize(&dir, &D3DXVECTOR2(iObstaclePosition-iTargetPosition));
	return iObstaclePosition + dir*awayFromObstacle;
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_Hide::CalculateForce()
	{
	if(Entity()->MaxSpeed()==0.0f)
		return D3DXVECTOR2(0, 0);

	vector<CCollisionObject_Static>	obstacles;
	AIManager->DetectCollision_WithStatic(Entity()->Position(), obstacleSearchRadius, obstacles);

	int closestObstacle = -1;
	float closestHideDistanceSq = numeric_limits<float>::infinity();
	D3DXVECTOR2 closestHidePosition(0, 0);

	for(unsigned i=0; i<obstacles.size(); i++)
		{
		D3DXVECTOR2 curHidePosition = GetHidingPosition(obstacles[i].PositionXZ(), obstacles[i].Radius(), Target()->PositionXZ());

		float curHideDistanceSq = Distance_Sq(Entity()->PositionXZ(), curHidePosition);
		
		if(curHideDistanceSq < closestHideDistanceSq)
			{
			closestHideDistanceSq = curHideDistanceSq;
			closestHidePosition = curHidePosition;
			closestObstacle = i;
			}
		}
	
	if(closestObstacle == -1)
		{
		CSteeringBehavior_Flee flee(Entity(), Target()->PositionXZ());
		return flee.CalculateForce();
		}
	else
		{
		CSteeringBehavior_Arrive arrive(Entity(), closestHidePosition, 1);
		return arrive.CalculateForce();
		}
	}

//*****************************************************************************
