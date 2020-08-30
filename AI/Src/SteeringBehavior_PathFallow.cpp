///////////////////////////////////////////////////////////
//  SteeringBehavior_PathFallow.cpp
//  Created on:      11-10-2009
//  Last modified:   11-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior_PathFallow.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior_PathFallow::CSteeringBehavior_PathFallow(Regina::CMovingEntity* const iMovingEntity, const vector<D3DXVECTOR2>& iWaypoints, const bool& iLoop, const float& iWaypointSeekDistance) : CSteeringBehavior("PathFallow", 6, 0.9, iMovingEntity), waypoints(iWaypoints), loop(iLoop), waypointSeekDistanceSq(iWaypointSeekDistance*iWaypointSeekDistance), curWaypoint(0)
	{
	}

//*****************************************************************************

float CSteeringBehavior_PathFallow::DistanceToNextWaypointSq()
	{
	return Distance_Sq(Entity()->PositionXZ(), waypoints[curWaypoint]);
	}

//*****************************************************************************

bool CSteeringBehavior_PathFallow::ExistNextWaypoint()
	{
	if(curWaypoint+1 >= waypoints.size())
		{
		if(Loop()==true)
			{
			return true;
			}
		else
			return false;
		}
	else
		return true;
	}

//*****************************************************************************

void CSteeringBehavior_PathFallow::SetNextWaypoint()
	{
	curWaypoint++;

	if(curWaypoint >= waypoints.size())
		{
		if(Loop()==true)
			{
			curWaypoint=0;	
			}
		else
			assert(false);
		}
	}

//*****************************************************************************

D3DXVECTOR2 CSteeringBehavior_PathFallow::CalculateForce()
	{
	if(DistanceToNextWaypointSq() < WaypointSeekDistanceSq())
		{
		if(ExistNextWaypoint() == true)
			{
			SetNextWaypoint();
			}
		}
	if(ExistNextWaypoint() == true)
		{
		CSteeringBehavior_Seek seek(Entity(), waypoints[CurWaypoint()]);
		return seek.CalculateForce();
		}
	else
		{
		CSteeringBehavior_Arrive arrive(Entity(), waypoints[CurWaypoint()], 2);
		return arrive.CalculateForce();
		}
	}

//*****************************************************************************
