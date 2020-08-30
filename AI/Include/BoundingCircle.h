///////////////////////////////////////////////////////////
//  BoundingCircle.h
//  Created on:      23-06-2009
//  Last modified:   23-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_BOUNDINGCIRCLE_H
#define REGINA_BOUNDINGCIRCLE_H

#include <Functions_Math.h>
#include <BoundingSphere.h>

namespace Regina
{

class CBoundingCircle
{
	D3DXVECTOR2 position;
	float		radius;

public:
	CBoundingCircle(D3DXVECTOR2 iPosition = D3DXVECTOR2(0.0f, 0.0f), float iRadius = 0.0f) : position(iPosition), radius(iRadius) {}	

	D3DXVECTOR2 Position()	const { return position; }
	float		Radius()	const { return radius; }

	void SetPosition(D3DXVECTOR2 iPosition) { position = iPosition; }
	void SetPosition(float iX, float iY) { position.x = iX; position.y = iY; }
	void SetRadius(float iRadius) { radius = iRadius; }

	float Area() { return D3DX_PI*radius*radius; }

	void IncreaseRadius(float iX, float iY, float iRadius);
	void IncreaseRadius(const CBoundingCircle& iCircle) { IncreaseRadius(iCircle.Position().x, iCircle.Position().y, iCircle.Radius()); }
	void IncreaseRadius(const CBoundingSphere& iSphere) { IncreaseRadius(iSphere.Position().x, iSphere.Position().z, iSphere.Radius()); }
	void IncreaseRadius(D3DXVECTOR2 iPosition, float iRadius) { IncreaseRadius(iPosition.x, iPosition.y, iRadius); }
	void IncreaseRadius(D3DXVECTOR3 iPosition, float iRadius) { IncreaseRadius(iPosition.x, iPosition.z, iRadius); }

		
};


}


#endif
