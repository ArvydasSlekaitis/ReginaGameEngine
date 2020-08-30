/*
    CMessageManager.h - Contains class CMessageManager.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CMESSAGEMANAGER_H
#define REGINA_UI_CMESSAGEMANAGER_H


#include <vector>
#include <map>
#include <deque>
using namespace std;

#include <CMessageBox.h>
#include <CInputQuery.h>
#include <CQuestionBox.h>

namespace Regina
{

namespace UI
{

class CMessageManager
{
	wstring						language;
	D3DXVECTOR2					screenResolution;
	D3DXVECTOR2					originalScreenResolution;
	HWND						hWnd;

	map<wstring, CMessageBox*>	messageBoxTemplateMap;
	map<wstring, CInputQuery*>	inputQueryTemplateMap;
	map<wstring, CQuestionBox*> questionBoxTemplateMap;

	deque<CUIMessage*>			messageDeque;
	deque<wstring>				messageHeadersDeque;

	CMessageBox* GetNewMessageBox(const wstring& iTemplateName, const wstring& iHeader);
	CInputQuery* GetNewInputQuery(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer);
	CQuestionBox* GetNewQuestionBox(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer);

	CMessageBox* GetMessageBoxTemplate(const wstring& iTemplateName);
	CInputQuery* GetInputQueryTemplate(const wstring& iTemplateName);
	CQuestionBox* GetQuestionBoxTemplate(const wstring& iTemplateName);

	CUIObject*	 GetTemplate(const wstring& iTemplateName);

	void	LoadTemplateText(const vector<wstring>& iInitializingText, unsigned& ioCurrentLine, vector<wstring>& oInitializingTemplateText);

public:
	CMessageManager(HWND iHWnd, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iLanguage);
	virtual ~CMessageManager();

	void Render();
	void FrameMove(const float& iElapsedTime);
	bool MsgProc(UINT uMsg, WPARAM wParam);
	void Load(const vector<wstring>& iInitializingText);
	void SetScreenResolution(const D3DXVECTOR2& iScreenResolution);
	void GetInitializingText(vector<wstring>& oInitializingText);
	void Clear();

	bool MessageBox(const wstring& iTemplateName, const wstring& iHeader);
	bool InputQuery(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer);
	bool QuestionBox(const wstring& iTemplateName, const wstring& iHeader, wstring* oAnswer);

	void AddTemplate_MessageBox(const wstring& iTemplateName, const vector<wstring>& iInitializingScript);
	void AddTemplate_InputQuery(const wstring& iTemplateName, const vector<wstring>& iInitializingScript);
	void AddTemplate_QuestionBox(const wstring& iTemplateName, const vector<wstring>& iInitializingScript);

	void RemoveTemplate(const wstring& iTemplateName);

	void GetTemplateList_MessageBox(vector<wstring>& oTemplateList);
	void GetTemplateList_InputQuery(vector<wstring>& oTemplateList);
	void GetTemplateList_QuestionBox(vector<wstring>& oTemplateList);
	
	void SetCallbackFunction(const wstring& iTemplateName, const EUIEventType& iEventType, void (*iCallbackFunction)(const CUIEventInformation&));

	bool	GetProperty(const wstring& iTemplateName, const EUIObjectProperty_Bool& iProperty);
	int		GetProperty(const wstring& iTemplateName, const EUIObjectProperty_Int& iProperty);
	float	GetProperty(const wstring& iTemplateName, const EUIObjectProperty_Float& iProperty);
	wstring GetProperty(const wstring& iTemplateName, const EUIObjectProperty_String& iProperty);

	void	SetProperty(const wstring& iTemplateName, const EUIObjectProperty_Bool& iProperty, const bool& iValue);
	void	SetProperty(const wstring& iTemplateName, const EUIObjectProperty_Int& iProperty, const int& iValue);
	void	SetProperty(const wstring& iTemplateName, const EUIObjectProperty_Float& iProperty, const float& iValue);
	void	SetProperty(const wstring& iTemplateName, const EUIObjectProperty_String& iProperty, const wstring& iValue);

	D3DXVECTOR2 ScreenResolution()			const	{ return screenResolution; }
	D3DXVECTOR2 OriginalScreenResolution()	const	{ return originalScreenResolution; }
	wstring		Language()					const	{ return language; }
	unsigned	NumMessageInQuene()			const   { return messageDeque.size(); }
};

}

}

#endif 