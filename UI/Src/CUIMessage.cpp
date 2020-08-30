/*
    CUIMessage.cpp - Contains class CUIMessage implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CUIMessage.h>
using namespace Regina::UI;


//*****************************************************************************

CUIMessage::CUIMessage(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, const EUIObjectType& iObjectType) : state(E_UIMessageState_Render), CUIObject(iHWnd, iLanguage, iOriginalScreenResolution, L"MESSAGE_TEMPLATE", iName, iObjectType)
	{

	}

//*****************************************************************************

CUIMessage::~CUIMessage()
	{

	}

//*****************************************************************************