///////////////////////////////////////////////////////////
//  Line_2D.h
//  Created on:      25-06-2009
//  Last modified:   21-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_LINE_2D_H
#define REGINA_LINE_2D_H

#include <d3dx9.h>

#include <exception>
#include <assert.h>
using namespace std;

#include <Functions_Math.h>

namespace Regina
{

class CLine_2D
{
private:
	D3DXVECTOR2 begin;
	D3DXVECTOR2 end;
	D3DXVECTOR2 normal;
	D3DXVECTOR2 center;
	float		length_Sq;
	float		k;
	float		b;
	float		minX;
	float		maxX;
	float		minY;
	float		maxY;

	void RecalculateLineParams();

public:
	CLine_2D(const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd, const D3DXVECTOR2& iNormal, const float& iK, const float& iB);
	CLine_2D(const float& iBeginX, const float& iBeginY, const float& iEndX, const float& iEndY, const float& iNormalX, const float& iNormalY, const float& iK, const float& iB);

	CLine_2D(const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd, const D3DXVECTOR2& iNormal);
	CLine_2D(const float& iBeginX, const float& iBeginY, const float& iEndX, const float& iEndY, const float& iNormalX, const float& iNormalY);

	CLine_2D(const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd);
	CLine_2D(const float& iBeginX, const float& iBeginY, const float& iEndX, const float& iEndY);
	
	
	D3DXVECTOR2 Begin()		const { return begin; }
	D3DXVECTOR2 End()		const { return end; }
	D3DXVECTOR2 Normal()	const { return normal; }
	float		K()			const { return k; }
	float		B()			const { return b; }
	float		MinX()		const { return minX; }
	float		MaxX()		const { return maxX; }
	float		MinY()		const { return minY; }
	float		MaxY()		const { return maxY; }
	D3DXVECTOR2 Center()    const { return center; }
	float		Length()		  { return sqrt(length_Sq); }
	float		Length_Sq() const { return length_Sq; } 	

	unsigned	Intersect(const float& iCircleCenterX, const float& iCircleCenterY, const float& iCircleRadius, float& oX1, float& oY1, float& oX2, float& oY2, float& oPenetration);
	unsigned	Intersect(const D3DXVECTOR2& iCircleCenter, const float& iCircleRadius, float& oX1, float& oY1, float& oX2, float& oY2, float& oPenetration) { return Intersect(iCircleCenter.x, iCircleCenter.y, iCircleRadius, oX1, oY1, oX2, oY2, oPenetration); }
	bool		Intersect(const D3DXVECTOR2& iCircleCenter, const float& iCircleRadius);
	bool		Intersect(const D3DXVECTOR2& iVectorBegin, const D3DXVECTOR2& iVectorEnd, D3DXVECTOR2* oIntersectionPoint = NULL);
	
	bool		BelongsToLine(const D3DXVECTOR2& iCoordinates) { return BelongsToLine(iCoordinates.x, iCoordinates.y); }
	bool		BelongsToLine(const float& iX, const float& iY);

	void SetBegin(const D3DXVECTOR2& iBegin);
	void SetEnd(const D3DXVECTOR2& iEnd);

	void SetBegin(const float& iBeginX, const float& iBeginY) { SetBegin(D3DXVECTOR2(iBeginX, iBeginY)); }
	void SetEnd(const float& iEndX, const float& iEndY) { SetEnd(D3DXVECTOR2(iEndX, iEndY)); }
};

}

#endif