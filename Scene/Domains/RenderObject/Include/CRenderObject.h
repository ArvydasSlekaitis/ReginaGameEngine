/*
    CRenderObject.h - Contains class CRenderObject.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CRENDEROBJECT_H
#define REGINA_CRENDEROBJECT_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <CMaterial.h>

#include <CException_NullPointer.h>
using namespace Regina::Misc;

namespace Regina
{

namespace Scene
{

/**
 * This class is used as a base class for different render objects.
 */
class CRenderObject
{
public:
	/**
	 * This enumeration defines possible render object types.
	 */
	enum ERenderObjectType
	{
		/**
		 * Render object type - static mesh.
		 */
		type_StaticMesh,
		/**
		 * Render object type - skinned mesh.
		 */
		type_SkinnedMesh
	};

private:
	/**
	 * Stores material.
	 */
	CMaterial* material;
	/**
	 * Stores transparency flag.
	 */
	const bool transparencyEnabled;
	/**
	 * Stores render object type.
	 */
	const ERenderObjectType type;
	/**
	 * Stores radius from object center (in world coordinates).
	 */
	const float radius;
	/**
	 * Stores object center position (in world coordinates).
	 */
	const D3DXVECTOR3 position;
	/**
	 * This flag indicates whatever render object is static (true) or dynamic (false).
	 */
	const bool isStatic;

public:
	/**
	 * Constructor.
	 */
	CRenderObject(const ERenderObjectType& iType, CMaterial* iMaterial, const D3DXVECTOR3& iObjectCenter, const float& iObjectRadius, const bool& iStatic, const bool& iTransparencyEnabled) throw(CException_NullPointer);
	/**
	 * Destructor.
	 */
	virtual ~CRenderObject();
	/**
	 * Returns material.
	 */
	CMaterial* GetMaterial();
	/**
	 * Returns transparency flag.
	 */
	bool IsTransparencyEnabled() const;
	/**
	 * Returns render object type.
	 */
	ERenderObjectType GetType() const;
	/**
	 * Returns radius from object center (in world coordinates).
	 */
	float GetRadius() const;
	/**
	 * Returns object center position (in world coordinates).
	 */
	D3DXVECTOR3 GetPosition() const;
	/**
	 * Returns flag which indicates whatever render object is static (true) or dynamic
	 * (false).
	 */
	bool IsStatic() const;
};

}

}

#pragma warning( pop )

#endif 