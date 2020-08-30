/*
    CQuestionBox.h - Contains class CMessageBox.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CQUESTIONBOX_H
#define REGINA_UI_CQUESTIONBOX_H

#include <CImageProp.h>
#include <CLabelProp.h>
#include <CUIMessage.h>

#include <TScriptManager.h>
using namespace Regina::Script;

namespace Regina
{


namespace UI
{


class CQuestionBox : public CUIMessage
{
	D3DXVECTOR2					position;
	D3DXVECTOR2					scale;
	float						maxQuestionTextSize;
	CLabelProp					questionTextProp;
	CLabelProp					questionTextToRender;			// Temprory variable only used for rendering
	CLabelProp					yesButtonTextProp;
	CImageProp					yesButtonImageProp;
	CLabelProp					noButtonTextProp;
	CImageProp					noButtonImageProp;
	CImageProp					backgroundImageProp;
	wstring*					answer;

	TScriptManager<CQuestionBox>	scriptManager;

	//ScriptName's
	wstring						scriptName_OnFrameMove;
	wstring						scriptName_OnRender;
	wstring						scriptName_OnYesButtonPress;
	wstring						scriptName_OnYesButtonMouseFocus;
	wstring						scriptName_OnYesButtonMouseUnfocus;
	wstring						scriptName_OnNoButtonPress;
	wstring						scriptName_OnNoButtonMouseFocus;
	wstring						scriptName_OnNoButtonMouseUnfocus;
	wstring						scriptName_OnQuestionBoxMouseFocus;
	wstring						scriptName_OnQuestionBoxMouseUnfocus;

	
	void	RunScript(const wstring& iScriptName);
	wstring	GetQuestionTextToRender();

protected:
	virtual void On_FrameMove();
	virtual void On_Render();
	virtual bool On_LeftClick(const D3DXVECTOR2& iCursorPosition);
	virtual void On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution);
	  	
public:
	virtual ~CQuestionBox();
	CQuestionBox(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, wstring* oAnswer, const vector<wstring>& iInitializingScript);
	
	virtual void	GetInitializingText(vector<wstring>& oScriptText);
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