///////////////////////////////////////////////////////////
//  TriggerRegion_Spherical.cpp
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <TriggerRegion_Spherical.h>
using namespace Regina;

//*****************************************************************************

bool CTriggerRegion_Spherical::Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius)
	{
	const float distance_sq = Distance_Sq(iSpherePosition, position);
	return (distance_sq < (iSphereRadius + radius)*(iSphereRadius + radius));
	}

//*****************************************************************************