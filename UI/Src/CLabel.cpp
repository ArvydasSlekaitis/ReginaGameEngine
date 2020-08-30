/*
    CLabel.cpp - Contains class CLabel implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CLabel.h>
using namespace Regina::UI;


//*****************************************************************************

CLabel::~CLabel()
	{
	}

//*****************************************************************************

CLabel::CLabel(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingScript) : CUIObject(iHWnd, iLanguage, iOriginalScreenResolution, iInterfaceName, iName, EUIObjectType::e_UIObject_Label), textProp(iOriginalScreenResolution, iOriginalScreenResolution), scriptManager(this), position(0, 0), scale(1, 1), scriptName_OnFrameMove(L""), scriptName_OnRender(L""), scriptName_OnLeftClick(L""), scriptName_OnRightClick(L""), scriptName_OnMouseFocus(L""), scriptName_OnMouseUnfocus(L"")
  	{
	scriptManager.VariablePool().AddLocalVariable(L"elapsedTime", &elapsedTime);
	scriptManager.VariablePool().AddLocalVariable(L"time", &time);
	scriptManager.VariablePool().AddLocalVariable(L"visible", &visible);
	scriptManager.VariablePool().AddLocalVariable(L"active", &active);

	scriptManager.VariablePool().AddLocalVariable(L"positionX", &position.x);
	scriptManager.VariablePool().AddLocalVariable(L"positionY", &position.y);

	scriptManager.VariablePool().AddLocalVariable(L"scaleX", &scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"scaleY", &scale.y);

	scriptManager.VariablePool().AddLocalVariable(L"colorR", &textProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"colorG", &textProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"colorB", &textProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"colorA", &textProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"facename", &textProp.facename);
	scriptManager.VariablePool().AddLocalVariable(L"height", &textProp.height);
	scriptManager.VariablePool().AddLocalVariable(L"weight", &textProp.weight);
	scriptManager.VariablePool().AddLocalVariable(L"italic", &textProp.italic);
	scriptManager.VariablePool().AddLocalVariable(L"line", &textProp.line);

	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnFrameMove", &scriptName_OnFrameMove);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRender", &scriptName_OnRender);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnLeftClick", &scriptName_OnLeftClick);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRightClick", &scriptName_OnRightClick);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnMouseFocus", &scriptName_OnMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnMouseUnfocus", &scriptName_OnMouseUnfocus);

	try
		{
		scriptManager.RunScript(iInitializingScript);
		}
	catch(exception& iExcpetion)
		{
		ostringstream str;
		str << iExcpetion.what();
		//Log
		}
	}

//*****************************************************************************

void CLabel::On_FrameMove()
  	{
	RunScript(scriptName_OnFrameMove);
	CallCallbackFunction(EUIEventType::e_UIEvent_FrameMove);

	if(textProp.Intersect(Cursor_Position(hWnd), position, scale))
		{
		RunScript(scriptName_OnMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_MouseFocus);
		}
	else
		{
		RunScript(scriptName_OnMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_MouseUnfocus);
		}
	}

//*****************************************************************************

void CLabel::On_Render()
  	{
	RunScript(scriptName_OnRender);

	textProp.Render(position, scale);

	CallCallbackFunction(EUIEventType::e_UIEvent_Render);
	}

//*****************************************************************************

bool CLabel::On_LeftClick(const D3DXVECTOR2& iCursorPosition)
  	{
	if(textProp.Intersect(iCursorPosition, position, scale))
		{
		RunScript(scriptName_OnLeftClick);
		CallCallbackFunction(EUIEventType::e_UIEvent_LeftClick);
		return true;
		}
	return false;
	}

//*****************************************************************************

bool CLabel::On_RightClick(const D3DXVECTOR2& iCursorPosition)
  	{
	if(textProp.Intersect(iCursorPosition, position, scale))
		{
		RunScript(scriptName_OnRightClick);
		CallCallbackFunction(EUIEventType::e_UIEvent_RightClick);
		return true;
		}
	return false;
	}

//*****************************************************************************
	
void CLabel::On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	textProp.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************
	
void CLabel::GetInitializingText(vector<wstring>& oText)
	{
	oText.push_back(L"Label " + Name());
	oText.push_back(L"{");
	scriptManager.VariablePool().GetInitializingScriptText(oText);
	oText.push_back(L"}");
	}

//*****************************************************************************

void CLabel::RunScript(const wstring& iScriptName)
	{
	if(Active() == true)
		if(iScriptName.size() > 0)
			{
			try
				{
				scriptManager.RunScript(iScriptName);
				}
			catch(exception& iExcpetion)
				{
				ostringstream str;
				str << iExcpetion.what();
				//Log
				}
			}
	}

//*****************************************************************************

bool CLabel::GetProperty(const EUIObjectProperty_Bool& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:	return visible;
		case e_UIObjectProperty_Active:		return active;

		case e_UIObjectProperty_Italic:		return textProp.italic;
		
		default: throw invalid_argument("CLabel::GetProperty - iProperty is not valid label property");
		}
	}

//*****************************************************************************

int	CLabel::GetProperty(const EUIObjectProperty_Int& iProperty)
	{
	throw invalid_argument("CLabel::GetProperty - iProperty is not valid label property");
	}

//*****************************************************************************

float CLabel::GetProperty(const EUIObjectProperty_Float& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:	return position.x;
		case e_UIObjectProperty_PositionY:	return position.y;

		case e_UIObjectProperty_ScaleX:		return scale.x;
		case e_UIObjectProperty_ScaleY:		return scale.y;

		case e_UIObjectProperty_ColorR:		return textProp.color.r;
		case e_UIObjectProperty_ColorG:		return textProp.color.g;
		case e_UIObjectProperty_ColorB:		return textProp.color.b;
		case e_UIObjectProperty_ColorA:		return textProp.color.a;
		case e_UIObjectProperty_Height:		return textProp.height;
		case e_UIObjectProperty_Weight:		return textProp.weight;

		default: throw invalid_argument("CLabel::GetProperty - iProperty is not valid label property");
		}
	}

//*****************************************************************************

wstring	CLabel::GetProperty(const EUIObjectProperty_String& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:		return scriptName_OnFrameMove;
		case e_UIObjectProperty_ScriptName_OnRender:		return scriptName_OnRender;
		case e_UIObjectProperty_ScriptName_OnLeftClick:		return scriptName_OnLeftClick;
		case e_UIObjectProperty_ScriptName_OnRightClick:	return scriptName_OnRightClick;
		case e_UIObjectProperty_ScriptName_OnMouseFocus:	return scriptName_OnMouseFocus;
		case e_UIObjectProperty_ScriptName_OnMouseUnfocus:	return scriptName_OnMouseUnfocus;
		case e_UIObjectProperty_Facename:					return textProp.facename;
		case e_UIObjectProperty_Line:						return textProp.line;

		default: throw invalid_argument("CLabel::GetProperty - iProperty is not valid label property");
		}
	}

//*****************************************************************************

void CLabel::SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:	visible				= iValue; return;
		case e_UIObjectProperty_Active:		active				= iValue; return;

		case e_UIObjectProperty_Italic:		textProp.italic		= iValue; return;

		default: throw invalid_argument("CLabel::SetProperty - iProperty is not valid label property");
		}
	}

//*****************************************************************************

void CLabel::SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	throw invalid_argument("CLabel::SetProperty - iProperty is not valid label property");
	}

//*****************************************************************************

void CLabel::SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:	position.x			= iValue; return;
		case e_UIObjectProperty_PositionY:	position.y			= iValue; return;

		case e_UIObjectProperty_ScaleX:		scale.x				= iValue; return;
		case e_UIObjectProperty_ScaleY:		scale.y				= iValue; return;

		case e_UIObjectProperty_ColorR:		textProp.color.r	= iValue; return;
		case e_UIObjectProperty_ColorG:		textProp.color.g	= iValue; return;
		case e_UIObjectProperty_ColorB:		textProp.color.b	= iValue; return;
		case e_UIObjectProperty_ColorA:		textProp.color.a	= iValue; return;
		case e_UIObjectProperty_Height:		textProp.height		= iValue; return;
		case e_UIObjectProperty_Weight:		textProp.weight		= iValue; return;

		default: throw invalid_argument("CLabel::SetProperty - iProperty is not valid label property");
		}
	}

//*****************************************************************************

void CLabel::SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:		scriptName_OnFrameMove		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRender:		scriptName_OnRender			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnLeftClick:		scriptName_OnLeftClick		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRightClick:	scriptName_OnRightClick		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnMouseFocus:	scriptName_OnMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnMouseUnfocus:	scriptName_OnMouseUnfocus	= iValue; return;
		case e_UIObjectProperty_Facename:					textProp.facename			= iValue; return;
		case e_UIObjectProperty_Line:						textProp.line				= iValue; return;

		default: throw invalid_argument("CLabel::SetProperty - iProperty is not valid label property");
		}
	}

//*****************************************************************************

bool CLabel::Intersect(const D3DXVECTOR2& iPosition)
	{
	if(textProp.Intersect(iPosition, position, scale))
		return true;
	else
		return false;
	}

//*****************************************************************************
