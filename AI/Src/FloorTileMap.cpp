///////////////////////////////////////////////////////////
//  FloorTileMap.cpp
//  Created on:      12-08-2009
//  Last modified:   12-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <FloorTileMap.h>
using namespace Regina;

//*****************************************************************************
	
CFloorTileMap::CFloorTileMap(const unsigned& iGridSizeX, const unsigned& iGridSizeY, const float& iTileSize) : gridSizeX(iGridSizeX), gridSizeY(iGridSizeY), tileSize(iTileSize)
	{
	}

//*****************************************************************************

CFloorTileMap::CFloorTileMap(const unsigned& iGridSizeX, const unsigned& iGridSizeY, const float& iTileSize, vector<string> iText) : gridSizeX(iGridSizeX), gridSizeY(iGridSizeY), tileSize(iTileSize)
	{
	unsigned curGridX = 0;
	unsigned curGridY = 0;

	for(unsigned i=0; i<iText.size(); i++)
		{		
		istringstream line(iText[i]);
		string type;
		line >> type;
		if(type == "FloorTile_Flat")
			{
			D3DXVECTOR2 iCenter;
			iCenter.x = curGridX*iTileSize + iTileSize/2;
			iCenter.y = curGridY*iTileSize + iTileSize/2;

			float iHeightOffset;
			float iRestitution;
			line >> iHeightOffset >> iRestitution;
			
			tileMap.push_back(new CFloorTile_Flat(iCenter, iTileSize, iHeightOffset, iRestitution));
			curGridX++;

			if(curGridX+1>iGridSizeX)
				{
				curGridX=0;
				curGridY++;
				}

			}
		else
		if(type == "FloorTile_Rampa")
			{
			D3DXVECTOR2 iCenter;
			iCenter.x = curGridX*iTileSize + iTileSize/2;
			iCenter.y = curGridY*iTileSize + iTileSize/2;

			float iHeightOffset;
			float iRestitution;
			float iRotation;
			float iSlope;
			line >> iHeightOffset >> iRestitution >> iRotation >> iSlope;
			
			tileMap.push_back(new CFloorTile_Rampa(iCenter, iTileSize, iRotation, iSlope, iHeightOffset, iRestitution));
			curGridX++;

			if(curGridX+1>iGridSizeX)
				{
				curGridX=0;
				curGridY++;
				}

			}
			
		}
	}

//*****************************************************************************
	
float CFloorTileMap::GetHeight(const D3DXVECTOR3& iPosition)
	{
	CFloorTile* tile = GetTile(iPosition);
	if(tile!=NULL)
		return tile->GetHeight(iPosition);

	return 0;
	}

//*****************************************************************************

float CFloorTileMap::GetAverageHeight(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
		return 0;
	}

//*****************************************************************************

D3DXVECTOR3 CFloorTileMap::GetNormal(const D3DXVECTOR3& iPosition)
	{
	CFloorTile* tile = GetTile(iPosition);
	if(tile!=NULL)
		return tile->GetNormal(iPosition);

	return D3DXVECTOR3(0, 0, 0);
	}

//*****************************************************************************

bool CFloorTileMap::TileExist(const D3DXVECTOR3& iPosition)
	{
	return (GetTile(iPosition)!=NULL);
	}

//*****************************************************************************

bool CFloorTileMap::TileExist(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	return false;

	}

//*****************************************************************************

CFloorTile* CFloorTileMap::GetTile(const D3DXVECTOR3& iPosition)
	{
	unsigned tileX = (int)iPosition.x/tileSize;
	unsigned tileY = (int)iPosition.z/tileSize;
	if(tileX>=gridSizeX) return NULL;
	if(tileY>=gridSizeY) return NULL;
	CFloorTile* tile = tileMap[tileX + tileY*gridSizeX];
	
	if(tile->BelongsToTile(iPosition)==true)
		return tileMap[tileX + tileY*gridSizeX];
	else 
		return NULL;
	}

//*****************************************************************************

float CFloorTileMap::GetRestitution(const D3DXVECTOR3& iPosition)
	{
	CFloorTile* tile = GetTile(iPosition);
	if(tile!=NULL)
		return tile->Restitution();

	return 0;
	}

//*****************************************************************************
