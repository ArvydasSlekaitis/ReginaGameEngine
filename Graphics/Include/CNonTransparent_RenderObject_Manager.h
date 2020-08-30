///////////////////////////////////////////////////////////
//  CNonTransparent_RenderObject_Manager.h
//  Created on:      27-11-2009
//  Last modified:   27-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CNONTRANSPARENT_RENDEROBJECT_MANAGER_H
#define REGINA_CNONTRANSPARENT_RENDEROBJECT_MANAGER_H

#include <CRenderInstanceManager.h>

namespace Regina
{


class CNonTransparent_RenderObject_Manager
{
	CRenderInstanceManager* instanceManager;
	LPDIRECT3DDEVICE9	device;

public:
	virtual ~CNonTransparent_RenderObject_Manager();

	CNonTransparent_RenderObject_Manager(LPDIRECT3DDEVICE9 iDevice);
	void Render(const eRenderType& iRenderType, const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition);
	void Clear();
	void ClearStatic();
	void ClearDynamic();
	void OnLostDevice();
	void OnResetDevice();
	void AddRenderObject(CRenderObject_SimpleMesh& iRenderObject);

};

}

#endif 