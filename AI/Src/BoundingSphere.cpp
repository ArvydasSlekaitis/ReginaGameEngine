///////////////////////////////////////////////////////////
//  BoundingSphere.cpp
//  Created on:      23-06-2009
//  Last modified:   23-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <BoundingSphere.h>
using namespace Regina;

//*****************************************************************************

void CBoundingSphere::IncreaseRadius(float iX, float iY, float iZ, float iRadius)
	{
	float distance = Distance(position.x, position.y, position.z, iX, iY, iZ) + iRadius;
	if(radius < distance)
		radius = distance;
	}

//*****************************************************************************
