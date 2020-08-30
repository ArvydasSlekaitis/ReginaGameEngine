///////////////////////////////////////////////////////////
//  CSimpleMeshRenderInstanceManager.h
//  Created on:      20-11-2009
//  Last modified:   20-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CSIMPLEMESHRENDERINSTANCEMANAGER_H
#define REGINA_CSIMPLEMESHRENDERINSTANCEMANAGER_H

#include <CRenderInstance_SimpleMesh.h>
#include <CRenderInstanceCreator.h>

namespace Regina
{


class CSimpleMeshRenderInstanceManager
{
	vector<CRenderInstance_SimpleMesh*> dynamicInstance;
	vector<CRenderInstance_SimpleMesh*> staticInstance;

private:
	void AddDynamic(CRenderObject_SimpleMesh& iRenderObject);
	void AddStatic(CRenderObject_SimpleMesh& iRenderObject);
	CRenderInstance_SimpleMesh* GetInstance_Dynamic(CRenderObject_SimpleMesh& iRenderObject);
	CRenderInstance_SimpleMesh* GetInstance_Static(CRenderObject_SimpleMesh& iRenderObject);

protected:
	LPDIRECT3DDEVICE9 device;

public:
	virtual ~CSimpleMeshRenderInstanceManager();

	CSimpleMeshRenderInstanceManager(LPDIRECT3DDEVICE9 iDevice);
	
	void Render(const eRenderType& iRenderType, const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition);
	void OnLostDevice();
	void OnResetDevice();
	void Clear();
	void ClearStatic();
	void ClearDynamic();
	void AddRenderObject(CRenderObject_SimpleMesh& iRenderObject);

};

}

#endif 