/*
    CImage.cpp - Contains class CImage implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CImage.h>
using namespace Regina::UI;


//*****************************************************************************

CImage::~CImage()
	{
	}

//*****************************************************************************

CImage::CImage(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingScript) : CUIObject(iHWnd, iLanguage, iOriginalScreenResolution, iInterfaceName, iName, EUIObjectType::e_UIObject_Image), imageProp(iOriginalScreenResolution, iOriginalScreenResolution), scriptManager(this), position(0, 0), scriptName_OnFrameMove(L""), scriptName_OnRender(L""), scriptName_OnLeftClick(L""), scriptName_OnRightClick(L""), scriptName_OnMouseFocus(L""), scriptName_OnMouseUnfocus(L"")
  	{
	scriptManager.VariablePool().AddLocalVariable(L"elapsedTime", &elapsedTime);
	scriptManager.VariablePool().AddLocalVariable(L"time", &time);
	scriptManager.VariablePool().AddLocalVariable(L"visible", &visible);
	scriptManager.VariablePool().AddLocalVariable(L"active", &active);

	scriptManager.VariablePool().AddLocalVariable(L"positionX", &position.x);
	scriptManager.VariablePool().AddLocalVariable(L"positionY", &position.y);

	scriptManager.VariablePool().AddLocalVariable(L"colorR", &imageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"colorG", &imageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"colorB", &imageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"colorA", &imageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"scaleX", &imageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"scaleY", &imageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"rotation", &imageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"textureName", &imageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"alphaIntersectionTest", &imageProp.alphaIntersectionTest);

	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnFrameMove", &scriptName_OnFrameMove);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRender", &scriptName_OnRender);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnLeftClick", &scriptName_OnLeftClick);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRightClick", &scriptName_OnRightClick);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnMouseFocus", &scriptName_OnMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnMouseUnFocus", &scriptName_OnMouseUnfocus);

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

void CImage::On_FrameMove()
  	{
	RunScript(scriptName_OnFrameMove);
	CallCallbackFunction(EUIEventType::e_UIEvent_FrameMove);

	if(imageProp.Intersect(Cursor_Position(hWnd), position))
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

void CImage::On_Render()
  	{
	RunScript(scriptName_OnRender);

	imageProp.Render(position);

	CallCallbackFunction(EUIEventType::e_UIEvent_Render);
	}

//*****************************************************************************

bool CImage::On_LeftClick(const D3DXVECTOR2& iCursorPosition)
  	{
	if(imageProp.Intersect(iCursorPosition, position))
		{
		RunScript(scriptName_OnLeftClick);
		CallCallbackFunction(EUIEventType::e_UIEvent_LeftClick);
		return true;
		}
	return false;
	}

//*****************************************************************************

bool CImage::On_RightClick(const D3DXVECTOR2& iCursorPosition)
  	{
	if(imageProp.Intersect(iCursorPosition, position))
		{
		RunScript(scriptName_OnRightClick);
		CallCallbackFunction(EUIEventType::e_UIEvent_RightClick);
		return true;
		}
	return false;
	}

//*****************************************************************************

void CImage::On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	imageProp.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************
	
void CImage::GetInitializingText(vector<wstring>& oText)
	{
	oText.push_back(L"Image " + Name());
	oText.push_back(L"{");
	scriptManager.VariablePool().GetInitializingScriptText(oText);
	oText.push_back(L"}");
	}

//*****************************************************************************

void CImage::RunScript(const wstring& iScriptName)
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

bool CImage::GetProperty(const EUIObjectProperty_Bool& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:				return visible;
		case e_UIObjectProperty_Active:					return active;
		case e_UIObjectProperty_AlphaIntersectionTest:	return imageProp.alphaIntersectionTest;
	
		default: throw invalid_argument("CImage::GetProperty - iProperty is not valid image property");
		}
	}

//*****************************************************************************

int	CImage::GetProperty(const EUIObjectProperty_Int& iProperty)
	{
	throw invalid_argument("CImage::GetProperty - iProperty is not valid image property");
	}

//*****************************************************************************

float CImage::GetProperty(const EUIObjectProperty_Float& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:	return position.x;
		case e_UIObjectProperty_PositionY:	return position.y;
		case e_UIObjectProperty_ColorR:		return imageProp.color.r;
		case e_UIObjectProperty_ColorG:		return imageProp.color.g;
		case e_UIObjectProperty_ColorB:		return imageProp.color.b;
		case e_UIObjectProperty_ColorA:		return imageProp.color.a;
		case e_UIObjectProperty_ScaleX:		return imageProp.scale.x;
		case e_UIObjectProperty_ScaleY:		return imageProp.scale.y;
		case e_UIObjectProperty_Rotation:	return imageProp.rotation;

		default: throw invalid_argument("CImage::GetProperty - iProperty is not valid image property");
		}
	}

//*****************************************************************************

wstring	CImage::GetProperty(const EUIObjectProperty_String& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:		return scriptName_OnFrameMove;
		case e_UIObjectProperty_ScriptName_OnRender:		return scriptName_OnRender;
		case e_UIObjectProperty_ScriptName_OnLeftClick:		return scriptName_OnLeftClick;
		case e_UIObjectProperty_ScriptName_OnRightClick:	return scriptName_OnRightClick;
		case e_UIObjectProperty_ScriptName_OnMouseFocus:	return scriptName_OnMouseFocus;
		case e_UIObjectProperty_ScriptName_OnMouseUnfocus:	return scriptName_OnMouseUnfocus;
		case e_UIObjectProperty_TextureName:				return imageProp.textureName;

		default: throw invalid_argument("CImage::GetProperty - iProperty is not valid image property");
		}
	}

//*****************************************************************************

void CImage::SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:				visible							= iValue; return;
		case e_UIObjectProperty_Active:					active							= iValue; return;
		case e_UIObjectProperty_AlphaIntersectionTest:	imageProp.alphaIntersectionTest	= iValue; return;

		default: throw invalid_argument("CImage::SetProperty - iProperty is not valid image property");
		}
	}

//*****************************************************************************

void CImage::SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	throw invalid_argument("CImage::SetProperty - iProperty is not valid image property");
	}

//*****************************************************************************

void CImage::SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:	position.x				= iValue; return;
		case e_UIObjectProperty_PositionY:	position.y				= iValue; return;
		case e_UIObjectProperty_ColorR:		imageProp.color.r		= iValue; return;
		case e_UIObjectProperty_ColorG:		imageProp.color.g		= iValue; return;
		case e_UIObjectProperty_ColorB:		imageProp.color.b		= iValue; return;
		case e_UIObjectProperty_ColorA:		imageProp.color.a		= iValue; return;
		case e_UIObjectProperty_ScaleX:		imageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_ScaleY:		imageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_Rotation:	imageProp.rotation		= iValue; return;

		default: throw invalid_argument("CImage::SetProperty - iProperty is not valid image property");
		}
	}

//*****************************************************************************

void CImage::SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:		scriptName_OnFrameMove		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRender:		scriptName_OnRender			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnLeftClick:		scriptName_OnLeftClick		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRightClick:	scriptName_OnRightClick		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnMouseFocus:	scriptName_OnMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnMouseUnfocus:	scriptName_OnMouseUnfocus	= iValue; return;
		case e_UIObjectProperty_TextureName:				imageProp.textureName		= iValue; return;

		default: throw invalid_argument("CImage::SetProperty - iProperty is not valid image property");
		}
	}

//*****************************************************************************

bool CImage::Intersect(const D3DXVECTOR2& iPosition)
	{
	if(imageProp.Intersect(iPosition, position))
		return true;
	else
		return false;
	}

//*****************************************************************************
