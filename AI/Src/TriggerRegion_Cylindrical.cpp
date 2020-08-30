///////////////////////////////////////////////////////////
//  TriggerRegion_Cylindrical.cpp
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <TriggerRegion_Cylindrical.h>
using namespace Regina;

//*****************************************************************************

bool CTriggerRegion_Cylindrical::Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius)
	{
	if(abs(iSpherePosition.y - position.y) >= halfHeight) return false;

	const float distance_sq = Distance_Sq(D3DXVECTOR2(iSpherePosition.x, iSpherePosition.z), D3DXVECTOR2(position.x, position.z));
	return (distance_sq < (iSphereRadius + radius)*(iSphereRadius + radius));
	}

//*****************************************************************************