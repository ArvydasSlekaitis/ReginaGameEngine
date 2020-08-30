/*
    TScriptAction_While_NotEqual.h - Contains template TScriptAction_While_NotEqual.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTACTION_WHILE_NOTEQUAL
#define REGINA_SCRIPT_TSCRIPTACTION_WHILE_NOTEQUAL

#include <string>
#include <sstream>
#include <CScriptAction.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------------------------------------------|
//TScriptAction_While_NotEqual template.																			|
//Simulate while statement: while(argument1 >= argument2) ScriptActionDo->Execute()									|
//T1 argument1 type, T2 argument2 type																				|
//------------------------------------------------------------------------------------------------------------------|
template<class T1, class T2>
class TScriptAction_While_NotEqual : public CScriptAction
{
	T1*	argument1;
	T2*	argument2;
	CScriptAction*	scriptActionDo;
	CScriptAction*	scriptActionCondition;
	
public:
	~TScriptAction_While_NotEqual() { delete scriptActionDo; delete scriptActionCondition;}
	TScriptAction_While_NotEqual(T1* iArgument1, T2* iArgument2, CScriptAction* iScriptActionDo, CScriptAction* iScriptActionCondtion) throw(invalid_argument); 
	void Execute();
		
};

//*****************************************************************************

template<class T1, class T2>
TScriptAction_While_NotEqual<T1, T2>::TScriptAction_While_NotEqual(T1* iArgument1, T2* iArgument2, CScriptAction* iScriptActionDo, CScriptAction* iScriptActionCondition) : argument1(iArgument1), argument2(iArgument2), scriptActionDo(iScriptActionDo), scriptActionCondition(iScriptActionCondition)
	{ 
	if(iArgument1 == NULL)
		throw invalid_argument("TScriptAction_While_NotEqual<T1, T2>::TScriptAction_While_NotEqual - argument iArgument1 == NULL");

	if(iArgument2 == NULL)
		throw invalid_argument("TScriptAction_While_NotEqual<T1, T2>::TScriptAction_While_NotEqual - argument iArgument2 == NULL");

	if(iScriptActionDo == NULL)
		throw invalid_argument("TScriptAction_While_NotEqual<T1, T2>::TScriptAction_While_NotEqual - argument iScriptActionDo == NULL");

	if(iScriptActionCondition == NULL)
		throw invalid_argument("TScriptAction_While_NotEqual<T1, T2>::TScriptAction_While_NotEqual - argument iScriptActionCondition == NULL");
	}

//*****************************************************************************

template<class T1, class T2>
void TScriptAction_While_NotEqual<T1, T2>::Execute()
	{
	while(true)
		{
		scriptActionCondition->Execute();

		if(*argument1 != *argument2)
			scriptActionDo->Execute();
		else
			break;
		}
	}

//*****************************************************************************


}

}

#endif