/*
    CRenderInstance_StaticMesh.cpp - Contains class CRenderInstance_StaticMesh implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#include <CRenderInstance_StaticMesh.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Constructor.
 */
CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const unsigned& iInstanceDataSize, const wstring& iEffectFilename) : CRenderInstance(iDevice, iMaterialType), effect(NULL), instanceVertexBuffer(NULL), instanceVertexDeclaration(NULL), meshVertexBuffer(NULL), meshIndexBuffer(NULL), lastInstanceVertexBufferSize(0), instanceDataSize(iInstanceDataSize), mesh(NULL)
	{
	HRESULT hr;

	if(iMesh == NULL)
		throw CException_NullPointer("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iMesh");

	if(iInstanceVertexElement == NULL)
		throw CException_NullPointer("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iInstanceVertexElement");

	try
		{
		//Create effect
		hr = D3DXCreateEffectFromFile( device, iEffectFilename.c_str(), NULL, NULL, D3DXSHADER_NO_PRESHADER | D3DXFX_DONOTSAVESTATE | D3DXFX_DONOTSAVESAMPLERSTATE, NULL, &effect, NULL);

		if(FAILED(hr))
			{
			if(hr == D3DERR_INVALIDCALL)
				throw CException_InvalidArgument("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iEffectFilename", "Function 'D3DXCreateEffectFromFile' returns 'D3DERR_INVALIDCALL'");

			if(hr == D3DXERR_INVALIDDATA)
				throw CException_InvalidArgument("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iEffectFilename", "Function 'D3DXCreateEffectFromFile' returns 'D3DERR_INVALIDCALL'");

			if(hr == E_OUTOFMEMORY)
				throw CException_OutOfMemory("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "D3DXCreateEffectFromFile", "Function 'D3DXCreateEffectFromFile' returns 'E_OUTOFMEMORY'");

			throw CException_InvalidArgument("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iEffectFilename", "Function 'D3DXCreateEffectFromFile' returns unknown error.");
			}

		//Assign vertex element
		instanceVertexElement = iInstanceVertexElement;

		//Assign mesh
		mesh = iMesh;
		mesh->AddRef();

		//Create instance vertex declaration
		hr = device->CreateVertexDeclaration(instanceVertexElement, &instanceVertexDeclaration);

		if(FAILED(hr))
			{
			if(hr == D3DERR_INVALIDCALL)
				throw CException_InvalidArgument("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iInstanceVertexElement", "Function 'CreateVertexDeclaration' returns 'D3DERR_INVALIDCALL'");

			throw CException_InvalidArgument("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iInstanceVertexElement", "Function 'CreateVertexDeclaration' returns unknown error.");
			}

		//Retrieve mesh vertex buffer
		hr = mesh->GetVertexBuffer(&meshVertexBuffer);

		if(FAILED(hr))
			{
			if(hr == D3DERR_INVALIDCALL)
				throw CException_InvalidArgument("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iMesh", "Function 'GetVertexBuffer' returns 'D3DERR_INVALIDCALL'");

			throw CException_InvalidArgument("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iMesh", "Function 'GetVertexBuffer' returns unknown error.");
			}

		//Retrieve mesh index buffer
		mesh->GetIndexBuffer(&meshIndexBuffer);

		if(FAILED(hr))
			{
			if(hr == D3DERR_INVALIDCALL)
				throw CException_InvalidArgument("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iMesh", "Function 'GetIndexBuffer' returns 'D3DERR_INVALIDCALL'");

			throw CException_InvalidArgument("CRenderInstance_StaticMesh::CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const wstring& iEffectFilename)", "iMesh", "Function 'GetIndexBuffer' returns unknown error.");
			}
		}
	catch(...)
		{
		if(instanceVertexBuffer!=NULL)
			instanceVertexBuffer->Release();
		instanceVertexBuffer = NULL;

		if(meshVertexBuffer!=NULL)
			meshVertexBuffer->Release();
		meshVertexBuffer = NULL;
	
		if(meshIndexBuffer!=NULL)
			meshIndexBuffer->Release();
		meshIndexBuffer = NULL;

		if(mesh!=NULL)
			mesh->Release();
		mesh = NULL;

		if(instanceVertexDeclaration!=NULL)
			instanceVertexDeclaration->Release();
		instanceVertexDeclaration = NULL;

		if(effect!=NULL)
			effect->Release();
		effect=NULL;

		throw;
		}
	}

//*****************************************************************************

/**
 * Destructor.
 */
CRenderInstance_StaticMesh::~CRenderInstance_StaticMesh()
	{
	Clear();

	if(instanceVertexBuffer!=NULL)
		instanceVertexBuffer->Release();
	instanceVertexBuffer = NULL;

	if(meshVertexBuffer!=NULL)
		meshVertexBuffer->Release();
	meshVertexBuffer = NULL;
	
	if(meshIndexBuffer!=NULL)
		meshIndexBuffer->Release();
	meshIndexBuffer = NULL;

	if(mesh!=NULL)
		mesh->Release();
	mesh = NULL;

	if(instanceVertexDeclaration!=NULL)
		instanceVertexDeclaration->Release();
	instanceVertexDeclaration = NULL;

	if(effect!=NULL)
		effect->Release();
	effect=NULL;
	}

//*****************************************************************************

/**
 * Expands buffer if current size is smaller than new size.
 */
void CRenderInstance_StaticMesh::RecreateInstanceBuffer(const unsigned& iNewSize)
	{
	if(iNewSize > lastInstanceVertexBufferSize && instanceDataSize > 0)
		{
		if(instanceVertexBuffer != NULL)
			instanceVertexBuffer->Release();

		device->CreateVertexBuffer(iNewSize * instanceDataSize, D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &instanceVertexBuffer, NULL);

		lastInstanceVertexBufferSize = iNewSize;
		}	
	}

//*****************************************************************************

/**
 * Fills instance VB.
 */
void CRenderInstance_StaticMesh::FillInstanceVB()
	{
	if(instanceDataSize > 0)
		{
		D3DXVECTOR4* pVertices;
		instanceVertexBuffer->Lock(0, 0, (VOID**)&pVertices, 0);
	
		const unsigned renderListSize(RenderListSize());
		unsigned curPos(0);

		for(unsigned i=0; i<renderListSize; i++)
			renderList[i]->GetMaterial()->FillInstanceVB(pVertices, curPos);

		instanceVertexBuffer->Unlock();
		}
	}

//*****************************************************************************

/**
 * Returns render list size.
 */
unsigned CRenderInstance_StaticMesh::RenderListSize() const 
	{
	return renderList.size();
	}

//*****************************************************************************

/**
 * Clear render list.
 */
void CRenderInstance_StaticMesh::Clear()
	{
	renderList.clear();
	SetMaterialID(0);
	SetModified(true);
	}

//*****************************************************************************

/**
 * Renders instance.
 */
void CRenderInstance_StaticMesh::Render()
	{
	if(RenderListSize() > 0)
		{
		renderList[0]->GetMaterial()->SetEffectParameters(effect);

		if(IsModified() == true)
			{
			RecreateInstanceBuffer(RenderListSize());
			FillInstanceVB();
			SetModified(false);
			}

		device->SetVertexDeclaration(instanceVertexDeclaration);
		device->SetStreamSourceFreq(0, (D3DSTREAMSOURCE_INDEXEDDATA | RenderListSize()));
		device->SetStreamSourceFreq(1, (D3DSTREAMSOURCE_INSTANCEDATA | 1));

		device->SetIndices(meshIndexBuffer);
		device->SetStreamSource(0, meshVertexBuffer, 0, D3DXGetDeclVertexSize(instanceVertexElement, 0));
		device->SetStreamSource(1, instanceVertexBuffer, 0, D3DXGetDeclVertexSize(instanceVertexElement, 1));

		UINT passes;
		effect->Begin(&passes, 0);
		for(UINT pass = 0; pass < passes; ++ pass )
			{
			effect->BeginPass(pass);
			device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, mesh->GetNumVertices(),0, mesh->GetNumFaces());
			effect->EndPass();
			}
		effect->End();

		device->SetStreamSourceFreq(0, 1);
		device->SetStreamSourceFreq(1, 1);
		}
	}

//*****************************************************************************

/**
 * Add render object to render list.
 */
void CRenderInstance_StaticMesh::AddRenderObject(CRenderObject_StaticMesh* iRenderObject)
	{
	assert(CanBeInserted(iRenderObject) == true && L"void CRenderInstance_StaticMesh::AddRenderObject(CRenderObject_StaticMesh* iRenderObject) - CanBeInserted(iRenderObject) == true");

	if(RenderListSize() == 0)
		SetMaterialID(iRenderObject->GetMaterial()->GetMaterialID());

	renderList.push_back(iRenderObject);
	SetModified(true);
	}

//*****************************************************************************

/**
 * Returns true if render object can be inserted into render instance, otherwise
 * returns false.
 */
bool CRenderInstance_StaticMesh::CanBeInserted(CRenderObject_StaticMesh* iRenderObject)
	{
	if(iRenderObject->GetMaterial()->GetMaterialType() == GetMaterialType() && iRenderObject->GetMesh() == mesh)
		{
		if(RenderListSize() == 0)
			return true;
		else
			return (iRenderObject->GetMaterial()->GetMaterialID() == GetMaterialID());
		}
	else
		return false;
	}

//*****************************************************************************

/**
 * Performs all actions to ensure proper lost device state.
 */
void CRenderInstance_StaticMesh::OnLostDevice()
	{
	effect->OnLostDevice();
	}

//*****************************************************************************

/**
 * Performs all actions to ensure proper reset device state.
 */
void CRenderInstance_StaticMesh::OnResetDevice()
	{
	effect->OnResetDevice();
	}

//*****************************************************************************