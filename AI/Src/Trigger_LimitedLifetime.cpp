///////////////////////////////////////////////////////////
//  Trigger_LimitedLifetime.cpp
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Trigger_LimitedLifetime.h>
using namespace Regina;

//*****************************************************************************

void CTrigger_LimitedLifetime::Update(float duration)
	{
	timeUntilDye -= duration;

	if(timeUntilDye <= 0)
		AIManager->RemoveEntity(this);
	}

//*****************************************************************************


