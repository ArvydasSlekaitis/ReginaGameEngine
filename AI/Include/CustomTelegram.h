///////////////////////////////////////////////////////////
//  CustomTelegram.h
//  Created on:      19-07-2008
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

/*
Definition for UnaryTelegram with template parameter of type data
*/

#ifndef REGINA_CUSTOMTELEGRAM_H
#define REGINA_CUSTOMTELEGRAM_H

#include <Telegram.h>

namespace Regina
{

template<class T1>
class CUnaryTelegram : public CTelegram
{
	T1 alData;
	CUnaryTelegram<T1>(const CUnaryTelegram&);
	CUnaryTelegram<T1>& operator=(const CUnaryTelegram<T1>&);
public:
	CUnaryTelegram(unsigned iSender, unsigned iReceiver, unsigned iMsg, float iDispatchTime = 0, const T1& iData = T1()) : CTelegram(iSender, iReceiver, iMsg, iDispatchTime, NULL), alData(iData) { data = (void*)&alData; }
	~CUnaryTelegram() { }
};

}

#endif
