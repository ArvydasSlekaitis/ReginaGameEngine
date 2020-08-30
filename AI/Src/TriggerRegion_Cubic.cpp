///////////////////////////////////////////////////////////
//  TriggerRegion_Cubic.cpp
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <TriggerRegion_Cubic.h>
using namespace Regina;

//*****************************************************************************

bool CTriggerRegion_Cubic::Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius)
	{
	D3DXVECTOR3 localSphere = iSpherePosition - position;

	if(abs(localSphere.x) - iSphereRadius >  halfSize.x) return false;
	if(abs(localSphere.y) - iSphereRadius >  halfSize.y) return false; 
	if(abs(localSphere.z) - iSphereRadius >  halfSize.z) return false;

	D3DXVECTOR3 closestPoint; // from sphere to box
	float distance;

	distance = localSphere.x;
	if(localSphere.x > halfSize.x) distance = halfSize.x;
	if(localSphere.x < -halfSize.x) distance = -halfSize.x;
	closestPoint.x = distance;

	distance = localSphere.y;
	if(localSphere.y > halfSize.y) distance = halfSize.y;
	if(localSphere.y < -halfSize.y) distance = -halfSize.y;
	closestPoint.y = distance;

	distance = localSphere.z;
	if(localSphere.z > halfSize.z) distance = halfSize.z;
	if(localSphere.z < -halfSize.z) distance = -halfSize.z;
	closestPoint.z = distance;

	distance = Distance_Sq(D3DXVECTOR3(localSphere.x, localSphere.y, localSphere.z), closestPoint);
	if(distance < iSphereRadius*iSphereRadius)
	return true;

	return false;
	}

//*****************************************************************************