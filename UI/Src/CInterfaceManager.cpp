/*
    CInterfaceManager.cpp - Contains class CInterfaceManager implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CInterfaceManager.h>
using namespace Regina::UI;


//*****************************************************************************

CInterfaceManager::CInterfaceManager(HWND iHWnd, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iLanguage) : language(iLanguage), hWnd(iHWnd), screenResolution(iOriginalScreenResolution), originalScreenResolution(iOriginalScreenResolution)
	{
	}

//*****************************************************************************

CInterfaceManager::~CInterfaceManager()
	{
	Clear();
	}

//*****************************************************************************

void CInterfaceManager::AddInterface(CInterface* iInterface)
	{
	assert(iInterface!=NULL && L"CInterfaceManager::AddInterface - iInterface == NULL");
	interfaceVector.push_back(iInterface);
	interfaceMap.insert(make_pair(iInterface->Name(), iInterface));
	}

//*****************************************************************************

CInterface*	CInterfaceManager::GetInterface(const wstring& iInterfaceName)
	{
	map<wstring, CInterface*>::iterator it = interfaceMap.find(iInterfaceName);
	
	if(it!=interfaceMap.end())
		return it->second;
	else
		return NULL;
	}

//*****************************************************************************

void CInterfaceManager::Load(const vector<wstring>& iInitializingText)
	{
	for(unsigned i = 0; i<iInitializingText.size(); i++)
		{
		if(iInitializingText[i].size() == 0)
			continue;

		wstring interfaceType;
		wstring interfaceName;
		wistringstream is(iInitializingText[i]);
		is >> interfaceType >> interfaceName;

		vector<wstring> initializingInterfaceText;

		i++;
		
		LoadInterfaceText(iInitializingText, i, initializingInterfaceText);

		if(interfaceType == L"Interface")
			{
			AddInterface(originalScreenResolution, interfaceName, language, initializingInterfaceText);
			continue;
			}

		throw CException("CInterface::Load", "Bad initializing text - unknown interface type");
		}
	}

//*****************************************************************************

void CInterfaceManager::LoadInterfaceText(const vector<wstring>& iInitializingText, unsigned& ioCurrentLine, vector<wstring>& oInitializingInterfaceText)
	{
	if(iInitializingText[ioCurrentLine] != L"{")
		throw CException("CInterfaceManager::LoadInterfaceText", "Bad initializing text ( after interface name must follow '{' )");

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
				oInitializingInterfaceText.push_back(iInitializingText[ioCurrentLine]);
			}
		else
			oInitializingInterfaceText.push_back(iInitializingText[ioCurrentLine]);
		}

	if(endFound == false)
		throw CException("CInterfaceManager::LoadInterfaceText", "Bad initializing text ( after interface initializing text must follow '}' )");		
	}

//*****************************************************************************

void CInterfaceManager::FrameMove(const float& iElapsedTime)
	{
	for(unsigned i=0; i<interfaceRunning.size(); i++)
		interfaceRunning[i]->FrameMove(iElapsedTime);
	}

//*****************************************************************************

void CInterfaceManager::Render(const wstring& iInterfaceName)
	{
	for(unsigned i=0; i<interfaceRunning.size(); i++)
		if(interfaceRunning[i]->Name() == iInterfaceName)
			return;

	CInterface* tInterface = GetInterface(iInterfaceName);
	if(tInterface != NULL)
		{
		tInterface->Render();
		interfaceRunning.push_back(tInterface);
		}
	else
		throw invalid_argument("CInterfaceManager::Render - Argument iInterfaceName - Specified interface does not exist.");
	}

//*****************************************************************************

bool CInterfaceManager::MsgProc(UINT uMsg, WPARAM wParam)
	{
	for(unsigned i=0; i<interfaceRunning.size(); i++)
		if(interfaceRunning[i]->MsgProc(uMsg, wParam) == true)
			return true;

	return false;
	}

//*****************************************************************************

void CInterfaceManager::Clear()
	{
	for(unsigned i=0; i<interfaceVector.size(); i++)
		delete interfaceVector[i];

	interfaceRunning.clear();
	interfaceMap.clear();
	interfaceVector.clear();
	}

//*****************************************************************************

void CInterfaceManager::ClearRenderList()
	{
	interfaceRunning.clear();
	}

//*****************************************************************************

void CInterfaceManager::AddInterface(const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, const wstring& iLanguage, const vector<wstring>& iInitializingText)
	{
	if(ExistInterface(iName))
		throw invalid_argument("CInterfaceManager::AddInterface - Argument iName - Specified interface already exist.");

	AddInterface(new CInterface(hWnd, iOriginalScreenResolution, iName, iLanguage, iInitializingText));
	}

//*****************************************************************************

void CInterfaceManager::RemoveInterface(const wstring& iInterfaceName)
	{
	for(unsigned i=0; i<interfaceVector.size(); i++)
		if(interfaceVector[i]->Name() == iInterfaceName)
			{
			delete interfaceVector[i];

			for(unsigned ii=i; ii<interfaceVector.size()-1; ii++)
				interfaceVector[ii] = interfaceVector[ii+1];

			interfaceVector.pop_back();

			interfaceMap.erase(iInterfaceName);

			for(unsigned iii=0; iii<interfaceRunning.size(); iii++)
				if(interfaceRunning[iii]->Name() == iInterfaceName)
					{
					for(unsigned iiii=iii; iiii<interfaceRunning.size()-1; iiii++)
						interfaceRunning[iiii] = interfaceRunning[iiii+1];

					interfaceRunning.pop_back();
					}

			break;
			}
	}

//*****************************************************************************

bool CInterfaceManager::ExistInterface(const wstring& iInterfaceName)
	{
	return (interfaceMap.find(iInterfaceName) != interfaceMap.end()); 
	}

//*****************************************************************************

void CInterfaceManager::GetInterfaceList(vector<wstring>& oInterfaceList)
	{
	for(unsigned i=0; i<interfaceVector.size(); i++)
		oInterfaceList.push_back(interfaceVector[i]->Name());	
	}

//*****************************************************************************

void CInterfaceManager::Add_Label(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::Add_Label - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->Add_Label(iName, iInitializingText);
	}

//*****************************************************************************

void CInterfaceManager::Add_Image(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::Add_Image - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->Add_Image(iName, iInitializingText);
	}

//*****************************************************************************

void CInterfaceManager::Add_EditBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::Add_EditBox - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->Add_EditBox(iName, iInitializingText);
	}

//*****************************************************************************

void CInterfaceManager::Add_CheckBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::Add_CheckBox - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->Add_CheckBox(iName, iInitializingText);
	}

//*****************************************************************************

void CInterfaceManager::Add_VerticalScrollBar(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::Add_VerticalScrollBar - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->Add_VerticalScrollBar(iName, iInitializingText);
	}

//*****************************************************************************

void CInterfaceManager::Add_HorizontalScrollBar(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::Add_HorizontalScrollBar - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->Add_HorizontalScrollBar(iName, iInitializingText);
	}

//*****************************************************************************

void CInterfaceManager::Add_TextBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::Add_TextBox - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->Add_TextBox(iName, iInitializingText);
	}

//*****************************************************************************

bool CInterfaceManager::ExistObject(const wstring& iInterfaceName, const wstring& iObjectName)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::ExistObject - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->Exist(iObjectName);
	}

//*****************************************************************************

void CInterfaceManager::RemoveObject(const wstring& iInterfaceName, const wstring& iObjectName)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::RemoveObject - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->Remove(iObjectName);
	}

//*****************************************************************************

void CInterfaceManager::GetObjectList(const wstring& iInterfaceName, vector<wstring>& oObjectList)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::GetObjectList - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->GetObjectList(oObjectList);
	}

//*****************************************************************************

void CInterfaceManager::IncreaseObjectPriority(const wstring& iInterfaceName, const wstring& iObjectName)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::IncreaseObjectPriority - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->IncreasePriority(iObjectName);
	}

//*****************************************************************************

void CInterfaceManager::DecreaseObjectPriority(const wstring& iInterfaceName, const wstring& iObjectName)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::DecreaseObjectPriority - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->DecreasePriority(iObjectName);
	}

//*****************************************************************************

void CInterfaceManager::SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
	{
	screenResolution = iScreenResolution;

	for(unsigned i=0; i<interfaceVector.size(); i++)
		interfaceVector[i]->SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************

void CInterfaceManager::GetInitializingText(vector<wstring>& oInitializingText)
	{
	wostringstream os;
	os << L"InterfaceManager";
	oInitializingText.push_back(os.str());
	oInitializingText.push_back(L"{");

	for(unsigned i=0; i<interfaceVector.size(); i++)
		interfaceVector[i]->GetInitializingText(oInitializingText);

	oInitializingText.push_back(L"}");
	}

//*****************************************************************************

void CInterfaceManager::DeselectAll()
	{
	for(unsigned i=0; i<interfaceVector.size(); i++)
		interfaceVector[i]->DeselectAll();
	}

//*****************************************************************************

bool CInterfaceManager::GetFirstIntersection(const wstring& iInterfaceName, const D3DXVECTOR2& iPosition, wstring& oIntersectedObjectName)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::GetFirstIntersection - Argument iInterfaceName - Specified interface does not exist.");

	return tInterface->GetFirstIntersection(iPosition, oIntersectedObjectName);
	}

//*****************************************************************************

void CInterfaceManager::SetCallbackFunction(const wstring& iInterfaceName, const wstring& iObjectName, const EUIEventType& iEventType, void (*iCallbackFunction)(const CUIEventInformation&))
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::SetCallbackFunction - Argument iInterfaceName - Specified interface does not exist.");

	return tInterface->SetCallbackFunction(iObjectName, iEventType, iCallbackFunction);
	}

//*****************************************************************************

bool CInterfaceManager::GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::GetProperty - Argument iInterfaceName - Specified interface does not exist.");

	return tInterface->GetProperty(iObjectName, iProperty);
	}

//*****************************************************************************

int	CInterfaceManager::GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Int& iProperty)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::GetProperty - Argument iInterfaceName - Specified interface does not exist.");

	return tInterface->GetProperty(iObjectName, iProperty);
	}

//*****************************************************************************

float CInterfaceManager::GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Float& iProperty)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::GetProperty - Argument iInterfaceName - Specified interface does not exist.");

	return tInterface->GetProperty(iObjectName, iProperty);
	}

//*****************************************************************************

wstring CInterfaceManager::GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_String& iProperty)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::GetProperty - Argument iInterfaceName - Specified interface does not exist.");

	return tInterface->GetProperty(iObjectName, iProperty);
	}

//*****************************************************************************

void CInterfaceManager::SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty, const bool& iValue)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::SetProperty - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->SetProperty(iObjectName, iProperty, iValue);
	}

//*****************************************************************************

void CInterfaceManager::SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Int& iProperty, const int& iValue)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::SetProperty - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->SetProperty(iObjectName, iProperty, iValue);
	}

//*****************************************************************************

void CInterfaceManager::SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Float& iProperty, const float& iValue)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::SetProperty - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->SetProperty(iObjectName, iProperty, iValue);
	}

//*****************************************************************************

void CInterfaceManager::SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_String& iProperty, const wstring& iValue)
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::SetProperty - Argument iInterfaceName - Specified interface does not exist.");

	tInterface->SetProperty(iObjectName, iProperty, iValue);
	}

//*****************************************************************************

unsigned CInterfaceManager::ObjectCount(const wstring& iInterfaceName) 
	{
	CInterface* tInterface = GetInterface(iInterfaceName);

	if(tInterface == NULL)
		throw invalid_argument("CInterfaceManager::ObjectCount - Argument iInterfaceName - Specified interface does not exist.");

	return tInterface->Size();
	}

//*****************************************************************************