///////////////////////////////////////////////////////////
//  FloorTile.cpp
//  Created on:      12-08-2009
//  Last modified:   12-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <FloorTile.h>
using namespace Regina;

//*****************************************************************************
	
CFloorTile::CFloorTile(const D3DXVECTOR2& iCenter, const float& iSize, const float iHeightOffset, const float iRestitution) : center(iCenter), size(iSize), heightOffset(iHeightOffset), restitution(iRestitution)
	{
	}

//*****************************************************************************

bool CFloorTile::BelongsToTile(const D3DXVECTOR3& iPosition)
	{
	if(iPosition.x >= center.x - size/2 && iPosition.x < center.x + size/2 && iPosition.z >= center.y - size/2 && iPosition.z < center.y + size/2)
		return true;
	else
		return false;
	}

//*****************************************************************************
