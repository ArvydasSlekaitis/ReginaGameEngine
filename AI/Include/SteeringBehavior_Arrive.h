///////////////////////////////////////////////////////////
//  SteeringBehavior_Arrive.h
//  Created on:      14-09-2009
//  Last modified:   14-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_ARRIVE_H
#define REGINA_STEERINGBEHAVIOR_ARRIVE_H

#include <assert.h>

#include <SteeringBehavior.h>

namespace Regina
{

class CSteeringBehavior_Arrive : public CSteeringBehavior
{
	D3DXVECTOR2 targetPosition;
	unsigned	targetSpeed; // 3 - slow, 2 normal, 1 fast
	
protected:
	D3DXVECTOR2 TargetPosition()	const { return targetPosition; }
	unsigned	TargetSpeed()		const { return targetSpeed; } // 3 - slow, 2 normal, 1 fast

public:
	CSteeringBehavior_Arrive(CMovingEntity* const iMovingEntity, const D3DXVECTOR2& iTargetPosition, const unsigned& iTargetSpeed);
	D3DXVECTOR2 CalculateForce();

	void SetTargetPosition(const D3DXVECTOR2& iTargetPosition) { targetPosition = iTargetPosition; }
	void SetTargetSpeed(const unsigned& iTargetSpeed) { targetSpeed = iTargetSpeed; }
};

}

#endif
