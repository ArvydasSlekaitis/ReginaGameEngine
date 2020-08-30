///////////////////////////////////////////////////////////
//  Functions_Math.h
//  Created on:      05-09-2008
//  Last modified:   23-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_FUNCTIONS_MATH_H
#define REGINA_FUNCTIONS_MATH_H

#include <d3dx9.h>

#include <vector>
#include <exception>
#include <limits>
#include <assert.h>
using namespace std;


namespace Regina
{

//*****************************************************************************

static float Distance(float iX1, float iY1, float iZ1, float iX2, float iY2, float iZ2) 
	{
	float x=iX1 - iX2;
	float y=iY1 - iY2;
	float z=iZ1 - iZ2;
	float xyz=x*x+y*y+z*z;

	if(xyz > 0.0f)
		return sqrt(xyz);
	else
		return 0.0f;
	}

//*****************************************************************************

static float Distance_Sq(float iX1, float iY1, float iZ1, float iX2, float iY2, float iZ2)
{
	float x=iX1 - iX2;
	float y=iY1 - iY2;
	float z=iZ1 - iZ2;

	return x*x+y*y+z*z;
}

//*****************************************************************************

static float Distance(float iX1, float iY1, float iX2, float iY2)
{
	float x=iX1 - iX2;
	float y=iY1 - iY2;
	float xy=x*x+y*y;

	if(xy > 0.0f)
		return sqrt(xy);
	else
		return 0.0f;
}

//*****************************************************************************

static float Distance_Sq(float iX1, float iY1, float iX2, float iY2)
{
	float x=iX1 - iX2;
	float y=iY1 - iY2;

	return x*x+y*y;
}

//*****************************************************************************

static void CalculateLineNormal(const float& iX1, const float& iY1, const float& iX2, const float& iY2, D3DXVECTOR2& oNormal)
{
float dy = iY2 - iY1;
if(dy == 0.0f)
	{
	oNormal.y=1;
	oNormal.x=0;
	return;
	}

float dx = iX2 - iX1;
if(dx == 0.0f)
	{
	oNormal.y=0;
	oNormal.x=1;
	return;
	}

oNormal.x = iX1;
if(oNormal.x == 0.0f)
	oNormal.x = iX2;

oNormal.y = -(dx/dy)*oNormal.x;

D3DXVec2Normalize(&oNormal, &oNormal);
}

//*****************************************************************************

static void CalculateLineParams(const float& iX1, const float& iY1, const float& iX2, const float& iY2, D3DXVECTOR2& oNormal, float& oK, float& oB)
{
float dy = iY2 - iY1;
if(dy == 0.0f)
	{
	oNormal.y=1;
	oNormal.x=0;
	oK = 0;
	oB = iY1;
	return;
	}

float dx = iX2 - iX1;
if(dx == 0.0f)
	{
	oNormal.y=0;
	oNormal.x=1;
	oK = numeric_limits<float>::infinity(); 
	oB = iY1;
	return;
	}

oNormal.x = iX1;
if(oNormal.x == 0.0f)
	oNormal.x = iX2;

oK= dy/dx;
oB= iY1 - oK*iX1;

oNormal.y = -(dx/dy)*oNormal.x;

D3DXVec2Normalize(&oNormal, &oNormal);
}

//*****************************************************************************

static inline float sgn(const float& x)
	{
	if(x<0) return -1;
	else	return 1;
	}

//*****************************************************************************

static unsigned LineCircleIntersection(float iLineBeginX, float iLineBeginY, float iLineEndX, float iLineEndY, const float& iCircleCenterX, const float& iCircleCenterY, const float& iCircleRadius, float& oX1, float& oY1, float& oX2, float& oY2, float& oPenetration)
	{
	float minX = min(iLineBeginX, iLineEndX);
	float maxX = max(iLineBeginX, iLineEndX);

	float minY = min(iLineBeginY, iLineEndY);
	float maxY = max(iLineBeginY, iLineEndY);

	iLineBeginX -= iCircleCenterX;
	iLineEndX	-= iCircleCenterX;
	
	iLineBeginY -= iCircleCenterY;
	iLineEndY	-= iCircleCenterY;

		float dx = iLineEndX - iLineBeginX;
		float dy = iLineEndY - iLineBeginY;

		float dr = sqrt ( dx*dx + dy*dy );
		float D = iLineBeginX*iLineEndY -  iLineEndX*iLineBeginY;

		float discriminant = iCircleRadius*iCircleRadius*dr*dr-D*D;
		if(discriminant <= 0)
			{
			return 0;
			}
		else
			{
			float dxx = sgn(dy)*dx*sqrt(discriminant);
			float dyy = abs(dy)*sqrt(discriminant);

			float X1 = (D*dy + dxx)/(dr*dr) + iCircleCenterX;
			float Y1 = (-D*dx + dyy)/(dr*dr) + iCircleCenterY;
			
			float X2 = (D*dy - dxx)/(dr*dr) + iCircleCenterX;
			float Y2 = (-D*dx - dyy)/(dr*dr) + iCircleCenterY;

			float halfDist = Distance(X1, Y1, X2, Y2)/2;
			oPenetration = sqrt(iCircleRadius*iCircleRadius - halfDist*halfDist);

			if(X1 >= minX && X1 <=maxX && Y1 >= minY && Y1 <= maxY)
				{
				if(X2 >= minX && X2 <=maxX && Y2 >= minY && Y2 <= maxY)
					{
					oX1 = X1;
					oY1 = Y1;
					oX2 = X2;
					oY2 = Y2;

					return 2;
					}
				else
					{
					oX1 = X1;
					oY1 = Y1;
					return 1;
					}
				}
			else 
				{
				if(X2 >= minX && X2 <=maxX && Y2 >= minY && Y2 <= maxY)
					{
					oX1 = X1;
					oY1 = Y1;
					return 1;
					}
				else
					return 0;
				}
			}
	}

//*****************************************************************************

static unsigned LineCircleIntersection(float iLineBeginX, float iLineBeginY, float iLineEndX, float iLineEndY, const float& iMinX, const float& iMaxX, const float& iMinY, const float& iMaxY, const float& iCircleCenterX, const float& iCircleCenterY, const float& iCircleRadius, float& oX1, float& oY1, float& oX2, float& oY2, float& oPenetration)
	{
	iLineBeginX -= iCircleCenterX;
	iLineEndX	-= iCircleCenterX;
	
	iLineBeginY -= iCircleCenterY;
	iLineEndY	-= iCircleCenterY;

		float dx = iLineEndX - iLineBeginX;
		float dy = iLineEndY - iLineBeginY;

		float dr = sqrt ( dx*dx + dy*dy );
		float D = iLineBeginX*iLineEndY -  iLineEndX*iLineBeginY;

		float discriminant = iCircleRadius*iCircleRadius*dr*dr-D*D;
		if(discriminant <= 0)
			{
			return 0;
			}
		else
			{
			float dxx = sgn(dy)*dx*sqrt(discriminant);
			float dyy = abs(dy)*sqrt(discriminant);

			float X1 = (D*dy + dxx)/(dr*dr) + iCircleCenterX;
			float Y1 = (-D*dx + dyy)/(dr*dr) + iCircleCenterY;
			
			float X2 = (D*dy - dxx)/(dr*dr) + iCircleCenterX;
			float Y2 = (-D*dx - dyy)/(dr*dr) + iCircleCenterY;

			float middlePointX = (X2 + X1)/2;
			float middlePointY = (Y2 + Y1)/2;

			oPenetration = iCircleRadius - Distance(middlePointX, middlePointY, iCircleCenterX, iCircleCenterY);

			if(X1 >= iMinX && X1 <=iMaxX && Y1 >= iMinY && Y1 <= iMaxY)
				{
				if(X2 >= iMinX && X2 <=iMaxX && Y2 >= iMinY && Y2 <= iMaxY)
					{
					oX1 = X1;
					oY1 = Y1;
					oX2 = X2;
					oY2 = Y2;

					return 2;
					}
				else
					{
					oX1 = X1;
					oY1 = Y1;
					return 1;
					}
				}
			else 
				{
				if(X2 >= iMinX && X2 <=iMaxX && Y2 >= iMinY && Y2 <= iMaxY)
					{
					oX1 = X1;
					oY1 = Y1;
					return 1;
					}
				else
					return 0;
				}
			}
	}

//*****************************************************************************

static void GenerateVertices_Box(const D3DXVECTOR3& iHalfSize, vector<D3DXVECTOR3>& oVertices)
	{
	oVertices.push_back(D3DXVECTOR3(-iHalfSize.x, -iHalfSize.y, -iHalfSize.z));
	oVertices.push_back(D3DXVECTOR3(-iHalfSize.x, -iHalfSize.y, iHalfSize.z));
	oVertices.push_back(D3DXVECTOR3(-iHalfSize.x, iHalfSize.y, -iHalfSize.z));
	oVertices.push_back(D3DXVECTOR3(-iHalfSize.x, iHalfSize.y, iHalfSize.z));
	oVertices.push_back(D3DXVECTOR3(iHalfSize.x, -iHalfSize.y, -iHalfSize.z));
	oVertices.push_back(D3DXVECTOR3(iHalfSize.x, -iHalfSize.y, iHalfSize.z));
	oVertices.push_back(D3DXVECTOR3(iHalfSize.x, iHalfSize.y, -iHalfSize.z));
	oVertices.push_back(D3DXVECTOR3(iHalfSize.x, iHalfSize.y, iHalfSize.z));
	}

//*****************************************************************************

static float VectorToRotation(const float& iX, const float& iY)
	{
	//iX and iY must be coordinates of normalized vector
	//Assuming y==0 is the orign
	float rot = acos(iY);
	if(iX < 0)
		rot = D3DX_PI*2 - rot;

	return rot;
	}

//*****************************************************************************

static D3DXMATRIX Transform(const float& iPositionX, const float& iPositionY, const float& iPositionZ, const float& iScale, const float& iRotationY)
{
const float siny = sin(iRotationY);
const float cosy = cos(iRotationY);

return D3DXMATRIXA16(	iScale*cosy,		0,		 -iScale*siny,		0,
							 0,		 	 iScale,	      0,			0,
						iScale*siny,		0,		  iScale*cosy, 		0,
						iPositionX, 	iPositionY,  iPositionZ,     	1   );
}

//*****************************************************************************

static inline float Distance(D3DXVECTOR3 iPosition1, D3DXVECTOR3 iPosition2) { return Distance(iPosition1.x, iPosition1.y, iPosition1.z, iPosition2.x, iPosition2.y, iPosition2.z); }
static inline float Distance_Sq(D3DXVECTOR3 iPosition1, D3DXVECTOR3 iPosition2) { return Distance_Sq(iPosition1.x, iPosition1.y, iPosition1.z, iPosition2.x, iPosition2.y, iPosition2.z); }
static inline float Distance(D3DXVECTOR2 iPosition1, D3DXVECTOR2 iPosition2) { return Distance(iPosition1.x, iPosition1.y, iPosition2.x, iPosition2.y); }
static inline float Distance_Sq(D3DXVECTOR2 iPosition1, D3DXVECTOR2 iPosition2) { return Distance_Sq(iPosition1.x, iPosition1.y, iPosition2.x, iPosition2.y); }
static inline void CalculateLineNormal(const D3DXVECTOR2& iPosition1, const D3DXVECTOR2& iPosition2, D3DXVECTOR2& oNormal) { CalculateLineNormal(iPosition1.x, iPosition1.y, iPosition2.x, iPosition2.y, oNormal); }
static inline void CalculateLineParams(const D3DXVECTOR2& iPosition1, const D3DXVECTOR2& iPosition2, D3DXVECTOR2& oNormal, float& oK, float& oB) { CalculateLineParams(iPosition1.x, iPosition1.y, iPosition2.x, iPosition2.y, oNormal, oK, oB); }
static inline float VectorToRotation(const D3DXVECTOR2& iVector) { return VectorToRotation(iVector.x, iVector.y); }
static inline D3DXMATRIX Transform(const D3DXVECTOR3& iPosition, const float& iScale, const float& iRotationY) { return Transform(iPosition.x, iPosition.y, iPosition.z, iScale, iRotationY); }

//*****************************************************************************




}

#endif