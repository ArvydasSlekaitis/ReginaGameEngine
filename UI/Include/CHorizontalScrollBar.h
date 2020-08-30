/*
    CHorizontalScrollBar.h - Contains class CHorizontalScrollBar.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CHORIZONTALSCROLLBAR_H
#define REGINA_UI_CHORIZONTALSCROLLBAR_H

#include <CLabelProp.h>
#include <CImageProp.h>
#include <CUIObject.h>
#include <TScriptManager.h>
using namespace Regina::Script;

namespace Regina
{

namespace UI
{

class CHorizontalScrollBar : public CUIObject
{
	D3DXVECTOR2					position;
	D3DXVECTOR2					scale;
	D3DXVECTOR2					markerStartPositionOffset;
	float						markerEndPositionOffsetX;
	int							maxStep;
	int							minStep;
	int							curStep;

	CImageProp					backgroundImageProp;
	CImageProp					markerImageProp;
	CImageProp					leftButtonImageProp;
	CImageProp					rightButtonImageProp;

	TScriptManager<CHorizontalScrollBar>	scriptManager;

	//ScriptName's
	wstring						scriptName_OnFrameMove;
	wstring						scriptName_OnRender;
	wstring						scriptName_OnLeftButtonPress;
	wstring						scriptName_OnLeftButtonMouseFocus;
	wstring						scriptName_OnLeftButtonMouseUnfocus;
	wstring						scriptName_OnRightButtonPress;
	wstring						scriptName_OnRightButtonMouseFocus;
	wstring						scriptName_OnRightButtonMouseUnfocus;
	wstring						scriptName_OnScrollBarMouseFocus;
	wstring						scriptName_OnScrollBarMouseUnfocus;
	wstring						scriptName_OnStepChange;
	
	
	void			CorrectParams();
	unsigned		NumSteps()					const;
	float			Round(const float& iValue)	const;
	D3DXVECTOR2		GetMarkerPosition();
	void			RunScript(const wstring& iScriptName);

protected:
	virtual void On_FrameMove();
	virtual void On_Render();
	virtual bool On_LeftClick(const D3DXVECTOR2& iCursorPosition);
	virtual void On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution);
	  	
public:
	virtual ~CHorizontalScrollBar();
	CHorizontalScrollBar(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingScript);
	
	virtual void	GetInitializingText(vector<wstring>& oText);
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