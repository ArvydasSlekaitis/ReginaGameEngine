///////////////////////////////////////////////////////////
//  Floor.cpp
//  Created on:      22-07-2009
//  Last modified:   31-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Floor.h>
using namespace Regina;

//*****************************************************************************

CFloor::CFloor(const D3DXVECTOR2& iFloorCenter, const float& iFloorSizeX, const float& iFloorSizeY, const float& iHeight) : height(iHeight), walls(iFloorCenter, iFloorSizeX, iFloorSizeY), doors(iFloorCenter, iFloorSizeX, iFloorSizeY), staticObjects(iFloorCenter, iFloorSizeX, iFloorSizeY), dynamicObjects(iFloorCenter, iFloorSizeX, iFloorSizeY), particlePhisicsObjects(iFloorCenter, iFloorSizeX, iFloorSizeY), floorTileMap(NULL)
	{
	}

//*****************************************************************************

CFloor::CFloor(const D3DXVECTOR2& iFloorCenter, const float& iFloorSizeX, const float& iFloorSizeY, const float& iHeight, vector<string> iFloorDefinition) : height(iHeight), walls(iFloorCenter, iFloorSizeX, iFloorSizeY), doors(iFloorCenter, iFloorSizeX, iFloorSizeY), staticObjects(iFloorCenter, iFloorSizeX, iFloorSizeY), dynamicObjects(iFloorCenter, iFloorSizeX, iFloorSizeY), particlePhisicsObjects(iFloorCenter, iFloorSizeX, iFloorSizeY), floorTileMap(NULL)
	{
	for(unsigned i=0; i<iFloorDefinition.size(); i++)
		{		
		istringstream line(iFloorDefinition[i]);
		string type;
		line >> type;
		if(type == "FloorTileMap")
			{
			unsigned iGridSizeX;
			unsigned iGridSizeY;
			line >> iGridSizeX >> iGridSizeY;
			assert(floorTileMap == NULL);

			float tileSize = iFloorSizeX/iGridSizeX;
			floorTileMap = new CFloorTileMap(iGridSizeX, iGridSizeY, tileSize, LoadSubset(iFloorDefinition, i, i));
			}

		else

		if(type == "Wall_2D")
			{
			float iBeginX;
			float iBeginY;
			float iEndX;
			float iEndY;
			float iRestitution;
			
			line >> iBeginX >> iBeginY >> iEndX >> iEndY >> iRestitution;
			AddWall(new CWall_2D(iBeginX, iBeginY, iEndX, iEndY, iRestitution));
			}
			
		}
	}

//*****************************************************************************
	
void CFloor::AddWall(CWall_2D* iWall)
	{
	if(iWall == NULL)
		throw invalid_argument("CFloor::AddWall - argument iWall==NULL");

	walls.Add(iWall);
	walls.RecalculateBoundingVolume();
	wallList.push_back(iWall);
	}

//*****************************************************************************

void CFloor::AddDoor(CDoor_2D* iDoor)
	{
	if(iDoor == NULL)
		throw invalid_argument("CFloor::AddDoor - argument iDoor==NULL");

	doors.Add(iDoor);
	doors.RecalculateBoundingVolume();
	}

//*****************************************************************************

void CFloor::AddStaticObject(CCollisionObject_Static_Data* iData)
	{
	staticObjects.Add(iData);
	staticObjects.RecalculateBoundingVolume();
	}

//*****************************************************************************

void CFloor::AddDynamicObject(CCollisionObject_Dynamic_Data* iData)
	{
	dynamicObjects.Add(iData);
	dynamicObjectList.push_back(iData);
	}


//*****************************************************************************

void CFloor::AddParticlePhisicsObject(CCollisionObject_ParticlePhisics_Data* iData)
	{
	particlePhisicsObjects.Add(iData);
	particlePhisicsObjectList.push_back(iData);
	}

//*****************************************************************************

void CFloor::CreateGrids()
	{
	if(particlePhisicsObjects.ChildrenSize() != 0)
		{
		particlePhisicsObjects.Clear();
		particlePhisicsObjects.Add(particlePhisicsObjectList.begin(), particlePhisicsObjectList.end());
		}

	if(dynamicObjects.ChildrenSize() != 0)
		{
		dynamicObjects.Clear();
		dynamicObjects.Add(dynamicObjectList.begin(), dynamicObjectList.end());
		}
			
	unsigned iMaxParticlePhisicsObjectGridIterations =	Settings->GetParameter("MaxIterationsForParticlePhisicsGridCreation");
	unsigned iMaxDynamicObjectGridIterations =			Settings->GetParameter("MaxIterationsForDynamicObjectGridCreation");
	
	bool DynamicObjectHorizontalGridCreationEnabled =	Settings->GetParameter("DynamicObjectHorizontalGridCreationEnabled");
	bool DynamicObjectVerticalGridCreationEnabled	=	Settings->GetParameter("DynamicObjectVerticalGridCreationEnabled");
	bool DynamicObjectHorizontalVerticalGridCreationEnabled = Settings->GetParameter("DynamicObjectHorizontalVerticalGridCreationEnabled");

	bool ParticlePhisicsHorizontalGridCreationEnabled =	Settings->GetParameter("ParticlePhisicsHorizontalGridCreationEnabled");
	bool ParticlePhisicsVerticalGridCreationEnabled	=	Settings->GetParameter("ParticlePhisicsVerticalGridCreationEnabled");
	bool ParticlePhisicsHorizontalVerticalGridCreationEnabled = Settings->GetParameter("ParticlePhisicsHorizontalVerticalGridCreationEnabled");

	dynamicObjects.Create(iMaxDynamicObjectGridIterations, DynamicObjectHorizontalGridCreationEnabled, DynamicObjectVerticalGridCreationEnabled, DynamicObjectHorizontalVerticalGridCreationEnabled);
	particlePhisicsObjects.Create(iMaxParticlePhisicsObjectGridIterations, ParticlePhisicsHorizontalGridCreationEnabled, ParticlePhisicsVerticalGridCreationEnabled, ParticlePhisicsHorizontalVerticalGridCreationEnabled);
	}

//*****************************************************************************

void CFloor::ClearParticlePhisics()
	{
	particlePhisicsObjectList.clear();
	particlePhisicsObjects.Clear();
	}

//*****************************************************************************

void CFloor::ClearDynamics()
	{
	dynamicObjectList.clear();
	dynamicObjects.Clear();
	}

//*****************************************************************************

void CFloor::RemoveParticlePhisicsObject(CCollisionObject_ParticlePhisics_Data* iData)
	{
	particlePhisicsObjects.Remove(iData);

	for(unsigned i=0; i<particlePhisicsObjectList.size(); i++)
	if(particlePhisicsObjectList[i] == iData)
		{
		particlePhisicsObjectList[i] = particlePhisicsObjectList[particlePhisicsObjectList.size()-1];
		particlePhisicsObjectList.pop_back();
		}	
	}

//*****************************************************************************

void CFloor::RemoveDoor(CDoor_2D* iDoor)
	{
	doors.Remove(iDoor);
	}

//*****************************************************************************

void CFloor::RemoveWall(CWall_2D* iWall)
	{
	walls.Remove(iWall);
	}

//*****************************************************************************

void CFloor::RemoveStaticObject(CCollisionObject_Static_Data* iData)
	{
	staticObjects.Remove(iData);
	}

//*****************************************************************************

void CFloor::RemoveDynamicObject(CCollisionObject_Dynamic_Data* iData)
	{
	dynamicObjects.Remove(iData);

	for(unsigned i=0; i<dynamicObjectList.size(); i++)
	if(dynamicObjectList[i] == iData)
		{
		dynamicObjectList[i] = dynamicObjectList[dynamicObjectList.size()-1];
		dynamicObjectList.pop_back();
		}
	}

//*****************************************************************************

void CFloor::LoadComplete()
	{
	assert(staticObjects.ChildrenSize() == 0);
	assert(walls.ChildrenSize() == 0);
	assert(doors.ChildrenSize() == 0);

	unsigned numStaticIt = Settings->GetParameter("MaxIterationsForStaticObjectGridCreation");
	unsigned numWallsIt = Settings->GetParameter("MaxIterationsForWallsGridCreation");
	unsigned numDoorsIt = Settings->GetParameter("MaxIterationsForDoorsGridCreation");

	staticObjects.Create(numStaticIt);
	walls.Create(numWallsIt);
	doors.Create(numDoorsIt);
	}

//*****************************************************************************

CFloor::~CFloor()
	{
	for(unsigned i=0; i<wallList.size(); i++)
		delete wallList[i];

	wallList.clear();
	}

//*****************************************************************************

void CFloor::GenerateParticlePhisicsContacts()
	{	
	for(unsigned i=0; i<particlePhisicsObjectList.size(); i++)
		{
		GenerateParticlePhisicsContacts_WithFloor(particlePhisicsObjectList[i]);
		GenerateParticlePhisicsContacts_WithWalls(particlePhisicsObjectList[i]);
		GenerateParticlePhisicsContacts_WithDoors(particlePhisicsObjectList[i]);
		GenerateParticlePhisicsContacts_WithStatics(particlePhisicsObjectList[i]);
		GenerateParticlePhisicsContacts_WithDynamics(particlePhisicsObjectList[i]);
		GenerateParticlePhisicsContacts_WithParticles(particlePhisicsObjectList[i]);
		}
	}

//*****************************************************************************

void CFloor::EnsureDynamicZeroPenetration()
	{
	for(unsigned i=0; i<dynamicObjectList.size(); i++)
		{
		EnsureDynamicZeroPenetration_WithDynamics(dynamicObjectList[i]);
		EnsureDynamicZeroPenetration_WithStatics(dynamicObjectList[i]);
		EnsureDynamicZeroPenetration_WithDoors(dynamicObjectList[i]);
		EnsureDynamicZeroPenetration_WithWalls(dynamicObjectList[i]);
		EnsureDynamicZeroPenetration_WithFloor(dynamicObjectList[i]);
		}
	}

//*****************************************************************************

void CFloor::GenerateParticlePhisicsContacts_WithFloor(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject)
	{
	if(floorTileMap!=NULL)
		{
		CFloorTile* tile_center = floorTileMap->GetTile(iParticlePhisicsObject->Position());
		CFloorTile* tile_x		= floorTileMap->GetTile(D3DXVECTOR3(iParticlePhisicsObject->Position().x + iParticlePhisicsObject->Radius(), iParticlePhisicsObject->Position().y, iParticlePhisicsObject->Position().z));
		CFloorTile* tile_nx		= floorTileMap->GetTile(D3DXVECTOR3(iParticlePhisicsObject->Position().x - iParticlePhisicsObject->Radius(), iParticlePhisicsObject->Position().y, iParticlePhisicsObject->Position().z));
		CFloorTile* tile_z		= floorTileMap->GetTile(D3DXVECTOR3(iParticlePhisicsObject->Position().x, iParticlePhisicsObject->Position().y, iParticlePhisicsObject->Position().z  + iParticlePhisicsObject->Radius()));
		CFloorTile* tile_nz		= floorTileMap->GetTile(D3DXVECTOR3(iParticlePhisicsObject->Position().x, iParticlePhisicsObject->Position().y, iParticlePhisicsObject->Position().z  - iParticlePhisicsObject->Radius()));

		if(tile_center!=NULL)
			{
			float height = tile_center->GetHeight(iParticlePhisicsObject->Position());
			if(iParticlePhisicsObject->Position().y - iParticlePhisicsObject->Radius()< height  && iParticlePhisicsObject->Position().y + iParticlePhisicsObject->Radius() >= this->Height())
				{
				CContactData* contact = new CContactData_ParticleImmovable(iParticlePhisicsObject->ParticlePhisics(), tile_center->GetNormal(iParticlePhisicsObject->Position()), iParticlePhisicsObject->Position().y - iParticlePhisicsObject->Radius() -height, (tile_center->Restitution() + iParticlePhisicsObject->Restitution())/2);
				PhisicsManager->AddContact(contact);

				if(iParticlePhisicsObject->CanSendMessageToEntity())
					iParticlePhisicsObject->SendMessageToEntity(new CTelegram(0, iParticlePhisicsObject->EntityID(), BasicMessageID::msg_Collision_WithFloor, 0));

				}
			}

		if(tile_x!=tile_center && tile_x!=NULL)
			{
			float height = tile_x->GetHeight(D3DXVECTOR3(iParticlePhisicsObject->Position().x + iParticlePhisicsObject->Radius(), iParticlePhisicsObject->Position().y, iParticlePhisicsObject->Position().z));
			if(iParticlePhisicsObject->Position().y < height  && iParticlePhisicsObject->Position().y >= this->Height())
				{
				CContactData* contact = new CContactData_ParticleImmovable(iParticlePhisicsObject->ParticlePhisics(), D3DXVECTOR3(-1, 0, 0),  -tile_x->Center().x + tile_x->Size()/2 + iParticlePhisicsObject->Position().x, (tile_x->Restitution() + iParticlePhisicsObject->Restitution())/2);
				PhisicsManager->AddContact(contact);

				if(iParticlePhisicsObject->CanSendMessageToEntity())
					iParticlePhisicsObject->SendMessageToEntity(new CTelegram(0, iParticlePhisicsObject->EntityID(), BasicMessageID::msg_Collision_WithFloor, 0));

				}
			}

		if(tile_nx!=tile_center && tile_nx!=NULL)
			{
			float height = tile_nx->GetHeight(D3DXVECTOR3(iParticlePhisicsObject->Position().x - iParticlePhisicsObject->Radius(), iParticlePhisicsObject->Position().y, iParticlePhisicsObject->Position().z));
			if(iParticlePhisicsObject->Position().y < height && iParticlePhisicsObject->Position().y >= this->Height())
				{
				CContactData* contact = new CContactData_ParticleImmovable(iParticlePhisicsObject->ParticlePhisics(), D3DXVECTOR3(1, 0, 0),  tile_nx->Center().x + tile_nx->Size()/2 - iParticlePhisicsObject->Position().x, (tile_nx->Restitution() + iParticlePhisicsObject->Restitution())/2);
				PhisicsManager->AddContact(contact);

				if(iParticlePhisicsObject->CanSendMessageToEntity())
					iParticlePhisicsObject->SendMessageToEntity(new CTelegram(0, iParticlePhisicsObject->EntityID(), BasicMessageID::msg_Collision_WithFloor, 0));

				}
			}
		
		if(tile_z!=tile_center && tile_z!=NULL)
			{
			float height = tile_z->GetHeight(D3DXVECTOR3(iParticlePhisicsObject->Position().x, iParticlePhisicsObject->Position().y, iParticlePhisicsObject->Position().z + iParticlePhisicsObject->Radius()));
			if(iParticlePhisicsObject->Position().y < height  && iParticlePhisicsObject->Position().y >= this->Height())
				{
				CContactData* contact = new CContactData_ParticleImmovable(iParticlePhisicsObject->ParticlePhisics(), D3DXVECTOR3(0, 0, -1),  -tile_z->Center().y + tile_z->Size()/2 + iParticlePhisicsObject->Position().z, (tile_z->Restitution() + iParticlePhisicsObject->Restitution())/2);
				PhisicsManager->AddContact(contact);

				if(iParticlePhisicsObject->CanSendMessageToEntity())
					iParticlePhisicsObject->SendMessageToEntity(new CTelegram(0, iParticlePhisicsObject->EntityID(), BasicMessageID::msg_Collision_WithFloor, 0));

				}
			}

		if(tile_nz!=tile_center && tile_nz!=NULL)
			{
			float height = tile_nz->GetHeight(D3DXVECTOR3(iParticlePhisicsObject->Position().x, iParticlePhisicsObject->Position().y, iParticlePhisicsObject->Position().z - iParticlePhisicsObject->Radius()));
			if(iParticlePhisicsObject->Position().y < height  && iParticlePhisicsObject->Position().y >= this->Height())
				{
				CContactData* contact = new CContactData_ParticleImmovable(iParticlePhisicsObject->ParticlePhisics(), D3DXVECTOR3(0, 0, 1),  tile_nz->Center().y + tile_nz->Size()/2 - iParticlePhisicsObject->Position().z, (tile_nz->Restitution() + iParticlePhisicsObject->Restitution())/2);
				PhisicsManager->AddContact(contact);

				if(iParticlePhisicsObject->CanSendMessageToEntity())
					iParticlePhisicsObject->SendMessageToEntity(new CTelegram(0, iParticlePhisicsObject->EntityID(), BasicMessageID::msg_Collision_WithFloor, 0));

				}
			}
		}
	}

//*****************************************************************************

void CFloor::GenerateParticlePhisicsContacts_WithWalls(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject)
	{
	vector<CWall_2D*> collisionsWithWalls;
	walls.CheckCollision(iParticlePhisicsObject->PositionXZ(), iParticlePhisicsObject->Radius(), &collisionsWithWalls);
	
	for(unsigned ii=0; ii<collisionsWithWalls.size(); ii++)
		{
		float oX1;
		float oY1;
		float oX2;
		float oY2;
		float oPenetration;
		unsigned numCollisions = collisionsWithWalls[ii]->Intersect(iParticlePhisicsObject->PositionXZ(), iParticlePhisicsObject->Radius(), oX1, oY1, oX2, oY2, oPenetration);

		if(numCollisions > 0)
			{
			D3DXVECTOR2 direction = iParticlePhisicsObject->PositionXZ() - D3DXVECTOR2(oX1, oY1);
			CContactData* contact = new CContactData_ParticleImmovable(iParticlePhisicsObject->ParticlePhisics());

			contact->SetPenetration(oPenetration);
			contact->SetRestitution((iParticlePhisicsObject->Restitution() +  collisionsWithWalls[ii]->Restitution())/2);

			if(D3DXVec2Dot(&direction, &(collisionsWithWalls[ii]->Normal())) > 0)
				contact->SetContactNormal(D3DXVECTOR3(collisionsWithWalls[ii]->Normal().x, 0, collisionsWithWalls[ii]->Normal().y));
			else
				contact->SetContactNormal(-D3DXVECTOR3(collisionsWithWalls[ii]->Normal().x, 0, collisionsWithWalls[ii]->Normal().y));

			PhisicsManager->AddContact(contact);

			if(iParticlePhisicsObject->CanSendMessageToEntity())
				iParticlePhisicsObject->SendMessageToEntity(new CUnaryTelegram<CWall_2D>(0, iParticlePhisicsObject->EntityID(), BasicMessageID::msg_Collision_With2DWall, 0, *collisionsWithWalls[ii]));

			}

		}
	}

//*****************************************************************************

void CFloor::GenerateParticlePhisicsContacts_WithDoors(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject)
	{
	vector<CDoor_2D*> collisionsWithDoors;
	doors.CheckCollision(iParticlePhisicsObject->PositionXZ(), iParticlePhisicsObject->Radius(), &collisionsWithDoors);
	
	for(unsigned ii=0; ii<collisionsWithDoors.size(); ii++)
		if(collisionsWithDoors[ii]->Closed() == true)
		{
		float oX1;
		float oY1;
		float oX2;
		float oY2;
		float oPenetration;
		unsigned numCollisions = collisionsWithDoors[ii]->Wall_2D().Intersect(iParticlePhisicsObject->PositionXZ(), iParticlePhisicsObject->Radius(), oX1, oY1, oX2, oY2, oPenetration);

		if(numCollisions > 0)
			{
			D3DXVECTOR2 direction = iParticlePhisicsObject->PositionXZ() - D3DXVECTOR2(oX1, oY1);
			CContactData* contact = new CContactData_ParticleImmovable(iParticlePhisicsObject->ParticlePhisics());

			contact->SetPenetration(oPenetration);
			contact->SetRestitution((iParticlePhisicsObject->Restitution() +  collisionsWithDoors[ii]->Wall_2D().Restitution())/2);

			if(D3DXVec2Dot(&direction, &(collisionsWithDoors[ii]->Wall_2D().Normal())) > 0)
				contact->SetContactNormal(D3DXVECTOR3(collisionsWithDoors[ii]->Wall_2D().Normal().x, 0, collisionsWithDoors[ii]->Wall_2D().Normal().y));
			else
				contact->SetContactNormal(-D3DXVECTOR3(collisionsWithDoors[ii]->Wall_2D().Normal().x, 0, collisionsWithDoors[ii]->Wall_2D().Normal().y));

			PhisicsManager->AddContact(contact);

			if(iParticlePhisicsObject->CanSendMessageToEntity())
				iParticlePhisicsObject->SendMessageToEntity(new CUnaryTelegram<CDoor_2D>(0, iParticlePhisicsObject->EntityID(), BasicMessageID::msg_Collision_With2DDoor, 0, *collisionsWithDoors[ii]));

			}

		}
	}

//*****************************************************************************

void CFloor::GenerateParticlePhisicsContacts_WithStatics(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject)
	{
	vector<CCollisionObject_Static_Data*> collisionsWithStatics;
	staticObjects.CheckCollision(iParticlePhisicsObject->PositionXZ(), iParticlePhisicsObject->Radius(), &collisionsWithStatics);

	for(unsigned ii=0; ii<collisionsWithStatics.size(); ii++)
		{
		vector<CBasicContactData> oContactData;
		collisionsWithStatics[ii]->CollisionMesh()->DetectContacts(iParticlePhisicsObject->Position(), iParticlePhisicsObject->Radius(), iParticlePhisicsObject->Restitution(), oContactData);
		for(unsigned iii=0; iii<oContactData.size(); iii++)
			{
			CContactData* contact = new CContactData_ParticleImmovable(iParticlePhisicsObject->ParticlePhisics(), oContactData[iii]);
			PhisicsManager->AddContact(contact);
			
			if(iParticlePhisicsObject->CanSendMessageToEntity())
					iParticlePhisicsObject->SendMessageToEntity(new CUnaryTelegram<CCollisionObject_Static>(0, iParticlePhisicsObject->EntityID(), BasicMessageID::msg_Collision_WithStaticObject, 0, CCollisionObject_Static(collisionsWithStatics[ii])));

			if(collisionsWithStatics[ii]->CanSendMessageToEntity())
					collisionsWithStatics[ii]->SendMessageToEntity(new CUnaryTelegram<CCollisionObject_ParticlePhisics>(0, collisionsWithStatics[ii]->EntityID(), BasicMessageID::msg_Collision_WithParticlePhisicsObject, 0, CCollisionObject_ParticlePhisics(iParticlePhisicsObject)));

			}
		}
	}

//*****************************************************************************

void CFloor::GenerateParticlePhisicsContacts_WithDynamics(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject)
	{
	vector<CCollisionObject_Dynamic_Data*> collisionsWithDynamics;
	dynamicObjects.CheckCollision(iParticlePhisicsObject->PositionXZ(), iParticlePhisicsObject->Radius(), &collisionsWithDynamics);

	for(unsigned ii=0; ii<collisionsWithDynamics.size(); ii++)
		{
		vector<CBasicContactData> oContactData;
		collisionsWithDynamics[ii]->CollisionMesh()->DetectContacts(iParticlePhisicsObject->Position(), iParticlePhisicsObject->Radius(), oContactData);
		for(unsigned iii=0; iii<oContactData.size(); iii++)
			{
			CContactData* contact = new CContactData_ParticleImmovable(iParticlePhisicsObject->ParticlePhisics(), oContactData[iii]);
			PhisicsManager->AddContact(contact);
			
			if(iParticlePhisicsObject->CanSendMessageToEntity())
					iParticlePhisicsObject->SendMessageToEntity(new CUnaryTelegram<CCollisionObject_Dynamic>(0, iParticlePhisicsObject->EntityID(), BasicMessageID::msg_Collision_WithDynamicObject, 0, CCollisionObject_Dynamic(collisionsWithDynamics[ii])));

			if(collisionsWithDynamics[ii]->CanSendMessageToEntity())
					collisionsWithDynamics[ii]->SendMessageToEntity(new CUnaryTelegram<CCollisionObject_ParticlePhisics>(0, collisionsWithDynamics[ii]->EntityID(), BasicMessageID::msg_Collision_WithParticlePhisicsObject, 0, CCollisionObject_ParticlePhisics(iParticlePhisicsObject)));

			}
		}
	}

//*****************************************************************************

void CFloor::GenerateParticlePhisicsContacts_WithParticles(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject)
	{
	vector<CCollisionObject_ParticlePhisics_Data*> collisionsWithParticlePhisics;
	particlePhisicsObjects.CheckCollision(iParticlePhisicsObject->PositionXZ(), iParticlePhisicsObject->Radius(), &collisionsWithParticlePhisics);

	for(unsigned ii=0; ii<collisionsWithParticlePhisics.size(); ii++)
	if(iParticlePhisicsObject!=collisionsWithParticlePhisics[ii])
		{
		D3DXVECTOR3 contactNormal =  iParticlePhisicsObject->Position() - collisionsWithParticlePhisics[ii]->Position();
		float curLength = D3DXVec3Length(&contactNormal); 
		if(curLength < iParticlePhisicsObject->Radius() +  collisionsWithParticlePhisics[ii]->Radius())
			{
			CContactData* contact = new CContactData_ParticleParticle(iParticlePhisicsObject->ParticlePhisics(), collisionsWithParticlePhisics[ii]->ParticlePhisics());

			if(curLength!=0)
				contactNormal/=curLength;
			
			contact->SetContactNormal(contactNormal);
			contact->SetPenetration(iParticlePhisicsObject->Radius() +  collisionsWithParticlePhisics[ii]->Radius() - curLength);
			contact->SetRestitution((iParticlePhisicsObject->Restitution() +  collisionsWithParticlePhisics[ii]->Restitution())/2);

			PhisicsManager->AddContact(contact);

			if(iParticlePhisicsObject->CanSendMessageToEntity())
					iParticlePhisicsObject->SendMessageToEntity(new CUnaryTelegram<CCollisionObject_ParticlePhisics>(0, iParticlePhisicsObject->EntityID(), BasicMessageID::msg_Collision_WithParticlePhisicsObject, 0, CCollisionObject_ParticlePhisics(collisionsWithParticlePhisics[ii])));

			if(collisionsWithParticlePhisics[ii]->CanSendMessageToEntity())
					collisionsWithParticlePhisics[ii]->SendMessageToEntity(new CUnaryTelegram<CCollisionObject_ParticlePhisics>(0, collisionsWithParticlePhisics[ii]->EntityID(), BasicMessageID::msg_Collision_WithParticlePhisicsObject, 0, CCollisionObject_ParticlePhisics(iParticlePhisicsObject)));

			}
		}
	}

//*****************************************************************************

void CFloor::EnsureDynamicZeroPenetration_WithFloor(CCollisionObject_Dynamic_Data* iDynamicObject)
	{
	if(floorTileMap!=NULL)
		{
		CFloorTile* tile_center = floorTileMap->GetTile(iDynamicObject->Position());
		CFloorTile* tile_x		= floorTileMap->GetTile(D3DXVECTOR3(iDynamicObject->Position().x + iDynamicObject->Radius(), iDynamicObject->Position().y, iDynamicObject->Position().z));
		CFloorTile* tile_nx		= floorTileMap->GetTile(D3DXVECTOR3(iDynamicObject->Position().x - iDynamicObject->Radius(), iDynamicObject->Position().y, iDynamicObject->Position().z));
		CFloorTile* tile_z		= floorTileMap->GetTile(D3DXVECTOR3(iDynamicObject->Position().x, iDynamicObject->Position().y, iDynamicObject->Position().z  + iDynamicObject->Radius()));
		CFloorTile* tile_nz		= floorTileMap->GetTile(D3DXVECTOR3(iDynamicObject->Position().x, iDynamicObject->Position().y, iDynamicObject->Position().z  - iDynamicObject->Radius()));

		if(tile_center!=NULL)
			{
			float height = tile_center->GetHeight(iDynamicObject->Position());
			if(iDynamicObject->Position().y - iDynamicObject->Radius()< height  && iDynamicObject->Position().y + iDynamicObject->Radius() >= this->Height())
				{			
				iDynamicObject->SetPosition(iDynamicObject->Position() + D3DXVECTOR3(0, height - iDynamicObject->Position().y + iDynamicObject->Radius(), 0));
				}
			}

		if(tile_x!=tile_center && tile_x!=NULL)
			{
			float height = tile_x->GetHeight(D3DXVECTOR3(iDynamicObject->Position().x + iDynamicObject->Radius(), iDynamicObject->Position().y, iDynamicObject->Position().z));
			if(iDynamicObject->Position().y < height  && iDynamicObject->Position().y >= this->Height())
				{	
				iDynamicObject->SetPosition(iDynamicObject->Position() + D3DXVECTOR3(-(-tile_x->Center().x + tile_x->Size()/2 + iDynamicObject->Position().x + iDynamicObject->Radius()), 0, 0));
				}
			}

		if(tile_nx!=tile_center && tile_nx!=NULL)
			{
			float height = tile_nx->GetHeight(D3DXVECTOR3(iDynamicObject->Position().x - iDynamicObject->Radius(), iDynamicObject->Position().y, iDynamicObject->Position().z));
			if(iDynamicObject->Position().y < height && iDynamicObject->Position().y >= this->Height())
				{
				iDynamicObject->SetPosition(iDynamicObject->Position() + D3DXVECTOR3(-(tile_nx->Center().x + tile_nx->Size()/2 - iDynamicObject->Position().x - iDynamicObject->Radius()), 0, 0));
				}
			}
		
		if(tile_z!=tile_center && tile_z!=NULL)
			{
			float height = tile_z->GetHeight(D3DXVECTOR3(iDynamicObject->Position().x, iDynamicObject->Position().y, iDynamicObject->Position().z + iDynamicObject->Radius()));
			if(iDynamicObject->Position().y < height  && iDynamicObject->Position().y >= this->Height())
				{
				iDynamicObject->SetPosition(iDynamicObject->Position() + D3DXVECTOR3(-(-tile_z->Center().y + tile_z->Size()/2 + iDynamicObject->Position().z + iDynamicObject->Radius()), 0, 0));
				}
			}

		if(tile_nz!=tile_center && tile_nz!=NULL)
			{
			float height = tile_nz->GetHeight(D3DXVECTOR3(iDynamicObject->Position().x, iDynamicObject->Position().y, iDynamicObject->Position().z - iDynamicObject->Radius()));
			if(iDynamicObject->Position().y < height  && iDynamicObject->Position().y >= this->Height())
				{
				iDynamicObject->SetPosition(iDynamicObject->Position() + D3DXVECTOR3(-(tile_nz->Center().y + tile_nz->Size()/2 - iDynamicObject->Position().z - iDynamicObject->Radius()), 0, 0));
				}
			}
		}			
	}

//*****************************************************************************

void CFloor::EnsureDynamicZeroPenetration_WithWalls(CCollisionObject_Dynamic_Data* iDynamicObject)
	{
	vector<CWall_2D*> collisionsWithWalls;
	walls.CheckCollision(iDynamicObject->PositionXZ(), iDynamicObject->Radius(), &collisionsWithWalls);
	
	for(unsigned ii=0; ii<collisionsWithWalls.size(); ii++)
		{
		float oX1;
		float oY1;
		float oX2;
		float oY2;
		float oPenetration;
		unsigned numCollisions = collisionsWithWalls[ii]->Intersect(iDynamicObject->PositionXZ(), iDynamicObject->Radius(), oX1, oY1, oX2, oY2, oPenetration);

		if(numCollisions > 0)
			{
			D3DXVECTOR2 direction = iDynamicObject->PositionXZ() - D3DXVECTOR2(oX1, oY1);
			D3DXVec2Normalize(&direction, &direction);
			if(D3DXVec2Dot(&direction, &(collisionsWithWalls[ii]->Normal())) > 0)
				iDynamicObject->SetPosition(iDynamicObject->Position() + D3DXVECTOR3(collisionsWithWalls[ii]->Normal().x, 0, collisionsWithWalls[ii]->Normal().y)*oPenetration);
			else
				iDynamicObject->SetPosition(iDynamicObject->Position() - D3DXVECTOR3(collisionsWithWalls[ii]->Normal().x, 0, collisionsWithWalls[ii]->Normal().y)*oPenetration);

			if(iDynamicObject->CanSendMessageToEntity())
				iDynamicObject->SendMessageToEntity(new CUnaryTelegram<CWall_2D>(0, iDynamicObject->EntityID(), BasicMessageID::msg_Collision_With2DWall, 0, *collisionsWithWalls[ii]));
			}

		}
	}

//*****************************************************************************

void CFloor::EnsureDynamicZeroPenetration_WithDoors(CCollisionObject_Dynamic_Data* iDynamicObject)
	{
	vector<CDoor_2D*> collisionsWithDoors;
	doors.CheckCollision(iDynamicObject->PositionXZ(), iDynamicObject->Radius(), &collisionsWithDoors);
	
	for(unsigned ii=0; ii<collisionsWithDoors.size(); ii++)
		if(collisionsWithDoors[ii]->Closed() == true)
		{
		float oX1;
		float oY1;
		float oX2;
		float oY2;
		float oPenetration;
		unsigned numCollisions = collisionsWithDoors[ii]->Wall_2D().Intersect(iDynamicObject->PositionXZ(), iDynamicObject->Radius(), oX1, oY1, oX2, oY2, oPenetration);

		if(numCollisions > 0)
			{
			D3DXVECTOR2 direction = iDynamicObject->PositionXZ() - D3DXVECTOR2(oX1, oY1);
			D3DXVec2Normalize(&direction, &direction);
			if(D3DXVec2Dot(&direction, &(collisionsWithDoors[ii]->Wall_2D().Normal())) > 0)
				iDynamicObject->SetPosition(iDynamicObject->Position() + D3DXVECTOR3(collisionsWithDoors[ii]->Wall_2D().Normal().x, 0, collisionsWithDoors[ii]->Wall_2D().Normal().y)*oPenetration);
			else
				iDynamicObject->SetPosition(iDynamicObject->Position() - D3DXVECTOR3(collisionsWithDoors[ii]->Wall_2D().Normal().x, 0, collisionsWithDoors[ii]->Wall_2D().Normal().y)*oPenetration);

			if(iDynamicObject->CanSendMessageToEntity())
				iDynamicObject->SendMessageToEntity(new CUnaryTelegram<CDoor_2D>(0, iDynamicObject->EntityID(), BasicMessageID::msg_Collision_With2DDoor, 0, *collisionsWithDoors[ii]));
			}

		}
	}

//*****************************************************************************

void CFloor::EnsureDynamicZeroPenetration_WithStatics(CCollisionObject_Dynamic_Data* iDynamicObject)
	{
	vector<CCollisionObject_Static_Data*> collisionsWithStatic;
	staticObjects.CheckCollision(iDynamicObject->PositionXZ(), iDynamicObject->Radius(), &collisionsWithStatic);

	for(unsigned ii=0; ii<collisionsWithStatic.size(); ii++)
		{
		vector<CBasicContactData> oContactData;
		collisionsWithStatic[ii]->CollisionMesh()->DetectContacts(iDynamicObject->Position(), iDynamicObject->Radius(), oContactData);
		for(unsigned iii=0; iii<oContactData.size(); iii++)
			{
			iDynamicObject->SetPosition(iDynamicObject->Position() - oContactData[iii].ContactNormal()*oContactData[iii].Penetration());
			
			if(iDynamicObject->CanSendMessageToEntity())
				iDynamicObject->SendMessageToEntity(new CUnaryTelegram<CCollisionObject_Static>(0, iDynamicObject->EntityID(), BasicMessageID::msg_Collision_WithStaticObject, 0, CCollisionObject_Static(collisionsWithStatic[ii])));

			if(collisionsWithStatic[ii]->CanSendMessageToEntity())
				collisionsWithStatic[ii]->SendMessageToEntity(new CUnaryTelegram<CCollisionObject_Dynamic>(0, collisionsWithStatic[ii]->EntityID(), BasicMessageID::msg_Collision_WithDynamicObject, 0, CCollisionObject_Dynamic(iDynamicObject)));
			}

		}
	}

//*****************************************************************************

void CFloor::EnsureDynamicZeroPenetration_WithDynamics(CCollisionObject_Dynamic_Data* iDynamicObject)
	{
	vector<CCollisionObject_Dynamic_Data*> collisionsWithDynamic;
	dynamicObjects.CheckCollision(iDynamicObject->PositionXZ(), iDynamicObject->Radius(), &collisionsWithDynamic);

	for(unsigned ii=0; ii<collisionsWithDynamic.size(); ii++)
	if(iDynamicObject!=collisionsWithDynamic[ii])
		{
	
		D3DXVECTOR2 direction = iDynamicObject->PositionXZ() - collisionsWithDynamic[ii]->PositionXZ();
		
		float distance = direction.x*direction.x+direction.y*direction.y;
		if(distance > 0.0f)
			distance = sqrt(distance);
		else
			distance = 0.0f;
		

		const float moveAmount = distance - iDynamicObject->Radius() - collisionsWithDynamic[ii]->Radius() ;

		if(moveAmount < 0)
			{
			D3DXVec2Normalize(&direction, &direction);
			D3DXVECTOR3 dir(direction.x, 0, direction.y);
			
			iDynamicObject->SetPosition(iDynamicObject->Position() - dir*(moveAmount));
			collisionsWithDynamic[ii]->SetPosition(collisionsWithDynamic[ii]->Position() + dir*(moveAmount));

			if(iDynamicObject->CanSendMessageToEntity())
				iDynamicObject->SendMessageToEntity(new CUnaryTelegram<CCollisionObject_Dynamic>(0, iDynamicObject->EntityID(), BasicMessageID::msg_Collision_WithDynamicObject, 0, CCollisionObject_Dynamic(collisionsWithDynamic[ii])));
			
			if(collisionsWithDynamic[ii]->CanSendMessageToEntity())
				collisionsWithDynamic[ii]->SendMessageToEntity(new CUnaryTelegram<CCollisionObject_Dynamic>(0, collisionsWithDynamic[ii]->EntityID(), BasicMessageID::msg_Collision_WithDynamicObject, 0, CCollisionObject_Dynamic(iDynamicObject)));

			}

		}


	}

//*****************************************************************************

void CFloor::DetectCollision_WithStatic(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_Static>& oCollisions)
	{	
	vector<CCollisionObject_Static_Data*> collisionsWithStatic;
	staticObjects.CheckCollision(iPosition, iRadius, &collisionsWithStatic);

	for(unsigned i=0; i<collisionsWithStatic.size(); i++)
		{
		if(collisionsWithStatic[i]->CollisionMesh()->Intersect(iPosition, iRadius) == true)
			oCollisions.push_back(CCollisionObject_Static(collisionsWithStatic[i]));
		}
	}

//*****************************************************************************

void CFloor::DetectCollision_WithDynamic(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_Dynamic>& oCollisions)
	{
	vector<CCollisionObject_Dynamic_Data*> collisionsWithDynamic;
	dynamicObjects.CheckCollision(iPosition, iRadius, &collisionsWithDynamic);

	for(unsigned i=0; i<collisionsWithDynamic.size(); i++)
		{
		if(collisionsWithDynamic[i]->CollisionMesh()->Intersect(iPosition, iRadius) == true)
			oCollisions.push_back(CCollisionObject_Dynamic(collisionsWithDynamic[i]));
		}
	}

//*****************************************************************************

void CFloor::DetectCollision_WithParticlePhisics(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CCollisionObject_ParticlePhisics>& oCollisions)
	{
	vector<CCollisionObject_ParticlePhisics_Data*> collisionsWithParticlePhisics;
	particlePhisicsObjects.CheckCollision(iPosition, iRadius, &collisionsWithParticlePhisics);

	for(unsigned i=0; i<collisionsWithParticlePhisics.size(); i++)
		{
		D3DXVECTOR3 contactNormal =  iPosition - collisionsWithParticlePhisics[i]->Position();
		if(D3DXVec3Length(&contactNormal) < iRadius +  collisionsWithParticlePhisics[i]->Radius())
			oCollisions.push_back(CCollisionObject_ParticlePhisics(collisionsWithParticlePhisics[i]));
		}
	}

//*****************************************************************************

void CFloor::DetectCollision_WithDoors(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CDoor_2D>& oCollisions)
	{
	vector<CDoor_2D*> collisionsWithDoors;
	doors.CheckCollision(iPosition, iRadius, &collisionsWithDoors);

	for(unsigned i=0; i<collisionsWithDoors.size(); i++)
		{
		if(collisionsWithDoors[i]->Wall_2D().Intersect(D3DXVECTOR2(iPosition.x, iPosition.z), iRadius) == true)
			oCollisions.push_back(*collisionsWithDoors[i]);
		}
	}

//*****************************************************************************

void CFloor::DetectCollision_WithWalls(const D3DXVECTOR3& iPosition, const float& iRadius, vector<CWall_2D>& oCollisions)
	{
	vector<CWall_2D*> collisionsWithWalls;
	walls.CheckCollision(iPosition, iRadius, &collisionsWithWalls);

	for(unsigned i=0; i<collisionsWithWalls.size(); i++)
		{
		if(collisionsWithWalls[i]->Intersect(D3DXVECTOR2(iPosition.x, iPosition.z), iRadius) == true)
			oCollisions.push_back(*collisionsWithWalls[i]);
		}
	}

//*****************************************************************************

bool CFloor::DetectIntersection_WithStatic(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	vector<CCollisionObject_Static_Data*> collisionsWithStatic;
	staticObjects.CheckCollision(iPosition, iRadius, &collisionsWithStatic);

	for(unsigned i=0; i<collisionsWithStatic.size(); i++)
		{
		if(collisionsWithStatic[i]->CollisionMesh()->Intersect(iPosition, iRadius) == true)
			return true;
		}

	return false;
	}

//*****************************************************************************

bool CFloor::DetectIntersection_WithDynamic(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	vector<CCollisionObject_Dynamic_Data*> collisionsWithDynamic;
	dynamicObjects.CheckCollision(iPosition, iRadius, &collisionsWithDynamic);

	for(unsigned i=0; i<collisionsWithDynamic.size(); i++)
		{
		if(collisionsWithDynamic[i]->CollisionMesh()->Intersect(iPosition, iRadius) == true)
			return true;
		}

	return false;
	}

//*****************************************************************************

bool CFloor::DetectIntersection_WithParticlePhisics(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	vector<CCollisionObject_ParticlePhisics_Data*> collisionsWithParticlePhisics;
	particlePhisicsObjects.CheckCollision(iPosition, iRadius, &collisionsWithParticlePhisics);

	for(unsigned i=0; i<collisionsWithParticlePhisics.size(); i++)
		{
		D3DXVECTOR3 contactNormal =  iPosition - collisionsWithParticlePhisics[i]->Position();
		if(D3DXVec3Length(&contactNormal) < iRadius +  collisionsWithParticlePhisics[i]->Radius())
			return true;
		}

	return false;
	}

//*****************************************************************************

bool CFloor::DetectIntersection_WithDoors(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	vector<CDoor_2D*> collisionsWithDoors;
	doors.CheckCollision(iPosition, iRadius, &collisionsWithDoors);

	for(unsigned i=0; i<collisionsWithDoors.size(); i++)
		if(collisionsWithDoors[i]->Closed() == true)
			{
			if(collisionsWithDoors[i]->Wall_2D().Intersect(D3DXVECTOR2(iPosition.x, iPosition.z), iRadius) == true)
				return true;
			}

	return false;
	}

//*****************************************************************************

bool CFloor::DetectIntersection_WithWalls(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	vector<CWall_2D*> collisionsWithWalls;
	walls.CheckCollision(iPosition, iRadius, &collisionsWithWalls);

	for(unsigned i=0; i<collisionsWithWalls.size(); i++)
		{
		if(collisionsWithWalls[i]->Intersect(D3DXVECTOR2(iPosition.x, iPosition.z), iRadius) == true)
			return true;
		}

	return false;
	}

//*****************************************************************************


