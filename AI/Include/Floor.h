///////////////////////////////////////////////////////////
//  Floor.h
//  Created on:      22-07-2009
//  Last modified:   31-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_FLOOR_H
#define REGINA_FLOOR_H

#include <vector>
#include <map>
#include <assert.h>
using namespace std;

#include <SelfDividingGrid_2D.h>
#include <Wall_2D.h>
#include <Door_2D.h>
#include <CollisionObject_Static.h>
#include <CollisionObject_Dynamic.h>
#include <CollisionObject_ParticlePhisics.h>
#include <ContactData_ParticleParticle.h>
#include <PhisicsManager.h>
#include <BasicMessageEnumaration.h>
#include <CustomTelegram.h>
#include <FloorTileMap.h>
#include <Functions_Text.h>
#include <Settings.h>

namespace Regina
{


class CFloor
{
TSelfDividingGrid_2D<CWall_2D>								walls;
TSelfDividingGrid_2D<CDoor_2D>								doors;
TSelfDividingGrid_2D<CCollisionObject_Static_Data>			staticObjects;
TSelfDividingGrid_2D<CCollisionObject_Dynamic_Data>			dynamicObjects;
TSelfDividingGrid_2D<CCollisionObject_ParticlePhisics_Data>	particlePhisicsObjects;

vector<CCollisionObject_Dynamic_Data*>						dynamicObjectList;
vector<CCollisionObject_ParticlePhisics_Data*>				particlePhisicsObjectList;
vector<CWall_2D*>											wallList;

CFloorTileMap*												floorTileMap;

const float height;

public:
	CFloor(const D3DXVECTOR2& iFloorCenter, const float& iFloorSizeX, const float& iFloorSizeY, const float& iHeight);
	CFloor(const D3DXVECTOR2& iFloorCenter, const float& iFloorSizeX, const float& iFloorSizeY, const float& iHeight, vector<string> iFloorDefinition);
	~CFloor();

	//Add functions
	void AddWall(CWall_2D* iWall);
	void AddDoor(CDoor_2D* iDoor);
	void AddStaticObject(CCollisionObject_Static_Data* iData);
	void AddDynamicObject(CCollisionObject_Dynamic_Data* iData);
	void AddParticlePhisicsObject(CCollisionObject_ParticlePhisics_Data* iData);

	//Remove functions
	void RemoveParticlePhisicsObject(CCollisionObject_ParticlePhisics_Data* iData);
	void RemoveDynamicObject(CCollisionObject_Dynamic_Data* iData);
	void RemoveStaticObject(CCollisionObject_Static_Data* iData);
	void RemoveDoor(CDoor_2D* iDoor);
	void RemoveWall(CWall_2D* iWall);

	float Height() const { return height; }

	void CreateGrids();
	void LoadComplete();

	void GenerateParticlePhisicsContacts();
	void EnsureDynamicZeroPenetration();

	//Particle phisics contact generation functions
	void GenerateParticlePhisicsContacts_WithFloor(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject);
	void GenerateParticlePhisicsContacts_WithWalls(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject);
	void GenerateParticlePhisicsContacts_WithDoors(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject);
	void GenerateParticlePhisicsContacts_WithStatics(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject);
	void GenerateParticlePhisicsContacts_WithDynamics(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject);
	void GenerateParticlePhisicsContacts_WithParticles(CCollisionObject_ParticlePhisics_Data* iParticlePhisicsObject);

	//Dynamic objects zero penetration functions
	void EnsureDynamicZeroPenetration_WithFloor(CCollisionObject_Dynamic_Data* iDynamicObject);
	void EnsureDynamicZeroPenetration_WithWalls(CCollisionObject_Dynamic_Data* iDynamicObject);
	void EnsureDynamicZeroPenetration_WithDoors(CCollisionObject_Dynamic_Data* iDynamicObject);
	void EnsureDynamicZeroPenetration_WithStatics(CCollisionObject_Dynamic_Data* iDynamicObject);
	void EnsureDynamicZeroPenetration_WithDynamics(CCollisionObject_Dynamic_Data* iDynamicObject);

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

	//Clear functions
	void ClearParticlePhisics();
	void ClearDynamics();

	CFloorTileMap*	FloorTileMap() { return floorTileMap; }

};

}

#endif
