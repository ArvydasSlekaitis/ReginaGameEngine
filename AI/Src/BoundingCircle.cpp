///////////////////////////////////////////////////////////
//  BoundingCircle.cpp
//  Created on:      23-06-2009
//  Last modified:   23-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <BoundingCircle.h>
using namespace Regina;

//*****************************************************************************

void CBoundingCircle::IncreaseRadius(float iX, float iY, float iRadius)
	{
	float distance = Distance(position.x, position.y, iX, iY) + iRadius;
	if(radius < distance)
		radius = distance;
	}

//*****************************************************************************
