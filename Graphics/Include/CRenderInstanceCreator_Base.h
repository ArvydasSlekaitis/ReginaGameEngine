///////////////////////////////////////////////////////////
//  CRenderInstanceCreator_Base.h
//  Created on:      28-11-2009
//  Last modified:   28-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_CRENDERINSTANCECREATOR_BASE_H
#define REGINA_CRENDERINSTANCECREATOR_BASE_H

#include <d3dx9.h>

#include <string>
#include <assert.h>
using namespace std;

#include <CRenderInstance_SimpleMesh.h>
#include <ERenderInstanceTypeEnumaration.h>

namespace Regina
{

class CRenderInstanceCreator_Base
{
public:
	virtual CRenderInstance_SimpleMesh*	CreateInstance_SimpleMesh(const eRenderInstanceType& iRenderInstanceType, LPDIRECT3DDEVICE9 iDevice, LPD3DXMESH iMesh) = 0;

};

}

#endif
