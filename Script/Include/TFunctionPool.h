/*
    TFunctionPool.h - Contains template TFunctionPool.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TFUNCTIONPOOL_H
#define REGINA_SCRIPT_TFUNCTIONPOOL_H

#include <vector>
#include <string>
#include <exception>
#include <stdexcept>
#include <map>
using namespace std;

#include <TFunction.h>
#include <CFunctionDefinition.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//TFunctionPool template.													  |
//T class type																  |
//----------------------------------------------------------------------------|
template<class T>
class TFunctionPool
{
	T* workingClass;
	map<wstring, CFunctionDefinition>	functionDefinitions;	

	vector<TFunction<T, void, void> >	function_void_void; 	//Return void; Argument void;

	vector<TFunction<T, void, bool> >	function_void_bool; 	//Return void; Argument bool
	vector<TFunction<T, void, int> >	function_void_int;		//Return void; Argument int
	vector<TFunction<T, void, float> >	function_void_float;	//Return void; Argument float
	vector<TFunction<T, void, wstring> >function_void_string;	//Return void; Argument string

	vector<TFunction<T, bool, void> >	function_bool_void;		//Return bool; Argument void
	vector<TFunction<T, bool, bool> >	function_bool_bool;		//Return bool; Argument bool
	vector<TFunction<T, bool, int> >	function_bool_int;		//Return bool; Argument int
	vector<TFunction<T, bool, float> >	function_bool_float;	//Return bool; Argument float
	vector<TFunction<T, bool, wstring> >function_bool_string;	//Return bool; Argument string

	vector<TFunction<T, int, void> >	function_int_void;		//Return int; Argument void
	vector<TFunction<T, int, bool> >	function_int_bool;		//Return int; Argument bool
	vector<TFunction<T, int, int> >		function_int_int;		//Return int; Argument int
	vector<TFunction<T, int, float> >	function_int_float;		//Return int; Argument float
	vector<TFunction<T, int, wstring> >	function_int_string;	//Return int; Argument string

	vector<TFunction<T, float, void> >	function_float_void;	//Return float; Argument void
	vector<TFunction<T, float, bool> >	function_float_bool;	//Return float; Argument bool
	vector<TFunction<T, float, int> >	function_float_int;		//Return float; Argument int
	vector<TFunction<T, float, float> >	function_float_float;	//Return float; Argument float
	vector<TFunction<T, float, wstring> >function_float_string;	//Return float; Argument string

	vector<TFunction<T, wstring, void> >function_string_void;	//Return string; Argument void
	vector<TFunction<T, wstring, bool> >function_string_bool;	//Return string; Argument bool
	vector<TFunction<T, wstring, int> >	function_string_int;	//Return string; Argument int
	vector<TFunction<T, wstring, float> >function_string_float;	//Return string; Argument float
	vector<TFunction<T, wstring, wstring> >function_string_string;//Return string; Argument string

	void AddFunctionDefinition(const wstring& iName, const unsigned& iPosition, const CFunctionDefinition::EFunctionArgumentType& iReturnType, const CFunctionDefinition::EFunctionArgumentType& iArgumentType);

public:
	TFunctionPool(T* iWorkingClass) throw(invalid_argument);

	bool ExistFunction(const wstring& iFunctionName);
	CFunctionDefinition GetFunctionDefinition(const wstring& iFunctionName) throw(invalid_argument);	

	//Return void; Argument void;
	void AddFunction(const wstring &iFunctionName, void (T::*iFunction)())  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName);		
	void RunFunction(const unsigned &iFunctionPosition);	
	unsigned GetFunctionPosition_void_void(const wstring &iFunctionName)  throw(invalid_argument);	

	//Return void; Argument bool
	void AddFunction(const wstring &iFunctionName, void (T::*iFunction)(bool iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, bool iArgument);	
	void RunFunction(const unsigned &iFunctionPosition, bool iArgument);	
	unsigned GetFunctionPosition_void_bool(const wstring &iFunctionName)  throw(invalid_argument);	

	//Return void; Argument int
	void AddFunction(const wstring &iFunctionName, void (T::*iFunction)(int iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, int iArgument);	
	void RunFunction(const unsigned &iFunctionPosition, int iArgument);	
	unsigned GetFunctionPosition_void_int(const wstring &iFunctionName)  throw(invalid_argument);	
	
	//Return void; Argument float
	void AddFunction(const wstring &iFunctionName, void (T::*iFunction)(float iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, float iArgument);	
	void RunFunction(const unsigned &iFunctionPosition, float iArgument);	
	unsigned GetFunctionPosition_void_float(const wstring &iFunctionName)  throw(invalid_argument);	

	//Return void; Argument string
	void AddFunction(const wstring &iFunctionName, void (T::*iFunction)(wstring iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, wstring iArgument);
	void RunFunction(const unsigned &iFunctionPosition, wstring iArgument);	
	unsigned GetFunctionPosition_void_string(const wstring &iFunctionName)  throw(invalid_argument);	

	//Return bool; Argument void
	void AddFunction(const wstring &iFunctionName, bool (T::*iFunction)())  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, bool* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, bool* oReturnValue);	
	unsigned GetFunctionPosition_bool_void(const wstring &iFunctionName)  throw(invalid_argument);	

	//Return bool; Argument bool
	void AddFunction(const wstring &iFunctionName, bool (T::*iFunction)(bool iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, bool iArgument, bool* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, bool iArgument, bool* oReturnValue);	
	unsigned GetFunctionPosition_bool_bool(const wstring &iFunctionName)  throw(invalid_argument);	

	//Return bool; Argument int
	void AddFunction(const wstring &iFunctionName, bool (T::*iFunction)(int iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, int iArgument, bool* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, int iArgument, bool* oReturnValue);	
	unsigned GetFunctionPosition_bool_int(const wstring &iFunctionName)  throw(invalid_argument);	

	//Return bool; Argument float
	void AddFunction(const wstring &iFunctionName, bool (T::*iFunction)(float iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, float iArgument, bool* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, float iArgument, bool* oReturnValue);	
	unsigned GetFunctionPosition_bool_float(const wstring &iFunctionName)  throw(invalid_argument);	

	//Return bool; Argument string
	void AddFunction(const wstring &iFunctionName, bool (T::*iFunction)(wstring iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, wstring iArgument, bool* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, wstring iArgument, bool* oReturnValue);	
	unsigned GetFunctionPosition_bool_string(const wstring &iFunctionName)  throw(invalid_argument);	

	//Return int; Argument void
	void AddFunction(const wstring &iFunctionName, int (T::*iFunction)())  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, int* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, int* oReturnValue);	
	unsigned GetFunctionPosition_int_void(const wstring &iFunctionName)  throw(invalid_argument);	

	//Return int; Argument bool
	void AddFunction(const wstring &iFunctionName, int (T::*iFunction)(bool iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, bool iArgument, int* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, bool iArgument, int* oReturnValue);	
	unsigned GetFunctionPosition_int_bool(const wstring &iFunctionName)  throw(invalid_argument);

	//Return int; Argument int
	void AddFunction(const wstring &iFunctionName, int (T::*iFunction)(int iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, int iArgument, int* oReturnValue);
	void RunFunction(const unsigned &iFunctionPosition, int iArgument, int* oReturnValue);	
	unsigned GetFunctionPosition_int_int(const wstring &iFunctionName)  throw(invalid_argument);

	//Return int; Argument float
	void AddFunction(const wstring &iFunctionName, int (T::*iFunction)(float iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, float iArgument, int* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, float iArgument, int* oReturnValue);	
	unsigned GetFunctionPosition_int_float(const wstring &iFunctionName)  throw(invalid_argument);

	//Return int; Argument string
	void AddFunction(const wstring &iFunctionName, int (T::*iFunction)(wstring iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, wstring iArgument, int* oReturnValue);
	void RunFunction(const unsigned &iFunctionPosition, wstring iArgument, int* oReturnValue);	
	unsigned GetFunctionPosition_int_string(const wstring &iFunctionName)  throw(invalid_argument);

	//Return float; Argument void
	void AddFunction(const wstring &iFunctionName, float (T::*iFunction)())  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, float* oReturnValue);		
	void RunFunction(const unsigned &iFunctionPosition, float* oReturnValue);	
	unsigned GetFunctionPosition_float_void(const wstring &iFunctionName)  throw(invalid_argument);

	//Return float; Argument bool
	void AddFunction(const wstring &iFunctionName, float (T::*iFunction)(bool iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, bool iArgument, float* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, bool iArgument, float* oReturnValue);	
	unsigned GetFunctionPosition_float_bool(const wstring &iFunctionName)  throw(invalid_argument);

	//Return float; Argument int
	void AddFunction(const wstring &iFunctionName, float (T::*iFunction)(int iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, int iArgument, float* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, int iArgument, float* oReturnValue);	
	unsigned GetFunctionPosition_float_int(const wstring &iFunctionName)  throw(invalid_argument);

	//Return float; Argument float
	void AddFunction(const wstring &iFunctionName, float (T::*iFunction)(float iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, float iArgument, float* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, float iArgument, float* oReturnValue);	
	unsigned GetFunctionPosition_float_float(const wstring &iFunctionName)  throw(invalid_argument);

	//Return float; Argument string
	void AddFunction(const wstring &iFunctionName, float (T::*iFunction)(wstring iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, wstring iArgument, float* oReturnValue);
	void RunFunction(const unsigned &iFunctionPosition, wstring iArgument, float* oReturnValue);	
	unsigned GetFunctionPosition_float_string(const wstring &iFunctionName)  throw(invalid_argument);

	//Return string; Argument void
	void AddFunction(const wstring &iFunctionName, wstring (T::*iFunction)())  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, wstring* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, wstring* oReturnValue);	
	unsigned GetFunctionPosition_string_void(const wstring &iFunctionName)  throw(invalid_argument);

	//Return string; Argument bool
	void AddFunction(const wstring &iFunctionName, wstring (T::*iFunction)(bool iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, bool iArgument, wstring* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, bool iArgument, wstring* oReturnValue);	
	unsigned GetFunctionPosition_string_bool(const wstring &iFunctionName)  throw(invalid_argument);

	//Return string; Argument int
	void AddFunction(const wstring &iFunctionName, wstring (T::*iFunction)(int iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, int iArgument, wstring* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, int iArgument, wstring* oReturnValue);	
	unsigned GetFunctionPosition_string_int(const wstring &iFunctionName)  throw(invalid_argument);

	//Return string; Argument float
	void AddFunction(const wstring &iFunctionName, wstring (T::*iFunction)(float iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, float iArgument, wstring* oReturnValue);	
	void RunFunction(const unsigned &iFunctionPosition, float iArgument, wstring* oReturnValue);	
	unsigned GetFunctionPosition_string_float(const wstring &iFunctionName)  throw(invalid_argument);

	//Return string; Argument string
	void AddFunction(const wstring &iFunctionName, wstring (T::*iFunction)(wstring iArgument))  throw(invalid_argument);	
	void RunFunction(const wstring &iFunctionName, wstring iArgument, wstring* oReturnValue);
	void RunFunction(const unsigned &iFunctionPosition, wstring iArgument, wstring* oReturnValue);	
	unsigned GetFunctionPosition_string_string(const wstring &iFunctionName)  throw(invalid_argument);


};

//*****************************************************************************

template<class T>
TFunctionPool<T>::TFunctionPool(T* iWorkingClass) : workingClass(NULL)
	{
	if(iWorkingClass == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::TFunctionPool - iWorkingClass == NULL");

	workingClass = iWorkingClass;
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunctionDefinition(const wstring& iName, const unsigned& iPosition, const CFunctionDefinition::EFunctionArgumentType& iReturnType, const CFunctionDefinition::EFunctionArgumentType& iArgumentType)
	{
	functionDefinitions.insert(make_pair(iName, CFunctionDefinition(iName, iPosition, iReturnType, iArgumentType)));
	}

//*****************************************************************************

template<class T>
bool TFunctionPool<T>::ExistFunction(const wstring& iFunctionName)
	{
	return (functionDefinitions.find(iFunctionName) != functionDefinitions.end());
	}

//*****************************************************************************

template<class T>
CFunctionDefinition TFunctionPool<T>::GetFunctionDefinition(const wstring& iFunctionName)
	{
	map<wstring, CFunctionDefinition>::iterator it = functionDefinitions.find(iFunctionName);
	if(it == functionDefinitions.end())
		throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionDefinition - iFunctionName - Such function does not exist");
	else
		return it->second;
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, void (T::*iFunction)())
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");
	
	AddFunctionDefinition(iFunctionName, function_void_void.size(), CFunctionDefinition::e_Void, CFunctionDefinition::e_Void);

	function_void_void.push_back(TFunction<T, void, void>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_void_void.size(); i++)
		if(function_void_void[i].Name()==iFunctionName)
		{
		 function_void_void[i].RunFunction();
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition)
	{
	function_void_void[iFunctionPosition].RunFunction();
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_void_void(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_void_void.size(); i++)
		if(function_void_void[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_void_void - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, void (T::*iFunction)(bool iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_void_bool.size(), CFunctionDefinition::e_Void, CFunctionDefinition::e_Bool);

	function_void_bool.push_back(TFunction<T, void, bool>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, bool iArgument)
	{
	for(unsigned i=0; i<function_void_bool.size(); i++)
		if(function_void_bool[i].Name()==iFunctionName)
		{
		 function_void_bool[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, bool iArgument)
	{
	function_void_bool[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_void_bool(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_void_bool.size(); i++)
		if(function_void_bool[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_void_bool - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, void (T::*iFunction)(int iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_void_int.size(), CFunctionDefinition::e_Void, CFunctionDefinition::e_Int);

	function_void_int.push_back(TFunction<T, void, int>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, int iArgument)
	{
	for(unsigned i=0; i<function_void_int.size(); i++)
		if(function_void_int[i].Name()==iFunctionName)
		{
		 function_void_int[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, int iArgument)
	{
	function_void_int[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_void_int(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_void_int.size(); i++)
		if(function_void_int[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_void_int - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, void (T::*iFunction)(float iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_void_float.size(), CFunctionDefinition::e_Void, CFunctionDefinition::e_Float);

	function_void_float.push_back(TFunction<T, void, float>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, float iArgument)
	{
	for(unsigned i=0; i<function_void_float.size(); i++)
		if(function_void_float[i].Name()==iFunctionName)
		{
		 function_void_float[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, float iArgument)
	{
	function_void_float[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_void_float(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_void_float.size(); i++)
		if(function_void_float[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_void_float - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, void (T::*iFunction)(wstring iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_void_string.size(), CFunctionDefinition::e_Void, CFunctionDefinition::e_String);

	function_void_string.push_back(TFunction<T, void, wstring>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, wstring iArgument)
	{
	for(unsigned i=0; i<function_void_string.size(); i++)
		if(function_void_string[i].Name()==iFunctionName)
		{
		 function_void_string[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, wstring iArgument)
	{
	function_void_string[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_void_string(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_void_string.size(); i++)
		if(function_void_string[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_void_string - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, bool (T::*iFunction)())
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_bool_void.size(), CFunctionDefinition::e_Bool, CFunctionDefinition::e_Void);

	function_bool_void.push_back(TFunction<T, bool, void>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, bool* oReturnValue)
	{
	for(unsigned i=0; i<function_bool_void.size(); i++)
		if(function_bool_void[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_bool_void[i].RunFunction();
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, bool* oReturnValue)
	{
	*oReturnValue = function_bool_void[iFunctionPosition].RunFunction();
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_bool_void(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_bool_void.size(); i++)
		if(function_bool_void[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_void_string - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, bool (T::*iFunction)(bool iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_bool_bool.size(), CFunctionDefinition::e_Bool, CFunctionDefinition::e_Bool);

	function_bool_bool.push_back(TFunction<T, bool, bool>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, bool iArgument, bool* oReturnValue)
	{
	for(unsigned i=0; i<function_bool_bool.size(); i++)
		if(function_bool_bool[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_bool_bool[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, bool iArgument, bool* oReturnValue)
	{
	*oReturnValue = function_bool_bool[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_bool_bool(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_bool_bool.size(); i++)
		if(function_bool_bool[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_bool_bool - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, bool (T::*iFunction)(int iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_bool_int.size(), CFunctionDefinition::e_Bool, CFunctionDefinition::e_Int);

	function_bool_int.push_back(TFunction<T, bool, int>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, int iArgument, bool* oReturnValue)
	{
	for(unsigned i=0; i<function_bool_int.size(); i++)
		if(function_bool_int[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_bool_int[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, int iArgument, bool* oReturnValue)
	{
	*oReturnValue = function_bool_int[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_bool_int(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_bool_int.size(); i++)
		if(function_bool_int[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_bool_int - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, bool (T::*iFunction)(float iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_bool_float.size(), CFunctionDefinition::e_Bool, CFunctionDefinition::e_Float);

	function_bool_float.push_back(TFunction<T, bool, float>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, float iArgument, bool* oReturnValue)
	{
	for(unsigned i=0; i<function_bool_float.size(); i++)
		if(function_bool_float[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_bool_float[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, float iArgument, bool* oReturnValue)
	{
	*oReturnValue = function_bool_float[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_bool_float(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_bool_float.size(); i++)
		if(function_bool_float[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_bool_float - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, bool (T::*iFunction)(wstring iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_bool_string.size(), CFunctionDefinition::e_Bool, CFunctionDefinition::e_String);

	function_bool_string.push_back(TFunction<T, bool, wstring>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, wstring iArgument, bool* oReturnValue)
	{
	for(unsigned i=0; i<function_bool_string.size(); i++)
		if(function_bool_string[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_bool_string[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, wstring iArgument, bool* oReturnValue)
	{
	*oReturnValue = function_bool_string[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_bool_string(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_bool_string.size(); i++)
		if(function_bool_string[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_bool_string - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, int (T::*iFunction)())
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_int_void.size(), CFunctionDefinition::e_Int, CFunctionDefinition::e_Void);

	function_int_void.push_back(TFunction<T, int, void>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, int* oReturnValue)
	{
	for(unsigned i=0; i<function_int_void.size(); i++)
		if(function_int_void[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_int_void[i].RunFunction();
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, int* oReturnValue)
	{
	*oReturnValue = function_int_void[iFunctionPosition].RunFunction();
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_int_void(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_int_void.size(); i++)
		if(function_int_void[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_int_void - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, int (T::*iFunction)(bool iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_int_bool.size(), CFunctionDefinition::e_Int, CFunctionDefinition::e_Bool);

	function_int_bool.push_back(TFunction<T, int, bool>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, bool iArgument, int* oReturnValue)
	{
	for(unsigned i=0; i<function_int_bool.size(); i++)
		if(function_int_bool[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_int_bool[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, bool iArgument, int* oReturnValue)
	{
	*oReturnValue = function_int_bool[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_int_bool(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_int_bool.size(); i++)
		if(function_int_bool[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_int_bool - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, int (T::*iFunction)(int iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_int_int.size(), CFunctionDefinition::e_Int, CFunctionDefinition::e_Int);

	function_int_int.push_back(TFunction<T, int, int>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, int iArgument, int* oReturnValue)
	{
	for(unsigned i=0; i<function_int_int.size(); i++)
		if(function_int_int[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_int_int[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, int iArgument, int* oReturnValue)
	{
	*oReturnValue = function_int_int[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_int_int(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_int_int.size(); i++)
		if(function_int_int[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_int_int - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, int (T::*iFunction)(float iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_int_float.size(), CFunctionDefinition::e_Int, CFunctionDefinition::e_Float);

	function_int_float.push_back(TFunction<T, int, float>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, float iArgument, int* oReturnValue)
	{
	for(unsigned i=0; i<function_int_float.size(); i++)
		if(function_int_float[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_int_float[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, float iArgument, int* oReturnValue)
	{
	*oReturnValue = function_int_float[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_int_float(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_int_float.size(); i++)
		if(function_int_float[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_int_float - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, int (T::*iFunction)(wstring iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_int_string.size(), CFunctionDefinition::e_Int, CFunctionDefinition::e_String);

	function_int_string.push_back(TFunction<T, int, wstring>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, wstring iArgument, int* oReturnValue)
	{
	for(unsigned i=0; i<function_int_string.size(); i++)
		if(function_int_string[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_int_string[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, wstring iArgument, int* oReturnValue)
	{
	*oReturnValue = function_int_string[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_int_string(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_int_string.size(); i++)
		if(function_int_string[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_int_string - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, float (T::*iFunction)())
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_float_void.size(), CFunctionDefinition::e_Float, CFunctionDefinition::e_Void);

	function_float_void.push_back(TFunction<T, float, void>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, float* oReturnValue)
	{
	for(unsigned i=0; i<function_float_void.size(); i++)
		if(function_float_void[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_float_void[i].RunFunction();
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, float* oReturnValue)
	{
	*oReturnValue = function_float_void[iFunctionPosition].RunFunction();
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_float_void(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_float_void.size(); i++)
		if(function_float_void[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_float_void - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, float (T::*iFunction)(bool iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_float_bool.size(), CFunctionDefinition::e_Float, CFunctionDefinition::e_Bool);

	function_float_bool.push_back(TFunction<T, float, bool>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, bool iArgument, float* oReturnValue)
	{
	for(unsigned i=0; i<function_float_bool.size(); i++)
		if(function_float_bool[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_float_bool[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, bool iArgument, float* oReturnValue)
	{
	*oReturnValue = function_float_bool[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_float_bool(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_float_bool.size(); i++)
		if(function_float_bool[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_float_bool - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, float (T::*iFunction)(int iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_float_int.size(), CFunctionDefinition::e_Float, CFunctionDefinition::e_Int);

	function_float_int.push_back(TFunction<T, float, int>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, int iArgument, float* oReturnValue)
	{
	for(unsigned i=0; i<function_float_int.size(); i++)
		if(function_float_int[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_float_int[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, int iArgument, float* oReturnValue)
	{
	*oReturnValue = function_float_int[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_float_int(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_float_int.size(); i++)
		if(function_float_int[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_float_int - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, float (T::*iFunction)(float iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_float_float.size(), CFunctionDefinition::e_Float, CFunctionDefinition::e_Float);

	function_float_float.push_back(TFunction<T, float, float>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, float iArgument, float* oReturnValue)
	{
	for(unsigned i=0; i<function_float_float.size(); i++)
		if(function_float_float[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_float_float[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, float iArgument, float* oReturnValue)
	{
	*oReturnValue = function_float_float[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_float_float(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_float_float.size(); i++)
		if(function_float_float[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_float_float - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, float (T::*iFunction)(wstring iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_float_string.size(), CFunctionDefinition::e_Float, CFunctionDefinition::e_String);

	function_float_string.push_back(TFunction<T, float, wstring>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, wstring iArgument, float* oReturnValue)
	{
	for(unsigned i=0; i<function_float_string.size(); i++)
		if(function_float_string[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_float_string[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, wstring iArgument, float* oReturnValue)
	{
	*oReturnValue = function_float_string[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_float_string(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_float_string.size(); i++)
		if(function_float_string[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_float_string - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, wstring (T::*iFunction)())
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_string_void.size(), CFunctionDefinition::e_String, CFunctionDefinition::e_Void);

	function_string_void.push_back(TFunction<T, wstring, void>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, wstring* oReturnValue)
	{
	for(unsigned i=0; i<function_string_void.size(); i++)
		if(function_string_void[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_string_void[i].RunFunction();
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, wstring* oReturnValue)
	{
	*oReturnValue = function_string_void[iFunctionPosition].RunFunction();
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_string_void(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_string_void.size(); i++)
		if(function_string_void[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_string_void - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, wstring (T::*iFunction)(bool iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_string_bool.size(), CFunctionDefinition::e_String, CFunctionDefinition::e_Bool);

	function_string_bool.push_back(TFunction<T, wstring, bool>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, bool iArgument, wstring* oReturnValue)
	{
	for(unsigned i=0; i<function_string_bool.size(); i++)
		if(function_string_bool[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_string_bool[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, bool iArgument, wstring* oReturnValue)
	{
	*oReturnValue = function_string_bool[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_string_bool(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_string_bool.size(); i++)
		if(function_string_bool[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_string_bool - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, wstring (T::*iFunction)(int iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_string_int.size(), CFunctionDefinition::e_String, CFunctionDefinition::e_Int);

	function_string_int.push_back(TFunction<T, wstring, int>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, int iArgument, wstring* oReturnValue)
	{
	for(unsigned i=0; i<function_string_int.size(); i++)
		if(function_string_int[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_string_int[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, int iArgument, wstring* oReturnValue)
	{
	*oReturnValue = function_string_int[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_string_int(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_string_int.size(); i++)
		if(function_string_int[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_string_int - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, wstring (T::*iFunction)(float iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_string_float.size(), CFunctionDefinition::e_String, CFunctionDefinition::e_Float);

	function_string_float.push_back(TFunction<T, wstring, float>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, float iArgument, wstring* oReturnValue)
	{
	for(unsigned i=0; i<function_string_float.size(); i++)
		if(function_string_float[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_string_float[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, float iArgument, wstring* oReturnValue)
	{
	*oReturnValue = function_string_float[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_string_float(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_string_float.size(); i++)
		if(function_string_float[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_string_float - iFunctionName - cannot find such function");
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::AddFunction(const wstring &iFunctionName, wstring (T::*iFunction)(wstring iArgument))
	{
	if(iFunction == NULL)
		throw invalid_argument("Regina::Script::TFunctionPool::AddFunction - iFunction == NULL");

	AddFunctionDefinition(iFunctionName, function_string_string.size(), CFunctionDefinition::e_String, CFunctionDefinition::e_String);

	function_string_string.push_back(TFunction<T, wstring, wstring>(iFunctionName, iFunction, workingClass));
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const wstring &iFunctionName, wstring iArgument, wstring* oReturnValue)
	{
	for(unsigned i=0; i<function_string_string.size(); i++)
		if(function_string_string[i].Name()==iFunctionName)
		{
		 *oReturnValue = function_string_string[i].RunFunction(iArgument);
		 return;
		}	
	}

//*****************************************************************************

template<class T>
void TFunctionPool<T>::RunFunction(const unsigned &iFunctionPosition, wstring iArgument, wstring* oReturnValue)
	{
	*oReturnValue = function_string_string[iFunctionPosition].RunFunction(iArgument);
	}

//*****************************************************************************

template<class T>
unsigned TFunctionPool<T>::GetFunctionPosition_string_string(const wstring &iFunctionName)
	{
	for(unsigned i=0; i<function_string_string.size(); i++)
		if(function_string_string[i].Name()==iFunctionName)
			return i;

	throw invalid_argument("Regina::Script::TFunctionPool::GetFunctionPosition_string_string - iFunctionName - cannot find such function");
	}

//*****************************************************************************

	
}

}

#endif
