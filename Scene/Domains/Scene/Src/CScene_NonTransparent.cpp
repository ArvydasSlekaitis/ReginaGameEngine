/*
    CScene_NonTransparent.cpp - Contains class CScene_NonTransparent implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#include <CScene_NonTransparent.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Constructor.
 */
CScene_NonTransparent::CScene_NonTransparent(LPDIRECT3DDEVICE9 iDevice) : device(NULL), instanceManager(NULL)
	{
	if(iDevice == NULL)
		throw CException_NullPointer("CScene_NonTransparent::CScene_NonTransparent(LPDIRECT3DDEVICE9 iDevice)", "iDevice");

	device = iDevice;
	device->AddRef();

	instanceManager = new CRenderInstanceManager(iDevice);
	}

//*****************************************************************************

/**
 * Destructor.
 */
CScene_NonTransparent::~CScene_NonTransparent()
	{
	if(instanceManager!=NULL)
		delete instanceManager;
	instanceManager = NULL;

	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

/**
 * Renders non transparent objects.
 */
void CScene_NonTransparent::Render(const D3DXVECTOR3& iCameraPosition, const D3DXVECTOR3& iCameraDirection, const float& iRenderDistance)
	{
	instanceManager->Render();
	}

//*****************************************************************************

/**
 * Clears all render objects.
 */
void CScene_NonTransparent::Clear()
	{
	ClearStatic();
	ClearDynamic();
	}

//*****************************************************************************

/**
 * Clears static render objects.
 */
void CScene_NonTransparent::ClearStatic()
	{
	instanceManager->ClearStatic();
	}

//*****************************************************************************

/**
 * Clears dynamic render objects.
 */
void CScene_NonTransparent::ClearDynamic()
	{
	instanceManager->ClearDynamic();
	}

//*****************************************************************************

/**
 * Performs all actions to ensure proper lost device state.
 */
void CScene_NonTransparent::OnLostDevice()
	{
	instanceManager->OnLostDevice();
	}

//*****************************************************************************

/**
 * Performs all actions to ensure proper reset device state.
 */
void CScene_NonTransparent::OnResetDevice()
	{
	instanceManager->OnResetDevice();
	}

//*****************************************************************************

/**
 * Adds render object.
 */
void CScene_NonTransparent::AddRenderObject(CRenderObject_StaticMesh* iRenderObject)
	{
	instanceManager->AddRenderObject(iRenderObject);
	}

//*****************************************************************************