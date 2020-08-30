///////////////////////////////////////////////////////////
//  Entity_Statue.h
//  Created on:      25-08-2009
//  Last modified:   25-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef ENTITY_STATUE_H
#define ENTITY_STATUE_H

#include <exception>
using namespace std;

#include <BaseEntity.h>
#include <AIManager.h>
#include <CollisionMesh.h>
using namespace Regina;


class CEntity_Statue : public CBaseEntity
{
	D3DXVECTOR3		position;

public:
	CEntity_Statue();
	virtual ~CEntity_Statue();

	virtual void Update(float duration);
	virtual void HandleMsg(CTelegram* iTelegram) { delete iTelegram; }
	virtual void Load(const vector<string>& iText);
};

#endif