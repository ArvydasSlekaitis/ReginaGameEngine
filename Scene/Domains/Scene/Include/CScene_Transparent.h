/*
    CScene_Transparent.h - Contains class CScene_Transparent.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CSCENE_TRANSPARENT_H
#define REGINA_CSCENE_TRANSPARENT_H

#include <CRenderObject_StaticMesh.h>
#include <CRenderInstance_StaticMesh.h>

namespace Regina
{

namespace Scene
{

/**
 * This class is responsible for rendering transparent scene objects.
 */
class CScene_Transparent
{
private:
	/**
	 * Holds all render instances together with availability flag.
	 */
	vector<pair<CRenderInstance_StaticMesh*, bool> > loadedInstance;
	/**
	 * Holds all static mesh render objects.
	 */
	vector<CRenderObject_StaticMesh*> renderList;

	/**
	 * Returns available instance.
	 */
	CRenderInstance_StaticMesh* GetAvailableInstance(CRenderObject_StaticMesh* iRenderObject);

protected:
	/**
	 * Stores pointer to DirectX device interface.
	 */
	LPDIRECT3DDEVICE9 device;

public:
	/**
	 * Constructor.
	 */
	CScene_Transparent(LPDIRECT3DDEVICE9 iDevice);
	/**
	 * Destructor.
	 */
	virtual ~CScene_Transparent();
	/**
	 * Renders transparent objects in sorted order.
	 */
	void Render(const D3DXVECTOR3& iCameraPosition, const D3DXVECTOR3& iCameraDirection, const float& iRenderDistance);
	/**
	 * Clears all render objects.
	 */
	void Clear();
	/**
	 * Clears static render objects.
	 */
	void ClearStatic();
	/**
	 * Clears dynamic render objects.
	 */
	void ClearDynamic();
	/**
	 * Performs all actions to ensure proper lost device state.
	 */
	void OnLostDevice();
	/**
	 * Performs all actions to ensure proper reset device state.
	 */
	void OnResetDevice();
	/**
	 * Adds render object.
	 */
	void AddRenderObject(CRenderObject_StaticMesh* iRenderObject);
};

}

}

#endif 