/*
    CUIMessage.h - Contains class CUIMessage.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CUIMESSAGE_H
#define REGINA_UI_CUIMESSAGE_H

#include <CUIObject.h>

namespace Regina
{

namespace UI
{


class CUIMessage : public CUIObject
{
public:
	enum EUIMessageState { E_UIMessageState_Render, E_UIMessageState_BeginTermination, E_UIMessageState_Terminate };

private:
	EUIMessageState state;

protected:
	void SetState(const EUIMessageState& iNewState) { state = iNewState; }

public:
	CUIMessage(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, const EUIObjectType& iObjectType);
	virtual ~CUIMessage();
	
	EUIMessageState State()	const { return state; }
};

}

}

#endif 