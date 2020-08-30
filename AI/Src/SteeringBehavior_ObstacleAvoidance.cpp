///////////////////////////////////////////////////////////
//  SteeringBehavior_ObstacleAvoidance.cpp
//  Created on:      23-09-2009
//  Last modified:   23-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_ObstacleAvoidance.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_ObstacleAvoidance::CSteeringBehavior_ObstacleAvoidance(Regina::CMovingEntity *const iMovingEntity) : CSteeringBehavior("ObstacleAvoidance", 10, 0.9, iMovingEntity)
	{
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_ObstacleAvoidance::CalculateForce()
	{
	if(Entity()->MaxSpeed()==0.0f)
		return D3DXVECTOR2(0, 0);

	const float detBoxLength = max(Entity()->RadiusXZ(), (Entity()->Speed()/Entity()->MaxSpeed())*Settings->GetParameter("MaxEntityDetectionBoxLength"));
	
	vector<CCollisionObject_Static>	obstacles;
	AIManager->DetectCollision_WithStatic(Entity()->Position(), detBoxLength, obstacles);

	int closestObstacle = -1;
	float closestIntersectionPointZ = numeric_limits<float>::infinity();
	D3DXVECTOR3 localPositionOfClosestObstacle(0, 0, 0);

	for(unsigned i=0; i<obstacles.size(); i++)
		{
		D3DXVECTOR3 localPos;  //Local to entity

		D3DXVec3TransformCoord(&localPos, &obstacles[i].Position(), &(Entity()->InverseTransformation()));

		if(localPos.z < 0)
			{
			float dist = sqrt(localPos.x*localPos.x + localPos.z*localPos.z);
			if(dist > Entity()->RadiusXZ() + obstacles[i].Radius())
				continue;
			else
				{
				closestObstacle = i;
				closestIntersectionPointZ = 0;
				localPositionOfClosestObstacle = localPos;
				break;
				}
			}

		if(abs(localPos.x)-obstacles[i].Radius() > Entity()->RadiusXZ())
			continue;

		float root = sqrt(obstacles[i].Radius()*obstacles[i].Radius() - localPos.x*localPos.x);

		float curInterPointZ = localPos.z - root;

		if(curInterPointZ < 0)
			{
			curInterPointZ = localPos.z + root;
			}

		if(curInterPointZ > detBoxLength)
			{
			closestObstacle = i;
			closestIntersectionPointZ = 0;
			localPositionOfClosestObstacle = localPos;
			break;
			}

		if(curInterPointZ < closestIntersectionPointZ)
			{
			closestObstacle = i;
			closestIntersectionPointZ = curInterPointZ;
			localPositionOfClosestObstacle = localPos;
			}

		}

	D3DXVECTOR2 force(0, 0);

	if(closestObstacle != -1)
		{
		float multiplier = 1+(detBoxLength-closestIntersectionPointZ)/detBoxLength;

		//latheral force
		force.x = -(localPositionOfClosestObstacle.x - obstacles[closestObstacle].Radius() - Entity()->RadiusXZ()) * multiplier;
				
		//breaking force
		const float breakingWeight = 0.2;
		force.y = min(0, -(localPositionOfClosestObstacle.z - obstacles[closestObstacle].Radius())) * breakingWeight;

		D3DXVECTOR3 worldForce;
		D3DXVec3TransformCoord(&worldForce, &D3DXVECTOR3(force.x, 0, force.y), &(Entity()->Transformation()));
		worldForce-=Entity()->Position();
		
		force.x = worldForce.x;
		force.y = worldForce.z;
		}

	return force;
	}

//*****************************************************************************
