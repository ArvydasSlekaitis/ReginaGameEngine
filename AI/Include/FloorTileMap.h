///////////////////////////////////////////////////////////
//  FloorTileMap.h
//  Created on:      12-08-2009
//  Last modified:   12-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_FLOORTILEMAP_H
#define REGINA_FLOORTILEMAP_H

#include <d3dx9.h>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include <FloorTile.h>
#include <FloorTile_Flat.h>
#include <FloorTile_Rampa.h>

namespace Regina
{

class CFloorTileMap
{
	vector<CFloorTile*> tileMap;

	unsigned	gridSizeX;
	unsigned	gridSizeY;
	float		tileSize;

public:

	CFloorTileMap(const unsigned& iGridSizeX, const unsigned& iGridSizeY, const float& iTileSize);
	CFloorTileMap(const unsigned& iGridSizeX, const unsigned& iGridSizeY, const float& iTileSize, vector<string> iText);
	
	float		GetHeight(const D3DXVECTOR3& iPosition);
	float		GetAverageHeight(const D3DXVECTOR3& iPosition, const float& iRadius);
	D3DXVECTOR3 GetNormal(const D3DXVECTOR3& iPosition);
	bool		TileExist(const D3DXVECTOR3& iPosition);
	bool		TileExist(const D3DXVECTOR3& iPosition, const float& iRadius);
	float		GetRestitution(const D3DXVECTOR3& iPosition);
	CFloorTile* GetTile(const D3DXVECTOR3& iPosition);

};

}


#endif
