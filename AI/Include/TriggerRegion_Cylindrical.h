///////////////////////////////////////////////////////////
//  TriggerRegion_Cylindrical.h
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_TRIGGERREGION_CYLINDRICAL_H
#define REGINA_TRIGGERREGION_CYLINDRICAL_H

#include <Functions_Math.h>
#include <TriggerRegion.h>

namespace Regina
{

class CTriggerRegion_Cylindrical : public CTriggerRegion
{
	D3DXVECTOR3 position;
	float		radius;
	float		halfHeight;

public:
	CTriggerRegion_Cylindrical(const D3DXVECTOR3& iPosition, const float& iRadius, const float& iHalfHeight) : position(iPosition), radius(iRadius), halfHeight(iHalfHeight) {}
	bool Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius);	
};


}


#endif
