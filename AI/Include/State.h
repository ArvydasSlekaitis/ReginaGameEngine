///////////////////////////////////////////////////////////
//  State.h
//  Created on:      18-07-2008
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_STATE_H
#define REGINA_STATE_H

#include <Telegram.h>

namespace Regina
{

template<class T1>
class CState
{
protected:
	T1* object;

public:
	CState(T1* iObject) : object(iObject) {}
	virtual ~CState() {}
	virtual void Enter(){}
	virtual void Exit(){}
	virtual void Execute(float duration){}
	virtual bool HandleMsg(CTelegram*){ return false; }
};

}


#endif
