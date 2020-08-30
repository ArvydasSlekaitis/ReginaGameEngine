///////////////////////////////////////////////////////////
//  CRenderInstanceManager.cpp
//  Created on:      27-11-2009
//  Last modified:   27-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CRenderInstanceManager.h>
using namespace Regina;


//*****************************************************************************

CRenderInstanceManager::~CRenderInstanceManager()
	{
	if(simpleMeshRenderInstanceManager!=NULL)
		delete simpleMeshRenderInstanceManager;
	simpleMeshRenderInstanceManager = NULL;

	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

CRenderInstanceManager::CRenderInstanceManager(LPDIRECT3DDEVICE9 iDevice) : device(NULL), simpleMeshRenderInstanceManager(NULL)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CRenderInstanceManager::CRenderInstanceManager - argument iDevice==NULL");

	device = iDevice;
	device->AddRef();

	simpleMeshRenderInstanceManager = new CSimpleMeshRenderInstanceManager(iDevice);
	assert(simpleMeshRenderInstanceManager!=NULL && L"CRenderInstanceManager::CRenderInstanceManager - cannot create new CSimpleMeshRenderInstanceManager");
	}

//*****************************************************************************

void CRenderInstanceManager::Render(const eRenderType& iRenderType, const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition)
  	{
	simpleMeshRenderInstanceManager->Render(iRenderType, iCameraView, iCameraProj, iCameraPosition);
	}

//*****************************************************************************

void CRenderInstanceManager::Clear()
  	{
	simpleMeshRenderInstanceManager->Clear();
	}

//*****************************************************************************

void CRenderInstanceManager::ClearStatic()
  	{
	simpleMeshRenderInstanceManager->ClearStatic();
	}

//*****************************************************************************

void CRenderInstanceManager::ClearDynamic()
  	{
	simpleMeshRenderInstanceManager->ClearDynamic();
	}

//*****************************************************************************

void CRenderInstanceManager::OnLostDevice()
  	{
	simpleMeshRenderInstanceManager->OnLostDevice();
	}

//*****************************************************************************

void CRenderInstanceManager::OnResetDevice()
  	{
	simpleMeshRenderInstanceManager->OnResetDevice();
	}

//*****************************************************************************

void CRenderInstanceManager::AddRenderObject(CRenderObject_SimpleMesh& iRenderObject)
  	{
	simpleMeshRenderInstanceManager->AddRenderObject(iRenderObject);
	}

//*****************************************************************************