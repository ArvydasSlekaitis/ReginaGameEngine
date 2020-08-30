///////////////////////////////////////////////////////////
//  SteeringBehavior_WallAvoidance.h
//  Created on:      04-10-2009
//  Last modified:   04-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_WALLAVOIDANCE_H
#define REGINA_STEERINGBEHAVIOR_WALLAVOIDANCE_H

#include <SteeringBehavior.h>
#include <AIManager.h>
#include <Settings.h>
#include <Wall_2D.h>
#include <Door_2D.h>

namespace Regina
{

class CSteeringBehavior_WallAvoidance : public CSteeringBehavior
{
	void GetFeelers(vector<D3DXVECTOR3>& oFeelers);

public:
	CSteeringBehavior_WallAvoidance(CMovingEntity* const iMovingEntity);
	D3DXVECTOR2 CalculateForce();
};

}

#endif
