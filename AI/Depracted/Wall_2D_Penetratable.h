///////////////////////////////////////////////////////////
//  Wall_2D_Penetratable.h
//  Created on:      30-07-2009
//  Last modified:   30-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_WALL_2D_PENETRATABLE_H
#define REGINA_WALL_2D_PENETRATABLE_H

#include <Wall.h>
#include <Line_2D.h>

namespace Regina
{

class CWall_2D_Penetratable : public CWall, public CLine_2D
{
public:
	D3DXVECTOR3 Position()	const { return D3DXVECTOR3(Center().x, 0, Center().y); }
	float		Radius()		  { return Length(); }

	CWall_2D_Penetratable(const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd, const D3DXVECTOR2& iNormal, const float iRestitution = 1.0f) : CWall(iRestitution), CLine_2D(iBegin, iEnd, iNormal) {}
	CWall_2D_Penetratable(const float& iBeginX, const float& iBeginY, const float& iEndX, const float& iEndY, const float& iNormalX, const float& iNormalY, const float iRestitution = 1.0f) : CWall(iRestitution), CLine_2D(iBeginX, iBeginY, iEndX, iEndY, iNormalX, iNormalY) {}

};

}

#endif