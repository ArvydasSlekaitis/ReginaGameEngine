/*
    CQuestionBox.cpp - Contains class CQuestionBox implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CQuestionBox.h>
using namespace Regina::UI;


//*****************************************************************************

CQuestionBox::~CQuestionBox()
  	{
	}

//*****************************************************************************

CQuestionBox::CQuestionBox(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, wstring* oAnswer, const vector<wstring>& iInitializingScript) : CUIMessage(iHWnd, iLanguage, iOriginalScreenResolution, iName, EUIObjectType::e_UIObject_MessageBox), questionTextProp(iOriginalScreenResolution, iOriginalScreenResolution), questionTextToRender(iOriginalScreenResolution, iOriginalScreenResolution), yesButtonTextProp(iOriginalScreenResolution, iOriginalScreenResolution), yesButtonImageProp(iOriginalScreenResolution, iOriginalScreenResolution), noButtonTextProp(iOriginalScreenResolution, iOriginalScreenResolution), noButtonImageProp(iOriginalScreenResolution, iOriginalScreenResolution), backgroundImageProp(iOriginalScreenResolution, iOriginalScreenResolution), scriptManager(this), answer(oAnswer), position(0, 0), scale(1, 1), maxQuestionTextSize(50), scriptName_OnFrameMove(L""), scriptName_OnRender(L""), scriptName_OnYesButtonPress(L""), scriptName_OnYesButtonMouseFocus(L""), scriptName_OnYesButtonMouseUnfocus(L""), scriptName_OnNoButtonPress(L""), scriptName_OnNoButtonMouseFocus(L""), scriptName_OnNoButtonMouseUnfocus(L""), scriptName_OnQuestionBoxMouseFocus(L""), scriptName_OnQuestionBoxMouseUnfocus(L"")
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

	//Yes button Text
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_offsetX", &yesButtonTextProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_offsetY", &yesButtonTextProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_colorR", &yesButtonTextProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_colorG", &yesButtonTextProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_colorB", &yesButtonTextProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_colorA", &yesButtonTextProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_facename", &yesButtonTextProp.facename);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_height", &yesButtonTextProp.height);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_weight", &yesButtonTextProp.weight);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_italic", &yesButtonTextProp.italic);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonText_line", &yesButtonTextProp.line);

	//Yes button image
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_offsetX", &yesButtonImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_offsetY", &yesButtonImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_colorR", &yesButtonImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_colorG", &yesButtonImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_colorB", &yesButtonImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_colorA", &yesButtonImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_scaleX", &yesButtonImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_scaleY", &yesButtonImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_rotation", &yesButtonImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_textureName", &yesButtonImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"yesButtonImage_alphaIntersectionTest", &yesButtonImageProp.alphaIntersectionTest);

	//No button Text
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_offsetX", &noButtonTextProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_offsetY", &noButtonTextProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_colorR", &noButtonTextProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_colorG", &noButtonTextProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_colorB", &noButtonTextProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_colorA", &noButtonTextProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_facename", &noButtonTextProp.facename);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_height", &noButtonTextProp.height);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_weight", &noButtonTextProp.weight);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_italic", &noButtonTextProp.italic);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonText_line", &noButtonTextProp.line);

	//No button image
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_offsetX", &noButtonImageProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_offsetY", &noButtonImageProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_colorR", &noButtonImageProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_colorG", &noButtonImageProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_colorB", &noButtonImageProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_colorA", &noButtonImageProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_scaleX", &noButtonImageProp.scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_scaleY", &noButtonImageProp.scale.y);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_rotation", &noButtonImageProp.rotation);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_textureName", &noButtonImageProp.textureName);
	scriptManager.VariablePool().AddLocalVariable(L"noButtonImage_alphaIntersectionTest", &noButtonImageProp.alphaIntersectionTest);

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

	//Script name
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnFrameMove", &scriptName_OnFrameMove);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRender", &scriptName_OnRender);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnYesButtonPress", &scriptName_OnYesButtonPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnYesButtonMouseFocus", &scriptName_OnYesButtonMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnYesButtonMouseUnfocus", &scriptName_OnYesButtonMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnNoButtonPress", &scriptName_OnNoButtonPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnNoButtonMouseFocus", &scriptName_OnNoButtonMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnNoButtonMouseUnfocus", &scriptName_OnNoButtonMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnQuestionBoxMouseFocus", &scriptName_OnQuestionBoxMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnQuestionBoxMouseUnfocus", &scriptName_OnQuestionBoxMouseUnfocus);

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
	}

//*****************************************************************************

void CQuestionBox::On_FrameMove()
  	{
	RunScript(scriptName_OnFrameMove);
	CallCallbackFunction(EUIEventType::e_UIEvent_FrameMove);

	//On QuestionBox mouse focus/unfocus
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || yesButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || noButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnQuestionBoxMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_QuestionBoxMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnQuestionBoxMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_QuestionBoxMouseUnfocus);
		}

	//On Yes button mouse focus/unfocus
	if(yesButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnYesButtonMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_YesButtonMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnYesButtonMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_YesButtonMouseUnfocus);
		}

	//On No button mouse focus/unfocus
	if(noButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnNoButtonMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_NoButtonMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnNoButtonMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_NoButtonMouseUnfocus);
		}

	//Message specific
	if(State() == E_UIMessageState_BeginTermination)
			SetState(E_UIMessageState_Terminate);
	}

//*****************************************************************************

void CQuestionBox::On_Render()
  	{
	RunScript(scriptName_OnRender);

	position = TransformToUIScreenSpaceInverse(originalScreenResolution, screenResolution, screenResolution/2);

	backgroundImageProp.Render(position, scale, scale);
	questionTextProp.Render(position, GetQuestionTextToRender(), scale, scale);
	yesButtonImageProp.Render(position, scale, scale);
	yesButtonTextProp.Render(position, scale, scale);
	noButtonImageProp.Render(position, scale, scale);
	noButtonTextProp.Render(position, scale, scale);

	CallCallbackFunction(EUIEventType::e_UIEvent_Render);
	}

//*****************************************************************************

bool CQuestionBox::On_LeftClick(const D3DXVECTOR2& iCursorPosition)
  	{
	//Process yes image
	if(yesButtonImageProp.Intersect(iCursorPosition, position, scale, scale))
		{
		RunScript(scriptName_OnYesButtonPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_YesButtonPress);

		if(State() == E_UIMessageState_Render)
			SetState(E_UIMessageState_BeginTermination);

		assert(answer != NULL && L"CQuestionBox::On_LeftClick - answer != NULL - Using template as object");

		*answer = L"Yes";

		return true;
		}

	//Process no image
	if(noButtonImageProp.Intersect(iCursorPosition, position, scale, scale))
		{
		RunScript(scriptName_OnNoButtonPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_NoButtonPress);

		if(State() == E_UIMessageState_Render)
			SetState(E_UIMessageState_BeginTermination);

		assert(answer != NULL && L"CQuestionBox::On_LeftClick - answer != NULL - Using template as object");

		*answer = L"No";

		return true;
		}

	if(backgroundImageProp.Intersect(iCursorPosition, position, scale, scale))
		return true;

	return false;
	}

//*****************************************************************************
	
void CQuestionBox::On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	questionTextToRender.SetScreenResolution(iScreenResolution);
	questionTextProp.SetScreenResolution(iScreenResolution);
	yesButtonTextProp.SetScreenResolution(iScreenResolution);
	yesButtonImageProp.SetScreenResolution(iScreenResolution);
	noButtonTextProp.SetScreenResolution(iScreenResolution);
	noButtonImageProp.SetScreenResolution(iScreenResolution);
	backgroundImageProp.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************
	
void CQuestionBox::GetInitializingText(vector<wstring>& oText)
	{
	oText.push_back(L"QuestionBox " + Name());
	oText.push_back(L"{");
	scriptManager.VariablePool().GetInitializingScriptText(oText);
	oText.push_back(L"}");
	}

//*****************************************************************************

void CQuestionBox::RunScript(const wstring& iScriptName)
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

bool CQuestionBox::GetProperty(const EUIObjectProperty_Bool& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								return visible;
		case e_UIObjectProperty_Active:									return active;

		case e_UIObjectProperty_QuestionText_Italic:					return questionTextProp.italic;
		case e_UIObjectProperty_YesButtonText_Italic:					return yesButtonTextProp.italic;
		case e_UIObjectProperty_NoButtonText_Italic:					return noButtonTextProp.italic;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	return backgroundImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_YesButtonImage_AlphaIntersectionTest:	return yesButtonImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_NoButtonImage_AlphaIntersectionTest:	return noButtonImageProp.alphaIntersectionTest;
		
		
		default: throw invalid_argument("CQuestionBox::GetProperty - iProperty is not valid QuestionBox property");
		}
	}

//*****************************************************************************

int	CQuestionBox::GetProperty(const EUIObjectProperty_Int& iProperty)
	{
	throw invalid_argument("CQuestionBox::GetProperty - iProperty is not valid QuestionBox property");
	}

//*****************************************************************************

float CQuestionBox::GetProperty(const EUIObjectProperty_Float& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_MaxQuestionTextSize:		return maxQuestionTextSize;
	
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

		case e_UIObjectProperty_YesButtonImage_OffsetX:		return yesButtonImageProp.offset.x;
		case e_UIObjectProperty_YesButtonImage_OffsetY:		return yesButtonImageProp.offset.y;
		case e_UIObjectProperty_YesButtonImage_ColorR:		return yesButtonImageProp.color.r;
		case e_UIObjectProperty_YesButtonImage_ColorG:		return yesButtonImageProp.color.g;
		case e_UIObjectProperty_YesButtonImage_ColorB:		return yesButtonImageProp.color.b;
		case e_UIObjectProperty_YesButtonImage_ColorA:		return yesButtonImageProp.color.a;
		case e_UIObjectProperty_YesButtonImage_ScaleX:		return yesButtonImageProp.scale.x;
		case e_UIObjectProperty_YesButtonImage_ScaleY:		return yesButtonImageProp.scale.y;
		case e_UIObjectProperty_YesButtonImage_Rotation:	return yesButtonImageProp.rotation;

		case e_UIObjectProperty_YesButtonText_OffsetX:		return yesButtonTextProp.offset.x;
		case e_UIObjectProperty_YesButtonText_OffsetY:		return yesButtonTextProp.offset.y;
		case e_UIObjectProperty_YesButtonText_ColorR:		return yesButtonTextProp.color.r;
		case e_UIObjectProperty_YesButtonText_ColorG:		return yesButtonTextProp.color.g;
		case e_UIObjectProperty_YesButtonText_ColorB:		return yesButtonTextProp.color.b;
		case e_UIObjectProperty_YesButtonText_ColorA:		return yesButtonTextProp.color.a;
		case e_UIObjectProperty_YesButtonText_Height:		return yesButtonTextProp.height;
		case e_UIObjectProperty_YesButtonText_Weight:		return yesButtonTextProp.weight;

		case e_UIObjectProperty_NoButtonImage_OffsetX:		return noButtonImageProp.offset.x;
		case e_UIObjectProperty_NoButtonImage_OffsetY:		return noButtonImageProp.offset.y;
		case e_UIObjectProperty_NoButtonImage_ColorR:		return noButtonImageProp.color.r;
		case e_UIObjectProperty_NoButtonImage_ColorG:		return noButtonImageProp.color.g;
		case e_UIObjectProperty_NoButtonImage_ColorB:		return noButtonImageProp.color.b;
		case e_UIObjectProperty_NoButtonImage_ColorA:		return noButtonImageProp.color.a;
		case e_UIObjectProperty_NoButtonImage_ScaleX:		return noButtonImageProp.scale.x;
		case e_UIObjectProperty_NoButtonImage_ScaleY:		return noButtonImageProp.scale.y;
		case e_UIObjectProperty_NoButtonImage_Rotation:		return noButtonImageProp.rotation;

		case e_UIObjectProperty_NoButtonText_OffsetX:		return noButtonTextProp.offset.x;
		case e_UIObjectProperty_NoButtonText_OffsetY:		return noButtonTextProp.offset.y;
		case e_UIObjectProperty_NoButtonText_ColorR:		return noButtonTextProp.color.r;
		case e_UIObjectProperty_NoButtonText_ColorG:		return noButtonTextProp.color.g;
		case e_UIObjectProperty_NoButtonText_ColorB:		return noButtonTextProp.color.b;
		case e_UIObjectProperty_NoButtonText_ColorA:		return noButtonTextProp.color.a;
		case e_UIObjectProperty_NoButtonText_Height:		return noButtonTextProp.height;
		case e_UIObjectProperty_NoButtonText_Weight:		return noButtonTextProp.weight;

		case e_UIObjectProperty_QuestionText_OffsetX:		return questionTextProp.offset.x;
		case e_UIObjectProperty_QuestionText_OffsetY:		return questionTextProp.offset.y;
		case e_UIObjectProperty_QuestionText_ColorR:		return questionTextProp.color.r;
		case e_UIObjectProperty_QuestionText_ColorG:		return questionTextProp.color.g;
		case e_UIObjectProperty_QuestionText_ColorB:		return questionTextProp.color.b;
		case e_UIObjectProperty_QuestionText_ColorA:		return questionTextProp.color.a;
		case e_UIObjectProperty_QuestionText_Height:		return questionTextProp.height;
		case e_UIObjectProperty_QuestionText_Weight:		return questionTextProp.weight;

		default: throw invalid_argument("CQuestionBox::GetProperty - iProperty is not valid QuestionBox property");
		}
	}

//*****************************************************************************

wstring	CQuestionBox::GetProperty(const EUIObjectProperty_String& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:					return scriptName_OnFrameMove;
		case e_UIObjectProperty_ScriptName_OnRender:					return scriptName_OnRender;
		case e_UIObjectProperty_ScriptName_OnYesButtonPress:			return scriptName_OnYesButtonPress;
		case e_UIObjectProperty_ScriptName_OnYesButtonMouseFocus:		return scriptName_OnYesButtonMouseFocus;
		case e_UIObjectProperty_ScriptName_OnYesButtonMouseUnfocus:		return scriptName_OnYesButtonMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnNoButtonPress:				return scriptName_OnNoButtonPress;
		case e_UIObjectProperty_ScriptName_OnNoButtonMouseFocus:		return scriptName_OnNoButtonMouseFocus;
		case e_UIObjectProperty_ScriptName_OnNoButtonMouseUnfocus:		return scriptName_OnNoButtonMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnQuestionBoxMouseFocus:		return scriptName_OnQuestionBoxMouseFocus;
		case e_UIObjectProperty_ScriptName_OnQuestionBoxMouseUnfocus:	return scriptName_OnQuestionBoxMouseUnfocus;

		case e_UIObjectProperty_BackgroundImage_TextureName:			return backgroundImageProp.textureName;
		case e_UIObjectProperty_YesButtonImage_TextureName:				return yesButtonImageProp.textureName;
		case e_UIObjectProperty_NoButtonImage_TextureName:				return noButtonImageProp.textureName;
		case e_UIObjectProperty_QuestionText_Facename:					return questionTextProp.facename;
		case e_UIObjectProperty_QuestionText_Line:						return questionTextProp.line;
		case e_UIObjectProperty_YesButtonText_Facename:					return yesButtonTextProp.facename;
		case e_UIObjectProperty_YesButtonText_Line:						return yesButtonTextProp.line;
		case e_UIObjectProperty_NoButtonText_Facename:					return noButtonTextProp.facename;
		case e_UIObjectProperty_NoButtonText_Line:						return noButtonTextProp.line;

		default: throw invalid_argument("CQuestionBox::GetProperty - iProperty is not valid QuestionBox property");
		}
	}

//*****************************************************************************

void CQuestionBox::SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								visible										= iValue; return;
		case e_UIObjectProperty_Active:									active										= iValue; return;
		
		case e_UIObjectProperty_QuestionText_Italic:					questionTextProp.italic						= iValue; return;
		case e_UIObjectProperty_YesButtonText_Italic:					yesButtonTextProp.italic					= iValue; return;
		case e_UIObjectProperty_NoButtonText_Italic:					noButtonTextProp.italic						= iValue; return;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	backgroundImageProp.alphaIntersectionTest	= iValue; return;
		case e_UIObjectProperty_YesButtonImage_AlphaIntersectionTest:	yesButtonImageProp.alphaIntersectionTest	= iValue; return;
		case e_UIObjectProperty_NoButtonImage_AlphaIntersectionTest:	noButtonImageProp.alphaIntersectionTest		= iValue; return;
		
		default: throw invalid_argument("CQuestionBox::SetProperty - iProperty is not valid QuestionBox property");
		}
	}

//*****************************************************************************

void CQuestionBox::SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	throw invalid_argument("CQuestionBox::SetProperty - iProperty is not valid QuestionBox property");
	}

//*****************************************************************************

void CQuestionBox::SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_MaxQuestionTextSize:		maxQuestionTextSize				= iValue; GetQuestionTextToRender(); return;

		case e_UIObjectProperty_ScaleX:						scale.x							= iValue; return;
		case e_UIObjectProperty_ScaleY:						scale.y							= iValue; return;

		case e_UIObjectProperty_BackgroundImage_OffsetX:	backgroundImageProp.offset.x	= iValue; return;
		case e_UIObjectProperty_BackgroundImage_OffsetY:	backgroundImageProp.offset.y	= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorR:		backgroundImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorG:		backgroundImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorB:		backgroundImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ColorA:		backgroundImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ScaleX:		backgroundImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_ScaleY:		backgroundImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_BackgroundImage_Rotation:	backgroundImageProp.rotation	= iValue; return;

		case e_UIObjectProperty_YesButtonImage_OffsetX:		yesButtonImageProp.offset.x		= iValue; return;
		case e_UIObjectProperty_YesButtonImage_OffsetY:		yesButtonImageProp.offset.y		= iValue; return;
		case e_UIObjectProperty_YesButtonImage_ColorR:		yesButtonImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_YesButtonImage_ColorG:		yesButtonImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_YesButtonImage_ColorB:		yesButtonImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_YesButtonImage_ColorA:		yesButtonImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_YesButtonImage_ScaleX:		yesButtonImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_YesButtonImage_ScaleY:		yesButtonImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_YesButtonImage_Rotation:	yesButtonImageProp.rotation		= iValue; return;

		case e_UIObjectProperty_YesButtonText_OffsetX:		yesButtonTextProp.offset.x		= iValue; return;
		case e_UIObjectProperty_YesButtonText_OffsetY:		yesButtonTextProp.offset.y		= iValue; return;
		case e_UIObjectProperty_YesButtonText_ColorR:		yesButtonTextProp.color.r		= iValue; return;
		case e_UIObjectProperty_YesButtonText_ColorG:		yesButtonTextProp.color.g		= iValue; return;
		case e_UIObjectProperty_YesButtonText_ColorB:		yesButtonTextProp.color.b		= iValue; return;
		case e_UIObjectProperty_YesButtonText_ColorA:		yesButtonTextProp.color.a		= iValue; return;
		case e_UIObjectProperty_YesButtonText_Height:		yesButtonTextProp.height		= iValue; return;
		case e_UIObjectProperty_YesButtonText_Weight:		yesButtonTextProp.weight		= iValue; return;

		case e_UIObjectProperty_NoButtonImage_OffsetX:		noButtonImageProp.offset.x		= iValue; return;
		case e_UIObjectProperty_NoButtonImage_OffsetY:		noButtonImageProp.offset.y		= iValue; return;
		case e_UIObjectProperty_NoButtonImage_ColorR:		noButtonImageProp.color.r		= iValue; return;
		case e_UIObjectProperty_NoButtonImage_ColorG:		noButtonImageProp.color.g		= iValue; return;
		case e_UIObjectProperty_NoButtonImage_ColorB:		noButtonImageProp.color.b		= iValue; return;
		case e_UIObjectProperty_NoButtonImage_ColorA:		noButtonImageProp.color.a		= iValue; return;
		case e_UIObjectProperty_NoButtonImage_ScaleX:		noButtonImageProp.scale.x		= iValue; return;
		case e_UIObjectProperty_NoButtonImage_ScaleY:		noButtonImageProp.scale.y		= iValue; return;
		case e_UIObjectProperty_NoButtonImage_Rotation:		noButtonImageProp.rotation		= iValue; return;

		case e_UIObjectProperty_NoButtonText_OffsetX:		noButtonTextProp.offset.x		= iValue; return;
		case e_UIObjectProperty_NoButtonText_OffsetY:		noButtonTextProp.offset.y		= iValue; return;
		case e_UIObjectProperty_NoButtonText_ColorR:		noButtonTextProp.color.r		= iValue; return;
		case e_UIObjectProperty_NoButtonText_ColorG:		noButtonTextProp.color.g		= iValue; return;
		case e_UIObjectProperty_NoButtonText_ColorB:		noButtonTextProp.color.b		= iValue; return;
		case e_UIObjectProperty_NoButtonText_ColorA:		noButtonTextProp.color.a		= iValue; return;
		case e_UIObjectProperty_NoButtonText_Height:		noButtonTextProp.height			= iValue; return;
		case e_UIObjectProperty_NoButtonText_Weight:		noButtonTextProp.weight			= iValue; return;

		case e_UIObjectProperty_QuestionText_OffsetX:		questionTextProp.offset.x		= iValue; return;
		case e_UIObjectProperty_QuestionText_OffsetY:		questionTextProp.offset.y		= iValue; return;
		case e_UIObjectProperty_QuestionText_ColorR:		questionTextProp.color.r		= iValue; return;
		case e_UIObjectProperty_QuestionText_ColorG:		questionTextProp.color.g		= iValue; return;
		case e_UIObjectProperty_QuestionText_ColorB:		questionTextProp.color.b		= iValue; return;
		case e_UIObjectProperty_QuestionText_ColorA:		questionTextProp.color.a		= iValue; return;
		case e_UIObjectProperty_QuestionText_Height:		questionTextProp.height			= iValue; GetQuestionTextToRender(); return;
		case e_UIObjectProperty_QuestionText_Weight:		questionTextProp.weight			= iValue; return;

		default: throw invalid_argument("CQuestionBox::SetProperty - iProperty is not valid QuestionBox property");
		}
	}

//*****************************************************************************

void CQuestionBox::SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:					scriptName_OnFrameMove					= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRender:					scriptName_OnRender						= iValue; return;
		case e_UIObjectProperty_ScriptName_OnYesButtonPress:			scriptName_OnYesButtonPress				= iValue; return;
		case e_UIObjectProperty_ScriptName_OnYesButtonMouseFocus:		scriptName_OnYesButtonMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnYesButtonMouseUnfocus:		scriptName_OnYesButtonMouseUnfocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnNoButtonPress:				scriptName_OnNoButtonPress				= iValue; return;
		case e_UIObjectProperty_ScriptName_OnNoButtonMouseFocus:		scriptName_OnNoButtonMouseFocus			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnNoButtonMouseUnfocus:		scriptName_OnNoButtonMouseUnfocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnQuestionBoxMouseFocus:		scriptName_OnQuestionBoxMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnQuestionBoxMouseUnfocus:	scriptName_OnQuestionBoxMouseUnfocus	= iValue; return;

		case e_UIObjectProperty_BackgroundImage_TextureName:			backgroundImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_YesButtonImage_TextureName:				yesButtonImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_QuestionText_Facename:					questionTextProp.facename				= iValue; return;
		case e_UIObjectProperty_QuestionText_Line:						questionTextProp.line					= iValue; GetQuestionTextToRender(); return;
		case e_UIObjectProperty_YesButtonText_Facename:					yesButtonTextProp.facename				= iValue; return;
		case e_UIObjectProperty_YesButtonText_Line:						yesButtonTextProp.line					= iValue; return;
		case e_UIObjectProperty_NoButtonText_Facename:					noButtonTextProp.facename				= iValue; return;
		case e_UIObjectProperty_NoButtonText_Line:						noButtonTextProp.line					= iValue; return;

		default: throw invalid_argument("CQuestionBox::SetProperty - iProperty is not valid QuestionBox property");
		}
	}

//*****************************************************************************

bool CQuestionBox::Intersect(const D3DXVECTOR2& iPosition)
	{
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || yesButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || noButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		return true;
	else
		return false;
	}

//*****************************************************************************

wstring	CQuestionBox::GetQuestionTextToRender()
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


