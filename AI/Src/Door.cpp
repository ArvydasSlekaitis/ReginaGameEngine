///////////////////////////////////////////////////////////
//  Door.cpp
//  Created on:      31-08-2009
//  Last modified:   31-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Door.h>
using namespace Regina;

//*****************************************************************************

void CDoor::HandleMsg(CTelegram* iTelegram)
	{
	switch(iTelegram->Msg())
		{
		case(msg_Open_Door) :	Open();
								break;

		case(msg_Close_Door) :	Close();
								break;
		}

	delete iTelegram;
	}

//*****************************************************************************
