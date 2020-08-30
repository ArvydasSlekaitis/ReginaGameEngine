/*
    CInterface.cpp - Contains class CInterface implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CInterface.h>
using namespace Regina::UI;


//*****************************************************************************

CInterface::CInterface(HWND iHWnd, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, const wstring& iLanguage, const vector<wstring>& iInitializingText) : name(iName), language(iLanguage), hWnd(iHWnd), screenResolution(iOriginalScreenResolution), originalScreenResolution(iOriginalScreenResolution)
	{
	Load(iInitializingText);
	}

//*****************************************************************************

CInterface::~CInterface()
	{
	Clear();
	}

//*****************************************************************************

void CInterface::Clear()
	{
	for(unsigned i=0; i<objectVector.size(); i++)
		delete objectVector[i];

	objectVector.clear();
	objectMap.clear();
	}

//*****************************************************************************

void CInterface::FrameMove(const float& iElapsedTime)
  	{
	for(unsigned i=0; i<objectVector.size(); i++)
		objectVector[i]->FrameMove(iElapsedTime);
	}

//*****************************************************************************

void CInterface::Render()
  	{
	for(unsigned i=0; i<objectVector.size(); i++)
		objectVector[i]->Render();
	}

//*****************************************************************************

bool CInterface::MsgProc(UINT uMsg, WPARAM wParam)
  	{
	if(uMsg == WM_LBUTTONDOWN || uMsg == WM_RBUTTONDOWN)
		DeselectAll();

	for(unsigned i=0; i<objectVector.size(); i++)
		if(objectVector[i]->MsgProc(uMsg, wParam) == true)
			return true;

	return false;
	}

//*****************************************************************************

void CInterface::DeselectAll()
	{
	for(unsigned i=0; i<objectVector.size(); i++)
		if(objectVector[i]->Type() == e_UIObject_EditBox)
			objectVector[i]->SetProperty(e_UIObjectProperty_Selected, false);
	}

//*****************************************************************************

void CInterface::Add(CUIObject* iObject)
  	{
	assert(iObject!=NULL && L"CInterface::Add - iObject == NULL");
	objectVector.push_back(iObject);
	objectMap.insert(make_pair(iObject->Name(), iObject));
	}

//*****************************************************************************

CUIObject* CInterface::GetObject(const wstring& iObjectName)
	{
	map<wstring, CUIObject*>::iterator it = objectMap.find(iObjectName);
	
	if(it!=objectMap.end())
		return it->second;
	else
		return NULL;
	}

//*****************************************************************************

void CInterface::Add_Label(const wstring& iName, const vector<wstring>& iInitializingText)
	{
	if(Exist(iName))
		throw invalid_argument("CInterface::Add_Label - Argument iName - Specified object already exist.");

	Add(new CLabel(hWnd, language, originalScreenResolution, name, iName, iInitializingText));
	}

//*****************************************************************************

void CInterface::Add_Image(const wstring& iName, const vector<wstring>& iInitializingText)
	{
	if(Exist(iName))
		throw invalid_argument("CInterface::Add_Image - Argument iName - Specified object already exist.");

	Add(new CImage(hWnd, language, originalScreenResolution, name, iName, iInitializingText));
	}

//*****************************************************************************

void CInterface::Add_EditBox(const wstring& iName, const vector<wstring>& iInitializingText)
	{
	if(Exist(iName))
		throw invalid_argument("CInterface::Add_EditBox - Argument iName - Specified object already exist.");

	Add(new CEditBox(hWnd, language, originalScreenResolution, name, iName, iInitializingText));
	}

//*****************************************************************************

void CInterface::Add_CheckBox(const wstring& iName, const vector<wstring>& iInitializingText)
	{
	if(Exist(iName))
		throw invalid_argument("CInterface::Add_CheckBox - Argument iName - Specified object already exist.");

	Add(new CCheckBox(hWnd, language, originalScreenResolution, name, iName, iInitializingText));
	}

//*****************************************************************************

void CInterface::Add_VerticalScrollBar(const wstring& iName, const vector<wstring>& iInitializingText)
	{
	if(Exist(iName))
		throw invalid_argument("CInterface::Add_VerticalScrollBar - Argument iName - Specified object already exist.");

	Add(new CVerticalScrollBar(hWnd, language, originalScreenResolution, name, iName, iInitializingText));
	}

//*****************************************************************************

void CInterface::Add_HorizontalScrollBar(const wstring& iName, const vector<wstring>& iInitializingText)
	{
	if(Exist(iName))
		throw invalid_argument("CInterface::Add_HorizontalScrollBar - Argument iName - Specified object already exist.");

	Add(new CHorizontalScrollBar(hWnd, language, originalScreenResolution, name, iName, iInitializingText));
	}

//*****************************************************************************

void CInterface::Add_TextBox(const wstring& iName, const vector<wstring>& iInitializingText)
	{
	if(Exist(iName))
		throw invalid_argument("CInterface::Add_TextBox - Argument iName - Specified object already exist.");

	Add(new CTextBox(hWnd, language, originalScreenResolution, name, iName, iInitializingText));
	}

//*****************************************************************************


bool CInterface::Exist(const wstring& iObjectName)
  	{
	return (objectMap.find(iObjectName) != objectMap.end()); 
	}

//*****************************************************************************

void CInterface::Remove(const wstring& iObjectName)
  	{
	for(unsigned i=0; i<objectVector.size(); i++)
		if(objectVector[i]->Name() == iObjectName)
			{
			delete objectVector[i];
			
			for(unsigned ii=i; ii<objectVector.size()-1; ii++)
				objectVector[ii] = objectVector[ii+1];

			objectVector.pop_back();

			//Erase from objectMap
			objectMap.erase(iObjectName);

			break;
			}
	}

//*****************************************************************************

void CInterface::GetObjectList(vector<wstring>& oObjectList)
  	{
	for(unsigned i=0; i<objectVector.size(); i++)
		oObjectList.push_back(objectVector[i]->Name());	
	}

//*****************************************************************************

void CInterface::IncreasePriority(const wstring& iObjectName)
  	{
	for(unsigned i=0; i<objectVector.size(); i++)
		if(objectVector[i]->Name() == iObjectName)
			{
			if(i == 0) return;
			
			CUIObject* tempObject = objectVector[i-1];
			objectVector[i-1] = objectVector[i];
			objectVector[i] = tempObject;

			break;
			}
	}

//*****************************************************************************

void CInterface::DecreasePriority(const wstring& iObjectName)
  	{
	for(unsigned i=0; i<objectVector.size(); i++)
		if(objectVector[i]->Name() == iObjectName)
			{
			if(i == objectVector.size() - 1) return;
			
			CUIObject* tempObject = objectVector[i+1];
			objectVector[i+1] = objectVector[i];
			objectVector[i] = tempObject;

			break;
			}
	}

//*****************************************************************************

void CInterface::GetInitializingText(vector<wstring>& oInitializingText)
  	{
	wostringstream os;
	os << L"Interface " << name;
	oInitializingText.push_back(os.str());
	oInitializingText.push_back(L"{");

	for(unsigned i=0; i<objectVector.size(); i++)
		objectVector[i]->GetInitializingText(oInitializingText);

	oInitializingText.push_back(L"}");
	}

//*****************************************************************************

void CInterface::SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
  	{
	screenResolution = iScreenResolution;

	for(unsigned i=0; i<objectVector.size(); i++)
		objectVector[i]->SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************

void CInterface::SetCallbackFunction(const wstring& iObjectName, const EUIEventType& iEventType, void (*iCallbackFunction)(const CUIEventInformation&))
  	{
	CUIObject* object = GetObject(iObjectName);

	if(object == NULL)
		throw invalid_argument("CInterface::SetCallbackFunction - Argument iObjectName - Specified object does not exist.");

	object->SetCallbackFunction(iEventType, iCallbackFunction);
	}

//*****************************************************************************

bool CInterface::GetProperty(const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty)
  	{
	CUIObject* object = GetObject(iObjectName);

	if(object == NULL)
		throw invalid_argument("CInterface::GetProperty - Argument iObjectName - Specified object does not exist.");

	return object->GetProperty(iProperty);
	}

//*****************************************************************************

int CInterface::GetProperty(const wstring& iObjectName, const EUIObjectProperty_Int& iProperty)
  	{
	CUIObject* object = GetObject(iObjectName);

	if(object == NULL)
		throw invalid_argument("CInterface::GetProperty - Argument iObjectName - Specified object does not exist.");

	return object->GetProperty(iProperty);
	}

//*****************************************************************************

float CInterface::GetProperty(const wstring& iObjectName, const EUIObjectProperty_Float& iProperty)
  	{
	CUIObject* object = GetObject(iObjectName);

	if(object == NULL)
		throw invalid_argument("CInterface::GetProperty - Argument iObjectName - Specified object does not exist.");

	return object->GetProperty(iProperty);
	}

//*****************************************************************************

wstring CInterface::GetProperty(const wstring& iObjectName, const EUIObjectProperty_String& iProperty)
  	{
	CUIObject* object = GetObject(iObjectName);

	if(object == NULL)
		throw invalid_argument("CInterface::GetProperty - Argument iObjectName - Specified object does not exist.");

	return object->GetProperty(iProperty);
	}

//*****************************************************************************

void CInterface::SetProperty(const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty, const bool& iValue)
  	{
	CUIObject* object = GetObject(iObjectName);

	if(object == NULL)
		throw invalid_argument("CInterface::SetProperty - Argument iObjectName - Specified object does not exist.");

	object->SetProperty(iProperty, iValue);
	}

//*****************************************************************************

void CInterface::SetProperty(const wstring& iObjectName, const EUIObjectProperty_Int& iProperty, const int& iValue)
  	{
	CUIObject* object = GetObject(iObjectName);

	if(object == NULL)
		throw invalid_argument("CInterface::SetProperty - Argument iObjectName - Specified object does not exist.");

	object->SetProperty(iProperty, iValue);
	}

//*****************************************************************************

void CInterface::SetProperty(const wstring& iObjectName, const EUIObjectProperty_Float& iProperty, const float& iValue)
  	{
	CUIObject* object = GetObject(iObjectName);

	if(object == NULL)
		throw invalid_argument("CInterface::SetProperty - Argument iObjectName - Specified object does not exist.");

	object->SetProperty(iProperty, iValue);
	}

//*****************************************************************************

void CInterface::SetProperty(const wstring& iObjectName, const EUIObjectProperty_String& iProperty, const wstring& iValue)
  	{
	CUIObject* object = GetObject(iObjectName);

	if(object == NULL)
		throw invalid_argument("CInterface::SetProperty - Argument iObjectName - Specified object does not exist.");

	object->SetProperty(iProperty, iValue);
	}

//*****************************************************************************

void CInterface::Load(const vector<wstring>& iInitializingText)
	{
	for(unsigned i = 0; i<iInitializingText.size(); i++)
		{
		if(iInitializingText[i].size() == 0)
			continue;

		wstring objectType;
		wstring objectName;
		wistringstream is(iInitializingText[i]);
		is >> objectType >> objectName;

		vector<wstring> initializingObjectText;

		i++;
		
		LoadObjectText(iInitializingText, i, initializingObjectText);

		if(objectType == L"Label")
			{
			Add_Label(objectName, initializingObjectText);
			continue;
			}

		if(objectType == L"Image")
			{
			Add_Image(objectName, initializingObjectText);
			continue;
			}

		if(objectType == L"CheckBox")
			{
			Add_CheckBox(objectName, initializingObjectText);
			continue;
			}

		if(objectType == L"EditBox")
			{
			Add_EditBox(objectName, initializingObjectText);
			continue;
			}

		if(objectType == L"VerticalScrollBar")
			{
			Add_VerticalScrollBar(objectName, initializingObjectText);
			continue;
			}

		if(objectType == L"HorizontalScrollBar")
			{
			Add_HorizontalScrollBar(objectName, initializingObjectText);
			continue;
			}

		if(objectType == L"TextBox")
			{
			Add_TextBox(objectName, initializingObjectText);
			continue;
			}

		throw CException("CInterface::Load", "Bad initializing text - unknown object type");
		}
	}

//*****************************************************************************

void CInterface::LoadObjectText(const vector<wstring>& iInitializingText, unsigned& ioCurrentLine, vector<wstring>& oInitializingObjectText)
	{
	if(iInitializingText[ioCurrentLine] != L"{")
		throw CException("CInterface::LoadObjectText", "Bad initializing text ( after object name must follow '{' )");

	ioCurrentLine++;

	bool endFound(false);

	for(; ioCurrentLine<iInitializingText.size(); ioCurrentLine++)
		{
		if(iInitializingText[ioCurrentLine].size() == 0)
			continue;

		if(iInitializingText[ioCurrentLine] == L"}")
			{
			endFound = true;
			break;
			}
		else
			oInitializingObjectText.push_back(iInitializingText[ioCurrentLine]);
		}

	if(endFound == false)
		throw CException("CInterface::LoadObjectText", "Bad initializing text ( after object initializing text must follow '}' )");		
	}

//*****************************************************************************

bool CInterface::GetFirstIntersection(const D3DXVECTOR2& iPosition, wstring& oIntersectedObjectName)
	{
	for(unsigned i=0; i<objectVector.size(); i++)
		if(objectVector[i]->Intersect(iPosition))
			{
			oIntersectedObjectName = objectVector[i]->Name();
			return true;
			}
	return false;
	}

//*****************************************************************************