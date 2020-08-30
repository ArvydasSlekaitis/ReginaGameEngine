///////////////////////////////////////////////////////////
//  EntityManager.h
//  Created on:      18-07-2008
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_ENTITYMANAGER_H
#define REGINA_ENTITYMANAGER_H

#include <deque>
#include <map>
#include <vector>
#include <string>
#include <exception>
using namespace std;

#include <BaseEntity.h>
#include <FastAccessManager.h>


namespace Regina
{

class CEntityManager : public TFastAccessManager<CBaseEntity>
{
protected:
	void Unregister(CBaseEntity* iBaseEntity); //Unregister entity object, with all AI modules;
	void SetID(CBaseEntity* iObject, const unsigned& iID) { iObject->id = iID; }

public:
	CEntityManager();
	~CEntityManager() { Clear(); }

	CBaseEntity* EntityFromID(const unsigned& iID) { return ObjectFromID(iID); }
};

}

#endif
