/*
    CUIManager.h - Contains class CUIManager.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CUIMANAGER
#define REGINA_CUIMANAGER

#include <CUI.h>

namespace Regina
{

namespace UI
{


class CUIManager : public CUI
{
public:
	CUIManager(HWND iHWnd, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iLanguage, const wstring iName = L"");
	virtual ~CUIManager();

	void	Save(const wstring& iFileName);

	void	Add_Interface(const wstring& iName, const wstring& iLanguage, const vector<wstring>& iInitializingText);
	void	RemoveInterface(const wstring& iInterfaceName);
	bool	ExistInterface(const wstring& iInterfaceName);

	void	GetInterfaceList(vector<wstring>& oInterfaceList);

	void	Add_Label(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void	Add_Image(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void	Add_EditBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void	Add_CheckBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void	Add_VerticalScrollBar(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void	Add_HorizontalScrollBar(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void	Add_TextBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);

	bool	ExistObject(const wstring& iInterfaceName, const wstring& iObjectName);
	void	RemoveObject(const wstring& iInterfaceName, const wstring& iObjectName);
	void	GetObjectList(const wstring& iInterfaceName, vector<wstring>& oObjectList);
	void	IncreaseObjectPriority(const wstring& iInterfaceName, const wstring& iObjectName);
	void	DecreaseObjectPriority(const wstring& iInterfaceName, const wstring& iObjectName);

	bool	GetFirstIntersection(const wstring& iInterfaceName, const D3DXVECTOR2& iPosition, wstring& oIntersectedObjectName);  // position in current resolution

	void	Add_MessageTemplate_MessageBox(const wstring& iTemplateName, const vector<wstring>& iInitializingScript);
	void	Add_MessageTemplate_InputQuery(const wstring& iTemplateName, const vector<wstring>& iInitializingScript);
	void	Add_MessageTemplate_QuestionBox(const wstring& iTemplateName, const vector<wstring>& iInitializingScript);
	void	RemoveMessageTemplate(const wstring& iTemplateName);

	void	GetMessageTemplateList_MessageBox(vector<wstring>& oTemplateList);
	void	GetMessageTemplateList_InputQuery(vector<wstring>& oTemplateList);
	void	GetMessageTemplateList_QuestionBox(vector<wstring>& oTemplateList);

	unsigned	InterfaceCount() const;
	unsigned	ObjectCount(const wstring& iInterfaceName);
};

}

}

#endif 