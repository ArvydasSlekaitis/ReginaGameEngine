///////////////////////////////////////////////////////////
//  EntityCreator.h
//  Created on:      25-07-2008
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_ENTITYCREATOR_H
#define REGINA_ENTITYCREATOR_H

#include <d3dx9.h>

#include <BaseEntity.h>

namespace Regina
{

class CEntityCreator
{
public:
virtual ~CEntityCreator(){}
virtual CBaseEntity* Create(const string& iClassName, LPDIRECT3DDEVICE9 iDevice) = 0;
};

}


#endif