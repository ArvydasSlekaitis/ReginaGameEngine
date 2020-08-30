///////////////////////////////////////////////////////////
//  MovingEntity.cpp
//  Created on:      23-09-2009
//  Last modified:   15-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <MovingEntity.h>
using namespace Regina;

//*****************************************************************************

CMovingEntity::CMovingEntity(const string iClassName, const unsigned iType) : CBaseEntity(iClassName, iType), maxSpeed(0) 
	{
	}

//*****************************************************************************

