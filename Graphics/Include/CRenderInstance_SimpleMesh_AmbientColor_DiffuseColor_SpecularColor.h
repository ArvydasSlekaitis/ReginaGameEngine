///////////////////////////////////////////////////////////
//  CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor.h
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CRENDERINSTANCE_SIMPLEMESH_AMBIENTCOLOR_DIFFUSECOLOR_SPECULARCOLOR_H
#define REGINA_CRENDERINSTANCE_SIMPLEMESH_AMBIENTCOLOR_DIFFUSECOLOR_SPECULARCOLOR_H

#include <vector>
#include <assert.h>
#include <sstream>
using namespace std;

#include <CRenderInstance_SimpleMesh.h>
#include <CRenderObject_SimpleMesh.h>
#include <MeshDefinitions.h>
#include <CLightingManager.h>

namespace Regina
{


class CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor : public CRenderInstance_SimpleMesh
{
static const eMatterialType			matterialType;
static const eRenderInstanceType	renderInstanceType;
static const string					effectName;
static const unsigned				instanceDataSize;
static D3DVERTEXELEMENT9*			instanceVertexElement;

protected:
	virtual void SetEffectParams(LPD3DXEFFECT& ioEffect, const vector<CRenderObject_SimpleMesh>& iRenderList);
	virtual void FillInstanceVB(LPDIRECT3DVERTEXBUFFER9& ioVertexBuffer, const vector<CRenderObject_SimpleMesh>& iRenderList);

public:
	virtual ~CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor();

	CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor(LPDIRECT3DDEVICE9 iDevice, LPD3DXMESH iMesh);
};

}

#endif 