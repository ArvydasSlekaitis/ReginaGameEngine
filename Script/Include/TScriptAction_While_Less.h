/*
    TScriptAction_While_Less.h - Contains template TScriptAction_While_Less.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTACTION_WHILE_LESS
#define REGINA_SCRIPT_TSCRIPTACTION_WHILE_LESS

#include <string>
#include <sstream>
#include <CScriptAction.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------------------------------------------|
//TScriptAction_While_Less template.																				|
//Simulate while statement: while(argument1 < argument2) ScriptActionDo->Execute()									|
//T1 argument1 type, T2 argument2 type																				|
//------------------------------------------------------------------------------------------------------------------|
template<class T1, class T2>
class TScriptAction_While_Less : public CScriptAction
{
	T1*	argument1;
	T2*	argument2;
	CScriptAction*	scriptActionDo;
	CScriptAction*	scriptActionCondition;
	
public:
	~TScriptAction_While_Less() { delete scriptActionDo; delete scriptActionCondition;}
	TScriptAction_While_Less(T1* iArgument1, T2* iArgument2, CScriptAction* iScriptActionDo, CScriptAction* iScriptActionCondtion) throw(invalid_argument); 
	void Execute();
		
};

//*****************************************************************************

template<class T1, class T2>
TScriptAction_While_Less<T1, T2>::TScriptAction_While_Less(T1* iArgument1, T2* iArgument2, CScriptAction* iScriptActionDo, CScriptAction* iScriptActionCondition) : argument1(iArgument1), argument2(iArgument2), scriptActionDo(iScriptActionDo), scriptActionCondition(iScriptActionCondition)
	{ 
	if(iArgument1 == NULL)
		throw invalid_argument("TScriptAction_While_Less<T1, T2>::TScriptAction_While_Less - argument iArgument1 == NULL");

	if(iArgument2 == NULL)
		throw invalid_argument("TScriptAction_While_Less<T1, T2>::TScriptAction_While_Less - argument iArgument2 == NULL");

	if(iScriptActionDo == NULL)
		throw invalid_argument("TScriptAction_While_Less<T1, T2>::TScriptAction_While_Less - argument iScriptActionDo == NULL");

	if(iScriptActionCondition == NULL)
		throw invalid_argument("TScriptAction_While_Less<T1, T2>::TScriptAction_While_Less - argument iScriptActionCondition == NULL");
	}

//*****************************************************************************

template<class T1, class T2>
void TScriptAction_While_Less<T1, T2>::Execute()
	{
	while(true)
		{
		scriptActionCondition->Execute();

		if(*argument1 < *argument2)
			scriptActionDo->Execute();
		else
			break;
		}
	}

//*****************************************************************************


}

}

#endif