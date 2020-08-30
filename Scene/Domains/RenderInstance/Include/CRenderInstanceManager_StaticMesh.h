/*
    CRenderInstanceManager_StaticMesh.h - Contains class CRenderInstanceManager_StaticMesh.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CRENDERINSTANCEMANAGER_STATICMESH_H
#define REGINA_CRENDERINSTANCEMANAGER_STATICMESH_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <CRenderInstance_StaticMesh.h>

#include <CException_NullPointer.h>
using namespace Regina::Misc;

namespace Regina
{

namespace Scene
{

/**
 * This class manages static mesh render instances.
 */
class CRenderInstanceManager_StaticMesh
{
private:
	/**
	 * Stores dynamic instances.
	 */
	vector<CRenderInstance_StaticMesh*> dynamicInstance;
	/**
	 * Stores static instances.
	 */
	vector<CRenderInstance_StaticMesh*> staticInstance;

	/**
	 * Returns dynamic render instance.
	 */
	CRenderInstance_StaticMesh* GetRenderInstance_Dynamic(CRenderObject_StaticMesh* iRenderObject);
	/**
	 * Returns static render instance.
	 */
	CRenderInstance_StaticMesh* GetRenderInstance_Static(CRenderObject_StaticMesh* iRenderObject);

protected:
	/**
	 * Stores pointer to DirectX device interface.
	 */
	LPDIRECT3DDEVICE9 device;

public:
	/**
	 * Constructor.
	 */
	CRenderInstanceManager_StaticMesh(LPDIRECT3DDEVICE9 iDevice) throw(CException_NullPointer);
	/**
	 * Destructor.
	 */
	virtual ~CRenderInstanceManager_StaticMesh();
	/**
	 * Renders all instances.
	 */
	void Render();
	/**
	 * Ensures a proper lost device behavior.
	 */
	void OnLostDevice();
	/**
	 * Ensures a proper reset device behavior.
	 */
	void OnResetDevice();
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
	 * Adds render object.
	 */
	void AddRenderObject(CRenderObject_StaticMesh* iRenderObject);
};

}

}

#pragma warning( pop )

#endif 