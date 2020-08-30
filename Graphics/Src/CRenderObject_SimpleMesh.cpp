///////////////////////////////////////////////////////////
//  CRenderObject_SimpleMesh.cpp
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CRenderObject_SimpleMesh.h>
using namespace Regina;


//*****************************************************************************

CRenderObject_SimpleMesh::~CRenderObject_SimpleMesh()
	{
	if(mesh!=NULL)
		mesh->Release();
	mesh = NULL;
	}

//*****************************************************************************

CRenderObject_SimpleMesh::CRenderObject_SimpleMesh(const CRenderObject::eType& iType, const CMatterial& iMatterial, LPD3DXMESH iMesh, const D3DXMATRIX& iTransformation, const float& iSize, const bool& iCastShadows, const bool& iReceiveShadows) : CRenderObject(iType, iMatterial, iCastShadows, iReceiveShadows), transformation(iTransformation), size(iSize), mesh(NULL)
  	{
	if(iMesh == NULL)
		throw invalid_argument("CRenderObject_SimpleMesh::CRenderObject_SimpleMesh - argument iMesh==NULL");
	mesh = iMesh;
	mesh->AddRef();
	}

//*****************************************************************************

D3DXMATRIX CRenderObject_SimpleMesh::Transformation() const 
  	{
	return  transformation;
	}

//*****************************************************************************

LPD3DXMESH CRenderObject_SimpleMesh::Mesh() 
  	{
	return  mesh;
	}

//*****************************************************************************

CRenderObject_SimpleMesh& CRenderObject_SimpleMesh::operator=(const CRenderObject_SimpleMesh& iRenderObject)
	{
	if(this!=&iRenderObject)
		{
		if(mesh!=NULL)
			mesh->Release();
		mesh = iRenderObject.mesh;
		mesh->AddRef();
		transformation = iRenderObject.Transformation();
		size = iRenderObject.Size();
		(CRenderObject)(*this) = (CRenderObject)iRenderObject;
		}
	return *this;
	}

//*****************************************************************************

CRenderObject_SimpleMesh::CRenderObject_SimpleMesh(const CRenderObject_SimpleMesh& iRenderObject) : CRenderObject(iRenderObject.Type(), iRenderObject.Matterial(), iRenderObject.CastShadows(), iRenderObject.ReceiveShadows()), transformation(iRenderObject.Transformation()), mesh(NULL)
	{
	mesh = iRenderObject.mesh;
	mesh->AddRef();
	}

//*****************************************************************************