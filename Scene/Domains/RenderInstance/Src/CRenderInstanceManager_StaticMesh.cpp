/*
    CRenderInstanceManager_StaticMesh.cpp - Contains class CRenderInstanceManager_StaticMesh implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#include <CRenderInstanceManager_StaticMesh.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Constructor.
 */
CRenderInstanceManager_StaticMesh::CRenderInstanceManager_StaticMesh(LPDIRECT3DDEVICE9 iDevice)
	{
	if(iDevice == NULL)
		throw CException_NullPointer("CRenderInstanceManager_StaticMesh::CRenderInstanceManager_StaticMesh(LPDIRECT3DDEVICE9 iDevice)", "iDevice");

	device = iDevice;
	device->AddRef();
	}

//*****************************************************************************

/**
 * Destructor.
 */
CRenderInstanceManager_StaticMesh::~CRenderInstanceManager_StaticMesh()
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

/**
 * Returns dynamic render instance.
 */
CRenderInstance_StaticMesh* CRenderInstanceManager_StaticMesh::GetRenderInstance_Dynamic(CRenderObject_StaticMesh* iRenderObject)
	{
	const unsigned instanceSize(dynamicInstance.size());

	for(unsigned i=0; i<instanceSize; i++)
		{
		if(dynamicInstance[i]->CanBeInserted(iRenderObject) == true)
			{
			return dynamicInstance[i];
			}
		}
	CRenderInstance_StaticMesh* instance = new CRenderInstance_StaticMesh(device, iRenderObject->GetMaterial()->GetMaterialType(), iRenderObject->GetMesh(), iRenderObject->GetMaterial()->GetInstanceVertexElement(), iRenderObject->GetMaterial()->GetInstanceDataSize(), iRenderObject->GetMaterial()->GetEffectFilename());
	dynamicInstance.push_back(instance);

	return  instance;
	}

//*****************************************************************************

/**
 * Returns static render instance.
 */
CRenderInstance_StaticMesh* CRenderInstanceManager_StaticMesh::GetRenderInstance_Static(CRenderObject_StaticMesh* iRenderObject)
	{
	const unsigned instanceSize(staticInstance.size());

	for(unsigned i=0; i<instanceSize; i++)
		{
		if(staticInstance[i]->CanBeInserted(iRenderObject) == true)
			{
			return staticInstance[i];
			}
		}
	CRenderInstance_StaticMesh* instance = new CRenderInstance_StaticMesh(device, iRenderObject->GetMaterial()->GetMaterialType(), iRenderObject->GetMesh(), iRenderObject->GetMaterial()->GetInstanceVertexElement(), iRenderObject->GetMaterial()->GetInstanceDataSize(), iRenderObject->GetMaterial()->GetEffectFilename());
	staticInstance.push_back(instance);

	return  instance;
	}

//*****************************************************************************

/**
 * Renders all instances.
 */
void CRenderInstanceManager_StaticMesh::Render()
	{
	const unsigned staticInstanceSize(staticInstance.size());
	const unsigned dynamicInstanceSize(dynamicInstance.size());

	for(unsigned i=0; i<staticInstanceSize; i++)
		staticInstance[i]->Render();
		
	for(unsigned i=0; i<dynamicInstanceSize; i++)
		dynamicInstance[i]->Render();
	}

//*****************************************************************************

/**
 * Ensures a proper lost device behavior.
 */
void CRenderInstanceManager_StaticMesh::OnLostDevice()
	{
	const unsigned staticInstanceSize(staticInstance.size());
	const unsigned dynamicInstanceSize(dynamicInstance.size());

	for(unsigned i=0; i<staticInstanceSize; i++)
		staticInstance[i]->OnLostDevice();
		
	for(unsigned i=0; i<dynamicInstanceSize; i++)
		dynamicInstance[i]->OnLostDevice();
	}

//*****************************************************************************

/**
 * Ensures a proper reset device behavior.
 */
void CRenderInstanceManager_StaticMesh::OnResetDevice()
	{
	const unsigned staticInstanceSize(staticInstance.size());
	const unsigned dynamicInstanceSize(dynamicInstance.size());

	for(unsigned i=0; i<staticInstanceSize; i++)
		staticInstance[i]->OnResetDevice();
		
	for(unsigned i=0; i<dynamicInstanceSize; i++)
		dynamicInstance[i]->OnResetDevice();
	}

//*****************************************************************************

/**
 * Clears all render objects.
 */
void CRenderInstanceManager_StaticMesh::Clear()
	{
	ClearStatic();
	ClearDynamic();
	}

//*****************************************************************************

/**
 * Clears static render objects.
 */
void CRenderInstanceManager_StaticMesh::ClearStatic()
	{
	const unsigned instanceSize(staticInstance.size());

	for(unsigned i=0; i<instanceSize; i++)
		staticInstance[i]->Clear();
	}

//*****************************************************************************

/**
 * Clears dynamic render objects.
 */
void CRenderInstanceManager_StaticMesh::ClearDynamic()
	{
	const unsigned instanceSize(dynamicInstance.size());

	for(unsigned i=0; i<instanceSize; i++)
		dynamicInstance[i]->Clear();
	}

//*****************************************************************************

/**
 * Adds render object.
 */
void CRenderInstanceManager_StaticMesh::AddRenderObject(CRenderObject_StaticMesh* iRenderObject)
	{
	if(iRenderObject->IsStatic() == true)
		{
		CRenderInstance_StaticMesh* instance = GetRenderInstance_Static(iRenderObject);
		assert(instance!=NULL && L"CRenderInstanceManager_StaticMesh::AddRenderObject - instance!=NULL");
		instance->AddRenderObject(iRenderObject);
		}
	else
		{
		CRenderInstance_StaticMesh* instance = GetRenderInstance_Dynamic(iRenderObject);
		assert(instance!=NULL && L"CRenderInstanceManager_StaticMesh::AddRenderObject - instance!=NULL");
		instance->AddRenderObject(iRenderObject);
		}
	}

//*****************************************************************************