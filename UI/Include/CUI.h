/*
    CUI.h - Contains class CUI.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CUI_H
#define REGINA_UI_CUI_H

#include <CInterfaceManager.h>
#include <CMessageManager.h>

#include <CText.h>

namespace Regina
{


namespace UI
{

class CUIManager;

class CUI
{
	wstring				language;
	D3DXVECTOR2			screenResolution;
	D3DXVECTOR2			originalScreenResolution;
	HWND				hWnd;
		
	CInterfaceManager	interfaceManager;
	CMessageManager		messageManager;

	void LoadModuleText(const vector<wstring>& iInitializingText, unsigned& ioCurrentLine, vector<wstring>& oInitializingTemplateText);

public:
	CUI(HWND iHWnd, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iLanguage, const wstring iName = L"");
	virtual ~CUI();

	void Load(const wstring& iName);
	void Clear();
	void SetScreenResolution(const D3DXVECTOR2& iScreenResolution);

	void FrameMove(const float& iTime);
	bool MsgProc(UINT uMsg, WPARAM wParam);
	void Begin();
	void End();

	void Render(const wstring& iInterfaceName);

	bool MessageBox(const wstring& iTemplateName, const wstring& iHeader);
	bool InputQuery(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer);
	bool QuestionBox(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer);

	void	SetCallbackFunction(const wstring& iInterfaceName, const wstring& iObjectName, const EUIEventType& iEventType, void (*iCallbackFunction)(const CUIEventInformation&));

	bool	GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty);
	int		GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Int& iProperty);
	float	GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Float& iProperty);
	wstring GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_String& iProperty);

	void	SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty, const bool& iValue);
	void	SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Int& iProperty, const int& iValue);
	void	SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Float& iProperty, const float& iValue);
	void	SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_String& iProperty, const wstring& iValue);

	wstring		Language()					const	{ return language; }
	D3DXVECTOR2 ScreenResolution()			const	{ return screenResolution; }
	D3DXVECTOR2 OriginalScreenResolution()	const 	{ return originalScreenResolution; }

	friend CUIManager;
};

}

}

#endif 