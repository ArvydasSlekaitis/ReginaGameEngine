/*
    CRenderInstanceManager.cpp - Contains class CRenderInstanceManager implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#include <CRenderInstanceManager.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Constructor.
 */
CRenderInstanceManager::CRenderInstanceManager(LPDIRECT3DDEVICE9 iDevice) : renderInstanceManager_StaticMesh(NULL)
	{
	if(iDevice == NULL)
		throw CException_NullPointer("CRenderInstanceManager::CRenderInstanceManager(LPDIRECT3DDEVICE9 iDevice)", "iDevice");

	device = iDevice;
	device->AddRef();

	renderInstanceManager_StaticMesh = new CRenderInstanceManager_StaticMesh(iDevice);
	}

//*****************************************************************************

/**
 * Destructor.
 */
CRenderInstanceManager::~CRenderInstanceManager()
	{
	if(renderInstanceManager_StaticMesh!=NULL)
		delete renderInstanceManager_StaticMesh;
	renderInstanceManager_StaticMesh = NULL;

	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

/**
 * Renders all instances.
 */
void CRenderInstanceManager::Render()
	{
	renderInstanceManager_StaticMesh->Render();
	}

//*****************************************************************************

/**
 * Clear render list.
 */
void CRenderInstanceManager::Clear()
	{
	ClearStatic();
	ClearDynamic();
	}

//*****************************************************************************

/**
 * Clear static objects render list.
 */
void CRenderInstanceManager::ClearStatic()
	{
	renderInstanceManager_StaticMesh->ClearStatic();
	}

//*****************************************************************************

/**
 * Clear dynamic objects render list.
 */
void CRenderInstanceManager::ClearDynamic()
	{
	renderInstanceManager_StaticMesh->ClearDynamic();
	}

//*****************************************************************************

/**
 * Performs all actions to ensure proper lost device state.
 */
void CRenderInstanceManager::OnLostDevice()
	{
	renderInstanceManager_StaticMesh->OnLostDevice();
	}

//*****************************************************************************

/**
 * Performs all actions to ensure proper reset device state.
 */
void CRenderInstanceManager::OnResetDevice()
	{
	renderInstanceManager_StaticMesh->OnResetDevice();
	}

//*****************************************************************************

/**
 * Adds render object.
 */
void CRenderInstanceManager::AddRenderObject(CRenderObject_StaticMesh* iRenderObject)
	{
	renderInstanceManager_StaticMesh->AddRenderObject(iRenderObject);
	}

//*****************************************************************************