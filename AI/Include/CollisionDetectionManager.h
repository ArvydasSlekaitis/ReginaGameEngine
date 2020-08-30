///////////////////////////////////////////////////////////
//  CollisionDetectionManager.h
//  Created on:      22-07-2009
//  Last modified:   31-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_COLLISIONDETECTIONMANAGER_H
#define REGINA_COLLISIONDETECTIONMANAGER_H

#include <vector>
#include <map>
#include <assert.h>
using namespace std;

#include <Floor.h>
#include <CollisionObject_Static.h>
#include <CollisionObject_Dynamic.h>
#include <CollisionObject_ParticlePhisics.h>
#include <CollisionMesh.h>
#include <BaseEntity.h>
#include <Door_2D.h>
#include <Trigger.h>
#include <Wall_2D.h>
#include <MovingEntity.h>

namespace Regina
{

class CCollisionDetectionManager
{
	vector<CFloor*>													floor;	
	vector<CTrigger*>												triggers;	
	vector<CDoor_2D*>												doors;	
	vector<pair<CCollisionObject_Dynamic_Data*, unsigned> >			dynamicObjectList;			//unsigned - floor index
	vector<pair<CCollisionObject_Static_Data*, unsigned> >			staticObjectList;			//unsigned - floor index
	vector<pair<CCollisionObject_ParticlePhisics_Data*, unsigned> >	particlePhisicsObjectList;	//unsigned - floor index

public:
	CCollisionDetectionManager() {}
	~CCollisionDetectionManager();

	//Add functions
	void AddFloor(CFloor* iFloor);
	void AddDoor(CDoor_2D* iDoor);
	void AddTrigger(CTrigger* iTrigger);
	void AddWall(const unsigned& iFloorNumber, const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd, const float iRestitution = 1.0f);

	void AddStaticObject(const string& iCollisionMeshName, const D3DXMATRIXA16& iTransformation, CBaseEntity* iBaseEntity = NULL, const bool iMessageSendingEnabled = false);
	void AddDynamicObject(const string& iCollisionMeshName, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled = false);
	void AddDynamicObject(CCollisionMesh* iCollisionMesh, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled = false);
	void AddParticlePhisicsObject(CParticlePhisics* iParticlePhisics, const float& iRadius, const float& iRestitution, CBaseEntity* iBaseEntity = NULL, const bool iMessageSendingEnabled = false);

	//Remove functions
	void RemoveParticlePhisicsObject(CParticlePhisics* iParticlePhisics);
	void RemoveDynamicObject(const string& iCollisionMeshName, CMovingEntity* iMovingEntity);
	void RemoveDynamicObject(CMovingEntity* iMovingEntity);
	
	//Collision detection functions
	void DetectCollision_WithStatic(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_Static>& oCollisions);
	void DetectCollision_WithDynamic(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_Dynamic>& oCollisions);
	void DetectCollision_WithParticlePhisics(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_ParticlePhisics>& oCollisions);
	void DetectCollision_WithDoors(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CDoor_2D>& oCollisions);
	void DetectCollision_WithWalls(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CWall_2D>& oCollisions);

	//Intersection functions
	bool DetectIntersection_WithStatic(const D3DXVECTOR3& iPosition, const float& iRadius);
	bool DetectIntersection_WithDynamic(const D3DXVECTOR3& iPosition, const float& iRadius);
	bool DetectIntersection_WithParticlePhisics(const D3DXVECTOR3& iPosition, const float& iRadius);
	bool DetectIntersection_WithDoors(const D3DXVECTOR3& iPosition, const float& iRadius);
	bool DetectIntersection_WithWalls(const D3DXVECTOR3& iPosition, const float& iRadius);

	void UnregisterEntity(const unsigned& iID);

	void CreateGrids();
	void LoadComplete();
	void AutoCollisionDetection();
	
	void Clear();
	
};


}

#endif
