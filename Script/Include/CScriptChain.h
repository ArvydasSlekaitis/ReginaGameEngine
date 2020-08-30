/*
    CScriptChain.h - Contains class CScriptChain.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CSCRIPTCHAIN_H
#define REGINA_SCRIPT_CSCRIPTCHAIN_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <vector>
#include <exception>
#include <stdexcept>
using namespace std;

#include <CScriptAction.h>
#include <CScriptLine.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//CScriptChain class.														  |
//----------------------------------------------------------------------------|
class CScriptChain
{
vector<CScriptLine>		scriptText;
vector<CScriptAction*>	scriptAction;

public:
	~CScriptChain();
	void Add(CScriptAction* iScriptAction) throw(invalid_argument);
	void Run();
	
	void AddScriptLine(const CScriptLine& iScriptLine)	{ scriptText.push_back(iScriptLine); }
	void GetScriptText(vector<CScriptLine>& oScriptText){ oScriptText = scriptText; }
	unsigned GetScriptActionCount() const				{ return scriptAction.size(); }


};

//*****************************************************************************


}

}

#pragma warning( pop )

#endif