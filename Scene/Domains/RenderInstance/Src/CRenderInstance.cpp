/*
    CRenderInstance.cpp - Contains class CRenderInstance implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#include <CRenderInstance.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Constructor.
 */
CRenderInstance::CRenderInstance(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType) : materialType(iMaterialType), materialID(-1), modified(true)
	{
	if(iDevice == NULL)
		throw CException_NullPointer("CRenderInstance::CRenderInstance(LPDIRECT3DDEVICE9 iDevice, const int& iMaterialType)", "iDevice");

	device = iDevice;
	device->AddRef();
	}

//*****************************************************************************

/**
 * Destructor.
 */
CRenderInstance::~CRenderInstance()
	{
	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

/**
* Private copy constructor.
*/
CRenderInstance::CRenderInstance(const CRenderInstance& prm1) : materialType(-1), materialID(-1), modified(true)
	{
	}

//*****************************************************************************

/**
 * Private assignment operator.
 */
CRenderInstance& CRenderInstance::operator=(const CRenderInstance& prm1)
	{
	return *this;
	}

//*****************************************************************************

/**
 * Returns material type.
 */
int CRenderInstance::GetMaterialType() const 
	{
	return materialType;
	}

//*****************************************************************************

/**
 * Returns material ID.
 */
int CRenderInstance::GetMaterialID() const 
	{
	return materialID;
	}

//*****************************************************************************

/**
 * Returns modification flag.
 */
bool CRenderInstance::IsModified() const 
	{
	return modified;
	}

//*****************************************************************************

/**
 * Sets material ID.
 */
void CRenderInstance::SetMaterialID(const int& newVal)
	{
	materialID = newVal;
	}

//*****************************************************************************

/**
 * Sets modification flag.
 */
void CRenderInstance::SetModified(bool newVal)
	{
	modified = newVal;
	}

//*****************************************************************************