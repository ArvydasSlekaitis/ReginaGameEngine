///////////////////////////////////////////////////////////
//  AIManager.h
//  Created on:      20-08-2009
//  Last modified:   20-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_AIMANAGER_H
#define REGINA_AIMANAGER_H

#include <fstream>
#include <sstream>
using namespace std;

#include <EntityManager.h>
#include <EntityCreator.h>
#include <MessageDispatcher.h>
#include <CollisionDetectionManager.h>
#include <Functions_Text.h>
#include <Door_2D.h>
#include <BasicTypeEnumaration.h>
#include <Trigger.h>

namespace Regina
{

class CAIManager
{
	vector<unsigned>			idToRemove;
	LPDIRECT3DDEVICE9 			device;
	CEntityCreator* 			entityCreator;
	CEntityManager*				entityManager;
	CCollisionDetectionManager*	collisionDetectionManager;

	CAIManager();
	~CAIManager();
	CAIManager(const CAIManager&) {}

	bool						loadComplete;

	void AddDoor(CDoor_2D* iDoor);
	void AddTrigger(CTrigger* iTrigger);
	void AddFloor(CFloor* iFloor);

	

public:
	static CAIManager* Instance();

	CBaseEntity* EntityFromID(const unsigned& iID) { return entityManager->EntityFromID(iID); }
	CBaseEntity* CreateEntity(const string& iEntityClassName, const bool iAutoAdd = true);

	//Add functions
	void AddEntity(CBaseEntity* iEntity);
	void AddWall(const unsigned& iFloorNumber, const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd, const float iRestitution = 1.0f);
	
	void AddCollisionObject_Static(const string& iCollisionMeshName, const D3DXMATRIXA16& iTransformation, CBaseEntity* iBaseEntity = NULL, const bool iMessageSendingEnabled = false);
	void AddCollisionObject_Dynamic(const string& iCollisionMeshName, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled = false);
	void AddCollisionObject_Dynamic(CCollisionMesh* iCollisionMesh, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled = false);
	void AddCollisionObject_ParticlePhisics(CParticlePhisics* iParticlePhisics, const float& iRadius, const float& iRestitution, CBaseEntity* iBaseEntity = NULL, const bool iMessageSendingEnabled = false);

	//Remove functions
	void RemoveCollisionObject_ParticlePhisics(CParticlePhisics* iParticlePhisics);
	void RemoveCollisionObject_Dynamic(const string& iCollisionMeshName, CMovingEntity* iMovingEntity);
	void RemoveCollisionObject_Dynamic(const CCollisionMesh* const iCollisionMesh, CMovingEntity* iMovingEntity);
	void RemoveCollisionObject_Dynamic(CMovingEntity* iMovingEntity);
	
	void RemoveEntity(CBaseEntity* iEntity);
	void RemoveEntity(const unsigned& iEntityID);
		
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

	
	void Init(LPDIRECT3DDEVICE9 iDevice, CEntityCreator* iEntityCreator);
	void Clear();
	void ReleaseDevice();
	void Update(const float& iDuration);

	void LoadMap(const string& iFileName, const bool iLoadComplete = true);
	void LoadComplete(); //For best performance call This function ( or LoadMap with iLoadComplete parameter true) then you have loaded all static map objects

	//Use if you are using custom update method
	void Update_RemoveRemovedEntitys();
	void Update_Entitys(const float& iDuration);
	void Update_CollisionDetection();
	void Update_CreateCollisionGrids();

};

#define AIManager CAIManager::Instance()

}

#endif