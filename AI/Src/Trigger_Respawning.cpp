///////////////////////////////////////////////////////////
//  Trigger_Respawning.cpp
//  Created on:      01-09-2009
//  Last modified:   01-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Trigger_Respawning.h>
using namespace Regina;

//*****************************************************************************

void CTrigger_Respawning::Update(float duration)
	{
	if(Inactive() == true)
		{
		timeUntilNextRespawn -= duration;

		if(timeUntilNextRespawn <= 0)
			Activate();
		}
	}

//*****************************************************************************

void CTrigger_Respawning::Deactivate() 
	{ 
	CTrigger::Deactivate(); 
	timeUntilNextRespawn = respawningDelay; 
	}

//*****************************************************************************

