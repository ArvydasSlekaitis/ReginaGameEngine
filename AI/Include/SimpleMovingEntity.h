///////////////////////////////////////////////////////////
//  SimpleMovingEntity.h
//  Created on:      23-09-2009
//  Last modified:   23-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_SIMPLEMOVINGENTITY_H
#define REGINA_SIMPLEMOVINGENTITY_H

#include <assert.h>

#include <MovingEntity.h>
#include <AIManager.h>
#include <CollisionMesh.h>


namespace Regina
{

class CSimpleMovingEntity : public CMovingEntity
{
	D3DXMATRIXA16	transformation;
	D3DXMATRIXA16	inverseTransformation;
	CCollisionMesh*	collisionMesh;
	bool			collisionDetectionEnabled;

	CCollisionMesh*	CollisionMesh() { return collisionMesh; }
	bool			CollisionDetectionEnabled() const { return collisionDetectionEnabled; }

protected:
	void SetTransform(const D3DXMATRIXA16& iTransformation);
	void SetTransform(const D3DXMATRIXA16& iTransformation, const D3DXMATRIXA16& iInverseTransformation);
	void SetTransform(const D3DXVECTOR3& iPosition);
	void SetTransform(const D3DXVECTOR3& iPosition, const D3DXVECTOR2& iHeading);

	void EnableCollisionDetection(const bool iMessageSendingEnabled = false); // This will set moving entity as dynamic collision object
	void DisableCollisionDetection(const bool iMessageSendingEnabled = false);// This will set moving entity as dynamic collision object

public:
	CSimpleMovingEntity(const string& iCollisionMeshName, const string iClassName = "SimpleMovingEntity", const unsigned iType = 0);
	virtual ~CSimpleMovingEntity();

	D3DXMATRIXA16	Transformation()		const	{ return transformation; }
	D3DXMATRIXA16	InverseTransformation()	const	{ return inverseTransformation; }
	float			Radius()						{ assert(CollisionMesh()!=NULL); return CollisionMesh()->Radius(); }
	float			RadiusXZ()						{ assert(CollisionMesh()!=NULL); return CollisionMesh()->RadiusXZ(); }

	void			SetPosition(const D3DXVECTOR3& iPosition) { SetTransform(iPosition); }

	virtual D3DXVECTOR3		Velocity()					const = 0;
	virtual D3DXVECTOR2		Heading()					const = 0;
	virtual float			Speed()						const = 0;
};

}

#endif