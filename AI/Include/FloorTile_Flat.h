///////////////////////////////////////////////////////////
//  FloorTile_Flat.h
//  Created on:      12-08-2009
//  Last modified:   12-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_FLOORTILE_FLAT_H
#define REGINA_FLOORTILE_FLAT_H

#include <d3dx9.h>

#include <FloorTile.h>

namespace Regina
{

class CFloorTile_Flat : public CFloorTile
{
public:
	CFloorTile_Flat(const D3DXVECTOR2& iCenter, const float& iSize, const float iHeightOffset = 0.0f, const float iRestitution = 1.0f);

	inline virtual float		GetHeight(const D3DXVECTOR3& iPosition);
	inline virtual D3DXVECTOR3	GetNormal(const D3DXVECTOR3& iPosition);

};

}


#endif
