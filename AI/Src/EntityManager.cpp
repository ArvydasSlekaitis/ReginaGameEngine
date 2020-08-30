///////////////////////////////////////////////////////////
//  EntityManager.cpp
//  Created on:      18-07-2008
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <EntityManager.h>
using namespace Regina;

//******************************************************************************

CEntityManager::CEntityManager() : TFastAccessManager<CBaseEntity>(1, 64000)
	{
	}

//******************************************************************************

void CEntityManager::Unregister(CBaseEntity* iBaseEntity)
	{
	}

//******************************************************************************


