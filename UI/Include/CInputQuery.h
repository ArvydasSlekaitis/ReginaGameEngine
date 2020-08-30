/*
    CInputQuery.h - Contains class CInputQuery.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CINPUTQUERY_H
#define REGINA_UI_CINPUTQUERY_H

#include <CImageProp.h>
#include <CLabelProp.h>
#include <CUIMessage.h>

#include <TScriptManager.h>
using namespace Regina::Script;

namespace Regina
{


namespace UI
{


class CInputQuery : public CUIMessage
{
	D3DXVECTOR2					position;
	D3DXVECTOR2					scale;
	float						maxQuestionTextSize;
	float						maxInputTextSize;
	bool						rise;
	float						markerBlinkSpeed;    
	wstring*					answer;

	CLabelProp					questionTextProp;
	CLabelProp					questionTextToRender;			// Temprory variable only used for rendering
	CLabelProp					inputTextProp;
	CLabelProp					inputTextToRender;				// Temprory variable only used for rendering
	CLabelProp					okButtonTextProp;
	CImageProp					okButtonImageProp;
	CImageProp					backgroundImageProp;
	CImageProp					markerImageProp;

	TScriptManager<CInputQuery>	scriptManager;

	//ScriptName's
	wstring						scriptName_OnFrameMove;
	wstring						scriptName_OnRender;
	wstring						scriptName_OnOkButtonPress;
	wstring						scriptName_OnOkButtonMouseFocus;
	wstring						scriptName_OnOkButtonMouseUnfocus;
	wstring						scriptName_OnInputQueryMouseFocus;
	wstring						scriptName_OnInputQueryMouseUnfocus;
	wstring						scriptName_OnKeyPress;
	wstring						scriptName_OnEnterPress;

	
	void		RunScript(const wstring& iScriptName);
	void		UpdateMarker();
	D3DXVECTOR2	MarkerPosition();
	wstring		GetQuestionTextToRender();
	wstring		GetInputTextToRender();
	
protected:
	virtual void On_FrameMove();
	virtual void On_Render();
	virtual bool On_LeftClick(const D3DXVECTOR2& iCursorPosition);
	virtual bool On_KeyDown(const wchar_t& iKey);
	virtual void On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution);
	  	
public:
	virtual ~CInputQuery();
	CInputQuery(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, wstring* oAnswer, const vector<wstring>& iInitializingScript);
	
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