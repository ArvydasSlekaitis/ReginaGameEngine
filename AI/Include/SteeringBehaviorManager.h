///////////////////////////////////////////////////////////
//  SteeringBehaviorManager.h
//  Created on:      05-09-2009
//  Last modified:   26-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STEERINGBEHAVIORMANAGER_H
#define REGINA_STEERINGBEHAVIORMANAGER_H

#include <vector>
#include <assert.h>
using namespace std;

#include <SteeringBehavior.h>
#include <SteeringBehavior_Seek.h>
#include <SteeringBehavior_Flee.h>
#include <SteeringBehavior_Flee_Distanced.h>
#include <SteeringBehavior_Arrive.h>
#include <SteeringBehavior_Wander.h>
#include <SteeringBehavior_Pursuit.h>
#include <SteeringBehavior_Evade.h>
#include <SteeringBehavior_ObstacleAvoidance.h>
#include <SteeringBehavior_WallAvoidance.h>
#include <SteeringBehavior_Interpose_Entity_Entity.h>
#include <SteeringBehavior_Interpose_Entity_Position.h>
#include <SteeringBehavior_Hide.h>
#include <SteeringBehavior_PathFallow.h>
#include <SteeringBehavior_OffsetPursuit.h>
#include <SteeringBehavior_Separation.h>
#include <SteeringBehavior_Alignment.h>
#include <SteeringBehavior_Cohesion.h>


namespace Regina
{

class CSteeringBehaviorManager
{
	vector<CSteeringBehavior*>	steeringBehaviors;
	CMovingEntity* const		movingEntity;
	float						maxForce;

	void		AddSteeringBehavior(CSteeringBehavior* iSteeringBehavior);
	void		RemoveSteeringBehavior(const string& iName);
	bool		ExistSteeringBehavior(const string& iName);
	unsigned	GetSteeringBehaviorPosition(const string& iName);
	bool		AccumulateForce(D3DXVECTOR2& iTotalForce, const D3DXVECTOR2& iForce);

	CMovingEntity* Entity() const { return movingEntity; }
	
public:
	CSteeringBehaviorManager(CMovingEntity* const iMovingEntity, const float& iMaxForce);
	~CSteeringBehaviorManager();
	
	enum Travel_Speed { Slow = 3, Normal = 2, Fast = 1 };

	void		SetMaxForce(const float& iMaxForce)	{ maxForce = iMaxForce; }
	D3DXVECTOR3	CalculateForce();

	void		Disable_All();
	void		Disable_Seek();
	void		Disable_Flee();
	void		Disable_Arrive();
	void		Disable_Wander();
	void		Disable_Pursuit();
	void		Disable_Evade();
	void		Disable_ObstacleAvoidance();
	void		Disable_WallAvoidance();
	void		Disable_Interpose();
	void		Disable_Hide();
	void		Disable_PathFallow();
	void		Disable_OffsetPursuit();
	void		Disable_Separation();
	void		Disable_Alignment();
	void		Disable_Cohesion();

	void		Enable_Seek(const D3DXVECTOR2& iTargetPosition);
	void		Enable_Flee(const D3DXVECTOR2& iTargetPosition);
	void		Enable_Flee(const D3DXVECTOR2& iTargetPosition, const float& iPanicDistance);
	void		Enable_Arrive(const D3DXVECTOR2& iTargetPosition, const Travel_Speed& iTravelSpeed);
	void		Enable_Wander(const float& iWanderDistance, const float& iWanderRadius, const float& iWanderJitter);
	void		Enable_Pursuit(const CMovingEntity* iTarget);
	void		Enable_Evade(const CMovingEntity* iTarget);
	void		Enable_ObstacleAvoidance();
	void		Enable_WallAvoidance();
	void		Enable_Interpose(CMovingEntity* iTarget1, CMovingEntity* iTarget2);
	void		Enable_Interpose(CMovingEntity* iTarget1, const D3DXVECTOR2& iTarget2);
	void		Enable_Hide(CMovingEntity* iTarget, const float& iObstacleSearchRadius);
	void		Enable_PathFallow(const vector<D3DXVECTOR2>& iWaypoints, const bool& iLoop, const float& iWaypointSeekDistance);
	void		Enable_OffsetPursuit(const CMovingEntity* iLeader, const D3DXVECTOR2& iOffset);
	void		Enable_Separation(const float& iNeighborhoodRadius);
	void		Enable_Alignment(const float& iNeighborhoodRadius);
	void		Enable_Cohesion(const float& iNeighborhoodRadius);
};

}

#endif
