///////////////////////////////////////////////////////////
//  CollisionPrimitive_Sphere.h
//  Created on:      28-08-2008
//  Last modified:   29-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_COLLISIONPRIMITIVE_SPHERE_H
#define REGINA_COLLISIONPRIMITIVE_SPHERE_H

#include <d3dx9.h>

#include <istream>
#include <vector>
using namespace std;

#include <CollisionPrimitive.h>
#include <BasicContactData.h>
#include <Functions_Math.h>

namespace Regina
{

class CCollisionPrimitive_Sphere : public CCollisionPrimitive
{
protected:
	float		localRadius;
	float		worldScale;
	D3DXVECTOR3	localPosition;
	
public:
	
	float		LocalRadius()	const { return localRadius; }
	float		Radius()		const { return worldScale*localRadius; }
	D3DXVECTOR3 LocalPosition() const { return localPosition; }
	D3DXVECTOR3 WorldPosition() const { return localPosition + D3DXVECTOR3(transformation._41, transformation._42, transformation._43); }
	D3DXMATRIXA16 Offset()			  { return D3DXMATRIXA16(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, localPosition.x, localPosition.y, localPosition.z, 1); }
	D3DXMATRIXA16 ToLocal()     	  { return D3DXMATRIXA16(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -WorldPosition().x, -WorldPosition().y, -WorldPosition().z, 1); }

	CCollisionPrimitive_Sphere(const D3DXVECTOR3& iLocalPosition, const float& iLocalRadius, const float iRestitution = 1.0f);
	CCollisionPrimitive_Sphere(istream& iStream);

	void SetTransform(const D3DXMATRIXA16& iTransformation);
	void SetTransform(const D3DXMATRIXA16& iTransformation, const float& iScale); // Optimized version; iScale - scale with which was made iTransformation matrix
	void SetPosition(const D3DXVECTOR3& iPosition);

	float BigestDistanceFromOrigin(); // Get the distance of most further point of sphere to origin
	float BigestDistanceFromOriginXZ(); // Get the distance of most further point of sphere (only XZ axis ) to origin

	void DetectContacts(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius, const float& iSphereRestitution, vector<CBasicContactData>& oContactData);
	inline void DetectContacts(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius, const float& iSphereRestitution, vector<CBasicContactData>& oContactData) { DetectContacts(iSpherePosition.x, iSpherePosition.y, iSpherePosition.z, iSphereRadius, iSphereRestitution, oContactData); } 
	inline void DetectContacts(const CCollisionPrimitive_Sphere& iSphere, vector<CBasicContactData>& oContactData) { DetectContacts(iSphere.WorldPosition().x, iSphere.WorldPosition().y, iSphere.WorldPosition().z, iSphere.Radius(), iSphere.Restitution(), oContactData); } 

	void DetectContacts(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius, vector<CBasicContactData>& oContactData);
	inline void DetectContacts(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius, vector<CBasicContactData>& oContactData) { DetectContacts(iSpherePosition.x, iSpherePosition.y, iSpherePosition.z, iSphereRadius, oContactData); } 

	bool Intersect(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius);
	inline bool Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius) { return Intersect(iSpherePosition.x, iSpherePosition.y, iSpherePosition.z, iSphereRadius); }

	bool IntersectXZ(const float& iSpherePositionX, const float& iSpherePositionZ, const float& iSphereRadius);
	inline bool IntersectXZ(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius) { return IntersectXZ(iSpherePosition.x, iSpherePosition.z, iSphereRadius); }
	inline bool IntersectXZ(const D3DXVECTOR2& iSpherePosition, const float& iSphereRadius) { return IntersectXZ(iSpherePosition.x, iSpherePosition.y, iSphereRadius); }

};

};

#endif

