///////////////////////////////////////////////////////////
//  TriggerRegion_Cubic.h
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_TRIGGERREGION_CUBIC_H
#define REGINA_TRIGGERREGION_CUBIC_H

#include <Functions_Math.h>
#include <TriggerRegion.h>

namespace Regina
{

class CTriggerRegion_Cubic : public CTriggerRegion
{
	D3DXVECTOR3 position;
	D3DXVECTOR3 halfSize;

public:
	CTriggerRegion_Cubic(const D3DXVECTOR3& iPosition, const D3DXVECTOR3& iHalfSize) : position(iPosition), halfSize(iHalfSize) {}
	bool Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius);	
};


}


#endif
