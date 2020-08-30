/*
    CRenderInstance_StaticMesh.h - Contains class CRenderInstance_StaticMesh.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CRENDERINSTANCE_STATICMESH_H
#define REGINA_CRENDERINSTANCE_STATICMESH_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <CRenderInstance.h>
#include <CRenderObject_StaticMesh.h>

#include <CException_NullPointer.h>
#include <CException_InvalidArgument.h>
#include <CException_OutOfMemory.h>
using namespace Regina::Misc;

namespace Regina
{

namespace Scene
{

/**
 * This class provides a way to create and render static mesh instance in an
 * convenient way.
 */
class CRenderInstance_StaticMesh : public CRenderInstance
{
private:
	/**
	 * Stores render list.
	 */
	vector<CRenderObject_StaticMesh*> renderList;
	/**
	 * Stores pointer to effect.
	 */
	LPD3DXEFFECT effect;
	/**
	 * Stores pointer to instance vertex buffer.
	 */
	LPDIRECT3DVERTEXBUFFER9 instanceVertexBuffer;
	/**
	 * Stores pointer to instance vertex element.
	 */
	D3DVERTEXELEMENT9* instanceVertexElement;
	/**
	 * Stores pointer to instance vertex declaration.
	 */
	LPDIRECT3DVERTEXDECLARATION9 instanceVertexDeclaration;
	/**
	 * Stores pointer to mesh vertex buffer.
	 */
	LPDIRECT3DVERTEXBUFFER9 meshVertexBuffer;
	/**
	 * Stores pointer to mesh index buffer.
	 */
	LPDIRECT3DINDEXBUFFER9 meshIndexBuffer;
	/**
	 * Stores instance vertex buffer size.
	 */
	unsigned lastInstanceVertexBufferSize;
	/**
	 * Stores instance data size.
	 */
	unsigned instanceDataSize;
	/**
	 * Stores pointer to mesh.
	 */
	LPD3DXMESH mesh;

	/**
	 * Expands buffer if current size is smaller than new size.
	 */
	void RecreateInstanceBuffer(const unsigned& iNewSize);
	/**
	 * Fills instance VB.
	 */
	void FillInstanceVB();
	/**
	 * Returns render list size.
	 */
	unsigned RenderListSize() const;

public:
	/**
	 * Constructor.
	 */
	CRenderInstance_StaticMesh(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const unsigned& iInstanceDataSize, const wstring& iEffectFilename) throw(CException_NullPointer, CException_InvalidArgument, CException_OutOfMemory);
	/**
	 * Destructor.
	 */
	virtual ~CRenderInstance_StaticMesh();
	/**
	 * Clear render list.
	 */
	virtual void Clear();
	/**
	 * Renders instance.
	 */
	virtual void Render();
	/**
	 * Add render object to render list.
	 */
	void AddRenderObject(CRenderObject_StaticMesh* iRenderObject);
	/**
	 * Returns true if render object can be inserted into render instance, otherwise
	 * returns false.
	 */
	bool CanBeInserted(CRenderObject_StaticMesh* iRenderObject);
	/**
	 * Performs all actions to ensure proper lost device state.
	 */
	virtual void OnLostDevice();
	/**
	 * Performs all actions to ensure proper reset device state.
	 */
	virtual void OnResetDevice();
};

}

}

#pragma warning( pop )

#endif 