///////////////////////////////////////////////////////////
//  FloorTile.h
//  Created on:      12-08-2009
//  Last modified:   12-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_FLOORTILE_H
#define REGINA_FLOORTILE_H

#include <d3dx9.h>

namespace Regina
{

class CFloorTile
{
protected:
	float				heightOffset;
	float				restitution;
	const D3DXVECTOR2	center;
	const float			size;

public:
	CFloorTile(const D3DXVECTOR2& iCenter, const float& iSize, const float iHeightOffset = 0.0f, const float iRestitution = 1.0f);

	virtual float		GetHeight(const D3DXVECTOR3& iPosition) = 0;
	virtual D3DXVECTOR3 GetNormal(const D3DXVECTOR3& iPosition) = 0;
	bool				BelongsToTile(const D3DXVECTOR3& iPosition);

	void SetHeightOffset(const float& iHeightOffset) { heightOffset = iHeightOffset; }
	void SetRestitution(const float& iRestitution) { restitution = iRestitution; }

	float		HeightOffset()	const { return heightOffset; }
	float		Restitution()	const { return restitution; }
	D3DXVECTOR2 Center()		const { return center; }
	float		Size()			const { return size; }

};

}


#endif
