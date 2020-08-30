/*
    CUIManager.cpp - Contains class CUIManager implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CUIManager.h>
using namespace Regina::UI;


//*****************************************************************************

CUIManager::CUIManager(HWND iHWnd, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iLanguage, const wstring iName) : CUI(iHWnd, iOriginalScreenResolution, iLanguage, iName)
	{

	}

//*****************************************************************************

CUIManager::~CUIManager()
	{

	}

//*****************************************************************************

void CUIManager::Save(const wstring& iName)
  	{
	CText text;

	interfaceManager.GetInitializingText(text);
	messageManager.GetInitializingText(text);

	wostringstream os;
		os << L"\Data\\UI\\" << iName << L"_" << language << "_" << originalScreenResolution.x << "_" << originalScreenResolution.y << L".txt";

	text.Save(os.str());
	}

//*****************************************************************************

void CUIManager::Add_Interface(const wstring& iName, const wstring& iLanguage, const vector<wstring>& iInitializingText)
  	{
	interfaceManager.AddInterface(originalScreenResolution, iName, iLanguage, iInitializingText);
	}

//*****************************************************************************

void CUIManager::RemoveInterface(const wstring& iInterfaceName)
  	{
	interfaceManager.RemoveInterface(iInterfaceName);
	}

//*****************************************************************************

bool CUIManager::ExistInterface(const wstring& iInterfaceName)
  	{
	return interfaceManager.ExistInterface(iInterfaceName);
	}

//*****************************************************************************

unsigned CUIManager::InterfaceCount() const 
  	{
	return interfaceManager.InterfaceCount();
	}

//*****************************************************************************

void CUIManager::GetInterfaceList(vector<wstring>& oInterfaceList)
  	{
	interfaceManager.GetInterfaceList(oInterfaceList);
	}

//*****************************************************************************

void CUIManager::Add_Label(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	interfaceManager.Add_Label(iInterfaceName, iName, iInitializingText);
	}

//*****************************************************************************

void CUIManager::Add_Image(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	interfaceManager.Add_Image(iInterfaceName, iName, iInitializingText);
	}

//*****************************************************************************

void CUIManager::Add_EditBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	interfaceManager.Add_EditBox(iInterfaceName, iName, iInitializingText);
	}

//*****************************************************************************

void CUIManager::Add_CheckBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	interfaceManager.Add_CheckBox(iInterfaceName, iName, iInitializingText);
	}

//*****************************************************************************

void CUIManager::Add_VerticalScrollBar(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	interfaceManager.Add_VerticalScrollBar(iInterfaceName, iName, iInitializingText);
	}

//*****************************************************************************

void CUIManager::Add_HorizontalScrollBar(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	interfaceManager.Add_HorizontalScrollBar(iInterfaceName, iName, iInitializingText);
	}

//*****************************************************************************

void CUIManager::Add_TextBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	interfaceManager.Add_TextBox(iInterfaceName, iName, iInitializingText);
	}

//*****************************************************************************

bool CUIManager::ExistObject(const wstring& iInterfaceName, const wstring& iObjectName)
  	{
	return interfaceManager.ExistObject(iInterfaceName, iObjectName);
	}

//*****************************************************************************

void CUIManager::RemoveObject(const wstring& iInterfaceName, const wstring& iObjectName)
  	{
	interfaceManager.RemoveObject(iInterfaceName, iObjectName);
	}

//*****************************************************************************

unsigned CUIManager::ObjectCount(const wstring& iInterfaceName)  
  	{
	return interfaceManager.ObjectCount(iInterfaceName);
	}

//*****************************************************************************

void CUIManager::GetObjectList(const wstring& iInterfaceName, vector<wstring>& oObjectList)
  	{
	interfaceManager.GetObjectList(iInterfaceName, oObjectList);
	}

//*****************************************************************************

void CUIManager::IncreaseObjectPriority(const wstring& iInterfaceName, const wstring& iObjectName)
  	{
	interfaceManager.IncreaseObjectPriority(iInterfaceName, iObjectName);
	}

//*****************************************************************************

void CUIManager::DecreaseObjectPriority(const wstring& iInterfaceName, const wstring& iObjectName)
  	{
	interfaceManager.DecreaseObjectPriority(iInterfaceName, iObjectName);
	}

//*****************************************************************************

bool CUIManager::GetFirstIntersection(const wstring& iInterfaceName, const D3DXVECTOR2& iPosition, wstring& oIntersectedObjectName)
	{
	return interfaceManager.GetFirstIntersection(iInterfaceName, iPosition, oIntersectedObjectName);
	}

//*****************************************************************************

void CUIManager::Add_MessageTemplate_MessageBox(const wstring& iTemplateName, const vector<wstring>& iInitializingScript)
	{
	messageManager.AddTemplate_MessageBox(iTemplateName, iInitializingScript);
	}

//*****************************************************************************

void CUIManager::Add_MessageTemplate_InputQuery(const wstring& iTemplateName, const vector<wstring>& iInitializingScript)
	{
	messageManager.AddTemplate_InputQuery(iTemplateName, iInitializingScript);
	}

//*****************************************************************************

void CUIManager::Add_MessageTemplate_QuestionBox(const wstring& iTemplateName, const vector<wstring>& iInitializingScript)
	{
	messageManager.AddTemplate_QuestionBox(iTemplateName, iInitializingScript);
	}

//*****************************************************************************

void CUIManager::RemoveMessageTemplate(const wstring& iTemplateName)
  	{
	messageManager.RemoveTemplate(iTemplateName);
	}

//*****************************************************************************

void CUIManager::GetMessageTemplateList_InputQuery(vector<wstring>& oTemplateList)
  	{
	messageManager.GetTemplateList_InputQuery(oTemplateList);
	}

//*****************************************************************************

void CUIManager::GetMessageTemplateList_MessageBox(vector<wstring>& oTemplateList)
  	{
	messageManager.GetTemplateList_MessageBox(oTemplateList);
	}

//*****************************************************************************

void CUIManager::GetMessageTemplateList_QuestionBox(vector<wstring>& oTemplateList)
  	{
	messageManager.GetTemplateList_QuestionBox(oTemplateList);
	}

//*****************************************************************************