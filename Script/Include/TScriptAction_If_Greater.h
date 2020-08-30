/*
    TScriptAction_If_Greater.h - Contains template TScriptAction_If_Greater.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTACTION_IF_GREATER_H
#define REGINA_SCRIPT_TSCRIPTACTION_IF_GREATER_H

#include <string>
#include <sstream>
#include <CScriptAction.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------------------------------------------|
//TScriptAction_If_Greater template.																				|
//Simulate if statement: if(argument1 > argument2) ScriptActionTrue->Execute() else SriptActionFalse->Execute()		|
//T1 argument1 type, T2 argument2 type																				|
//------------------------------------------------------------------------------------------------------------------|
template<class T1, class T2>
class TScriptAction_If_Greater : public CScriptAction
{
	T1*	argument1;
	T2*	argument2;
	CScriptAction*	scriptActionTrue;
	CScriptAction*	scriptActionFalse;

	public:
	~TScriptAction_If_Greater() { delete scriptActionTrue; delete scriptActionFalse; }
	TScriptAction_If_Greater(T1* iArgument1, T2* iArgument2, CScriptAction* iScriptActionTrue, CScriptAction* iScriptActionFalse) throw(invalid_argument); 
	void Execute();
		
};

//*****************************************************************************

template<class T1, class T2>
TScriptAction_If_Greater<T1, T2>::TScriptAction_If_Greater(T1* iArgument1, T2* iArgument2, CScriptAction* iScriptActionTrue, CScriptAction* iScriptActionFalse) : argument1(iArgument1), argument2(iArgument2), scriptActionTrue(iScriptActionTrue), scriptActionFalse(iScriptActionFalse)
	{ 
	if(iArgument1 == NULL)
		throw invalid_argument("TScriptAction_If_Greater<T1, T2>::TScriptAction_If_Greater - argument iArgument1 == NULL");

	if(iArgument2 == NULL)
		throw invalid_argument("TScriptAction_If_Greater<T1, T2>::TScriptAction_If_Greater - argument iArgument2 == NULL");

	if(iScriptActionTrue == NULL)
		throw invalid_argument("TScriptAction_If_Greater<T1, T2>::TScriptAction_If_Greater - argument iScriptActionTrue == NULL");
	
	if(iScriptActionFalse == NULL)
		throw invalid_argument("TScriptAction_If_Greater<T1, T2>::TScriptAction_If_Greater - argument iScriptActionFalse == NULL");
	}

//*****************************************************************************

template<class T1, class T2>
void TScriptAction_If_Greater<T1, T2>::Execute()
	{
	if(*argument1 > *argument2)
		scriptActionTrue->Execute();
	else 
		scriptActionFalse->Execute();
	}

//*****************************************************************************


}

}

#endif