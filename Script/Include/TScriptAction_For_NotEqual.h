/*
    TScriptAction_For_NotEqual.h - Contains template TScriptAction_For_NotEqual.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTACTION_FOR_NOTEQUAL_H
#define REGINA_SCRIPT_TSCRIPTACTION_FOR_NOTEQUAL_H

#include <string>
#include <sstream>
#include <CScriptAction.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------------------------------------------|
//TScriptAction_For_NotEqual template.																				|
//Simulate for statement: for(; argument1!=argument2;) ScriptActionDo->Execute()									|
//T1 argument1 type, T2 argument2 type																				|
//------------------------------------------------------------------------------------------------------------------|
template<class T1, class T2>
class TScriptAction_For_NotEqual : public CScriptAction
{
	T1*	argument1;
	T2*	argument2;
	CScriptAction*	scriptActionDo;
	CScriptAction*	scriptActionCondition;
	CScriptAction*	scriptActionIncrement;
	
public:
	~TScriptAction_For_NotEqual() { delete scriptActionDo; delete scriptActionCondition; delete scriptActionIncrement; }
	TScriptAction_For_NotEqual(T1* iArgument1, T2* iArgument2, CScriptAction* iScriptActionDo, CScriptAction* iScriptActionCondtion, CScriptAction* iScriptActionIncrement) throw(invalid_argument); 
	void Execute();
		
};

//*****************************************************************************

template<class T1, class T2>
TScriptAction_For_NotEqual<T1, T2>::TScriptAction_For_NotEqual(T1* iArgument1, T2* iArgument2, CScriptAction* iScriptActionDo, CScriptAction* iScriptActionCondition, CScriptAction* iScriptActionIncrement) : argument1(iArgument1), argument2(iArgument2), scriptActionDo(iScriptActionDo), scriptActionCondition(iScriptActionCondition), scriptActionIncrement(iScriptActionIncrement)
	{ 
	if(iArgument1 == NULL)
		throw invalid_argument("TScriptAction_For_NotEqual<T1, T2>::TScriptAction_For_NotEqual - argument iArgument1 == NULL");

	if(iArgument2 == NULL)
		throw invalid_argument("TScriptAction_For_NotEqual<T1, T2>::TScriptAction_For_NotEqual - argument iArgument2 == NULL");

	if(iScriptActionDo == NULL)
		throw invalid_argument("TScriptAction_For_NotEqual<T1, T2>::TScriptAction_For_NotEqual - argument iScriptActionDo == NULL");

	if(iScriptActionCondition == NULL)
		throw invalid_argument("TScriptAction_For_NotEqual<T1, T2>::TScriptAction_For_NotEqual - argument iScriptActionCondition == NULL");

	if(scriptActionIncrement == NULL)
		throw invalid_argument("TScriptAction_For_NotEqual<T1, T2>::TScriptAction_For_NotEqual - argument iScriptActionIncrement == NULL");
	}

//*****************************************************************************

template<class T1, class T2>
void TScriptAction_For_NotEqual<T1, T2>::Execute()
	{
	while(true)
		{
		scriptActionCondition->Execute();

		if(*argument1 != *argument2)
			{
			scriptActionDo->Execute();
			scriptActionIncrement->Execute();
			}
		else
			break;
		}
	}

//*****************************************************************************


}

}

#endif