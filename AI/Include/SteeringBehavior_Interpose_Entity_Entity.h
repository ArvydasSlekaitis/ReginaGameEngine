///////////////////////////////////////////////////////////
//  SteeringBehavior_Interpose_Entity_Entity.h
//  Created on:      09-10-2009
//  Last modified:   09-10-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIOR_INTERPOSE_ENTITY_ENTITY_H
#define REGINA_STEERINGBEHAVIOR_INTERPOSE_ENTITY_ENTITY_H

#include <SteeringBehavior.h>
#include <AIManager.h>
#include <Settings.h>
#include <SteeringBehavior_Arrive.h>

namespace Regina
{

class CSteeringBehavior_Interpose_Entity_Entity : public CSteeringBehavior
{
	CMovingEntity*	target1;
	CMovingEntity*	target2;

	CMovingEntity* Target1() { return target1; }
	CMovingEntity* Target2() { return target2; }


public:
	CSteeringBehavior_Interpose_Entity_Entity(CMovingEntity* const iMovingEntity, CMovingEntity* iTarget1, CMovingEntity* iTarget2);
	D3DXVECTOR2 CalculateForce();

	void SetTarget1(CMovingEntity* iTarget1) { target1 = iTarget1; }
	void SetTarget2(CMovingEntity* iTarget2) { target2 = iTarget2; }
};

}

#endif
