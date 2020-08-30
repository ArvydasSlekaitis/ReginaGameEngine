///////////////////////////////////////////////////////////
//  Trigger.h
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_TRIGGER_H
#define REGINA_TRIGGER_H

#include <BaseEntity.h>
#include <TriggerRegion.h>
#include <TriggerRegion_Spherical.h>
#include <TriggerRegion_Cubic.h>
#include <TriggerRegion_Cylindrical.h>
#include <CollisionObject_Dynamic.h>
#include <BasicTypeEnumaration.h>

namespace Regina
{

class CTrigger : public CBaseEntity
{
	CTriggerRegion*	triggerRegion;
	bool			active;

protected:
	bool	Active()	const { return active; }
	bool	Inactive()	const { return !active; }
	
	void	Activate()		{ active = true; }
	void	Deactivate()	{ active = false; }

	bool	Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius);

	void	SetTriggerRegion_Cubic(const D3DXVECTOR3& iPosition, const D3DXVECTOR3& iHalfSize);
	void	SetTriggerRegion_Spherical(const D3DXVECTOR3& iPosition, const float& iRadius);
	void	SetTriggerRegion_Cylindrical(const D3DXVECTOR3& iPosition, const float& iRadius, const float& iHalfHeight);

public:
	CTrigger();
	virtual ~CTrigger();

	virtual void Try(CCollisionObject_Dynamic iDynamicMesh) = 0;
};


}


#endif
