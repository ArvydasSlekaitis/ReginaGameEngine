///////////////////////////////////////////////////////////
//  SteeringBehavior_Evade.h
//  Created on:      15-09-2009
//  Last modified:   15-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_EVADE_H
#define REGINA_STEERINGBEHAVIOR_EVADE_H

#include <SteeringBehavior.h>

namespace Regina
{

class CSteeringBehavior_Evade : public CSteeringBehavior
{
	const CMovingEntity* target;

protected:
	const CMovingEntity* Target() const { return target; }

public:
	CSteeringBehavior_Evade(CMovingEntity* const iMovingEntity, const CMovingEntity* iTarget);
	D3DXVECTOR2 CalculateForce();

	void SetTarget(const CMovingEntity* iTarget) { target = iTarget; }
};

}

#endif
