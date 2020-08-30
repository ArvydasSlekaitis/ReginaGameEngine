///////////////////////////////////////////////////////////
//  SteeringBehavior.h
//  Created on:      05-09-2009
//  Last modified:   05-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_H
#define REGINA_STEERINGBEHAVIOR_H

#include <MovingEntity.h>

namespace Regina
{

class CSteeringBehavior
{
	CMovingEntity*		const	movingEntity;
	const unsigned				priority;
	const float					weight;
	const string				name;
	
protected:
	CMovingEntity* Entity() const  { return movingEntity; }


public:
	CSteeringBehavior(const string& iName, const unsigned& iPriority, const float& iWeight, CMovingEntity* const iMovingEntity);
	virtual ~CSteeringBehavior() {}
	virtual D3DXVECTOR2 CalculateForce() = 0;
	
	unsigned	Priority()	const { return priority; }
	float		Weight()	const { return weight; }
	string		Name()		const { return name; }	
};

}

#endif
