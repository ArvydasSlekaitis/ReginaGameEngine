/*
    CMaterial.cpp - Contains class CMaterial implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#include <CMaterial.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Private copy constructor.
 */
CMaterial::CMaterial(const CMaterial& iMaterial) : effectFilename(L""), techniqueName(L"")
	{
	}

//*****************************************************************************

/**
 * Constructor.
 */
CMaterial::CMaterial(const wstring& iEffectFilename, const wstring& iEffectTechniqueName) : effectFilename(iEffectFilename), techniqueName(iEffectTechniqueName), materialID(-1), materialType(-1)
	{
	SetMaterialType(typeGenerator.Register(this));
	}

//*****************************************************************************

/**
 * Destructor.
 */
CMaterial::~CMaterial()
	{
	typeGenerator.Unregister(this, GetMaterialType());
	}

//*****************************************************************************

/**
* Private assignemnt operator.
*/
CMaterial& CMaterial::operator=(const CMaterial& iMaterial)
	{
	return *this;
	}

//*****************************************************************************

/**
* Comparison operator.
*/
bool CMaterial::CompareMaterialType(const CMaterial& iMaterial)
	{
	if(effectFilename == iMaterial.effectFilename && techniqueName == iMaterial.techniqueName)
		return true;
	else
		return false;
	}

//*****************************************************************************

/**
 * Returns material ID.
 */
int CMaterial::GetMaterialID() const 
	{
	return materialID;
	}

//*****************************************************************************

/**
 * Returns material type.
 */
int CMaterial::GetMaterialType() const 
	{
	return materialType;
	}

//*****************************************************************************

/**
 * Sets effect filename.
 */
wstring CMaterial::GetEffectFilename() const 
	{
	return effectFilename;
	}

//*****************************************************************************

/**
 * Returns technique name.
 */
wstring CMaterial::GetTechniqueName() const 
	{
	return techniqueName;
	}

//*****************************************************************************

/**
* Sets material ID.
*/
void CMaterial::SetMaterialID(const int& iMaterialID)
	{
	materialID = iMaterialID;
	}

//*****************************************************************************

TMaterialTypeGenerator<CMaterial> CMaterial::typeGenerator;

//*****************************************************************************