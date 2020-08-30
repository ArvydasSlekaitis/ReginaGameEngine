///////////////////////////////////////////////////////////
//  Telegram.h
//  Created on:      17-07-2008
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_TELEGRAM_H
#define REGINA_TELEGRAM_H


namespace Regina
{

class CTelegram
{
	unsigned	sender;
	unsigned	receiver;
	unsigned	msg;
	float		dispatchTime;

	CTelegram(const CTelegram&);
	CTelegram& operator=(const CTelegram&);

protected:
	void* data;

public:
	CTelegram(unsigned iSender, unsigned iReceiver, unsigned iMsg, float iDispatchTime = 0, void* iData=0) : sender(iSender), receiver(iReceiver), dispatchTime(iDispatchTime), data(iData), msg(iMsg) {}
	virtual ~CTelegram(){};
	bool operator<(const CTelegram& tel) { return dispatchTime < tel.DispatchTime(); }

	unsigned Sender()		const { return sender; }
	unsigned Receiver()		const { return receiver; }
	unsigned Msg()			const { return msg; }
	float	 DispatchTime() const { return dispatchTime; }
	void*	 Data()			const { return data; }
};


}


#endif
