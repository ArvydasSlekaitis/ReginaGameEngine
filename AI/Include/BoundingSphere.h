///////////////////////////////////////////////////////////
//  BoundingSphere.h
//  Created on:      18-08-2008
//  Last modified:   23-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_BOUNDINGSPEHERE_H
#define REGINA_BOUNDINGSPEHERE_H

#include <Functions_Math.h>

namespace Regina
{

class CBoundingSphere
{
	D3DXVECTOR3 position;
	float		radius;

public:
	CBoundingSphere(D3DXVECTOR3 iPosition = D3DXVECTOR3(0.0f, 0.0f, 0.0f), float iRadius=0.0f) : position(iPosition), radius(iRadius) {}
	
	D3DXVECTOR3 Position()	const { return position; }
	float  		Radius()	const { return radius; }

	void SetPosition(D3DXVECTOR3 iPosition) { position = iPosition; }
	void SetPosition(float iX, float iY, float iZ) { position.x = iX; position.y = iY; position.z = iZ; }
	void SetRadius(float iRadius) { radius = iRadius; }

	float Area() { return (4/3)*D3DX_PI*radius*radius*radius; }

	void IncreaseRadius(float iX, float iY, float iZ, float iRadius);
	void IncreaseRadius(const CBoundingSphere& iSphere) { IncreaseRadius(iSphere.Position().x, iSphere.Position().y, iSphere.Position().z, iSphere.Radius()); }
	void IncreaseRadius(D3DXVECTOR3 iPosition, float iRadius) { IncreaseRadius(iPosition.x, iPosition.y, iPosition.z, iRadius); }
	
};

}

#endif
