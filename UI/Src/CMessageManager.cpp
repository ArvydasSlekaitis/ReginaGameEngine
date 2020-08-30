/*
    CMessageManager.cpp - Contains class CMessageManager implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CMessageManager.h>
using namespace Regina::UI;


//*****************************************************************************

CMessageManager::CMessageManager(HWND iHWnd, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iLanguage) : language(iLanguage), hWnd(iHWnd), screenResolution(iOriginalScreenResolution), originalScreenResolution(iOriginalScreenResolution)
	{
	}

//*****************************************************************************

CMessageManager::~CMessageManager()
	{
	Clear();
	}

//*****************************************************************************

CMessageBox* CMessageManager::GetNewMessageBox(const wstring& iTemplateName, const wstring& iHeader)
  	{
	CMessageBox* ret(NULL);
	CMessageBox* tTemplate = GetMessageBoxTemplate(iTemplateName);
	
	if(tTemplate!=NULL)
		{
		vector<wstring> initText;
		tTemplate->GetInitializingText(initText);
		
		assert(initText.size()>2);
		initText.erase(initText.begin());	// Remove MessageBox line
		initText.erase(initText.begin());	// Remove { symbol
		initText.erase(initText.end()-1);	// Remove } symbol


		ret = new CMessageBox(hWnd, language, originalScreenResolution, iTemplateName, initText);
		ret->SetProperty(e_UIObjectProperty_MessageText_Line, iHeader);
		ret->SetScreenResolution(screenResolution);
		}
	
	return ret;
	}

//*****************************************************************************

CInputQuery* CMessageManager::GetNewInputQuery(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer)
  	{
	assert(oAnswer != NULL && L"CMessageManager::GetNewInputQuery - oAnswer != NULL");

	CInputQuery* ret(NULL);
	CInputQuery* tTemplate = GetInputQueryTemplate(iTemplateName);
	
	if(tTemplate!=NULL)
		{
		vector<wstring> initText;
		tTemplate->GetInitializingText(initText);
		
		assert(initText.size()>2);
		initText.erase(initText.begin());	// Remove InputQuery line
		initText.erase(initText.begin());	// Remove { symbol
		initText.erase(initText.end()-1);	// Remove } symbol


		ret = new CInputQuery(hWnd, language,  originalScreenResolution, iTemplateName, oAnswer, initText);
		ret->SetProperty(e_UIObjectProperty_QuestionText_Line, iHeader);
		ret->SetScreenResolution(screenResolution);
		}
	
	return ret;
	}

//*****************************************************************************

CQuestionBox* CMessageManager::GetNewQuestionBox(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer)
  	{
	assert(oAnswer != NULL && L"CMessageManager::GetNewQuestionBox - oAnswer != NULL");

	CQuestionBox* ret(NULL);
	CQuestionBox* tTemplate = GetQuestionBoxTemplate(iTemplateName);
	
	if(tTemplate!=NULL)
		{
		vector<wstring> initText;
		tTemplate->GetInitializingText(initText);
		
		assert(initText.size()>2);
		initText.erase(initText.begin());	// Remove InputQuery line
		initText.erase(initText.begin());	// Remove { symbol
		initText.erase(initText.end()-1);	// Remove } symbol


		ret = new CQuestionBox(hWnd, language, originalScreenResolution, iTemplateName, oAnswer, initText);
		ret->SetProperty(e_UIObjectProperty_QuestionText_Line, iHeader);
		ret->SetScreenResolution(screenResolution);
		}
	
	return ret;
	}

//*****************************************************************************

CMessageBox* CMessageManager::GetMessageBoxTemplate(const wstring& iTemplateName)
	{
	map<wstring, CMessageBox*>::iterator it = messageBoxTemplateMap.find(iTemplateName);
	if(it!=messageBoxTemplateMap.end())
		return it->second;
	else
		return NULL;
	}

//*****************************************************************************

CInputQuery* CMessageManager::GetInputQueryTemplate(const wstring& iTemplateName)
	{
	map<wstring, CInputQuery*>::iterator it = inputQueryTemplateMap.find(iTemplateName);
	if(it!=inputQueryTemplateMap.end())
		return it->second;
	else
		return NULL;
	}

//*****************************************************************************

CQuestionBox* CMessageManager::GetQuestionBoxTemplate(const wstring& iTemplateName)
	{
	map<wstring, CQuestionBox*>::iterator it = questionBoxTemplateMap.find(iTemplateName);
	if(it!=questionBoxTemplateMap.end())
		return it->second;
	else
		return NULL;
	}

//*****************************************************************************

CUIObject* CMessageManager::GetTemplate(const wstring& iTemplateName)
	{
	CUIObject* rTemplate(NULL);
	rTemplate = GetMessageBoxTemplate(iTemplateName);

	if(rTemplate != NULL)
		return rTemplate;

	rTemplate = GetInputQueryTemplate(iTemplateName);

	if(rTemplate != NULL)
		return rTemplate;

	rTemplate = GetQuestionBoxTemplate(iTemplateName);

	if(rTemplate != NULL)
		return rTemplate;
	}

//*****************************************************************************

void CMessageManager::Load(const vector<wstring>& iInitializingText)
	{
	for(unsigned i = 0; i<iInitializingText.size(); i++)
		{
		if(iInitializingText[i].size() == 0)
			continue;

		wstring templateType;
		wstring templateName;
		wistringstream is(iInitializingText[i]);
		is >> templateType >> templateName;

		vector<wstring> initializingTemplateText;

		i++;
		
		LoadTemplateText(iInitializingText, i, initializingTemplateText);

		if(templateType == L"MessageBox")
			{
			AddTemplate_MessageBox(templateName, initializingTemplateText);
			continue;
			}

		if(templateType == L"InputQuery")
			{
			AddTemplate_InputQuery(templateName, initializingTemplateText);
			continue;
			}

		if(templateType == L"QuestionBox")
			{
			AddTemplate_QuestionBox(templateName, initializingTemplateText);
			continue;
			}

		throw CException("CMessageManager::Load", "Bad initializing text - unknown template type");
		}
	}

//*****************************************************************************

void CMessageManager::LoadTemplateText(const vector<wstring>& iInitializingText, unsigned& ioCurrentLine, vector<wstring>& oInitializingTemplateText)
	{
	if(iInitializingText[ioCurrentLine] != L"{")
		throw CException("CMessageManager::LoadInterfaceText", "Bad initializing text ( after template name must follow '{' )");

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
				oInitializingTemplateText.push_back(iInitializingText[ioCurrentLine]);
			}
		else
			oInitializingTemplateText.push_back(iInitializingText[ioCurrentLine]);
		}

	if(endFound == false)
		throw CException("CMessageManager::LoadInterfaceText", "Bad initializing text ( after template initializing text must follow '}' )");		
	}

//*****************************************************************************

void CMessageManager::Render()
	{
	if(messageDeque.size() > 0)
		messageDeque[0]->Render();
	}

//*****************************************************************************

void CMessageManager::FrameMove(const float& iElapsedTime)
  	{
	if(messageDeque.size() > 0)
		if(messageDeque[0]->State() == CUIMessage::E_UIMessageState_Terminate)
			{
			delete messageDeque[0];
			messageDeque.pop_front();
			messageHeadersDeque.pop_front();
			} 

	if(messageDeque.size() > 0)
		messageDeque[0]->FrameMove(iElapsedTime);
	}

//*****************************************************************************

bool CMessageManager::MsgProc(UINT uMsg, WPARAM wParam)
  	{
	bool ret(false);

	if(messageDeque.size() > 0)
		ret = messageDeque[0]->MsgProc(uMsg, wParam);

	return ret;
	}

//*****************************************************************************

void CMessageManager::SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
  	{
	screenResolution = iScreenResolution;
	for(unsigned i=0; i<messageDeque.size(); i++)
		messageDeque[i]->SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************

void CMessageManager::GetInitializingText(vector<wstring>& oInitializingText)
	{
	wostringstream os;
	os << L"MessageManager";
	oInitializingText.push_back(os.str());
	oInitializingText.push_back(L"{");

	map<wstring, CMessageBox*>::iterator it_messageBox = messageBoxTemplateMap.begin();
	while(it_messageBox != messageBoxTemplateMap.end())
		{
		it_messageBox->second->GetInitializingText(oInitializingText);
		it_messageBox++;
		}

	map<wstring, CInputQuery*>::iterator it_inputQuery = inputQueryTemplateMap.begin();
	while(it_inputQuery != inputQueryTemplateMap.end())
		{
		it_inputQuery->second->GetInitializingText(oInitializingText);
		it_inputQuery++;
		}

	map<wstring, CQuestionBox*>::iterator it_QuestionBox = questionBoxTemplateMap.begin();
	while(it_QuestionBox != questionBoxTemplateMap.end())
		{
		it_QuestionBox->second->GetInitializingText(oInitializingText);
		it_QuestionBox++;
		}

	oInitializingText.push_back(L"}");
	}

//*****************************************************************************

void CMessageManager::Clear()
	{
	map<wstring, CMessageBox*>::iterator it_messageBox = messageBoxTemplateMap.begin();
	while(it_messageBox != messageBoxTemplateMap.end())
		{
		delete it_messageBox->second;
		it_messageBox++;
		}

	for(unsigned i = 0; i<messageDeque.size(); i++)
		delete messageDeque[i];

	map<wstring, CInputQuery*>::iterator it_inputQuery = inputQueryTemplateMap.begin();
	while(it_inputQuery != inputQueryTemplateMap.end())
		{
		delete it_inputQuery->second;
		it_inputQuery++;
		}

	map<wstring, CQuestionBox*>::iterator it_QuestionBox = questionBoxTemplateMap.begin();
	while(it_QuestionBox != questionBoxTemplateMap.end())
		{
		delete it_QuestionBox->second;
		it_QuestionBox++;
		}

	messageBoxTemplateMap.clear();
	inputQueryTemplateMap.clear();
	questionBoxTemplateMap.clear();

	messageDeque.clear();
	messageHeadersDeque.clear();
	}

//*****************************************************************************

bool CMessageManager::MessageBox(const wstring& iTemplateName, const wstring& iHeader)
  	{
	int pos(-1);

	//Search for specified header
	for(unsigned i = 0; i<messageHeadersDeque.size(); i++)
		if(messageHeadersDeque[i] == iHeader)
			{
			pos = i;
			break;
			}


	//If this is top message
	if(pos == 0)
		{
		if(messageDeque[pos]->State() == CUIMessage::E_UIMessageState_Terminate)
			{
			delete messageDeque[pos];
			messageDeque.pop_front();
			messageHeadersDeque.pop_front();

			return true;
			}
		}

	//If message with defined header does not exists, create new one from template
	if(pos == -1)
		{
		CMessageBox* tMessageBox = GetNewMessageBox(iTemplateName, iHeader);

		if(tMessageBox == NULL)
			throw invalid_argument("CMessageManager::MessageBox - Argument iTemplateName - Specified MessageBox template does not exist.");

		messageHeadersDeque.push_back(iHeader);
		messageDeque.push_back(tMessageBox);
		}


	return false;
	}

//*****************************************************************************

bool CMessageManager::InputQuery(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer)
  	{
	if(oAnswer == NULL)
		throw invalid_argument("CMessageManager::InputQuery - Argument oAnswer == NULL");

	int pos(-1);

	//Search for specified header
	for(unsigned i = 0; i<messageHeadersDeque.size(); i++)
		if(messageHeadersDeque[i] == iHeader)
			{
			pos = i;
			break;
			}


	//If this is top message
	if(pos == 0)
		{
		if(messageDeque[pos]->State() == CUIMessage::E_UIMessageState_Terminate)
			{
			delete messageDeque[pos];
			messageDeque.pop_front();
			messageHeadersDeque.pop_front();

			return true;
			}
		}

	//If message with defined header does not exists, create new one from template
	if(pos == -1)
		{
		CInputQuery* tInputQuery = GetNewInputQuery(iTemplateName, iHeader, oAnswer);

		if(tInputQuery == NULL)
			throw invalid_argument("CMessageManager::InputQuery - Argument iTemplateName - Specified InputQuery template does not exist.");

		messageHeadersDeque.push_back(iHeader);
		messageDeque.push_back(tInputQuery);
		}


	return false;
	}

//*****************************************************************************

bool CMessageManager::QuestionBox(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer)
  	{
	if(oAnswer == NULL)
		throw invalid_argument("CMessageManager::QuestionBox - Argument oAnswer == NULL");

	int pos(-1);

	//Search for specified header
	for(unsigned i = 0; i<messageHeadersDeque.size(); i++)
		if(messageHeadersDeque[i] == iHeader)
			{
			pos = i;
			break;
			}


	//If this is top message
	if(pos == 0)
		{
		if(messageDeque[pos]->State() == CUIMessage::E_UIMessageState_Terminate)
			{
			delete messageDeque[pos];
			messageDeque.pop_front();
			messageHeadersDeque.pop_front();

			return true;
			}
		}

	//If message with defined header does not exists, create new one from template
	if(pos == -1)
		{
		CQuestionBox* tQuestionBox = GetNewQuestionBox(iTemplateName, iHeader, oAnswer);

		if(tQuestionBox == NULL)
			throw invalid_argument("CMessageManager::InputQuery - Argument iTemplateName - Specified QuestionBox template does not exist.");

		messageHeadersDeque.push_back(iHeader);
		messageDeque.push_back(tQuestionBox);
		}


	return false;
	}

//*****************************************************************************

void CMessageManager::AddTemplate_MessageBox(const wstring& iTemplateName, const vector<wstring>& iInitializingScript)
	{
	if(messageBoxTemplateMap.find(iTemplateName) == messageBoxTemplateMap.end())
		{
		CMessageBox* tMessage(NULL);

		//try catch && log
		tMessage = new CMessageBox(hWnd, language, originalScreenResolution, iTemplateName, iInitializingScript);

		messageBoxTemplateMap.insert(make_pair(iTemplateName, tMessage));
		}
	else
		throw invalid_argument("CMessageManager::AddTemplate_MessageBox - Argument iTemplateName - Specified template already exist.");
	}

//*****************************************************************************

void CMessageManager::AddTemplate_InputQuery(const wstring& iTemplateName, const vector<wstring>& iInitializingScript)
	{
	if(inputQueryTemplateMap.find(iTemplateName) == inputQueryTemplateMap.end())
		{
		CInputQuery* tMessage(NULL);

		//try catch && log
		tMessage = new CInputQuery(hWnd, language, originalScreenResolution, iTemplateName, NULL, iInitializingScript);

		inputQueryTemplateMap.insert(make_pair(iTemplateName, tMessage));
		}
	else
		throw invalid_argument("CMessageManager::AddTemplate_InputQuery - Argument iTemplateName - Specified template already exist.");
	}

//*****************************************************************************

void CMessageManager::AddTemplate_QuestionBox(const wstring& iTemplateName, const vector<wstring>& iInitializingScript)
	{
	if(questionBoxTemplateMap.find(iTemplateName) == questionBoxTemplateMap.end())
		{
		CQuestionBox* tMessage(NULL);

		//try catch && log
		tMessage = new CQuestionBox(hWnd, language, originalScreenResolution, iTemplateName, NULL, iInitializingScript);

		questionBoxTemplateMap.insert(make_pair(iTemplateName, tMessage));
		}
	else
		throw invalid_argument("CMessageManager::AddTemplate_QuestionBox - Argument iTemplateName - Specified template already exist.");
	}

//*****************************************************************************

void CMessageManager::RemoveTemplate(const wstring& iTemplateName)
  	{
	map<wstring, CMessageBox*>::iterator it_messageBox = messageBoxTemplateMap.find(iTemplateName);
	if(it_messageBox != messageBoxTemplateMap.end())
		{
		delete it_messageBox->second;
		messageBoxTemplateMap.erase(it_messageBox);
		return;
		}

	map<wstring, CInputQuery*>::iterator it_inputQuery = inputQueryTemplateMap.find(iTemplateName);
	if(it_inputQuery != inputQueryTemplateMap.end())
		{
		delete it_inputQuery->second;
		inputQueryTemplateMap.erase(it_inputQuery);
		return;
		}


	map<wstring, CQuestionBox*>::iterator it_questionBox = questionBoxTemplateMap.find(iTemplateName);
	if(it_questionBox != questionBoxTemplateMap.end())
		{
		delete it_questionBox->second;
		questionBoxTemplateMap.erase(it_questionBox);
		return;
		}
	}

//*****************************************************************************

void CMessageManager::GetTemplateList_MessageBox(vector<wstring>& oTemplateList)
  	{
	map<wstring, CMessageBox*>::iterator it_messageBox = messageBoxTemplateMap.begin();
	while(it_messageBox != messageBoxTemplateMap.end())
		{
		oTemplateList.push_back(it_messageBox->second->Name());
		it_messageBox++;
		}
	}

//*****************************************************************************

void CMessageManager::GetTemplateList_InputQuery(vector<wstring>& oTemplateList)
  	{
	map<wstring, CInputQuery*>::iterator it_inputQuery = inputQueryTemplateMap.begin();
	while(it_inputQuery != inputQueryTemplateMap.end())
		{
		oTemplateList.push_back(it_inputQuery->second->Name());
		it_inputQuery++;
		}
	}

//*****************************************************************************

void CMessageManager::GetTemplateList_QuestionBox(vector<wstring>& oTemplateList)
  	{
	map<wstring, CQuestionBox*>::iterator it_questionBox = questionBoxTemplateMap.begin();
	while(it_questionBox != questionBoxTemplateMap.end())
		{
		oTemplateList.push_back(it_questionBox->second->Name());
		it_questionBox++;
		}
	}

//*****************************************************************************

void CMessageManager::SetCallbackFunction(const wstring& iTemplateName, const EUIEventType& iEventType, void (*iCallbackFunction)(const CUIEventInformation&))
	{
	CUIObject* object = GetTemplate(iTemplateName);

	if(object == NULL)
		throw invalid_argument("CMessageManager::SetCallbackFunction - Argument iTemplateName - Specified template does not exist.");

	object->SetCallbackFunction(iEventType, iCallbackFunction);
	}

//*****************************************************************************

int CMessageManager::GetProperty(const wstring& iTemplateName, const EUIObjectProperty_Int& iProperty)
  	{
	CUIObject* object = GetTemplate(iTemplateName);

	if(object == NULL)
		throw invalid_argument("CMessageManager::GetProperty - Argument iTemplateName - Specified template does not exist.");

	return object->GetProperty(iProperty);
	}

//*****************************************************************************

bool CMessageManager::GetProperty(const wstring& iTemplateName, const EUIObjectProperty_Bool& iProperty)
  	{
	CUIObject* object = GetTemplate(iTemplateName);

	if(object == NULL)
		throw invalid_argument("CMessageManager::GetProperty - Argument iTemplateName - Specified template does not exist.");

	return object->GetProperty(iProperty);
	}

//*****************************************************************************

float CMessageManager::GetProperty(const wstring& iTemplateName, const EUIObjectProperty_Float& iProperty)
  	{
	CUIObject* object = GetTemplate(iTemplateName);

	if(object == NULL)
		throw invalid_argument("CMessageManager::GetProperty - Argument iTemplateName - Specified template does not exist.");

	return object->GetProperty(iProperty);
	}

//*****************************************************************************

wstring CMessageManager::GetProperty(const wstring& iTemplateName, const EUIObjectProperty_String& iProperty)
  	{
	CUIObject* object = GetTemplate(iTemplateName);

	if(object == NULL)
		throw invalid_argument("CMessageManager::GetProperty - Argument iTemplateName - Specified template does not exist.");

	return object->GetProperty(iProperty);
	}

//*****************************************************************************

void CMessageManager::SetProperty(const wstring& iTemplateName, const EUIObjectProperty_Bool& iProperty, const bool& iValue)
  	{
	CUIObject* object = GetTemplate(iTemplateName);

	if(object == NULL)
		throw invalid_argument("CMessageManager::SetProperty - Argument iTemplateName - Specified template does not exist.");

	object->SetProperty(iProperty, iValue);
	}

//*****************************************************************************

void CMessageManager::SetProperty(const wstring& iTemplateName, const EUIObjectProperty_Int& iProperty, const int& iValue)
  	{
	CUIObject* object = GetTemplate(iTemplateName);

	if(object == NULL)
		throw invalid_argument("CMessageManager::SetProperty - Argument iTemplateName - Specified template does not exist.");

	object->SetProperty(iProperty, iValue);
	}

//*****************************************************************************

void CMessageManager::SetProperty(const wstring& iTemplateName, const EUIObjectProperty_String& iProperty, const wstring& iValue)
  	{
	CUIObject* object = GetTemplate(iTemplateName);

	if(object == NULL)
		throw invalid_argument("CMessageManager::SetProperty - Argument iTemplateName - Specified template does not exist.");

	object->SetProperty(iProperty, iValue);
	}

//*****************************************************************************

void CMessageManager::SetProperty(const wstring& iTemplateName, const EUIObjectProperty_Float& iProperty, const float& iValue)
  	{
	CUIObject* object = GetTemplate(iTemplateName);

	if(object == NULL)
		throw invalid_argument("CMessageManager::SetProperty - Argument iTemplateName - Specified template does not exist.");

	object->SetProperty(iProperty, iValue);
	}

//******************************************************************************/