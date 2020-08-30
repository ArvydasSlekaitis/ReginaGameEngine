/*
    CScene_NonTransparent.h - Contains class CScene_NonTransparent.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CSCENE_NONTRANSPARENT_H
#define REGINA_CSCENE_NONTRANSPARENT_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <CRenderInstanceManager.h>

#include <CException_NullPointer.h>
using namespace Regina::Misc;

namespace Regina
{

namespace Scene
{

/**
 * This class is responsible for rendering non transparent scene objects.
 */
class CScene_NonTransparent
{
private:
	/**
	 * Stores pointer to render instance manager.
	 */
	CRenderInstanceManager* instanceManager;
	/**
	 * Holds pointer to DirectX device interface.
	 */
	LPDIRECT3DDEVICE9 device;

public:
	/**
	 * Constructor.
	 */
	CScene_NonTransparent(LPDIRECT3DDEVICE9 iDevice) throw(CException_NullPointer);
	/**
	 * Destructor.
	 */
	virtual ~CScene_NonTransparent();
	/**
	 * Renders non transparent objects.
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

#pragma warning( pop )

#endif 