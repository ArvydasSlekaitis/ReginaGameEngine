///////////////////////////////////////////////////////////
//  Trigger.cpp
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Trigger.h>
using namespace Regina;

//*****************************************************************************

CTrigger::CTrigger() : triggerRegion(NULL), active(true), CBaseEntity("Trigger", BasicTypeID::type_Trigger)
	{
	}

//*****************************************************************************

CTrigger::~CTrigger()
	{
	if(triggerRegion!=NULL)
		delete triggerRegion;
	}

//*****************************************************************************

bool CTrigger::Intersect(const D3DXVECTOR3& iSpherePosition, const float& iSphereRadius)
	{
	if(triggerRegion==NULL)
		throw logic_error("CTrigger::Intersect - no trigger region is defines");

	return triggerRegion->Intersect(iSpherePosition, iSphereRadius);
	}

//*****************************************************************************

void CTrigger::SetTriggerRegion_Cubic(const D3DXVECTOR3& iPosition, const D3DXVECTOR3& iHalfSize)
	{
	if(triggerRegion!=NULL)
		delete triggerRegion;
	
	triggerRegion = new CTriggerRegion_Cubic(iPosition, iHalfSize);
	}

//*****************************************************************************

void CTrigger::SetTriggerRegion_Spherical(const D3DXVECTOR3& iPosition, const float& iRadius)
	{
	if(triggerRegion!=NULL)
		delete triggerRegion;
	
	triggerRegion = new CTriggerRegion_Spherical(iPosition, iRadius);
	}

//*****************************************************************************

void CTrigger::SetTriggerRegion_Cylindrical(const D3DXVECTOR3& iPosition, const float& iRadius, const float& iHalfHeight)
	{
	if(triggerRegion!=NULL)
		delete triggerRegion;
	
	triggerRegion = new CTriggerRegion_Cylindrical(iPosition, iRadius, iHalfHeight);
	}

//*****************************************************************************
