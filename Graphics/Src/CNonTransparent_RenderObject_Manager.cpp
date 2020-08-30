///////////////////////////////////////////////////////////
//  CNonTransparent_RenderObject_Manager.cpp
//  Created on:      27-11-2009
//  Last modified:   27-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CNonTransparent_RenderObject_Manager.h>
using namespace Regina;


//*****************************************************************************

CNonTransparent_RenderObject_Manager::~CNonTransparent_RenderObject_Manager()
	{
	if(instanceManager!=NULL)
		delete instanceManager;
	instanceManager = NULL;

	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

CNonTransparent_RenderObject_Manager::CNonTransparent_RenderObject_Manager(LPDIRECT3DDEVICE9 iDevice) : device(NULL), instanceManager(NULL)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CNonTransparent_RenderObject_Manager::CNonTransparent_RenderObject_Manager - argument iDevice==NULL");

	device = iDevice;
	device->AddRef();

	instanceManager = new CRenderInstanceManager(iDevice);
	assert(instanceManager!=NULL && L"CNonTransparent_RenderObject_Manager::CNonTransparent_RenderObject_Manager - cannot create new CInstanceManager");
	}

//*****************************************************************************

void CNonTransparent_RenderObject_Manager::Render(const eRenderType& iRenderType, const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition)
  	{
	instanceManager->Render(iRenderType, iCameraView, iCameraProj, iCameraPosition);
	}

//*****************************************************************************

void CNonTransparent_RenderObject_Manager::Clear()
  	{
	instanceManager->Clear();
	}

//*****************************************************************************

void CNonTransparent_RenderObject_Manager::ClearStatic()
  	{
	instanceManager->ClearStatic();
	}

//*****************************************************************************

void CNonTransparent_RenderObject_Manager::ClearDynamic()
  	{
	instanceManager->ClearDynamic();
	}

//*****************************************************************************

void CNonTransparent_RenderObject_Manager::OnLostDevice()
  	{
	instanceManager->OnLostDevice();
	}

//*****************************************************************************

void CNonTransparent_RenderObject_Manager::OnResetDevice()
  	{
	instanceManager->OnResetDevice();
	}

//*****************************************************************************

void CNonTransparent_RenderObject_Manager::AddRenderObject(CRenderObject_SimpleMesh& iRenderObject)
  	{
	instanceManager->AddRenderObject(iRenderObject);
	}

//*****************************************************************************