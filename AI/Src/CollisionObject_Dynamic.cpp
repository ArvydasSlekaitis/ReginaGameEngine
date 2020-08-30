///////////////////////////////////////////////////////////
//  CollisionObject_Dynamic.cpp
//  Created on:      07-09-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CollisionObject_Dynamic.h>
using namespace Regina;

//*****************************************************************************
	
CCollisionObject_Dynamic::CCollisionObject_Dynamic(CCollisionObject_Dynamic_Data* iData) 
	{
	if(iData == NULL)
		throw invalid_argument("CCollisionObject_Dynamic::CCollisionObject_Dynamic - argument iData==NULL");
	else
		data = iData;
	}


//*****************************************************************************
