///////////////////////////////////////////////////////////
//  FloorTile_Flat.cpp
//  Created on:      12-08-2009
//  Last modified:   12-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <FloorTile_Flat.h>
using namespace Regina;

//*****************************************************************************
	
CFloorTile_Flat::CFloorTile_Flat(const D3DXVECTOR2& iCenter, const float& iSize, const float iHeightOffset, const float iRestitution) : CFloorTile(iCenter, iSize, iHeightOffset, iRestitution)
	{
	}

//*****************************************************************************

float CFloorTile_Flat::GetHeight(const D3DXVECTOR3& iPosition)
	{
	return heightOffset;
	}

//*****************************************************************************

D3DXVECTOR3 CFloorTile_Flat::GetNormal(const D3DXVECTOR3& iPosition)
	{
	return D3DXVECTOR3(0, 1, 0);
	}

//*****************************************************************************
