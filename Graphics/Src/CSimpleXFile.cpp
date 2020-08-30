///////////////////////////////////////////////////////////
//  CSimpleXFile.cpp
//  Created on:      01-11-2009
//  Last modified:   05-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CSimpleXFile.h>
using namespace Regina;


//*****************************************************************************

CSimpleXFile::~CSimpleXFile()
	{
	if(mesh != NULL)
		mesh->Release();

	if(vertexDeclaration)
		vertexDeclaration->Release();
	}

//*****************************************************************************

CSimpleXFile::CSimpleXFile(LPDIRECT3DDEVICE9 iDevice, const string& iName) : name(iName), mesh(NULL), vertexDeclaration(NULL) 
  	{
	//Constructor
	if(iDevice == NULL)
		throw invalid_argument("CSimpleXFile::CSimpleXFile - argument iDevice==NULL");

	if(iName.size() == 0)
		throw invalid_argument("CSimpleXFile::CSimpleXFile - argument iName==''");


	LPD3DXBUFFER adjacencyBuffer(NULL);

	string fileName = string("Data\\X\\") + iName + ".x";

	HRESULT hr = D3DXLoadMeshFromXA(fileName.c_str(), D3DXMESH_SYSTEMMEM, iDevice, &adjacencyBuffer, NULL, NULL, NULL, &mesh);

	if(FAILED(hr))
		{
		if(mesh!=NULL)
			mesh->Release();
		mesh = NULL;

		if(adjacencyBuffer!=NULL)
			adjacencyBuffer->Release();
		adjacencyBuffer = NULL;

		ifstream tmpFile(fileName.c_str());
		if(tmpFile.is_open()==false)
			{
			tmpFile.close();
			throw invalid_argument("CSimpleXFile::CSimpleXFile - specified x file does not exist ( D3DXLoadMeshFromX returns D3DERR_INVALIDCALL )");
			}

		
		if(hr == D3DERR_INVALIDCALL)
			throw invalid_argument("CSimpleXFile::CSimpleXFile - one of the arguments is invalid ( D3DXLoadMeshFromX returns D3DERR_INVALIDCALL )");

		if(hr == E_OUTOFMEMORY)
			throw Exception_OutOfMemmory("CSimpleXFile::CSimpleXFile - there is not enough free memmory for mesh creating ( D3DXLoadMeshFromX returns E_OUTOFMEMORY )");
		}
	else
		{
		LPD3DXMESH tmpMesh = NULL;
		LPD3DXBUFFER newAdjacencyBuffer(NULL);

		//Optimize mesh
		hr = mesh->OptimizeInplace(D3DXMESHOPT_COMPACT | D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_VERTEXCACHE, (DWORD*)adjacencyBuffer->GetBufferPointer(), (DWORD*)newAdjacencyBuffer, NULL, NULL);

		//Release adjacency buffer
		if(adjacencyBuffer!=NULL)
			adjacencyBuffer->Release();
		adjacencyBuffer = NULL;
	
		if(FAILED(hr))
			{
			if(mesh!=NULL)
				mesh->Release();
			mesh = NULL;

			if(newAdjacencyBuffer!=NULL)
				newAdjacencyBuffer->Release();
			newAdjacencyBuffer = NULL;

			assert(hr != D3DERR_INVALIDCALL && L"mesh->OptimizeInplace D3DERR_INVALIDCALL");
			if(hr == E_OUTOFMEMORY)
				throw Exception_OutOfMemmory("CSimpleXFile::CSimpleXFile - there is not enough free memmory for mesh optimizing ( mesh->OptimizeInplace returns E_OUTOFMEMORY )");
			else
				throw exception("CSimpleXFile::CSimpleXFile - OptimizeInplace");
			}


		//Clone mesh using new VE
		hr = mesh->CloneMesh(D3DXMESH_MANAGED, vertexElement, iDevice, &tmpMesh);
		
		if(FAILED(hr))
			{
			if(mesh!=NULL)
				mesh->Release();
			mesh = NULL;

			if(tmpMesh!=NULL)
				tmpMesh->Release();
			tmpMesh = NULL;

			if(newAdjacencyBuffer!=NULL)
				newAdjacencyBuffer->Release();
			newAdjacencyBuffer = NULL;

			assert(hr != D3DERR_INVALIDCALL && L"mesh->CloneMesh D3DERR_INVALIDCALL");
			if(hr == E_OUTOFMEMORY)
				throw Exception_OutOfMemmory("CSimpleXFile::CSimpleXFile - there is not enough free memmory for mesh cloning ( mesh->CloneMesh returns E_OUTOFMEMORY )");
			else
				throw exception("CSimpleXFile::CSimpleXFile - CloneMesh");
			}


		//Compute tangents and normals
		hr = D3DXComputeNormals(tmpMesh, (DWORD*)newAdjacencyBuffer);

		if(FAILED(hr))
			{
			if(mesh!=NULL)
				mesh->Release();
			mesh = NULL;

			if(tmpMesh!=NULL)
				tmpMesh->Release();
			tmpMesh = NULL;

			if(newAdjacencyBuffer!=NULL)
				newAdjacencyBuffer->Release();
			newAdjacencyBuffer = NULL;

			assert(hr != D3DERR_INVALIDCALL && L"D3DXComputeNormals D3DERR_INVALIDCALL");
			
			if(hr == E_OUTOFMEMORY)
				throw Exception_OutOfMemmory("CSimpleXFile::CSimpleXFile - there is not enough free memmory for normals computing ( D3DXComputeNormals returns E_OUTOFMEMORY )");
			else
				throw exception("CSimpleXFile::CSimpleXFile - D3DXComputeNormals");
			}

		hr = D3DXComputeTangent(tmpMesh, 0, 0, 0, 1, (DWORD*)newAdjacencyBuffer);

		if(FAILED(hr))
			{
			if(mesh!=NULL)
				mesh->Release();
			mesh = NULL;

			if(tmpMesh!=NULL)
				tmpMesh->Release();
			tmpMesh = NULL;

			if(newAdjacencyBuffer!=NULL)
				newAdjacencyBuffer->Release();
			newAdjacencyBuffer = NULL;

			assert(hr != D3DERR_INVALIDCALL && L"D3DXComputeTangent D3DERR_INVALIDCALL");
			
			if(hr == E_OUTOFMEMORY)
				throw Exception_OutOfMemmory("CSimpleXFile::CSimpleXFile - there is not enough free memmory for tangents computing ( D3DXComputeTangent returns E_OUTOFMEMORY )");
			else
				throw exception("CSimpleXFile::CSimpleXFile - D3DXComputeTangent");
			}

		//Release a new adjacency buffer
		if(newAdjacencyBuffer!=NULL)
			newAdjacencyBuffer->Release();
		newAdjacencyBuffer = NULL;

		//Create vertex declaration
		hr = iDevice->CreateVertexDeclaration( vertexElement, &vertexDeclaration );

		if(FAILED(hr))
			{
			if(mesh!=NULL)
				mesh->Release();
			mesh = NULL;

			if(tmpMesh!=NULL)
				tmpMesh->Release();
			tmpMesh = NULL;

			if(vertexDeclaration!=NULL)
				vertexDeclaration->Release();
			vertexDeclaration = NULL;

			assert(hr != D3DERR_INVALIDCALL && L"CreateVertexDeclaration D3DERR_INVALIDCALL");
			throw exception("CSimpleXFile::CSimpleXFile - CreateVertexDeclaration");
			}

		mesh->Release();
		mesh = tmpMesh;
		
		tmpMesh=NULL;
		}


	}

//*****************************************************************************

LPD3DXMESH CSimpleXFile::Mesh()
  	{
	return mesh;
	}

//*****************************************************************************

string CSimpleXFile::Name() const 
  	{
	return name;
	}

//*****************************************************************************

LPDIRECT3DVERTEXDECLARATION9 CSimpleXFile::VertexDeclaration()
  	{
	return vertexDeclaration;
	}

//*****************************************************************************

const D3DVERTEXELEMENT9* CSimpleXFile::vertexElement = Regina::VE_POS_NORM_BINORM_TAN_UV;

//*****************************************************************************