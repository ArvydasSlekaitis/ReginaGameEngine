///////////////////////////////////////////////////////////
//  CollisionPrimitive_Box.h
//  Created on:      28-08-2008
//  Last modified:   29-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_COLLISIONPRIMITIVE_BOX_H
#define REGINA_COLLISIONPRIMITIVE_BOX_H

#include <d3dx9.h>

#include <istream>
#include <vector>
using namespace std;

#include <CollisionPrimitive.h>
#include <BasicContactData.h>
#include <Functions_Math.h>
#include <CollisionPrimitive_Sphere.h>

namespace Regina
{

class CCollisionPrimitive_Box : public CCollisionPrimitive
{
	bool			recalculateToLocalMatrix;	

protected:
	D3DXVECTOR3		halfSize;
	D3DXMATRIXA16	offset;
	D3DXMATRIXA16	inverseOffset;
	D3DXMATRIXA16	inverseTransformation;
	D3DXMATRIXA16	toLocal;

	void RecalculateToLocalMatrix();

public:
	D3DXVECTOR3		LocalPosition() const { return D3DXVECTOR3(offset._41, offset._42, offset._43); }
	D3DXVECTOR3		WorldPosition() const { return LocalPosition() + D3DXVECTOR3(transformation._41, transformation._42, transformation._43); }
	D3DXVECTOR3		HalfSize()		const { return halfSize; }
	D3DXMATRIXA16	Offset()		const { return offset; }
	D3DXMATRIXA16	InverseOffset() const { return inverseOffset; }
	D3DXMATRIXA16	ToLocal();


	CCollisionPrimitive_Box(const D3DXMATRIXA16& iOffset, const D3DXVECTOR3& iHalfSize, const float iRestitution = 1.0f);
	CCollisionPrimitive_Box(const D3DXVECTOR3& iPosition, const D3DXVECTOR3& iRotation, const D3DXVECTOR3& iHalfSize, const float iRestitution = 1.0f);
	CCollisionPrimitive_Box(istream& iStream);

	void SetTransform(const D3DXMATRIXA16& iTransformation);
	void SetTransform(const D3DXMATRIXA16& iTransformation, const D3DXMATRIXA16& iInverseTransformation);
	void SetPosition(const D3DXVECTOR3& iPosition);

	float BigestSqDistanceFromOrigin(); // Get the distance of most further box vertex to origin
	float BigestSqDistanceFromOriginXZ();// Get the distance of most further box vertex  (only XZ axis ) to origin

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


