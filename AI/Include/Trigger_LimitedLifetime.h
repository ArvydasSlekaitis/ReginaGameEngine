///////////////////////////////////////////////////////////
//  Trigger_LimitedLifetime.h
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_TRIGGER_LIMITEDLIFETIME_H
#define REGINA_TRIGGER_LIMITEDLIFETIME_H

#include <Trigger.h>
#include <AIManager.h>

namespace Regina
{

class CTrigger_LimitedLifetime : public CTrigger
{
	float timeUntilDye;

protected:
	float TimeLeft() const { return timeUntilDye; }

public:
	CTrigger_LimitedLifetime(const float& iTimeUntilDye) : timeUntilDye(iTimeUntilDye) {}
	~CTrigger_LimitedLifetime() {}

	void Try(CCollisionObject_Dynamic iDynamicMesh) = 0;
	void Update(float duration);
};


}


#endif
