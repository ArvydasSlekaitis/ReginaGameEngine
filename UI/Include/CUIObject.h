/*
    CUIObject.h - Contains class CUIObject.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CUIOBJECT
#define REGINA_UI_CUIOBJECT

#include <d3dx9.h>

#include <CFontManager.h>
#include <CTextureManager.h>
#include <EUIObjectType.h>
#include <EUIEventType.h>
#include <CUIEventInformation.h>
#include <EUIObjectProperty.h>
#include <Functions_UI.h>

namespace Regina
{

namespace UI
{

class CUIObject
{
	wstring			language;
	wstring			name;
	wstring			interfaceName;
	EUIObjectType	type;
	bool			shiftPressed;	// Remember if shift button was pressed ( for distinction between upper/lower case )

	void (*callbackFunction[DUIEventCount])(const CUIEventInformation&);	
		
	void UpdateTime(const float& iElapsedTime);

	wchar_t GetKeyChar(WPARAM wParam);

protected:
	HWND			hWnd;
	float			elapsedTime;
	float			time;
	bool			visible;
	bool			active;
	D3DXVECTOR2		screenResolution;
	D3DXVECTOR2		originalScreenResolution;

	virtual void On_FrameMove() {}
	virtual void On_Render() {}
	virtual bool On_LeftClick(const D3DXVECTOR2& iCursorPosition) { return false; }
	virtual bool On_RightClick(const D3DXVECTOR2& iCursorPosition) { return false; }
	virtual bool On_KeyDown(const wchar_t& iKey) { return false; }
	virtual bool On_KeyUp(const wchar_t& iKey) { return false; }
	virtual void On_SetScreenResolution(const D3DXVECTOR2& iScreenResolution) {}

	void CallCallbackFunction(const EUIEventType& iEventType);

public:
	virtual ~CUIObject();
	CUIObject(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const EUIObjectType& iObjectType);

	void FrameMove(const float& iElapsedTime);
	void Render();	
	bool MsgProc(UINT uMsg, WPARAM wParam);
	void SetScreenResolution(const D3DXVECTOR2& iScreenResolution);
	void SetCallbackFunction(const EUIEventType& iEventType, void (*iCallbackFunction)(const CUIEventInformation&));

	virtual void	GetInitializingText(vector<wstring>& oScriptText) =0;
	virtual bool	Intersect(const D3DXVECTOR2& iPosition) { return false; };

	virtual bool	GetProperty(const EUIObjectProperty_Bool& iProperty) = 0;
	virtual int		GetProperty(const EUIObjectProperty_Int& iProperty) = 0;
	virtual float	GetProperty(const EUIObjectProperty_Float& iProperty) = 0;
	virtual wstring	GetProperty(const EUIObjectProperty_String& iProperty) = 0;

	virtual void	SetProperty(const EUIObjectProperty_Bool& iProperty, const bool& iValue) = 0;
	virtual void	SetProperty(const EUIObjectProperty_Int& iProperty, const int& iValue) = 0;
	virtual void	SetProperty(const EUIObjectProperty_Float& iProperty, const float& iValue) = 0;
	virtual void	SetProperty(const EUIObjectProperty_String& iProperty, const wstring& iValue) = 0;

	wstring			Language()					const { return language; }
	wstring			Name()						const { return name; }
	wstring			InterfaceName()				const { return interfaceName; }
	EUIObjectType	Type()						const { return type; }
	D3DXVECTOR2		ScreenResolution()			const { return screenResolution; }
	D3DXVECTOR2		OriginalScreenResolution()	const { return originalScreenResolution; }
	bool			Visible()					const { return visible;}
	bool			Active()					const { return active; }
};

}

}
#endif

