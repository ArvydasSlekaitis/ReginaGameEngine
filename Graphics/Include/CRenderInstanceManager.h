///////////////////////////////////////////////////////////
//  CRenderInstanceManager.h
//  Created on:      27-11-2009
//  Last modified:   27-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CRENDERINSTANCEMANAGER_H
#define REGINA_CRENDERINSTANCEMANAGER_H

#include <CSimpleMeshRenderInstanceManager.h>

namespace Regina
{


class CRenderInstanceManager
{
	CSimpleMeshRenderInstanceManager*	simpleMeshRenderInstanceManager;
	LPDIRECT3DDEVICE9	device;

public:
	virtual ~CRenderInstanceManager();

	CRenderInstanceManager(LPDIRECT3DDEVICE9 iDevice);
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