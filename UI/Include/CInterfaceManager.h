/*
    CInterfaceManager.h - Contains class CInterfaceManager.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CINTERFACEMANAGER_H
#define REGINA_UI_CINTERFACEMANAGER_H

#include <map>
#include <vector>
using namespace std;

#include <CInterface.h>


namespace Regina
{

namespace UI
{

class CInterfaceManager
{
	wstring						language;
	D3DXVECTOR2					screenResolution;
	D3DXVECTOR2					originalScreenResolution;
	HWND						hWnd;

	vector<CInterface*>			interfaceVector;
	map<wstring, CInterface*>	interfaceMap;

	vector<CInterface*>			interfaceRunning;

	void		AddInterface(CInterface* iInterface);
	CInterface*	GetInterface(const wstring& iInterfaceName);
	void		LoadInterfaceText(const vector<wstring>& iInitializingText, unsigned& ioCurrentLine, vector<wstring>& oInitializingInterfaceText);

public:
	CInterfaceManager(HWND iHWnd, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iLanguage);
	virtual ~CInterfaceManager();

	void FrameMove(const float& iElapsedTime);
	void Render(const wstring& iInterfaceName);
	bool MsgProc(UINT uMsg, WPARAM wParam);
	void Load(const vector<wstring>& iInitializingText);
	void Clear();
	void ClearRenderList();

	void AddInterface(const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iName, const wstring& iLanguage, const vector<wstring>& iInitializingText);
	void RemoveInterface(const wstring& iInterfaceName);
	bool ExistInterface(const wstring& iInterfaceName);
	void GetInterfaceList(vector<wstring>& oInterfaceListList);

	void Add_Label(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_Image(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_EditBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_CheckBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_VerticalScrollBar(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_HorizontalScrollBar(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);
	void Add_TextBox(const wstring& iInterfaceName, const wstring& iName, const vector<wstring>& iInitializingText);

	bool ExistObject(const wstring& iInterfaceName, const wstring& iObjectName);
	void RemoveObject(const wstring& iInterfaceName, const wstring& iObjectName);

	void GetObjectList(const wstring& iInterfaceName, vector<wstring>& oObjectList);
	void IncreaseObjectPriority(const wstring& iInterfaceName, const wstring& iObjectName);
	void DecreaseObjectPriority(const wstring& iInterfaceName, const wstring& iObjectName);

	void SetScreenResolution(const D3DXVECTOR2& iScreenResolution);
	void GetInitializingText(vector<wstring>& oInitializingText);
	void DeselectAll();
	bool GetFirstIntersection(const wstring& iInterfaceName, const D3DXVECTOR2& iPosition, wstring& oIntersectedObjectName);  // position in current resolution

	void SetCallbackFunction(const wstring& iInterfaceName, const wstring& iObjectName, const EUIEventType& iEventType, void (*iCallbackFunction)(const CUIEventInformation&));

	bool	GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty);
	int		GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Int& iProperty);
	float	GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Float& iProperty);
	wstring GetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_String& iProperty);

	void	SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Bool& iProperty, const bool& iValue);
	void	SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Int& iProperty, const int& iValue);
	void	SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_Float& iProperty, const float& iValue);
	void	SetProperty(const wstring& iInterfaceName, const wstring& iObjectName, const EUIObjectProperty_String& iProperty, const wstring& iValue);

	wstring		Language()					const	{ return language; }
	D3DXVECTOR2 ScreenResolution()			const	{ return screenResolution; }
	D3DXVECTOR2 OriginalScreenResolution()	const 	{ return originalScreenResolution; }
	unsigned	InterfaceCount()			const	{ return interfaceVector.size(); }

	unsigned	ObjectCount(const wstring& iInterfaceName);
};

}

}

#endif 