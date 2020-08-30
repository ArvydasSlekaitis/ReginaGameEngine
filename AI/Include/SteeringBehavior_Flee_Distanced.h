///////////////////////////////////////////////////////////
//  SteeringBehavior_Flee_Distanced.h
//  Created on:      11-09-2009
//  Last modified:   11-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_FLEE_DISTANCED_H
#define REGINA_STEERINGBEHAVIOR_FLEE_DISTANCED_H

#include <SteeringBehavior.h>

namespace Regina
{

class CSteeringBehavior_Flee_Distanced : public CSteeringBehavior
{
	D3DXVECTOR2 targetPosition;
	float		sqPanicDistance;
	
protected:
	D3DXVECTOR2 TargetPosition() const { return targetPosition; }
	float		PanicDistance() const { return sqrt(sqPanicDistance); }

public:
	CSteeringBehavior_Flee_Distanced(CMovingEntity* const iMovingEntity, const D3DXVECTOR2& iTargetPosition, const float& iPanicDistance);
	D3DXVECTOR2 CalculateForce();

	void SetTargetPosition(const D3DXVECTOR2& iTargetPosition) { targetPosition = iTargetPosition; }
	void SetPanicDistance(const float& iPanicDistance) { sqPanicDistance = iPanicDistance*iPanicDistance; }
};

}

#endif
