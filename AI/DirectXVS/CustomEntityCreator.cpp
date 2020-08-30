///////////////////////////////////////////////////////////
//  CustomEntityCreator.cpp
//  Created on:      20-08-2009
//  Last modified:   20-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CustomEntityCreator.h>
using namespace Regina;

//*****************************************************************************

CBaseEntity* CCustomEntityCreator::Create(const string& iClassName, LPDIRECT3DDEVICE9 iDevice)
	{
	CBaseEntity* entity(NULL);

	if(iClassName == "EntitySphere")
		entity = new CEntity_Sphere();

	if(iClassName == "EntityStatue")
		entity = new CEntity_Statue();

	if(iClassName == "EntityDarkSmile")
		entity = new CEntity_DarkSmile();

	
	return entity;
	}

//*****************************************************************************
	