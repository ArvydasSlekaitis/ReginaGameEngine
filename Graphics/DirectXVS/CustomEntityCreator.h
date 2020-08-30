///////////////////////////////////////////////////////////
//  CustomEntityCreator.h
//  Created on:      20-08-2009
//  Last modified:   20-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef CUSTOMENTITYCREATOR_H
#define CUSTOMENTITYCREATOR_H

#include <EntityCreator.h>
#include <Entity_Sphere.h>
#include <Entity_Statue.h>
#include <Entity_DarkSmile.h>
using namespace Regina;


class CCustomEntityCreator : public CEntityCreator
{
public:
virtual ~CCustomEntityCreator(){}
virtual CBaseEntity* Create(const string& iClassName, LPDIRECT3DDEVICE9 iDevice);
};


#endif