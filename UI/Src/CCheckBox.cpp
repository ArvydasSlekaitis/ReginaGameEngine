/*
    CCheckBox.cpp - Contains class CCheckBox implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CCheckBox.h>
using namespace Regina::UI;


//*****************************************************************************

CCheckBox::~CCheckBox()
  	{
	}

//*****************************************************************************

CCheckBox::CCheckBox(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingScript) : CUIObject(iHWnd, iLanguage, iOriginalScreenResolution, iInterfaceName, iName, EUIObjectType::e_UIObject_CheckBox), textProp(iOriginalScreenResolution, iOriginalScreenResolution), backgroundImageProp(iOriginalScreenResolution, iOriginalScreenResolution), checkMarkImageProp(iOriginalScreenResolution, iOriginalScreenResolution), scriptManager(this), position(0, 0), scale(1, 1), checked(true), scriptName_OnFrameMove(L""), scriptName_OnRender(L""), scriptName_OnLeftClick(L""), scriptName_OnRightClick(L""), scriptName_OnMouseFocus(L""), scriptName_OnMouseUnfocus(L""), scriptName_OnStateChange(L"")
  	{
	scriptManager.VariablePool().AddLocalVariable(L"elapsedTime", &elapsedTime);
	scriptManager.VariablePool().AddLocalVariable(L"time", &time);
	scriptManager.VariablePool().AddLocalVariable(L"visible", &visible);
	scriptManager.VariablePool().AddLocalVariable(L"active", &active);

	scriptManager.VariablePool().AddLocalVariable(L"positionX", &position.x);
	scriptManager.VariablePool().AddLocalVariable(L"positionY", &position.y);

	scriptManager.VariablePool().AddLocalVariable(L"scaleX", &scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"scaleY", &scale.y);

	scriptManager.VariablePool().AddLocalVariable(L"checked", &checked);

	//Text
	scriptManager.VariablePool().AddLocalVariable(L"text_offsetX", &textProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"text_offsetY", &textProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"text_colorR", &textProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"text_colorG", &textProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"text_colorB", &textProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"text_colorA", &textProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"text_facename", &textProp.facename);
	scriptManager.VariablePool().AddLocalVariable(L"text_height", &textProp.height);
	scriptManager.VariablePool().AddLocalVariable(L"text_weight", &textProp.weight);
	scriptManager.VariablePool().AddLocalVariable(L"text_italic", &textProp.italic);
	scriptManager.VariablePool().AddLocalVariable(L"text_line", &textProp.line);

	//Background image
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_colorR", &backgroundImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_colorG", &backgroundImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_colorB", &backgroundImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_colorA", &backgroundImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_scaleX", &backgroundImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_scaleY", &backgroundImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_rotation", &backgroundImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_textureName", &backgroundImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_alphaIntersectionTest", &backgroundImageProp.alphaIntersectionTest);

	//CheckMark image
	scriptManager.VariablePool().AddLocalVariable(L"checkMarkImage_colorR", &checkMarkImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"checkMarkImage_colorG", &checkMarkImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"checkMarkImage_colorB", &checkMarkImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"checkMarkImage_colorA", &checkMarkImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"checkMarkImage_scaleX", &checkMarkImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"checkMarkImage_scaleY", &checkMarkImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"checkMarkImage_rotation", &checkMarkImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"checkMarkImage_textureName", &checkMarkImageProp.textureName);

	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnFrameMove", &scriptName_OnFrameMove);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRender", &scriptName_OnRender);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnLeftClick", &scriptName_OnLeftClick);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRightClick", &scriptName_OnRightClick);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnMouseFocus", &scriptName_OnMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnMouseUnFocus", &scriptName_OnMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnStateChange", &scriptName_OnStateChange);

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

void CCheckBox::On_FrameMove()
  	{
	RunScript(scriptName_OnFrameMove);
	CallCallbackFunction(EUIEventType::e_UIEvent_FrameMove);

	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || checkMarkImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || textProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
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

void CCheckBox::On_Render()
  	{
	RunScript(scriptName_OnRender);

	backgroundImageProp.Render(position, scale, scale);

	if(checked == true)
		checkMarkImageProp.Render(position, scale, scale);

	textProp.Render(position, scale, scale);

	CallCallbackFunction(EUIEventType::e_UIEvent_Render);
	}

//*****************************************************************************

bool CCheckBox::On_LeftClick(const D3DXVECTOR2& iCursorPosition)
  	{
	//Proccess background image
	if(backgroundImageProp.Intersect(iCursorPosition, position, scale, scale))
		{
		RunScript(scriptName_OnLeftClick);
		CallCallbackFunction(EUIEventType::e_UIEvent_LeftClick);

		checked = !checked;
		RunScript(scriptName_OnStateChange);
		CallCallbackFunction(EUIEventType::e_UIEvent_StateChange);

		return true;
		}

	//Process check mark image
	if(checkMarkImageProp.Intersect(iCursorPosition, position, scale, scale))
		{
		RunScript(scriptName_OnLeftClick);
		CallCallbackFunction(EUIEventType::e_UIEvent_LeftClick);
		return true;
		}

	//Process text 
	if(textProp.Intersect(iCursorPosition, position, scale, scale))
		{
		RunScript(scriptName_OnLeftClick);
		CallCallbackFunction(EUIEventType::e_UIEvent_LeftClick);
		return true;
		}

	return false;
	}

//*****************************************************************************

bool CCheckBox::On_RightClick(const D3DXVECTOR2& iCursorPosition)
  	{
	if(backgroundImageProp.Intersect(iCursorPosition, position, scale, scale) || checkMarkImageProp.Intersect(iCursorPosition, position, scale, scale) || textProp.Intersect(iCursorPosition, position, scale, scale))
		{
		RunScript(scriptName_OnRightClick);
		CallCallbackFunction(EUIEventType::e_UIEvent_RightClick);
		return true;
		}
	return false;
	}

//*****************************************************************************
	
void CCheckBox::On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	textProp.SetScreenResolution(iScreenResolution);
	backgroundImageProp.SetScreenResolution(iScreenResolution);
	checkMarkImageProp.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************
	
void CCheckBox::GetInitializingText(vector<wstring>& oText)
	{
	oText.push_back(L"CheckBox " + Name());
	oText.push_back(L"{");
	scriptManager.VariablePool().GetInitializingScriptText(oText);
	oText.push_back(L"}");
	}

//*****************************************************************************

void CCheckBox::RunScript(const wstring& iScriptName)
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

bool CCheckBox::GetProperty(const EUIObjectProperty_Bool& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								return visible;
		case e_UIObjectProperty_Active:									return active;

		case e_UIObjectProperty_Checked:								return checked;
		case e_UIObjectProperty_Text_Italic:							return textProp.italic;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	return backgroundImageProp.alphaIntersectionTest;
		
		default: throw invalid_argument("CCheckBox::GetProperty - iProperty is not valid CheckBox property");
		}
	}

//*****************************************************************************

int	CCheckBox::GetProperty(const EUIObjectProperty_Int& iProperty)
	{
	throw invalid_argument("CCheckBox::GetProperty - iProperty is not valid CheckBox property");
	}

//*****************************************************************************

float CCheckBox::GetProperty(const EUIObjectProperty_Float& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:					return position.x;
		case e_UIObjectProperty_PositionY:					return position.y;

		case e_UIObjectProperty_ScaleX:						return scale.x;
		case e_UIObjectProperty_ScaleY:						return scale.y;

		case e_UIObjectProperty_BackgroundImage_ColorR:		return backgroundImageProp.color.r;
		case e_UIObjectProperty_BackgroundImage_ColorG:		return backgroundImageProp.color.g;
		case e_UIObjectProperty_BackgroundImage_ColorB:		return backgroundImageProp.color.b;
		case e_UIObjectProperty_BackgroundImage_ColorA:		return backgroundImageProp.color.a;
		case e_UIObjectProperty_BackgroundImage_ScaleX:		return backgroundImageProp.scale.x;
		case e_UIObjectProperty_BackgroundImage_ScaleY:		return backgroundImageProp.scale.y;
		case e_UIObjectProperty_BackgroundImage_Rotation:	return backgroundImageProp.rotation;

		case e_UIObjectProperty_CheckMarkImage_ColorR:		return checkMarkImageProp.color.r;
		case e_UIObjectProperty_CheckMarkImage_ColorG:		return checkMarkImageProp.color.g;
		case e_UIObjectProperty_CheckMarkImage_ColorB:		return checkMarkImageProp.color.b;
		case e_UIObjectProperty_CheckMarkImage_ColorA:		return checkMarkImageProp.color.a;
		case e_UIObjectProperty_CheckMarkImage_ScaleX:		return checkMarkImageProp.scale.x;
		case e_UIObjectProperty_CheckMarkImage_ScaleY:		return checkMarkImageProp.scale.y;
		case e_UIObjectProperty_CheckMarkImage_Rotation:	return checkMarkImageProp.rotation;

		case e_UIObjectProperty_Text_OffsetX:				return textProp.offset.x;
		case e_UIObjectProperty_Text_OffsetY:				return textProp.offset.y;
		case e_UIObjectProperty_Text_ColorR:				return textProp.color.r;
		case e_UIObjectProperty_Text_ColorG:				return textProp.color.g;
		case e_UIObjectProperty_Text_ColorB:				return textProp.color.b;
		case e_UIObjectProperty_Text_ColorA:				return textProp.color.a;
		case e_UIObjectProperty_Text_Height:				return textProp.height;
		case e_UIObjectProperty_Text_Weight:				return textProp.weight;


		default: throw invalid_argument("CCheckBox::GetProperty - iProperty is not valid CheckBox property");
		}
	}

//*****************************************************************************

wstring	CCheckBox::GetProperty(const EUIObjectProperty_String& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:			return scriptName_OnFrameMove;
		case e_UIObjectProperty_ScriptName_OnRender:			return scriptName_OnRender;
		case e_UIObjectProperty_ScriptName_OnLeftClick:			return scriptName_OnLeftClick;
		case e_UIObjectProperty_ScriptName_OnRightClick:		return scriptName_OnRightClick;
		case e_UIObjectProperty_ScriptName_OnMouseFocus:		return scriptName_OnMouseFocus;
		case e_UIObjectProperty_ScriptName_OnMouseUnfocus:		return scriptName_OnMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnStateChange:		return scriptName_OnStateChange;

		case e_UIObjectProperty_BackgroundImage_TextureName:	return backgroundImageProp.textureName;
		case e_UIObjectProperty_CheckMarkImage_TextureName:		return checkMarkImageProp.textureName;
		case e_UIObjectProperty_Text_Facename:					return textProp.facename;
		case e_UIObjectProperty_Text_Line:						return textProp.line;

		default: throw invalid_argument("CCheckBox::GetProperty - iProperty is not valid CheckBox property");
		}
	}

//*****************************************************************************

void CCheckBox::SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								visible										= iValue; return;
		case e_UIObjectProperty_Active:									active										= iValue; return;
		
		case e_UIObjectProperty_Checked:								checked										= iValue; return;
		case e_UIObjectProperty_Text_Italic:							textProp.italic								= iValue; return;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	backgroundImageProp.alphaIntersectionTest	= iValue; return;;

		default: throw invalid_argument("CCheckBox::SetProperty - iProperty is not valid CheckBox property");
		}
	}

//*****************************************************************************

void CCheckBox::SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	throw invalid_argument("CCheckBox::SetProperty - iProperty is not valid CheckBox property");
	}

//*****************************************************************************

void CCheckBox::SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:					position.x						= iValue; return;
		case e_UIObjectProperty_PositionY:					position.y						= iValue; return;

		case e_UIObjectProperty_ScaleX:						scale.x							= iValue; return;
		case e_UIObjectProperty_ScaleY:						scale.y							= iValue; return;

		case e_UIObjectProperty_BackgroundImage_ColorR:		backgroundImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorG:		backgroundImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorB:		backgroundImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorA:		backgroundImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ScaleX:		backgroundImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ScaleY:		backgroundImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_Rotation:	backgroundImageProp.rotation	= iValue; return;

		case e_UIObjectProperty_CheckMarkImage_ColorR:		checkMarkImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_CheckMarkImage_ColorG:		checkMarkImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_CheckMarkImage_ColorB:		checkMarkImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_CheckMarkImage_ColorA:		checkMarkImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_CheckMarkImage_ScaleX:		checkMarkImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_CheckMarkImage_ScaleY:		checkMarkImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_CheckMarkImage_Rotation:	checkMarkImageProp.rotation		= iValue; return;

		case e_UIObjectProperty_Text_OffsetX:				textProp.offset.x				= iValue; return;
		case e_UIObjectProperty_Text_OffsetY:				textProp.offset.y				= iValue; return;
		case e_UIObjectProperty_Text_ColorR:				textProp.color.r				= iValue; return;
		case e_UIObjectProperty_Text_ColorG:				textProp.color.g				= iValue; return;
		case e_UIObjectProperty_Text_ColorB:				textProp.color.b				= iValue; return;
		case e_UIObjectProperty_Text_ColorA:				textProp.color.a				= iValue; return;
		case e_UIObjectProperty_Text_Height:				textProp.height					= iValue; return;
		case e_UIObjectProperty_Text_Weight:				textProp.weight					= iValue; return;

		default: throw invalid_argument("CCheckBox::SetProperty - iProperty is not valid CheckBox property");
		}
	}

//*****************************************************************************

void CCheckBox::SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:			scriptName_OnFrameMove			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRender:			scriptName_OnRender				= iValue; return;
		case e_UIObjectProperty_ScriptName_OnLeftClick:			scriptName_OnLeftClick			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRightClick:		scriptName_OnRightClick			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnMouseFocus:		scriptName_OnMouseFocus			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnMouseUnfocus:		scriptName_OnMouseUnfocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnStateChange:		scriptName_OnStateChange		= iValue; return;

		case e_UIObjectProperty_BackgroundImage_TextureName:	backgroundImageProp.textureName	= iValue; return;
		case e_UIObjectProperty_CheckMarkImage_TextureName:		checkMarkImageProp.textureName	= iValue; return;
		case e_UIObjectProperty_Text_Facename:					textProp.facename				= iValue; return;
		case e_UIObjectProperty_Text_Line:						textProp.line					= iValue; return;

		default: throw invalid_argument("CCheckBox::SetProperty - iProperty is not valid CheckBox property");
		}
	}

//*****************************************************************************

bool CCheckBox::Intersect(const D3DXVECTOR2& iPosition)
	{
	if(backgroundImageProp.Intersect(iPosition, position, scale, scale) || checkMarkImageProp.Intersect(iPosition, position, scale, scale) || textProp.Intersect(iPosition, position, scale, scale))
		return true;
	else
		return false;
	}

//*****************************************************************************
