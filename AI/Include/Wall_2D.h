///////////////////////////////////////////////////////////
//  Wall_2D.h
//  Created on:      25-06-2009
//  Last modified:   25-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_WALL_2D_H
#define REGINA_WALL_2D_H

#include <Wall.h>
#include <Line_2D.h>

namespace Regina
{

class CWall_2D : public CWall, public CLine_2D
{
public:
	D3DXVECTOR3 Position()	const { return D3DXVECTOR3(Center().x, 0, Center().y); }
	float		Radius()		  { return Length()/2; }

	CWall_2D(const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd, const float iRestitution = 1.0f) : CWall(iRestitution), CLine_2D(iBegin, iEnd) {}
	CWall_2D(const float& iBeginX, const float& iBeginY, const float& iEndX, const float& iEndY, const float iRestitution = 1.0f) : CWall(iRestitution), CLine_2D(iBeginX, iBeginY, iEndX, iEndY) {}
	
};

}

#endif