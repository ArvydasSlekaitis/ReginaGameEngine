/*
    EUIEventType.h - Contains UI event types enumeration.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_EUIEVENTTYPE_H
#define REGINA_UI_EUIEVENTTYPE_H

#include <d3dx9.h>

namespace Regina
{

namespace UI
{

enum EUIEventType{	e_UIEvent_FrameMove, 
					e_UIEvent_Render, 
					e_UIEvent_LeftClick, 
					e_UIEvent_RightClick, 
					e_UIEvent_KeyDown, 
					e_UIEvent_KeyUp, 
					e_UIEvent_KeyPress, 
					e_UIEvent_EnterPress, 
					e_UIEvent_MouseFocus, 
					e_UIEvent_MouseUnfocus, 
					e_UIEvent_StateChange, 
					e_UIEvent_Select, 
					e_UIEvent_Deselect,
					e_UIEvent_OkButtonPress,
					e_UIEvent_MessageBoxMouseFocus,
					e_UIEvent_MessageBoxMouseUnfocus,
					e_UIEvent_OkButtonMouseFocus,
					e_UIEvent_OkButtonMouseUnfocus,
					e_UIEvent_InputQueryMouseFocus,
					e_UIEvent_InputQueryMouseUnfocus,
					e_UIEvent_QuestionBoxMouseFocus,
					e_UIEvent_QuestionBoxMouseUnfocus,
					e_UIEvent_YesButtonPress,
					e_UIEvent_YesButtonMouseFocus,
					e_UIEvent_YesButtonMouseUnfocus,
					e_UIEvent_NoButtonPress,
					e_UIEvent_NoButtonMouseFocus,
					e_UIEvent_NoButtonMouseUnfocus,
					e_UIEvent_UpButtonPress,
					e_UIEvent_UpButtonMouseFocus,
					e_UIEvent_UpButtonMouseUnfocus,
					e_UIEvent_DownButtonPress,
					e_UIEvent_DownButtonMouseFocus,
					e_UIEvent_DownButtonMouseUnfocus,
					e_UIEvent_ScrollBarMouseFocus,
					e_UIEvent_ScrollBarMouseUnfocus,
					e_UIEvent_StepChange,
					e_UIEvent_LeftButtonPress,
					e_UIEvent_LeftButtonMouseFocus,
					e_UIEvent_LeftButtonMouseUnfocus,
					e_UIEvent_RightButtonPress,
					e_UIEvent_RightButtonMouseFocus,
					e_UIEvent_RightButtonMouseUnfocus,
					e_UIEvent_TextBoxMouseFocus,
					e_UIEvent_TextBoxMouseUnfocus,
					e_UIEvent_OnVerticalScrollBar_UpButtonPress,
					e_UIEvent_OnVerticalScrollBar_UpButtonMouseFocus,
					e_UIEvent_OnVerticalScrollBar_UpButtonMouseUnfocus,
					e_UIEvent_OnVerticalScrollBar_DownButtonPress,
					e_UIEvent_OnVerticalScrollBar_DownButtonMouseFocus,
					e_UIEvent_OnVerticalScrollBar_DownButtonMouseUnfocus
				};

#define DUIEventCount 51
}

}
#endif

