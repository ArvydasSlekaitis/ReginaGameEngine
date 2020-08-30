///////////////////////////////////////////////////////////
//  CScene.h
//  Created on:      27-11-2009
//  Last modified:   27-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CSCENE_H
#define REGINA_CSCENE_H

#include <CNonTransparent_RenderObject_Manager.h>

namespace Regina
{


class CScene
{
	CNonTransparent_RenderObject_Manager* renderObject_Manager_NonTransparent;
	LPDIRECT3DDEVICE9 device;

public:
	virtual ~CScene();

	CScene(LPDIRECT3DDEVICE9 iDevice);
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