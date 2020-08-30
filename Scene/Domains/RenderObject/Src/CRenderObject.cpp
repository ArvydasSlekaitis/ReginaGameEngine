/*
    CRenderObject.cpp - Contains class CRenderObject implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#include <CRenderObject.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Constructor.
 */
CRenderObject::CRenderObject(const ERenderObjectType& iType, CMaterial* iMaterial, const D3DXVECTOR3& iObjectCenter, const float& iObjectRadius, const bool& iStatic, const bool& iTransparencyEnabled) : type(iType), material(iMaterial), position(iObjectCenter), radius(iObjectRadius), isStatic(iStatic), transparencyEnabled(iTransparencyEnabled)
	{
	if(iMaterial == NULL)
		throw CException_NullPointer("CRenderObject::CRenderObject(const ERenderObjectType& iType, CMaterial* iMaterial, const D3DXVECTOR3& iObjectCenter, const float& iObjectRadius, const bool& iTransparencyEnabled)", "iMaterial");
	}

//*****************************************************************************

/**
 * Destructor.
 */
CRenderObject::~CRenderObject()
	{
	}

//*****************************************************************************

/**
 * Returns material.
 */
CMaterial* CRenderObject::GetMaterial()
	{
	return material;
	}

//*****************************************************************************

/**
 * Returns transparency flag.
 */
bool CRenderObject::IsTransparencyEnabled() const 
	{
	return transparencyEnabled;
	}

//*****************************************************************************

/**
 * Returns render object type.
 */
CRenderObject::ERenderObjectType CRenderObject::GetType() const 
	{
	return type;
	}

//*****************************************************************************

/**
 * Returns radius from object center (in world coordinates).
 */
float CRenderObject::GetRadius() const 
	{
	return radius;
	}

//*****************************************************************************

/**
 * Returns object center position (in world coordinates).
 */
D3DXVECTOR3 CRenderObject::GetPosition() const 
	{
	return position;
	}

//*****************************************************************************

/**
* Returns flag which indicates whatever render object is static (true) or dynamic
* (false).
*/
bool CRenderObject::IsStatic() const
	{
	return isStatic;
	}


//*****************************************************************************