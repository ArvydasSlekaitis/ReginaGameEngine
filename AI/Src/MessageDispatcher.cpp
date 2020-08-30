///////////////////////////////////////////////////////////
//  MessageDispatcher.cpp
//  Created on:      20-07-2008
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <MessageDispatcher.h>
using namespace Regina;

//*****************************************************************************

CMessageDispatcher* CMessageDispatcher::Instance()
{
static CMessageDispatcher msgDisp;
return &msgDisp;
}


//*****************************************************************************

void CMessageDispatcher::DispatchMsg(CTelegram* iTelegram)
{
assert(globalTime!=NULL && L"Message dispatcher is not initialized");

if(globalTime!=NULL)
{
CBaseEntity* entity = AIManager->EntityFromID(iTelegram->Receiver());
if(entity!=NULL)
{
if(iTelegram->DispatchTime()<=0)
Discharge(iTelegram, entity);
else
{
telegramQ.insert(make_pair(iTelegram->DispatchTime()+(*globalTime), iTelegram));
}
}
}
else
preInitatedTelegrams.push_back(iTelegram);

}

//*****************************************************************************

void CMessageDispatcher::UnregisterEntity(const unsigned& iID)
{
multimap<float, CTelegram*>::iterator it = telegramQ.begin();
while(it!=telegramQ.end())
{
if(it->second->Receiver() == iID)
{
multimap<float, CTelegram*>::iterator ite = it;
it++;
telegramQ.erase(ite);
}
else
it++;
}
}

//*****************************************************************************

void CMessageDispatcher::Update()
{
assert(globalTime!=NULL && L"Message dispatcher is not initialized");

if(preInitatedTelegrams.size()>0)
{
for(unsigned i=0; i<preInitatedTelegrams.size(); i++)
DispatchMsg(preInitatedTelegrams[i]);
preInitatedTelegrams.clear();
}

multimap<float, CTelegram*>::iterator it = telegramQ.begin();
while(it!=telegramQ.end())
{
if(it->first <= *globalTime)
{
CBaseEntity* entity = AIManager->EntityFromID(it->second->Receiver());
if(entity!=NULL) Discharge(it->second, entity);

multimap<float, CTelegram*>::iterator ite = it;
it++;
telegramQ.erase(ite);
}
else
break;
}

}

//*****************************************************************************

void CMessageDispatcher::Init(float* iGlobalTime)
{
globalTime = iGlobalTime;
}

