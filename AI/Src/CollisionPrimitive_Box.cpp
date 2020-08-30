///////////////////////////////////////////////////////////
//  CollisionPrimitive_Box.cpp
//  Created on:      23-07-2009
//  Last modified:   29-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CollisionPrimitive_Box.h>
using namespace Regina;

//*****************************************************************************
	
CCollisionPrimitive_Box::CCollisionPrimitive_Box(const D3DXMATRIXA16& iOffset, const D3DXVECTOR3& iHalfSize, const float iRestitution) : recalculateToLocalMatrix(false), offset(iOffset), halfSize(iHalfSize), CCollisionPrimitive(iRestitution)
	{
	D3DXMatrixIdentity(&toLocal);
	D3DXMatrixIdentity(&inverseTransformation);
	D3DXMatrixInverse(&inverseOffset, NULL, &iOffset);
	}

//*****************************************************************************

CCollisionPrimitive_Box::CCollisionPrimitive_Box(const D3DXVECTOR3& iPosition, const D3DXVECTOR3& iRotation, const D3DXVECTOR3& iHalfSize, const float iRestitution) : recalculateToLocalMatrix(false), halfSize(iHalfSize), CCollisionPrimitive(iRestitution)
	{
	D3DXVECTOR3 rotnorm;
	D3DXQUATERNION quat;
	D3DXVec3Normalize(&rotnorm, &iRotation);
	D3DXQuaternionRotationAxis(&quat, &rotnorm, D3DXVec3Length(&iRotation));
	D3DXMatrixAffineTransformation(&offset, 1.0, &D3DXVECTOR3(0, 0, 0), &quat, &iPosition);

	D3DXMatrixIdentity(&toLocal);
	D3DXMatrixIdentity(&inverseTransformation);
	D3DXMatrixInverse(&inverseOffset, NULL, &offset);
	}

//*****************************************************************************

CCollisionPrimitive_Box::CCollisionPrimitive_Box(istream& iStream) : recalculateToLocalMatrix(false), CCollisionPrimitive()
	{
	D3DXVECTOR3 iPosition(0, 0, 0);
	D3DXVECTOR3 iRotation(0, 0, 0);
	iStream >> iPosition.x >> iPosition.y >> iPosition.z >> iRotation.x >> iRotation.y >> iRotation.z >> halfSize.x >> halfSize.y >> halfSize.z >> restitution;

	D3DXVECTOR3 rotnorm;
	D3DXQUATERNION quat;
	D3DXVec3Normalize(&rotnorm, &iRotation);
	D3DXQuaternionRotationAxis(&quat, &rotnorm, D3DXVec3Length(&iRotation));
	D3DXMatrixAffineTransformation(&offset, 1.0, &D3DXVECTOR3(0, 0, 0), &quat, &iPosition);

	D3DXMatrixIdentity(&toLocal);
	D3DXMatrixIdentity(&inverseTransformation);
	D3DXMatrixInverse(&inverseOffset, NULL, &offset);
	}

//*****************************************************************************


void CCollisionPrimitive_Box::SetTransform(const D3DXMATRIXA16& iTransformation, const D3DXMATRIXA16& iInverseTransformation)
	{
	transformation = iTransformation;
	inverseTransformation = iInverseTransformation;
	recalculateToLocalMatrix = true;
	}

//*****************************************************************************

void CCollisionPrimitive_Box::SetTransform(const D3DXMATRIXA16& iTransformation)
	{
	transformation = iTransformation;
	D3DXMatrixInverse(&inverseTransformation, NULL, &transformation);
	recalculateToLocalMatrix = true;
	}

//*****************************************************************************

D3DXMATRIXA16 CCollisionPrimitive_Box::ToLocal()
	{
	if(recalculateToLocalMatrix==true)
		RecalculateToLocalMatrix();

	return toLocal;
	}

//*****************************************************************************

void CCollisionPrimitive_Box::RecalculateToLocalMatrix()
	{
	recalculateToLocalMatrix=false;

	D3DXMatrixMultiply(&toLocal, &inverseTransformation, &inverseOffset);
	}

//*****************************************************************************

float CCollisionPrimitive_Box::BigestSqDistanceFromOrigin()
	{
	vector<D3DXVECTOR3> vertices;
	GenerateVertices_Box(halfSize, vertices);

	float maxDistance = 0.0f;
	for(unsigned i=0; i<vertices.size(); i++)
		{
		D3DXVECTOR3 v(0, 0, 0);
		D3DXVec3TransformCoord(&v, &vertices[i], &offset);

		float dist = D3DXVec3LengthSq(&v);
		if(dist>maxDistance) maxDistance = dist;
		}

	return maxDistance;
	}

//*****************************************************************************

float CCollisionPrimitive_Box::BigestSqDistanceFromOriginXZ()
	{
	vector<D3DXVECTOR3> vertices;
	GenerateVertices_Box(halfSize, vertices);

	float maxDistance = 0.0f;
	for(unsigned i=0; i<vertices.size(); i++)
		{
		D3DXVECTOR3 v(0, 0, 0);
		D3DXVec3TransformCoord(&v, &vertices[i], &offset);

		float dist = D3DXVec2LengthSq(&D3DXVECTOR2(v.x, v.z));
		if(dist>maxDistance) maxDistance = dist;
		}

	return maxDistance;
	}

//*****************************************************************************

void CCollisionPrimitive_Box::DetectContacts(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius, const float& iSphereRestitution, vector<CBasicContactData>& oContactData)
	{
	const D3DXVECTOR3 worldSphere(iSpherePositionX, iSpherePositionY, iSpherePositionZ);
	D3DXVECTOR4 localSphere;  //Local to box

	D3DXVec3Transform(&localSphere, &worldSphere, &(ToLocal()));

	if(abs(localSphere.x) - iSphereRadius >  halfSize.x) return;
	if(abs(localSphere.y) - iSphereRadius >  halfSize.y) return;
	if(abs(localSphere.z) - iSphereRadius >  halfSize.z) return;

	D3DXVECTOR3 closestPoint; // from sphere to box
	float distance;

	distance = localSphere.x;
	if(localSphere.x > halfSize.x) distance = halfSize.x;
	if(localSphere.x < -halfSize.x) distance = -halfSize.x;
	closestPoint.x = distance;

	distance = localSphere.y;
	if(localSphere.y > halfSize.y) distance = halfSize.y;
	if(localSphere.y < -halfSize.y) distance = -halfSize.y;
	closestPoint.y = distance;

	distance = localSphere.z;
	if(localSphere.z > halfSize.z) distance = halfSize.z;
	if(localSphere.z < -halfSize.z) distance = -halfSize.z;
	closestPoint.z = distance;

	distance = Distance_Sq(D3DXVECTOR3(localSphere.x, localSphere.y, localSphere.z), closestPoint);
	if(distance < iSphereRadius*iSphereRadius)
		{
		//Contact found
		D3DXVECTOR3 contactNormal = closestPoint - D3DXVECTOR3(localSphere.x, localSphere.y, localSphere.z); //!!!
		D3DXVec3Normalize(&contactNormal, &contactNormal);

		oContactData.push_back(CBasicContactData(closestPoint, -contactNormal, sqrt(distance) - iSphereRadius, (iSphereRestitution + restitution)/2));
		}

	}

//*****************************************************************************

void CCollisionPrimitive_Box::DetectContacts(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius, vector<CBasicContactData>& oContactData)
	{
	const D3DXVECTOR3 worldSphere(iSpherePositionX, iSpherePositionY, iSpherePositionZ);
	D3DXVECTOR4 localSphere;  //Local to box

	D3DXVec3Transform(&localSphere, &worldSphere, &(ToLocal()));

	if(abs(localSphere.x) - iSphereRadius >  halfSize.x) return;
	if(abs(localSphere.y) - iSphereRadius >  halfSize.y) return;
	if(abs(localSphere.z) - iSphereRadius >  halfSize.z) return;

	D3DXVECTOR3 closestPoint; // from sphere to box
	float distance;

	distance = localSphere.x;
	if(localSphere.x > halfSize.x) distance = halfSize.x;
	if(localSphere.x < -halfSize.x) distance = -halfSize.x;
	closestPoint.x = distance;

	distance = localSphere.y;
	if(localSphere.y > halfSize.y) distance = halfSize.y;
	if(localSphere.y < -halfSize.y) distance = -halfSize.y;
	closestPoint.y = distance;

	distance = localSphere.z;
	if(localSphere.z > halfSize.z) distance = halfSize.z;
	if(localSphere.z < -halfSize.z) distance = -halfSize.z;
	closestPoint.z = distance;

	distance = Distance_Sq(D3DXVECTOR3(localSphere.x, localSphere.y, localSphere.z), closestPoint);
	if(distance < iSphereRadius*iSphereRadius)
		{		
		//Contact found
		D3DXVECTOR3 contactNormal = closestPoint - D3DXVECTOR3(localSphere.x, localSphere.y, localSphere.z); //!!!
		D3DXVec3Normalize(&contactNormal, &contactNormal);

		oContactData.push_back(CBasicContactData(closestPoint, -contactNormal, sqrt(distance) - iSphereRadius, restitution));
		}
	}

//*****************************************************************************

bool CCollisionPrimitive_Box::Intersect(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius)
	{
	const D3DXVECTOR3 worldSphere(iSpherePositionX, iSpherePositionY, iSpherePositionZ);
	D3DXVECTOR4 localSphere;  //Local to box

	D3DXVec3Transform(&localSphere, &worldSphere, &(ToLocal()));

	if(abs(localSphere.x) - iSphereRadius >  halfSize.x) return false;
	if(abs(localSphere.y) - iSphereRadius >  halfSize.y) return false; 
	if(abs(localSphere.z) - iSphereRadius >  halfSize.z) return false;

	D3DXVECTOR3 closestPoint; // from sphere to box
	float distance;

	distance = localSphere.x;
	if(localSphere.x > halfSize.x) distance = halfSize.x;
	if(localSphere.x < -halfSize.x) distance = -halfSize.x;
	closestPoint.x = distance;

	distance = localSphere.y;
	if(localSphere.y > halfSize.y) distance = halfSize.y;
	if(localSphere.y < -halfSize.y) distance = -halfSize.y;
	closestPoint.y = distance;

	distance = localSphere.z;
	if(localSphere.z > halfSize.z) distance = halfSize.z;
	if(localSphere.z < -halfSize.z) distance = -halfSize.z;
	closestPoint.z = distance;

	distance = Distance_Sq(D3DXVECTOR3(localSphere.x, localSphere.y, localSphere.z), closestPoint);
	if(distance < iSphereRadius*iSphereRadius)
	return true;


	return false;
	}

//*****************************************************************************

bool CCollisionPrimitive_Box::IntersectXZ(const float& iSpherePositionX, const float& iSpherePositionZ, const float& iSphereRadius)
	{	
	const D3DXVECTOR3 worldSphere(iSpherePositionX, 0, iSpherePositionZ);
	D3DXVECTOR4 localSphere;  //Local to box

	D3DXVec3Transform(&localSphere, &worldSphere, &(ToLocal()));

	if(abs(localSphere.x) - iSphereRadius >  halfSize.x) return false;
	if(abs(localSphere.z) - iSphereRadius >  halfSize.z) return false;

	D3DXVECTOR2 closestPoint; // from sphere to box
	float distance;

	distance = localSphere.x;
	if(localSphere.x > halfSize.x) distance = halfSize.x;
	if(localSphere.x < -halfSize.x) distance = -halfSize.x;
	closestPoint.x = distance;

	distance = localSphere.z;
	if(localSphere.z > halfSize.z) distance = halfSize.z;
	if(localSphere.z < -halfSize.z) distance = -halfSize.z;
	closestPoint.y = distance;

	distance = Distance_Sq(D3DXVECTOR2(localSphere.x, localSphere.z), closestPoint);
	if(distance < iSphereRadius*iSphereRadius)
	return true;


	return false;
	}

//*****************************************************************************

void CCollisionPrimitive_Box::SetPosition(const D3DXVECTOR3& iPosition)
	{
	transformation._41 = iPosition.x;
	transformation._42 = iPosition.y;
	transformation._43 = iPosition.z;

	inverseTransformation._41 = -iPosition.x;
	inverseTransformation._42 = -iPosition.y;
	inverseTransformation._43 = -iPosition.z;

	recalculateToLocalMatrix = true;
	}

//*****************************************************************************
