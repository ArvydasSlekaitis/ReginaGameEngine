/*
    CInputQuery.cpp - Contains class CInputQuery implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CInputQuery.h>
using namespace Regina::UI;


//*****************************************************************************

CInputQuery::~CInputQuery()
  	{
	}

//*****************************************************************************

CInputQuery::CInputQuery(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, wstring* oAnswer, const vector<wstring>& iInitializingScript) : CUIMessage(iHWnd, iLanguage, iOriginalScreenResolution, iName, EUIObjectType::e_UIObject_InputQuery), questionTextProp(iOriginalScreenResolution, iOriginalScreenResolution), questionTextToRender(iOriginalScreenResolution, iOriginalScreenResolution), inputTextProp(iOriginalScreenResolution, iOriginalScreenResolution), inputTextToRender(iOriginalScreenResolution, iOriginalScreenResolution), okButtonTextProp(iOriginalScreenResolution, iOriginalScreenResolution), okButtonImageProp(iOriginalScreenResolution, iOriginalScreenResolution), backgroundImageProp(iOriginalScreenResolution, iOriginalScreenResolution), markerImageProp(iOriginalScreenResolution, iOriginalScreenResolution), scriptManager(this), answer(oAnswer), position(0, 0), scale(1, 1), maxQuestionTextSize(50), maxInputTextSize(50), rise(true), markerBlinkSpeed(1020), scriptName_OnFrameMove(L""), scriptName_OnRender(L""), scriptName_OnOkButtonPress(L""), scriptName_OnOkButtonMouseFocus(L""), scriptName_OnOkButtonMouseUnfocus(L""), scriptName_OnInputQueryMouseFocus(L""), scriptName_OnInputQueryMouseUnfocus(L""), scriptName_OnKeyPress(L""), scriptName_OnEnterPress(L"")
  	{
	scriptManager.VariablePool().AddLocalVariable(L"elapsedTime", &elapsedTime);
	scriptManager.VariablePool().AddLocalVariable(L"time", &time);
	scriptManager.VariablePool().AddLocalVariable(L"visible", &visible);
	scriptManager.VariablePool().AddLocalVariable(L"active", &active);

	scriptManager.VariablePool().AddLocalVariable(L"positionX", &position.x);
	scriptManager.VariablePool().AddLocalVariable(L"positionY", &position.y);

	scriptManager.VariablePool().AddLocalVariable(L"scaleX", &scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"scaleY", &scale.y);

	scriptManager.VariablePool().AddLocalVariable(L"maxQuestionTextSize", &maxQuestionTextSize);
	scriptManager.VariablePool().AddLocalVariable(L"maxInputTextSize", &maxInputTextSize);
	scriptManager.VariablePool().AddLocalVariable(L"markerBlinkSpeed", &markerBlinkSpeed);

	//Question Text
	scriptManager.VariablePool().AddLocalVariable(L"questionText_offsetX", &questionTextProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"questionText_offsetY", &questionTextProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"questionText_colorR", &questionTextProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"questionText_colorG", &questionTextProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"questionText_colorB", &questionTextProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"questionText_colorA", &questionTextProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"questionText_facename", &questionTextProp.facename);
	scriptManager.VariablePool().AddLocalVariable(L"questionText_height", &questionTextProp.height);
	scriptManager.VariablePool().AddLocalVariable(L"questionText_weight", &questionTextProp.weight);
	scriptManager.VariablePool().AddLocalVariable(L"questionText_italic", &questionTextProp.italic);
	scriptManager.VariablePool().AddLocalVariable(L"questionText_line", &questionTextProp.line);

	//Input Text
	scriptManager.VariablePool().AddLocalVariable(L"inputText_offsetX", &inputTextProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"inputText_offsetY", &inputTextProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"inputText_colorR", &inputTextProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"inputText_colorG", &inputTextProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"inputText_colorB", &inputTextProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"inputText_colorA", &inputTextProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"inputText_facename", &inputTextProp.facename);
	scriptManager.VariablePool().AddLocalVariable(L"inputText_height", &inputTextProp.height);
	scriptManager.VariablePool().AddLocalVariable(L"inputText_weight", &inputTextProp.weight);
	scriptManager.VariablePool().AddLocalVariable(L"inputText_italic", &inputTextProp.italic);
	scriptManager.VariablePool().AddLocalVariable(L"inputText_line", &inputTextProp.line);

	//Ok button Text
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_offsetX", &okButtonTextProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_offsetY", &okButtonTextProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_colorR", &okButtonTextProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_colorG", &okButtonTextProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_colorB", &okButtonTextProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_colorA", &okButtonTextProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_facename", &okButtonTextProp.facename);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_height", &okButtonTextProp.height);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_weight", &okButtonTextProp.weight);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_italic", &okButtonTextProp.italic);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonText_line", &okButtonTextProp.line);

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

	//Ok button image
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_offsetX", &okButtonImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_offsetY", &okButtonImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_colorR", &okButtonImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_colorG", &okButtonImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_colorB", &okButtonImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_colorA", &okButtonImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_scaleX", &okButtonImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_scaleY", &okButtonImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_rotation", &okButtonImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_textureName", &okButtonImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"okButtonImage_alphaIntersectionTest", &okButtonImageProp.alphaIntersectionTest);

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

	//Script name
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnFrameMove", &scriptName_OnFrameMove);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRender", &scriptName_OnRender);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnOkButtonPress", &scriptName_OnOkButtonPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnOkButtonMouseFocus", &scriptName_OnOkButtonMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnOkButtonMouseUnFocus", &scriptName_OnOkButtonMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnInputQueryMouseFocus", &scriptName_OnInputQueryMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnInputQueryMouseUnfocus", &scriptName_OnInputQueryMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnKeyPress", &scriptName_OnKeyPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnEnterPress", &scriptName_OnEnterPress);

	scriptManager.VariablePool().AddLocalVariable(L"lastKeyPressed", wstring(L""));

	//try
		{
		scriptManager.RunScript(iInitializingScript);
		}
	/*catch(exception& iExcpetion)
		{
		ostringstream str;
		str << iExcpetion.what();
		//Log
		}*/

	GetQuestionTextToRender();
	GetInputTextToRender();
	}

//*****************************************************************************

void CInputQuery::On_FrameMove()
  	{
	RunScript(scriptName_OnFrameMove);
	CallCallbackFunction(EUIEventType::e_UIEvent_FrameMove);

	//On InputQuery mouse focus/unfocus
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || okButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnInputQueryMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_InputQueryMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnInputQueryMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_InputQueryMouseUnfocus);
		}

	//On Ok button mouse focus/unfocus
	if(okButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnOkButtonMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_OkButtonMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnOkButtonMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_OkButtonMouseUnfocus);
		}

	//Message specific
	if(State() == E_UIMessageState_BeginTermination)
			SetState(E_UIMessageState_Terminate);

	UpdateMarker();
	}

//*****************************************************************************

void CInputQuery::On_Render()
  	{
	RunScript(scriptName_OnRender);

	position = TransformToUIScreenSpaceInverse(originalScreenResolution, screenResolution, screenResolution/2);

	backgroundImageProp.Render(position, scale, scale);
	questionTextToRender.Render(position, GetQuestionTextToRender(), scale, scale);
	inputTextToRender.Render(position, GetInputTextToRender(), scale, scale);
	markerImageProp.Render(MarkerPosition(), scale, scale);
	okButtonImageProp.Render(position, scale, scale);
	okButtonTextProp.Render(position, scale, scale);

	CallCallbackFunction(EUIEventType::e_UIEvent_Render);
	}

//*****************************************************************************

bool CInputQuery::On_LeftClick(const D3DXVECTOR2& iCursorPosition)
  	{
	if(State() == E_UIMessageState_Render)
		{
		if(okButtonImageProp.Intersect(iCursorPosition, position, scale, scale))
			{
			RunScript(scriptName_OnOkButtonPress);
			CallCallbackFunction(EUIEventType::e_UIEvent_OkButtonPress);

			if(State() == E_UIMessageState_Render)
				SetState(E_UIMessageState_BeginTermination);
			
			assert(answer != NULL && L"CInputQuery::On_LeftClick - answer != NULL - Using template as object");

			*answer = inputTextProp.line;

			return true;
			}	
		
		if(backgroundImageProp.Intersect(iCursorPosition, position, scale, scale))
			return true;
		}



	return false;
	}

//*****************************************************************************

bool CInputQuery::On_KeyDown(const wchar_t& iKey)
	{
	if(State() == E_UIMessageState_Render)
		{
		if(iKey >= 'a' && iKey <= 'z' || iKey >= 'A' && iKey <= 'Z' || iKey >= '0' && iKey <= '9' || iKey == '+' || iKey == '-' || iKey == '*' || iKey == '/' || iKey == '.' || iKey == ' ' || iKey == ',' || iKey == ';' || iKey == ':' || iKey == '/' || iKey == '?' || iKey == '`' || iKey == '~' || iKey == '[' || iKey == '{' || iKey == ']' || iKey == '}' || iKey == '\\' || iKey == '|' || iKey == '}' || iKey == '\'' || iKey == '"') // Encompass all symbols
			inputTextProp.line = inputTextProp.line + iKey;
					
		if(iKey == VK_BACK)
			{
			if(inputTextProp.line.size() > 0)
				inputTextProp.line.erase(inputTextProp.line.end() - 1);
			}

		scriptManager.VariablePool().SetVariableValue(L"lastKeyPressed", wstring(L""+iKey));
		RunScript(scriptName_OnKeyPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_KeyPress);

		if(iKey == VK_RETURN)
			{
			RunScript(scriptName_OnEnterPress);
			CallCallbackFunction(EUIEventType::e_UIEvent_EnterPress);
			
			RunScript(scriptName_OnOkButtonPress);
			CallCallbackFunction(EUIEventType::e_UIEvent_OkButtonPress);

			if(State() == E_UIMessageState_Render)
				SetState(E_UIMessageState_BeginTermination);

			assert(answer != NULL && L"CInputQuery::On_KeyDown - answer != NULL - Using template as object");

			*answer = inputTextProp.line;
			}
		
		return true;
		}

	return false;
	}

//*****************************************************************************
	
void CInputQuery::On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	questionTextProp.SetScreenResolution(iScreenResolution);
	questionTextToRender.SetScreenResolution(iScreenResolution);
	inputTextProp.SetScreenResolution(iScreenResolution);
	inputTextToRender.SetScreenResolution(iScreenResolution);
	okButtonTextProp.SetScreenResolution(iScreenResolution);
	okButtonImageProp.SetScreenResolution(iScreenResolution);
	backgroundImageProp.SetScreenResolution(iScreenResolution);
	markerImageProp.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************
	
void CInputQuery::GetInitializingText(vector<wstring>& oText)
	{
	oText.push_back(L"InputQuery " + Name());
	oText.push_back(L"{");
	scriptManager.VariablePool().GetInitializingScriptText(oText);
	oText.push_back(L"}");
	}

//*****************************************************************************

void CInputQuery::RunScript(const wstring& iScriptName)
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

bool CInputQuery::GetProperty(const EUIObjectProperty_Bool& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								return visible;
		case e_UIObjectProperty_Active:									return active;

		case e_UIObjectProperty_QuestionText_Italic:					return questionTextProp.italic;
		case e_UIObjectProperty_InputText_Italic:						return inputTextProp.italic;
		case e_UIObjectProperty_OkButtonText_Italic:					return okButtonTextProp.italic;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	return backgroundImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_OkButtonImage_AlphaIntersectionTest:	return okButtonImageProp.alphaIntersectionTest;
		
		default: throw invalid_argument("CInputQuery::GetProperty - iProperty is not valid InptuQuery property");
		}
	}

//*****************************************************************************

int	CInputQuery::GetProperty(const EUIObjectProperty_Int& iProperty)
	{
	throw invalid_argument("CInputQuery::GetProperty - iProperty is not valid InptuQuery property");
	}

//*****************************************************************************

float CInputQuery::GetProperty(const EUIObjectProperty_Float& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_MaxQuestionTextSize:		return maxQuestionTextSize;
		case e_UIObjectProperty_MaxInputTextSize:			return maxInputTextSize;
		case e_UIObjectProperty_MarkerBlinkSpeed:			return markerBlinkSpeed;

		case e_UIObjectProperty_ScaleX:						return scale.x;
		case e_UIObjectProperty_ScaleY:						return scale.y;

		case e_UIObjectProperty_BackgroundImage_OffsetX:	return backgroundImageProp.offset.x;
		case e_UIObjectProperty_BackgroundImage_OffsetY:	return backgroundImageProp.offset.y;
		case e_UIObjectProperty_BackgroundImage_ColorR:		return backgroundImageProp.color.r;
		case e_UIObjectProperty_BackgroundImage_ColorG:		return backgroundImageProp.color.g;
		case e_UIObjectProperty_BackgroundImage_ColorB:		return backgroundImageProp.color.b;
		case e_UIObjectProperty_BackgroundImage_ColorA:		return backgroundImageProp.color.a;
		case e_UIObjectProperty_BackgroundImage_ScaleX:		return backgroundImageProp.scale.x;
		case e_UIObjectProperty_BackgroundImage_ScaleY:		return backgroundImageProp.scale.y;
		case e_UIObjectProperty_BackgroundImage_Rotation:	return backgroundImageProp.rotation;

		case e_UIObjectProperty_OkButtonImage_OffsetX:		return okButtonImageProp.offset.x;
		case e_UIObjectProperty_OkButtonImage_OffsetY:		return okButtonImageProp.offset.y;
		case e_UIObjectProperty_OkButtonImage_ColorR:		return okButtonImageProp.color.r;
		case e_UIObjectProperty_OkButtonImage_ColorG:		return okButtonImageProp.color.g;
		case e_UIObjectProperty_OkButtonImage_ColorB:		return okButtonImageProp.color.b;
		case e_UIObjectProperty_OkButtonImage_ColorA:		return okButtonImageProp.color.a;
		case e_UIObjectProperty_OkButtonImage_ScaleX:		return okButtonImageProp.scale.x;
		case e_UIObjectProperty_OkButtonImage_ScaleY:		return okButtonImageProp.scale.y;
		case e_UIObjectProperty_OkButtonImage_Rotation:		return okButtonImageProp.rotation;

		case e_UIObjectProperty_QuestionText_OffsetX:		return questionTextProp.offset.x;
		case e_UIObjectProperty_QuestionText_OffsetY:		return questionTextProp.offset.y;
		case e_UIObjectProperty_QuestionText_ColorR:		return questionTextProp.color.r;
		case e_UIObjectProperty_QuestionText_ColorG:		return questionTextProp.color.g;
		case e_UIObjectProperty_QuestionText_ColorB:		return questionTextProp.color.b;
		case e_UIObjectProperty_QuestionText_ColorA:		return questionTextProp.color.a;
		case e_UIObjectProperty_QuestionText_Height:		return questionTextProp.height;
		case e_UIObjectProperty_QuestionText_Weight:		return questionTextProp.weight;

		case e_UIObjectProperty_InputText_OffsetX:			return inputTextProp.offset.x;
		case e_UIObjectProperty_InputText_OffsetY:			return inputTextProp.offset.y;
		case e_UIObjectProperty_InputText_ColorR:			return inputTextProp.color.r;
		case e_UIObjectProperty_InputText_ColorG:			return inputTextProp.color.g;
		case e_UIObjectProperty_InputText_ColorB:			return inputTextProp.color.b;
		case e_UIObjectProperty_InputText_ColorA:			return inputTextProp.color.a;
		case e_UIObjectProperty_InputText_Height:			return inputTextProp.height;
		case e_UIObjectProperty_InputText_Weight:			return inputTextProp.weight;

		case e_UIObjectProperty_OkButtonText_OffsetX:		return okButtonTextProp.offset.x;
		case e_UIObjectProperty_OkButtonText_OffsetY:		return okButtonTextProp.offset.y;
		case e_UIObjectProperty_OkButtonText_ColorR:		return okButtonTextProp.color.r;
		case e_UIObjectProperty_OkButtonText_ColorG:		return okButtonTextProp.color.g;
		case e_UIObjectProperty_OkButtonText_ColorB:		return okButtonTextProp.color.b;
		case e_UIObjectProperty_OkButtonText_ColorA:		return okButtonTextProp.color.a;
		case e_UIObjectProperty_OkButtonText_Height:		return okButtonTextProp.height;
		case e_UIObjectProperty_OkButtonText_Weight:		return okButtonTextProp.weight;

		case e_UIObjectProperty_MarkerImage_OffsetX:		return markerImageProp.offset.x;
		case e_UIObjectProperty_MarkerImage_OffsetY:		return markerImageProp.offset.y;
		case e_UIObjectProperty_MarkerImage_ColorR:			return markerImageProp.color.r;
		case e_UIObjectProperty_MarkerImage_ColorG:			return markerImageProp.color.g;
		case e_UIObjectProperty_MarkerImage_ColorB:			return markerImageProp.color.b;
		case e_UIObjectProperty_MarkerImage_ColorA:			return markerImageProp.color.a;
		case e_UIObjectProperty_MarkerImage_ScaleX:			return markerImageProp.scale.x;
		case e_UIObjectProperty_MarkerImage_ScaleY:			return markerImageProp.scale.y;
		case e_UIObjectProperty_MarkerImage_Rotation:		return markerImageProp.rotation;

		default: throw invalid_argument("CInputQuery::GetProperty - iProperty is not valid InptuQuery property");
		}
	}

//*****************************************************************************

wstring	CInputQuery::GetProperty(const EUIObjectProperty_String& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:					return scriptName_OnFrameMove;
		case e_UIObjectProperty_ScriptName_OnRender:					return scriptName_OnRender;
		case e_UIObjectProperty_ScriptName_OnOkButtonPress:				return scriptName_OnOkButtonPress;
		case e_UIObjectProperty_ScriptName_OnOkButtonMouseFocus:		return scriptName_OnOkButtonMouseFocus;
		case e_UIObjectProperty_ScriptName_OnOkButtonMouseUnfocus:		return scriptName_OnOkButtonMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnInputQueryMouseFocus:		return scriptName_OnInputQueryMouseFocus;
		case e_UIObjectProperty_ScriptName_OnInputQueryMouseUnfocus:	return scriptName_OnInputQueryMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnKeyPress:					return scriptName_OnKeyPress;
		case e_UIObjectProperty_ScriptName_OnEnterPress:				return scriptName_OnEnterPress;

		case e_UIObjectProperty_BackgroundImage_TextureName:			return backgroundImageProp.textureName;
		case e_UIObjectProperty_OkButtonImage_TextureName:				return okButtonImageProp.textureName;
		case e_UIObjectProperty_QuestionText_Facename:					return questionTextProp.facename;
		case e_UIObjectProperty_QuestionText_Line:						return questionTextProp.line;
		case e_UIObjectProperty_InputText_Facename:						return inputTextProp.facename;
		case e_UIObjectProperty_InputText_Line:							return inputTextProp.line;
		case e_UIObjectProperty_OkButtonText_Facename:					return okButtonTextProp.facename;
		case e_UIObjectProperty_OkButtonText_Line:						return okButtonTextProp.line;
		case e_UIObjectProperty_MarkerImage_TextureName:				return markerImageProp.textureName;

		default: throw invalid_argument("CInputQuery::GetProperty - iProperty is not valid InptuQuery property");
		}
	}

//*****************************************************************************

void CInputQuery::SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								visible										= iValue; return;
		case e_UIObjectProperty_Active:									active										= iValue; return;
		
		case e_UIObjectProperty_QuestionText_Italic:					questionTextProp.italic						= iValue; return;
		case e_UIObjectProperty_InputText_Italic:						inputTextProp.italic						= iValue; return;
		case e_UIObjectProperty_OkButtonText_Italic:					okButtonTextProp.italic						= iValue; return;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	backgroundImageProp.alphaIntersectionTest	= iValue; return;
		case e_UIObjectProperty_OkButtonImage_AlphaIntersectionTest:	okButtonImageProp.alphaIntersectionTest		= iValue; return;

		default: throw invalid_argument("CInputQuery::SetProperty - iProperty is not valid InptuQuery property");
		}
	}

//*****************************************************************************

void CInputQuery::SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	throw invalid_argument("CInputQuery::SetProperty - iProperty is not valid InptuQuery property");
	}

//*****************************************************************************

void CInputQuery::SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_PositionX:					position.x						= iValue; return;
		case e_UIObjectProperty_PositionY:					position.y						= iValue; return;

		case e_UIObjectProperty_ScaleX:						scale.x							= iValue; return;
		case e_UIObjectProperty_ScaleY:						scale.y							= iValue; return;

		case e_UIObjectProperty_MaxQuestionTextSize:		maxQuestionTextSize				= iValue; GetQuestionTextToRender(); return;
		case e_UIObjectProperty_MaxInputTextSize:			maxInputTextSize				= iValue; GetInputTextToRender(); return;		
		case e_UIObjectProperty_MarkerBlinkSpeed:			markerBlinkSpeed				= iValue; return;

		case e_UIObjectProperty_BackgroundImage_OffsetX:	backgroundImageProp.offset.x	= iValue; return;
		case e_UIObjectProperty_BackgroundImage_OffsetY:	backgroundImageProp.offset.y	= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorR:		backgroundImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorG:		backgroundImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorB:		backgroundImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorA:		backgroundImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ScaleX:		backgroundImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ScaleY:		backgroundImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_Rotation:	backgroundImageProp.rotation	= iValue; return;

		case e_UIObjectProperty_OkButtonImage_OffsetX:		okButtonImageProp.offset.x		= iValue; return;
		case e_UIObjectProperty_OkButtonImage_OffsetY:		okButtonImageProp.offset.y		= iValue; return;
		case e_UIObjectProperty_OkButtonImage_ColorR:		okButtonImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_OkButtonImage_ColorG:		okButtonImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_OkButtonImage_ColorB:		okButtonImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_OkButtonImage_ColorA:		okButtonImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_OkButtonImage_ScaleX:		okButtonImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_OkButtonImage_ScaleY:		okButtonImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_OkButtonImage_Rotation:		okButtonImageProp.rotation		= iValue; return;

		case e_UIObjectProperty_QuestionText_OffsetX:		questionTextProp.offset.x		= iValue; return;
		case e_UIObjectProperty_QuestionText_OffsetY:		questionTextProp.offset.y		= iValue; return;
		case e_UIObjectProperty_QuestionText_ColorR:		questionTextProp.color.r		= iValue; return;
		case e_UIObjectProperty_QuestionText_ColorG:		questionTextProp.color.g		= iValue; return;
		case e_UIObjectProperty_QuestionText_ColorB:		questionTextProp.color.b		= iValue; return;
		case e_UIObjectProperty_QuestionText_ColorA:		questionTextProp.color.a		= iValue; return;
		case e_UIObjectProperty_QuestionText_Height:		questionTextProp.height			= iValue; GetQuestionTextToRender(); return;
		case e_UIObjectProperty_QuestionText_Weight:		questionTextProp.weight			= iValue; return;

		case e_UIObjectProperty_InputText_OffsetX:			inputTextProp.offset.x			= iValue; return;
		case e_UIObjectProperty_InputText_OffsetY:			inputTextProp.offset.y			= iValue; return;
		case e_UIObjectProperty_InputText_ColorR:			inputTextProp.color.r			= iValue; return;
		case e_UIObjectProperty_InputText_ColorG:			inputTextProp.color.g			= iValue; return;
		case e_UIObjectProperty_InputText_ColorB:			inputTextProp.color.b			= iValue; return;
		case e_UIObjectProperty_InputText_ColorA:			inputTextProp.color.a			= iValue; return;
		case e_UIObjectProperty_InputText_Height:			inputTextProp.height			= iValue; GetInputTextToRender(); return;
		case e_UIObjectProperty_InputText_Weight:			inputTextProp.weight			= iValue; return;

		case e_UIObjectProperty_OkButtonText_OffsetX:		okButtonTextProp.offset.x		= iValue; return;
		case e_UIObjectProperty_OkButtonText_OffsetY:		okButtonTextProp.offset.y		= iValue; return;
		case e_UIObjectProperty_OkButtonText_ColorR:		okButtonTextProp.color.r		= iValue; return;
		case e_UIObjectProperty_OkButtonText_ColorG:		okButtonTextProp.color.g		= iValue; return;
		case e_UIObjectProperty_OkButtonText_ColorB:		okButtonTextProp.color.b		= iValue; return;
		case e_UIObjectProperty_OkButtonText_ColorA:		okButtonTextProp.color.a		= iValue; return;
		case e_UIObjectProperty_OkButtonText_Height:		okButtonTextProp.height			= iValue; return;
		case e_UIObjectProperty_OkButtonText_Weight:		okButtonTextProp.weight			= iValue; return;

		case e_UIObjectProperty_MarkerImage_OffsetX:		markerImageProp.offset.x		= iValue; return;
		case e_UIObjectProperty_MarkerImage_OffsetY:		markerImageProp.offset.y		= iValue; return;
		case e_UIObjectProperty_MarkerImage_ColorR:			markerImageProp.color.r			= iValue; return;
		case e_UIObjectProperty_MarkerImage_ColorG:			markerImageProp.color.g			= iValue; return;
		case e_UIObjectProperty_MarkerImage_ColorB:			markerImageProp.color.b			= iValue; return;
		case e_UIObjectProperty_MarkerImage_ColorA:			markerImageProp.color.a			= iValue; return;
		case e_UIObjectProperty_MarkerImage_ScaleX:			markerImageProp.scale.x			= iValue; return;
		case e_UIObjectProperty_MarkerImage_ScaleY:			markerImageProp.scale.y			= iValue; return;
		case e_UIObjectProperty_MarkerImage_Rotation:		markerImageProp.rotation		= iValue; return;

		default: throw invalid_argument("CInputQuery::SetProperty - iProperty is not valid InptuQuery property");
		}
	}

//*****************************************************************************

void CInputQuery::SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:					scriptName_OnFrameMove					= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRender:					scriptName_OnRender						= iValue; return;
		case e_UIObjectProperty_ScriptName_OnOkButtonPress:				scriptName_OnOkButtonPress				= iValue; return;
		case e_UIObjectProperty_ScriptName_OnOkButtonMouseFocus:		scriptName_OnOkButtonMouseFocus			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnOkButtonMouseUnfocus:		scriptName_OnOkButtonMouseUnfocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnInputQueryMouseFocus:		scriptName_OnInputQueryMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnInputQueryMouseUnfocus:	scriptName_OnInputQueryMouseUnfocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnKeyPress:					scriptName_OnKeyPress					= iValue; return;
		case e_UIObjectProperty_ScriptName_OnEnterPress:				scriptName_OnEnterPress					= iValue; return;

		case e_UIObjectProperty_BackgroundImage_TextureName:			backgroundImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_OkButtonImage_TextureName:				okButtonImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_QuestionText_Facename:					questionTextProp.facename				= iValue; return;
		case e_UIObjectProperty_QuestionText_Line:						questionTextProp.line					= iValue; GetQuestionTextToRender(); return;
		case e_UIObjectProperty_InputText_Facename:						inputTextProp.facename					= iValue; return;
		case e_UIObjectProperty_InputText_Line:							inputTextProp.line						= iValue; GetInputTextToRender(); return;
		case e_UIObjectProperty_OkButtonText_Facename:					okButtonTextProp.facename				= iValue; return;
		case e_UIObjectProperty_OkButtonText_Line:						okButtonTextProp.line					= iValue; return;
		case e_UIObjectProperty_MarkerImage_TextureName:				markerImageProp.textureName				= iValue; return;

		default: throw invalid_argument("CInputQuery::SetProperty - iProperty is not valid InptuQuery property");
		}
	}

//*****************************************************************************

wstring	CInputQuery::GetQuestionTextToRender()
	{
	if(maxQuestionTextSize < 0)
		maxQuestionTextSize = 0; 

	questionTextToRender = questionTextProp;

	while(true)
		{
		const float curSize = questionTextToRender.GetTextExtent(scale).right;
		D3DXVECTOR2 curMaxTextSizeTemp(maxQuestionTextSize*scale.x, 0);
		curMaxTextSizeTemp = TransformToUIScreenSpace(originalScreenResolution, screenResolution, curMaxTextSizeTemp);
		const float curMaxTextSize = curMaxTextSizeTemp.x;

		if(curSize <= curMaxTextSize)
			break;
		else
			if(questionTextToRender.line.size() > 0)
				questionTextToRender.line.erase(questionTextToRender.line.end()-1);
			else
				break;
		}

	return questionTextToRender.line;
	}

//*****************************************************************************

void CInputQuery::UpdateMarker()
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

//*****************************************************************************

D3DXVECTOR2 CInputQuery::MarkerPosition()
	{
	D3DXVECTOR2 ret(position);
	ret.x += inputTextToRender.offset.x*scale.x;
	ret = TransformToUIScreenSpace(originalScreenResolution, screenResolution, ret);
	ret.x += inputTextToRender.GetTextExtent(scale).right;
	ret = TransformToUIScreenSpaceInverse(originalScreenResolution, screenResolution, ret);
	return ret; 
	}

//*****************************************************************************

wstring CInputQuery::GetInputTextToRender()
	{
	if(maxInputTextSize < 0)
		maxInputTextSize = 0; 

	inputTextToRender = inputTextProp;

	while(true)
		{
		const float curSize = inputTextToRender.GetTextExtent(scale).right;
		D3DXVECTOR2 curMaxTextSizeTemp(maxInputTextSize*scale.x, 0);
		curMaxTextSizeTemp = TransformToUIScreenSpace(originalScreenResolution, screenResolution, curMaxTextSizeTemp);
		const float curMaxTextSize = curMaxTextSizeTemp.x;

		if(curSize <= curMaxTextSize)
			break;
		else
			if(inputTextToRender.line.size() > 0)
				inputTextToRender.line.erase(inputTextToRender.line.begin());
			else
				break;
		}

	return inputTextToRender.line;
	}

//*****************************************************************************

bool CInputQuery::Intersect(const D3DXVECTOR2& iPosition)
	{
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || okButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		return true;
	else
		return false;
	}

//*****************************************************************************


