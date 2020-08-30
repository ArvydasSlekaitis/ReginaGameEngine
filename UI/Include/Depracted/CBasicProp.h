/*
    CBasicProp.h - Contains class CBasicProp.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CBASICPROP_H
#define REGINA_UI_CBASICPROP_H

#include <vector>
#include <sstream>
#include <string>
using namespace std;

#include <CColor.h>

namespace Regina
{

namespace UI
{

class CBasicProp
{
public:
	wstring			scriptName_OnFrameMove;
	wstring			scriptName_OnRender;
	wstring			scriptName_OnLeftClick;
	wstring			scriptName_OnRightClick;
	wstring			scriptName_OnKeyDown;
	wstring			scriptName_OnKeyUp;
	wstring			scriptName_OnMouseFocus;
	wstring			scriptName_OnMouseUnFocus;

public:
	void GetInitializingScriptText(const wstring& iPrefix, vector<wstring>& oScriptText);
	
};

}

}

#endif
