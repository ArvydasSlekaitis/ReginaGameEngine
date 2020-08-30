/*
    CScriptAction_While.cpp - Contains class CScriptAction_While implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CScriptAction_While.h>
using namespace Regina::Script;

//*****************************************************************************

CScriptAction_While::CScriptAction_While(bool* iCondition, CScriptAction* iScriptActionDo) : condition(iCondition), scriptActionDo(iScriptActionDo)
	{
	if(iCondition == NULL)
		throw invalid_argument("CScriptAction_While::CScriptAction_While - argument iCondition == NULL");

	if(iScriptActionDo == NULL)
		throw invalid_argument("CScriptAction_While::CScriptAction_While - argument iScriptActionDo == NULL");
	}

//*****************************************************************************

void CScriptAction_While::Execute()
	{
	while(*condition == true)
		scriptActionDo->Execute();
	}

//*****************************************************************************


