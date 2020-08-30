///////////////////////////////////////////////////////////
//  Trigger_Respawning.h
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_TRIGGER_RESPAWNING_H
#define REGINA_TRIGGER_RESPAWNING_H

#include <Trigger.h>

namespace Regina
{

class CTrigger_Respawning : public CTrigger
{
	float respawningDelay;
	float timeUntilNextRespawn;

protected:
	void SetRespawningDelay(const float& iRespawningDelay)	{ respawningDelay = iRespawningDelay; }
	void Deactivate();

	float RespawningDelay()			const { return respawningDelay; }
	float TimeUntilNextRespawn()	const { return timeUntilNextRespawn; }	

public:
	CTrigger_Respawning() : respawningDelay(0), timeUntilNextRespawn(0) {}
	~CTrigger_Respawning() {}

	void Try(CCollisionObject_Dynamic iDynamicMesh) = 0;
	void Update(float duration);
};


}


#endif
