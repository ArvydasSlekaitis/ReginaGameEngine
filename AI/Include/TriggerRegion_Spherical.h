///////////////////////////////////////////////////////////
//  TriggerRegion_Spherical.h
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_TRIGGERREGION_SPHERICAL_H
#define REGINA_TRIGGERREGION_SPHERICAL_H

#include <Functions_Math.h>
#include <TriggerRegion.h>

namespace Regina
{

class CTriggerRegion_Spherical : public CTriggerRegion
{
	D3DXVECTOR3 position;
	float		radius;

public:
	CTriggerRegion_Spherical(const D3DXVECTOR3& iPosition, const float& iRadius) : position(iPosition), radius(iRadius) {}
	bool Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius);	
};


}


#endif
