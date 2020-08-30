///////////////////////////////////////////////////////////
//  CollisionDetectionManager.cpp
//  Created on:      22-07-2009
//  Last modified:   31-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CollisionDetectionManager.h>
using namespace Regina;


//*****************************************************************************

CCollisionDetectionManager::~CCollisionDetectionManager()
	{
	Clear();
	}

//*****************************************************************************

void CCollisionDetectionManager::Clear()
	{
	for(unsigned i=0; i<floor.size(); i++)
		delete floor[i];

	for(unsigned i=0; i<dynamicObjectList.size(); i++)
		delete dynamicObjectList[i].first;

	for(unsigned i=0; i<particlePhisicsObjectList.size(); i++)
		delete particlePhisicsObjectList[i].first;

	for(unsigned i=0; i<staticObjectList.size(); i++)
		delete staticObjectList[i].first;

	floor.clear();
	triggers.clear();
	doors.clear();
	dynamicObjectList.clear();
	particlePhisicsObjectList.clear();
	staticObjectList.clear();
	}

//*****************************************************************************

void CCollisionDetectionManager::AddFloor(CFloor* iFloor)
	{
	if(iFloor == NULL)
		throw invalid_argument("CCollisionDetectionManager::AddFloor - argument iFloor==NULL");

	floor.push_back(NULL);
	for(unsigned i=0; i<floor.size()-1; i++)
		{
		if(iFloor->Height() > floor[i]->Height())
			continue;

		for(unsigned ii=floor.size(); ii>i; ii--)
			{
			floor[ii] = floor[ii-1];
			}

		floor[i] = iFloor;
		return;
		}

	floor[floor.size()-1] = iFloor;

	}

//*****************************************************************************

void CCollisionDetectionManager::AddDoor(CDoor_2D* iDoor)
	{
	if(iDoor == NULL)
		throw invalid_argument("CCollisionDetectionManager::AddDoor - argument iDoor==NULL");

	if(iDoor->FloorNumber() >= floor.size())
		throw invalid_argument("CCollisionDetectionManager::AddDoor - argument iDoor - Specified floor does not exist");

	floor[iDoor->FloorNumber()]->AddDoor(iDoor);
	}

//*****************************************************************************

void CCollisionDetectionManager::AddTrigger(CTrigger* iTrigger)
	{
	if(iTrigger == NULL)
		throw invalid_argument("CCollisionDetectionManager::AddTrigger - argument iTrigger==NULL");

	triggers.push_back(iTrigger);
	}

//*****************************************************************************

void CCollisionDetectionManager::AddStaticObject(const string& iCollisionMeshName, const D3DXMATRIXA16& iTransformation, CBaseEntity* iBaseEntity, const bool iMessageSendingEnabled)
	{
	if(floor.size() == 0)
		throw logic_error("In CCollisionDetectionManager::AddStaticObject - trying to add static object, while no floor exist");

	CCollisionObject_Static_Data* data = new CCollisionObject_Static_Data(iCollisionMeshName, iTransformation, iBaseEntity, iMessageSendingEnabled);

	for(unsigned i=floor.size()-1; i>0; i--)
		{
		if(iTransformation._42 < floor[i]->Height())
			continue;
		
		staticObjectList.push_back(make_pair(data, i));
		floor[i]->AddStaticObject(data);
		}

	staticObjectList.push_back(make_pair(data, 0));
	floor[0]->AddStaticObject(data);
	}

//*****************************************************************************

void CCollisionDetectionManager::AddDynamicObject(const string& iCollisionMeshName, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled)
	{
	if(floor.size() == 0)
		throw logic_error("In CCollisionDetectionManager::AddDynamicObject - trying to add dynamic object, while no floor exist");

	if(iMovingEntity == NULL)
		throw invalid_argument("In CCollisionDetectionManager::AddDynamicObject - argument iMovingEntity == NULL");

	CCollisionObject_Dynamic_Data* data = new CCollisionObject_Dynamic_Data(iCollisionMeshName, iMovingEntity, iMessageSendingEnabled);

	for(unsigned i=floor.size()-1; i>0; i--)
		{
		if(iMovingEntity->Position().y < floor[i]->Height())
			continue;
		
		dynamicObjectList.push_back(make_pair(data, i));
		floor[i]->AddDynamicObject(data);
		}

	dynamicObjectList.push_back(make_pair(data, 0));
	floor[0]->AddDynamicObject(data);
	}

//*****************************************************************************

void CCollisionDetectionManager::AddDynamicObject(CCollisionMesh* iCollisionMesh, CMovingEntity* iMovingEntity, const bool iMessageSendingEnabled)
	{
	if(floor.size() == 0)
		throw logic_error("In CCollisionDetectionManager::AddDynamicObject - trying to add dynamic object, while no floor exist");

	if(iMovingEntity == NULL)
		throw invalid_argument("In CCollisionDetectionManager::AddDynamicObject - argument iMovingEntity == NULL");

	CCollisionObject_Dynamic_Data* data = new CCollisionObject_Dynamic_Data(iCollisionMesh, iMovingEntity, iMessageSendingEnabled);

	for(unsigned i=floor.size()-1; i>0; i--)
		{
		if(iMovingEntity->Position().y < floor[i]->Height())
			continue;
		
		dynamicObjectList.push_back(make_pair(data, i));
		floor[i]->AddDynamicObject(data);
		}

	dynamicObjectList.push_back(make_pair(data, 0));
	floor[0]->AddDynamicObject(data);
	}

//*****************************************************************************
	
void CCollisionDetectionManager::AddParticlePhisicsObject(CParticlePhisics* iParticlePhisics, const float& iRadius, const float& iRestitution, CBaseEntity* iBaseEntity, const bool iMessageSendingEnabled)
	{
	if(iParticlePhisics == NULL)
		throw invalid_argument("CCollisionDetectionManager::AddCollider - argument iParticlePhisics==NULL");

	if(floor.size() == 0)
		throw logic_error(string("In CCollisionDetectionManager::AddCollider - trying to add collider, while no floor exist"));

	CCollisionObject_ParticlePhisics_Data* data = new CCollisionObject_ParticlePhisics_Data(iParticlePhisics, iRadius, iRestitution, iBaseEntity, iMessageSendingEnabled);

	for(unsigned i=floor.size()-1; i>0; i--)
		{
		if(iParticlePhisics->Position().y < floor[i]->Height())
			continue;
		
		particlePhisicsObjectList.push_back(make_pair(data, i));
		floor[i]->AddParticlePhisicsObject(data);
		}

	particlePhisicsObjectList.push_back(make_pair(data, 0));
	floor[0]->AddParticlePhisicsObject(data);
	}

//*****************************************************************************

void CCollisionDetectionManager::CreateGrids()
	{
	for(unsigned i=0; i<floor.size(); i++)
		{
		floor[i]->ClearDynamics();
		floor[i]->ClearParticlePhisics();
		}

	for(unsigned i=0; i<particlePhisicsObjectList.size(); i++)
		{
		for(unsigned ii=floor.size()-1; ii>0; ii--)
			{
			if(particlePhisicsObjectList[i].first->Position().y < floor[ii]->Height())
				continue;
			
			particlePhisicsObjectList[i].second=ii;
			floor[ii]->AddParticlePhisicsObject(particlePhisicsObjectList[i].first);
			}

		particlePhisicsObjectList[i].second=0;
		floor[0]->AddParticlePhisicsObject(particlePhisicsObjectList[i].first);
		}

	for(unsigned i=0; i<dynamicObjectList.size(); i++)
		{
		for(unsigned ii=floor.size()-1; ii>0; ii--)
			{
			if(dynamicObjectList[i].first->Position().y < floor[ii]->Height())
				continue;
			
			dynamicObjectList[i].second=ii;
			floor[ii]->AddDynamicObject(dynamicObjectList[i].first);
			}
			
		dynamicObjectList[i].second=0;
		floor[0]->AddDynamicObject(dynamicObjectList[i].first);
		}


	for(unsigned i=0; i<floor.size(); i++)
		floor[i]->CreateGrids();
	}

//*****************************************************************************

void CCollisionDetectionManager::AutoCollisionDetection()
	{
	for(unsigned i=0; i<triggers.size(); i++)
	for(unsigned ii=0; ii<dynamicObjectList.size(); ii++)
		{
		triggers[i]->Try(CCollisionObject_Dynamic(dynamicObjectList[ii].first));
		}

	for(unsigned i=0; i<particlePhisicsObjectList.size(); i++)
		if(particlePhisicsObjectList[i].second + 1 <= floor.size()-1)
			if(floor[particlePhisicsObjectList[i].second+1]->FloorTileMap()->TileExist(particlePhisicsObjectList[i].first->Position())==true)
				{
				if(particlePhisicsObjectList[i].first->Position().y + particlePhisicsObjectList[i].first->Radius() > floor[particlePhisicsObjectList[i].second+1]->Height())
					{
					CContactData* contact = new CContactData_ParticleImmovable(particlePhisicsObjectList[i].first->ParticlePhisics(), D3DXVECTOR3(0, -1, 0), particlePhisicsObjectList[i].first->Position().y + particlePhisicsObjectList[i].first->Radius() - floor[particlePhisicsObjectList[i].second+1]->Height(), (1.0 + particlePhisicsObjectList[i].first->Restitution())/2);
					PhisicsManager->AddContact(contact);
					}
				}
			else
				{
				//Upper tile does not exist
				floor[particlePhisicsObjectList[i].second+1]->GenerateParticlePhisicsContacts_WithDynamics(particlePhisicsObjectList[i].first);
				floor[particlePhisicsObjectList[i].second+1]->GenerateParticlePhisicsContacts_WithStatics(particlePhisicsObjectList[i].first);
				floor[particlePhisicsObjectList[i].second+1]->GenerateParticlePhisicsContacts_WithParticles(particlePhisicsObjectList[i].first);
				}

	for(unsigned i=0; i<floor.size(); i++)
		{
		floor[i]->GenerateParticlePhisicsContacts();
		floor[i]->EnsureDynamicZeroPenetration();
		}
	}

//*****************************************************************************

void CCollisionDetectionManager::RemoveParticlePhisicsObject(CParticlePhisics* iParticlePhisics)
	{
	for(unsigned i=0; i<particlePhisicsObjectList.size(); i++)
		{
		if(particlePhisicsObjectList[i].first->ParticlePhisics()->ID() == iParticlePhisics->ID())
			{
			floor[particlePhisicsObjectList[i].second]->RemoveParticlePhisicsObject(particlePhisicsObjectList[i].first);

			delete particlePhisicsObjectList[i].first;
			particlePhisicsObjectList[i] = particlePhisicsObjectList[particlePhisicsObjectList.size()-1];
			particlePhisicsObjectList.pop_back();
			}
		}
	}

//*****************************************************************************

void CCollisionDetectionManager::RemoveDynamicObject(const string& iCollisionMeshName, CMovingEntity* iMovingEntity)
	{
	for(unsigned i=0; i<dynamicObjectList.size(); i++)
		{
		if(dynamicObjectList[i].first->CollisionMesh()->Name() == iCollisionMeshName && dynamicObjectList[i].first->EntityID() == iMovingEntity->ID())
			{
			floor[dynamicObjectList[i].second]->RemoveDynamicObject(dynamicObjectList[i].first);

			delete dynamicObjectList[i].first;
			dynamicObjectList[i] = dynamicObjectList[dynamicObjectList.size()-1];
			dynamicObjectList.pop_back();
			}
		}
	}

//*****************************************************************************

void CCollisionDetectionManager::RemoveDynamicObject(CMovingEntity* iMovingEntity)
	{
	for(unsigned i=0; i<dynamicObjectList.size(); i++)
		{
		if(dynamicObjectList[i].first->EntityID() == iMovingEntity->ID())
			{
			floor[dynamicObjectList[i].second]->RemoveDynamicObject(dynamicObjectList[i].first);

			delete dynamicObjectList[i].first;
			dynamicObjectList[i] = dynamicObjectList[dynamicObjectList.size()-1];
			dynamicObjectList.pop_back();
			}
		}
	}

//*****************************************************************************

void CCollisionDetectionManager::LoadComplete()
	{
	for(unsigned i=0; i<staticObjectList.size(); i++)
		{
		for(unsigned ii=floor.size()-1; ii>0; ii--)
			{
			if(staticObjectList[i].first->Position().y < floor[ii]->Height())
				continue;
			
			staticObjectList[i].second=ii;
			floor[ii]->AddStaticObject(staticObjectList[i].first);
			}

		staticObjectList[i].second=0;
		floor[0]->AddStaticObject(staticObjectList[i].first);
		}

	for(unsigned i=0; i<floor.size(); i++)
		floor[i]->LoadComplete();
	}

//****************************************************************************

void CCollisionDetectionManager::UnregisterEntity(const unsigned& iID)
	{
	for(unsigned i=0; i<triggers.size(); i++)
		if(triggers[i]->ID() == iID)
			{
			triggers[i] = triggers[triggers.size()-1];
			triggers.pop_back();
			}
	
	for(unsigned i=0; i<doors.size(); i++)
		if(doors[i]->ID() == iID)
			{
			floor[doors[i]->FloorNumber()]->RemoveDoor(doors[i]);
			doors[i] = doors[doors.size()-1];
			doors.pop_back();
			}

	for(unsigned i=0; i<dynamicObjectList.size(); i++)
		if(dynamicObjectList[i].first->EntityID() == iID)
			{
			delete dynamicObjectList[i].first;
			dynamicObjectList[i] = dynamicObjectList[dynamicObjectList.size()-1];
			dynamicObjectList.pop_back();
			}

	for(unsigned i=0; i<particlePhisicsObjectList.size(); i++)
		if(particlePhisicsObjectList[i].first->EntityExist())
			if(particlePhisicsObjectList[i].first->EntityID() == iID)
				{
				delete particlePhisicsObjectList[i].first;
				particlePhisicsObjectList[i] = particlePhisicsObjectList[particlePhisicsObjectList.size()-1];
				particlePhisicsObjectList.pop_back();
				}

	for(unsigned i=0; i<staticObjectList.size(); i++)
		if(staticObjectList[i].first->EntityExist())
			if(staticObjectList[i].first->EntityID() == iID)
				{
				floor[staticObjectList[i].second]->RemoveStaticObject(staticObjectList[i].first);
				delete staticObjectList[i].first;
				staticObjectList[i] = staticObjectList[staticObjectList.size()-1];
				staticObjectList.pop_back();
				}

	}

//****************************************************************************

void CCollisionDetectionManager::AddWall(const unsigned& iFloorNumber, const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd, const float iRestitution)
	{
	if(floor.size() < iFloorNumber)
		throw logic_error("In CCollisionDetectionManager::AddWall - trying to add static object, while such floor does not exist");
	
	floor[iFloorNumber]->AddWall(new CWall_2D(iBegin, iEnd, iRestitution));
	}

//****************************************************************************

void CCollisionDetectionManager::DetectCollision_WithStatic(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_Static>& oCollisions)
	{
	for(unsigned i=floor.size()-1; i>=0; i--)
		if(iPosition.y >= floor[i]->Height() || iPosition.y + iRadius >= floor[i]->Height())
			{
			floor[i]->DetectCollision_WithStatic(iPosition, iRadius, oCollisions);
			
			if(iPosition.y >= floor[i]->Height())
				break;
			}
	}

//****************************************************************************

void CCollisionDetectionManager::DetectCollision_WithDynamic(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_Dynamic>& oCollisions)
	{
	for(unsigned i=floor.size()-1; i>=0; i--)
		if(iPosition.y >= floor[i]->Height() || iPosition.y + iRadius >= floor[i]->Height())
			{
			floor[i]->DetectCollision_WithDynamic(iPosition, iRadius, oCollisions);
			
			if(iPosition.y >= floor[i]->Height())
				break;
			}
	}

//****************************************************************************

void CCollisionDetectionManager::DetectCollision_WithParticlePhisics(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_ParticlePhisics>& oCollisions)
	{
	for(unsigned i=floor.size()-1; i>=0; i--)
		if(iPosition.y >= floor[i]->Height() || iPosition.y + iRadius >= floor[i]->Height())
			{
			floor[i]->DetectCollision_WithParticlePhisics(iPosition, iRadius, oCollisions);
			
			if(iPosition.y >= floor[i]->Height())
				break;
			}
	}

//****************************************************************************

void CCollisionDetectionManager::DetectCollision_WithDoors(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CDoor_2D>& oCollisions)
	{
	for(unsigned i=floor.size()-1; i>=0; i--)
		if(iPosition.y >= floor[i]->Height() || iPosition.y + iRadius >= floor[i]->Height())
			{
			floor[i]->DetectCollision_WithDoors(iPosition, iRadius, oCollisions);
			
			if(iPosition.y >= floor[i]->Height())
				break;
			}
	}

//****************************************************************************

void CCollisionDetectionManager::DetectCollision_WithWalls(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CWall_2D>& oCollisions)
	{
	for(unsigned i=floor.size()-1; i>=0; i--)
		if(iPosition.y >= floor[i]->Height() || iPosition.y + iRadius >= floor[i]->Height())
			{
			floor[i]->DetectCollision_WithWalls(iPosition, iRadius, oCollisions);
			
			if(iPosition.y >= floor[i]->Height())
				break;
			}
	}

//****************************************************************************

bool CCollisionDetectionManager::DetectIntersection_WithStatic(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	for(unsigned i=floor.size()-1; i>=0; i--)
		if(iPosition.y >= floor[i]->Height() || iPosition.y + iRadius >= floor[i]->Height())
			{
			if(floor[i]->DetectIntersection_WithStatic(iPosition, iRadius)==true)
				return true;
			
			if(iPosition.y >= floor[i]->Height())
				break;
			}

	return false;
	}

//****************************************************************************

bool CCollisionDetectionManager::DetectIntersection_WithDynamic(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	for(unsigned i=floor.size()-1; i>=0; i--)
		if(iPosition.y >= floor[i]->Height() || iPosition.y + iRadius >= floor[i]->Height())
			{
			if(floor[i]->DetectIntersection_WithDynamic(iPosition, iRadius)==true)
				return true;
			
			if(iPosition.y >= floor[i]->Height())
				break;
			}

	return false;
	}

//****************************************************************************

bool CCollisionDetectionManager::DetectIntersection_WithParticlePhisics(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	for(unsigned i=floor.size()-1; i>=0; i--)
		if(iPosition.y >= floor[i]->Height() || iPosition.y + iRadius >= floor[i]->Height())
			{
			if(floor[i]->DetectIntersection_WithParticlePhisics(iPosition, iRadius)==true)
				return true;
			
			if(iPosition.y >= floor[i]->Height())
				break;
			}

	return false;
	}

//****************************************************************************

bool CCollisionDetectionManager::DetectIntersection_WithDoors(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	for(unsigned i=floor.size()-1; i>=0; i--)
		if(iPosition.y >= floor[i]->Height() || iPosition.y + iRadius >= floor[i]->Height())
			{
			if(floor[i]->DetectIntersection_WithDoors(iPosition, iRadius)==true)
				return true;
			
			if(iPosition.y >= floor[i]->Height())
				break;
			}

	return false;
	}

//****************************************************************************

bool CCollisionDetectionManager::DetectIntersection_WithWalls(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	for(unsigned i=floor.size()-1; i>=0; i--)
		if(iPosition.y >= floor[i]->Height() || iPosition.y + iRadius >= floor[i]->Height())
			{
			if(floor[i]->DetectIntersection_WithWalls(iPosition, iRadius)==true)
				return true;
			
			if(iPosition.y >= floor[i]->Height())
				break;
			}

	return false;
	}

//****************************************************************************




