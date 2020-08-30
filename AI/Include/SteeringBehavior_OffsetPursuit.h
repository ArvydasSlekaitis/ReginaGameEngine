///////////////////////////////////////////////////////////
//  SteeringBehavior_OffsetPursuit.h
//  Created on:      11-10-2009
//  Last modified:   11-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_OFFSETPURSUIT_H
#define REGINA_STEERINGBEHAVIOR_OFFSETPURSUIT_H

#include <SteeringBehavior.h>
#include <SteeringBehavior_Arrive.h>
#include <Functions_Math.h>

namespace Regina
{

class CSteeringBehavior_OffsetPursuit : public CSteeringBehavior
{
	const CMovingEntity*	leader;
	D3DXVECTOR2				offset;

protected:
	const CMovingEntity*	Leader() const { return leader; }
	D3DXVECTOR2				Offset() const { return offset; }

public:
	CSteeringBehavior_OffsetPursuit(CMovingEntity* const iMovingEntity, const CMovingEntity* iLeader, const D3DXVECTOR2& iOffset);
	D3DXVECTOR2 CalculateForce();

	void SetLeader(const CMovingEntity* iLeader) { leader = iLeader; }
	void SetOffset(const D3DXVECTOR2& iOffset) { offset = iOffset; }
};

}

#endif
