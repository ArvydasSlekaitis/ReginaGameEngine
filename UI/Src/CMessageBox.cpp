/*
    CMessageBox.cpp - Contains class CMessageBox implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CMessageBox.h>
using namespace Regina::UI;


//*****************************************************************************

CMessageBox::~CMessageBox()
  	{
	}

//*****************************************************************************

CMessageBox::CMessageBox(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, const vector<wstring>& iInitializingScript) : CUIMessage(iHWnd, iLanguage, iOriginalScreenResolution, iName, EUIObjectType::e_UIObject_MessageBox), messageTextProp(iOriginalScreenResolution, iOriginalScreenResolution), okButtonTextProp(iOriginalScreenResolution, iOriginalScreenResolution), backgroundImageProp(iOriginalScreenResolution, iOriginalScreenResolution), okButtonImageProp(iOriginalScreenResolution, iOriginalScreenResolution), scriptManager(this), position(0, 0), scale(1, 1), maxMessageTextSize(50), messageTextToRender(iOriginalScreenResolution, iOriginalScreenResolution), scriptName_OnFrameMove(L""), scriptName_OnRender(L""), scriptName_OnOkButtonPress(L""), scriptName_OnOkButtonMouseFocus(L""), scriptName_OnOkButtonMouseUnfocus(L""), scriptName_OnMessageBoxMouseFocus(L""), scriptName_OnMessageBoxMouseUnfocus(L"")
  	{
	scriptManager.VariablePool().AddLocalVariable(L"elapsedTime", &elapsedTime);
	scriptManager.VariablePool().AddLocalVariable(L"time", &time);
	scriptManager.VariablePool().AddLocalVariable(L"visible", &visible);
	scriptManager.VariablePool().AddLocalVariable(L"active", &active);

	scriptManager.VariablePool().AddLocalVariable(L"positionX", &position.x);
	scriptManager.VariablePool().AddLocalVariable(L"positionY", &position.y);

	scriptManager.VariablePool().AddLocalVariable(L"scaleX", &scale.x);
	scriptManager.VariablePool().AddLocalVariable(L"scaleY", &scale.y);

	scriptManager.VariablePool().AddLocalVariable(L"maxMessageTextSize", &maxMessageTextSize);

	//Message Text
	scriptManager.VariablePool().AddLocalVariable(L"messageText_offsetX", &messageTextProp.offset.x);
	scriptManager.VariablePool().AddLocalVariable(L"messageText_offsetY", &messageTextProp.offset.y);
	scriptManager.VariablePool().AddLocalVariable(L"messageText_colorR", &messageTextProp.color.r);
	scriptManager.VariablePool().AddLocalVariable(L"messageText_colorG", &messageTextProp.color.g);
	scriptManager.VariablePool().AddLocalVariable(L"messageText_colorB", &messageTextProp.color.b);
	scriptManager.VariablePool().AddLocalVariable(L"messageText_colorA", &messageTextProp.color.a);
	scriptManager.VariablePool().AddLocalVariable(L"messageText_facename", &messageTextProp.facename);
	scriptManager.VariablePool().AddLocalVariable(L"messageText_height", &messageTextProp.height);
	scriptManager.VariablePool().AddLocalVariable(L"messageText_weight", &messageTextProp.weight);
	scriptManager.VariablePool().AddLocalVariable(L"messageText_italic", &messageTextProp.italic);
	scriptManager.VariablePool().AddLocalVariable(L"messageText_line", &messageTextProp.line);

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

	//Script name
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnFrameMove", &scriptName_OnFrameMove);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnRender", &scriptName_OnRender);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnOkButtonPress", &scriptName_OnOkButtonPress);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnOkButtonMouseFocus", &scriptName_OnOkButtonMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnOkButtonMouseUnFocus", &scriptName_OnOkButtonMouseUnfocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnMessageBoxMouseFocus", &scriptName_OnMessageBoxMouseFocus);
	scriptManager.VariablePool().AddLocalVariable(L"scriptName_OnMessageBoxMouseUnFocus", &scriptName_OnMessageBoxMouseUnfocus);

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

	GetMessageTextToRender();
	}

//*****************************************************************************

void CMessageBox::On_FrameMove()
  	{
	RunScript(scriptName_OnFrameMove);
	CallCallbackFunction(EUIEventType::e_UIEvent_FrameMove);

	//On Message box mouse focus/unfocus
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale) || okButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		{
		RunScript(scriptName_OnMessageBoxMouseFocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_MessageBoxMouseFocus);
		}
	else
		{
		RunScript(scriptName_OnMessageBoxMouseUnfocus);
		CallCallbackFunction(EUIEventType::e_UIEvent_MessageBoxMouseUnfocus);
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
	}

//*****************************************************************************

void CMessageBox::On_Render()
  	{
	RunScript(scriptName_OnRender);

	position = TransformToUIScreenSpaceInverse(originalScreenResolution, screenResolution, screenResolution/2);

	backgroundImageProp.Render(position, scale, scale);
	messageTextProp.Render(position, GetMessageTextToRender(), scale, scale);
	okButtonImageProp.Render(position, scale, scale);
	okButtonTextProp.Render(position, scale, scale);

	CallCallbackFunction(EUIEventType::e_UIEvent_Render);
	}

//*****************************************************************************

bool CMessageBox::On_LeftClick(const D3DXVECTOR2& iCursorPosition)
  	{
	if(okButtonImageProp.Intersect(iCursorPosition, position, scale, scale))
		{
		RunScript(scriptName_OnOkButtonPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_OkButtonPress);

		if(State() == E_UIMessageState_Render)
			SetState(E_UIMessageState_BeginTermination);

		return true;
		}

	if(backgroundImageProp.Intersect(iCursorPosition, position, scale, scale))
		return true;

	return false;
	}

//*****************************************************************************

bool CMessageBox::On_KeyDown(const wchar_t& iKey)
	{
	if(iKey == VK_RETURN)
		{
		RunScript(scriptName_OnOkButtonPress);
		CallCallbackFunction(EUIEventType::e_UIEvent_OkButtonPress);

		if(State() == E_UIMessageState_Render)
			SetState(E_UIMessageState_BeginTermination);

		return true;
		}
	else
		return false;
	}

//*****************************************************************************
	
void CMessageBox::On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	messageTextToRender.SetScreenResolution(iScreenResolution);
	messageTextProp.SetScreenResolution(iScreenResolution);
	okButtonTextProp.SetScreenResolution(iScreenResolution);
	okButtonImageProp.SetScreenResolution(iScreenResolution);
	backgroundImageProp.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************
	
void CMessageBox::GetInitializingText(vector<wstring>& oText)
	{
	oText.push_back(L"MessageBox " + Name());
	oText.push_back(L"{");
	scriptManager.VariablePool().GetInitializingScriptText(oText);
	oText.push_back(L"}");
	}

//*****************************************************************************

void CMessageBox::RunScript(const wstring& iScriptName)
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

bool CMessageBox::GetProperty(const EUIObjectProperty_Bool& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								return visible;
		case e_UIObjectProperty_Active:									return active;

		case e_UIObjectProperty_MessageText_Italic:						return messageTextProp.italic;
		case e_UIObjectProperty_OkButtonText_Italic:					return okButtonTextProp.italic;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	return backgroundImageProp.alphaIntersectionTest;
		case e_UIObjectProperty_OkButtonImage_AlphaIntersectionTest:	return okButtonImageProp.alphaIntersectionTest;
		
		default: throw invalid_argument("CMessageBox::GetProperty - iProperty is not valid MessageBox property");
		}
	}

//*****************************************************************************

int	CMessageBox::GetProperty(const EUIObjectProperty_Int& iProperty)
	{
	throw invalid_argument("CMessageBox::GetProperty - iProperty is not valid MessageBox property");
	}

//*****************************************************************************

float CMessageBox::GetProperty(const EUIObjectProperty_Float& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_MaxMessageTextSize:			return maxMessageTextSize;
	
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

		case e_UIObjectProperty_MessageText_OffsetX:		return messageTextProp.offset.x;
		case e_UIObjectProperty_MessageText_OffsetY:		return messageTextProp.offset.y;
		case e_UIObjectProperty_MessageText_ColorR:			return messageTextProp.color.r;
		case e_UIObjectProperty_MessageText_ColorG:			return messageTextProp.color.g;
		case e_UIObjectProperty_MessageText_ColorB:			return messageTextProp.color.b;
		case e_UIObjectProperty_MessageText_ColorA:			return messageTextProp.color.a;
		case e_UIObjectProperty_MessageText_Height:			return messageTextProp.height;
		case e_UIObjectProperty_MessageText_Weight:			return messageTextProp.weight;

		case e_UIObjectProperty_OkButtonText_OffsetX:		return okButtonTextProp.offset.x;
		case e_UIObjectProperty_OkButtonText_OffsetY:		return okButtonTextProp.offset.y;
		case e_UIObjectProperty_OkButtonText_ColorR:		return okButtonTextProp.color.r;
		case e_UIObjectProperty_OkButtonText_ColorG:		return okButtonTextProp.color.g;
		case e_UIObjectProperty_OkButtonText_ColorB:		return okButtonTextProp.color.b;
		case e_UIObjectProperty_OkButtonText_ColorA:		return okButtonTextProp.color.a;
		case e_UIObjectProperty_OkButtonText_Height:		return okButtonTextProp.height;
		case e_UIObjectProperty_OkButtonText_Weight:		return okButtonTextProp.weight;


		default: throw invalid_argument("CMessageBox::GetProperty - iProperty is not valid MessageBox property");
		}
	}

//*****************************************************************************

wstring	CMessageBox::GetProperty(const EUIObjectProperty_String& iProperty)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:					return scriptName_OnFrameMove;
		case e_UIObjectProperty_ScriptName_OnRender:					return scriptName_OnRender;
		case e_UIObjectProperty_ScriptName_OnOkButtonPress:				return scriptName_OnOkButtonPress;
		case e_UIObjectProperty_ScriptName_OnOkButtonMouseFocus:		return scriptName_OnOkButtonMouseFocus;
		case e_UIObjectProperty_ScriptName_OnOkButtonMouseUnfocus:		return scriptName_OnOkButtonMouseUnfocus;
		case e_UIObjectProperty_ScriptName_OnMessageBoxMouseFocus:		return scriptName_OnMessageBoxMouseFocus;
		case e_UIObjectProperty_ScriptName_OnMessageBoxMouseUnfocus:	return scriptName_OnMessageBoxMouseUnfocus;

		case e_UIObjectProperty_BackgroundImage_TextureName:			return backgroundImageProp.textureName;
		case e_UIObjectProperty_OkButtonImage_TextureName:				return okButtonImageProp.textureName;
		case e_UIObjectProperty_MessageText_Facename:					return messageTextProp.facename;
		case e_UIObjectProperty_MessageText_Line:						return messageTextProp.line;
		case e_UIObjectProperty_OkButtonText_Facename:					return okButtonTextProp.facename;
		case e_UIObjectProperty_OkButtonText_Line:						return okButtonTextProp.line;

		default: throw invalid_argument("CMessageBox::GetProperty - iProperty is not valid MessageBox property");
		}
	}

//*****************************************************************************

void CMessageBox::SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_Visible:								visible											= iValue; return;
		case e_UIObjectProperty_Active:									active											= iValue; return;
		
		case e_UIObjectProperty_MessageText_Italic:						messageTextProp.italic							= iValue; return;
		case e_UIObjectProperty_OkButtonText_Italic:					okButtonTextProp.italic							= iValue; return;
		case e_UIObjectProperty_BackgroundImage_AlphaIntersectionTest:	backgroundImageProp.alphaIntersectionTest		= iValue; return;
		case e_UIObjectProperty_OkButtonImage_AlphaIntersectionTest:	okButtonImageProp.alphaIntersectionTest			= iValue; return;

		default: throw invalid_argument("CMessageBox::SetProperty - iProperty is not valid MessageBox property");
		}
	}

//*****************************************************************************

void CMessageBox::SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	throw invalid_argument("CMessageBox::SetProperty - iProperty is not valid MessageBox property");
	}

//*****************************************************************************

void CMessageBox::SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScaleX:						scale.x							= iValue; return;
		case e_UIObjectProperty_ScaleY:						scale.y							= iValue; return;

		case e_UIObjectProperty_MaxMessageTextSize:			maxMessageTextSize				= iValue; GetMessageTextToRender(); return;

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

		case e_UIObjectProperty_MessageText_OffsetX:		messageTextProp.offset.x		= iValue; return;
		case e_UIObjectProperty_MessageText_OffsetY:		messageTextProp.offset.y		= iValue; return;
		case e_UIObjectProperty_MessageText_ColorR:			messageTextProp.color.r			= iValue; return;
		case e_UIObjectProperty_MessageText_ColorG:			messageTextProp.color.g			= iValue; return;
		case e_UIObjectProperty_MessageText_ColorB:			messageTextProp.color.b			= iValue; return;
		case e_UIObjectProperty_MessageText_ColorA:			messageTextProp.color.a			= iValue; return;
		case e_UIObjectProperty_MessageText_Height:			messageTextProp.height			= iValue; GetMessageTextToRender(); return;
		case e_UIObjectProperty_MessageText_Weight:			messageTextProp.weight			= iValue; return;

		case e_UIObjectProperty_OkButtonText_OffsetX:		okButtonTextProp.offset.x		= iValue; return;
		case e_UIObjectProperty_OkButtonText_OffsetY:		okButtonTextProp.offset.y		= iValue; return;
		case e_UIObjectProperty_OkButtonText_ColorR:		okButtonTextProp.color.r		= iValue; return;
		case e_UIObjectProperty_OkButtonText_ColorG:		okButtonTextProp.color.g		= iValue; return;
		case e_UIObjectProperty_OkButtonText_ColorB:		okButtonTextProp.color.b		= iValue; return;
		case e_UIObjectProperty_OkButtonText_ColorA:		okButtonTextProp.color.a		= iValue; return;
		case e_UIObjectProperty_OkButtonText_Height:		okButtonTextProp.height			= iValue; return;
		case e_UIObjectProperty_OkButtonText_Weight:		okButtonTextProp.weight			= iValue; return;

		default: throw invalid_argument("CMessageBox::SetProperty - iProperty is not valid MessageBox property");
		}
	}

//*****************************************************************************

void CMessageBox::SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	switch(iProperty)
		{
		case e_UIObjectProperty_ScriptName_OnFrameMove:					scriptName_OnFrameMove					= iValue; return;
		case e_UIObjectProperty_ScriptName_OnRender:					scriptName_OnRender						= iValue; return;
		case e_UIObjectProperty_ScriptName_OnOkButtonPress:				scriptName_OnOkButtonPress				= iValue; return;
		case e_UIObjectProperty_ScriptName_OnOkButtonMouseFocus:		scriptName_OnOkButtonMouseFocus			= iValue; return;
		case e_UIObjectProperty_ScriptName_OnOkButtonMouseUnfocus:		scriptName_OnOkButtonMouseUnfocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnMessageBoxMouseFocus:		scriptName_OnMessageBoxMouseFocus		= iValue; return;
		case e_UIObjectProperty_ScriptName_OnMessageBoxMouseUnfocus:	scriptName_OnMessageBoxMouseUnfocus		= iValue; return;

		case e_UIObjectProperty_BackgroundImage_TextureName:			backgroundImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_OkButtonImage_TextureName:				okButtonImageProp.textureName			= iValue; return;
		case e_UIObjectProperty_MessageText_Facename:					messageTextProp.facename				= iValue; return;
		case e_UIObjectProperty_MessageText_Line:						messageTextProp.line					= iValue; GetMessageTextToRender(); return;
		case e_UIObjectProperty_OkButtonText_Facename:					okButtonTextProp.facename				= iValue; return;
		case e_UIObjectProperty_OkButtonText_Line:						okButtonTextProp.line					= iValue; return;

		default: throw invalid_argument("CMessageBox::SetProperty - iProperty is not valid MessageBox property");
		}
	}

//*****************************************************************************

bool CMessageBox::Intersect(const D3DXVECTOR2& iPosition)
	{
	if(backgroundImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale) || okButtonImageProp.Intersect(Cursor_Position(hWnd), position, scale, scale))
		return true;
	else
		return false;
	}

//*****************************************************************************

wstring	CMessageBox::GetMessageTextToRender()
	{
	if(maxMessageTextSize < 0)
		maxMessageTextSize = 0; 

	messageTextToRender = messageTextProp;

	while(true)
		{
		const float curSize = messageTextToRender.GetTextExtent(scale).right;
		D3DXVECTOR2 curMaxTextSizeTemp(maxMessageTextSize*scale.x, 0);
		curMaxTextSizeTemp = TransformToUIScreenSpace(originalScreenResolution, screenResolution, curMaxTextSizeTemp);
		const float curMaxTextSize = curMaxTextSizeTemp.x;

		if(curSize <= curMaxTextSize)
			break;
		else
			if(messageTextToRender.line.size() > 0)
				messageTextToRender.line.erase(messageTextToRender.line.end()-1);
			else
				break;
		}

	return messageTextToRender.line;
	}

//*****************************************************************************


