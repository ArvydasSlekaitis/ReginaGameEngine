/*
    CInterface.h - Contains class CInterface.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CINTERFACE_H
#define REGINA_UI_CINTERFACE_H

#include <map>
#include <vector>
using namespace std;

#include <CUIObject.h>
#include <CLabel.h>
#include <CImage.h>
#include <CEditBox.h>
#include <CCheckBox.h>
#include <CVerticalScrollBar.h>
#include <CHorizontalScrollBar.h>
#include <CTextBox.h>
#include <CException.h>

namespace Regina
{

namespace UI
{

class CInterface
{
	wstring						name;
	wstring						language;
	D3DXVECTOR2					screenResolution;
	D3DXVECTOR2					originalScreenResolution;
	HWND						hWnd;

	vector<CUIObject*>			objectVector;
	map<wstring, CUIObject*>	objectMap;

	void		Add(CUIObject* iObject);
	CUIObject*	GetObject(const wstring& iObjectName);
	void		Load(const vector<wstring>& iInitializingText);
	void		LoadObjectText(const vector<wstring>& iInitializingText, unsigned& ioCurrentLine, vector<wstring>& oInitializingObjectText);

public:
	CInterface(HWND iHWnd, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, const wstring& iLanguage, const vector<wstring>& iInitializingText);
	virtual ~CInterface();

	void FrameMove(const float& iElapsedTime);
	void Render();
	bool MsgProc(UINT uMsg, WPARAM wParam);
	void Clear();


	void Add_Label(const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_Image(const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_EditBox(const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_CheckBox(const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_VerticalScrollBar(const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_HorizontalScrollBar(const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_TextBox(const wstring& iName, const vector<wstring>& iInitializingText);

	bool Exist(const wstring& iObjectName);
	void Remove(const wstring& iObjectName);

	void GetObjectList(vector<wstring>& oObjectList);
	void IncreasePriority(const wstring& iObjectName);
	void DecreasePriority(const wstring& iObjectName);

	void SetScreenResolution(const D3DXVECTOR2& iScreenResolution);
	void GetInitializingText(vector<wstring>& oInitializingText);
	void DeselectAll();
	bool GetFirstIntersection(const D3DXVECTOR2& iPosition, wstring& oIntersectedObjectName);  // position in current resolution

	void SetCallbackFunction(const wstring& iObjectName, const EUIEventType& iEventType, void (*iCallbackFunction)(const CUIEventInformation&));

	bool	GetProperty(const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty);
	int		GetProperty(const wstring& iObjectName, const EUIObjectProperty_Int& iProperty);
	float	GetProperty(const wstring& iObjectName, const EUIObjectProperty_Float& iProperty);
	wstring GetProperty(const wstring& iObjectName, const EUIObjectProperty_String& iProperty);

	void	SetProperty(const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty, const bool& iValue);
	void	SetProperty(const wstring& iObjectName, const EUIObjectProperty_Int& iProperty, const int& iValue);
	void	SetProperty(const wstring& iObjectName, const EUIObjectProperty_Float& iProperty, const float& iValue);
	void	SetProperty(const wstring& iObjectName, const EUIObjectProperty_String& iProperty, const wstring& iValue);

	unsigned	Size()						const	{ return objectVector.size(); }
	wstring		Name()						const	{ return name; }
	wstring		Language()					const	{ return language; }
	D3DXVECTOR2 ScreenResolution()			const	{ return screenResolution; }
	D3DXVECTOR2 OriginalScreenResolution()	const 	{ return originalScreenResolution; }
};

}

}

#endif 