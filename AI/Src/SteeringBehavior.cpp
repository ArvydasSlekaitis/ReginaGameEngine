///////////////////////////////////////////////////////////
//  SteeringBehavior.cpp
//  Created on:      05-09-2009
//  Last modified:   05-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SteeringBehavior.h>
using namespace Regina;

//*****************************************************************************

CSteeringBehavior::CSteeringBehavior(const std::string &iName, const unsigned int &iPriority, const float &iWeight, Regina::CMovingEntity *const iMovingEntity) : name(iName), priority(iPriority), weight(iWeight), movingEntity(iMovingEntity)
	{
	if(movingEntity == NULL)
		throw invalid_argument("CSteeringBehavior::CSteeringBehavior - argument iMovingEntity==NULL");
	}

//*****************************************************************************
