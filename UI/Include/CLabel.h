/*
    CLabel.h - Contains class CLabel.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CLABEL
#define REGINA_UI_CLABEL

#include <CLabelProp.h>
#include <CUIObject.h>
#include <TScriptManager.h>
using namespace Regina::Script;

namespace Regina
{

namespace UI
{

class CLabel : public CUIObject
{
	D3DXVECTOR2				position;
	D3DXVECTOR2				scale;
	CLabelProp				textProp;
	TScriptManager<CLabel>	scriptManager;

	//ScriptName's
	wstring					scriptName_OnFrameMove;
	wstring					scriptName_OnRender;
	wstring					scriptName_OnLeftClick;
	wstring					scriptName_OnRightClick;
	wstring					scriptName_OnMouseFocus;
	wstring					scriptName_OnMouseUnfocus;

	void RunScript(const wstring& iScriptName);

protected:
	virtual void On_FrameMove();
	virtual void On_Render();
	virtual bool On_LeftClick(const D3DXVECTOR2& iCursorPosition);
	virtual bool On_RightClick(const D3DXVECTOR2& iCursorPosition);
	virtual void On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution);

public:
	virtual ~CLabel();
	CLabel(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingScript);

	virtual	void	GetInitializingText(vector<wstring>& oText);
	virtual bool	Intersect(const D3DXVECTOR2& iPosition);
	
	virtual bool	GetProperty(const EUIObjectProperty_Bool& iProperty);
	virtual int		GetProperty(const EUIObjectProperty_Int& iProperty);
	virtual float	GetProperty(const EUIObjectProperty_Float& iProperty);
	virtual wstring	GetProperty(const EUIObjectProperty_String& iProperty);

	virtual void	SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue);
	virtual void	SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue);
	virtual void	SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue);
	virtual void	SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue);
};

}

}

#endif 