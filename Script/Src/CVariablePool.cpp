/*
    CVariablePool.cpp - Contains class CVariablePool implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CVariablePool.h>
using namespace Regina::Script;

//*****************************************************************************

CVariablePool::~CVariablePool()
	{
	for(unsigned i=0; i<workingVariable_bool.size(); i++)
		if(workingVariable_bool[i] != NULL)
			delete workingVariable_bool[i];

	for(unsigned i=0; i<workingVariable_int.size(); i++)
		if(workingVariable_int[i] != NULL)
			delete workingVariable_int[i];

	for(unsigned i=0; i<workingVariable_float.size(); i++)
		if(workingVariable_float[i] != NULL)
			delete workingVariable_float[i];

	for(unsigned i=0; i<workingVariable_string.size(); i++)
		if(workingVariable_string[i] != NULL)
			delete workingVariable_string[i];

	for(unsigned i=0; i<localVariable_bool.size(); i++)
		if(localVariable_bool[i] != NULL)
			delete localVariable_bool[i];

	for(unsigned i=0; i<localVariable_int.size(); i++)
		if(localVariable_int[i] != NULL)
			delete localVariable_int[i];

	for(unsigned i=0; i<localVariable_float.size(); i++)
		if(localVariable_float[i] != NULL)
			delete localVariable_float[i];

	for(unsigned i=0; i<localVariable_string.size(); i++)
		if(localVariable_string[i] != NULL)
			delete localVariable_string[i];
	}

//*****************************************************************************

CVariablePool::CGlobalVariables::~CGlobalVariables()
	{
	for(unsigned i=0; i<globalVariable_bool.size(); i++)
		if(globalVariable_bool[i] != NULL)
			delete globalVariable_bool[i];

	for(unsigned i=0; i<globalVariable_int.size(); i++)
		if(globalVariable_int[i] != NULL)
			delete globalVariable_int[i];

	for(unsigned i=0; i<globalVariable_float.size(); i++)
		if(globalVariable_float[i] != NULL)
			delete globalVariable_float[i];

	for(unsigned i=0; i<globalVariable_string.size(); i++)
		if(globalVariable_string[i] != NULL)
			delete globalVariable_string[i];
	}

//*****************************************************************************

void CVariablePool::CheckVariableName(const wstring& iVariableName)
	{
	if(iVariableName == L"true" || iVariableName == L"false" || iVariableName == L"if" || iVariableName == L"while" || iVariableName == L"for" || iVariableName == L"string" || iVariableName == L"float" || iVariableName == L"bool" || iVariableName == L"int" || iVariableName == L"{" || iVariableName == L"}" || iVariableName == L"(" || iVariableName == L")" || iVariableName == L"void")
		throw invalid_argument("CVariablePool::CheckVariableName - argument iVariableName - this name is reserved for system");
	}

//*****************************************************************************

void CVariablePool::AddLocalVariable(const wstring &iVariableName, bool* iPntrToVariable) 
	{
	CheckVariableName(iVariableName);

	if(ExistLocalVariable_bool(iVariableName))
		throw invalid_argument("CVariablePool::AddLocalVariable - argument iVariableName - This variable is already created.");

	localVariable_bool.push_back(new TVariable<bool>(iVariableName, iPntrToVariable));
	}

//*****************************************************************************

void CVariablePool::AddLocalVariable(const wstring &iVariableName, const bool& iValue, bool* iPntrToVariable)
	{
	CheckVariableName(iVariableName);

	if(ExistLocalVariable_bool(iVariableName))
		throw invalid_argument("CVariablePool::AddLocalVariable - argument iVariableName - This variable is already created.");

	localVariable_bool.push_back(new TVariable<bool>(iVariableName, iValue, iPntrToVariable));
	}

//*****************************************************************************

void CVariablePool::AddGlobalVariable(const wstring &iVariableName, const bool& iValue)
	{
	CheckVariableName(iVariableName);

	for(unsigned i=0; i<globalVariables.globalVariable_bool.size(); i++)
		if(globalVariables.globalVariable_bool[i]->Name() == iVariableName)
			{
			globalVariables.globalVariable_bool[i]->SetValue(iValue);
			return;
			}

	globalVariables.globalVariable_bool.push_back(new TVariable<bool>(iVariableName, iValue));
	}

//*****************************************************************************

void CVariablePool::GetVariableValue(const wstring &iVariableName, bool& oValue)
	{
	for(unsigned i=0; i<localVariable_bool.size(); i++)
		if(localVariable_bool[i]->Name() == iVariableName)
			{
			oValue = localVariable_bool[i]->Value();
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_bool.size(); i++)
		if(globalVariables.globalVariable_bool[i]->Name() == iVariableName)
			{
			oValue = globalVariables.globalVariable_bool[i]->Value();
			return;
			}

	}

//*****************************************************************************

void CVariablePool::SetVariableValue(const wstring &iVariableName, const bool& iValue)
	{
	for(unsigned i=0; i<localVariable_bool.size(); i++)
		if(localVariable_bool[i]->Name() == iVariableName)
			{
			localVariable_bool[i]->SetValue(iValue);
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_bool.size(); i++)
		if(globalVariables.globalVariable_bool[i]->Name() == iVariableName)
			{
			globalVariables.globalVariable_bool[i]->SetValue(iValue);
			return;
			}
	}

//*****************************************************************************

void CVariablePool::GetPointerToVariable(const wstring &iVariableName, bool*& oPntrToVariable)
	{
	for(unsigned i=0; i<localVariable_bool.size(); i++)
		if(localVariable_bool[i]->Name() == iVariableName)
			{
			oPntrToVariable = localVariable_bool[i]->PointerToVariable();
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_bool.size(); i++)
		if(globalVariables.globalVariable_bool[i]->Name() == iVariableName)
			{
			oPntrToVariable = globalVariables.globalVariable_bool[i]->PointerToVariable();
			return;
			}
	}

//*****************************************************************************

void CVariablePool::AddLocalVariable(const wstring &iVariableName, int* iPntrToVariable) 
	{
	CheckVariableName(iVariableName);

	if(ExistLocalVariable_int(iVariableName))
		throw invalid_argument("CVariablePool::AddLocalVariable - argument iVariableName - This variable is already created.");

	localVariable_int.push_back(new TVariable<int>(iVariableName, iPntrToVariable));
	}

//*****************************************************************************

void CVariablePool::AddLocalVariable(const wstring &iVariableName, const int& iValue, int* iPntrToVariable)
	{
	CheckVariableName(iVariableName);

	if(ExistLocalVariable_int(iVariableName))
		throw invalid_argument("CVariablePool::AddLocalVariable - argument iVariableName - This variable is already created.");

	localVariable_int.push_back(new TVariable<int>(iVariableName, iValue, iPntrToVariable));
	}

//*****************************************************************************

void CVariablePool::AddGlobalVariable(const wstring &iVariableName, const int& iValue)
	{
	CheckVariableName(iVariableName);
	for(unsigned i=0; i<globalVariables.globalVariable_int.size(); i++)
		if(globalVariables.globalVariable_int[i]->Name() == iVariableName)
			{
			globalVariables.globalVariable_int[i]->SetValue(iValue);
			return;
			}

	globalVariables.globalVariable_int.push_back(new TVariable<int>(iVariableName, iValue));
	}

//*****************************************************************************

void CVariablePool::GetVariableValue(const wstring &iVariableName, int& oValue)
	{
	for(unsigned i=0; i<localVariable_int.size(); i++)
		if(localVariable_int[i]->Name() == iVariableName)
			{
			oValue = localVariable_int[i]->Value();
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_int.size(); i++)
		if(globalVariables.globalVariable_int[i]->Name() == iVariableName)
			{
			oValue = globalVariables.globalVariable_int[i]->Value();
			return;
			}

	}

//*****************************************************************************

void CVariablePool::SetVariableValue(const wstring &iVariableName, const int& iValue)
	{
	for(unsigned i=0; i<localVariable_int.size(); i++)
		if(localVariable_int[i]->Name() == iVariableName)
			{
			localVariable_int[i]->SetValue(iValue);
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_int.size(); i++)
		if(globalVariables.globalVariable_int[i]->Name() == iVariableName)
			{
			globalVariables.globalVariable_int[i]->SetValue(iValue);
			return;
			}
	}

//*****************************************************************************

void CVariablePool::GetPointerToVariable(const wstring &iVariableName, int*& oPntrToVariable)
	{
	for(unsigned i=0; i<localVariable_int.size(); i++)
		if(localVariable_int[i]->Name() == iVariableName)
			{
			oPntrToVariable = localVariable_int[i]->PointerToVariable();
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_int.size(); i++)
		if(globalVariables.globalVariable_int[i]->Name() == iVariableName)
			{
			oPntrToVariable = globalVariables.globalVariable_int[i]->PointerToVariable();
			return;
			}
	}

//*****************************************************************************

void CVariablePool::AddLocalVariable(const wstring &iVariableName, float* iPntrToVariable) 
	{
	CheckVariableName(iVariableName);

	if(ExistLocalVariable_float(iVariableName))
		throw invalid_argument("CVariablePool::AddLocalVariable - argument iVariableName - This variable is already created.");

	localVariable_float.push_back(new TVariable<float>(iVariableName, iPntrToVariable));
	}

//*****************************************************************************

void CVariablePool::AddLocalVariable(const wstring &iVariableName, const float& iValue, float* iPntrToVariable)
	{
	CheckVariableName(iVariableName);

	if(ExistLocalVariable_float(iVariableName))
		throw invalid_argument("CVariablePool::AddLocalVariable - argument iVariableName - This variable is already created.");

	localVariable_float.push_back(new TVariable<float>(iVariableName, iValue, iPntrToVariable));
	}

//*****************************************************************************

void CVariablePool::AddGlobalVariable(const wstring &iVariableName, const float& iValue)
	{
	CheckVariableName(iVariableName);
	for(unsigned i=0; i<globalVariables.globalVariable_float.size(); i++)
		if(globalVariables.globalVariable_float[i]->Name() == iVariableName)
			{
			globalVariables.globalVariable_float[i]->SetValue(iValue);
			return;
			}

	globalVariables.globalVariable_float.push_back(new TVariable<float>(iVariableName, iValue));
	}

//*****************************************************************************

void CVariablePool::GetVariableValue(const wstring &iVariableName, float& oValue)
	{
	for(unsigned i=0; i<localVariable_float.size(); i++)
		if(localVariable_float[i]->Name() == iVariableName)
			{
			oValue = localVariable_float[i]->Value();
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_float.size(); i++)
		if(globalVariables.globalVariable_float[i]->Name() == iVariableName)
			{
			oValue = globalVariables.globalVariable_float[i]->Value();
			return;
			}

	}

//*****************************************************************************

void CVariablePool::SetVariableValue(const wstring &iVariableName, const float& iValue)
	{
	for(unsigned i=0; i<localVariable_float.size(); i++)
		if(localVariable_float[i]->Name() == iVariableName)
			{
			localVariable_float[i]->SetValue(iValue);
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_float.size(); i++)
		if(globalVariables.globalVariable_float[i]->Name() == iVariableName)
			{
			globalVariables.globalVariable_float[i]->SetValue(iValue);
			return;
			}
	}

//*****************************************************************************

void CVariablePool::GetPointerToVariable(const wstring &iVariableName, float*& oPntrToVariable)
	{
	for(unsigned i=0; i<localVariable_float.size(); i++)
		if(localVariable_float[i]->Name() == iVariableName)
			{
			oPntrToVariable = localVariable_float[i]->PointerToVariable();
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_int.size(); i++)
		if(globalVariables.globalVariable_int[i]->Name() == iVariableName)
			{
			oPntrToVariable = globalVariables.globalVariable_float[i]->PointerToVariable();
			return;
			}
	}

//*****************************************************************************

void CVariablePool::AddLocalVariable(const wstring &iVariableName, wstring* iPntrToVariable) 
	{
	CheckVariableName(iVariableName);

	if(ExistLocalVariable_string(iVariableName))
		throw invalid_argument("CVariablePool::AddLocalVariable - argument iVariableName - This variable is already created.");

	localVariable_string.push_back(new TVariable<wstring>(iVariableName, iPntrToVariable));
	}

//*****************************************************************************

void CVariablePool::AddLocalVariable(const wstring &iVariableName, const wstring& iValue, wstring* iPntrToVariable)
	{
	CheckVariableName(iVariableName);

	if(ExistLocalVariable_string(iVariableName))
		throw invalid_argument("CVariablePool::AddLocalVariable - argument iVariableName - This variable is already created.");

	localVariable_string.push_back(new TVariable<wstring>(iVariableName, iValue, iPntrToVariable));
	}

//*****************************************************************************

void CVariablePool::AddGlobalVariable(const wstring &iVariableName, const wstring& iValue)
	{
	CheckVariableName(iVariableName);
	for(unsigned i=0; i<globalVariables.globalVariable_string.size(); i++)
		if(globalVariables.globalVariable_string[i]->Name() == iVariableName)
			{
			globalVariables.globalVariable_string[i]->SetValue(iValue);
			return;
			}

	globalVariables.globalVariable_string.push_back(new TVariable<wstring>(iVariableName, iValue));
	}

//*****************************************************************************

void CVariablePool::GetVariableValue(const wstring &iVariableName, wstring& oValue)
	{
	for(unsigned i=0; i<localVariable_string.size(); i++)
		if(localVariable_string[i]->Name() == iVariableName)
			{
			oValue = localVariable_string[i]->Value();
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_string.size(); i++)
		if(globalVariables.globalVariable_string[i]->Name() == iVariableName)
			{
			oValue = globalVariables.globalVariable_string[i]->Value();
			return;
			}

	}

//*****************************************************************************

void CVariablePool::SetVariableValue(const wstring &iVariableName, const wstring& iValue)
	{
	for(unsigned i=0; i<localVariable_string.size(); i++)
		if(localVariable_string[i]->Name() == iVariableName)
			{
			localVariable_string[i]->SetValue(iValue);
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_string.size(); i++)
		if(globalVariables.globalVariable_string[i]->Name() == iVariableName)
			{
			globalVariables.globalVariable_string[i]->SetValue(iValue);
			return;
			}
	}

//*****************************************************************************

void CVariablePool::GetPointerToVariable(const wstring &iVariableName, wstring*& oPntrToVariable)
	{
	oPntrToVariable = NULL;
	for(unsigned i=0; i<localVariable_string.size(); i++)
		if(localVariable_string[i]->Name() == iVariableName)
			{
			oPntrToVariable = localVariable_string[i]->PointerToVariable();
			return;
			}

	for(unsigned i=0; i<globalVariables.globalVariable_string.size(); i++)
		if(globalVariables.globalVariable_string[i]->Name() == iVariableName)
			{
			oPntrToVariable = globalVariables.globalVariable_string[i]->PointerToVariable();
			return;
			}
	}

//*****************************************************************************

void CVariablePool::AddWorkingVariable(bool* iWorkingVariable)
	{
	workingVariable_bool.push_back(iWorkingVariable);
	}

//*****************************************************************************

void CVariablePool::AddWorkingVariable(int* iWorkingVariable)
	{
	workingVariable_int.push_back(iWorkingVariable);
	}

//*****************************************************************************

void CVariablePool::AddWorkingVariable(float* iWorkingVariable)
	{
	workingVariable_float.push_back(iWorkingVariable);
	}

//*****************************************************************************

void CVariablePool::AddWorkingVariable(wstring* iWorkingVariable)
	{
	workingVariable_string.push_back(iWorkingVariable);
	}

//*****************************************************************************

bool CVariablePool::ExistVariable(const wstring &iVariableName) const
	{
	return (ExistLocalVariable(iVariableName) || ExistGlobalVariable(iVariableName));
	}

//*****************************************************************************

bool CVariablePool::ExistVariable_bool(const wstring &iVariableName) const
	{
	if(ExistLocalVariable_bool(iVariableName) == true || ExistGlobalVariable_bool(iVariableName) == true)
		return true;
	else
		return false;
	}

//*****************************************************************************

bool CVariablePool::ExistVariable_int(const wstring &iVariableName)	const
	{
	if(ExistLocalVariable_int(iVariableName) == true || ExistGlobalVariable_int(iVariableName) == true)
		return true;
	else
		return false;
	}

//*****************************************************************************

bool CVariablePool::ExistVariable_float(const wstring &iVariableName) const
	{
	if(ExistLocalVariable_float(iVariableName) == true || ExistGlobalVariable_float(iVariableName) == true)
		return true;
	else
		return false;
	}

//*****************************************************************************

bool CVariablePool::ExistVariable_string(const wstring &iVariableName) const
	{
	if(ExistLocalVariable_string(iVariableName) == true || ExistGlobalVariable_string(iVariableName) == true)
		return true;
	else
		return false;
	}

//*****************************************************************************

bool CVariablePool::ExistLocalVariable(const wstring &iVariableName) const
	{
	return (ExistLocalVariable_bool(iVariableName) || ExistLocalVariable_int(iVariableName) || ExistLocalVariable_float(iVariableName) || ExistLocalVariable_string(iVariableName));
	}

//*****************************************************************************

bool CVariablePool::ExistLocalVariable_bool(const wstring &iVariableName) const
	{
	for(unsigned i=0; i<localVariable_bool.size(); i++)
		if(localVariable_bool[i]->Name() == iVariableName)
			return true;

	return false;
	}

//*****************************************************************************

bool CVariablePool::ExistLocalVariable_int(const wstring &iVariableName) const
	{
	for(unsigned i=0; i<localVariable_int.size(); i++)
		if(localVariable_int[i]->Name() == iVariableName)
			return true;

	return false;
	}

//*****************************************************************************

bool CVariablePool::ExistLocalVariable_float(const wstring &iVariableName) const
	{
	for(unsigned i=0; i<localVariable_float.size(); i++)
		if(localVariable_float[i]->Name() == iVariableName)
			return true;

	return false;
	}

//*****************************************************************************

bool CVariablePool::ExistLocalVariable_string(const wstring &iVariableName) const
	{
	for(unsigned i=0; i<localVariable_string.size(); i++)
		if(localVariable_string[i]->Name() == iVariableName)
			return true;

	return false;
	}

//*****************************************************************************

bool CVariablePool::ExistGlobalVariable(const wstring &iVariableName) const
	{
	return (ExistGlobalVariable_bool(iVariableName) || ExistGlobalVariable_int(iVariableName) || ExistGlobalVariable_float(iVariableName) || ExistGlobalVariable_string(iVariableName));
	}

//*****************************************************************************

bool CVariablePool::ExistGlobalVariable_bool(const wstring &iVariableName) const
	{
	for(unsigned i=0; i<globalVariables.globalVariable_bool.size(); i++)
		if(globalVariables.globalVariable_bool[i]->Name() == iVariableName)
			return true;

	return false;
	}

//*****************************************************************************

bool CVariablePool::ExistGlobalVariable_int(const wstring &iVariableName) const
	{
	for(unsigned i=0; i<globalVariables.globalVariable_int.size(); i++)
		if(globalVariables.globalVariable_int[i]->Name() == iVariableName)
			return true;

	return false;
	}

//*****************************************************************************

bool CVariablePool::ExistGlobalVariable_float(const wstring &iVariableName) const
	{
	for(unsigned i=0; i<globalVariables.globalVariable_float.size(); i++)
		if(globalVariables.globalVariable_float[i]->Name() == iVariableName)
			return true;

	return false;
	}

//*****************************************************************************

bool CVariablePool::ExistGlobalVariable_string(const wstring &iVariableName) const
	{
	for(unsigned i=0; i<globalVariables.globalVariable_string.size(); i++)
		if(globalVariables.globalVariable_string[i]->Name() == iVariableName)
			return true;

	return false;
	}

//*****************************************************************************

void CVariablePool::GetInitializingScriptText(vector<wstring>& oScriptText)
	{

	for(unsigned i=0; i<localVariable_bool.size(); i++)
		{
		wostringstream os;
		os << L"bool " << localVariable_bool[i]->Name() << L"(" << localVariable_bool[i]->Value() << L");";
		oScriptText.push_back(os.str());
		}

	for(unsigned i=0; i<localVariable_int.size(); i++)
		{
		wostringstream os;
		os << L"int " << localVariable_int[i]->Name() << L"(" << localVariable_int[i]->Value() << L");";
		oScriptText.push_back(os.str());
		}

	for(unsigned i=0; i<localVariable_float.size(); i++)
		{
		wostringstream os;
		os << L"float " << localVariable_float[i]->Name() << L"(" << localVariable_float[i]->Value() << L");";
		oScriptText.push_back(os.str());
		}

	for(unsigned i=0; i<localVariable_string.size(); i++)
		{
		wostringstream os;
		os << L"string " << localVariable_string[i]->Name() << L"(\"" << localVariable_string[i]->Value() << L"\");";
		oScriptText.push_back(os.str());
		}
	}

//*****************************************************************************

CVariablePool::CGlobalVariables	CVariablePool::globalVariables;

//*****************************************************************************


