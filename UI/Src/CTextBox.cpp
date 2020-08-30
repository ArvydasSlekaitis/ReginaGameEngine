/*
    CTextBox.cpp - Contains class CTextBox implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CTextBox.h>
using namespace Regina::UI;


//*****************************************************************************

CTextBox::~CTextBox()
  	{
	}

//*****************************************************************************

CTextBox::CTextBox(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingScript) : CUIObject(iHWnd, iLanguage, iOriginalScreenResolution, iInterfaceName, iName, EUIObjectType::e_UIObject_TextBox), textProp(iOriginalScreenResolution, iOriginalScreenResolution), backgroundImageProp(iOriginalScreenResolution, iOriginalScreenResolution), verticalScrollBar_MarkerImageProp(iOriginalScreenResolution, iOriginalScreenResolution), verticalScrollBar_BackgroundImageProp(iOriginalScreenResolution, iOriginalScreenResolution), verticalScrollBar_UpButtonImageProp(iOriginalScreenResolution, iOriginalScreenResolution), verticalScrollBar_DownButtonImageProp(iOriginalScreenResolution, iOriginalScreenResolution), scriptManager(this), position(0, 0), scale(1, 1), verticalScrollBar_MarkerStartPositionOffset(0, 0), verticalScrollBar_MarkerEndPositionOffsetY(100), verticalScrollBar_CurStep(0), scriptName_OnFrameMove(L""), scriptName_OnRender(L""), scriptName_OnVerticalScrollBar_UpButtonPress(L""), scriptName_OnVerticalScrollBar_UpButtonMouseFocus(L""), scriptName_OnVerticalScrollBar_UpButtonMouseUnfocus(L""), scriptName_OnVerticalScrollBar_DownButtonPress(L""), scriptName_OnVerticalScrollBar_DownButtonMouseFocus(L""), scriptName_OnVerticalScrollBar_DownButtonMouseUnfocus(L""), scriptName_OnTextBoxMouseFocus(L""), scriptName_OnTextBoxMouseUnfocus(L"")
  	{
	scriptManager.VariablePool().AddLocalVariable(L"elapsedTime", &elapsedTime);
	scriptManager.VariablePool().AddLocalVariable(L"time", &time);
	scriptManager.VariablePool().AddLocalVariable(L"visible", &visible);
	scriptManager.VariablePool().AddLocalVariable(L"active", &active);

	scriptManager.VariablePool().AddLocalVariable(L"positionX", &position.x);
	scriptManager.VariablePool().AddLocalVariable(L"positionY", &position.y);

	scriptManager.VariablePool().AddLocalVariable(L"scaleX", &scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"scaleY", &scale.y);

	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerStartPositionOffsetX", &verticalScrollBar_MarkerStartPositionOffset.x);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerStartPositionOffsetY", &verticalScrollBar_MarkerStartPositionOffset.y);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerEndPositionOffsetY", &verticalScrollBar_MarkerEndPositionOffsetY);

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

	//VerticalScrollBar Background image
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_offsetX", &verticalScrollBar_BackgroundImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_offsetY", &verticalScrollBar_BackgroundImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_colorR", &verticalScrollBar_BackgroundImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_colorG", &verticalScrollBar_BackgroundImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_colorB", &verticalScrollBar_BackgroundImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_colorA", &verticalScrollBar_BackgroundImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_scaleX", &verticalScrollBar_BackgroundImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_scaleY", &verticalScrollBar_BackgroundImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_rotation", &verticalScrollBar_BackgroundImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_textureName", &verticalScrollBar_BackgroundImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_BackgroundImage_alphaIntersectionTest", &verticalScrollBar_BackgroundImageProp.alphaIntersectionTest);

	//VerticalScrollBar Marker image
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerImage_colorR", &verticalScrollBar_MarkerImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerImage_colorG", &verticalScrollBar_MarkerImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerImage_colorB", &verticalScrollBar_MarkerImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerImage_colorA", &verticalScrollBar_MarkerImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerImage_scaleX", &verticalScrollBar_MarkerImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerImage_scaleY", &verticalScrollBar_MarkerImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerImage_rotation", &verticalScrollBar_MarkerImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerImage_textureName", &verticalScrollBar_MarkerImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_MarkerImage_alphaIntersectionTest", &verticalScrollBar_MarkerImageProp.alphaIntersectionTest);

	//VerticalScrollBar Up button image
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_offsetX", &verticalScrollBar_UpButtonImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_offsetY", &verticalScrollBar_UpButtonImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_colorR", &verticalScrollBar_UpButtonImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_colorG", &verticalScrollBar_UpButtonImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_colorB", &verticalScrollBar_UpButtonImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_colorA", &verticalScrollBar_UpButtonImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_scaleX", &verticalScrollBar_UpButtonImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_scaleY", &verticalScrollBar_UpButtonImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_rotation", &verticalScrollBar_UpButtonImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_textureName", &verticalScrollBar_UpButtonImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_UpButtonImage_alphaIntersectionTest", &verticalScrollBar_UpButtonImageProp.alphaIntersectionTest);

	//VerticalScrollBar Down button image
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_offsetX", &verticalScrollBar_DownButtonImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_offsetY", &verticalScrollBar_DownButtonImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_colorR", &verticalScrollBar_DownButtonImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_colorG", &verticalScrollBar_DownButtonImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_colorB", &verticalScrollBar_DownButtonImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_colorA", &verticalScrollBar_DownButtonImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_scaleX", &verticalScrollBar_DownButtonImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_scaleY", &verticalScrollBar_DownButtonImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_rotation", &verticalScrollBar_DownButtonImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_textureName", &verticalScrollBar_DownButtonImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"verticalScrollBar_DownButtonImage_alphaIntersectionTest", &verticalScrollBar_DownButtonImageProp.alphaIntersectionTest);

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
	scriptManager.VariablePool().AddLocalVariable(L"text_fileName", &textProp.fileName);
	scriptManager.VariablePool().AddLocalVariable(L"text_lineDistance", &textProp.lineDistance);
	scriptManager.VariablePool().AddLocalVariable(L"text_maxTextSizeX", &textProp.maxTextSizeX);
	scriptManager.VariablePool().AddLocalVariable(L"text_maxTextSizeY", &textProp.maxTextSizeY);

	//Script Name
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnFrameMove", &scriptName_OnFrameMove);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRender", &scriptName_OnRender);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnVerticalScrollBar_UpButtonPress", &scriptName_OnVerticalScrollBar_UpButtonPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnVerticalScrollBar_UpButtonMouseFocus", &scriptName_OnVerticalScrollBar_UpButtonMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnVerticalScrollBar_UpButtonMouseUnfocus", &scriptName_OnVerticalScrollBar_UpButtonMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnVerticalScrollBar_DownButtonPress", &scriptName_OnVerticalScrollBar_DownButtonPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnVerticalScrollBar_DownButtonMouseFocus", &scriptName_OnVerticalScrollBar_DownButtonMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnVerticalScrollBar_DownButtonMouseUnfocus", &scriptName_OnVerticalScrollBar_DownButtonMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnTextBoxMouseFocus", &scriptName_OnTextBoxMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnTextBoxMouseUnfocus", &scriptName_OnTextBoxMouseUnfocus);

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

void CTextBox::On_FrameMove()
  	{
	RunScript(scriptName_OnFrameMove);
	CallCallbackFunction(EUIEventType::e_UIEvent_FrameMove);

	//Process TextBox MouseFocus/Unfocus part
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale) || textProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || verticalScrollBar_BackgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || verticalScrollBar_UpButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || verticalScrollBar_DownButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || verticalScrollBar_MarkerImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnTextBoxMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_TextBoxMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnTextBoxMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_TextBoxMouseUnfocus);
		}

	//Process VerticalScrollBar Up button image
	if(verticalScrollBar_UpButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnVerticalScrollBar_UpButtonMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_OnVerticalScrollBar_UpButtonMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnVerticalScrollBar_UpButtonMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_OnVerticalScrollBar_UpButtonMouseUnfocus);
		}

	//Process VerticalScrollBar Down button image
	if(verticalScrollBar_DownButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnVerticalScrollBar_DownButtonMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_OnVerticalScrollBar_DownButtonMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnVerticalScrollBar_DownButtonMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_OnVerticalScrollBar_DownButtonMouseUnfocus);
		}
	}

//*****************************************************************************

void CTextBox::On_Render()
  	{
	RunScript(scriptName_OnRender);

	backgroundImageProp.Render(position, scale);

	textProp.Render(position, verticalScrollBar_CurStep, scale, scale);

	verticalScrollBar_BackgroundImageProp.Render(position, scale, scale);
	verticalScrollBar_MarkerImageProp.Render(GetMarkerPosition(), scale, scale);
	verticalScrollBar_UpButtonImageProp.Render(position, scale, scale);
	verticalScrollBar_DownButtonImageProp.Render(position, scale, scale);

	CallCallbackFunction(EUIEventType::e_UIEvent_Render);
	}

//*****************************************************************************

bool CTextBox::On_LeftClick(const D3DXVECTOR2& iCursorPosition)
  	{
	//Process Up button image
	if(verticalScrollBar_UpButtonImageProp.Intersect(iCursorPosition, position, scale, scale))
		{
		if(verticalScrollBar_CurStep > MinStep())
			verticalScrollBar_CurStep--;

		RunScript(scriptName_OnVerticalScrollBar_UpButtonPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_OnVerticalScrollBar_UpButtonPress);

		return true;
		}

	//Process Down button image
	if(verticalScrollBar_DownButtonImageProp.Intersect(iCursorPosition, position, scale, scale))
		{		
		if(verticalScrollBar_CurStep < MaxStep())
			verticalScrollBar_CurStep++;

		RunScript(scriptName_OnVerticalScrollBar_DownButtonPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_OnVerticalScrollBar_DownButtonPress);

		return true;
		}

	//Process VerticalScrollBar Background (slider) image
	if(verticalScrollBar_BackgroundImageProp.Intersect(iCursorPosition, position, scale, scale))
		{
		CorrectParams();

		D3DXVECTOR2 pos = TransformToUIScreenSpaceInverse(originalScreenResolution, screenResolution, iCursorPosition); // Position in original screen resolution
		pos -= position - verticalScrollBar_BackgroundImageProp.offset;;					// Position in object cordinates

		if(pos.y >= verticalScrollBar_MarkerEndPositionOffsetY*scale.y)
			verticalScrollBar_CurStep = MaxStep();
		else
			{
			pos -= D3DXVECTOR2(verticalScrollBar_MarkerStartPositionOffset.x*scale.x, verticalScrollBar_MarkerStartPositionOffset.y*scale.y);	// Position relative to marker start position
			
				if(pos.y <= 0)
					verticalScrollBar_CurStep = MinStep();
				else
					{
					int numSteps   = NumSteps();

					float distance = verticalScrollBar_MarkerEndPositionOffsetY*scale.y - verticalScrollBar_MarkerStartPositionOffset.y*scale.y;

					float tStep = pos.y / distance * ((float)numSteps - 1);
					tStep += MinStep();

					verticalScrollBar_CurStep = Round(tStep);				
					}
			}

		return true;
		}

	return false;
	}

//*****************************************************************************
	
void CTextBox::On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	backgroundImageProp.SetScreenResolution(iScreenResolution);
	textProp.SetScreenResolution(iScreenResolution);
	verticalScrollBar_BackgroundImageProp.SetScreenResolution(iScreenResolution);
	verticalScrollBar_MarkerImageProp.SetScreenResolution(iScreenResolution);
	verticalScrollBar_UpButtonImageProp.SetScreenResolution(iScreenResolution);
	verticalScrollBar_DownButtonImageProp.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************
	
void CTextBox::GetInitializingText(vector<wstring>& oText)
	{
	oText.push_back(L"TextBox " + Name());
	oText.push_back(L"{");
	scriptManager.VariablePool().GetInitializingScriptText(oText);
	oText.push_back(L"}");
	}

//*****************************************************************************

void CTextBox::RunScript(const wstring& iScriptName)
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

bool CTextBox::GetProperty(const EUIObjectProperty_Bool& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:													return visible;
		case e_UIObjectProperty_Active:														return active;

		case e_UIObjectProperty_Text_Italic:												return textProp.italic;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:						return backgroundImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_AlphaIntersectionTest:	return verticalScrollBar_BackgroundImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_VerticlaScrollBar_MarkerImage_AlphaIntersectionTest:		return verticalScrollBar_MarkerImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_VerticlaScrollBar_UpButtonImage_AlphaIntersectionTest:		return verticalScrollBar_UpButtonImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_VerticlaScrollBar_DownButtonImage_AlphaIntersectionTest:	return verticalScrollBar_DownButtonImageProp.alphaIntersectionTest;
	
		default: throw invalid_argument("CTextBox::GetProperty - iProperty is not valid TextBox property");
		}
	}

//*****************************************************************************

int	CTextBox::GetProperty(const EUIObjectProperty_Int& iProperty)
	{
	switch(iProperty)
		{	
		default: throw invalid_argument("CTextBox::GetProperty - iProperty is not valid TextBox property");
		}
	}

//*****************************************************************************

float CTextBox::GetProperty(const EUIObjectProperty_Float& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:										return position.x;
		case e_UIObjectProperty_PositionY:										return position.y;
			
		case e_UIObjectProperty_ScaleX:											return scale.x;
		case e_UIObjectProperty_ScaleY:											return scale.y;

		case e_UIObjectProperty_VerticalScrollBar_MarkerStartPositionOffsetX:	return verticalScrollBar_MarkerStartPositionOffset.x;
		case e_UIObjectProperty_VerticalScrollBar_MarkerStartPositionOffsetY:	return verticalScrollBar_MarkerStartPositionOffset.y;
		case e_UIObjectProperty_VerticalScrollBar_MarkerEndPositionOffsetY:		return verticalScrollBar_MarkerEndPositionOffsetY;

		case e_UIObjectProperty_BackgroundImage_OffsetX:						return backgroundImageProp.offset.x;
		case e_UIObjectProperty_BackgroundImage_OffsetY:						return backgroundImageProp.offset.y;
		case e_UIObjectProperty_BackgroundImage_ColorR:							return backgroundImageProp.color.r;
		case e_UIObjectProperty_BackgroundImage_ColorG:							return backgroundImageProp.color.g;
		case e_UIObjectProperty_BackgroundImage_ColorB:							return backgroundImageProp.color.b;
		case e_UIObjectProperty_BackgroundImage_ColorA:							return backgroundImageProp.color.a;
		case e_UIObjectProperty_BackgroundImage_ScaleX:							return backgroundImageProp.scale.x;
		case e_UIObjectProperty_BackgroundImage_ScaleY:							return backgroundImageProp.scale.y;
		case e_UIObjectProperty_BackgroundImage_Rotation:						return backgroundImageProp.rotation;

		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_OffsetX:		return verticalScrollBar_BackgroundImageProp.offset.x;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_OffsetY:		return verticalScrollBar_BackgroundImageProp.offset.y;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ColorR:		return verticalScrollBar_BackgroundImageProp.color.r;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ColorG:		return verticalScrollBar_BackgroundImageProp.color.g;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ColorB:		return verticalScrollBar_BackgroundImageProp.color.b;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ColorA:		return verticalScrollBar_BackgroundImageProp.color.a;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ScaleX:		return verticalScrollBar_BackgroundImageProp.scale.x;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ScaleY:		return verticalScrollBar_BackgroundImageProp.scale.y;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_Rotation:		return verticalScrollBar_BackgroundImageProp.rotation;

		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_OffsetX:			return verticalScrollBar_MarkerImageProp.offset.x;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_OffsetY:			return verticalScrollBar_MarkerImageProp.offset.y;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ColorR:			return verticalScrollBar_MarkerImageProp.color.r;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ColorG:			return verticalScrollBar_MarkerImageProp.color.g;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ColorB:			return verticalScrollBar_MarkerImageProp.color.b;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ColorA:			return verticalScrollBar_MarkerImageProp.color.a;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ScaleX:			return verticalScrollBar_MarkerImageProp.scale.x;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ScaleY:			return verticalScrollBar_MarkerImageProp.scale.y;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_Rotation:			return verticalScrollBar_MarkerImageProp.rotation;

		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_OffsetX:		return verticalScrollBar_UpButtonImageProp.offset.x;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_OffsetY:		return verticalScrollBar_UpButtonImageProp.offset.y;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ColorR:			return verticalScrollBar_UpButtonImageProp.color.r;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ColorG:			return verticalScrollBar_UpButtonImageProp.color.g;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ColorB:			return verticalScrollBar_UpButtonImageProp.color.b;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ColorA:			return verticalScrollBar_UpButtonImageProp.color.a;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ScaleX:			return verticalScrollBar_UpButtonImageProp.scale.x;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ScaleY:			return verticalScrollBar_UpButtonImageProp.scale.y;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_Rotation:		return verticalScrollBar_UpButtonImageProp.rotation;

		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_OffsetX:		return verticalScrollBar_DownButtonImageProp.offset.x;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_OffsetY:		return verticalScrollBar_DownButtonImageProp.offset.y;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ColorR:		return verticalScrollBar_DownButtonImageProp.color.r;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ColorG:		return verticalScrollBar_DownButtonImageProp.color.g;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ColorB:		return verticalScrollBar_DownButtonImageProp.color.b;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ColorA:		return verticalScrollBar_DownButtonImageProp.color.a;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ScaleX:		return verticalScrollBar_DownButtonImageProp.scale.x;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ScaleY:		return verticalScrollBar_DownButtonImageProp.scale.y;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_Rotation:		return verticalScrollBar_DownButtonImageProp.rotation;

		case e_UIObjectProperty_Text_OffsetX:									return textProp.offset.x;
		case e_UIObjectProperty_Text_OffsetY:									return textProp.offset.y;
		case e_UIObjectProperty_Text_ColorR:									return textProp.color.r;
		case e_UIObjectProperty_Text_ColorG:									return textProp.color.g;
		case e_UIObjectProperty_Text_ColorB:									return textProp.color.b;
		case e_UIObjectProperty_Text_ColorA:									return textProp.color.a;
		case e_UIObjectProperty_Text_Height:									return textProp.height;
		case e_UIObjectProperty_Text_Weight:									return textProp.weight;
		case e_UIObjectProperty_Text_LineDistance:								return textProp.lineDistance;
		case e_UIObjectProperty_Text_MaxTextSizeX:								return textProp.maxTextSizeX;
		case e_UIObjectProperty_Text_MaxTextSizeY:								return textProp.maxTextSizeY;

		default: throw invalid_argument("CTextBox::GetProperty - iProperty is not valid TextBox property");
		}
	}

//*****************************************************************************

wstring	CTextBox::GetProperty(const EUIObjectProperty_String& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:									return scriptName_OnFrameMove;
		case e_UIObjectProperty_ScriptName_OnRender:									return scriptName_OnRender;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_UpButtonPress:			return scriptName_OnVerticalScrollBar_UpButtonPress;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_UpButtonMouseFocus:		return scriptName_OnVerticalScrollBar_UpButtonMouseFocus;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_UpButtonMouseUnfocus:	return scriptName_OnVerticalScrollBar_UpButtonMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_DownButtonPress:			return scriptName_OnVerticalScrollBar_DownButtonPress;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_DownButtonMouseFocus:	return scriptName_OnVerticalScrollBar_DownButtonMouseFocus;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_DownButtonMouseUnfocus:	return scriptName_OnVerticalScrollBar_DownButtonMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnTextBoxMouseFocus:							return scriptName_OnTextBoxMouseFocus;
		case e_UIObjectProperty_ScriptName_OnTextBoxMouseUnfocus:						return scriptName_OnTextBoxMouseUnfocus;

			
		case e_UIObjectProperty_BackgroundImage_TextureName:							return backgroundImageProp.textureName;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_TextureName:			return verticalScrollBar_BackgroundImageProp.textureName;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_TextureName:				return verticalScrollBar_MarkerImageProp.textureName;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_TextureName:			return verticalScrollBar_UpButtonImageProp.textureName;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_TextureName:			return verticalScrollBar_DownButtonImageProp.textureName;

		case e_UIObjectProperty_Text_Facename:											return textProp.facename;
		case e_UIObjectProperty_Text_FileName:											return textProp.fileName;

		default: throw invalid_argument("CTextBox::GetProperty - iProperty is not valid TextBox property");
		}
	}

//*****************************************************************************

void CTextBox::SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:													visible															= iValue; return;
		case e_UIObjectProperty_Active:														active															= iValue; return;
		
		case e_UIObjectProperty_Text_Italic:												textProp.italic													= iValue; return;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:						backgroundImageProp.alphaIntersectionTest						= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_AlphaIntersectionTest:	verticalScrollBar_BackgroundImageProp.alphaIntersectionTest		= iValue; return;
		case e_UIObjectProperty_VerticlaScrollBar_MarkerImage_AlphaIntersectionTest:		verticalScrollBar_MarkerImageProp.alphaIntersectionTest			= iValue; return;
		case e_UIObjectProperty_VerticlaScrollBar_UpButtonImage_AlphaIntersectionTest:		verticalScrollBar_UpButtonImageProp.alphaIntersectionTest		= iValue; return;
		case e_UIObjectProperty_VerticlaScrollBar_DownButtonImage_AlphaIntersectionTest:	verticalScrollBar_DownButtonImageProp.alphaIntersectionTest		= iValue; return;

		default: throw invalid_argument("CTextBox::SetProperty - iProperty is not valid TextBox property");
		}
	}

//*****************************************************************************

void CTextBox::SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	switch(iProperty)
		{
		default: throw invalid_argument("CTextBox::SetProperty - iProperty is not valid TextBox property");
		}
	}

//*****************************************************************************

void CTextBox::SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:										position.x											= iValue; return;
		case e_UIObjectProperty_PositionY:										position.y											= iValue; return;

		case e_UIObjectProperty_ScaleX:											scale.x												= iValue; return;
		case e_UIObjectProperty_ScaleY:											scale.y												= iValue; return;

		case e_UIObjectProperty_VerticalScrollBar_MarkerStartPositionOffsetX:	verticalScrollBar_MarkerStartPositionOffset.x		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerStartPositionOffsetY:	verticalScrollBar_MarkerStartPositionOffset.y		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerEndPositionOffsetY:		verticalScrollBar_MarkerEndPositionOffsetY			= iValue; return;

		case e_UIObjectProperty_BackgroundImage_OffsetX:						backgroundImageProp.offset.x						= iValue; return;
		case e_UIObjectProperty_BackgroundImage_OffsetY:						backgroundImageProp.offset.y						= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorR:							backgroundImageProp.color.r							= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorG:							backgroundImageProp.color.g							= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorB:							backgroundImageProp.color.b							= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorA:							backgroundImageProp.color.a							= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ScaleX:							backgroundImageProp.scale.x							= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ScaleY:							backgroundImageProp.scale.y							= iValue; return;
		case e_UIObjectProperty_BackgroundImage_Rotation:						backgroundImageProp.rotation						= iValue; return;

		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_OffsetX:		verticalScrollBar_BackgroundImageProp.offset.x		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_OffsetY:		verticalScrollBar_BackgroundImageProp.offset.y		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ColorR:		verticalScrollBar_BackgroundImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ColorG:		verticalScrollBar_BackgroundImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ColorB:		verticalScrollBar_BackgroundImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ColorA:		verticalScrollBar_BackgroundImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ScaleX:		verticalScrollBar_BackgroundImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_ScaleY:		verticalScrollBar_BackgroundImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_Rotation:		verticalScrollBar_BackgroundImageProp.rotation		= iValue; return;

		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_OffsetX:			verticalScrollBar_MarkerImageProp.offset.x			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_OffsetY:			verticalScrollBar_MarkerImageProp.offset.y			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ColorR:			verticalScrollBar_MarkerImageProp.color.r			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ColorG:			verticalScrollBar_MarkerImageProp.color.g			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ColorB:			verticalScrollBar_MarkerImageProp.color.b			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ColorA:			verticalScrollBar_MarkerImageProp.color.a			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ScaleX:			verticalScrollBar_MarkerImageProp.scale.x			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_ScaleY:			verticalScrollBar_MarkerImageProp.scale.y			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_Rotation:			verticalScrollBar_MarkerImageProp.rotation			= iValue; return;

		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_OffsetX:		verticalScrollBar_UpButtonImageProp.offset.x		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_OffsetY:		verticalScrollBar_UpButtonImageProp.offset.y		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ColorR:			verticalScrollBar_UpButtonImageProp.color.r			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ColorG:			verticalScrollBar_UpButtonImageProp.color.g			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ColorB:			verticalScrollBar_UpButtonImageProp.color.b			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ColorA:			verticalScrollBar_UpButtonImageProp.color.a			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ScaleX:			verticalScrollBar_UpButtonImageProp.scale.x			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_ScaleY:			verticalScrollBar_UpButtonImageProp.scale.y			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_Rotation:		verticalScrollBar_UpButtonImageProp.rotation		= iValue; return;

		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_OffsetX:		verticalScrollBar_DownButtonImageProp.offset.x		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_OffsetY:		verticalScrollBar_DownButtonImageProp.offset.y		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ColorR:		verticalScrollBar_DownButtonImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ColorG:		verticalScrollBar_DownButtonImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ColorB:		verticalScrollBar_DownButtonImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ColorA:		verticalScrollBar_DownButtonImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ScaleX:		verticalScrollBar_DownButtonImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_ScaleY:		verticalScrollBar_DownButtonImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_Rotation:		verticalScrollBar_DownButtonImageProp.rotation		= iValue; return;

		case e_UIObjectProperty_Text_OffsetX:									textProp.offset.x									= iValue; return;
		case e_UIObjectProperty_Text_OffsetY:									textProp.offset.y									= iValue; return;
		case e_UIObjectProperty_Text_ColorR:									textProp.color.r									= iValue; return;
		case e_UIObjectProperty_Text_ColorG:									textProp.color.g									= iValue; return;
		case e_UIObjectProperty_Text_ColorB:									textProp.color.b									= iValue; return;
		case e_UIObjectProperty_Text_ColorA:									textProp.color.a									= iValue; return;
		case e_UIObjectProperty_Text_Height:									textProp.height										= iValue; return;
		case e_UIObjectProperty_Text_Weight:									textProp.weight										= iValue; return;

		case e_UIObjectProperty_Text_LineDistance:								textProp.lineDistance								= iValue; return;
		case e_UIObjectProperty_Text_MaxTextSizeX:								textProp.maxTextSizeX								= iValue; return;
		case e_UIObjectProperty_Text_MaxTextSizeY:								textProp.maxTextSizeY								= iValue; return;

		default: throw invalid_argument("CTextBox::SetProperty - iProperty is not valid TextBox property");
		}
	}

//*****************************************************************************

void CTextBox::SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:									scriptName_OnFrameMove									= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRender:									scriptName_OnRender										= iValue; return;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_UpButtonPress:			scriptName_OnVerticalScrollBar_UpButtonPress			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_UpButtonMouseFocus:		scriptName_OnVerticalScrollBar_UpButtonMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_UpButtonMouseUnfocus:	scriptName_OnVerticalScrollBar_UpButtonMouseUnfocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_DownButtonPress:			scriptName_OnVerticalScrollBar_DownButtonPress			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_DownButtonMouseFocus:	scriptName_OnVerticalScrollBar_DownButtonMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnVerticalScrollBar_DownButtonMouseUnfocus:	scriptName_OnVerticalScrollBar_DownButtonMouseUnfocus	= iValue; return;
		case e_UIObjectProperty_ScriptName_OnTextBoxMouseFocus:							scriptName_OnTextBoxMouseFocus							= iValue; return;
		case e_UIObjectProperty_ScriptName_OnTextBoxMouseUnfocus:						scriptName_OnTextBoxMouseUnfocus						= iValue; return;
		
		case e_UIObjectProperty_BackgroundImage_TextureName:							backgroundImageProp.textureName	= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_BackgroundImage_TextureName:			verticalScrollBar_BackgroundImageProp.textureName		= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_MarkerImage_TextureName:				verticalScrollBar_MarkerImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_UpButtonImage_TextureName:			verticalScrollBar_UpButtonImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_VerticalScrollBar_DownButtonImage_TextureName:			verticalScrollBar_DownButtonImageProp.textureName		= iValue; return;

		case e_UIObjectProperty_Text_Facename:											textProp.facename										= iValue; return;
		case e_UIObjectProperty_Text_FileName:											textProp.fileName										= iValue; return;

		default: throw invalid_argument("CTextBox::SetProperty - iProperty is not valid TextBox property");
		}
	}

//*****************************************************************************

bool CTextBox::Intersect(const D3DXVECTOR2& iPosition)
	{
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale) || textProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || verticalScrollBar_BackgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || verticalScrollBar_UpButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || verticalScrollBar_DownButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || verticalScrollBar_MarkerImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		return true;
	else
		return false;
	}

//*****************************************************************************

D3DXVECTOR2	CTextBox::GetMarkerPosition()
	{	
	CorrectParams();

	D3DXVECTOR2 pos(position);
	pos += D3DXVECTOR2(verticalScrollBar_MarkerStartPositionOffset.x*scale.x, verticalScrollBar_MarkerStartPositionOffset.y*scale.y);	
	
	int numSteps = NumSteps();
	int tCurStep = verticalScrollBar_CurStep - MinStep();

	if(numSteps == 0)
		return pos;

	float distance = verticalScrollBar_MarkerEndPositionOffsetY*scale.y - verticalScrollBar_MarkerStartPositionOffset.y*scale.y;

	pos.y += (float)tCurStep / ((float)numSteps - 1) * distance;

	return pos;
	}

//*****************************************************************************

unsigned CTextBox::NumSteps() 
	{
	if(MinStep() > 0)
		return MaxStep() - MinStep() + 1;   

	if(MinStep() == 0)
		return MaxStep() + 1;
	}

//*****************************************************************************

void CTextBox::CorrectParams()
	{
	if(verticalScrollBar_MarkerEndPositionOffsetY < verticalScrollBar_MarkerStartPositionOffset.y)
		verticalScrollBar_MarkerEndPositionOffsetY = verticalScrollBar_MarkerStartPositionOffset.y;

	if(verticalScrollBar_CurStep < MinStep())
		verticalScrollBar_CurStep = MinStep();

	if(verticalScrollBar_CurStep > MaxStep())
		verticalScrollBar_CurStep = MaxStep();
	}

//*****************************************************************************

float CTextBox::Round(const float& iValue) const
	{
		if(ceil(iValue) - iValue < 0.5)
			return ceil(iValue);
		else
			return floor(iValue);
	}

//*****************************************************************************

unsigned CTextBox::MaxStep() 
	{
	return textProp.NumSliderSteps();
	}

//*****************************************************************************

unsigned CTextBox::MinStep() const
	{
	return 0;
	}

//*****************************************************************************