/*
    CRenderObject_StaticMesh.h - Contains class CRenderObject_StaticMesh.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CRENDEROBJECT_STATICMESH_H
#define REGINA_CRENDEROBJECT_STATICMESH_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <CRenderObject.h>

#include <CException_NullPointer.h>
using namespace Regina::Misc;

namespace Regina
{

namespace Scene
{

/**
 * This class defines render object for static mesh.
 */
class CRenderObject_StaticMesh : public CRenderObject
{
private:
	/**
	 * Stores pointer to mesh.
	 */
	LPD3DXMESH mesh;

	/**
	 * Private assignment operator.
	 */
	CRenderObject_StaticMesh& operator=(const CRenderObject_StaticMesh& iRenderObject);

public:
	/**
	 * Copy constructor.
	 */
	CRenderObject_StaticMesh(const CRenderObject_StaticMesh& iRenderObject);
	/**
	 * Constructor.
	 */
	CRenderObject_StaticMesh(LPD3DXMESH iMesh, CMaterial* iMaterial, const D3DXVECTOR3& iObjectCenter, const float& iObjectRadius, const bool& iStatic = false, const bool& iTransparencyEnabled = false) throw(CException_NullPointer);
	/**
	 * Destructor.
	 */
	virtual ~CRenderObject_StaticMesh();

	/**
	 * Returns pointer to mesh.
	 */
	LPD3DXMESH GetMesh();
};

}

}

#pragma warning( pop )

#endif 