///////////////////////////////////////////////////////////
//  SteeringBehavior_Pursuit.h
//  Created on:      15-09-2009
//  Last modified:   15-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_PURSUIT_H
#define REGINA_STEERINGBEHAVIOR_PURSUIT_H

#include <SteeringBehavior.h>

namespace Regina
{

class CSteeringBehavior_Pursuit : public CSteeringBehavior
{
	const CMovingEntity* target;

protected:
	const CMovingEntity* Target() const { return target; }

public:
	CSteeringBehavior_Pursuit(CMovingEntity* const iMovingEntity, const CMovingEntity* iTarget);
	D3DXVECTOR2 CalculateForce();

	void SetTarget(const CMovingEntity* iTarget) { target = iTarget; }
};

}

#endif
