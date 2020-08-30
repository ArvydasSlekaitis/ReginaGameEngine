///////////////////////////////////////////////////////////
//  AIManager.cpp
//  Created on:      20-08-2009
//  Last modified:   20-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <AIManager.h>
using namespace Regina;

//*****************************************************************************

CAIManager* CAIManager::Instance()
{
static CAIManager aiManager;
return &aiManager;
}

//*****************************************************************************

CAIManager::CAIManager() : entityCreator(NULL), loadComplete(false)
	{
	entityManager = new CEntityManager();
	collisionDetectionManager = new CCollisionDetectionManager();
	}

//*****************************************************************************

CAIManager::~CAIManager()
	{
	Clear();
	delete entityManager;
	delete collisionDetectionManager;
	if(entityCreator!=NULL)
		delete entityCreator;
	}

//*****************************************************************************

CBaseEntity* CAIManager::CreateEntity(const string& iEntityClassName, const bool iAutoAdd)
	{
	if(entityCreator==NULL)
		throw logic_error("CAIManager::CreateEntity - Trying to create entity, while no entity creator is defined");
	
	CBaseEntity* entity = entityCreator->Create(iEntityClassName, device);
	
	if(iAutoAdd==true)
		entityManager->Add(entity);

	return entity;
	}

//*****************************************************************************
	
void CAIManager::Init(LPDIRECT3DDEVICE9 iDevice, CEntityCreator* iEntityCreator)
	{
	if(iEntityCreator == NULL)
		throw invalid_argument("CAIManager::Init - iEntityCreator == NULL");
	if(iDevice == NULL)	
		throw invalid_argument("CAIManager::Init - iDevice == NULL");
	
	entityCreator = iEntityCreator;
	
	device = iDevice;
	device->AddRef();
	}

//*****************************************************************************

void CAIManager::Clear()
	{
	entityManager->Clear();
	collisionDetectionManager->Clear();
	loadComplete = false;
	}

//*****************************************************************************

void CAIManager::ReleaseDevice()
	{
	device->Release();
	device = NULL;
	}

//*****************************************************************************

void CAIManager::LoadMap(const string& iFileName, const bool iLoadComplete)
	{
	ifstream file(string(string("Data\\Map\\") + iFileName + ".txt").c_str());

	if(file.is_open() == false)
		throw runtime_error("CAIManager::Load - Cannot open specified file");
	
	while(!file.eof())
		{
		string tmpLine;
		string objectType;
		getline(file, tmpLine);
		istringstream line(tmpLine);
		line >> objectType;
		
		if(objectType == "Entity")
			{
			string entityType;
			line >> entityType;

			CBaseEntity* entity = CreateEntity(entityType, false);
			if(entity!=NULL)
				{
				entity->Load(LoadSubset(file));
				AddEntity(entity);
				} 
			else
				throw runtime_error("CAIManager::Load - Cannot create new entity (Out of memmory?)");
			}

		if(objectType == "Floor")
			{
			D3DXVECTOR2 iFloorCenter;
			float iFloorSizeX;
			float iFloorSizeY;
			float iHeight;

			line >> iFloorCenter.x >> iFloorCenter.y >> iHeight >> iFloorSizeX >> iFloorSizeY;

			CFloor* floor = new CFloor(iFloorCenter, iFloorSizeX, iFloorSizeY, iHeight, LoadSubset(file));
			if(floor!=NULL)
				{
				AddFloor(floor);
				} 
			else
				throw runtime_error("CAIManager::Load - Cannot create new floor (Out of memmory?)");
			}
		}

	if(iLoadComplete==true)
		LoadComplete();
	}

//*****************************************************************************

void CAIManager::AddEntity(CBaseEntity* iEntity)
	{
	entityManager->Add(iEntity);

	switch(iEntity->Type())
		{
		case(BasicTypeID::type_Door_2D) :	AddDoor((CDoor_2D*)iEntity);
											break;

		case(BasicTypeID::type_Trigger) :	AddTrigger((CTrigger*)iEntity);
											break;
		}
	}

//*****************************************************************************

void CAIManager::AddFloor(CFloor* iFloor)
	{
	collisionDetectionManager->AddFloor(iFloor);
	}

//*****************************************************************************

void CAIManager::AddDoor(CDoor_2D* iDoor)
	{
	collisionDetectionManager->AddDoor(iDoor);
	}

//*****************************************************************************

void CAIManager::AddTrigger(CTrigger* iTrigger)
	{
	collisionDetectionManager->AddTrigger(iTrigger);
	}

//*****************************************************************************

void CAIManager::RemoveEntity(CBaseEntity* iEntity)
	{
	if(iEntity->ID()!=0)
		{
		idToRemove.push_back(iEntity->ID());
		entityManager->Remove(iEntity->ID());
		}
	}

//*****************************************************************************

void CAIManager::RemoveEntity(const unsigned& iEntityID)
	{
	if(iEntityID!=0)
		{
		idToRemove.push_back(iEntityID);
		entityManager->Remove(iEntityID);
		}
	}

//*****************************************************************************

void CAIManager::Update_RemoveRemovedEntitys()
		{
		for(unsigned i = 0; i<idToRemove.size(); i++)
			{
			MessageDispatcher->UnregisterEntity(idToRemove[i]);
			collisionDetectionManager->UnregisterEntity(idToRemove[i]);
			}

		entityManager->RemoveRemoved();

		idToRemove.clear();
		}

//*****************************************************************************

void CAIManager::Update(const float& iDuration)
	{
	Update_RemoveRemovedEntitys();
	Update_Entitys(iDuration);
	Update_CreateCollisionGrids();
	Update_CollisionDetection();
	}

//*****************************************************************************

void CAIManager::Update_Entitys(const float& iDuration)
	{
	entityManager->Update(iDuration);
	}

//*****************************************************************************

void CAIManager::Update_CollisionDetection()
	{
	collisionDetectionManager->AutoCollisionDetection();
	}
	
//*****************************************************************************

void CAIManager::Update_CreateCollisionGrids()
	{
	collisionDetectionManager->CreateGrids();
	}

//*****************************************************************************

void CAIManager::LoadComplete()
	{
	if(loadComplete == false)
		{
		collisionDetectionManager->LoadComplete();
		loadComplete = true;
		}
	}

//*****************************************************************************

void CAIManager::AddCollisionObject_Static(const string& iCollisionMeshName, const D3DXMATRIXA16& iTransformation, CBaseEntity* iBaseEntity, const bool iMessageSendingEnabled)
	{
	collisionDetectionManager->AddStaticObject(iCollisionMeshName, iTransformation, iBaseEntity, iMessageSendingEnabled);
	}

//*****************************************************************************

void CAIManager::AddCollisionObject_Dynamic(const string& iCollisionMeshName, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled)
	{
	collisionDetectionManager->AddDynamicObject(iCollisionMeshName, iMovingEntity, iMessageSendingEnabled);
	}

//*****************************************************************************

void CAIManager::AddCollisionObject_Dynamic(CCollisionMesh* iCollisionMesh, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled)
	{
	collisionDetectionManager->AddDynamicObject(iCollisionMesh, iMovingEntity, iMessageSendingEnabled);
	}

//*****************************************************************************

void CAIManager::AddCollisionObject_ParticlePhisics(CParticlePhisics* iParticlePhisics, const float& iRadius, const float& iRestitution, CBaseEntity* iBaseEntity, const bool iMessageSendingEnabled)
	{
	collisionDetectionManager->AddParticlePhisicsObject(iParticlePhisics, iRadius, iRestitution, iBaseEntity, iMessageSendingEnabled);
	}

//*****************************************************************************

void CAIManager::RemoveCollisionObject_ParticlePhisics(CParticlePhisics* iParticlePhisics)
	{
	collisionDetectionManager->RemoveParticlePhisicsObject(iParticlePhisics);
	}

//*****************************************************************************

void CAIManager::RemoveCollisionObject_Dynamic(const string& iCollisionMeshName, CMovingEntity* iMovingEntity)
	{
	collisionDetectionManager->RemoveDynamicObject(iCollisionMeshName, iMovingEntity);
	}

//*****************************************************************************

void CAIManager::RemoveCollisionObject_Dynamic(CMovingEntity* iMovingEntity)
	{
	collisionDetectionManager->RemoveDynamicObject(iMovingEntity);
	}

//*****************************************************************************

void CAIManager::RemoveCollisionObject_Dynamic(const CCollisionMesh* const iCollisionMesh, CMovingEntity* iMovingEntity)
	{
	collisionDetectionManager->RemoveDynamicObject(iCollisionMesh->Name(), iMovingEntity);
	}

//*****************************************************************************

void CAIManager::DetectCollision_WithStatic(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_Static>& oCollisions)
	{
	collisionDetectionManager->DetectCollision_WithStatic(iPosition, iRadius, oCollisions);
	}

//*****************************************************************************

void CAIManager::DetectCollision_WithDynamic(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_Dynamic>& oCollisions)
	{
	collisionDetectionManager->DetectCollision_WithDynamic(iPosition, iRadius, oCollisions);
	}

//*****************************************************************************

void CAIManager::DetectCollision_WithParticlePhisics(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_ParticlePhisics>& oCollisions)
	{
	collisionDetectionManager->DetectCollision_WithParticlePhisics(iPosition, iRadius, oCollisions);
	}

//*****************************************************************************

void CAIManager::DetectCollision_WithDoors(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CDoor_2D>& oCollisions)
	{
	collisionDetectionManager->DetectCollision_WithDoors(iPosition, iRadius, oCollisions);
	}

//*****************************************************************************

void CAIManager::DetectCollision_WithWalls(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CWall_2D>& oCollisions)
	{
	collisionDetectionManager->DetectCollision_WithWalls(iPosition, iRadius, oCollisions);
	}

//*****************************************************************************

bool CAIManager::DetectIntersection_WithStatic(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	return collisionDetectionManager->DetectIntersection_WithStatic(iPosition, iRadius);
	}

//*****************************************************************************

bool CAIManager::DetectIntersection_WithDynamic(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	return collisionDetectionManager->DetectIntersection_WithDynamic(iPosition, iRadius);
	}

//*****************************************************************************

bool CAIManager::DetectIntersection_WithParticlePhisics(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	return collisionDetectionManager->DetectIntersection_WithParticlePhisics(iPosition, iRadius);
	}

//*****************************************************************************

bool CAIManager::DetectIntersection_WithDoors(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	return collisionDetectionManager->DetectIntersection_WithDoors(iPosition, iRadius);
	}

//*****************************************************************************

bool CAIManager::DetectIntersection_WithWalls(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	return collisionDetectionManager->DetectIntersection_WithWalls(iPosition, iRadius);
	}

//*****************************************************************************
