///////////////////////////////////////////////////////////
//  CollisionMesh.h
//  Created on:      28-08-2008
//  Last modified:   22-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CollisionMesh.h>
using namespace Regina;

//*****************************************************************************

CCollisionMesh::CCollisionMesh(const string iName) : sphere(0), box(0), name(iName), radius(0), radiusXZ(0), worldScale(1)
	{
	 D3DXMatrixIdentity(&transformation);
	
	 if(iName.size()>0)
		Load(iName);
	}

//*****************************************************************************

CCollisionMesh::CCollisionMesh(const string& iName, const D3DXMATRIXA16& iTransformation) : sphere(0), box(0), name(iName), radius(0), radiusXZ(0), worldScale(1)
	{
	transformation=iTransformation;
	Load(iName);
	SetTransform(transformation);
	}

//*****************************************************************************

CCollisionMesh::~CCollisionMesh()
	{
	for(unsigned i=0; i<sphere.size(); i++)
		delete sphere[i];

	for(unsigned i=0; i<box.size(); i++)
		delete box[i];
	}

//*****************************************************************************

void CCollisionMesh::Load(const string& iName)
{
	name = iName;

	string fileName = string("Data\\CollisionMesh\\")+iName + string(".txt");;
	ifstream file(fileName.c_str());

	if(file.is_open() == false)
		throw logic_error("Trying to open CollisionMesh file, which does not exist");

	string line;
	string type;

	while(!file.eof())
	{
		getline(file, line);
		istringstream ssLine(line);
		ssLine >> type;
		if(type == "Sphere") sphere.push_back(new CCollisionPrimitive_Sphere(ssLine));
		if(type == "Box") 	 box.push_back(new CCollisionPrimitive_Box(ssLine));
	}

	CalculateRadius();
}

//*****************************************************************************

void CCollisionMesh::CalculateRadius()
	{
	radius = 0;
	radiusXZ = 0;
	float sqRadius = 0;
	float sqRadiusXZ = 0;

	for(unsigned i=0; i<sphere.size(); i++)
		{
		float dist = sphere[i]->BigestDistanceFromOrigin();
		if(dist>radius) radius = dist;

		float distXZ = sphere[i]->BigestDistanceFromOriginXZ();
		if(distXZ>radiusXZ) radiusXZ = distXZ;
		}

	for(unsigned i=0; i<box.size(); i++)
		{
		float dist = box[i]->BigestSqDistanceFromOrigin();
		if(dist>sqRadius) sqRadius = dist;

		float distXZ = box[i]->BigestSqDistanceFromOriginXZ();
		if(distXZ>sqRadiusXZ) sqRadiusXZ = distXZ;
		}

	radius = max(radius, sqrt(sqRadius));
	radiusXZ = max(radiusXZ, sqrt(sqRadiusXZ));
	}

//*****************************************************************************

void CCollisionMesh::SetTransform(const D3DXMATRIXA16& iTransformation)
	{
	transformation = iTransformation;

	D3DXVECTOR3 pOutScale;
	D3DXQUATERNION pOutRotation;
	D3DXVECTOR3 pOutTranslation;

	D3DXMatrixDecompose(&pOutScale, &pOutRotation, &pOutTranslation, &transformation);

	worldScale = max(pOutScale.x, max(pOutScale.y, pOutScale.z));

	D3DXMATRIXA16	inverseTransformation;
	D3DXMatrixInverse(&inverseTransformation, NULL, &transformation);

	for(unsigned i=0; i<sphere.size(); i++)
		{
		sphere[i]->SetTransform(iTransformation, worldScale);
		}

	for(unsigned i=0; i<box.size(); i++)
		{
		box[i]->SetTransform(iTransformation, inverseTransformation);
		}
	}

//*****************************************************************************

void CCollisionMesh::SetTransform(const D3DXMATRIXA16& iTransformation, const D3DXMATRIXA16& iInverseTransformation)
	{
	transformation = iTransformation;

	D3DXVECTOR3 pOutScale;
	D3DXQUATERNION pOutRotation;
	D3DXVECTOR3 pOutTranslation;

	D3DXMatrixDecompose(&pOutScale, &pOutRotation, &pOutTranslation, &transformation);

	worldScale = max(pOutScale.x, max(pOutScale.y, pOutScale.z));

	for(unsigned i=0; i<sphere.size(); i++)
		{
		sphere[i]->SetTransform(iTransformation, worldScale);
		}

	for(unsigned i=0; i<box.size(); i++)
		{
		box[i]->SetTransform(iTransformation, iInverseTransformation);
		}
	}

//*****************************************************************************

void CCollisionMesh::SetTransform(const D3DXMATRIXA16& iTransformation, const D3DXMATRIXA16& iInverseTransformation, const float& iScale)
	{
	transformation = iTransformation;
	worldScale = iScale;

	for(unsigned i=0; i<sphere.size(); i++)
		{
		sphere[i]->SetTransform(iTransformation, worldScale);
		}

	for(unsigned i=0; i<box.size(); i++)
		{
		box[i]->SetTransform(iTransformation, iInverseTransformation);
		}
	}

//*****************************************************************************

void CCollisionMesh::SetTransform(const D3DXMATRIXA16& iTransformation, const float& iScale)
	{
	transformation = iTransformation;
	worldScale = iScale;

	for(unsigned i=0; i<sphere.size(); i++)
		{
		sphere[i]->SetTransform(iTransformation, worldScale);
		}

	D3DXMATRIXA16	inverseTransformation;
	D3DXMatrixInverse(&inverseTransformation, NULL, &transformation);

	for(unsigned i=0; i<box.size(); i++)
		{
		box[i]->SetTransform(iTransformation);
		}
	}

//*****************************************************************************

CCollisionMesh::CCollisionMesh(const CCollisionMesh& iCollisionMesh)
	{
	name = iCollisionMesh.name;
	radius = iCollisionMesh.radius;
	radiusXZ = iCollisionMesh.radiusXZ;
	worldScale = iCollisionMesh.worldScale;
	transformation=iCollisionMesh.transformation;

	sphere.clear();
	box.clear();

	for(unsigned i=0; i<iCollisionMesh.sphere.size(); i++)
		sphere.push_back(new CCollisionPrimitive_Sphere(*iCollisionMesh.sphere[i]));

	for(unsigned i=0; i<box.size(); i++)
		box.push_back(new CCollisionPrimitive_Box(*iCollisionMesh.box[i]));
	}

//*****************************************************************************

CCollisionMesh& CCollisionMesh::operator=(const CCollisionMesh& iCollisionMesh)
	{
	if(this != &iCollisionMesh)
		{
		name = iCollisionMesh.name;
		radius = iCollisionMesh.radius;
		radiusXZ = iCollisionMesh.radiusXZ;
		worldScale = iCollisionMesh.worldScale;
		transformation=iCollisionMesh.transformation;

		sphere.clear();
		box.clear();

		for(unsigned i=0; i<iCollisionMesh.sphere.size(); i++)
			sphere.push_back(new CCollisionPrimitive_Sphere(*iCollisionMesh.sphere[i]));

		for(unsigned i=0; i<box.size(); i++)
			box.push_back(new CCollisionPrimitive_Box(*iCollisionMesh.box[i]));
		}

	return *this;
	}

//*****************************************************************************

void CCollisionMesh::SetPosition(const D3DXVECTOR3& iPosition)
	{
	transformation._41 = iPosition.x;
	transformation._42 = iPosition.y;
	transformation._43 = iPosition.z;

	for(unsigned i=0; i<sphere.size(); i++)
		{
		sphere[i]->SetPosition(iPosition);
		}

	for(unsigned i=0; i<box.size(); i++)
		{
		box[i]->SetPosition(iPosition);
		}
	}

//*****************************************************************************

void CCollisionMesh::DetectContacts(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius, const float& iSphereRestitution, vector<CBasicContactData>& oContactData)
	{
	for(unsigned i=0; i<sphere.size(); i++)
		{
		sphere[i]->DetectContacts(iSpherePositionX, iSpherePositionY, iSpherePositionZ, iSphereRadius, iSphereRestitution, oContactData);
		}

	for(unsigned i=0; i<box.size(); i++)
		{
		box[i]->DetectContacts(iSpherePositionX, iSpherePositionY, iSpherePositionZ, iSphereRadius, iSphereRestitution, oContactData);
		}
	}

//*****************************************************************************

void CCollisionMesh::DetectContacts(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius, const float& iSphereRestitution, vector<CBasicContactData>& oContactData)
	{
	for(unsigned i=0; i<sphere.size(); i++)
		{
		sphere[i]->DetectContacts(iSpherePosition, iSphereRadius, iSphereRestitution, oContactData);
		}

	for(unsigned i=0; i<box.size(); i++)
		{
		box[i]->DetectContacts(iSpherePosition, iSphereRadius, iSphereRestitution, oContactData);
		}
	}

//*****************************************************************************

void CCollisionMesh::DetectContacts(const CCollisionPrimitive_Sphere& iSphere, vector<CBasicContactData>& oContactData)
	{
	for(unsigned i=0; i<sphere.size(); i++)
		{
		sphere[i]->DetectContacts(iSphere, oContactData);
		}

	for(unsigned i=0; i<box.size(); i++)
		{
		box[i]->DetectContacts(iSphere, oContactData);
		}
	}

//*****************************************************************************

void CCollisionMesh::DetectContacts(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius, vector<CBasicContactData>& oContactData)
	{
	for(unsigned i=0; i<sphere.size(); i++)
		{
		sphere[i]->DetectContacts(iSpherePositionX, iSpherePositionY, iSpherePositionZ, iSphereRadius, oContactData);
		}

	for(unsigned i=0; i<box.size(); i++)
		{
		box[i]->DetectContacts(iSpherePositionX, iSpherePositionY, iSpherePositionZ, iSphereRadius, oContactData);
		}
	}

//*****************************************************************************

void CCollisionMesh::DetectContacts(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius, vector<CBasicContactData>& oContactData)
	{
	for(unsigned i=0; i<sphere.size(); i++)
		{
		sphere[i]->DetectContacts(iSpherePosition, iSphereRadius, oContactData);
		}

	for(unsigned i=0; i<box.size(); i++)
		{
		box[i]->DetectContacts(iSpherePosition, iSphereRadius, oContactData);
		}
	}

//*****************************************************************************

bool CCollisionMesh::Intersect(const float& iSpherePositionX, const float& iSpherePositionY, const float& iSpherePositionZ, const float& iSphereRadius)
	{
	for(unsigned i=0; i<sphere.size(); i++)
		if(sphere[i]->Intersect(iSpherePositionX, iSpherePositionY, iSpherePositionZ, iSphereRadius))
			return true;

	for(unsigned i=0; i<box.size(); i++)
		if(box[i]->Intersect(iSpherePositionX, iSpherePositionY, iSpherePositionZ, iSphereRadius))
			return true;

	return false;
	}

//*****************************************************************************

bool CCollisionMesh::Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius)
	{
	for(unsigned i=0; i<sphere.size(); i++)
		if(sphere[i]->Intersect(iSpherePosition, iSphereRadius))
			return true;

	for(unsigned i=0; i<box.size(); i++)
		if(box[i]->Intersect(iSpherePosition, iSphereRadius))
			return true;

	return false;
	}

//*****************************************************************************

bool CCollisionMesh::IntersectXZ(const float& iSpherePositionX, const float& iSpherePositionZ, const float& iSphereRadius)
	{
	for(unsigned i=0; i<sphere.size(); i++)
		if(sphere[i]->IntersectXZ(iSpherePositionX, iSpherePositionZ, iSphereRadius))
			return true;

	for(unsigned i=0; i<box.size(); i++)
		if(box[i]->IntersectXZ(iSpherePositionX, iSpherePositionZ, iSphereRadius))
			return true;

	return false;
	}

//*****************************************************************************

bool CCollisionMesh::IntersectXZ(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius)
	{
	for(unsigned i=0; i<sphere.size(); i++)
		if(sphere[i]->IntersectXZ(iSpherePosition, iSphereRadius))
			return true;

	for(unsigned i=0; i<box.size(); i++)
		if(box[i]->IntersectXZ(iSpherePosition, iSphereRadius))
			return true;

	return false;
	}

//*****************************************************************************

bool CCollisionMesh::IntersectXZ(const D3DXVECTOR2& iSpherePosition, const float& iSphereRadius)
	{
	for(unsigned i=0; i<sphere.size(); i++)
		if(sphere[i]->IntersectXZ(iSpherePosition, iSphereRadius))
			return true;

	for(unsigned i=0; i<box.size(); i++)
		if(box[i]->IntersectXZ(iSpherePosition, iSphereRadius))
			return true;

	return false;
	}

//*****************************************************************************
