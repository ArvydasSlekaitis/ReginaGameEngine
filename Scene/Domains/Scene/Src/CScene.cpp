/*
    CScene.cpp - Contains class CScene implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#include <CScene.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
* Protected constructor - used by global version.
*/
CScene::CScene() : device(NULL), nonTransparentScene(NULL), transparentScene(NULL)
	{
	}

//*****************************************************************************

/**
 * Constructor.
 */
CScene::CScene(LPDIRECT3DDEVICE9 iDevice) : device(NULL), nonTransparentScene(NULL), transparentScene(NULL)
	{
	if(iDevice == NULL)
		throw CException_NullPointer("CScene::CScene(LPDIRECT3DDEVICE9 iDevice)", "iDevice");

	device = iDevice;
	device->AddRef();

	nonTransparentScene = new CScene_NonTransparent(iDevice);
	transparentScene = new CScene_Transparent(iDevice);
	}

//*****************************************************************************

/**
 * Destructor.
 */
CScene::~CScene()
	{
	if(nonTransparentScene!=NULL)
		delete nonTransparentScene;
	nonTransparentScene = NULL;

	if(transparentScene!=NULL)
		delete transparentScene;
	transparentScene = NULL;

	for(unsigned i=0; i<renderObject_StaticMesh_Dynamic.size(); i++)
		delete renderObject_StaticMesh_Dynamic[i];
	renderObject_StaticMesh_Dynamic.clear();

	for(unsigned i=0; i<renderObject_StaticMesh_Static.size(); i++)
		delete renderObject_StaticMesh_Static[i];
	renderObject_StaticMesh_Static.clear();

	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

/**
 * Sets pointer to DirectX device.
 */
void CScene::SetDevice(LPDIRECT3DDEVICE9 iDevice)
	{
	if(iDevice == NULL)
		throw CException_NullPointer("void CScene::SetDevice(LPDIRECT3DDEVICE9 iDevice)", "iDevice");

	if(device!=NULL)
		device->Release();
	device = NULL;

	if(nonTransparentScene!=NULL)
		delete nonTransparentScene;
	nonTransparentScene = NULL;

	if(transparentScene!=NULL)
		delete transparentScene;
	transparentScene = NULL;
	
	device = iDevice;
	device->AddRef();

	nonTransparentScene = new CScene_NonTransparent(iDevice);
	transparentScene = new CScene_Transparent(iDevice);
	}

//*****************************************************************************

/**
 * Renders scene.
 */
void CScene::Render(const D3DXVECTOR3& iCameraPosition, const D3DXVECTOR3& iCameraDirection, const float& iRenderDistance)
	{
	const float renderDistanceSq = iRenderDistance*iRenderDistance;
	const unsigned numStaticMesh_Dynamic(renderObject_StaticMesh_Dynamic.size());

	for(unsigned i=0; i<numStaticMesh_Dynamic; i++)
		{
		const D3DXVECTOR3 direction = renderObject_StaticMesh_Dynamic[i]->GetPosition() - iCameraPosition;
		const float distanceSq = D3DXVec3LengthSq(&(direction));
		 
		if(distanceSq <= renderDistanceSq)
			{
			if(distanceSq <= renderObject_StaticMesh_Dynamic[i]->GetRadius()*renderObject_StaticMesh_Dynamic[i]->GetRadius())
				{
				if(renderObject_StaticMesh_Dynamic[i]->IsTransparencyEnabled()==true)
					transparentScene->AddRenderObject(renderObject_StaticMesh_Dynamic[i]);
				else
					nonTransparentScene->AddRenderObject(renderObject_StaticMesh_Dynamic[i]);
				}
			else
				{
				D3DXVECTOR3 directionNormalized;
				if(D3DXVec3Dot(D3DXVec3Normalize(&directionNormalized, &direction), &iCameraDirection)>0)
					{
					if(renderObject_StaticMesh_Dynamic[i]->IsTransparencyEnabled()==true)
						transparentScene->AddRenderObject(renderObject_StaticMesh_Dynamic[i]);
					else
						nonTransparentScene->AddRenderObject(renderObject_StaticMesh_Dynamic[i]);
					}
				}
			}
		}


	nonTransparentScene->Render(iCameraPosition, iCameraDirection, iRenderDistance);
	transparentScene->Render(iCameraPosition, iCameraDirection, iRenderDistance);
	}

//*****************************************************************************

/**
 * Clears all render objects.
 */
void CScene::Clear()
	{
	ClearStatic();
	ClearDynamic();
	}

//*****************************************************************************

/**
 * Clears static render objects.
 */
void CScene::ClearStatic()
	{
	nonTransparentScene->ClearStatic();
	transparentScene->ClearStatic();

	for(unsigned i=0; i<renderObject_StaticMesh_Static.size(); i++)
		delete renderObject_StaticMesh_Static[i];
	renderObject_StaticMesh_Static.clear();
	}

//*****************************************************************************

/**
 * Clears dynamic render objects.
 */
void CScene::ClearDynamic()
	{
	nonTransparentScene->ClearDynamic();
	transparentScene->ClearDynamic();

	const unsigned numStaticMeshDynamic(renderObject_StaticMesh_Dynamic.size());

	for(unsigned i=0; i<numStaticMeshDynamic; i++)
		delete renderObject_StaticMesh_Dynamic[i];
	renderObject_StaticMesh_Dynamic.clear();
	}

//*****************************************************************************

/**
 * Performs all actions to ensure proper lost device state.
 */
void CScene::OnLostDevice()
	{
	nonTransparentScene->OnLostDevice();
	transparentScene->OnLostDevice();
	}

//*****************************************************************************

/**
 * Performs all actions to ensure proper reset device state.
 */
void CScene::OnResetDevice()
	{
	nonTransparentScene->OnResetDevice();
	transparentScene->OnResetDevice();
	}

//*****************************************************************************

/**
 * Clears scene and releases DirectX device interface.
 */
void CScene::OnDestroyDevice()
	{
	if(device!=NULL)
		device->Release();
	device = NULL;

	if(nonTransparentScene!=NULL)
		delete nonTransparentScene;
	nonTransparentScene = NULL;

	if(transparentScene!=NULL)
		delete transparentScene;
	transparentScene = NULL;
	}

//*****************************************************************************

/**
 * Adds render object.
 */
void CScene::AddRenderObject(CRenderObject_StaticMesh& iRenderObject)
	{
	CRenderObject_StaticMesh* renderObject = new CRenderObject_StaticMesh(iRenderObject);

	if(renderObject->IsStatic() == true)
		{
		renderObject_StaticMesh_Static.push_back(renderObject);
		
		if(renderObject->IsTransparencyEnabled()==true)
			transparentScene->AddRenderObject(renderObject);
		else
			nonTransparentScene->AddRenderObject(renderObject);
		}
	else
		renderObject_StaticMesh_Dynamic.push_back(renderObject);
	}

//*****************************************************************************