///////////////////////////////////////////////////////////
//  SteeringBehavior_ObstacleAvoidance.h
//  Created on:      23-09-2009
//  Last modified:   23-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_OBSTACLEAVOIDANCE_H
#define REGINA_STEERINGBEHAVIOR_OBSTACLEAVOIDANCE_H

#include <SteeringBehavior.h>
#include <AIManager.h>
#include <Settings.h>
#include <CollisionObject_Static.h>

namespace Regina
{

class CSteeringBehavior_ObstacleAvoidance : public CSteeringBehavior
{
public:
	CSteeringBehavior_ObstacleAvoidance(CMovingEntity* const iMovingEntity);
	D3DXVECTOR2 CalculateForce();
};

}

#endif
