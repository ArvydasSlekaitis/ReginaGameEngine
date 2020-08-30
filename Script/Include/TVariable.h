/*
    TVariable.h - Contains template TVariable.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TVARIABLE_H
#define REGINA_SCRIPT_TVARIABLE_H

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//TVariable template.														  |
//T1 variable type															  |
//----------------------------------------------------------------------------|
template<class T>
class TVariable
{
	wstring	name;
	T*		variable;
	bool	usingPtr;

	public:
	TVariable(const wstring& iName, T iValue = T(), T* iPntrToVariable = NULL);
	TVariable(const wstring& iName, T* iPntrToVariable = NULL);
	TVariable(const TVariable& iVariable);
	TVariable& operator=(const TVariable &iVariable);

	~TVariable();

	wstring	Name()	const { return name; }
	T		Value()	const { return *variable; }
	T*		PointerToVariable()	{ return variable; } 
	void	SetValue(T iValue) { *variable = iValue; }
};

//*****************************************************************************

template<class T>
TVariable<T>::TVariable(const wstring& iName, T iValue, T* iPntrToVariable) : name(iName), variable(NULL), usingPtr(true) 
	{ 
	if(iPntrToVariable==NULL) 
		{
		variable = new T(iValue); 
		usingPtr = false; 
		} 
	else 
		{
		variable = iPntrToVariable; 
		*variable = iValue;
		usingPtr = true;
		} 
	}

//*****************************************************************************

template<class T>
TVariable<T>::TVariable(const wstring& iName, T* iPntrToVariable) : name(iName), variable(NULL), usingPtr(true) 
	{ 
	if(iPntrToVariable==NULL) 
		{
		variable = new T(); 
		usingPtr = false; 
		} 
	else 
		{
		variable = iPntrToVariable; 
		usingPtr = true;
		} 
	}

//*****************************************************************************

template<class T>
TVariable<T>::TVariable(const TVariable& iVariable) 
	{
	name = iVariable.name;
	usingPtr = iVariable.usingPtr;

	if(iVariable.usingPtr == true)
		variable = iVariable.variable;
	else
		variable = new T(*iVariable.variable); 
	}

//*****************************************************************************

template<class T>
TVariable<T>::~TVariable()
	{
	if(!usingPtr) delete variable;
	variable = NULL;
	}

//*****************************************************************************

template<class T>
TVariable<T>& TVariable<T>::operator=(const TVariable<T> &iVariable)
	{
	if (this != &iVariable) 
		{
		if(!usingPtr) delete variable;
		variable = NULL;

		name = iVariable.name;
		usingPtr = iVariable.usingPtr;

		if(iVariable.usingPtr == true)
			variable = iVariable.variable;
		else
			variable = new T(*iVariable.variable); 
		}

	return *this;
	}

//*****************************************************************************


}

}

#endif