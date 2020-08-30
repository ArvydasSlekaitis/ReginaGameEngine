/*
    CUI.cpp - Contains class CUI implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CUI.h>
using namespace Regina::UI;


//*****************************************************************************

CUI::CUI(HWND iHWnd, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iLanguage, const wstring iName) : language(iLanguage), hWnd(iHWnd), screenResolution(iOriginalScreenResolution), originalScreenResolution(iOriginalScreenResolution), interfaceManager(iHWnd, iOriginalScreenResolution, iLanguage), messageManager(iHWnd, iOriginalScreenResolution, iLanguage)
	{
	Load(iName);
	}

//*****************************************************************************

CUI::~CUI()
	{
	Clear();
	}

//*****************************************************************************

void CUI::Load(const wstring& iName)
  	{
	if(iName.size()>0)
		{
		wostringstream os;
		os << L"\Data\\UI\\" << iName << L"_" << language << "_" << originalScreenResolution.x << "_" << originalScreenResolution.y << L".txt";

		CText initializingText;
		initializingText.Load(os.str());
		
		for(unsigned i = 0; i<initializingText.size(); i++)
			{
			if(initializingText[i].size() == 0)
				continue;

			wstring moduleType;
			wistringstream is(initializingText[i]);
			is >> moduleType;

			vector<wstring> initializingModuleText;

			i++;
			
			LoadModuleText(initializingText, i, initializingModuleText);

			if(moduleType == L"MessageManager")
				{
				messageManager.Load(initializingModuleText);
				continue;
				}

			if(moduleType == L"InterfaceManager")
				{
				interfaceManager.Load(initializingModuleText);
				continue;
				}

			throw CException("CUI::Load", "Bad file format - unknown UI module type");
			}
		}
	}

//*****************************************************************************

void CUI::Clear()
	{
	interfaceManager.Clear();
	messageManager.Clear();
	}

//*****************************************************************************

void CUI::LoadModuleText(const vector<wstring>& iInitializingText, unsigned& ioCurrentLine, vector<wstring>& oInitializingModuleText)
	{
	if(iInitializingText[ioCurrentLine] != L"{")
		throw CException("CUI::LoadModuleText", "Bad initializing text ( after module type must fallow '{' )");

	ioCurrentLine++;

	bool endFound(false);

	int openings(1);

	for(; ioCurrentLine<iInitializingText.size(); ioCurrentLine++)
		{
		if(iInitializingText[ioCurrentLine].size() == 0)
			continue;

		if(iInitializingText[ioCurrentLine] == L"{")
			openings++;

		if(iInitializingText[ioCurrentLine] == L"}")
			{
			openings--;
			if(openings == 0)
				{
				endFound = true;
				break;
				}
			else
				oInitializingModuleText.push_back(iInitializingText[ioCurrentLine]);
			}
		else
			oInitializingModuleText.push_back(iInitializingText[ioCurrentLine]);
		}

	if(endFound == false)
		throw CException("CUI::LoadModuleText", "Bad initializing text ( after module initializing text must follow '}' )");		
	}

//*****************************************************************************

void CUI::FrameMove(const float& iElapsedTime)
  	{
	if(messageManager.NumMessageInQuene() > 0)
		interfaceManager.DeselectAll();

	interfaceManager.FrameMove(iElapsedTime);
	messageManager.FrameMove(iElapsedTime);
	}

//*****************************************************************************

void CUI::Render(const wstring& iInterfaceName)
  	{
	interfaceManager.Render(iInterfaceName);
	}

//*****************************************************************************

bool CUI::MsgProc(UINT uMsg, WPARAM wParam)
  	{
	if(messageManager.MsgProc(uMsg, wParam) == true)
		return true;

	if(interfaceManager.MsgProc(uMsg, wParam) == true)
		return true;

	return false;
	}

//*****************************************************************************

void CUI::Begin()
	{
	interfaceManager.ClearRenderList();
	}

//*****************************************************************************

void CUI::End()
	{
	messageManager.Render();
	}

//*****************************************************************************

bool CUI::MessageBox(const wstring& iTemplateName, const wstring& iHeader)
  	{
	return messageManager.MessageBox(iTemplateName, iHeader);
	}

//*****************************************************************************

bool CUI::InputQuery(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer)
  	{	
	if(oAnswer == NULL)
		throw invalid_argument("CUI::InputQuery - Argument oAnswer == NULL");

	return messageManager.InputQuery(iTemplateName, iHeader, oAnswer);
	}

//*****************************************************************************

bool CUI::QuestionBox(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer)
  	{
	if(oAnswer == NULL)
		throw invalid_argument("CUI::QuestionBox - Argument oAnswer == NULL");

	return messageManager.QuestionBox(iTemplateName, iHeader, oAnswer);
	}

//*****************************************************************************

void CUI::SetCallbackFunction(const wstring& iInterfaceName, const wstring& iObjectName, const EUIEventType& iEventType, void (*iCallbackFunction)(const CUIEventInformation&))
  	{
	if(iInterfaceName == L"MESSAGE_TEMPLATE")
		messageManager.SetCallbackFunction(iObjectName, iEventType, iCallbackFunction);
	else
		interfaceManager.SetCallbackFunction(iInterfaceName, iObjectName, iEventType, iCallbackFunction);
	}

//*****************************************************************************

void CUI::SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
  	{
	messageManager.SetScreenResolution(iScreenResolution);
	interfaceManager.SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************

bool CUI::GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty)
  	{
	if(iInterfaceName == L"MESSAGE_TEMPLATE")
		return messageManager.GetProperty(iObjectName, iProperty);
	else
		return interfaceManager.GetProperty(iInterfaceName, iObjectName, iProperty);
	}

//*****************************************************************************

float CUI::GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Float& iProperty)
  	{
	if(iInterfaceName == L"MESSAGE_TEMPLATE")
		return messageManager.GetProperty(iObjectName, iProperty);
	else
		return interfaceManager.GetProperty(iInterfaceName, iObjectName, iProperty);
	}

//*****************************************************************************

int CUI::GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Int& iProperty)
  	{
	if(iInterfaceName == L"MESSAGE_TEMPLATE")
		return messageManager.GetProperty(iObjectName, iProperty);
	else
		return interfaceManager.GetProperty(iInterfaceName, iObjectName, iProperty);
	}

//*****************************************************************************

wstring CUI::GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_String& iProperty)
  	{
	if(iInterfaceName == L"MESSAGE_TEMPLATE")
		return messageManager.GetProperty(iObjectName, iProperty);
	else
		return interfaceManager.GetProperty(iInterfaceName, iObjectName, iProperty);
	}

//*****************************************************************************

void CUI::SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty, const bool& iValue)
  	{
	if(iInterfaceName == L"MESSAGE_TEMPLATE")
		messageManager.SetProperty(iObjectName, iProperty, iValue);
	else
		interfaceManager.SetProperty(iInterfaceName, iObjectName, iProperty, iValue);
	}

//*****************************************************************************

void CUI::SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Int& iProperty, const int& iValue)
  	{
	if(iInterfaceName == L"MESSAGE_TEMPLATE")
		messageManager.SetProperty(iObjectName, iProperty, iValue);
	else
		interfaceManager.SetProperty(iInterfaceName, iObjectName, iProperty, iValue);
	}

//*****************************************************************************

void CUI::SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_String& iProperty, const wstring& iValue)
  	{
	if(iInterfaceName == L"MESSAGE_TEMPLATE")
		messageManager.SetProperty(iObjectName, iProperty, iValue);
	else
		interfaceManager.SetProperty(iInterfaceName, iObjectName, iProperty, iValue);
	}

//*****************************************************************************

void CUI::SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Float& iProperty, const float& iValue)
  	{
	if(iInterfaceName == L"MESSAGE_TEMPLATE")
		messageManager.SetProperty(iObjectName, iProperty, iValue);
	else
		interfaceManager.SetProperty(iInterfaceName, iObjectName, iProperty, iValue);
	}

//*****************************************************************************