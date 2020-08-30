/*
    CScriptAction_While.h - Contains class CScriptAction_While.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/



#ifndef REGINA_SCRIPT_CSCRIPTACTION_NONE_H
#define REGINA_SCRIPT_CSCRIPTACTION_NONE_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <exception>
#include <stdexcept>
using namespace std;

#include <CScriptAction.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//CScriptAction_While class.												  |
//Simulates while cycle: while(*condition) scriptActionDo->Execute()		  |
//----------------------------------------------------------------------------|
class CScriptAction_While: public CScriptAction
{
bool*			condition;
CScriptAction*	scriptActionDo;
public:
	CScriptAction_While(bool* iCondition, CScriptAction* iSciptActionDo) throw(invalid_argument);
	void Execute();
};
//*****************************************************************************


}

}

#pragma warning( pop )

#endif