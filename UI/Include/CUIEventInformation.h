/*
    CUIEventInformation.h - Contains class CUIEventInformation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CUIEVENTINFORMATION_H
#define REGINA_UI_CUIEVENTINFORMATION_H

#include <string>
using namespace std;

#include <EUIObjectType.h>
#include <EUIEventType.h>

namespace Regina
{

namespace UI
{

class CUIEventInformation
{
	EUIEventType	eventType;
	EUIObjectType	objectType;
	wstring			interfaceName;
	wstring			objectName;

public:
	CUIEventInformation(const EUIEventType& iEventType, const EUIObjectType& iObjectType, const wstring& iInterfaceName, const wstring& iObjectName) : eventType(iEventType), objectType(iObjectType), interfaceName(iInterfaceName), objectName(iObjectName) {}

	EUIEventType	EventType()		const { return eventType; }
	EUIObjectType	ObjectType()	const { return objectType; }
	wstring			InterfaceName()	const { return interfaceName; }
	wstring			ObjectName()	const { return objectName; }	

};

}

}
#endif

