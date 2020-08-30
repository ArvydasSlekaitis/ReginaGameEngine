///////////////////////////////////////////////////////////
//  CollisionObject_ParticlePhisics.cpp
//  Created on:      30-07-2009
//  Last modified:   30-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CollisionObject_ParticlePhisics.h>
using namespace Regina;

//*****************************************************************************
	
CCollisionObject_ParticlePhisics::CCollisionObject_ParticlePhisics(CCollisionObject_ParticlePhisics_Data* iData) 
	{
	if(iData == NULL)
		throw invalid_argument("CCollisionObject_ParticlePhisics::CCollisionObject_ParticlePhisics - argument iData==NULL");
	else
		data = iData;
	}


//*****************************************************************************
