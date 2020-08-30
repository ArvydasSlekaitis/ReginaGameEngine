/*
    CScene.h - Contains class CScene.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CSCENE_H
#define REGINA_CSCENE_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <CScene_NonTransparent.h>
#include <CScene_Transparent.h>
#include <CRenderObject_StaticMesh.h>

namespace Regina
{

namespace Scene
{

/**
 * This class is responsible for providing all top interface for drawing 
 * scene.
 */
class CScene
{
private:
	/**
	 * Stores pointers of all static meshes (dynamic) registered with scene.
	 */
	vector<CRenderObject_StaticMesh*> renderObject_StaticMesh_Dynamic;
	/**
	 * Stores pointers of all static meshes (static) registered with scene.
	 */
	vector<CRenderObject_StaticMesh*> renderObject_StaticMesh_Static;
	/**
	 * Stores pointer to non transparent scene.
	 */
	CScene_NonTransparent* nonTransparentScene;
	/**
	 * Stores pointer to transparent scene.
	 */
	CScene_Transparent* transparentScene;
	/**
	 * Stores pointer to DirectX device interface.
	 */
	LPDIRECT3DDEVICE9 device;

protected:
	/**
	 * Protected constructor - used by global version.
	 */
	CScene();
	/**
	 * Sets pointer to DirectX device.
	 */
	void SetDevice(LPDIRECT3DDEVICE9 iDevice) throw(CException_NullPointer);

public:
	/**
	 * Constructor.
	 */
	CScene(LPDIRECT3DDEVICE9 iDevice) throw(CException_NullPointer);
	/**
	 * Destructor.
	 */
	virtual ~CScene();
	/**
	 * Renders scene.
	 */
	void Render(const D3DXVECTOR3& iCameraPosition, const D3DXVECTOR3& iCameraDirection, const float& iRenderDistance = 1000.0f);
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
	 * Clears scene and releases DirectX device interface.
	 */
	void OnDestroyDevice();
	/**
	 * Adds render object.
	 */
	void AddRenderObject(CRenderObject_StaticMesh& iRenderObject);
};

}

}

#pragma warning( pop )

#endif 