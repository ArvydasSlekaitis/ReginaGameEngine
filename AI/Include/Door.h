///////////////////////////////////////////////////////////
//  Door.h
//  Created on:      31-08-2009
//  Last modified:   31-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_DOOR_H
#define REGINA_DOOR_H

#include <BaseEntity.h>
#include <BasicTypeEnumaration.h>
#include <BasicMessageEnumaration.h>

namespace Regina
{

class CDoor : public CBaseEntity
{
	bool opened;	

public:
	CDoor(const string iClassName = "Door", const unsigned iType = BasicTypeID::type_Door) : CBaseEntity(iClassName, iType) { }

	bool Opened() const { return opened; }
	bool Closed() const { return !opened; }

	virtual void HandleMsg(CTelegram* iTelegram);
	virtual void Open() { opened = true; }
	virtual void Close(){ opened = false; }		
};


}


#endif
