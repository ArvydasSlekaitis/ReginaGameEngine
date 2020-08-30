/*
    CRenderInstance.h - Contains class CRenderInstance.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CRENDERINSTANCE_H
#define REGINA_CRENDERINSTANCE_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <d3dx9.h>

#include <CException_NullPointer.h>
using namespace Regina::Misc;

namespace Regina
{

namespace Scene
{

/**
 * This class is used as a base class for different render instances.
 */
class CRenderInstance
{
private:
	/**
	 * Stores material type.
	 */
	const int materialType;
	/**
	 * Stores material ID.
	 */
	int materialID;
	/**
	 * Stores modification flag.
	 */
	bool modified;

	/**
	 * Private copy constructor.
	 */
	CRenderInstance(const CRenderInstance& prm1);
	/**
	 * Private assignment operator.
	 */
	CRenderInstance& operator=(const CRenderInstance& prm1);

protected:
	/**
	 * Stores pointer to DirectX device.
	 */
	LPDIRECT3DDEVICE9 device;

	/**
	 * Returns modification flag.
	 */
	bool IsModified() const;
	/**
	 * Sets material ID.
	 */
	void SetMaterialID(const int& newVal);
	/**
	 * Sets modification flag.
	 */
	void SetModified(bool newVal);

public:
	/**
	 * Constructor.
	 */
	CRenderInstance(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType) throw(CException_NullPointer);
	/**
	 * Destructor.
	 */
	virtual ~CRenderInstance();
	/**
	 * Renders instance.
	 */
	virtual void Render() =0;
	/**
	 * Clears VB.
	 */
	virtual void Clear() =0;
	/**
	 * Returns material type.
	 */
	int GetMaterialType() const;
	/**
	 * Performs all actions to ensure proper lost device state.
	 */
	virtual void OnLostDevice() =0;
	/**
	 * Performs all actions to ensure proper reset device state.
	 */
	virtual void OnResetDevice() =0;
	/**
	 * Returns material ID.
	 */
	int GetMaterialID() const;
};

}

}

#pragma warning( pop )

#endif 