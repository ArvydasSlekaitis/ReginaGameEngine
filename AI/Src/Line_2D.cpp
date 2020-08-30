///////////////////////////////////////////////////////////
//  Line_2D.cpp
//  Created on:      25-06-2009
//  Last modified:   21-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Line_2D.h>
using namespace Regina;

//*****************************************************************************

CLine_2D::CLine_2D(const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd) : begin(iBegin), end(iEnd)
	{
	if(iBegin==iEnd)
		throw invalid_argument("CLine_2D::CLine_2D - Line begin point cannot be equal to its end point");
	
	RecalculateLineParams();
	}

//*****************************************************************************

CLine_2D::CLine_2D(const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd, const D3DXVECTOR2& iNormal) : begin(iBegin), end(iEnd)
	{
	if(iBegin==iEnd)
		throw invalid_argument("CLine_2D::CLine_2D - Line begin point cannot be equal to its end point");
	
	RecalculateLineParams();

	#ifndef NDEBUG
	float val = abs(D3DXVec2Dot(&normal, &iNormal));
	if(val < 0.999)
		throw invalid_argument("CLine_2D::CLine_2D - argument iNormal does not belong to two defined points");
	#endif

	normal = iNormal;
	}

//*****************************************************************************

CLine_2D::CLine_2D(const float& iBeginX, const float& iBeginY, const float& iEndX, const float& iEndY, const float& iNormalX, const float& iNormalY) : begin(D3DXVECTOR2(iBeginX, iBeginY)), end(D3DXVECTOR2(iEndX, iEndY))
	{
	if(begin==end)
		throw invalid_argument("CLine_2D::CLine_2D - Line begin point cannot be equal to its end point");
	
	RecalculateLineParams();

	#ifndef NDEBUG
	float val = abs(D3DXVec2Dot(&normal, &(D3DXVECTOR2(iNormalX, iNormalY))));
	if(val < 0.999)
		throw invalid_argument("CLine_2D::CLine_2D - argument iNormal does not belong to two defined points");
	#endif

	normal.x = iNormalX;
	normal.y = iNormalY;
	}

//*****************************************************************************

CLine_2D::CLine_2D(const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd, const D3DXVECTOR2& iNormal, const float& iK, const float& iB) : begin(iBegin), end(iEnd), normal(iNormal), k(iK), b(iB)
{
	if(begin==iEnd)
		throw invalid_argument("CLine_2D::CLine_2D - Line begin point cannot be equal to its end point");

	minX = min(iBegin.x, iEnd.x);
	maxX = max(iBegin.x, iEnd.x);

	minY = min(iBegin.y, iEnd.y);
	maxY = max(iBegin.y, iEnd.y);

	center.x = (begin.x+end.x)/2;
	center.y = (begin.y+end.y)/2;

	length_Sq = D3DXVec2LengthSq(&D3DXVECTOR2(end-begin)); 
}

//*****************************************************************************

CLine_2D::CLine_2D(const float& iBeginX, const float& iBeginY, const float& iEndX, const float& iEndY, const float& iNormalX, const float& iNormalY, const float& iK, const float& iB)
	{
	begin.x=iBeginX;
	begin.y=iBeginY;
	end.x=iEndX;
	end.y=iEndY;
	normal.x=iNormalX;
	normal.y=iNormalY;
	k = iK;
	b = iB;

	if(begin==end)
	throw invalid_argument("CLine_2D::CLine_2D - Line begin point cannot be equal to its end point");

	minX = min(begin.x, end.x);
	maxX = max(begin.x, end.x);

	minY = min(begin.y, end.y);
	maxY = max(begin.y, end.y);

	center.x = (begin.x+end.x)/2;
	center.y = (begin.y+end.y)/2;

	length_Sq = D3DXVec2LengthSq(&D3DXVECTOR2(end-begin)); 
	}

//*****************************************************************************

CLine_2D::CLine_2D(const float& iBeginX, const float& iBeginY, const float& iEndX, const float& iEndY)
	{
	begin.x=iBeginX;
	begin.y=iBeginY;
	end.x=iEndX;
	end.y=iEndY;

	if(begin==end)
	throw invalid_argument("CLine_2D::CLine_2D - Line begin point cannot be equal to its end point");

	RecalculateLineParams();
	}

//*****************************************************************************

void CLine_2D::SetBegin(const D3DXVECTOR2& iBegin)
	{
	begin = iBegin;

	if(iBegin==end)
	throw invalid_argument("CLine_2D::CLine_2D - Line begin point cannot be equal to its end point");

	RecalculateLineParams();
	}

//*****************************************************************************

void CLine_2D::SetEnd(const D3DXVECTOR2& iEnd)
	{
	end = iEnd;

	if(begin==iEnd)
	throw invalid_argument("CLine_2D::CLine_2D - Line begin point cannot be equal to its end point");

	RecalculateLineParams();
	}

//*****************************************************************************
	
void CLine_2D::RecalculateLineParams()
	{
	minX = min(begin.x, end.x);
	maxX = max(begin.x, end.x);

	minY = min(begin.y, end.y);
	maxY = max(begin.y, end.y);

	CalculateLineParams(begin, end, normal, k, b);

	center.x = (begin.x+end.x)/2;
	center.y = (begin.y+end.y)/2;

	length_Sq = D3DXVec2LengthSq(&D3DXVECTOR2(end-begin)); 
	}

//*****************************************************************************

unsigned CLine_2D::Intersect(const float& iCircleCenterX, const float& iCircleCenterY, const float& iCircleRadius, float& oX1, float& oY1, float& oX2, float& oY2, float& oPenetration)
	{
	if(k == numeric_limits<float>::infinity())
		{
		float diff = begin.x - iCircleCenterX;

		if(iCircleRadius <= abs(diff))
			{
			return 0;
			}
		else
			{
			float sq = sqrt(iCircleRadius*iCircleRadius - diff*diff);

			if(iCircleCenterY + sq >= minY &&  iCircleCenterY + sq <= maxY)
				{
				oX1 = begin.x;
				oY1 = iCircleCenterY + sq;
				
				oPenetration = iCircleRadius - abs(diff);

				if(iCircleCenterY - sq >= minY &&  iCircleCenterY - sq <= maxY)
					{
					oX2 = begin.x;
					oY2 = iCircleCenterY - sq;
					return 2;
					}
				else	
					return 1;
				}
			else
				{
				if(iCircleCenterY - sq >= minY &&  iCircleCenterY - sq <= maxY)
					{
					oX1 = begin.x;
					oY1 = iCircleCenterY - sq;
					return 1;
					}
				else 
					return 0;
				}
			} // end of iCircleRadius >= abs(diff)

		} // end of k == INFINITY
	else
	if(k == 0)
		{
		float diff = begin.y - iCircleCenterY;

		if(iCircleRadius <= abs(diff))
			{
			return 0;
			}
		else
			{
			float sq = sqrt(iCircleRadius*iCircleRadius - diff*diff);

			if(iCircleCenterX + sq >= minX &&  iCircleCenterX + sq <= maxX)
				{
				oX1 = iCircleCenterX + sq;
				oY1 = begin.y;
				
				oPenetration = iCircleRadius -  abs(diff);

				if(iCircleCenterX - sq >= minX &&  iCircleCenterX - sq <= maxX)
					{
					oX2 = iCircleCenterX - sq;
					oY2 =  begin.y;
					return 2;
					}
				else	
					return 1;
				}
			else
				{
				if(iCircleCenterX - sq >= minX &&  iCircleCenterX - sq <= maxX)
					{
					oX1 = iCircleCenterX - sq;
					oY1 =  begin.y;
					return 1;
					}
				else 
					return 0;
				}
			
			}

		} // end of k == 0
	else
		{
		return LineCircleIntersection(begin.x, begin.y, end.x, end.y, minX, maxX, minY, maxY, iCircleCenterX, iCircleCenterY, iCircleRadius, oX1, oY1, oX2, oY2, oPenetration);
		}

	}

//*****************************************************************************

bool CLine_2D::Intersect(const D3DXVECTOR2& iCircleCenter, const float& iCircleRadius)
	{
	float oX1, oY1, oX2, oY2, oPenetration;
	return (Intersect(iCircleCenter, iCircleRadius, oX1, oY1, oX2, oY2, oPenetration)!=0);
	}

//*****************************************************************************

bool CLine_2D::Intersect(const D3DXVECTOR2& iVectorBegin, const D3DXVECTOR2& iVectorEnd, D3DXVECTOR2* oIntersectionPoint)
	{
	CLine_2D tmpLine(iVectorBegin, iVectorEnd);

	if(K() == tmpLine.K())
		{
		if(BelongsToLine(iVectorBegin))
			{
			if(oIntersectionPoint!=NULL)
				*oIntersectionPoint = iVectorBegin;
			return true;
			}

		if(tmpLine.BelongsToLine(Begin()))
			{
			if(tmpLine.BelongsToLine(End()))
				{
				if(Distance_Sq(iVectorBegin, Begin()) > Distance_Sq(iVectorBegin, End()))
					{
					if(oIntersectionPoint!=NULL)
						*oIntersectionPoint = End();
					return true;
					}
				else
					{
					if(oIntersectionPoint!=NULL)
						*oIntersectionPoint = Begin();
					return true;
					}
				}
			else
				{
				if(oIntersectionPoint!=NULL)
					*oIntersectionPoint = Begin();
				return true;
				}
			}
		else
			{
			return false;
			}

		}

	float x = (tmpLine.B() - B())/(K() - tmpLine.K());
	float y;

	if(K() == numeric_limits<float>::infinity())
		{
		y=tmpLine.K()*x+tmpLine.B();
		}
	else
		{
		y=K()*x+B();
		}

	if(BelongsToLine(x, y) && tmpLine.BelongsToLine(x, y))
		{
		if(oIntersectionPoint!=NULL)
			*oIntersectionPoint = D3DXVECTOR2(x, y);
		return true;
		}
	else
		return false;
	}

//*****************************************************************************

bool CLine_2D::BelongsToLine(const float& iX, const float& iY)
	{
	if(iX >= minX && iX <= maxX && iY >= minY && iY <= maxY)
		return true;
	else
		return false;

	}