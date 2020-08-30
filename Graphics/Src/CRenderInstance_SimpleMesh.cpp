///////////////////////////////////////////////////////////
//  CRenderInstance_SimpleMesh.cpp
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CRenderInstance_SimpleMesh.h>
using namespace Regina;


//*****************************************************************************

CRenderInstance_SimpleMesh::~CRenderInstance_SimpleMesh()
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

	instanceVertexElement = NULL;

	if(instanceVertexDeclaration!=NULL)
		instanceVertexDeclaration->Release();
	instanceVertexDeclaration = NULL;

	if(effect!=NULL)
		effect->Release();
	effect=NULL;
	}

//*****************************************************************************

CRenderInstance_SimpleMesh::CRenderInstance_SimpleMesh(LPDIRECT3DDEVICE9 iDevice, const eMatterialType& iMatterialType, const eRenderInstanceType&	iRenderInstanceType, const string& iEffectName, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const unsigned& iInstanceDataSize) : CRenderInstance(iDevice, iMatterialType, iRenderInstanceType), mesh(NULL), instanceVertexElement(NULL), instanceVertexDeclaration(NULL), instanceVertexBuffer(NULL), meshVertexBuffer(NULL), meshIndexBuffer(NULL), effect(NULL), instanceDataSize(iInstanceDataSize), lastInstanceVertexBufferSize(0)
  	{
	if(iMesh == NULL)
		throw invalid_argument("CRenderInstance_SimpleMesh::CRenderInstance_SimpleMesh - argument iMesh==NULL");

	if(iInstanceVertexElement == NULL)
		throw invalid_argument("CRenderInstance_SimpleMesh::CRenderInstance_SimpleMesh - argument iVertexElement==NULL");

	HRESULT hr;
	string effectFileName = string("Data\\FX\\") + iEffectName + string(".fx");
	hr = D3DXCreateEffectFromFileA( device, effectFileName.c_str(), NULL, NULL, D3DXSHADER_NO_PRESHADER | D3DXFX_DONOTSAVESTATE | D3DXFX_DONOTSAVESAMPLERSTATE, NULL, &effect, NULL);

	if(FAILED(hr))
			{
			if(effect!=NULL)
				effect->Release();
			effect=NULL;

			ifstream tmpFile(effectFileName.c_str());
			if(tmpFile.is_open()==false)
				{
				tmpFile.close();
				throw invalid_argument("CRenderInstance_SimpleMesh::CRenderInstance_SimpleMesh - specified FX file does not exist ( D3DXCreateEffectFromFile returns D3DERR_INVALIDCALL )");
				}
			else
				throw exception("CRenderInstance_SimpleMesh::CRenderInstance_SimpleMesh - D3DXCreateEffectFromFile");
			}

	instanceVertexElement = iInstanceVertexElement;
	mesh = iMesh;
	mesh->AddRef();

	hr = device->CreateVertexDeclaration(instanceVertexElement, &instanceVertexDeclaration);

	if(FAILED(hr))
			{
			if(mesh!=NULL)
				mesh->Release();
			mesh = NULL;

			if(instanceVertexDeclaration!=NULL)
				instanceVertexDeclaration->Release();
			instanceVertexDeclaration = NULL;

			assert(hr != D3DERR_INVALIDCALL && L"CreateVertexDeclaration D3DERR_INVALIDCALL");
			throw exception("CRenderInstance_SimpleMesh::CRenderInstance_SimpleMesh - CreateVertexDeclaration");
			}

	mesh->GetVertexBuffer(&meshVertexBuffer);
	mesh->GetIndexBuffer(&meshIndexBuffer);
	}


//*****************************************************************************

unsigned CRenderInstance_SimpleMesh::RenderListSize() const 
  	{
	return  renderList.size();
	}

//*****************************************************************************

void CRenderInstance_SimpleMesh::Clear()
  	{
	renderList.clear();
	SetMatterialID(0);
	SetModified(true);
	}

//*****************************************************************************

void CRenderInstance_SimpleMesh::Render(const eRenderType& iRenderType, const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition)
	{
	renderType=iRenderType;
	cameraView = iCameraView;
	cameraProj = iCameraProj;
	cameraPosition = iCameraPosition;


	if(RenderListSize() > 0)
		{
		SetEffectParams(effect, renderList);

		if(Modified() == true)
			{
			RecreateInstanceBuffer(RenderListSize());
			FillInstanceVB(instanceVertexBuffer, renderList);
			UpdateInstancePosition();
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

void CRenderInstance_SimpleMesh::AddRenderObject(CRenderObject_SimpleMesh& iRenderObject)
	{
	assert(CanBeInserted(iRenderObject) == true && L"CRenderInstance_SimpleMesh::AddRenderObject - CanBeInserted(iRenderObject) == true");
	renderList.push_back(iRenderObject);
	SetModified(true);
	}

//*****************************************************************************

void CRenderInstance_SimpleMesh::OnLostDevice()
	{
	effect->OnLostDevice();
	}

//*****************************************************************************

void CRenderInstance_SimpleMesh::OnResetDevice()
	{
	effect->OnResetDevice();
	}

//*****************************************************************************

bool CRenderInstance_SimpleMesh::CanBeInserted(CRenderObject_SimpleMesh& iRenderObject)
	{
	if(iRenderObject.MatterialType() == MatterialType() && iRenderObject.RenderInstanceType() == RenderInstanceType() && iRenderObject.Mesh() == mesh)
		{
		if(RenderListSize() == 0)
			return true;
		else
			return (iRenderObject.MatterialID() == MatterialID());
		}
	else
		return false;
	}

//*****************************************************************************

void CRenderInstance_SimpleMesh::RecreateInstanceBuffer(const unsigned& iNewSize)
	{
	if(iNewSize>lastInstanceVertexBufferSize)
		{
		if(instanceVertexBuffer!=NULL)
			instanceVertexBuffer->Release();

		device->CreateVertexBuffer(iNewSize * instanceDataSize, D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &instanceVertexBuffer, NULL);

		lastInstanceVertexBufferSize = iNewSize;
		}	
	}

//*****************************************************************************

void CRenderInstance_SimpleMesh::UpdateInstancePosition()
	{
	//Find average position
	instanceCenter = D3DXVECTOR3(0, 0, 0);

	for(unsigned i=0; i<renderList.size(); i++)
		instanceCenter += renderList[i].Position();

	if(renderList.size()!=0)
		instanceCenter/=renderList.size();

	//Find sq radius
	float sqRadius = 0;

	for(unsigned i=0; i<renderList.size(); i++)
		{
		float curSqRadius = Distance_Sq(instanceCenter, renderList[i].Position());
		if(curSqRadius > sqRadius)
			sqRadius = curSqRadius;
		}

	instanceRadius = sqrt(sqRadius);
	}

//*****************************************************************************