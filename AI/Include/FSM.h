///////////////////////////////////////////////////////////
//  FSM.h
//  Created on:      19-07-2008
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_FSM_H
#define REGINA_FSM_H

#include <Telegram.h>
#include <State.h>

namespace Regina
{

template<class T1>
class CFSM
{
	T1* object;
	CState<T1>* currentState;
	CState<T1>* prievousState;
	CState<T1>* globalState;

public:
	CFSM(T1* iObject, CState<T1>* iCurrentState = NULL, CState<T1>* iGlobalState = NULL, CState<T1>* iPrievousState = NULL) : object(iObject), currentState(iCurrentState), globalState(iGlobalState), prievousState(iPrievousState) {}

	void SetCurrentState(CState<T1>* iState) { currentState = iState; }
	void SetGlobalState(CState<T1>* iState) { globalState = iState; }
	void SetPrievousState(CState<T1>* iState) { prievousState = iState; }
	void RevertPrievousState() { ChangeState(prievousState); }
	void Update(float duration);
	bool IsInState(const CState<T1>& iState) { return currentState==iState || globalState == iState; }
	CState<T1>* GetCurrentState() const { return currentState; }
	CState<T1>* GetPrievousState() const { return prievousState; }
	CState<T1>* GetGlobalState() const { return globalState; }
	void ChangeState(CState<T1>* iState);
	bool HandleMsg(CTelegram* iTelegram);


};

//******************************************************************************

template<class T1>
void CFSM<T1>::Update(double duration)
{
if(globalState!=NULL) globalState->Execute(duration);
if(currentState!=NULL) currentState->Execute(duration);
}

//******************************************************************************

template<class T1>
void CFSM<T1>::ChangeState(CState<T1>* iState)
{
prievousState = currentState;

if(currentState!=NULL)
	{
	currentState->Exit();
	delete currentState;
	}

currentState = iState;

if(currentState!=NULL)
currentState->Enter();
}

//******************************************************************************

template<class T1>
bool CFSM<T1>::HandleMsg(CTelegram* iTelegram)
{
if(currentState!=NULL)
if(currentState->HandleMsg(iTelegram)==true)
return true;

if(globalState!=NULL)
if(globalState->HandleMsg(iTelegram)==true)
return true;

return false;
}


}

#endif

