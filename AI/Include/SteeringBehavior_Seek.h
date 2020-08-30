///////////////////////////////////////////////////////////
//  SteeringBehavior_Seek.h
//  Created on:      11-09-2009
//  Last modified:   11-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_SEEK_H
#define REGINA_STEERINGBEHAVIOR_SEEK_H

#include <SteeringBehavior.h>

namespace Regina
{

class CSteeringBehavior_Seek : public CSteeringBehavior
{
	D3DXVECTOR2 targetPosition;
	
protected:
	D3DXVECTOR2 TargetPosition() const { return targetPosition; }

public:
	CSteeringBehavior_Seek(CMovingEntity* const iMovingEntity, const D3DXVECTOR2& iTargetPosition);
	D3DXVECTOR2 CalculateForce();

	void SetTargetPosition(const D3DXVECTOR2& iTargetPosition) { targetPosition = iTargetPosition; }
};

}

#endif
