///////////////////////////////////////////////////////////
//  SteeringBehavior_WallAvoidance.cpp
//  Created on:      04-10-2009
//  Last modified:   04-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_WallAvoidance.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_WallAvoidance::CSteeringBehavior_WallAvoidance(Regina::CMovingEntity *const iMovingEntity) : CSteeringBehavior("WallAvoidance", 10, 1, iMovingEntity)
	{
	}

//*****************************************************************************

void CSteeringBehavior_WallAvoidance::GetFeelers(vector<D3DXVECTOR3>& oFeelers)
	{
	const float detBoxLength = max(Entity()->RadiusXZ(), (Entity()->Speed()/Entity()->MaxSpeed())*Settings->GetParameter("MaxEntityDetectionBoxLength"));
	D3DXVECTOR3 feelerWorldPosition;
	//1 Feeler
	D3DXVec3TransformCoord(&feelerWorldPosition, &D3DXVECTOR3(0, 0, detBoxLength), &(Entity()->Transformation()));
	oFeelers.push_back(feelerWorldPosition);
	//2 Feeler
	D3DXVec3TransformCoord(&feelerWorldPosition, &D3DXVECTOR3(detBoxLength/2, 0, detBoxLength/2), &(Entity()->Transformation()));
	oFeelers.push_back(feelerWorldPosition);
	//3 Feeler
	D3DXVec3TransformCoord(&feelerWorldPosition, &D3DXVECTOR3(-detBoxLength/2, 0, detBoxLength/2), &(Entity()->Transformation()));
	oFeelers.push_back(feelerWorldPosition);
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_WallAvoidance::CalculateForce()
	{
	if(Entity()->MaxSpeed()==0.0f)
		return D3DXVECTOR2(0, 0);

	int			closestFeeler = -1;
	int			closestWall = -1;
	D3DXVECTOR2 closestIntersectionPoint(0, 0);
	float		closestIntersectionDistanceSq = numeric_limits<float>::infinity();


	vector<D3DXVECTOR3> feelers;
	GetFeelers(feelers);
		
	const float detBoxLength = max(Entity()->RadiusXZ(), (Entity()->Speed()/Entity()->MaxSpeed())*Settings->GetParameter("MaxEntityDetectionBoxLength"));

	vector<CWall_2D>	walls;
	vector<CDoor_2D>	doors;
	AIManager->DetectCollision_WithWalls(Entity()->Position(), detBoxLength, walls);
	AIManager->DetectCollision_WithDoors(Entity()->Position(), detBoxLength, doors);

	for(unsigned i=0; i<doors.size(); i++)
		walls.push_back(doors[i].Wall_2D());

	for(unsigned i =0; i<feelers.size(); i++)
		{

		for(unsigned ii=0; ii<walls.size(); ii++)
			{
			float curIntersectionDistanceSq;
			D3DXVECTOR2 curIntersectionPoint;
			
			bool exist = walls[ii].Intersect(Entity()->PositionXZ(), D3DXVECTOR2(feelers[i].x, feelers[i].z), &curIntersectionPoint);

			if(exist)
				{
				float curIntersectionDistanceSq = Distance_Sq(Entity()->PositionXZ(), curIntersectionPoint);
				if(curIntersectionDistanceSq < closestIntersectionDistanceSq)
					{
					closestIntersectionDistanceSq = curIntersectionDistanceSq;
					closestIntersectionPoint = curIntersectionPoint;
					closestFeeler = i;
					closestWall = ii;
					}
				}

			}

		}

	float closestIntersectionDistance = min(sqrt(closestIntersectionDistanceSq), detBoxLength);

	if(closestWall >= 0)
		{
		return walls[closestWall].Normal() * max(detBoxLength-closestIntersectionDistance, Entity()->Radius());
		}
	else
		return D3DXVECTOR2(0, 0);

	}

//*****************************************************************************
