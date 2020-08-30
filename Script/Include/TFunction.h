/*
    TFunction.h - Contains template TFunction and its specelizations.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TFUNCTION_H
#define REGINA_SCRIPT_TFUNCTION_H

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//Default TFunction template.												  |
//T1 class type, T2 return type, T3 argument type							  |
//----------------------------------------------------------------------------|
template<class T1, class T2, class T3>
class TFunction
{
	T2 (T1::*function)(T3);
	wstring	name;
	T1*		workingClass;

public:
	TFunction(const wstring &iName, T2 (T1::*iFunction)(T3), T1* iWorkingClass);
	T2 RunFunction(T3 iArgument) { return (workingClass->*function)(iArgument); }
	wstring Name() const { return name; }
};

//*****************************************************************************

template<class T1, class T2, class T3>
TFunction<T1, T2, T3>::TFunction(const wstring &iName, T2 (T1::*iFunction)(T3), T1* iWorkingClass) : function(NULL), name(iName), workingClass(NULL)
	{
	function = iFunction;
	workingClass = iWorkingClass;
	}

//*****************************************************************************

//----------------------------------------------------------------------------|
// TFunction template specialization.										  |	
//T1 class type, T2 return type = void, T3 argument type = void				  |
//----------------------------------------------------------------------------|
template<class T1>
class TFunction <T1, void, void>
{
	void (T1::*function)(void);
	wstring	name;
	T1*		workingClass;

public:
	TFunction(const wstring &iName, void (T1::*iFunction)(), T1* iWorkingClass);
	void RunFunction() { (workingClass->*function)(); }
	wstring Name() const { return name; }
};

//*****************************************************************************

template<class T1>
TFunction<T1, void, void>::TFunction(const wstring &iName, void (T1::*iFunction)(), T1* iWorkingClass) : function(NULL), name(iName), workingClass(NULL)
	{
	function = iFunction;
	workingClass = iWorkingClass;
	}

//*****************************************************************************

//----------------------------------------------------------------------------|
// TFunction template specialization.										  |	
//T1 class type, T2 return type, T3 argument type = void				      |
//----------------------------------------------------------------------------|
template<class T1, class T2>
class TFunction <T1, T2, void>
{
	T2 (T1::*function)(void);
	wstring	name;
	T1*		workingClass;

public:
	TFunction(const wstring &iName, T2 (T1::*iFunction)(), T1* iWorkingClass);
	T2 RunFunction() { return (workingClass->*function)(); }
	wstring Name() const { return name; }
};

//*****************************************************************************

template<class T1, class T2>
TFunction<T1, T2, void>::TFunction(const wstring &iName, T2 (T1::*iFunction)(), T1* iWorkingClass) : function(NULL), name(iName), workingClass(NULL)
	{
	function = iFunction;
	workingClass = iWorkingClass;
	}

//*****************************************************************************

}

}

#endif
