///////////////////////////////////////////////////////////
//  CRenderInstanceCreator_Default.h
//  Created on:      28-11-2009
//  Last modified:   28-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_CRENDERINSTANCECREATOR_DEFAULT_H
#define REGINA_CRENDERINSTANCECREATOR_DEFAULT_H

#include <d3dx9.h>

#include <string>
#include <assert.h>
using namespace std;

#include <CRenderInstance_SimpleMesh.h>
#include <ERenderInstanceTypeEnumaration.h>
#include <CRenderInstanceCreator_Base.h>

#include <CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor.h>
#include <CRenderInstance_SimpleMesh_AmbientMap_DiffuseMap_SpecularColor.h>
#include <CRenderInstance_SimpleMesh_Alpha_AmbientMap_DiffuseMap_SpecularColor.h>

namespace Regina
{

class CRenderInstanceCreator_Default : public CRenderInstanceCreator_Base
{
public:
	virtual CRenderInstance_SimpleMesh*	CreateInstance_SimpleMesh(const eRenderInstanceType& iRenderInstanceType, LPDIRECT3DDEVICE9 iDevice, LPD3DXMESH iMesh);

};

}

#endif
