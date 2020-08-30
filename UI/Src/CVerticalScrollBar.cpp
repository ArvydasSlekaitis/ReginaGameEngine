/*
    CVerticalScrollBar.cpp - Contains class CVerticalScrollBar implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CVerticalScrollBar.h>
using namespace Regina::UI;


//*****************************************************************************

CVerticalScrollBar::~CVerticalScrollBar()
  	{
	}

//*****************************************************************************

CVerticalScrollBar::CVerticalScrollBar(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingScript) : CUIObject(iHWnd, iLanguage, iOriginalScreenResolution, iInterfaceName, iName, EUIObjectType::e_UIObject_VerticalScrollBar), markerImageProp(iOriginalScreenResolution, iOriginalScreenResolution), backgroundImageProp(iOriginalScreenResolution, iOriginalScreenResolution), upButtonImageProp(iOriginalScreenResolution, iOriginalScreenResolution), downButtonImageProp(iOriginalScreenResolution, iOriginalScreenResolution), scriptManager(this), position(0, 0), scale(1, 1), markerStartPositionOffset(0, 0), markerEndPositionOffsetY(100), maxStep(100), minStep(0), curStep(0), scriptName_OnFrameMove(L""), scriptName_OnRender(L""), scriptName_OnUpButtonPress(L""), scriptName_OnUpButtonMouseFocus(L""), scriptName_OnUpButtonMouseUnfocus(L""), scriptName_OnDownButtonPress(L""), scriptName_OnDownButtonMouseFocus(L""), scriptName_OnDownButtonMouseUnfocus(L""), scriptName_OnScrollBarMouseFocus(L""), scriptName_OnScrollBarMouseUnfocus(L""), scriptName_OnStepChange(L"")
  	{
	scriptManager.VariablePool().AddLocalVariable(L"elapsedTime", &elapsedTime);
	scriptManager.VariablePool().AddLocalVariable(L"time", &time);
	scriptManager.VariablePool().AddLocalVariable(L"visible", &visible);
	scriptManager.VariablePool().AddLocalVariable(L"active", &active);

	scriptManager.VariablePool().AddLocalVariable(L"positionX", &position.x);
	scriptManager.VariablePool().AddLocalVariable(L"positionY", &position.y);

	scriptManager.VariablePool().AddLocalVariable(L"scaleX", &scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"scaleY", &scale.y);

	scriptManager.VariablePool().AddLocalVariable(L"markerStartPositionOffsetX", &markerStartPositionOffset.x);
	scriptManager.VariablePool().AddLocalVariable(L"markerStartPositionOffsetY", &markerStartPositionOffset.y);
	scriptManager.VariablePool().AddLocalVariable(L"markerEndPositionOffsetY", &markerEndPositionOffsetY);
	scriptManager.VariablePool().AddLocalVariable(L"maxStep", &maxStep);
	scriptManager.VariablePool().AddLocalVariable(L"minStep", &minStep);
	scriptManager.VariablePool().AddLocalVariable(L"curStep", &curStep);


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
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_colorR", &markerImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_colorG", &markerImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_colorB", &markerImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_colorA", &markerImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_scaleX", &markerImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_scaleY", &markerImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_rotation", &markerImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_textureName", &markerImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"markerImage_alphaIntersectionTest", &markerImageProp.alphaIntersectionTest);

	//Up button image
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_offsetX", &upButtonImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_offsetY", &upButtonImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_colorR", &upButtonImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_colorG", &upButtonImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_colorB", &upButtonImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_colorA", &upButtonImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_scaleX", &upButtonImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_scaleY", &upButtonImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_rotation", &upButtonImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_textureName", &upButtonImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"upButtonImage_alphaIntersectionTest", &upButtonImageProp.alphaIntersectionTest);

	//Down button image
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_offsetX", &downButtonImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_offsetY", &downButtonImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_colorR", &downButtonImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_colorG", &downButtonImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_colorB", &downButtonImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_colorA", &downButtonImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_scaleX", &downButtonImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_scaleY", &downButtonImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_rotation", &downButtonImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_textureName", &downButtonImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"downButtonImage_alphaIntersectionTest", &downButtonImageProp.alphaIntersectionTest);

	//Script Name
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnFrameMove", &scriptName_OnFrameMove);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRender", &scriptName_OnRender);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnUpButtonPress", &scriptName_OnUpButtonPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnUpButtonMouseFocus", &scriptName_OnUpButtonMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnUpButtonMouseUnfocus", &scriptName_OnUpButtonMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnDownButtonPress", &scriptName_OnDownButtonPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnDownButtonMouseFocus", &scriptName_OnDownButtonMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnDownButtonMouseUnfocus", &scriptName_OnDownButtonMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnScrollBarMouseFocus", &scriptName_OnScrollBarMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnScrollBarMouseUnfocus", &scriptName_OnScrollBarMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnStepChange", &scriptName_OnStepChange);

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

void CVerticalScrollBar::On_FrameMove()
  	{
	RunScript(scriptName_OnFrameMove);
	CallCallbackFunction(EUIEventType::e_UIEvent_FrameMove);

	//Process background image
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale) || upButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || downButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || markerImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnScrollBarMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_ScrollBarMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnScrollBarMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_ScrollBarMouseUnfocus);
		}

	//Process Up button image
	if(upButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnUpButtonMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_UpButtonMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnUpButtonMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_UpButtonMouseUnfocus);
		}

	//Process Down button image
	if(downButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnDownButtonMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_DownButtonMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnDownButtonMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_DownButtonMouseUnfocus);
		}
	}

//*****************************************************************************

void CVerticalScrollBar::On_Render()
  	{
	RunScript(scriptName_OnRender);

	backgroundImageProp.Render(position, scale);

	markerImageProp.Render(GetMarkerPosition(), scale, scale);

	upButtonImageProp.Render(position, scale, scale);
	downButtonImageProp.Render(position, scale, scale);

	CallCallbackFunction(EUIEventType::e_UIEvent_Render);
	}

//*****************************************************************************

bool CVerticalScrollBar::On_LeftClick(const D3DXVECTOR2& iCursorPosition)
  	{
	//Process Up button image
	if(upButtonImageProp.Intersect(iCursorPosition, position, scale, scale))
		{
		if(curStep > minStep)
			curStep--;

		RunScript(scriptName_OnUpButtonPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_UpButtonPress);

		RunScript(scriptName_OnStepChange);
		CallCallbackFunction(EUIEventType::e_UIEvent_StepChange);

		return true;
		}

	//Process Down button image
	if(downButtonImageProp.Intersect(iCursorPosition, position, scale, scale))
		{		
		if(curStep < maxStep)
			curStep++;

		RunScript(scriptName_OnDownButtonPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_DownButtonPress);

		RunScript(scriptName_OnStepChange);
		CallCallbackFunction(EUIEventType::e_UIEvent_StepChange);

		return true;
		}

	//Process Background (slider) image
	if(backgroundImageProp.Intersect(iCursorPosition, position, scale))
		{
		CorrectParams();

		D3DXVECTOR2 pos = TransformToUIScreenSpaceInverse(originalScreenResolution, screenResolution, iCursorPosition); // Position in original screen resolution
		pos -= position - backgroundImageProp.offset;					// Position in object cordinates

		if(pos.y >= markerEndPositionOffsetY*scale.y)
			curStep = maxStep;
		else
			{
			pos -= D3DXVECTOR2(markerStartPositionOffset.x*scale.x, markerStartPositionOffset.y*scale.y);	// Position relative to marker start position
			
				if(pos.y <= 0)
					curStep = minStep;
				else
					{
					int numSteps   = NumSteps();

					float distance = markerEndPositionOffsetY*scale.y - markerStartPositionOffset.y*scale.y;

					float tStep = pos.y / distance * ((float)numSteps - 1);
					tStep += minStep;

					curStep = Round(tStep);				
					}
			}


		RunScript(scriptName_OnStepChange);
		CallCallbackFunction(EUIEventType::e_UIEvent_StepChange);

		return true;
		}

	return false;
	}

//*****************************************************************************
	
void CVerticalScrollBar::On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	backgroundImageProp.SetScreenResolution(iScreenResolution);
	markerImageProp.SetScreenResolution(iScreenResolution);
	upButtonImageProp.SetScreenResolution(iScreenResolution);
	downButtonImageProp.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************
	
void CVerticalScrollBar::GetInitializingText(vector<wstring>& oText)
	{
	oText.push_back(L"VerticalScrollBar " + Name());
	oText.push_back(L"{");
	scriptManager.VariablePool().GetInitializingScriptText(oText);
	oText.push_back(L"}");
	}

//*****************************************************************************

void CVerticalScrollBar::RunScript(const wstring& iScriptName)
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

bool CVerticalScrollBar::GetProperty(const EUIObjectProperty_Bool& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								return visible;
		case e_UIObjectProperty_Active:									return active;

		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	return backgroundImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_MarkerImage_AlphaIntersectionTest:		return markerImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_UpButtonImage_AlphaIntersectionTest:	return upButtonImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_DownButtonImage_AlphaIntersectionTest:	return downButtonImageProp.alphaIntersectionTest;
	
		default: throw invalid_argument("CVerticalScrollBar::GetProperty - iProperty is not valid VerticalScrollBar property");
		}
	}

//*****************************************************************************

int	CVerticalScrollBar::GetProperty(const EUIObjectProperty_Int& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_MaxStep:		return maxStep;
		case e_UIObjectProperty_MinStep:		return minStep;
		case e_UIObjectProperty_CurStep:		return curStep;

		default: throw invalid_argument("CVerticalScrollBar::GetProperty - iProperty is not valid VerticalScrollBar property");
		}
	}

//*****************************************************************************

float CVerticalScrollBar::GetProperty(const EUIObjectProperty_Float& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:					return position.x;
		case e_UIObjectProperty_PositionY:					return position.y;

		case e_UIObjectProperty_ScaleX:						return scale.x;
		case e_UIObjectProperty_ScaleY:						return scale.y;

		case e_UIObjectProperty_MarkerStartPositionOffsetX:	return markerStartPositionOffset.x;
		case e_UIObjectProperty_MarkerStartPositionOffsetY:	return markerStartPositionOffset.y;
		case e_UIObjectProperty_MarkerEndPositionOffsetY:	return markerEndPositionOffsetY;

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

		case e_UIObjectProperty_UpButtonImage_OffsetX:		return upButtonImageProp.offset.x;
		case e_UIObjectProperty_UpButtonImage_OffsetY:		return upButtonImageProp.offset.y;
		case e_UIObjectProperty_UpButtonImage_ColorR:		return upButtonImageProp.color.r;
		case e_UIObjectProperty_UpButtonImage_ColorG:		return upButtonImageProp.color.g;
		case e_UIObjectProperty_UpButtonImage_ColorB:		return upButtonImageProp.color.b;
		case e_UIObjectProperty_UpButtonImage_ColorA:		return upButtonImageProp.color.a;
		case e_UIObjectProperty_UpButtonImage_ScaleX:		return upButtonImageProp.scale.x;
		case e_UIObjectProperty_UpButtonImage_ScaleY:		return upButtonImageProp.scale.y;
		case e_UIObjectProperty_UpButtonImage_Rotation:		return upButtonImageProp.rotation;

		case e_UIObjectProperty_DownButtonImage_OffsetX:	return downButtonImageProp.offset.x;
		case e_UIObjectProperty_DownButtonImage_OffsetY:	return downButtonImageProp.offset.y;
		case e_UIObjectProperty_DownButtonImage_ColorR:		return downButtonImageProp.color.r;
		case e_UIObjectProperty_DownButtonImage_ColorG:		return downButtonImageProp.color.g;
		case e_UIObjectProperty_DownButtonImage_ColorB:		return downButtonImageProp.color.b;
		case e_UIObjectProperty_DownButtonImage_ColorA:		return downButtonImageProp.color.a;
		case e_UIObjectProperty_DownButtonImage_ScaleX:		return downButtonImageProp.scale.x;
		case e_UIObjectProperty_DownButtonImage_ScaleY:		return downButtonImageProp.scale.y;
		case e_UIObjectProperty_DownButtonImage_Rotation:	return downButtonImageProp.rotation;

		default: throw invalid_argument("CVerticalScrollBar::GetProperty - iProperty is not valid VerticalScrollBar property");
		}
	}

//*****************************************************************************

wstring	CVerticalScrollBar::GetProperty(const EUIObjectProperty_String& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:					return scriptName_OnFrameMove;
		case e_UIObjectProperty_ScriptName_OnRender:					return scriptName_OnRender;
		case e_UIObjectProperty_ScriptName_OnUpButtonPress:				return scriptName_OnUpButtonPress;
		case e_UIObjectProperty_ScriptName_OnUpButtonMouseFocus:		return scriptName_OnUpButtonMouseFocus;
		case e_UIObjectProperty_ScriptName_OnUpButtonMouseUnfocus:		return scriptName_OnUpButtonMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnDownButtonPress:			return scriptName_OnDownButtonPress;
		case e_UIObjectProperty_ScriptName_OnDownButtonMouseFocus:		return scriptName_OnDownButtonMouseFocus;
		case e_UIObjectProperty_ScriptName_OnDownButtonMouseUnfocus:	return scriptName_OnDownButtonMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnScrollBarMouseFocus:		return scriptName_OnScrollBarMouseFocus;
		case e_UIObjectProperty_ScriptName_OnScrollBarMouseUnfocus:		return scriptName_OnScrollBarMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnStepChange:				return scriptName_OnStepChange;

		case e_UIObjectProperty_BackgroundImage_TextureName:			return backgroundImageProp.textureName;
		case e_UIObjectProperty_MarkerImage_TextureName:				return markerImageProp.textureName;
		case e_UIObjectProperty_UpButtonImage_TextureName:				return upButtonImageProp.textureName;
		case e_UIObjectProperty_DownButtonImage_TextureName:			return downButtonImageProp.textureName;

		default: throw invalid_argument("CVerticalScrollBar::GetProperty - iProperty is not valid VerticalScrollBar property");
		}
	}

//*****************************************************************************

void CVerticalScrollBar::SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								visible										= iValue; return;
		case e_UIObjectProperty_Active:									active										= iValue; return;

		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	backgroundImageProp.alphaIntersectionTest	= iValue; return;
		case e_UIObjectProperty_MarkerImage_AlphaIntersectionTest:		markerImageProp.alphaIntersectionTest		= iValue; return;
		case e_UIObjectProperty_UpButtonImage_AlphaIntersectionTest:	upButtonImageProp.alphaIntersectionTest		= iValue; return;
		case e_UIObjectProperty_DownButtonImage_AlphaIntersectionTest:	downButtonImageProp.alphaIntersectionTest	= iValue; return;
			
		default: throw invalid_argument("CVerticalScrollBar::SetProperty - iProperty is not valid VerticalScrollBar property");
		}
	}

//*****************************************************************************

void CVerticalScrollBar::SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_MaxStep:		maxStep			= iValue; return;
		case e_UIObjectProperty_MinStep:		minStep			= iValue; return;
		case e_UIObjectProperty_CurStep:		curStep			= iValue; return;

		default: throw invalid_argument("CVerticalScrollBar::SetProperty - iProperty is not valid VerticalScrollBar property");
		}
	}

//*****************************************************************************

void CVerticalScrollBar::SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:					position.x						= iValue; return;
		case e_UIObjectProperty_PositionY:					position.y						= iValue; return;

		case e_UIObjectProperty_ScaleX:						scale.x							= iValue; return;
		case e_UIObjectProperty_ScaleY:						scale.y							= iValue; return;

		case e_UIObjectProperty_MarkerStartPositionOffsetX:	markerStartPositionOffset.x		= iValue; return;
		case e_UIObjectProperty_MarkerStartPositionOffsetY:	markerStartPositionOffset.y		= iValue; return;
		case e_UIObjectProperty_MarkerEndPositionOffsetY:	markerEndPositionOffsetY		= iValue; return;

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

		case e_UIObjectProperty_UpButtonImage_OffsetX:		upButtonImageProp.offset.x		= iValue; return;
		case e_UIObjectProperty_UpButtonImage_OffsetY:		upButtonImageProp.offset.y		= iValue; return;
		case e_UIObjectProperty_UpButtonImage_ColorR:		upButtonImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_UpButtonImage_ColorG:		upButtonImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_UpButtonImage_ColorB:		upButtonImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_UpButtonImage_ColorA:		upButtonImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_UpButtonImage_ScaleX:		upButtonImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_UpButtonImage_ScaleY:		upButtonImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_UpButtonImage_Rotation:		upButtonImageProp.rotation		= iValue; return;

		case e_UIObjectProperty_DownButtonImage_OffsetX:		downButtonImageProp.offset.x	= iValue; return;
		case e_UIObjectProperty_DownButtonImage_OffsetY:		downButtonImageProp.offset.y	= iValue; return;
		case e_UIObjectProperty_DownButtonImage_ColorR:		downButtonImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_DownButtonImage_ColorG:		downButtonImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_DownButtonImage_ColorB:		downButtonImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_DownButtonImage_ColorA:		downButtonImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_DownButtonImage_ScaleX:		downButtonImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_DownButtonImage_ScaleY:		downButtonImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_DownButtonImage_Rotation:		downButtonImageProp.rotation	= iValue; return;

		default: throw invalid_argument("CVerticalScrollBar::SetProperty - iProperty is not valid VerticalScrollBar property");
		}
	}

//*****************************************************************************

void CVerticalScrollBar::SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:					scriptName_OnFrameMove				= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRender:					scriptName_OnRender					= iValue; return;
		case e_UIObjectProperty_ScriptName_OnUpButtonPress:				scriptName_OnUpButtonPress			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnUpButtonMouseFocus:		scriptName_OnUpButtonMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnUpButtonMouseUnfocus:		scriptName_OnUpButtonMouseUnfocus	= iValue; return;
		case e_UIObjectProperty_ScriptName_OnDownButtonPress:			scriptName_OnDownButtonPress		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnDownButtonMouseFocus:		scriptName_OnDownButtonMouseFocus	= iValue; return;
		case e_UIObjectProperty_ScriptName_OnDownButtonMouseUnfocus:	scriptName_OnDownButtonMouseUnfocus	= iValue; return;
		case e_UIObjectProperty_ScriptName_OnScrollBarMouseFocus:		scriptName_OnScrollBarMouseFocus	= iValue; return;
		case e_UIObjectProperty_ScriptName_OnScrollBarMouseUnfocus:		scriptName_OnScrollBarMouseUnfocus	= iValue; return;
		case e_UIObjectProperty_ScriptName_OnStepChange:				scriptName_OnStepChange				= iValue; return;

		case e_UIObjectProperty_BackgroundImage_TextureName:			backgroundImageProp.textureName		= iValue; return;
		case e_UIObjectProperty_MarkerImage_TextureName:				markerImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_UpButtonImage_TextureName:				upButtonImageProp.textureName		= iValue; return;
		case e_UIObjectProperty_DownButtonImage_TextureName:			downButtonImageProp.textureName		= iValue; return;

		default: throw invalid_argument("CVerticalScrollBar::SetProperty - iProperty is not valid VerticalScrollBar property");
		}
	}

//*****************************************************************************

bool CVerticalScrollBar::Intersect(const D3DXVECTOR2& iPosition)
	{
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale) || upButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || downButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || markerImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		return true;
	else
		return false;
	}

//*****************************************************************************

D3DXVECTOR2	CVerticalScrollBar::GetMarkerPosition()
	{	
	CorrectParams();

	D3DXVECTOR2 pos(position);
	pos += D3DXVECTOR2(markerStartPositionOffset.x*scale.x, markerStartPositionOffset.y*scale.y);	
	
	int numSteps = NumSteps();
	int tCurStep = curStep - minStep;

	if(numSteps == 0)
		return pos;

	float distance = markerEndPositionOffsetY*scale.y - markerStartPositionOffset.y*scale.y;

	pos.y += (float)tCurStep / ((float)numSteps - 1) * distance;

	return pos;
	}

//*****************************************************************************

unsigned CVerticalScrollBar::NumSteps() const
	{
	if(minStep > 0)
		return maxStep - minStep + 1;   

	if(minStep == 0)
		return maxStep + 1;

	//minStep < 0

	if(maxStep > 0)
		return maxStep + abs(minStep) + 1;   

	if(maxStep == 0)
		return abs(minStep) + 1;

	if(maxStep < 0)
		return abs(minStep) - abs(maxStep) + 1;  
	}

//*****************************************************************************

void CVerticalScrollBar::CorrectParams()
	{
	if(markerEndPositionOffsetY < markerStartPositionOffset.y)
		markerEndPositionOffsetY = markerStartPositionOffset.y;

	if(minStep > maxStep)
		minStep = maxStep;

	if(curStep < minStep)
		curStep = minStep;

	if(curStep > maxStep)
		curStep = maxStep;
	}

//*****************************************************************************

float CVerticalScrollBar::Round(const float& iValue) const
	{
		if(ceil(iValue) - iValue < 0.5)
			return ceil(iValue);
		else
			return floor(iValue);
	}

//*****************************************************************************
