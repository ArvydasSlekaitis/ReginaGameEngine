///////////////////////////////////////////////////////////
//  CRenderInstance_SimpleMesh.h
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CRENDERINSTANCE_SIMPLEMESH_H
#define REGINA_CRENDERINSTANCE_SIMPLEMESH_H

#include <vector>
#include <fstream>
#include <assert.h>
using namespace std;

#include <CRenderInstance.h>
#include <CRenderObject_SimpleMesh.h>
#include <Functions_Math.h>

namespace Regina
{


class CRenderInstance_SimpleMesh : public CRenderInstance
{
	vector<CRenderObject_SimpleMesh> renderList;

	ID3DXEffect*					effect;
	IDirect3DVertexBuffer9*			instanceVertexBuffer;
	D3DVERTEXELEMENT9*				instanceVertexElement;
	LPDIRECT3DVERTEXDECLARATION9	instanceVertexDeclaration;
	IDirect3DVertexBuffer9*			meshVertexBuffer;
	IDirect3DIndexBuffer9*			meshIndexBuffer;
	unsigned						lastInstanceVertexBufferSize;
	unsigned						instanceDataSize;
	D3DXVECTOR3						instanceCenter;
	float							instanceRadius;

	eRenderType						renderType;
	D3DXMATRIX						cameraView;
	D3DXMATRIX						cameraProj;
	D3DXVECTOR3						cameraPosition;

	LPD3DXMESH						mesh;
	void RecreateInstanceBuffer(const unsigned& iNewSize);
	void UpdateInstancePosition();

protected:
	virtual void SetEffectParams(LPD3DXEFFECT& ioEffect, const vector<CRenderObject_SimpleMesh>& iRenderList) =0;
	virtual void FillInstanceVB(LPDIRECT3DVERTEXBUFFER9& ioVertexBuffer, const vector<CRenderObject_SimpleMesh>& iRenderList) = 0;
	
	unsigned	RenderListSize()	const;
	eRenderType	RenderType()		const { return renderType; }
	D3DXMATRIX	CameraView()		const { return cameraView; }
	D3DXMATRIX	CameraProj()		const { return cameraProj; }
	D3DXVECTOR3	CameraPosition()	const { return cameraPosition; }
	D3DXVECTOR3	InstanceCenter()	const { return instanceCenter; }
	float		InstanceRadius()	const { return instanceRadius; }

public:
	virtual ~CRenderInstance_SimpleMesh();

	CRenderInstance_SimpleMesh(LPDIRECT3DDEVICE9 iDevice, const eMatterialType& iMatterialType, const eRenderInstanceType& iRenderInstanceType, const string& iEffectName, LPD3DXMESH iMesh, D3DVERTEXELEMENT9* iInstanceVertexElement, const unsigned& iInstanceDataSize);
	virtual void Clear();
	virtual void Render(const eRenderType& iRenderType, const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition);

	void AddRenderObject(CRenderObject_SimpleMesh& iRenderObject);
	bool CanBeInserted(CRenderObject_SimpleMesh& iRenderObject);

	virtual void OnLostDevice();
	virtual void OnResetDevice();

};

}

#endif 