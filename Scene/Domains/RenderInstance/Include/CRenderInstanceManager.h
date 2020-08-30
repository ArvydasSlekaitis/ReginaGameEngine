/*
    CRenderInstanceManager.h - Contains class CRenderInstanceManager.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CRENDERINSTANCEMANAGER_H
#define REGINA_CRENDERINSTANCEMANAGER_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <CRenderInstanceManager_StaticMesh.h>

#include <CException_NullPointer.h>
using namespace Regina::Misc;

namespace Regina
{

namespace Scene
{

/**
 * This class is responsible for managing render instances.
 */
class CRenderInstanceManager
{
private:
	/**
	 * Stores pointer to static mesh render instance manager.
	 */
	CRenderInstanceManager_StaticMesh* renderInstanceManager_StaticMesh;
	/**
	 * Stores pointer to DirectX device interface.
	 */
	LPDIRECT3DDEVICE9 device;

public:
	CRenderInstanceManager();

	/**
	 * Constructor.
	 */
	CRenderInstanceManager(LPDIRECT3DDEVICE9 iDevice) throw(CException_NullPointer);
	/**
	 * Destructor.
	 */
	virtual ~CRenderInstanceManager();
	/**
	 * Renders all instances.
	 */
	void Render();
	/**
	 * Clear render list.
	 */
	void Clear();
	/**
	 * Clear static objects render list.
	 */
	void ClearStatic();
	/**
	 * Clear dynamic objects render list.
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