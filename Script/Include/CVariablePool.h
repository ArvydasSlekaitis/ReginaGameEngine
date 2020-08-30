/*
    CVariablePool.h - Contains class CVariablePool.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CVARIABLEPOOL_H_H
#define REGINA_SCRIPT_CVARIABLEPOOL_H_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <vector>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
using namespace std;

#include <TVariable.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//CVariablePool class.														  |
//----------------------------------------------------------------------------|
class CVariablePool
{
	vector<TVariable<bool>* >	localVariable_bool;
	vector<TVariable<int>* >	localVariable_int;
	vector<TVariable<float>* >	localVariable_float;
	vector<TVariable<wstring>* >localVariable_string;

	vector<bool*>				workingVariable_bool;
	vector<int*>				workingVariable_int;
	vector<float*>				workingVariable_float;
	vector<wstring*>			workingVariable_string;

	static struct CGlobalVariables
		{
		vector<TVariable<bool>* >	globalVariable_bool;
		vector<TVariable<int>* >	globalVariable_int;
		vector<TVariable<float>* >	globalVariable_float;
		vector<TVariable<wstring>* >globalVariable_string;
		~CGlobalVariables();
		} globalVariables;

	void CheckVariableName(const wstring& iVariableName) throw(invalid_argument);

public:
	CVariablePool() {}
	~CVariablePool();

	void GetInitializingScriptText(vector<wstring>& oScriptText);

	//bool variable
	void AddLocalVariable(const wstring &iVariableName, bool* iPntrToVariable = NULL) throw(invalid_argument);
	void AddLocalVariable(const wstring &iVariableName, const bool& iValue, bool* iPntrToVariable = NULL) throw(invalid_argument);
	void AddGlobalVariable(const wstring &iVariableName, const bool& iValue) throw(invalid_argument);
	void GetVariableValue(const wstring &iVariableName, bool& oValue);		
	void SetVariableValue(const wstring &iVariableName, const bool& iValue);

	//int variable
	void AddLocalVariable(const wstring &iVariableName, int* iPntrToVariable = NULL) throw(invalid_argument);
	void AddLocalVariable(const wstring &iVariableName, const int& iValue, int* iPntrToVariable = NULL) throw(invalid_argument);
	void AddGlobalVariable(const wstring &iVariableName, const int& iValue) throw(invalid_argument);
	void GetVariableValue(const wstring &iVariableName, int& oValue);		
	void SetVariableValue(const wstring &iVariableName, const int& iValue);

	//float variable
	void AddLocalVariable(const wstring &iVariableName, float* iPntrToVariable = NULL) throw(invalid_argument);
	void AddLocalVariable(const wstring &iVariableName, const float& iValue, float* iPntrToVariable = NULL) throw(invalid_argument);
	void AddGlobalVariable(const wstring &iVariableName, const float& iValue) throw(invalid_argument);
	void GetVariableValue(const wstring &iVariableName, float& oValue);		
	void SetVariableValue(const wstring &iVariableName, const float& iValue);

	//string variable
	void AddLocalVariable(const wstring &iVariableName, wstring* iPntrToVariable = NULL) throw(invalid_argument);
	void AddLocalVariable(const wstring &iVariableName, const wstring& iValue, wstring* iPntrToVariable = NULL) throw(invalid_argument);
	void AddGlobalVariable(const wstring &iVariableName, const wstring& iValue) throw(invalid_argument);
	void GetVariableValue(const wstring &iVariableName, wstring& oValue);		
	void SetVariableValue(const wstring &iVariableName, const wstring& iValue);

	bool ExistVariable(const wstring &iVariableName)		const;
	bool ExistVariable_bool(const wstring &iVariableName)	const;
	bool ExistVariable_int(const wstring &iVariableName)	const;
	bool ExistVariable_float(const wstring &iVariableName)	const;
	bool ExistVariable_string(const wstring &iVariableName)	const;

	bool ExistLocalVariable(const wstring &iVariableName)		const;
	bool ExistLocalVariable_bool(const wstring &iVariableName)	const;
	bool ExistLocalVariable_int(const wstring &iVariableName)	const;
	bool ExistLocalVariable_float(const wstring &iVariableName)	const;
	bool ExistLocalVariable_string(const wstring &iVariableName)const;

	bool ExistGlobalVariable(const wstring &iVariableName)		const;
	bool ExistGlobalVariable_bool(const wstring &iVariableName)	const;
	bool ExistGlobalVariable_int(const wstring &iVariableName)	const;
	bool ExistGlobalVariable_float(const wstring &iVariableName)const;
	bool ExistGlobalVariable_string(const wstring &iVariableName)const;

	void GetPointerToVariable(const wstring &iVariableName, bool*& oPntrToVariable);
	void GetPointerToVariable(const wstring &iVariableName, int*& oPntrToVariable);
	void GetPointerToVariable(const wstring &iVariableName, float*& oPntrToVariable);
	void GetPointerToVariable(const wstring &iVariableName, wstring*& oPntrToVariable);

	void AddWorkingVariable(bool* iWorkingVariable);
	void AddWorkingVariable(int* iWorkingVariable);
	void AddWorkingVariable(float* iWorkingVariable);
	void AddWorkingVariable(wstring* iWorkingVariable);


};
//*****************************************************************************


}

}

#pragma warning( pop )

#endif