///////////////////////////////////////////////////////////
//  CollisionObject_Static.cpp
//  Created on:      07-09-2009
//  Last modified:   07-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CollisionObject_Static.h>
using namespace Regina;

//*****************************************************************************
	
CCollisionObject_Static::CCollisionObject_Static(CCollisionObject_Static_Data* iData) 
	{
	if(iData == NULL)
		throw invalid_argument("CCollisionObject_Static::CCollisionObject_Static - argument iData==NULL");
	else
		data = iData;
	}


//*****************************************************************************
