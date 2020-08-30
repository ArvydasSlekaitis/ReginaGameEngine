///////////////////////////////////////////////////////////
//  MessageDispatcher.h
//  Created on:      19-07-2008
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_MESSAGEDISPATCHER_H
#define REGINA_MESSAGEDISPATCHER_H

#include <vector>
#include <map>
#include <assert.h>
using namespace std;

#include <Telegram.h>
#include <BaseEntity.h>
#include <AIManager.h>


namespace Regina
{


class CMessageDispatcher
{
	multimap<float, CTelegram*> telegramQ;
	vector<CTelegram*>	preInitatedTelegrams;
	float* globalTime;

	CMessageDispatcher() : globalTime(NULL){}
	void Discharge(CTelegram* telegram, CBaseEntity* entity) { entity->HandleMsg(telegram); }

public:
	static CMessageDispatcher* Instance();
	void DispatchMsg(CTelegram* iTelegram);
	void UnregisterEntity(const unsigned& iID);
	void Update(); //Dispatche delayed messages
	void Init(float* iGlobalTime);
};

#define MessageDispatcher Regina::CMessageDispatcher::Instance()




}

#endif
