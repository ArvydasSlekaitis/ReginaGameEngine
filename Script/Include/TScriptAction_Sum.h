/*
    TScriptAction_Sum.h - Contains template TScriptAction_Sum and its specelizations.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTACTION_SUM_H
#define REGINA_SCRIPT_TSCRIPTACTION_SUM_H

#pragma warning( push )
#pragma warning( disable : 4244 )

#include <string>
#include <sstream>
using namespace std;

#include <CScriptAction.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//TScriptAction_Sum template.												  |
//Simulate function: Return = argument1 + argument2							  |
//T1 return type, T2 argument1 type, T3 argument2 type.						  |
//----------------------------------------------------------------------------|
template<class T1, class T2, class T3>
class TScriptAction_Sum : public CScriptAction
{
	T1* result;
	T2*	argument1;
	T3*	argument2;
	
	public:
	TScriptAction_Sum(T1* iResult, T2* iArgument1, T3* iArgument2) throw(invalid_argument); 
	void Execute() { *result = *argument1 + *argument2; }
		
};

//*****************************************************************************

template<class T1, class T2, class T3>
TScriptAction_Sum<T1, T2, T3>::TScriptAction_Sum(T1* iResult, T2* iArgument1, T3* iArgument2) : argument1(iArgument1), argument2(iArgument2), result(iResult)
	{ 
	if(iArgument1 == NULL)
		throw invalid_argument("TScriptAction_Sum<T1, T2>::TScriptAction_Sum - argument iArgument1 == NULL");

	if(iArgument2 == NULL)
		throw invalid_argument("TScriptAction_Sum<T1, T2>::TScriptAction_Sum - argument iArgument2 == NULL");

	if(iResult == NULL)
		throw invalid_argument("TScriptAction_Sum<T1, T2>::TScriptAction_Sum - argument iResult == NULL");
	}

//----------------------------------------------------------------------------|
//TScriptAction_Sum template specelization.									  |
//T1 return type = wstring, T2 argument1 type, T3 argument2 type.			  |
//----------------------------------------------------------------------------|
template<class T2, class T3>
class TScriptAction_Sum<wstring, T2, T3> : public CScriptAction
{
	wstring* result;
	T2*	argument1;
	T3*	argument2;

	public:
	TScriptAction_Sum(wstring* iResult, T2* iArgument1, T3* iArgument2) throw(invalid_argument); 
	void Execute() { wostringstream os; os << *argument1 << *argument2; *result = os.str(); }
		
};

//*****************************************************************************

template<class T2, class T3>
TScriptAction_Sum<wstring, T2, T3>::TScriptAction_Sum(wstring* iResult, T2* iArgument1, T3* iArgument2) : argument1(iArgument1), argument2(iArgument2), result(iResult)
	{ 
	if(iArgument1 == NULL)
		throw invalid_argument("TScriptAction_Sum<T1, T2>::TScriptAction_Sum - argument iArgument1 == NULL");

	if(iArgument2 == NULL)
		throw invalid_argument("TScriptAction_Sum<T1, T2>::TScriptAction_Sum - argument iArgument2 == NULL");

	if(iResult == NULL)
		throw invalid_argument("TScriptAction_Sum<T1, T2>::TScriptAction_Sum - argument iResult == NULL");
	}

//*****************************************************************************

//----------------------------------------------------------------------------------|
//TScriptAction_Sum template specelization.											|
//T1 argument1 type = wstring, T2 argument2 type = wstring, T3 return type = wstring.	|
//----------------------------------------------------------------------------------|
template<>
class TScriptAction_Sum<wstring, wstring, wstring> : public CScriptAction
{
	wstring* result;
	wstring*	argument1;
	wstring*	argument2;

	public:
	TScriptAction_Sum(wstring* iResult, wstring* iArgument1, wstring* iArgument2) throw(invalid_argument) : argument1(iArgument1), argument2(iArgument2), result(iResult)	{	if(iArgument1 == NULL) throw invalid_argument("TScriptAction_Set<T1, T2>::TScriptAction_Set - argument iArgument1 == NULL"); if(iArgument2 == NULL) throw invalid_argument("TScriptAction_Set<T1, T2>::TScriptAction_Set - argument iArgument2 == NULL"); if(iResult == NULL) 	throw invalid_argument("TScriptAction_Set<T1, T2>::TScriptAction_Set - argument iResult == NULL");	}
	void Execute() {*result = *argument1 + *argument2; }
		
};

//*****************************************************************************


}

}

#pragma warning( pop )

#endif