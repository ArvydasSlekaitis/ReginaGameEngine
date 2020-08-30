///////////////////////////////////////////////////////////
//  CRenderInstance_SimpleMesh_Alpha_AmbientMap_DiffuseMap_SpecularColor.h
//  Created on:      31-01-2010
//  Last modified:   31-01-2010
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CRENDERINSTANCE_SIMPLEMESH_ALPHA_AMBIENTMAP_DIFFUSEMAP_SPECULARCOLOR_H
#define REGINA_CRENDERINSTANCE_SIMPLEMESH_ALPHA_AMBIENTMAP_DIFFUSEMAP_SPECULARCOLOR_H

#include <vector>
#include <assert.h>
#include <sstream>
using namespace std;

#include <CRenderInstance_SimpleMesh.h>
#include <CRenderObject_SimpleMesh.h>
#include <MeshDefinitions.h>
#include <CLightingManager.h>
#include <TextureHandler.h>

namespace Regina
{


class CRenderInstance_SimpleMesh_Alpha_AmbientMap_DiffuseMap_SpecularColor : public CRenderInstance_SimpleMesh
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
	virtual ~CRenderInstance_SimpleMesh_Alpha_AmbientMap_DiffuseMap_SpecularColor();

	CRenderInstance_SimpleMesh_Alpha_AmbientMap_DiffuseMap_SpecularColor(LPDIRECT3DDEVICE9 iDevice, LPD3DXMESH iMesh);
};

}

#endif 