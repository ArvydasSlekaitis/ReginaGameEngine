///////////////////////////////////////////////////////////
//  CRenderObject_SimpleMesh.h
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CRENDEROBJECT_SIMPLEMESH_H
#define REGINA_CRENDEROBJECT_SIMPLEMESH_H

#include <CRenderObject.h>

namespace Regina
{


class CRenderObject_SimpleMesh : public CRenderObject
{
	D3DXMATRIX	transformation;
	LPD3DXMESH	mesh;
	float		size;

public:
	virtual ~CRenderObject_SimpleMesh();

	CRenderObject_SimpleMesh(const CRenderObject::eType& iType, const CMatterial& iMatterial, LPD3DXMESH iMesh, const D3DXMATRIX& iTransformation, const float& iSize, const bool& iCastShadows, const bool& iReceiveShadows);
	CRenderObject_SimpleMesh(const CRenderObject_SimpleMesh& iRenderObject);
	
	D3DXMATRIX	Transformation()	const;
	float		Size()				const { return size; }
	D3DXVECTOR3 Position()			const { return D3DXVECTOR3(transformation._41, transformation._42, transformation._43); } 
	LPD3DXMESH	Mesh();
	
	CRenderObject_SimpleMesh& operator=(const CRenderObject_SimpleMesh& iRenderObject);

};

}

#endif 