/*
    TScriptAction_Set.h - Contains template TScriptAction_Set and its specelizations.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTACTION_SET_H
#define REGINA_SCRIPT_TSCRIPTACTION_SET_H

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
//TScriptAction_Set template.												  |
//T1 return type, T2 argument type.											  |
//----------------------------------------------------------------------------|
template<class T1, class T2>
class TScriptAction_Set : public CScriptAction
{
	T1* result;
	T2*	argument1;

	public:
	TScriptAction_Set(T1* iResult, T2* iArgument) throw(invalid_argument); 
	void Execute() { *result = *argument1; }
		
};

//*****************************************************************************

template<class T1, class T2>
TScriptAction_Set<T1, T2>::TScriptAction_Set(T1* iResult, T2* iArgument) : argument1(iArgument), result(iResult)
	{ 
	if(iArgument == NULL)
		throw invalid_argument("TScriptAction_Set<T1, T2>::TScriptAction_Set - argument iArgument == NULL");

	if(iResult == NULL)
		throw invalid_argument("TScriptAction_Set<T1, T2>::TScriptAction_Set - argument iResult == NULL");
	}

//----------------------------------------------------------------------------|
//TScriptAction_Set template specelization.									  |
//T1 return type = wstring, T2 argument type.								  |
//----------------------------------------------------------------------------|
template<class T2>
class TScriptAction_Set<wstring, T2> : public CScriptAction
{
	wstring* result;
	T2*	argument1;

	public:
	TScriptAction_Set(wstring* iResult, T2* iArgument) throw(invalid_argument); 
	void Execute() { wostringstream os; os << *argument1; *result = os.str(); }
		
};

//*****************************************************************************

template<class T2>
TScriptAction_Set<wstring, T2>::TScriptAction_Set(wstring* iResult, T2* iArgument) : argument1(iArgument), result(iResult)
	{ 
	if(iArgument == NULL)
		throw invalid_argument("TScriptAction_Set<T1, T2>::TScriptAction_Set - argument iArgument == NULL");

	if(iResult == NULL)
		throw invalid_argument("TScriptAction_Set<T1, T2>::TScriptAction_Set - argument iResult == NULL");
	}

//----------------------------------------------------------------------------|
//TScriptAction_Set template specelization.									  |
//T1 return type = wstring, T2 argument type = wstring.						  |
//----------------------------------------------------------------------------|
template<>
class TScriptAction_Set<wstring, wstring> : public CScriptAction
{
	wstring* result;
	wstring*	argument1;

public:
	TScriptAction_Set(wstring* iResult, wstring* iArgument) throw(invalid_argument) : argument1(iArgument), result(iResult)		{	if(iArgument == NULL) throw invalid_argument("TScriptAction_Set<T1, T2>::TScriptAction_Set - argument iArgument == NULL"); if(iResult == NULL) 	throw invalid_argument("TScriptAction_Set<T1, T2>::TScriptAction_Set - argument iResult == NULL");	}
	void Execute() { *result = *argument1; }
		
};

//*****************************************************************************

}

}

#pragma warning( pop )

#endif