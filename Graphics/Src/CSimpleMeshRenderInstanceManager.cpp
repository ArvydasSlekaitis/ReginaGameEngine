///////////////////////////////////////////////////////////
//  CSimpleMeshRenderInstanceManager.cpp
//  Created on:      20-11-2009
//  Last modified:   20-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CSimpleMeshRenderInstanceManager.h>
using namespace Regina;


//*****************************************************************************

CSimpleMeshRenderInstanceManager::~CSimpleMeshRenderInstanceManager()
	{
	Clear();

	if(device!=NULL)
		device->Release();
	device = NULL;

	for(unsigned i=0; i<dynamicInstance.size(); i++)
		delete dynamicInstance[i];

	for(unsigned i=0; i<staticInstance.size(); i++)
		delete staticInstance[i];

	dynamicInstance.clear();
	staticInstance.clear();
	}

//*****************************************************************************

CSimpleMeshRenderInstanceManager::CSimpleMeshRenderInstanceManager(LPDIRECT3DDEVICE9 iDevice) : device(NULL)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CSimpleMeshRenderInstanceManager::CSimpleMeshRenderInstanceManager - argument iDevice==NULL");

	device = iDevice;
	device->AddRef();
	}

//*****************************************************************************

void CSimpleMeshRenderInstanceManager::Clear()
  	{
	ClearStatic();
	ClearDynamic();
	}

//*****************************************************************************

void CSimpleMeshRenderInstanceManager::ClearStatic()
  	{
	for(unsigned i=0; i<staticInstance.size(); i++)
		staticInstance[i]->Clear();
	}

//*****************************************************************************

void CSimpleMeshRenderInstanceManager::ClearDynamic()
  	{
	for(unsigned i=0; i<dynamicInstance.size(); i++)
		dynamicInstance[i]->Clear();
	}

//*****************************************************************************

void CSimpleMeshRenderInstanceManager::AddRenderObject(CRenderObject_SimpleMesh& iRenderObject)
  	{
	switch(iRenderObject.Type())
		{
		case iRenderObject.type_Dynamic:	AddDynamic(iRenderObject);
											break;

		case iRenderObject.type_Static:		AddStatic(iRenderObject);
											break;
		}
	}

//*****************************************************************************

void CSimpleMeshRenderInstanceManager::AddDynamic(CRenderObject_SimpleMesh& iRenderObject)
  	{
	CRenderInstance_SimpleMesh* instance = GetInstance_Dynamic(iRenderObject);
	assert(instance!=NULL && L"CSimpleMeshRenderInstanceManager::AddDynamic - instance!=NULL");
	instance->AddRenderObject(iRenderObject);
	}

//*****************************************************************************

void CSimpleMeshRenderInstanceManager::AddStatic(CRenderObject_SimpleMesh& iRenderObject)
  	{
	CRenderInstance_SimpleMesh* instance = GetInstance_Static(iRenderObject);
	assert(instance!=NULL && L"CSimpleMeshRenderInstanceManager::AddStatic - instance!=NULL");
	instance->AddRenderObject(iRenderObject);
	}

//*****************************************************************************

CRenderInstance_SimpleMesh* CSimpleMeshRenderInstanceManager::GetInstance_Dynamic(CRenderObject_SimpleMesh& iRenderObject)
  	{
	for(unsigned i=0; i<dynamicInstance.size(); i++)
		if(dynamicInstance[i]->CanBeInserted(iRenderObject) == true)
			return dynamicInstance[i];

	CRenderInstance_SimpleMesh* instance = RenderInstanceCreator->CreateInstance_SimpleMesh(iRenderObject.RenderInstanceType(), device, iRenderObject.Mesh());
	assert(instance!=NULL && L"CSimpleMeshRenderInstanceManager::GetInstance_Dynamic - instance!=NULL");
	dynamicInstance.push_back(instance);

	return  instance;
	}

//*****************************************************************************

CRenderInstance_SimpleMesh* CSimpleMeshRenderInstanceManager::GetInstance_Static(CRenderObject_SimpleMesh& iRenderObject)
  	{
	for(unsigned i=0; i<staticInstance.size(); i++)
		if(staticInstance[i]->CanBeInserted(iRenderObject) == true)
			return staticInstance[i];

	CRenderInstance_SimpleMesh* instance = RenderInstanceCreator->CreateInstance_SimpleMesh(iRenderObject.RenderInstanceType(), device, iRenderObject.Mesh());
	assert(instance!=NULL && L"CSimpleMeshRenderInstanceManager::GetInstance_Static - instance!=NULL");
	staticInstance.push_back(instance);

	return  instance;
	}

//*****************************************************************************

void CSimpleMeshRenderInstanceManager::Render(const eRenderType& iRenderType, const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition)
	{
	for(unsigned i=0; i<staticInstance.size(); i++)
		staticInstance[i]->Render(iRenderType, iCameraView, iCameraProj, iCameraPosition);

	for(unsigned i=0; i<dynamicInstance.size(); i++)
		dynamicInstance[i]->Render(iRenderType, iCameraView, iCameraProj, iCameraPosition);
	}

//*****************************************************************************

void CSimpleMeshRenderInstanceManager::OnLostDevice()
	{
	for(unsigned i=0; i<dynamicInstance.size(); i++)
		dynamicInstance[i]->OnLostDevice();

	for(unsigned i=0; i<staticInstance.size(); i++)
		staticInstance[i]->OnLostDevice();
	}

//*****************************************************************************

void CSimpleMeshRenderInstanceManager::OnResetDevice()
	{
	for(unsigned i=0; i<dynamicInstance.size(); i++)
		dynamicInstance[i]->OnResetDevice();

	for(unsigned i=0; i<staticInstance.size(); i++)
		staticInstance[i]->OnResetDevice();
	}

//*****************************************************************************