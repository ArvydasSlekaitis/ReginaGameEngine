/*
    CHorizontalScrollBar.cpp - Contains class CHorizontalScrollBar implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CHorizontalScrollBar.h>
using namespace Regina::UI;


//*****************************************************************************

CHorizontalScrollBar::~CHorizontalScrollBar()
  	{
	}

//*****************************************************************************

CHorizontalScrollBar::CHorizontalScrollBar(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingScript) : CUIObject(iHWnd, iLanguage, iOriginalScreenResolution, iInterfaceName, iName, EUIObjectType::e_UIObject_HorizontalScrollBar), markerImageProp(iOriginalScreenResolution, iOriginalScreenResolution), backgroundImageProp(iOriginalScreenResolution, iOriginalScreenResolution), leftButtonImageProp(iOriginalScreenResolution, iOriginalScreenResolution), rightButtonImageProp(iOriginalScreenResolution, iOriginalScreenResolution), scriptManager(this), position(0, 0), markerStartPositionOffset(0, 0), scale(1, 1), markerEndPositionOffsetX(100), maxStep(100), minStep(0), curStep(0), scriptName_OnFrameMove(L""), scriptName_OnRender(L""), scriptName_OnLeftButtonPress(L""), scriptName_OnLeftButtonMouseFocus(L""), scriptName_OnLeftButtonMouseUnfocus(L""), scriptName_OnRightButtonPress(L""), scriptName_OnRightButtonMouseFocus(L""), scriptName_OnRightButtonMouseUnfocus(L""), scriptName_OnScrollBarMouseFocus(L""), scriptName_OnScrollBarMouseUnfocus(L""), scriptName_OnStepChange(L"")
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
	scriptManager.VariablePool().AddLocalVariable(L"markerEndPositionOffsetX", &markerEndPositionOffsetX);
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

	//Left button image
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_offsetX", &leftButtonImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_offsetY", &leftButtonImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_colorR", &leftButtonImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_colorG", &leftButtonImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_colorB", &leftButtonImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_colorA", &leftButtonImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_scaleX", &leftButtonImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_scaleY", &leftButtonImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_rotation", &leftButtonImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_textureName", &leftButtonImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"leftButtonImage_alphaIntersectionTest", &leftButtonImageProp.alphaIntersectionTest);

	//Right button image
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_offsetX", &rightButtonImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_offsetY", &rightButtonImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_colorR", &rightButtonImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_colorG", &rightButtonImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_colorB", &rightButtonImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_colorA", &rightButtonImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_scaleX", &rightButtonImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_scaleY", &rightButtonImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_rotation", &rightButtonImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_textureName", &rightButtonImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"rightButtonImage_alphaIntersectionTest", &rightButtonImageProp.alphaIntersectionTest);

	//Script Name
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnFrameMove", &scriptName_OnFrameMove);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRender", &scriptName_OnRender);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnLeftButtonPress", &scriptName_OnLeftButtonPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnLeftButtonMouseFocus", &scriptName_OnLeftButtonMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnLeftButtonMouseUnfocus", &scriptName_OnLeftButtonMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRightButtonPress", &scriptName_OnRightButtonPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRightButtonMouseFocus", &scriptName_OnRightButtonMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRightButtonMouseUnfocus", &scriptName_OnRightButtonMouseUnfocus);
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

void CHorizontalScrollBar::On_FrameMove()
  	{
	RunScript(scriptName_OnFrameMove);
	CallCallbackFunction(EUIEventType::e_UIEvent_FrameMove);

	//Process background image
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale) || leftButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || rightButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || markerImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnScrollBarMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_ScrollBarMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnScrollBarMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_ScrollBarMouseUnfocus);
		}

	//Process Left button image
	if(leftButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnLeftButtonMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_LeftButtonMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnLeftButtonMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_LeftButtonMouseUnfocus);
		}

	//Process Right button image
	if(rightButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnRightButtonMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_RightButtonMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnRightButtonMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_RightButtonMouseUnfocus);
		}
	}

//*****************************************************************************

void CHorizontalScrollBar::On_Render()
  	{
	RunScript(scriptName_OnRender);

	backgroundImageProp.Render(position, scale);

	markerImageProp.Render(GetMarkerPosition(), scale, scale);

	leftButtonImageProp.Render(position, scale, scale);
	rightButtonImageProp.Render(position, scale, scale);

	CallCallbackFunction(EUIEventType::e_UIEvent_Render);
	}

//*****************************************************************************

bool CHorizontalScrollBar::On_LeftClick(const D3DXVECTOR2& iCursorPosition)
  	{
	//Process Left button image
	if(leftButtonImageProp.Intersect(iCursorPosition, position, scale, scale))
		{
		if(curStep > minStep)
			curStep--;

		RunScript(scriptName_OnLeftButtonPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_LeftButtonPress);

		RunScript(scriptName_OnStepChange);
		CallCallbackFunction(EUIEventType::e_UIEvent_StepChange);

		return true;
		}

	//Process Right button image
	if(rightButtonImageProp.Intersect(iCursorPosition, position, scale, scale))
		{		
		if(curStep < maxStep)
			curStep++;

		RunScript(scriptName_OnRightButtonPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_RightButtonPress);

		RunScript(scriptName_OnStepChange);
		CallCallbackFunction(EUIEventType::e_UIEvent_StepChange);

		return true;
		}

	//Process Background (slider) image
	if(backgroundImageProp.Intersect(iCursorPosition, position, scale))
		{
		CorrectParams();

		D3DXVECTOR2 pos = TransformToUIScreenSpaceInverse(originalScreenResolution, screenResolution, iCursorPosition); // Position in original screen resolution
		pos -= position - backgroundImageProp.offset;		// Position in object cordinates

		if(pos.x >= markerEndPositionOffsetX*scale.x)
			curStep = maxStep;
		else
			{
			pos -= D3DXVECTOR2(markerStartPositionOffset.x*scale.x, markerStartPositionOffset.y*scale.y);	// Position relative to marker start position
			
				if(pos.x <= 0)
					curStep = minStep;
				else
					{
					int numSteps   = NumSteps();

					float distance = markerEndPositionOffsetX*scale.x - markerStartPositionOffset.x*scale.x;

					float tStep = pos.x / distance * ((float)numSteps - 1);
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
	
void CHorizontalScrollBar::On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	backgroundImageProp.SetScreenResolution(iScreenResolution);
	markerImageProp.SetScreenResolution(iScreenResolution);
	leftButtonImageProp.SetScreenResolution(iScreenResolution);
	rightButtonImageProp.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************
	
void CHorizontalScrollBar::GetInitializingText(vector<wstring>& oText)
	{
	oText.push_back(L"HorizontalScrollBar " + Name());
	oText.push_back(L"{");
	scriptManager.VariablePool().GetInitializingScriptText(oText);
	oText.push_back(L"}");
	}

//*****************************************************************************

void CHorizontalScrollBar::RunScript(const wstring& iScriptName)
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

bool CHorizontalScrollBar::GetProperty(const EUIObjectProperty_Bool& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								return visible;
		case e_UIObjectProperty_Active:									return active;

		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	return backgroundImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_MarkerImage_AlphaIntersectionTest:		return markerImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_LeftButtonImage_AlphaIntersectionTest:	return leftButtonImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_RightButtonImage_AlphaIntersectionTest:	return rightButtonImageProp.alphaIntersectionTest;
	
		default: throw invalid_argument("CHorizontalScrollBar::GetProperty - iProperty is not valid HorizontalScrollBar property");
		}
	}

//*****************************************************************************

int	CHorizontalScrollBar::GetProperty(const EUIObjectProperty_Int& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_MaxStep:		return maxStep;
		case e_UIObjectProperty_MinStep:		return minStep;
		case e_UIObjectProperty_CurStep:		return curStep;

		default: throw invalid_argument("CHorizontalScrollBar::GetProperty - iProperty is not valid HorizontalScrollBar property");
		}
	}

//*****************************************************************************

float CHorizontalScrollBar::GetProperty(const EUIObjectProperty_Float& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:					return position.x;
		case e_UIObjectProperty_PositionY:					return position.y;

		case e_UIObjectProperty_ScaleX:						return scale.x;
		case e_UIObjectProperty_ScaleY:						return scale.y;

		case e_UIObjectProperty_MarkerStartPositionOffsetX:	return markerStartPositionOffset.x;
		case e_UIObjectProperty_MarkerStartPositionOffsetY:	return markerStartPositionOffset.y;
		case e_UIObjectProperty_MarkerEndPositionOffsetX:	return markerEndPositionOffsetX;

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

		case e_UIObjectProperty_LeftButtonImage_OffsetX:	return leftButtonImageProp.offset.x;
		case e_UIObjectProperty_LeftButtonImage_OffsetY:	return leftButtonImageProp.offset.y;
		case e_UIObjectProperty_LeftButtonImage_ColorR:		return leftButtonImageProp.color.r;
		case e_UIObjectProperty_LeftButtonImage_ColorG:		return leftButtonImageProp.color.g;
		case e_UIObjectProperty_LeftButtonImage_ColorB:		return leftButtonImageProp.color.b;
		case e_UIObjectProperty_LeftButtonImage_ColorA:		return leftButtonImageProp.color.a;
		case e_UIObjectProperty_LeftButtonImage_ScaleX:		return leftButtonImageProp.scale.x;
		case e_UIObjectProperty_LeftButtonImage_ScaleY:		return leftButtonImageProp.scale.y;
		case e_UIObjectProperty_LeftButtonImage_Rotation:	return leftButtonImageProp.rotation;

		case e_UIObjectProperty_RightButtonImage_OffsetX:	return rightButtonImageProp.offset.x;
		case e_UIObjectProperty_RightButtonImage_OffsetY:	return rightButtonImageProp.offset.y;
		case e_UIObjectProperty_RightButtonImage_ColorR:	return rightButtonImageProp.color.r;
		case e_UIObjectProperty_RightButtonImage_ColorG:	return rightButtonImageProp.color.g;
		case e_UIObjectProperty_RightButtonImage_ColorB:	return rightButtonImageProp.color.b;
		case e_UIObjectProperty_RightButtonImage_ColorA:	return rightButtonImageProp.color.a;
		case e_UIObjectProperty_RightButtonImage_ScaleX:	return rightButtonImageProp.scale.x;
		case e_UIObjectProperty_RightButtonImage_ScaleY:	return rightButtonImageProp.scale.y;
		case e_UIObjectProperty_RightButtonImage_Rotation:	return rightButtonImageProp.rotation;

		default: throw invalid_argument("CHorizontalScrollBar::GetProperty - iProperty is not valid HorizontalScrollBar property");
		}
	}

//*****************************************************************************

wstring	CHorizontalScrollBar::GetProperty(const EUIObjectProperty_String& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:					return scriptName_OnFrameMove;
		case e_UIObjectProperty_ScriptName_OnRender:					return scriptName_OnRender;
		case e_UIObjectProperty_ScriptName_OnLeftButtonPress:			return scriptName_OnLeftButtonPress;
		case e_UIObjectProperty_ScriptName_OnLeftButtonMouseFocus:		return scriptName_OnLeftButtonMouseFocus;
		case e_UIObjectProperty_ScriptName_OnLeftButtonMouseUnfocus:	return scriptName_OnLeftButtonMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnRightButtonPress:			return scriptName_OnRightButtonPress;
		case e_UIObjectProperty_ScriptName_OnRightButtonMouseFocus:		return scriptName_OnRightButtonMouseFocus;
		case e_UIObjectProperty_ScriptName_OnRightButtonMouseUnfocus:	return scriptName_OnRightButtonMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnScrollBarMouseFocus:		return scriptName_OnScrollBarMouseFocus;
		case e_UIObjectProperty_ScriptName_OnScrollBarMouseUnfocus:		return scriptName_OnScrollBarMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnStepChange:				return scriptName_OnStepChange;

		case e_UIObjectProperty_BackgroundImage_TextureName:			return backgroundImageProp.textureName;
		case e_UIObjectProperty_MarkerImage_TextureName:				return markerImageProp.textureName;
		case e_UIObjectProperty_LeftButtonImage_TextureName:			return leftButtonImageProp.textureName;
		case e_UIObjectProperty_RightButtonImage_TextureName:			return rightButtonImageProp.textureName;

		default: throw invalid_argument("CHorizontalScrollBar::GetProperty - iProperty is not valid HorizontalScrollBar property");
		}
	}

//*****************************************************************************

void CHorizontalScrollBar::SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								visible										= iValue; return;
		case e_UIObjectProperty_Active:									active										= iValue; return;

		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	backgroundImageProp.alphaIntersectionTest	= iValue; return;
		case e_UIObjectProperty_MarkerImage_AlphaIntersectionTest:		markerImageProp.alphaIntersectionTest		= iValue; return;
		case e_UIObjectProperty_LeftButtonImage_AlphaIntersectionTest:	leftButtonImageProp.alphaIntersectionTest	= iValue; return;
		case e_UIObjectProperty_RightButtonImage_AlphaIntersectionTest:	rightButtonImageProp.alphaIntersectionTest	= iValue; return;
			
		default: throw invalid_argument("CHorizontalScrollBar::SetProperty - iProperty is not valid HorizontalScrollBar property");
		}
	}

//*****************************************************************************

void CHorizontalScrollBar::SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_MaxStep:		maxStep			= iValue; return;
		case e_UIObjectProperty_MinStep:		minStep			= iValue; return;
		case e_UIObjectProperty_CurStep:		curStep			= iValue; return;

		default: throw invalid_argument("CHorizontalScrollBar::SetProperty - iProperty is not valid HorizontalScrollBar property");
		}
	}

//*****************************************************************************

void CHorizontalScrollBar::SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:					position.x						= iValue; return;
		case e_UIObjectProperty_PositionY:					position.y						= iValue; return;

		case e_UIObjectProperty_ScaleX:						scale.x							= iValue; return;
		case e_UIObjectProperty_ScaleY:						scale.y							= iValue; return;

		case e_UIObjectProperty_MarkerStartPositionOffsetX:	markerStartPositionOffset.x		= iValue; return;
		case e_UIObjectProperty_MarkerStartPositionOffsetY:	markerStartPositionOffset.y		= iValue; return;
		case e_UIObjectProperty_MarkerEndPositionOffsetX:	markerEndPositionOffsetX		= iValue; return;

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

		case e_UIObjectProperty_LeftButtonImage_OffsetX:	leftButtonImageProp.offset.x	= iValue; return;
		case e_UIObjectProperty_LeftButtonImage_OffsetY:	leftButtonImageProp.offset.y	= iValue; return;
		case e_UIObjectProperty_LeftButtonImage_ColorR:		leftButtonImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_LeftButtonImage_ColorG:		leftButtonImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_LeftButtonImage_ColorB:		leftButtonImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_LeftButtonImage_ColorA:		leftButtonImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_LeftButtonImage_ScaleX:		leftButtonImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_LeftButtonImage_ScaleY:		leftButtonImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_LeftButtonImage_Rotation:	leftButtonImageProp.rotation	= iValue; return;

		case e_UIObjectProperty_RightButtonImage_OffsetX:	rightButtonImageProp.offset.x	= iValue; return;
		case e_UIObjectProperty_RightButtonImage_OffsetY:	rightButtonImageProp.offset.y	= iValue; return;
		case e_UIObjectProperty_RightButtonImage_ColorR:	rightButtonImageProp.color.r	= iValue; return;
		case e_UIObjectProperty_RightButtonImage_ColorG:	rightButtonImageProp.color.g	= iValue; return;
		case e_UIObjectProperty_RightButtonImage_ColorB:	rightButtonImageProp.color.b	= iValue; return;
		case e_UIObjectProperty_RightButtonImage_ColorA:	rightButtonImageProp.color.a	= iValue; return;
		case e_UIObjectProperty_RightButtonImage_ScaleX:	rightButtonImageProp.scale.x	= iValue; return;
		case e_UIObjectProperty_RightButtonImage_ScaleY:	rightButtonImageProp.scale.y	= iValue; return;
		case e_UIObjectProperty_RightButtonImage_Rotation:	rightButtonImageProp.rotation	= iValue; return;

		default: throw invalid_argument("CHorizontalScrollBar::SetProperty - iProperty is not valid HorizontalScrollBar property");
		}
	}

//*****************************************************************************

void CHorizontalScrollBar::SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:					scriptName_OnFrameMove					= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRender:					scriptName_OnRender						= iValue; return;
		case e_UIObjectProperty_ScriptName_OnLeftButtonPress:			scriptName_OnLeftButtonPress			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnLeftButtonMouseFocus:		scriptName_OnLeftButtonMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnLeftButtonMouseUnfocus:	scriptName_OnLeftButtonMouseUnfocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRightButtonPress:			scriptName_OnRightButtonPress			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRightButtonMouseFocus:		scriptName_OnRightButtonMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRightButtonMouseUnfocus:	scriptName_OnRightButtonMouseUnfocus	= iValue; return;
		case e_UIObjectProperty_ScriptName_OnScrollBarMouseFocus:		scriptName_OnScrollBarMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnScrollBarMouseUnfocus:		scriptName_OnScrollBarMouseUnfocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnStepChange:				scriptName_OnStepChange					= iValue; return;

		case e_UIObjectProperty_BackgroundImage_TextureName:			backgroundImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_MarkerImage_TextureName:				markerImageProp.textureName				= iValue; return;
		case e_UIObjectProperty_LeftButtonImage_TextureName:			leftButtonImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_RightButtonImage_TextureName:			rightButtonImageProp.textureName		= iValue; return;

		default: throw invalid_argument("CHorizontalScrollBar::SetProperty - iProperty is not valid HorizontalScrollBar property");
		}
	}

//*****************************************************************************

bool CHorizontalScrollBar::Intersect(const D3DXVECTOR2& iPosition)
	{
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale) || leftButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || rightButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || markerImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		return true;
	else
		return false;
	}

//*****************************************************************************

D3DXVECTOR2	CHorizontalScrollBar::GetMarkerPosition()
	{	
	CorrectParams();

	D3DXVECTOR2 pos(position);
	pos += D3DXVECTOR2(markerStartPositionOffset.x*scale.x, markerStartPositionOffset.y*scale.y);	
	
	int numSteps = NumSteps();
	int tCurStep = curStep - minStep;

	if(numSteps == 0)
		return pos;

	float distance = markerEndPositionOffsetX*scale.x - markerStartPositionOffset.x*scale.x;

	pos.x += (float)tCurStep / ((float)numSteps - 1) * distance;

	return pos;
	}

//*****************************************************************************

unsigned CHorizontalScrollBar::NumSteps() const
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

void CHorizontalScrollBar::CorrectParams()
	{
	if(markerEndPositionOffsetX < markerStartPositionOffset.x)
		markerEndPositionOffsetX = markerStartPositionOffset.x;

	if(minStep > maxStep)
		minStep = maxStep;

	if(curStep < minStep)
		curStep = minStep;

	if(curStep > maxStep)
		curStep = maxStep;
	}

//*****************************************************************************

float CHorizontalScrollBar::Round(const float& iValue) const
	{
		if(ceil(iValue) - iValue < 0.5)
			return ceil(iValue);
		else
			return floor(iValue);
	}

//*****************************************************************************
