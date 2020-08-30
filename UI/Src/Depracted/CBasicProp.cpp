/*
    CBasicProp.cpp - Contains class CBasicProp implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CBasicProp.h>
using namespace Regina::UI;


//******************************************************************************

void CBasicProp::GetInitializingScriptText(const wstring& iPrefix, vector<wstring>& oScriptText)
	{
	//scriptName_OnFrameMove
	if(scriptName_OnFrameMove.size()>0)
		{
		wostringstream os;
		os << iPrefix << L"scriptName_OnFrameMove = \"" << scriptName_OnFrameMove << L"\"";
		oScriptText.push_back(os.str());
		}

	//scriptName_OnRender
	if(scriptName_OnRender.size()>0)
		{
		wostringstream os;
		os << iPrefix << L"scriptName_OnRender = \"" << scriptName_OnRender << L"\"";
		oScriptText.push_back(os.str());
		}

	//scriptName_OnLeftClick
	if(scriptName_OnLeftClick.size()>0)
		{
		wostringstream os;
		os << iPrefix << L"scriptName_OnLeftClick = \"" << scriptName_OnLeftClick << L"\"";
		oScriptText.push_back(os.str());
		}

	//scriptName_OnRightClick
	if(scriptName_OnRightClick.size()>0)
		{
		wostringstream os;
		os << iPrefix << L"scriptName_OnRightClick = \"" << scriptName_OnRightClick << L"\"";
		oScriptText.push_back(os.str());
		}

	//scriptName_OnKeyDown
	if(scriptName_OnKeyDown.size()>0)
		{
		wostringstream os;
		os << iPrefix << L"scriptName_OnKeyDown = \"" << scriptName_OnKeyDown << L"\"";
		oScriptText.push_back(os.str());
		}
	
	//scriptName_OnKeyUp
	if(scriptName_OnKeyUp.size()>0)
		{
		wostringstream os;
		os << iPrefix << L"scriptName_OnKeyUp = \"" << scriptName_OnKeyUp << L"\"";
		oScriptText.push_back(os.str());
		}

	//scriptName_OnMouseFocus
	if(scriptName_OnMouseFocus.size()>0)
		{
		wostringstream os;
		os << iPrefix << L"scriptName_OnMouseFocus = \"" << scriptName_OnMouseFocus << L"\"";
		oScriptText.push_back(os.str());
		}

	//scriptName_OnMouseUnFocus
	if(scriptName_OnMouseUnFocus.size()>0)
		{
		wostringstream os;
		os << iPrefix << L"scriptName_OnMouseUnFocus = \"" << scriptName_OnMouseUnFocus << L"\"";
		oScriptText.push_back(os.str());
		}
}

//*****************************************************************************

