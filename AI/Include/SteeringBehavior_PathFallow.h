///////////////////////////////////////////////////////////
//  SteeringBehavior_PathFallow.h
//  Created on:      11-10-2009
//  Last modified:   11-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_PATHFALLOW_H
#define REGINA_STEERINGBEHAVIOR_PATHFALLOW_H

#include <SteeringBehavior.h>
#include <SteeringBehavior_Arrive.h>
#include <SteeringBehavior_Seek.h>
#include <SteeringBehavior.h>
#include <Functions_Math.h>

namespace Regina
{

class CSteeringBehavior_PathFallow : public CSteeringBehavior
{
	vector<D3DXVECTOR2>	waypoints;
	unsigned			curWaypoint;
	bool				loop;
	float				waypointSeekDistanceSq;
	
	float		DistanceToNextWaypointSq();
	bool		ExistNextWaypoint();
	void		SetNextWaypoint();
	unsigned	CurWaypoint()				const { return curWaypoint; }
	bool		Loop()						const { return loop; }
	float		WaypointSeekDistanceSq()	const { return waypointSeekDistanceSq; }

public:
	CSteeringBehavior_PathFallow(CMovingEntity* const iMovingEntity, const vector<D3DXVECTOR2>& iWaypoints, const bool& iLoop, const float& iWaypointSeekDistance);
	D3DXVECTOR2 CalculateForce();

	void SetWaypoints(const vector<D3DXVECTOR2>& iWaypoints) { waypoints = iWaypoints; }
	void SetCurWaypoint(const unsigned& iCurWaypoint) { curWaypoint = iCurWaypoint; }
	void SetLoop(const bool& iLoop) { loop = iLoop; }
	void SetWaypointSeekDistance(const float& iWaypointSeekDistance) { waypointSeekDistanceSq = iWaypointSeekDistance*iWaypointSeekDistance; }
};

}

#endif
