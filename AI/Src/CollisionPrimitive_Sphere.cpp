///////////////////////////////////////////////////////////
//  CollisionPrimitive_Sphere.cpp
//  Created on:      23-07-2009
//  Last modified:   29-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CollisionPrimitive_Sphere.h>
using namespace Regina;

//*****************************************************************************
	
CCollisionPrimitive_Sphere::CCollisionPrimitive_Sphere(const D3DXVECTOR3& iLocalPosition, const float& iLocalRadius, const float iRestitution) : worldScale(1.0f), localPosition(iLocalPosition), localRadius(iLocalRadius), CCollisionPrimitive(iRestitution)
	{
	}

//*****************************************************************************

CCollisionPrimitive_Sphere::CCollisionPrimitive_Sphere(istream& iStream): worldScale(1.0f), CCollisionPrimitive()
	{
	iStream >> localPosition.x >> localPosition.y >> localPosition.z >> localRadius >> restitution;
	}

//*****************************************************************************

void CCollisionPrimitive_Sphere::SetTransform(const D3DXMATRIXA16& iTransformation)
	{
	transformation = iTransformation;

	D3DXVECTOR3 pOutScale;
	D3DXQUATERNION pOutRotation;
	D3DXVECTOR3 pOutTranslation;

	D3DXMatrixDecompose(&pOutScale, &pOutRotation, &pOutTranslation, &transformation);

	worldScale = max(pOutScale.x, max(pOutScale.y, pOutScale.z));
	}

//*****************************************************************************

void CCollisionPrimitive_Sphere::SetTransform(const D3DXMATRIXA16& iTransformation, const float& iScale)
	{
	transformation = iTransformation;
	worldScale = iScale;
	}

//*****************************************************************************

float CCollisionPrimitive_Sphere::BigestDistanceFromOrigin()
	{
	return D3DXVec3Length(&localPosition) + localRadius;
	}

//*****************************************************************************

float CCollisionPrimitive_Sphere::BigestDistanceFromOriginXZ()
	{
	return D3DXVec2Length(&D3DXVECTOR2(localPosition.x, localPosition.z)) + localRadius;
	}

//*****************************************************************************

void CCollisionPrimitive_Sphere::DetectContacts(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius, const float& iSphereRestitution, vector<CBasicContactData>& oContactData)
	{
	const D3DXVECTOR3 iPosition1(iSpherePositionX, iSpherePositionY, iSpherePositionZ);
	const D3DXVECTOR3 iPosition2(WorldPosition());

	float distance = Distance(iPosition1, iPosition2);
	if(distance < iSphereRadius + Radius())
		{
		//Contact found
		D3DXVECTOR3 direction = iPosition1 - iPosition2;
		D3DXVECTOR3 contactNormal;
		D3DXVec3Normalize(&contactNormal, &direction);
		float penetration = (distance - iSphereRadius - Radius());
		D3DXVECTOR3 contactPoint = contactNormal*(iSphereRadius-penetration) + iPosition1;

		oContactData.push_back(CBasicContactData(contactPoint, contactNormal, penetration, (iSphereRestitution+restitution)/2));
		}
	}

//*****************************************************************************

void CCollisionPrimitive_Sphere::DetectContacts(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius, vector<CBasicContactData>& oContactData)
	{
	const D3DXVECTOR3 iPosition1(iSpherePositionX, iSpherePositionY, iSpherePositionZ);
	const D3DXVECTOR3 iPosition2(WorldPosition());

	const float distance = Distance(iPosition1, iPosition2);
	if(distance < iSphereRadius + Radius())
		{
		//Contact found
		D3DXVECTOR3 direction = iPosition1 - iPosition2;
		D3DXVECTOR3 contactNormal;
		D3DXVec3Normalize(&contactNormal, &direction);
		float penetration = (distance - iSphereRadius - Radius());
		D3DXVECTOR3 contactPoint = contactNormal*(iSphereRadius-penetration) + iPosition1;

		oContactData.push_back(CBasicContactData(contactPoint, contactNormal, penetration, restitution));
		}
	}

//*****************************************************************************

bool CCollisionPrimitive_Sphere::Intersect(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius)
	{
	const D3DXVECTOR3 iPosition1(iSpherePositionX, iSpherePositionY, iSpherePositionZ);
	const D3DXVECTOR3 iPosition2(WorldPosition());

	const float distance = Distance(iPosition1, iPosition2);
	return (distance < iSphereRadius + Radius());
	}

//*****************************************************************************

bool CCollisionPrimitive_Sphere::IntersectXZ(const float& iSpherePositionX, const float& iSpherePositionZ, const float& iSphereRadius)
	{
	const D3DXVECTOR2 iPosition1(iSpherePositionX, iSpherePositionZ);

	const float distance = Distance(iPosition1, D3DXVECTOR2(WorldPosition().x, WorldPosition().z));
	return (distance < iSphereRadius + Radius());
	}

//*****************************************************************************

void CCollisionPrimitive_Sphere::SetPosition(const D3DXVECTOR3& iPosition)
	{
	transformation._41 = iPosition.x;
	transformation._42 = iPosition.y;
	transformation._43 = iPosition.z;
	}

//*****************************************************************************