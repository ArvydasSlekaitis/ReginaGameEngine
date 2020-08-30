/*
    CRenderObject_StaticMesh.cpp - Contains class CRenderObject_StaticMesh implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#include <CRenderObject_StaticMesh.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Constructor.
 */
CRenderObject_StaticMesh::CRenderObject_StaticMesh(LPD3DXMESH iMesh, CMaterial* iMaterial, const D3DXVECTOR3& iObjectCenter, const float& iObjectRadius, const bool& iStatic, const bool& iTransparencyEnabled) : CRenderObject(type_StaticMesh, iMaterial, iObjectCenter, iObjectRadius, iStatic, iTransparencyEnabled), mesh(NULL)
	{
	if(iMesh == NULL)
		throw CException_NullPointer("CRenderObject_StaticMesh::CRenderObject_StaticMesh(LPD3DXMESH iMesh, CMaterial* iMaterial, const D3DXVECTOR3& iObjectCenter, const float& iObjectRadius, const bool& iTransparencyEnabled)", "iMesh");

	mesh = iMesh;
	mesh->AddRef();
	}

//*****************************************************************************

/**
 * Copy constructor.
 */
CRenderObject_StaticMesh::CRenderObject_StaticMesh(const CRenderObject_StaticMesh& iRenderObject) : CRenderObject(iRenderObject), mesh(NULL)
	{
	mesh = iRenderObject.mesh;
	mesh->AddRef();
	}

//*****************************************************************************

/**
 * Destructor.
 */
CRenderObject_StaticMesh::~CRenderObject_StaticMesh()
	{
	if(mesh!=NULL)
		mesh->Release();
	mesh = NULL;
	}

//*****************************************************************************

/**
 * Private assignment operator.
 */
CRenderObject_StaticMesh& CRenderObject_StaticMesh::operator=(const CRenderObject_StaticMesh& iRenderObject)
	{
	if(this!=&iRenderObject)
		{
		}
	return *this;
	}

//*****************************************************************************

/**
 * Stores pointer to mesh.
 */
LPD3DXMESH CRenderObject_StaticMesh::GetMesh()
	{
	return mesh;
	}

//*****************************************************************************