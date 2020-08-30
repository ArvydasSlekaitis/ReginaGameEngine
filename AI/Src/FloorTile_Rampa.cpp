///////////////////////////////////////////////////////////
//  FloorTile_Rampa.cpp
//  Created on:      12-08-2009
//  Last modified:   12-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <FloorTile_Rampa.h>
using namespace Regina;

//*****************************************************************************
	
CFloorTile_Rampa::CFloorTile_Rampa(const D3DXVECTOR2& iCenter, const float& iSize, const float& iRotation, const float& iSlope, const float iHeightOffset, const float iRestitution) : CFloorTile(iCenter, iSize, iHeightOffset, iRestitution), rotation(iRotation), slope(iSlope)
	{
	}

//*****************************************************************************

float CFloorTile_Rampa::GetHeight(const D3DXVECTOR3& iPosition)
	{
	if(rotation == 0)
		return heightOffset + slope*(iPosition.z - center.y + size/2);
	else
	if(rotation == 90)
		return heightOffset + slope*(iPosition.x - center.x + size/2);
	else
	if(rotation == 180)
		return heightOffset - slope*(iPosition.z - center.y - size/2);
	else
	if(rotation == 270)
		return heightOffset - slope*(iPosition.x - center.x - size/2);
	}

//*****************************************************************************

D3DXVECTOR3 CFloorTile_Rampa::GetNormal(const D3DXVECTOR3& iPosition)
	{
	D3DXVECTOR3 normal;


	if(rotation == 0)
		{
		normal.x = 0.0f;
		normal.z = -size;
		normal.y = (1/slope)*size;
		}
	
	else

	if(rotation == 90)
		{
		normal.x = -size;
		normal.z = 0;
		normal.y = (1/slope)*size;
		}


	if(rotation == 180)
		{
		normal.x = 0.0f;
		normal.z = size;
		normal.y = (1/slope)*size;
		}

	else

	if(rotation == 270)
		{
		normal.x = size;
		normal.z = 0;
		normal.y = (1/slope)*size;
		}

	D3DXVec3Normalize(&normal, &normal);

	return normal;
	}

//*****************************************************************************
