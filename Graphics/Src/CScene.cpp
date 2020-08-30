///////////////////////////////////////////////////////////
//  CScene.cpp
//  Created on:      27-11-2009
//  Last modified:   27-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CScene.h>
using namespace Regina;


//*****************************************************************************

CScene::~CScene()
	{
	if(renderObject_Manager_NonTransparent!=NULL)
		delete renderObject_Manager_NonTransparent;
	renderObject_Manager_NonTransparent = NULL;

	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

CScene::CScene(LPDIRECT3DDEVICE9 iDevice) : device(NULL), renderObject_Manager_NonTransparent(NULL)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CScene::CScene - argument iDevice==NULL");

	device = iDevice;
	device->AddRef();

	renderObject_Manager_NonTransparent = new CNonTransparent_RenderObject_Manager(iDevice);
	assert(renderObject_Manager_NonTransparent!=NULL && L"CScene::CScene - cannot create new CNonTransparent_RenderObject_Manager");
	}

//*****************************************************************************

void CScene::Render(const eRenderType& iRenderType, const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition)
  	{
	renderObject_Manager_NonTransparent->Render(iRenderType, iCameraView, iCameraProj, iCameraPosition);
	}

//*****************************************************************************

void CScene::Clear()
  	{
	renderObject_Manager_NonTransparent->Clear();
	}

//*****************************************************************************

void CScene::ClearStatic()
  	{
	renderObject_Manager_NonTransparent->ClearStatic();
	}

//*****************************************************************************

void CScene::ClearDynamic()
  	{
	renderObject_Manager_NonTransparent->ClearDynamic();
	}

//*****************************************************************************

void CScene::OnLostDevice()
  	{
	renderObject_Manager_NonTransparent->OnLostDevice();
	}

//*****************************************************************************

void CScene::OnResetDevice()
  	{
	renderObject_Manager_NonTransparent->OnResetDevice();
	}

//*****************************************************************************

void CScene::AddRenderObject(CRenderObject_SimpleMesh& iRenderObject)
  	{
	//if(iRenderObject.TransparencyEnabled()==false)
		renderObject_Manager_NonTransparent->AddRenderObject(iRenderObject);
	}

//*****************************************************************************