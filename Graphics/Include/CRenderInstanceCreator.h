///////////////////////////////////////////////////////////
//  CRenderInstanceCreator.h
//  Created on:      20-11-2009
//  Last modified:   20-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_CRENDERINSTANCECREATOR_H
#define REGINA_CRENDERINSTANCECREATOR_H

#include <d3dx9.h>

#include <string>
#include <assert.h>
using namespace std;

#include <CRenderInstance_SimpleMesh.h>
#include <ERenderInstanceTypeEnumaration.h>
#include <CRenderInstanceCreator_Base.h>

namespace Regina
{

class CRenderInstanceCreator
{
	CRenderInstanceCreator_Base*  renderInstanceCreator;
	CRenderInstanceCreator();
	CRenderInstanceCreator(const CRenderInstanceCreator&) {}

public:
	~CRenderInstanceCreator();
	static CRenderInstanceCreator* Instance();
	void Init(CRenderInstanceCreator_Base* iRenderInstanceCreator);

	CRenderInstance_SimpleMesh*	CreateInstance_SimpleMesh(const eRenderInstanceType& iRenderInstanceType, LPDIRECT3DDEVICE9 iDevice, LPD3DXMESH iMesh);

};

#define RenderInstanceCreator CRenderInstanceCreator::Instance()

}

#endif
