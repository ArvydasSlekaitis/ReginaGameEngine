///////////////////////////////////////////////////////////
//  CollisionPrimitive.h
//  Created on:      28-08-2008
//  Last modified:   23-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_COLLISIONPRIMITIVE_H
#define REGINA_COLLISIONPRIMITIVE_H

#include <d3dx9.h>

namespace Regina
{

class CCollisionPrimitive
{
protected:
	D3DXMATRIXA16	transformation;
	float			restitution;

public:
	CCollisionPrimitive(const float iRestitution = 1.0f) : restitution(iRestitution) { D3DXMatrixIdentity(&transformation); }
	
	D3DXMATRIXA16	Transformation()	const { return transformation; }
	float			Restitution()		const { return restitution; }

	void SetRestitution(const float& iRestitution) { restitution = iRestitution; }
};

};

#endif
