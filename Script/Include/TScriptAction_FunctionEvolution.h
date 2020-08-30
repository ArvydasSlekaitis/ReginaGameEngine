/*
    TSciptAction_FunctionEvolution.h - Contains template TSciptAction_FunctionEvolution and its specelizations.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTACTION_FUNCTIONEVOLUTION_H
#define REGINA_SCRIPT_TSCRIPTACTION_FUNCTIONEVOLUTION_H

#include <CScriptAction.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------------------------------------------|
//TSciptAction_FunctionEvolution template.																			|
//Evolutes Function: functionPool->RunFunction(position, return, argument)											|
//T1 function pool type, T2 return type, T3 argument type															|
//------------------------------------------------------------------------------------------------------------------|
template<class T1, class T2, class T3>
class TSciptAction_FunctionEvolution : public CScriptAction
{
	T1*			functionPool;
	T2*			result;
	T3*			argument;
	unsigned	position;

public:
	TSciptAction_FunctionEvolution(T1* iFunctionPool, T2* iResult, T3* iArgument, const unsigned& iPosition);
	void Execute();
};

//*****************************************************************************

template<class T1, class T2, class T3>
TSciptAction_FunctionEvolution<T1, T2, T3>::TSciptAction_FunctionEvolution(T1* iFunctionPool, T2* iResult, T3* iArgument, const unsigned& iPosition) : functionPool(iFunctionPool), result(iResult), argument(iArgument), position(iPosition)
	{
	if(iFunctionPool == NULL)
		throw invalid_argument("TSciptAction_FunctionEvolution<T1, T2, T3>::TSciptAction_FunctionEvolution - argument iFunctionPool == NULL");

	if(iResult == NULL)
		throw invalid_argument("TSciptAction_FunctionEvolution<T1, T2, T3>::TSciptAction_FunctionEvolution - argument iResult == NULL");

	if(iArgument == NULL)
		throw invalid_argument("TSciptAction_FunctionEvolution<T1, T2, T3>::TSciptAction_FunctionEvolution - argument iArgument == NULL");
	}

//*****************************************************************************

template<class T1, class T2, class T3>
void TSciptAction_FunctionEvolution<T1, T2, T3>::Execute()
	{
	functionPool->RunFunction(position, *argument, result);
	}

//*****************************************************************************

//------------------------------------------------------------------------------------------------------------------|
//TSciptAction_FunctionEvolution template specelization.															|
//Evolutes Function: functionPool->RunFunction(position)															|
//T1 function pool type, T2 return type = void, T3 argument type = void												|
//------------------------------------------------------------------------------------------------------------------|
template<class T1>
class TSciptAction_FunctionEvolution <T1, void, void>  : public CScriptAction
{
	T1*			functionPool;
	unsigned	position;

public:
	TSciptAction_FunctionEvolution(T1* iFunctionPool, const unsigned& iPosition);
	void Execute();
};

//*****************************************************************************

template<class T1>
TSciptAction_FunctionEvolution<T1, void, void>::TSciptAction_FunctionEvolution(T1* iFunctionPool, const unsigned& iPosition) :  functionPool(iFunctionPool), position(iPosition)
	{
	if(iFunctionPool == NULL)
		throw invalid_argument("TSciptAction_FunctionEvolution<T1, T2, T3>::TSciptAction_FunctionEvolution - argument iFunctionPool == NULL");
	}

//*****************************************************************************

template<class T1>
void TSciptAction_FunctionEvolution<T1, void, void>::Execute()
	{
	functionPool->RunFunction(position);
	}

//*****************************************************************************

//------------------------------------------------------------------------------------------------------------------|
//TSciptAction_FunctionEvolution template specelization.															|
//Evolutes Function: functionPool->RunFunction(position, return)													|
//T1 function pool type, T2 return type, T3 argument type = void													|
//------------------------------------------------------------------------------------------------------------------|
template<class T1, class T2>
class TSciptAction_FunctionEvolution <T1, T2, void>  : public CScriptAction
{
	T1*			functionPool;
	T2*			result;
	unsigned	position;

public:
	TSciptAction_FunctionEvolution(T1* iFunctionPool, T2* iResult, const unsigned& iPosition);
	void Execute();
};

//*****************************************************************************

template<class T1, class T2>
TSciptAction_FunctionEvolution<T1, T2, void>::TSciptAction_FunctionEvolution(T1* iFunctionPool, T2* iResult, const unsigned& iPosition) :  functionPool(iFunctionPool), result(iResult), position(iPosition)
	{
	if(iFunctionPool == NULL)
		throw invalid_argument("TSciptAction_FunctionEvolution<T1, T2, T3>::TSciptAction_FunctionEvolution - argument iFunctionPool == NULL");

	if(iResult == NULL)
		throw invalid_argument("TSciptAction_FunctionEvolution<T1, T2, T3>::TSciptAction_FunctionEvolution - argument iResult == NULL");
	}

//*****************************************************************************

template<class T1, class T2>
void TSciptAction_FunctionEvolution<T1, T2, void>::Execute()
	{
	functionPool->RunFunction(position, result);
	}

//*****************************************************************************

//------------------------------------------------------------------------------------------------------------------|
//TSciptAction_FunctionEvolution template specelization.															|
//Evolutes Function: functionPool->RunFunction(position, return)													|
//T1 function pool type, T2 return type = void, T3 argument type													|
//------------------------------------------------------------------------------------------------------------------|
template<class T1, class T3>
class TSciptAction_FunctionEvolution <T1, void, T3>  : public CScriptAction
{
	T1*			functionPool;
	T3*			argument;
	unsigned	position;

public:
	TSciptAction_FunctionEvolution(T1* iFunctionPool, T3* iArgument, const unsigned& iPosition);
	void Execute();
};

//*****************************************************************************

template<class T1, class T3>
TSciptAction_FunctionEvolution<T1, void, T3>::TSciptAction_FunctionEvolution(T1* iFunctionPool, T3* iArgument, const unsigned& iPosition) :  functionPool(iFunctionPool), argument(iArgument), position(iPosition)
	{
	if(iFunctionPool == NULL)
		throw invalid_argument("TSciptAction_FunctionEvolution<T1, T2, T3>::TSciptAction_FunctionEvolution - argument iFunctionPool == NULL");

	if(iArgument == NULL)
		throw invalid_argument("TSciptAction_FunctionEvolution<T1, T2, T3>::TSciptAction_FunctionEvolution - argument iArgument == NULL");
	}

//*****************************************************************************

template<class T1, class T3>
void TSciptAction_FunctionEvolution<T1, void, T3>::Execute()
	{
	functionPool->RunFunction(position, *argument);
	}

//*****************************************************************************

}

}

#endif
