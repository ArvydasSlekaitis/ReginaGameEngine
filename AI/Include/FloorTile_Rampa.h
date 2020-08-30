///////////////////////////////////////////////////////////
//  FloorTile_Rampa.h
//  Created on:      12-08-2009
//  Last modified:   12-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_FLOORTILE_RAMPA_H
#define REGINA_FLOORTILE_RAMPA_H

#include <d3dx9.h>

#include <FloorTile.h>

namespace Regina
{

class CFloorTile_Rampa : public CFloorTile
{
protected:
	float rotation;
	float slope;

public:
	CFloorTile_Rampa(const D3DXVECTOR2& iCenter, const float& iSize, const float& iRotation, const float& iSlope, const float iHeightOffset = 0.0f, const float iRestitution = 1.0f); // iRotation in degress: 0, 90, 180, 270

	inline virtual float		GetHeight(const D3DXVECTOR3& iPosition);
	inline virtual D3DXVECTOR3	GetNormal(const D3DXVECTOR3& iPosition);

};

}


#endif
