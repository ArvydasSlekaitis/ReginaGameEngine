/*
    CTextBox.h - Contains class CTextBox.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CTEXTBOX_H
#define REGINA_UI_CTEXTBOX_H

#include <CImageProp.h>
#include <CTextProp.h>
#include <CUIObject.h>
#include <TScriptManager.h>
using namespace Regina::Script;

namespace Regina
{

namespace UI
{

class CTextBox : public CUIObject
{
	D3DXVECTOR2					position;
	D3DXVECTOR2					scale;
	D3DXVECTOR2					verticalScrollBar_MarkerStartPositionOffset;
	float						verticalScrollBar_MarkerEndPositionOffsetY;
	int							verticalScrollBar_CurStep;

	CTextProp					textProp;
	CImageProp					backgroundImageProp;
	CImageProp					verticalScrollBar_BackgroundImageProp;
	CImageProp					verticalScrollBar_MarkerImageProp;
	CImageProp					verticalScrollBar_UpButtonImageProp;
	CImageProp					verticalScrollBar_DownButtonImageProp;

	TScriptManager<CTextBox>	scriptManager;

	//ScriptName's
	wstring						scriptName_OnFrameMove;
	wstring						scriptName_OnRender;
	wstring						scriptName_OnVerticalScrollBar_UpButtonPress;
	wstring						scriptName_OnVerticalScrollBar_UpButtonMouseFocus;
	wstring						scriptName_OnVerticalScrollBar_UpButtonMouseUnfocus;
	wstring						scriptName_OnVerticalScrollBar_DownButtonPress;
	wstring						scriptName_OnVerticalScrollBar_DownButtonMouseFocus;
	wstring						scriptName_OnVerticalScrollBar_DownButtonMouseUnfocus;
	wstring						scriptName_OnTextBoxMouseFocus;
	wstring						scriptName_OnTextBoxMouseUnfocus;
	
	void			CorrectParams();
	unsigned		NumSteps();
	unsigned		MaxStep();
	unsigned		MinStep()					const;
	float			Round(const float& iValue)	const;
	D3DXVECTOR2		GetMarkerPosition();
	void			RunScript(const wstring& iScriptName);

protected:
	virtual void On_FrameMove();
	virtual void On_Render();
	virtual bool On_LeftClick(const D3DXVECTOR2& iCursorPosition);
	virtual void On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution);
	  	
public:
	virtual ~CTextBox();
	CTextBox(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingScript);
	
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