///////////////////////////////////////////////////////////
//  TriggerRegion.h
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_TRIGGERREGION_H
#define REGINA_TRIGGERREGION_H

namespace Regina
{

class CTriggerRegion
{

public:
	virtual ~CTriggerRegion() {}
	virtual bool Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius) = 0;
};


}


#endif
