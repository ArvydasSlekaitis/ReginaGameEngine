///////////////////////////////////////////////////////////
//  CollisionMesh.h
//  Created on:      28-08-2008
//  Last modified:   22-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_COLLISIONMESH_H
#define REGINA_COLLISIONMESH_H

#include <d3dx9.h>

#include <string>
#include <sstream>
#include <assert.h>
#include <vector>
#include <fstream>
using namespace std;

#include <CollisionPrimitive_Sphere.h>
#include <CollisionPrimitive_Box.h>
#include <Functions_Math.h>

        
namespace Regina
{

class CCollisionMesh
{
	string			name;
	float			radius;
	float			radiusXZ;
	float			worldScale;
	D3DXMATRIXA16	transformation;

	void CalculateRadius();

protected:
	vector<CCollisionPrimitive_Sphere*>		sphere;
	vector<CCollisionPrimitive_Box*>		box;
                                        
public:
	CCollisionMesh(const CCollisionMesh& iCollisionMesh);
	CCollisionMesh& operator=(const CCollisionMesh& iCollisionMesh);
	CCollisionMesh(const string iName = string());
	CCollisionMesh(const string& iName, const D3DXMATRIXA16& iTransformation);
	~CCollisionMesh();

	void Load(const string& iName);

	string			Name()				const { return name; }
	
	float			Radius()			const { return radius*worldScale; }
	float			RadiusXZ()			const { return radiusXZ*worldScale; }  
	D3DXVECTOR3		Position()			const { return D3DXVECTOR3(transformation._41, transformation._42, transformation._43); }
	D3DXMATRIXA16	Transformation()	const { return transformation; }

	void SetTransform(const D3DXMATRIXA16& iTransformation);
	void SetTransform(const D3DXMATRIXA16& iTransformation, const D3DXMATRIXA16& iInverseTransformation);
	void SetTransform(const D3DXMATRIXA16& iTransformation, const D3DXMATRIXA16& iInverseTransformation, const float& iScale); // Optimized version; iScale - scale with which was made iTransformation matrix
	void SetTransform(const D3DXMATRIXA16& iTransformation, const float& iScale); 
	void SetPosition(const D3DXVECTOR3& iPosition);

	void DetectContacts(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius, const float& iSphereRestitution, vector<CBasicContactData>& oContactData);
	void DetectContacts(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius, const float& iSphereRestitution, vector<CBasicContactData>& oContactData);
	void DetectContacts(const CCollisionPrimitive_Sphere& iSphere, vector<CBasicContactData>& oContactData);

	void DetectContacts(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius, vector<CBasicContactData>& oContactData);
	void DetectContacts(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius, vector<CBasicContactData>& oContactData);

	bool Intersect(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius);
	bool Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius);

	bool IntersectXZ(const float& iSpherePositionX, const float& iSpherePositionZ, const float& iSphereRadius);
	bool IntersectXZ(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius);
	bool IntersectXZ(const D3DXVECTOR2& iSpherePosition, const float& iSphereRadius);
};

};

#endif
