/*
    TScriptManager.h - Contains template TScriptManager which is responsible for managing different scripts for a single class.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTMANAGER_H
#define REGINA_SCRIPT_TSCRIPTMANAGER_H

#pragma warning( push )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4290 )
#pragma warning( disable : 4129 )

#include <map>
using namespace std;

#include <TScript.h>
#include <CVariablePool.h>
#include <TFunctionPool.h>
#include <CException_ScriptError.h>
#include <CText.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//TScriptManager template.													  |
//T1 class type.															  |
//----------------------------------------------------------------------------|
template<class T>
class TScriptManager
{
	map<wstring, TScript<T>*>script;
	CVariablePool*			variablePool;
	TFunctionPool<T>*		functionPool;

	TScriptManager<T>(const TScriptManager<T>&) {}
	TScriptManager<T>& operator=(const TScriptManager<T>&) {}

	public:
	TScriptManager(T* iClass)	throw(invalid_argument);
	~TScriptManager();

	void LoadScript(const wstring& iName)				throw(invalid_argument, CException_ScriptError_MissingVariableName, CException_ScriptError_SyntaxError, CException_ScriptError_UndefinedSymbol);
	void RunScript(const wstring& iName)				throw(invalid_argument);
	void RunScript(const vector<wstring>& iScriptText)	throw(invalid_argument);
	void RunScriptLine(const wstring& iScriptText)		throw(CException_ScriptError_MissingVariableName, CException_ScriptError_SyntaxError, CException_ScriptError_UndefinedSymbol);

	CVariablePool&			VariablePool() { return *variablePool; }
	TFunctionPool<T>&		FunctionPool() { return *functionPool; }
};

//*****************************************************************************

template<class T>
TScriptManager<T>::TScriptManager(T* iClass) 
	{ 
	if(iClass == NULL)
		throw invalid_argument("TScriptManager<T>::TScriptManager - iClass == NULL");

	variablePool = new CVariablePool();
	functionPool = new TFunctionPool<T>(iClass);
	}

//*****************************************************************************

template<class T>
TScriptManager<T>::~TScriptManager()
	{
	delete variablePool;
	delete functionPool;
	map<wstring, TScript<T>*>::iterator it = script.begin();
	while(it!=script.end())
		{
		delete it->second;
		it++;
		}
	}

//*****************************************************************************

template<class T>
void TScriptManager<T>::LoadScript(const wstring& iName)
	{
	if(script.find(iName) == script.end())
		{
		TScript<T>* c_script = new TScript<T>(iName, variablePool, functionPool);
		
		try	{
			CText scriptText;
			scriptText.Load(L"\Data\\Script\\" + iName);
			c_script->Load(scriptText);
			}
		catch(CException_ScriptError& Exception)
			{
			delete c_script;
			throw Exception;
			}

		script.insert(make_pair(iName, c_script));
		}
	}

//*****************************************************************************

template<class T>
void TScriptManager<T>::RunScript(const wstring& iName)
	{
	map<wstring, TScript<T>*>::iterator it = script.find(iName);
	if(it != script.end())
		{
		it->second->Run();
		}
	else
		{
		TScript<T>* c_script = new TScript<T>(iName, variablePool, functionPool);
		
		try	{
			CText scriptText;
			scriptText.Load(L"\Data\\Script\\" + iName);
			c_script->Load(scriptText);
			}
		catch(CException_ScriptError& Exception)
			{
			delete c_script;
			throw Exception;
			}

		c_script->Run();

		script.insert(make_pair(iName, c_script));
		}

	}

//*****************************************************************************

template<class T>
void TScriptManager<T>::RunScriptLine(const wstring& iName)
	{
	TScript<T>* c_script = new TScript<T>(iName, variablePool, functionPool);
		
	try	{
		vector<wstring> scriptText;
		scriptText.push_back(iName);
		c_script->Load(scriptText);
		c_script->Run();
		}
	catch(CException_ScriptError& Exception)
		{
		delete c_script;
		throw Exception;
		}
	delete c_script;
	}

//*****************************************************************************

template<class T>
void TScriptManager<T>::RunScript(const vector<wstring>& iScriptText)
	{
	TScript<T>* c_script = new TScript<T>(L"", variablePool, functionPool);
		
	try	{
		c_script->Load(iScriptText);
		c_script->Run();
		}
	catch(CException_ScriptError& Exception)
		{
		delete c_script;
		throw Exception;
		}
	delete c_script;
	}

//*****************************************************************************

}

}

#pragma warning( pop ) 

#endif