///////////////////////////////////////////////////////////
//  SteeringBehaviorManager.cpp
//  Created on:      05-09-2009
//  Last modified:   14-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehaviorManager.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehaviorManager::CSteeringBehaviorManager(Regina::CMovingEntity *const iMovingEntity, const float &iMaxForce) : movingEntity(iMovingEntity), maxForce(iMaxForce)
	{
	if(movingEntity == NULL)
		throw invalid_argument("CSteeringBehaviorManager::CSteeringBehaviorManager - argument iMovingEntity==NULL");
	}

//*****************************************************************************

CSteeringBehaviorManager::~CSteeringBehaviorManager()
	{
	Disable_All();
	}

//*****************************************************************************

void CSteeringBehaviorManager::AddSteeringBehavior(Regina::CSteeringBehavior *iSteeringBehavior)
	{
	assert(iSteeringBehavior!=NULL);
	assert(!ExistSteeringBehavior(iSteeringBehavior->Name()));
	
	for(unsigned i=0; i<steeringBehaviors.size(); i++)
		{
		if(iSteeringBehavior->Priority() > steeringBehaviors[i]->Priority())
			{
			steeringBehaviors.push_back(NULL);

			for(unsigned ii=steeringBehaviors.size()-1; ii>i; ii--)
				{
				steeringBehaviors[ii] = steeringBehaviors[ii-1];
				}

			steeringBehaviors[i] = iSteeringBehavior;
			return;
			}
		}

	steeringBehaviors.push_back(iSteeringBehavior);
	}

//*****************************************************************************

void CSteeringBehaviorManager::RemoveSteeringBehavior(const std::string &iName)
	{
	assert(ExistSteeringBehavior(iName));

	unsigned position = GetSteeringBehaviorPosition(iName);
	delete steeringBehaviors[position];

	for(unsigned i=position; i<steeringBehaviors.size()-1; i++)
		{
		steeringBehaviors[i] = steeringBehaviors[i+1];
		}
	
	steeringBehaviors.pop_back();
	}

//*****************************************************************************

bool CSteeringBehaviorManager::ExistSteeringBehavior(const std::string &iName)
	{
	for(unsigned i=0; i<steeringBehaviors.size(); i++)
		if(steeringBehaviors[i]->Name() == iName)
			return true;

	return false;
	}

//*****************************************************************************

unsigned CSteeringBehaviorManager::GetSteeringBehaviorPosition(const std::string& iName)
	{
	assert(ExistSteeringBehavior(iName));

	for(unsigned i=0; i<steeringBehaviors.size(); i++)
		if(steeringBehaviors[i]->Name() == iName)
			return i;

	return 0;
	}

//*****************************************************************************

bool CSteeringBehaviorManager::AccumulateForce(D3DXVECTOR2 &iTotalForce, const D3DXVECTOR2 &iForce)
	{
	float remainingForce = maxForce - D3DXVec2Length(&iTotalForce);
	float forceSize = D3DXVec2Length(&iForce);

	if(forceSize == 0)
		return remainingForce > 0;

	if(remainingForce - forceSize < 0)
		{
		D3DXVECTOR2 forceNormal = iForce / forceSize;
		iTotalForce += forceNormal * remainingForce;
		return false;
		}
	else
		{
		iTotalForce += iForce;

		if(maxForce*maxForce - D3DXVec2LengthSq(&iTotalForce) <= 0)
			return false;
		else
			return true;
		}
	}

//*****************************************************************************

D3DXVECTOR3 CSteeringBehaviorManager::CalculateForce()
	{
	D3DXVECTOR2 totalForce(0, 0);

	for(unsigned i=0; i<steeringBehaviors.size(); i++)
		{
		D3DXVECTOR2 force = steeringBehaviors[i]->CalculateForce() * steeringBehaviors[i]->Weight(); 

		if(AccumulateForce(totalForce, force) == false) 
			break;  // All force is used
		}

	return D3DXVECTOR3(totalForce.x, 0, totalForce.y);
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_All()
	{
	for(unsigned i=0; i<steeringBehaviors.size(); i++)
		delete steeringBehaviors[i];

	steeringBehaviors.clear();
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Seek(const D3DXVECTOR2& iTargetPosition)
	{
	if(ExistSteeringBehavior("Seek"))
		{
		((CSteeringBehavior_Seek*)steeringBehaviors[GetSteeringBehaviorPosition("Seek")])->SetTargetPosition(iTargetPosition);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_Seek(Entity(), iTargetPosition));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Flee(const D3DXVECTOR2& iTargetPosition)
	{
	if(ExistSteeringBehavior("Flee"))
		{
		((CSteeringBehavior_Flee*)steeringBehaviors[GetSteeringBehaviorPosition("Flee")])->SetTargetPosition(iTargetPosition);
		}
	else
		{
		if(ExistSteeringBehavior("Flee_Distanced"))
			RemoveSteeringBehavior("Flee_Distanced");

		AddSteeringBehavior(new CSteeringBehavior_Flee(Entity(), iTargetPosition));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Flee(const D3DXVECTOR2& iTargetPosition, const float& iPanicDistance)
	{
	if(ExistSteeringBehavior("Flee_Distanced"))
		{
		((CSteeringBehavior_Flee_Distanced*)steeringBehaviors[GetSteeringBehaviorPosition("Flee_Distanced")])->SetTargetPosition(iTargetPosition);
		((CSteeringBehavior_Flee_Distanced*)steeringBehaviors[GetSteeringBehaviorPosition("Flee_Distanced")])->SetPanicDistance(iPanicDistance);
		}
	else
		{
		if(ExistSteeringBehavior("Flee"))
			RemoveSteeringBehavior("Flee");

		AddSteeringBehavior(new CSteeringBehavior_Flee_Distanced(Entity(), iTargetPosition, iPanicDistance));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Arrive(const D3DXVECTOR2& iTargetPosition, const Travel_Speed& iTravelSpeed)
	{
	if(iTravelSpeed!=Travel_Speed::Fast && iTravelSpeed!=Travel_Speed::Normal && iTravelSpeed!=Travel_Speed::Slow)
		throw invalid_argument("CSteeringBehaviorManager::Enable_Arrive - argument iTravelSpeed value is incorrect");

	if(ExistSteeringBehavior("Arrive"))
		{
		((CSteeringBehavior_Arrive*)steeringBehaviors[GetSteeringBehaviorPosition("Arrive")])->SetTargetPosition(iTargetPosition);
		((CSteeringBehavior_Arrive*)steeringBehaviors[GetSteeringBehaviorPosition("Arrive")])->SetTargetSpeed(iTravelSpeed);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_Arrive(Entity(), iTargetPosition, iTravelSpeed));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Wander(const float& iWanderDistance, const float& iWanderRadius, const float& iWanderJitter)
	{
	if(ExistSteeringBehavior("Wander"))
		{
		const unsigned pos = GetSteeringBehaviorPosition("Wander");
		((CSteeringBehavior_Wander*)steeringBehaviors[pos])->SetWanderDistance(iWanderDistance);
		((CSteeringBehavior_Wander*)steeringBehaviors[pos])->SetWanderRadius(iWanderRadius);
		((CSteeringBehavior_Wander*)steeringBehaviors[pos])->SetWanderJitter(iWanderJitter);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_Wander(Entity(), iWanderDistance, iWanderRadius, iWanderJitter));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Pursuit(const Regina::CMovingEntity* iTarget)
	{
	if(ExistSteeringBehavior("Pursuit"))
		{
		const unsigned pos = GetSteeringBehaviorPosition("Pursuit");
		((CSteeringBehavior_Pursuit*)steeringBehaviors[pos])->SetTarget(iTarget);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_Pursuit(Entity(), iTarget));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Evade(const Regina::CMovingEntity* iTarget)
	{
	if(ExistSteeringBehavior("Evade"))
		{
		const unsigned pos = GetSteeringBehaviorPosition("Evade");
		((CSteeringBehavior_Evade*)steeringBehaviors[pos])->SetTarget(iTarget);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_Evade(Entity(), iTarget));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_ObstacleAvoidance()
	{
	if(ExistSteeringBehavior("ObstacleAvoidance") == false)
		{
		AddSteeringBehavior(new CSteeringBehavior_ObstacleAvoidance(Entity()));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_WallAvoidance()
	{
	if(ExistSteeringBehavior("WallAvoidance") == false)
		{
		AddSteeringBehavior(new CSteeringBehavior_WallAvoidance(Entity()));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Interpose(Regina::CMovingEntity* iTarget1, Regina::CMovingEntity* iTarget2)
	{
	if(ExistSteeringBehavior("Interpose_Entity_Entity"))
		{
		((CSteeringBehavior_Interpose_Entity_Entity*)steeringBehaviors[GetSteeringBehaviorPosition("Interpose_Entity_Entity")])->SetTarget1(iTarget1);
		((CSteeringBehavior_Interpose_Entity_Entity*)steeringBehaviors[GetSteeringBehaviorPosition("Interpose_Entity_Entity")])->SetTarget2(iTarget2);
		}
	else
		{
		if(ExistSteeringBehavior("Interpose_Entity_Position"))
			RemoveSteeringBehavior("Interpose_Entity_Position");

		AddSteeringBehavior(new CSteeringBehavior_Interpose_Entity_Entity(Entity(), iTarget1, iTarget2));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Interpose(CMovingEntity* iTarget1, const D3DXVECTOR2& iTarget2)
	{
	if(ExistSteeringBehavior("Interpose_Entity_Position"))
		{
		((CSteeringBehavior_Interpose_Entity_Position*)steeringBehaviors[GetSteeringBehaviorPosition("Interpose_Entity_Position")])->SetTarget1(iTarget1);
		((CSteeringBehavior_Interpose_Entity_Position*)steeringBehaviors[GetSteeringBehaviorPosition("Interpose_Entity_Position")])->SetTarget2(iTarget2);
		}
	else
		{
		if(ExistSteeringBehavior("Interpose_Entity_Entity"))
			RemoveSteeringBehavior("Interpose_Entity_Entity");

		AddSteeringBehavior(new CSteeringBehavior_Interpose_Entity_Position(Entity(), iTarget1, iTarget2));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Hide(Regina::CMovingEntity* iTarget, const float& iObstacleSearchRadius)
	{
	if(ExistSteeringBehavior("Hide"))
		{
		const unsigned pos = GetSteeringBehaviorPosition("Hide");
		((CSteeringBehavior_Hide*)steeringBehaviors[pos])->SetTarget(iTarget);
		((CSteeringBehavior_Hide*)steeringBehaviors[pos])->SetObstacleSearchRadius(iObstacleSearchRadius);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_Hide(Entity(), iTarget, iObstacleSearchRadius));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_PathFallow(const vector<D3DXVECTOR2>& iWaypoints, const bool& iLoop, const float& iWaypointSeekDistance)
	{
	if(ExistSteeringBehavior("PathFallow"))
		{
		const unsigned pos = GetSteeringBehaviorPosition("PathFallow");
		((CSteeringBehavior_PathFallow*)steeringBehaviors[pos])->SetWaypoints(iWaypoints);
		((CSteeringBehavior_PathFallow*)steeringBehaviors[pos])->SetLoop(iLoop);
		((CSteeringBehavior_PathFallow*)steeringBehaviors[pos])->SetWaypointSeekDistance(iWaypointSeekDistance);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_PathFallow(Entity(), iWaypoints, iLoop, iWaypointSeekDistance));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_OffsetPursuit(const CMovingEntity* iLeader, const D3DXVECTOR2& iOffset)
	{
	if(ExistSteeringBehavior("OffsetPursuit"))
		{
		const unsigned pos = GetSteeringBehaviorPosition("OffsetPursuit");
		((CSteeringBehavior_OffsetPursuit*)steeringBehaviors[pos])->SetLeader(iLeader);
		((CSteeringBehavior_OffsetPursuit*)steeringBehaviors[pos])->SetOffset(iOffset);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_OffsetPursuit(Entity(), iLeader, iOffset));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Separation(const float& iNeighborhoodRadius)
	{
	if(ExistSteeringBehavior("Separation"))
		{
		const unsigned pos = GetSteeringBehaviorPosition("Separation");
		((CSteeringBehavior_Separation*)steeringBehaviors[pos])->SetNeighborhoodRadius(iNeighborhoodRadius);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_Separation(Entity(), iNeighborhoodRadius));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Alignment(const float& iNeighborhoodRadius)
	{
	if(ExistSteeringBehavior("Alignment"))
		{
		const unsigned pos = GetSteeringBehaviorPosition("Alignment");
		((CSteeringBehavior_Alignment*)steeringBehaviors[pos])->SetNeighborhoodRadius(iNeighborhoodRadius);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_Alignment(Entity(), iNeighborhoodRadius));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Enable_Cohesion(const float& iNeighborhoodRadius)
	{
	if(ExistSteeringBehavior("Cohesion"))
		{
		const unsigned pos = GetSteeringBehaviorPosition("Cohesion");
		((CSteeringBehavior_Cohesion*)steeringBehaviors[pos])->SetNeighborhoodRadius(iNeighborhoodRadius);
		}
	else
		{
		AddSteeringBehavior(new CSteeringBehavior_Cohesion(Entity(), iNeighborhoodRadius));
		}
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Seek()
	{
	if(ExistSteeringBehavior("Seek"))
		RemoveSteeringBehavior("Seek");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Flee()
	{
	if(ExistSteeringBehavior("Flee"))
		RemoveSteeringBehavior("Flee");

	if(ExistSteeringBehavior("Flee_Distanced"))
		RemoveSteeringBehavior("Flee_Distanced");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Arrive()
	{
	if(ExistSteeringBehavior("Arrive"))
		RemoveSteeringBehavior("Arrive");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Wander()
	{
	if(ExistSteeringBehavior("Wander"))
		RemoveSteeringBehavior("Wander");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Pursuit()
	{
	if(ExistSteeringBehavior("Pursuit"))
		RemoveSteeringBehavior("Pursuit");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Evade()
	{
	if(ExistSteeringBehavior("Evade"))
		RemoveSteeringBehavior("Evade");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_ObstacleAvoidance()
	{
	if(ExistSteeringBehavior("ObstacleAvoidance"))
		RemoveSteeringBehavior("ObstacleAvoidance");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_WallAvoidance()
	{
	if(ExistSteeringBehavior("WallAvoidance"))
		RemoveSteeringBehavior("WallAvoidance");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Interpose()
	{
	if(ExistSteeringBehavior("Interpose_Entity_Entity"))
		RemoveSteeringBehavior("Interpose_Entity_Entity");

	if(ExistSteeringBehavior("Interpose_Entity_Position"))
		RemoveSteeringBehavior("Interpose_Entity_Position");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Hide()
	{
	if(ExistSteeringBehavior("Hide"))
		RemoveSteeringBehavior("Hide");
	}

//*****************************************************************************
	
void CSteeringBehaviorManager::Disable_PathFallow()
	{
	if(ExistSteeringBehavior("PathFallow"))
		RemoveSteeringBehavior("PathFallow");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_OffsetPursuit()
	{
	if(ExistSteeringBehavior("OffsetPursuit"))
		RemoveSteeringBehavior("OffsetPursuit");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Separation()
	{
	if(ExistSteeringBehavior("Separation"))
		RemoveSteeringBehavior("Separation");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Alignment()
	{
	if(ExistSteeringBehavior("Alignment"))
		RemoveSteeringBehavior("Alignment");
	}

//*****************************************************************************

void CSteeringBehaviorManager::Disable_Cohesion()
	{
	if(ExistSteeringBehavior("Cohesion"))
		RemoveSteeringBehavior("Cohesion");
	}

//*****************************************************************************




