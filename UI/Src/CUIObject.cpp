/*
    CUIObject.cpp - Contains class CUIObject implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CUIObject.h>
using namespace Regina::UI;


//*****************************************************************************

CUIObject::~CUIObject()
	{
	}

//*****************************************************************************

CUIObject::CUIObject(HWND iHWnd, const wstring& iLanguage, const D3DXVECTOR2& iOriginalScreenResolution, const wstring& iInterfaceName, const wstring& iName, const EUIObjectType& iObjectType) : name(iName), elapsedTime(0), time(0), screenResolution(iOriginalScreenResolution), originalScreenResolution(iOriginalScreenResolution), interfaceName(iInterfaceName), type(iObjectType), hWnd(iHWnd), visible(true), active(true), shiftPressed(false), language(iLanguage)
  	{
	for(unsigned i=0; i<DUIEventCount; i++)
		callbackFunction[i] = NULL;
	}

//*****************************************************************************

void CUIObject::UpdateTime(const float& iElapsedTime)
  	{
	elapsedTime = iElapsedTime;
	time += iElapsedTime;
	}

//*****************************************************************************

void CUIObject::SetScreenResolution(const D3DXVECTOR2& iScreenResolution)
  	{
	screenResolution = iScreenResolution;
	On_SetScreenResolution(iScreenResolution);
	}

//*****************************************************************************

void CUIObject::FrameMove(const float& iElapsedTime)
  	{
	UpdateTime(iElapsedTime);
	if(Active() == true)
		On_FrameMove();
	}

//*****************************************************************************

void CUIObject::Render()
  	{
	if(Visible() == true)
		On_Render();
	}

//*****************************************************************************

bool CUIObject::MsgProc(UINT uMsg, WPARAM wParam)
	{
	bool ret(false);

	if(Active() == true)
		{
		switch(uMsg)
			{
			case WM_KEYDOWN:		if(wParam == VK_SHIFT)
										shiftPressed = true;
				
									if(On_KeyDown(GetKeyChar(wParam)) == true) ret = true;
									break;

			case WM_KEYUP:			if(wParam == VK_SHIFT)
										shiftPressed = false;

									if(On_KeyUp(wParam) == true) ret = true;
									break;

			case WM_LBUTTONDOWN:	
			case WM_LBUTTONDBLCLK:	if(On_LeftClick(Cursor_Position(hWnd)) == true) ret = true;
									break;

			case WM_RBUTTONDOWN:
			case WM_RBUTTONDBLCLK:	if(On_RightClick(Cursor_Position(hWnd)) == true) ret = true;
									break;
							
			}
		}

	return ret;
	}

//*****************************************************************************

void CUIObject::SetCallbackFunction(const EUIEventType& iEventType, void (*iCallbackFunction)(const CUIEventInformation&))
	{
	if(iEventType >= DUIEventCount || iEventType < 0)
		throw invalid_argument("CUIObject::SetCallbackFunction - Argument iEventType is not valid");

	callbackFunction[iEventType] = iCallbackFunction;
	}

//*****************************************************************************

void CUIObject::CallCallbackFunction(const EUIEventType& iEventType)
	{
	if(Active() == true)
		if(callbackFunction[iEventType]!=NULL)
			callbackFunction[iEventType](CUIEventInformation(iEventType, Type(), InterfaceName(), Name()));
	}

//*****************************************************************************

wchar_t CUIObject::GetKeyChar(WPARAM wParam)
	{
	if(wParam >= 'A' && wParam <= 'Z')
		{
		if(shiftPressed == false)										
			return wParam + 32;
		else
			return wParam;
		}

	if(wParam >= '0' && wParam <= '9')
		return wParam;
		
	if(wParam >= 0x60 && wParam <= 0x69) //Remap num pad values
										{
										switch(wParam)
											{
											case VK_NUMPAD0: return '0';
											case VK_NUMPAD1: return '1';
											case VK_NUMPAD2: return '2';
											case VK_NUMPAD3: return '3';
											case VK_NUMPAD4: return '4';
											case VK_NUMPAD5: return '5';
											case VK_NUMPAD6: return '6';
											case VK_NUMPAD7: return '7';
											case VK_NUMPAD8: return '8';
											case VK_NUMPAD9: return '9';
											}
										}	

	switch(wParam)
		{
		case VK_MULTIPLY:	return '*';
		case VK_ADD:		return '+';
		case VK_SUBTRACT:	return '-';
		case VK_DECIMAL:	return '.';
		case VK_DIVIDE:		return '/';
		case VK_SPACE:		return ' ';
		case VK_OEM_PLUS:	return '+';
		case VK_OEM_COMMA:	return ',';
		case VK_OEM_MINUS:	return '-';
		case VK_OEM_PERIOD:	return '.';	
		}

	if(language == L"English")
		{
		switch(wParam)
			{
			case VK_OEM_1:		if(shiftPressed == false) return ';'; else return ':';
			case VK_OEM_2:		if(shiftPressed == false) return '/'; else return '?';
			case VK_OEM_3:		if(shiftPressed == false) return '`'; else return '~';
			case VK_OEM_4:		if(shiftPressed == false) return '['; else return '{';
			case VK_OEM_5:		if(shiftPressed == false) return '\\'; else return '|';
			case VK_OEM_6:		if(shiftPressed == false) return ']'; else return '}';
			case VK_OEM_7:		if(shiftPressed == false) return '\''; else return '"';


/*
				#define VK_OEM_1          0xBA   // ';:' for US
#define VK_OEM_2          0xBF   // '/?' for US
#define VK_OEM_3          0xC0   // '`~' for US


#define VK_OEM_4          0xDB  //  '[{' for US
#define VK_OEM_5          0xDC  //  '\|' for US
#define VK_OEM_6          0xDD  //  ']}' for US
#define VK_OEM_7          0xDE  //  ''"' for US*/
			}
		}

	return wParam;		
	}

//*****************************************************************************
