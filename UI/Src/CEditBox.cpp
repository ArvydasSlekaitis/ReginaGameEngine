/*
    CEditBox.cpp - Contains class CEditBox implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CEditBox.h>
using namespace Regina::UI;


//*****************************************************************************

CEditBox::~CEditBox()
  	{
	}

//*****************************************************************************

CEditBox::CEditBox(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingScript) : CUIObject(iHWnd, iLanguage, iOriginalScreenResolution, iInterfaceName, iName, EUIObjectType::e_UIObject_EditBox), textProp(iOriginalScreenResolution, iOriginalScreenResolution), backgroundImageProp(iOriginalScreenResolution, iOriginalScreenResolution), markerImageProp(iOriginalScreenResolution, iOriginalScreenResolution), scriptManager(this), position(0, 0), scale(1, 1), scriptName_OnFrameMove(L""), scriptName_OnRender(L""), scriptName_OnMouseFocus(L""), scriptName_OnMouseUnfocus(L""), scriptName_OnSelect(L""), scriptName_OnDeselect(L""), scriptName_OnKeyPress(L""), scriptName_OnEnterPress(L""), selected(false), markerBlinkSpeed(1020), maxTextSize(50), rise(true), textToRender(iOriginalScreenResolution, iOriginalScreenResolution)
  	{
	scriptManager.VariablePool().AddLocalVariable(L"elapsedTime", &elapsedTime);
	scriptManager.VariablePool().AddLocalVariable(L"time", &time);
	scriptManager.VariablePool().AddLocalVariable(L"visible", &visible);
	scriptManager.VariablePool().AddLocalVariable(L"active", &active);

	scriptManager.VariablePool().AddLocalVariable(L"positionX", &position.x);
	scriptManager.VariablePool().AddLocalVariable(L"positionY", &position.y);

	scriptManager.VariablePool().AddLocalVariable(L"scaleX", &scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"scaleY", &scale.y);

	scriptManager.VariablePool().AddLocalVariable(L"selected", &selected);
	scriptManager.VariablePool().AddLocalVariable(L"markerBlinkSpeed", &markerBlinkSpeed);
	scriptManager.VariablePool().AddLocalVariable(L"maxTextSize", &maxTextSize);

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
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_offsetX", &backgroundImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_offsetY", &backgroundImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_colorR", &backgroundImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_colorG", &backgroundImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_colorB", &backgroundImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_colorA", &backgroundImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_scaleX", &backgroundImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_scaleY", &backgroundImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_rotation", &backgroundImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_textureName", &backgroundImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"backgroundImage_alphaIntersectionTest", &backgroundImageProp.alphaIntersectionTest);

	//Marker image
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_offsetX", &markerImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_offsetY", &markerImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_colorR", &markerImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_colorG", &markerImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_colorB", &markerImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_colorA", &markerImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_scaleX", &markerImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_scaleY", &markerImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_rotation", &markerImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_textureName", &markerImageProp.textureName);

	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnFrameMove", &scriptName_OnFrameMove);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRender", &scriptName_OnRender);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnMouseFocus", &scriptName_OnMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnMouseUnfocus", &scriptName_OnMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnSelect", &scriptName_OnSelect);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnDeselect", &scriptName_OnDeselect);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnKeyPress", &scriptName_OnKeyPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnEnterPress", &scriptName_OnEnterPress);

	scriptManager.VariablePool().AddLocalVariable(L"lastKeyPressed", wstring(L""));

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

	GetTextToRender();
	}

//*****************************************************************************

void CEditBox::On_FrameMove()
  	{
	RunScript(scriptName_OnFrameMove);
	CallCallbackFunction(EUIEventType::e_UIEvent_FrameMove);

	if(textProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_MouseFocus);
		}
	else
		{
		RunScript(scriptName_OnMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_MouseUnfocus);
		}

	UpdateMarker();
	}

//*****************************************************************************

void CEditBox::On_Render()
  	{
	RunScript(scriptName_OnRender);

	backgroundImageProp.Render(position, scale);

	textProp.Render(position, GetTextToRender(), scale, scale);

	if(selected == true)
		markerImageProp.Render(MarkerPosition(), scale);

	CallCallbackFunction(EUIEventType::e_UIEvent_Render);
	}

//*****************************************************************************

bool CEditBox::On_LeftClick(const D3DXVECTOR2& iCursorPosition)
  	{
	//Proccess background image
	if(backgroundImageProp.Intersect(iCursorPosition, position, scale))
		{
		Select();
		return true;
		}

	return false;
	}

//*****************************************************************************

bool CEditBox::On_KeyDown(const wchar_t& iKey)
  	{
	if(selected == true)
		{
		if(iKey >= 'a' && iKey <= 'z' || iKey >= 'A' && iKey <= 'Z' || iKey >= '0' && iKey <= '9' || iKey == '+' || iKey == '-' || iKey == '*' || iKey == '/' || iKey == '.' || iKey == ' ' || iKey == ',' || iKey == ';' || iKey == ':' || iKey == '/' || iKey == '?' || iKey == '`' || iKey == '~' || iKey == '[' || iKey == '{' || iKey == ']' || iKey == '}' || iKey == '\\' || iKey == '|' || iKey == '}' || iKey == '\'' || iKey == '"') // Encompass all symbols
			textProp.line = textProp.line + iKey;
		
		if(iKey == VK_BACK)
			{
			if(textProp.line.size() > 0)
				textProp.line.erase(textProp.line.end() - 1);
			}

		GetTextToRender();

		scriptManager.VariablePool().SetVariableValue(L"lastKeyPressed", wstring(L""+iKey));
		RunScript(scriptName_OnKeyPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_KeyPress);

		if(iKey == VK_RETURN)
			{
			RunScript(scriptName_OnEnterPress);
			CallCallbackFunction(EUIEventType::e_UIEvent_EnterPress);
			Deselect();
			}

		return true;
		}
	return false;
	}

//*****************************************************************************
	
void CEditBox::On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	textToRender.SetScreenResolution(iScreenResolution);
	textProp.SetScreenResolution(iScreenResolution);
	backgroundImageProp.SetScreenResolution(iScreenResolution);
	markerImageProp.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************
	
void CEditBox::GetInitializingText(vector<wstring>& oText)
	{
	oText.push_back(L"EditBox " + Name());
	oText.push_back(L"{");
	scriptManager.VariablePool().GetInitializingScriptText(oText);
	oText.push_back(L"}");
	}

//*****************************************************************************

void CEditBox::RunScript(const wstring& iScriptName)
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

bool CEditBox::GetProperty(const EUIObjectProperty_Bool& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								return visible;
		case e_UIObjectProperty_Active:									return active;

		case e_UIObjectProperty_Selected:								return selected;
		case e_UIObjectProperty_Text_Italic:							return textProp.italic;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	return backgroundImageProp.alphaIntersectionTest;
		
		default: throw invalid_argument("CEditBox::GetProperty - iProperty is not valid EditBox property");
		}
	}

//*****************************************************************************

int	CEditBox::GetProperty(const EUIObjectProperty_Int& iProperty)
	{
	switch(iProperty)
		{
		default: throw invalid_argument("CEditBox::GetProperty - iProperty is not valid EditBox property");
		}
	}

//*****************************************************************************

float CEditBox::GetProperty(const EUIObjectProperty_Float& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:					return position.x;
		case e_UIObjectProperty_PositionY:					return position.y;

		case e_UIObjectProperty_ScaleX:						return scale.x;
		case e_UIObjectProperty_ScaleY:						return scale.y;

		case e_UIObjectProperty_MarkerBlinkSpeed:			return markerBlinkSpeed;
		case e_UIObjectProperty_MaxTextSize:				return maxTextSize;

		case e_UIObjectProperty_BackgroundImage_OffsetX:	return backgroundImageProp.offset.x;
		case e_UIObjectProperty_BackgroundImage_OffsetY:	return backgroundImageProp.offset.y;
		case e_UIObjectProperty_BackgroundImage_ColorR:		return backgroundImageProp.color.r;
		case e_UIObjectProperty_BackgroundImage_ColorG:		return backgroundImageProp.color.g;
		case e_UIObjectProperty_BackgroundImage_ColorB:		return backgroundImageProp.color.b;
		case e_UIObjectProperty_BackgroundImage_ColorA:		return backgroundImageProp.color.a;
		case e_UIObjectProperty_BackgroundImage_ScaleX:		return backgroundImageProp.scale.x;
		case e_UIObjectProperty_BackgroundImage_ScaleY:		return backgroundImageProp.scale.y;
		case e_UIObjectProperty_BackgroundImage_Rotation:	return backgroundImageProp.rotation;

		case e_UIObjectProperty_MarkerImage_OffsetX:		return markerImageProp.offset.x;
		case e_UIObjectProperty_MarkerImage_OffsetY:		return markerImageProp.offset.y;
		case e_UIObjectProperty_MarkerImage_ColorR:			return markerImageProp.color.r;
		case e_UIObjectProperty_MarkerImage_ColorG:			return markerImageProp.color.g;
		case e_UIObjectProperty_MarkerImage_ColorB:			return markerImageProp.color.b;
		case e_UIObjectProperty_MarkerImage_ColorA:			return markerImageProp.color.a;
		case e_UIObjectProperty_MarkerImage_ScaleX:			return markerImageProp.scale.x;
		case e_UIObjectProperty_MarkerImage_ScaleY:			return markerImageProp.scale.y;
		case e_UIObjectProperty_MarkerImage_Rotation:		return markerImageProp.rotation;

		case e_UIObjectProperty_Text_OffsetX:				return textProp.offset.x;
		case e_UIObjectProperty_Text_OffsetY:				return textProp.offset.y;
		case e_UIObjectProperty_Text_ColorR:				return textProp.color.r;
		case e_UIObjectProperty_Text_ColorG:				return textProp.color.g;
		case e_UIObjectProperty_Text_ColorB:				return textProp.color.b;
		case e_UIObjectProperty_Text_ColorA:				return textProp.color.a;
		case e_UIObjectProperty_Text_Height:				return textProp.height;
		case e_UIObjectProperty_Text_Weight:				return textProp.weight;


		default: throw invalid_argument("CEditBox::GetProperty - iProperty is not valid EditBox property");
		}
	}

//*****************************************************************************

wstring	CEditBox::GetProperty(const EUIObjectProperty_String& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:			return scriptName_OnFrameMove;
		case e_UIObjectProperty_ScriptName_OnRender:			return scriptName_OnRender;
		case e_UIObjectProperty_ScriptName_OnMouseFocus:		return scriptName_OnMouseFocus;
		case e_UIObjectProperty_ScriptName_OnMouseUnfocus:		return scriptName_OnMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnSelect:			return scriptName_OnSelect;
		case e_UIObjectProperty_ScriptName_OnDeselect:			return scriptName_OnDeselect;
		case e_UIObjectProperty_ScriptName_OnKeyPress:			return scriptName_OnKeyPress;
		case e_UIObjectProperty_ScriptName_OnEnterPress:		return scriptName_OnEnterPress;


		case e_UIObjectProperty_BackgroundImage_TextureName:	return backgroundImageProp.textureName;
		case e_UIObjectProperty_MarkerImage_TextureName:		return markerImageProp.textureName;
		case e_UIObjectProperty_Text_Facename:					return textProp.facename;
		case e_UIObjectProperty_Text_Line:						return textProp.line;

		default: throw invalid_argument("CEditBox::GetProperty - iProperty is not valid EditBox property");
		}
	}

//*****************************************************************************

void CEditBox::SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								visible										= iValue; return;
		case e_UIObjectProperty_Active:									active										= iValue; return;
		
		case e_UIObjectProperty_Selected:								selected									= iValue; if(iValue == true) Select(); else Deselect(); return;
		case e_UIObjectProperty_Text_Italic:							textProp.italic								= iValue; return;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	backgroundImageProp.alphaIntersectionTest	= iValue; return;;

		default: throw invalid_argument("CEditBox::SetProperty - iProperty is not valid EditBox property");
		}
	}

//*****************************************************************************

void CEditBox::SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	switch(iProperty)
		{
		default: throw invalid_argument("CEditBox::SetProperty - iProperty is not valid EditBox property");
		}
	}

//*****************************************************************************

void CEditBox::SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:					position.x						= iValue; return;
		case e_UIObjectProperty_PositionY:					position.y						= iValue; return;

		case e_UIObjectProperty_ScaleX:						scale.x							= iValue; return;
		case e_UIObjectProperty_ScaleY:						scale.y							= iValue; return;

		case e_UIObjectProperty_MarkerBlinkSpeed:			markerBlinkSpeed				= iValue; return;
		case e_UIObjectProperty_MaxTextSize:				maxTextSize						= iValue; GetTextToRender(); return;

		case e_UIObjectProperty_BackgroundImage_OffsetX:	backgroundImageProp.offset.x	= iValue; return;
		case e_UIObjectProperty_BackgroundImage_OffsetY:	backgroundImageProp.offset.y	= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorR:		backgroundImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorG:		backgroundImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorB:		backgroundImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorA:		backgroundImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ScaleX:		backgroundImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ScaleY:		backgroundImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_Rotation:	backgroundImageProp.rotation	= iValue; return;

		case e_UIObjectProperty_MarkerImage_OffsetX:		markerImageProp.offset.x		= iValue; return;
		case e_UIObjectProperty_MarkerImage_OffsetY:		markerImageProp.offset.y		= iValue; return;
		case e_UIObjectProperty_MarkerImage_ColorR:			markerImageProp.color.r			= iValue; return;
		case e_UIObjectProperty_MarkerImage_ColorG:			markerImageProp.color.g			= iValue; return;
		case e_UIObjectProperty_MarkerImage_ColorB:			markerImageProp.color.b			= iValue; return;
		case e_UIObjectProperty_MarkerImage_ColorA:			markerImageProp.color.a			= iValue; return;
		case e_UIObjectProperty_MarkerImage_ScaleX:			markerImageProp.scale.x			= iValue; return;
		case e_UIObjectProperty_MarkerImage_ScaleY:			markerImageProp.scale.y			= iValue; return;
		case e_UIObjectProperty_MarkerImage_Rotation:		markerImageProp.rotation		= iValue; return;

		case e_UIObjectProperty_Text_OffsetX:				textProp.offset.x				= iValue; return;
		case e_UIObjectProperty_Text_OffsetY:				textProp.offset.y				= iValue; return;
		case e_UIObjectProperty_Text_ColorR:				textProp.color.r				= iValue; return;
		case e_UIObjectProperty_Text_ColorG:				textProp.color.g				= iValue; return;
		case e_UIObjectProperty_Text_ColorB:				textProp.color.b				= iValue; return;
		case e_UIObjectProperty_Text_ColorA:				textProp.color.a				= iValue; return;
		case e_UIObjectProperty_Text_Height:				textProp.height					= iValue; GetTextToRender(); return;
		case e_UIObjectProperty_Text_Weight:				textProp.weight					= iValue; return;

		default: throw invalid_argument("CEditBox::SetProperty - iProperty is not valid EditBox property");
		}
	}

//*****************************************************************************

void CEditBox::SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:			scriptName_OnFrameMove			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRender:			scriptName_OnRender				= iValue; return;
		case e_UIObjectProperty_ScriptName_OnMouseFocus:		scriptName_OnMouseFocus			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnMouseUnfocus:		scriptName_OnMouseUnfocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnSelect:			scriptName_OnSelect				= iValue; return;
		case e_UIObjectProperty_ScriptName_OnDeselect:			scriptName_OnDeselect			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnKeyPress:			scriptName_OnKeyPress			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnEnterPress:		scriptName_OnEnterPress			= iValue; return;

		case e_UIObjectProperty_BackgroundImage_TextureName:	backgroundImageProp.textureName	= iValue; return;
		case e_UIObjectProperty_MarkerImage_TextureName:		markerImageProp.textureName		= iValue; return;
		case e_UIObjectProperty_Text_Facename:					textProp.facename				= iValue; return;
		case e_UIObjectProperty_Text_Line:						textProp.line					= iValue; GetTextToRender(); return;


		default: throw invalid_argument("CEditBox::SetProperty - iProperty is not valid EditBox property");
		}
	}

//*****************************************************************************

void CEditBox::Select()
	{
	rise = true;
	markerImageProp.color.a = 0;
	selected = true;

	RunScript(scriptName_OnSelect);
	CallCallbackFunction(EUIEventType::e_UIEvent_Select);
	}

//*****************************************************************************

void CEditBox::Deselect()
	{
	rise = true;
	markerImageProp.color.a = 0;
	selected = false;

	RunScript(scriptName_OnDeselect);
	CallCallbackFunction(EUIEventType::e_UIEvent_Deselect);
	}

//*****************************************************************************

void CEditBox::UpdateMarker()
	{
	if(selected == true)
		{
		if(rise == true)
			{
			markerImageProp.color.a += elapsedTime * markerBlinkSpeed;
			if(markerImageProp.color.a > 255)
				{
				rise = false;
				markerImageProp.color.a = 255;
				}
			}
		else
			{
			markerImageProp.color.a -= elapsedTime * markerBlinkSpeed;
			if(markerImageProp.color.a < 0)
				{
				rise = true;
				markerImageProp.color.a = 0;
				}
			}

		}
	}

//*****************************************************************************

D3DXVECTOR2 CEditBox::MarkerPosition()
	{
	D3DXVECTOR2 ret(position);
	ret.x += textToRender.offset.x * scale.x;
	ret = TransformToUIScreenSpace(originalScreenResolution, screenResolution, ret);
	ret.x += textToRender.GetTextExtent(scale).right;
	ret = TransformToUIScreenSpaceInverse(originalScreenResolution, screenResolution, ret);
	return ret; 
	}

//*****************************************************************************

wstring CEditBox::GetTextToRender()
	{
	if(maxTextSize < 0)
		maxTextSize = 0; 

	textToRender = textProp;

	while(true)
		{
		const float curSize = textToRender.GetTextExtent(scale).right;
		D3DXVECTOR2 curMaxTextSizeTemp(maxTextSize*scale.x, 0);
		curMaxTextSizeTemp = TransformToUIScreenSpace(originalScreenResolution, screenResolution, curMaxTextSizeTemp);
		const float curMaxTextSize = curMaxTextSizeTemp.x;

		if(curSize <= curMaxTextSize)
			break;
		else
			if(textToRender.line.size() > 0)
				textToRender.line.erase(textToRender.line.begin());
			else
				break;
		}

	return textToRender.line;
	}

//*****************************************************************************

bool CEditBox::Intersect(const D3DXVECTOR2& iPosition)
	{
	if(backgroundImageProp.Intersect(iPosition, position, scale) || markerImageProp.Intersect(iPosition, position, scale) || textToRender.Intersect(iPosition, position, scale, scale))
		return true;
	else
		return false;
	}

//*****************************************************************************