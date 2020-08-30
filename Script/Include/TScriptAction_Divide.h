/*
    TScriptAction_Divide.h - Contains template TScriptAction_Divide.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTACTION_DIVIDE_H
#define REGINA_SCRIPT_TSCRIPTACTION_DIVIDE_H

#pragma warning( push )
#pragma warning( disable : 4244 )

#include <string>
#include <sstream>
#include <CScriptAction.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//TScriptAction_Divide template.											  |
//Simulate function: Return = argument1 / argument2							  |
//T1 return type, T2 argument1 type, T3 argument2 type.						  |
//----------------------------------------------------------------------------|
template<class T1, class T2, class T3>
class TScriptAction_Divide : public CScriptAction
{
	T1* result;
	T2*	argument1;
	T3*	argument2;

	public:
	TScriptAction_Divide(T1* iResult, T2* iArgument1, T3* iArgument2) throw(invalid_argument); 
	void Execute() { *result = *argument1 / *argument2; }
		
};

//*****************************************************************************

template<class T1, class T2, class T3>
TScriptAction_Divide<T1, T2, T3>::TScriptAction_Divide(T1* iResult, T2* iArgument1, T3* iArgument2) : argument1(iArgument1), argument2(iArgument2), result(iResult)
	{ 
	if(iArgument1 == NULL)
		throw invalid_argument("TScriptAction_Divide<T1, T2>::TScriptAction_Divide - argument iArgument1 == NULL");

	if(iArgument2 == NULL)
		throw invalid_argument("TScriptAction_Divide<T1, T2>::TScriptAction_Divide - argument iArgument2 == NULL");

	if(iResult == NULL)
		throw invalid_argument("TScriptAction_Divide<T1, T2>::TScriptAction_Divide - argument iResult == NULL");
	}

//*****************************************************************************


}

}

#pragma warning( pop )

#endif