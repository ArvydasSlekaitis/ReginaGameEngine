/*
    TScript.h - Contains template TScript.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPT_H
#define REGINA_SCRIPT_TSCRIPT_H

#include <CScriptChain.h>
#include <CVariablePool.h>
#include <TFunctionPool.h>
#include <CScriptString.h>
#include <CException_ScriptError_SyntaxError.h>
#include <CException_ScriptError_UndefinedSymbol.h>
#include <CException_ScriptError_MissingVariableName.h>
#include <CExpressionEvolutor_String.h>
#include <CExpressionEvolutor_Int.h>
#include <CExpressionEvolutor_Float.h>
#include <CExpressionEvolutor_Bool.h>
#include <TScriptAction_FunctionEvolution.h>
#include <TScriptAction_If_Equal.h>
#include <TScriptAction_If_NotEqual.h>
#include <TScriptAction_If_Greater.h>
#include <TScriptAction_If_GreaterEqual.h>
#include <TScriptAction_If_Less.h>
#include <TScriptAction_If_LessEqual.h>
#include <TScriptAction_RunChain.h>
#include <TScriptAction_While_Equal.h>
#include <TScriptAction_While_NotEqual.h>
#include <TScriptAction_While_LessEqual.h>
#include <TScriptAction_While_GreaterEqual.h>
#include <TScriptAction_While_Less.h>
#include <TScriptAction_While_Greater.h>
#include <TScriptAction_For_Equal.h>
#include <TScriptAction_For_NotEqual.h>
#include <TScriptAction_For_Greater.h>
#include <TScriptAction_For_Less.h>
#include <TScriptAction_For_LessEqual.h>
#include <TScriptAction_For_GreaterEqual.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//TScript template.															  |
//T1 class type.															  |
//----------------------------------------------------------------------------|
template<class T>
class TScript
{
	wstring					name;
	vector<CScriptChain*>	scriptChain;
	CVariablePool*			variablePool;
	TFunctionPool<T>*		functionPool;

	void CompileChain(const unsigned& iChainNumber) throw(CException_ScriptError_SyntaxError);
	void CompileChains();
	void PrepareScriptText(const vector<wstring>& iScriptText);
	
	void EvoluteExpression(CScriptChain* iScriptChain, wstring*& oArgument, CScriptString& iLine) throw(CException_ScriptError_SyntaxError);
	void EvoluteExpression(CScriptChain* iScriptChain, int*& oArgument, CScriptString& iLine) throw(CException_ScriptError_SyntaxError);
	void EvoluteExpression(CScriptChain* iScriptChain, float*& oArgument, CScriptString& iLine) throw(CException_ScriptError_SyntaxError);
	void EvoluteExpression(CScriptChain* iScriptChain, bool*& oArgument, CScriptString& iLine) throw(CException_ScriptError_SyntaxError);
	void EvoluteFunction(CScriptChain* iScriptChain, wstring*& oArgument, CScriptString& iLine) throw(CException_ScriptError_SyntaxError);
	void EvoluteFunction(CScriptChain* iScriptChain, int*& oArgument, CScriptString& iLine) throw(CException_ScriptError_SyntaxError);
	void EvoluteFunction(CScriptChain* iScriptChain, float*& oArgument, CScriptString& iLine) throw(CException_ScriptError_SyntaxError);
	void EvoluteFunction(CScriptChain* iScriptChain, bool*& oArgument, CScriptString& iLine) throw(CException_ScriptError_SyntaxError);
	void EvoluteFunction(CScriptChain* iScriptChain, CScriptString& iLine) throw(CException_ScriptError_SyntaxError); // VOID

	CFunctionDefinition::EFunctionArgumentType GetFirstOccuredVariableType(const wstring& iStr) throw(CException_ScriptError_UndefinedSymbol);
	

	public:
	TScript(const wstring& iName, CVariablePool* iVariablePool, TFunctionPool<T>* iFunctionPool) throw(invalid_argument);
	~TScript();

	wstring	Name()	const { return name; }
	void Run();
	void Load(const vector<wstring>& iScriptText);
	void Clear();

	void PrintScriptText(ostream& oStream);
};

//*****************************************************************************

template<class T>
TScript<T>::TScript(const wstring& iName, CVariablePool* iVariablePool, TFunctionPool<T>* iFunctionPool) : name(iName), variablePool(iVariablePool), functionPool(iFunctionPool) 
	{ 
	if(iVariablePool == NULL)
		throw invalid_argument("Regina::Script::TScript<T>::TScript - iVariablePool == NULL");

	if(iFunctionPool == NULL)
		throw invalid_argument("Regina::Script::TScript<T>::TScript - iFunctionPool == NULL");


	}

//*****************************************************************************

template<class T>
TScript<T>::~TScript()
	{
	Clear();
	}

//*****************************************************************************

template<class T>
void TScript<T>::Clear()
	{
	for(unsigned i=0; i<scriptChain.size(); i++)
		if(scriptChain[i]!=NULL)
			delete scriptChain[i];
	scriptChain.clear();
	}

//*****************************************************************************

template<class T>
void TScript<T>::Load(const vector<wstring>& iScriptText)
	{
	try	{
		PrepareScriptText(iScriptText);
		CompileChains();
		}
	catch(CException_ScriptError& iException)
		{
		Clear();
		throw iException;
		}
	}

//*****************************************************************************

template<class T>
void TScript<T>::Run()
	{
	if(scriptChain.size()>0)
		scriptChain[0]->Run();
	}

//*****************************************************************************

template<class T>
CFunctionDefinition::EFunctionArgumentType TScript<T>::GetFirstOccuredVariableType(const wstring& iStr)
	{
	CScriptString iLine(iStr.c_str());

	if(iLine.NextSymbol() == '"')
		return CFunctionDefinition::e_String;

	if(variablePool->ExistVariable(iLine.NextVariable()))
		{
		wstring st1 = iLine.ScanVariable();
		
		if(variablePool->ExistVariable_string(st1))
			return CFunctionDefinition::e_String;

		if(variablePool->ExistVariable_bool(st1))
			return CFunctionDefinition::e_Bool;
		
		if(variablePool->ExistVariable_int(st1))
			return CFunctionDefinition::e_Int;

		if(variablePool->ExistVariable_float(st1))
			return CFunctionDefinition::e_Float;
		}

		if(functionPool->ExistFunction(iLine.NextVariable()))
			{
			CFunctionDefinition definition = functionPool->GetFunctionDefinition(iLine.NextVariable());
			switch(definition.ReturnType())
				{
				case CFunctionDefinition::e_String:			return CFunctionDefinition::e_String;
														
				case CFunctionDefinition::e_Int:			return CFunctionDefinition::e_Int;

				case CFunctionDefinition::e_Float:			return CFunctionDefinition::e_Float;

				case CFunctionDefinition::e_Bool:			return CFunctionDefinition::e_Bool;

				default:									{
															assert(false && L"TScript<T>::GetFirstOccuredVariableType - invalid function return type");
															}
										
				}
			}

		if(iLine.NextSymbol() == '1' || iLine.NextSymbol() == '2' || iLine.NextSymbol() == '3' || iLine.NextSymbol() == '4' || iLine.NextSymbol() == '5' || iLine.NextSymbol() == '6' || iLine.NextSymbol() == '7' || iLine.NextSymbol() == '8' || iLine.NextSymbol() == '9' || iLine.NextSymbol() == '0')
			return CFunctionDefinition::e_Float;

		if(iLine.NextVariable()==L"true")
			return CFunctionDefinition::e_Bool;

		if(iLine.NextVariable()==L"false")
			return CFunctionDefinition::e_Bool;

	throw CException_ScriptError_UndefinedSymbol("TScript<T>::GetFirstOccuredVariableType", "");
	}

//*****************************************************************************

template<class T>
void TScript<T>::PrintScriptText(ostream& oStream)
	{
	for(unsigned i=0; i<scriptChain.size(); i++)
		{
		vector<CScriptLine> curScriptText;
		scriptChain[i]->GetScriptText(curScriptText);

		oStream << "*****************************************************************************" << endl;
		oStream << "Script Text of " << i << " chain:" << endl << endl;

		for(unsigned ii=0; ii<curScriptText.size(); ii++)
			oStream << curScriptText[ii] << endl;

		oStream << endl;
		oStream << "*****************************************************************************" << endl << endl;
		}
	}

//*****************************************************************************

template<class T>
void TScript<T>::CompileChains()
	{
	if(scriptChain.size()>0)
		CompileChain(0);
	}

//*****************************************************************************

template<class T>
void TScript<T>::PrepareScriptText(const vector<wstring>& iScriptText)
	{
	vector<unsigned> info;
	info.push_back(0);
	scriptChain.push_back(new CScriptChain());

	for(unsigned i=0; i<iScriptText.size(); i++)
		{
		wstring curLine(iScriptText[i]);
		unsigned curStartPos(0);
		bool quoteEnabled(false);

		for(unsigned ii=0; ii<curLine.size(); ii++)
			{
			if(curStartPos == ii)
				{
				if(curLine[ii] == ' ')
					{
					curStartPos++;
					continue;
					}
				}

			if(curStartPos == ii)
				{
				if(curLine[ii] == '\t')
					{
					curStartPos++;
					continue;
					}
				}

			if(curLine[ii] == '"')
				{
				if(quoteEnabled == true)
					{
					quoteEnabled = false;
					if(ii==curLine.size()-1)
						{
						wstring stringPart(curLine.begin() + curStartPos, curLine.begin() + ii + 1);
						scriptChain[info[info.size()-1]]->AddScriptLine(CScriptLine(stringPart, i+1));
						}
					continue;
					}
				else
					{
					quoteEnabled = true;
					if(ii==curLine.size()-1)
						{
						wstring stringPart(curLine.begin() + curStartPos, curLine.begin() + ii + 1);
						scriptChain[info[info.size()-1]]->AddScriptLine(CScriptLine(stringPart, i+1));
						}
					continue;
					}
				}

			if(quoteEnabled == true)
				{
				if(ii==curLine.size()-1)
					{
					wstring stringPart(curLine.begin() + curStartPos, curLine.begin() + ii + 1);
					scriptChain[info[info.size()-1]]->AddScriptLine(CScriptLine(stringPart, i+1));
					}
				continue;
				}

			if(curLine[ii] == ';')
				{
				wstring stringPart(curLine.begin() + curStartPos, curLine.begin() + ii + 1);
				scriptChain[info[info.size()-1]]->AddScriptLine(CScriptLine(stringPart, i+1));
				curStartPos = ii+1;
				continue;
				}

			if(curLine[ii] == '{')
				{
				wostringstream st;
				st << "call " << scriptChain.size();
				scriptChain[info[info.size()-1]]->AddScriptLine(CScriptLine(st.str(), i+1));
				info.push_back(scriptChain.size());
				scriptChain.push_back(new CScriptChain());
				if(curStartPos != ii)
					{
					wstring stringPart(curLine.begin() + curStartPos, curLine.begin() + ii);
					scriptChain[info[info.size()-1]]->AddScriptLine(CScriptLine(stringPart, i+1));
					}

				curStartPos = ii+1;
				continue;
				}

			if(curLine[ii] == '}')
				{
				if(curStartPos != ii)
					{
					wstring stringPart(curLine.begin() + curStartPos, curLine.begin() + ii);
					scriptChain[info[info.size()-1]]->AddScriptLine(CScriptLine(stringPart, i+1));
					}
				
				if(info.size()>1)
					info.pop_back();
				else
					throw CException_ScriptError_SyntaxError("TScript<T>::PrepareScriptText", "Too many } symbols.", i); 
				
				curStartPos = ii+1;
				continue;
				}

			if(ii==curLine.size()-1)
				{
				wstring stringPart(curLine.begin() + curStartPos, curLine.begin() + ii + 1);
				scriptChain[info[info.size()-1]]->AddScriptLine(CScriptLine(stringPart, i+1));
				}
			}
		}
	}

//*****************************************************************************


template<class T>
void TScript<T>::EvoluteExpression(CScriptChain* iScriptChain, wstring*& oArgument, CScriptString& iLine)
	{
	//For string only add operator
	//All variable types are supported
	CExpressionEvolutor_String expression;
	unsigned parenthesisCount(0);

	while(true)
		{
		iLine.Omit();

		if(iLine.End() == true)
			break;

		if(iLine.NextSymbol() == '"')
			{
			iLine.ScanNextSymbol();
			wstring st1 = iLine.ScanToSymbol('"');
			iLine.ScanNextSymbol();
			wstring* str = new wstring(st1);
			variablePool->AddWorkingVariable(str);
			expression.AddVariable(str);
			continue;
			}

		if(iLine.NextSymbol() == '(')
			{
			iLine.ScanNextSymbol();
			expression.AddParentheses_Opening();
			parenthesisCount++;
			continue;
			}

		if(iLine.NextSymbol() == ')')
			{
			if(parenthesisCount==0)
				break;
			else
				{
				iLine.ScanNextSymbol();
				expression.AddParentheses_Closing();
				parenthesisCount--;
				continue;
				}
			}

		if(iLine.NextSymbol() == ';')
			break;

		if(iLine.NextSymbol() == '+')
			{
			iLine.ScanNextSymbol();
			expression.AddSign_Plus();
			continue;
			}

		if(variablePool->ExistVariable(iLine.NextVariable()))
			{
			wstring st1 = iLine.ScanVariable();
			
			if(variablePool->ExistVariable_string(st1))
				{
				wstring* var(NULL);
				variablePool->GetPointerToVariable(st1, var);
				assert(var!=NULL);

				expression.AddVariable(var);
				continue;
				}

			if(variablePool->ExistVariable_bool(st1))
				{
				bool* var(NULL);
				variablePool->GetPointerToVariable(st1, var);
				assert(var!=NULL);

				expression.AddVariable(var);
				continue;
				}

			
			if(variablePool->ExistVariable_int(st1))
				{
				int* var(NULL);
				variablePool->GetPointerToVariable(st1, var);
				assert(var!=NULL);

				expression.AddVariable(var);
				continue;
				}

			if(variablePool->ExistVariable_float(st1))
				{
				float* var(NULL);
				variablePool->GetPointerToVariable(st1, var);
				assert(var!=NULL);

				expression.AddVariable(var);
				continue;
				}

			}

		if(functionPool->ExistFunction(iLine.NextVariable()))
			{
			CFunctionDefinition definition = functionPool->GetFunctionDefinition(iLine.NextVariable());
			switch(definition.ReturnType())
				{
				case CFunctionDefinition::e_String:			{
															wstring* var(NULL);
															EvoluteFunction(iScriptChain, var, iLine);
															assert(var!=NULL);
															expression.AddVariable(var);
															continue;
															break;
															}

				case CFunctionDefinition::e_Int:			{
															int* var(NULL);
															EvoluteFunction(iScriptChain, var, iLine);
															assert(var!=NULL);
															expression.AddVariable(var);
															continue;
															break;
															}

				case CFunctionDefinition::e_Float:			{
															float* var(NULL);
															EvoluteFunction(iScriptChain, var, iLine);
															assert(var!=NULL);
															expression.AddVariable(var);
															continue;
															break;
															}

				case CFunctionDefinition::e_Bool:			{
															bool* var(NULL);
															EvoluteFunction(iScriptChain, var, iLine);
															assert(var!=NULL);
															expression.AddVariable(var);
															continue;
															break;
															}

				default:									{
															//unsuported return type
															assert(false && L"TScript<T>::EvoluteExpression - invalid function return type");
															}
										
				}
			}

		//undefined symbol
		throw CException_ScriptError_UndefinedSymbol("TScript<T>::EvoluteExpression", "");
		}

	vector<CScriptAction*>	oScriptAction;
	vector<wstring*>			oTempVariable;

	try	{
		expression.Evolute(oArgument, oScriptAction, oTempVariable);
		}
	catch(CException_ScriptError_SyntaxError& iException)
		{
		for(unsigned i=0; i<oScriptAction.size(); i++)
			if(oScriptAction[i]!=NULL)
				delete oScriptAction[i];

		for(unsigned i=0; i<oTempVariable.size(); i++)
			if(oTempVariable[i]!=NULL)
				delete oTempVariable[i];

		oScriptAction.clear();
		oTempVariable.clear();

		throw iException;
		}

	for(unsigned i=0; i<oScriptAction.size(); i++)
		iScriptChain->Add(oScriptAction[i]);

	for(unsigned i=0; i<oTempVariable.size(); i++)
		variablePool->AddWorkingVariable(oTempVariable[i]);	
	}

//*****************************************************************************

template<class T>
void TScript<T>::EvoluteFunction(CScriptChain* iScriptChain, wstring*& oArgument, CScriptString& iLine)
	{
	wstring st1 = iLine.ScanVariable(); //FunctionName
	
	CFunctionDefinition definition = functionPool->GetFunctionDefinition(st1);
	switch(definition.ArgumentType())
				{
				case CFunctionDefinition::e_Void:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															wstring* var = new wstring(L"");
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, wstring, void>(functionPool, var, definition.Position())); 
																
															oArgument = var;

															return;
															}



				case CFunctionDefinition::e_String:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															wstring* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															wstring* var = new wstring(L"");
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, wstring, wstring>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}

				case CFunctionDefinition::e_Int:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															int* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															wstring* var = new wstring(L"");
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, wstring, int>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}


				case CFunctionDefinition::e_Float:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															float* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															wstring* var = new wstring(L"");
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, wstring, float>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}

				case CFunctionDefinition::e_Bool:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															bool* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															wstring* var = new wstring(L"");
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, wstring, bool>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}
															
										
				}
	}

//*****************************************************************************

template<class T>
void TScript<T>::EvoluteExpression(CScriptChain* iScriptChain, int*& oArgument, CScriptString& iLine)
	{
	//For int all operators are supported
	//Only int and float variable
	CExpressionEvolutor_Int expression;
	unsigned parenthesisCount(0);

	while(true)
		{
		iLine.Omit();

		if(iLine.End() == true)
			break;

		if(iLine.NextSymbol() == '1' || iLine.NextSymbol() == '2' || iLine.NextSymbol() == '3' || iLine.NextSymbol() == '4' || iLine.NextSymbol() == '5' || iLine.NextSymbol() == '6' || iLine.NextSymbol() == '7' || iLine.NextSymbol() == '8' || iLine.NextSymbol() == '9' || iLine.NextSymbol() == '0')
			{
			float* var = new float(iLine.ScanFloat());
			variablePool->AddWorkingVariable(var);
			expression.AddVariable(var);
			continue;
			}

		if(iLine.NextSymbol() == '(')
			{
			iLine.ScanNextSymbol();
			expression.AddParentheses_Opening();
			parenthesisCount++;
			continue;
			}

		if(iLine.NextSymbol() == ')')
			{
			if(parenthesisCount==0)
				break;
			else
				{
				iLine.ScanNextSymbol();
				expression.AddParentheses_Closing();
				parenthesisCount--;
				continue;
				}
			}

		if(iLine.NextSymbol() == ';')
			break;

		if(iLine.NextSymbol() == '+')
			{
			iLine.ScanNextSymbol();
			expression.AddSign_Plus();
			continue;
			}

		if(iLine.NextSymbol() == '-')
			{
			iLine.ScanNextSymbol();
			expression.AddSign_Minus();
			continue;
			}
		
		if(iLine.NextSymbol() == '/')
			{
			iLine.ScanNextSymbol();
			expression.AddSign_Divide();
			continue;
			}

		if(iLine.NextSymbol() == '*')
			{
			iLine.ScanNextSymbol();
			expression.AddSign_Multiply();
			continue;
			}

		if(variablePool->ExistVariable(iLine.NextVariable()))
			{
			wstring st1 = iLine.ScanVariable();
				
			if(variablePool->ExistVariable_int(st1))
				{
				int* var(NULL);
				variablePool->GetPointerToVariable(st1, var);
				assert(var!=NULL);

				expression.AddVariable(var);
				continue;
				}

			if(variablePool->ExistVariable_float(st1))
				{
				float* var(NULL);
				variablePool->GetPointerToVariable(st1, var);
				assert(var!=NULL);

				expression.AddVariable(var);
				continue;
				}

			}

		if(functionPool->ExistFunction(iLine.NextVariable()))
			{
			CFunctionDefinition definition = functionPool->GetFunctionDefinition(iLine.NextVariable());
			switch(definition.ReturnType())
				{
				case CFunctionDefinition::e_Int:			{
															int* var(NULL);
															EvoluteFunction(iScriptChain, var, iLine);
															assert(var!=NULL);
															expression.AddVariable(var);
															continue;
															break;
															}

				case CFunctionDefinition::e_Float:			{
															float* var(NULL);
															EvoluteFunction(iScriptChain, var, iLine);
															assert(var!=NULL);
															expression.AddVariable(var);
															continue;
															break;
															}									
				}
			}

		//undefined symbol
		throw CException_ScriptError_UndefinedSymbol("TScript<T>::EvoluteExpression", "");
		}

	vector<CScriptAction*>	oScriptAction;
	vector<int*>			oTempVariable;

	try	{
		expression.Evolute(oArgument, oScriptAction, oTempVariable);
		}
	catch(CException_ScriptError_SyntaxError& iException)
		{
		for(unsigned i=0; i<oScriptAction.size(); i++)
			if(oScriptAction[i]!=NULL)
				delete oScriptAction[i];

		for(unsigned i=0; i<oTempVariable.size(); i++)
			if(oTempVariable[i]!=NULL)
				delete oTempVariable[i];

		oScriptAction.clear();
		oTempVariable.clear();

		throw iException;
		}

	for(unsigned i=0; i<oScriptAction.size(); i++)
		iScriptChain->Add(oScriptAction[i]);

	for(unsigned i=0; i<oTempVariable.size(); i++)
		variablePool->AddWorkingVariable(oTempVariable[i]);	
	}

//*****************************************************************************

template<class T>
void TScript<T>::EvoluteFunction(CScriptChain* iScriptChain, int*& oArgument, CScriptString& iLine)
	{
	wstring st1 = iLine.ScanVariable(); //FunctionName
	
	CFunctionDefinition definition = functionPool->GetFunctionDefinition(st1);
	switch(definition.ArgumentType())
				{
				case CFunctionDefinition::e_Void:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															int* var = new int(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, int, void>(functionPool, var, definition.Position())); 
																
															oArgument = var;

															return;
															}



				case CFunctionDefinition::e_Int:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															int* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															int* var = new int(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, int, int>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}

				case CFunctionDefinition::e_Float:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															float* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															int* var = new int(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, int, float>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}


				case CFunctionDefinition::e_String:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															wstring* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															int* var = new int(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, int, wstring>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}

				case CFunctionDefinition::e_Bool:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															bool* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															int* var = new int(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, int, bool>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}


															
										
				}
	}


//*****************************************************************************

template<class T>
void TScript<T>::EvoluteExpression(CScriptChain* iScriptChain, float*& oArgument, CScriptString& iLine)
	{
	//For int all operators are supported
	//Only int and float variable
	CExpressionEvolutor_Float expression;
	unsigned parenthesisCount(0);

	while(true)
		{
		iLine.Omit();

		if(iLine.End() == true)
			break;

		if(iLine.NextSymbol() == '1' || iLine.NextSymbol() == '2' || iLine.NextSymbol() == '3' || iLine.NextSymbol() == '4' || iLine.NextSymbol() == '5' || iLine.NextSymbol() == '6' || iLine.NextSymbol() == '7' || iLine.NextSymbol() == '8' || iLine.NextSymbol() == '9' || iLine.NextSymbol() == '0')
			{
			float* var = new float(iLine.ScanFloat());
			variablePool->AddWorkingVariable(var);
			expression.AddVariable(var);
			continue;
			}

		if(iLine.NextSymbol() == '(')
			{
			iLine.ScanNextSymbol();
			expression.AddParentheses_Opening();
			parenthesisCount++;
			continue;
			}

		if(iLine.NextSymbol() == ')')
			{
			if(parenthesisCount==0)
				break;
			else
				{
				iLine.ScanNextSymbol();
				expression.AddParentheses_Closing();
				parenthesisCount--;
				continue;
				}
			}

		if(iLine.NextSymbol() == ';')
			break;

		if(iLine.NextSymbol() == '+')
			{
			iLine.ScanNextSymbol();
			expression.AddSign_Plus();
			continue;
			}

		if(iLine.NextSymbol() == '-')
			{
			iLine.ScanNextSymbol();
			expression.AddSign_Minus();
			continue;
			}
		
		if(iLine.NextSymbol() == '/')
			{
			iLine.ScanNextSymbol();
			expression.AddSign_Divide();
			continue;
			}

		if(iLine.NextSymbol() == '*')
			{
			iLine.ScanNextSymbol();
			expression.AddSign_Multiply();
			continue;
			}

		if(variablePool->ExistVariable(iLine.NextVariable()))
			{
			wstring st1 = iLine.ScanVariable();
				
			if(variablePool->ExistVariable_int(st1))
				{
				int* var(NULL);
				variablePool->GetPointerToVariable(st1, var);
				assert(var!=NULL);

				expression.AddVariable(var);
				continue;
				}

			if(variablePool->ExistVariable_float(st1))
				{
				float* var(NULL);
				variablePool->GetPointerToVariable(st1, var);
				assert(var!=NULL);

				expression.AddVariable(var);
				continue;
				}

			}

		if(functionPool->ExistFunction(iLine.NextVariable()))
			{
			CFunctionDefinition definition = functionPool->GetFunctionDefinition(iLine.NextVariable());
			switch(definition.ReturnType())
				{
				case CFunctionDefinition::e_Int:			{
															int* var(NULL);
															EvoluteFunction(iScriptChain, var, iLine);
															assert(var!=NULL);
															expression.AddVariable(var);
															continue;
															break;
															}

				case CFunctionDefinition::e_Float:			{
															float* var(NULL);
															EvoluteFunction(iScriptChain, var, iLine);
															assert(var!=NULL);
															expression.AddVariable(var);
															continue;
															break;
															}
										
				}
			}

		//undefined symbol
		throw CException_ScriptError_UndefinedSymbol("TScript<T>::EvoluteExpression", "");
		}

	vector<CScriptAction*>	oScriptAction;
	vector<float*>			oTempVariable;

	try	{
		expression.Evolute(oArgument, oScriptAction, oTempVariable);
		}
	catch(CException_ScriptError_SyntaxError& iException)
		{
		for(unsigned i=0; i<oScriptAction.size(); i++)
			if(oScriptAction[i]!=NULL)
				delete oScriptAction[i];

		for(unsigned i=0; i<oTempVariable.size(); i++)
			if(oTempVariable[i]!=NULL)
				delete oTempVariable[i];

		oScriptAction.clear();
		oTempVariable.clear();

		throw iException;
		}

	for(unsigned i=0; i<oScriptAction.size(); i++)
		iScriptChain->Add(oScriptAction[i]);

	for(unsigned i=0; i<oTempVariable.size(); i++)
		variablePool->AddWorkingVariable(oTempVariable[i]);	
	}

//*****************************************************************************

template<class T>
void TScript<T>::EvoluteFunction(CScriptChain* iScriptChain, float*& oArgument, CScriptString& iLine)
	{
	wstring st1 = iLine.ScanVariable(); //FunctionName
	
	CFunctionDefinition definition = functionPool->GetFunctionDefinition(st1);
	switch(definition.ArgumentType())
				{
				case CFunctionDefinition::e_Void:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															float* var = new float(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, float, void>(functionPool, var, definition.Position())); 
																
															oArgument = var;

															return;
															}



				case CFunctionDefinition::e_Int:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															int* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															float* var = new float(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, float, int>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}

		
				case CFunctionDefinition::e_Float:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															float* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															float* var = new float(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, float, float>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}

				case CFunctionDefinition::e_String:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															wstring* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															float* var = new float(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, float, wstring>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}


				case CFunctionDefinition::e_Bool:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															bool* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															float* var = new float(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, float, bool>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}

															
										
				}
	}


//*****************************************************************************

template<class T>
void TScript<T>::EvoluteExpression(CScriptChain* iScriptChain, bool*& oArgument, CScriptString& iLine)
	{
	//For bool only multiply operator is supported
	//Only bool variable
	CExpressionEvolutor_Bool expression;
	unsigned parenthesisCount(0);

	while(true)
		{
		iLine.Omit();

		if(iLine.End() == true)
			break;

		if(iLine.NextVariable()==L"true")
			{
			iLine.ScanVariable();
			bool* var = new bool(true);
			variablePool->AddWorkingVariable(var);
			expression.AddVariable(var);
			continue;
			}

		if(iLine.NextVariable()==L"false")
			{
			iLine.ScanVariable();
			bool* var = new bool(false);
			variablePool->AddWorkingVariable(var);
			expression.AddVariable(var);
			continue;
			}

		if(iLine.NextSymbol()== '0')
			{
			iLine.ScanNextSymbol();
			bool* var = new bool(false);
			variablePool->AddWorkingVariable(var);
			expression.AddVariable(var);
			continue;
			}

		if(iLine.NextSymbol()== '1')
			{
			iLine.ScanNextSymbol();
			bool* var = new bool(true);
			variablePool->AddWorkingVariable(var);
			expression.AddVariable(var);
			continue;
			}

		if(iLine.NextSymbol() == '(')
			{
			iLine.ScanNextSymbol();
			expression.AddParentheses_Opening();
			parenthesisCount++;
			continue;
			}

		if(iLine.NextSymbol() == ')')
			{
			if(parenthesisCount==0)
				break;
			else
				{
				iLine.ScanNextSymbol();
				expression.AddParentheses_Closing();
				parenthesisCount--;
				continue;
				}
			}

		if(iLine.NextSymbol() == ';')
			break;

		if(iLine.NextSymbol() == '*')
			{
			iLine.ScanNextSymbol();
			expression.AddSign_Multiply();
			continue;
			}

		if(variablePool->ExistVariable_bool(iLine.NextVariable()))
			{
			wstring st1 = iLine.ScanVariable();

			bool* var(NULL);
			variablePool->GetPointerToVariable(st1, var);
			assert(var!=NULL);
			expression.AddVariable(var);
			continue;
			}

		if(functionPool->ExistFunction(iLine.NextVariable()))
			{
			CFunctionDefinition definition = functionPool->GetFunctionDefinition(iLine.NextVariable());
			switch(definition.ReturnType())
				{
				case CFunctionDefinition::e_Bool:			{
															bool* var(NULL);
															EvoluteFunction(iScriptChain, var, iLine);
															assert(var!=NULL);
															expression.AddVariable(var);
															continue;
															break;
															}
										
				}
			}

		//undefined symbol
		throw CException_ScriptError_UndefinedSymbol("TScript<T>::EvoluteExpression", "");
		}

	vector<CScriptAction*>	oScriptAction;
	vector<bool*>			oTempVariable;

	try	{
		expression.Evolute(oArgument, oScriptAction, oTempVariable);
		}
	catch(CException_ScriptError_SyntaxError& iException)
		{
		for(unsigned i=0; i<oScriptAction.size(); i++)
			if(oScriptAction[i]!=NULL)
				delete oScriptAction[i];

		for(unsigned i=0; i<oTempVariable.size(); i++)
			if(oTempVariable[i]!=NULL)
				delete oTempVariable[i];

		oScriptAction.clear();
		oTempVariable.clear();

		throw iException;
		}

	for(unsigned i=0; i<oScriptAction.size(); i++)
		iScriptChain->Add(oScriptAction[i]);

	for(unsigned i=0; i<oTempVariable.size(); i++)
		variablePool->AddWorkingVariable(oTempVariable[i]);	
	}

//*****************************************************************************

template<class T>
void TScript<T>::EvoluteFunction(CScriptChain* iScriptChain, bool*& oArgument, CScriptString& iLine)
	{
	wstring st1 = iLine.ScanVariable(); //FunctionName
	
	CFunctionDefinition definition = functionPool->GetFunctionDefinition(st1);
	switch(definition.ArgumentType())
				{
				case CFunctionDefinition::e_Void:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															bool* var = new bool(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, bool, void>(functionPool, var, definition.Position())); 
																
															oArgument = var;

															return;
															}



				case CFunctionDefinition::e_Int:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															int* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															bool* var = new bool(true);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, bool, int>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}

		
				case CFunctionDefinition::e_Float:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															float* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															bool* var = new bool(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, bool, float>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}


				case CFunctionDefinition::e_String:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															wstring* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															bool* var = new bool(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, bool, wstring>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}

				case CFunctionDefinition::e_Bool:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															bool* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
															bool* var = new bool(0);
															variablePool->AddWorkingVariable(var);
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, bool, bool>(functionPool, var, argument, definition.Position())); 
																
															oArgument = var;

															return;
															}

															
										
				}
	}


//*****************************************************************************

template<class T>
void TScript<T>::EvoluteFunction(CScriptChain* iScriptChain, CScriptString& iLine)
	{
	wstring st1 = iLine.ScanVariable(); //FunctionName
	
	CFunctionDefinition definition = functionPool->GetFunctionDefinition(st1);
	switch(definition.ArgumentType())
				{
				case CFunctionDefinition::e_Void:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
																												
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, void, void>(functionPool, definition.Position())); 
															return;
															}



				case CFunctionDefinition::e_Int:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															int* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");						
															
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, void, int>(functionPool, argument, definition.Position())); 

															return;
															}

		
				case CFunctionDefinition::e_Float:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															float* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
																													
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, void, float>(functionPool, argument, definition.Position())); 
																
															return;
															}


				case CFunctionDefinition::e_String:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															wstring* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
														
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, void, wstring>(functionPool, argument, definition.Position())); 
																
															return;
															}

				case CFunctionDefinition::e_Bool:			{
															if(iLine.ScanNextSymbol()!='(')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ( symbol.");
																			
															bool* argument(NULL);
															EvoluteExpression(iScriptChain, argument, iLine);
															assert(argument!=NULL);

															if(iLine.ScanNextSymbol()!=')')
																throw CException_ScriptError_SyntaxError("TScript<T>::EvoluteFunction", "Missing ) symbol.");
															
												
															iScriptChain->Add(new TSciptAction_FunctionEvolution<TFunctionPool<T>, void, bool>(functionPool, argument, definition.Position())); 

															return;
															}

															
										
				}
	}


//*****************************************************************************

template<class T>
void TScript<T>::CompileChain(const unsigned& iChainNumber)
	{	
	vector<CScriptLine> iScriptText;
	scriptChain[iChainNumber]->GetScriptText(iScriptText);
	CScriptChain* curScriptChain = scriptChain[iChainNumber];

	if(curScriptChain->GetScriptActionCount()>0)
		return;

	for(unsigned i=0; i<iScriptText.size(); i++)
		{
		CScriptString line(iScriptText[i].c_str());
		wstring st1 = line.NextVariable();

		if(st1 == L"")
			continue;

//STATIC
		if(st1 == L"static")
			{
			line.ScanVariable();
			st1 = line.ScanVariable();

	//STATIC STRING 	
			if(st1 == L"string")
				{
				wstring st2 = line.ScanVariable(); // Variable name

				if(st2.size() == 0)
					throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After string must follow variable name", iScriptText[i].PositionInOriginalScriptText());

				if(line.NextSymbol() == ';')
					{
					if(variablePool->ExistVariable_string(st2) == false)
						variablePool->AddGlobalVariable(st2, wstring(L""));
					continue;
					}

				if(line.NextSymbol() == '(')
					{
					wstring* variable(NULL);
					if(variablePool->ExistVariable_string(st2) == false)
						variablePool->AddGlobalVariable(st2, wstring(L""));

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					wstring* argument(NULL);
					
					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					*variable = *argument;
					continue;					
					}

				if(line.NextSymbol() == '=')
					{
					line.ScanNextSymbol();
					wstring* variable(NULL);
					if(variablePool->ExistVariable_string(st2) == false)
						variablePool->AddGlobalVariable(st2, wstring(L""));

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					wstring* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					*variable = *argument;
					continue;					
					}

				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
				}

	//STATIC INT
			if(st1 == L"int")
				{
				wstring st2 = line.ScanVariable(); // Variable name

				if(st2.size() == 0)
					throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After int must follow variable name", iScriptText[i].PositionInOriginalScriptText());

				if(line.NextSymbol() == ';')
					{
					if(variablePool->ExistVariable_int(st2) == false)
						variablePool->AddGlobalVariable(st2, (int)0);
					continue;
					}

				if(line.NextSymbol() == '(')
					{
					int* variable(NULL);
					if(variablePool->ExistVariable_int(st2) == false)
						variablePool->AddGlobalVariable(st2, (int)0);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					int* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					*variable = *argument;
					continue;							
					}


				if(line.NextSymbol() == '=')
					{
					line.ScanNextSymbol();
					int* variable(NULL);
					if(variablePool->ExistVariable_int(st2) == false)
						variablePool->AddGlobalVariable(st2, (int)0);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					int* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					*variable = *argument;
					continue;							
					}


				//undefined symbol
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
				}

	//STATIC FLOAT
			if(st1 == L"float")
				{
				wstring st2 = line.ScanVariable(); // Variable name

				if(st2.size() == 0)
					throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After float must follow variable name", iScriptText[i].PositionInOriginalScriptText());

				if(line.NextSymbol() == ';')
					{
					if(variablePool->ExistVariable_float(st2) == false)
						variablePool->AddGlobalVariable(st2, (float)0);
					continue;
					}

				if(line.NextSymbol() == '(')
					{
					float* variable(NULL);
					if(variablePool->ExistVariable_float(st2) == false)
						variablePool->AddGlobalVariable(st2, (float)0);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					float* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					*variable = *argument;
					continue;							
					}


				if(line.NextSymbol() == '=')
					{
					line.ScanNextSymbol();
					float* variable(NULL);
					if(variablePool->ExistVariable_float(st2) == false)
						variablePool->AddGlobalVariable(st2, (float)0);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					float* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					*variable = *argument;
					continue;							
					}


				//undefined symbol
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
				}

	//STATIC BOOL
			if(st1 == L"bool")
				{
				wstring st2 = line.ScanVariable(); // Variable name

				if(st2.size() == 0)
					throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After bool must follow variable name", iScriptText[i].PositionInOriginalScriptText());

				if(line.NextSymbol() == ';')
					{
					if(variablePool->ExistVariable_bool(st2) == false)
						variablePool->AddGlobalVariable(st2, (bool)true);
					continue;
					}

				if(line.NextSymbol() == '(')
					{
					bool* variable(NULL);
					if(variablePool->ExistVariable_bool(st2) == false)
						variablePool->AddGlobalVariable(st2, (bool)true);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					bool* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					*variable = *argument;
					continue;							
					}


				if(line.NextSymbol() == '=')
					{
					line.ScanNextSymbol();
					bool* variable(NULL);
					if(variablePool->ExistVariable_bool(st2) == false)
						variablePool->AddGlobalVariable(st2, (bool)true);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					bool* argument(NULL);
	
					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					*variable = *argument;
					continue;							
					}
				}

				//undefined symbol
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
			}

//GlLOBAL
		if(st1 == L"global")
			{
			line.ScanVariable();
			st1 = line.ScanVariable();

	//GLOBAL STRING 	
			if(st1 == L"string")
				{
				wstring st2 = line.ScanVariable(); // Variable name

				if(st2.size() == 0)
					throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After string must follow variable name", iScriptText[i].PositionInOriginalScriptText());

				if(line.NextSymbol() == ';')
					{
					if(variablePool->ExistVariable_string(st2) == false)
						variablePool->AddGlobalVariable(st2, wstring(L""));
					continue;
					}

				if(line.NextSymbol() == '(')
					{
					wstring* variable(NULL);
					if(variablePool->ExistVariable_string(st2) == false)
						variablePool->AddGlobalVariable(st2, wstring(L""));

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					wstring* argument(NULL);
					
					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<wstring, wstring>(variable, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(line.NextSymbol() == '=')
					{
					line.ScanNextSymbol();
					wstring* variable(NULL);
					if(variablePool->ExistVariable_string(st2) == false)
						variablePool->AddGlobalVariable(st2, wstring(L""));

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					wstring* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<wstring, wstring>(variable, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
				}

	//GLOBAL INT
			if(st1 == L"int")
				{
				wstring st2 = line.ScanVariable(); // Variable name

				if(st2.size() == 0)
					throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After int must follow variable name", iScriptText[i].PositionInOriginalScriptText());

				if(line.NextSymbol() == ';')
					{
					if(variablePool->ExistVariable_int(st2) == false)
						variablePool->AddGlobalVariable(st2, (int)0);
					continue;
					}

				if(line.NextSymbol() == '(')
					{
					int* variable(NULL);
					if(variablePool->ExistVariable_int(st2) == false)
						variablePool->AddGlobalVariable(st2, (int)0);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					int* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<int, int>(variable, argument);
					curScriptChain->Add(sa);
					continue;							
					}


				if(line.NextSymbol() == '=')
					{
					line.ScanNextSymbol();
					int* variable(NULL);
					if(variablePool->ExistVariable_int(st2) == false)
						variablePool->AddGlobalVariable(st2, (int)0);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					int* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<int, int>(variable, argument);
					curScriptChain->Add(sa);
					continue;							
					}


				//undefined symbol
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
				}

	//GLOBAL FLOAT
			if(st1 == L"float")
				{
				wstring st2 = line.ScanVariable(); // Variable name

				if(st2.size() == 0)
					throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After float must follow variable name", iScriptText[i].PositionInOriginalScriptText());

				if(line.NextSymbol() == ';')
					{
					if(variablePool->ExistVariable_float(st2) == false)
						variablePool->AddGlobalVariable(st2, (float)0);
					continue;
					}

				if(line.NextSymbol() == '(')
					{
					float* variable(NULL);
					if(variablePool->ExistVariable_float(st2) == false)
						variablePool->AddGlobalVariable(st2, (float)0);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					float* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<float, float>(variable, argument);
					curScriptChain->Add(sa);
					continue;							
					}


				if(line.NextSymbol() == '=')
					{
					line.ScanNextSymbol();
					float* variable(NULL);
					if(variablePool->ExistVariable_float(st2) == false)
						variablePool->AddGlobalVariable(st2, (float)0);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					float* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<float, float>(variable, argument);
					curScriptChain->Add(sa);
					continue;							
					}


				//undefined symbol
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
				}

	//GLOBAL BOOL
			if(st1 == L"bool")
				{
				wstring st2 = line.ScanVariable(); // Variable name

				if(st2.size() == 0)
					throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After bool must follow variable name", iScriptText[i].PositionInOriginalScriptText());

				if(line.NextSymbol() == ';')
					{
					if(variablePool->ExistVariable_bool(st2) == false)
						variablePool->AddGlobalVariable(st2, (bool)true);
					continue;
					}

				if(line.NextSymbol() == '(')
					{
					bool* variable(NULL);
					if(variablePool->ExistVariable_bool(st2) == false)
						variablePool->AddGlobalVariable(st2, (bool)true);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					bool* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<bool, bool>(variable, argument);
					curScriptChain->Add(sa);
					continue;							
					}


				if(line.NextSymbol() == '=')
					{
					line.ScanNextSymbol();
					bool* variable(NULL);
					if(variablePool->ExistVariable_bool(st2) == false)
						variablePool->AddGlobalVariable(st2, (bool)true);

					variablePool->GetPointerToVariable(st2, variable);
					assert(variable!=NULL);
					
					bool* argument(NULL);
	
					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<bool, bool>(variable, argument);
					curScriptChain->Add(sa);
					continue;							
					}
				}

				//undefined symbol
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
			}

//STRING 	
		if(st1 == L"string")
			{
			line.ScanVariable();
			wstring st2 = line.ScanVariable(); // Variable name

			if(st2.size() == 0)
				throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After string must follow variable name", iScriptText[i].PositionInOriginalScriptText());

			if(line.NextSymbol() == ';')
				{
				if(variablePool->ExistVariable_string(st2) == false)
					variablePool->AddLocalVariable(st2, wstring(L""));
				continue;
				}

			if(line.NextSymbol() == '(')
				{
				wstring* variable(NULL);
				if(variablePool->ExistVariable_string(st2) == false)
					variablePool->AddLocalVariable(st2, wstring(L""));

				variablePool->GetPointerToVariable(st2, variable);
				assert(variable!=NULL);
				
				wstring* argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, argument, line);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}
				
				assert(argument!=NULL);

				CScriptAction* sa = new TScriptAction_Set<wstring, wstring>(variable, argument);
				curScriptChain->Add(sa);
				continue;					
				}

			if(line.NextSymbol() == '=')
				{
				line.ScanNextSymbol();
				wstring* variable(NULL);
				if(variablePool->ExistVariable_string(st2) == false)
					variablePool->AddLocalVariable(st2, wstring(L""));

				variablePool->GetPointerToVariable(st2, variable);
				assert(variable!=NULL);
				
				wstring* argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, argument, line);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}
				
				assert(argument!=NULL);

				CScriptAction* sa = new TScriptAction_Set<wstring, wstring>(variable, argument);
				curScriptChain->Add(sa);
				continue;					
				}


			//undefined symbol
			throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
			}

//INT
		if(st1 == L"int")
			{
			line.ScanVariable();
			wstring st2 = line.ScanVariable(); // Variable name

			if(st2.size() == 0)
				throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After int must follow variable name", iScriptText[i].PositionInOriginalScriptText());

			if(line.NextSymbol() == ';')
				{
				if(variablePool->ExistVariable_int(st2) == false)
					variablePool->AddLocalVariable(st2, (int)0);
				continue;
				}

			if(line.NextSymbol() == '(')
				{
				int* variable(NULL);
				if(variablePool->ExistVariable_int(st2) == false)
					variablePool->AddLocalVariable(st2, (int)0);

				variablePool->GetPointerToVariable(st2, variable);
				assert(variable!=NULL);
				
				int* argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, argument, line);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}
				
				assert(argument!=NULL);

				CScriptAction* sa = new TScriptAction_Set<int, int>(variable, argument);
				curScriptChain->Add(sa);
				continue;							
				}

			if(line.NextSymbol() == '=')
				{
				line.ScanNextSymbol();
				int* variable(NULL);
				if(variablePool->ExistVariable_int(st2) == false)
					variablePool->AddLocalVariable(st2, (int)0);

				variablePool->GetPointerToVariable(st2, variable);
				assert(variable!=NULL);
				
				int* argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, argument, line);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}
				
				assert(argument!=NULL);

				CScriptAction* sa = new TScriptAction_Set<int, int>(variable, argument);
				curScriptChain->Add(sa);
				continue;							
				}

			//undefined symbol
			throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
			}

//FLOAT
		if(st1 == L"float")
			{
			line.ScanVariable();
			wstring st2 = line.ScanVariable(); // Variable name

			if(st2.size() == 0)
				throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After float must follow variable name", iScriptText[i].PositionInOriginalScriptText());

			if(line.NextSymbol() == ';')
				{
				if(variablePool->ExistVariable_float(st2) == false)
					variablePool->AddLocalVariable(st2, (float)0);
				continue;
				}

			if(line.NextSymbol() == '(')
				{
				float* variable(NULL);
				if(variablePool->ExistVariable_float(st2) == false)
					variablePool->AddLocalVariable(st2, (float)0);

				variablePool->GetPointerToVariable(st2, variable);
				assert(variable!=NULL);
				
				float* argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, argument, line);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}
				
				assert(argument!=NULL);

				CScriptAction* sa = new TScriptAction_Set<float, float>(variable, argument);
				curScriptChain->Add(sa);
				continue;							
				}

			if(line.NextSymbol() == '=')
				{
				line.ScanNextSymbol();
				float* variable(NULL);
				if(variablePool->ExistVariable_float(st2) == false)
					variablePool->AddLocalVariable(st2, (float)0);

				variablePool->GetPointerToVariable(st2, variable);
				assert(variable!=NULL);
				
				float* argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, argument, line);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}
				
				assert(argument!=NULL);

				CScriptAction* sa = new TScriptAction_Set<float, float>(variable, argument);
				curScriptChain->Add(sa);
				continue;							
				}

			//undefined symbol
			throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
			}

//BOOL
		if(st1 == L"bool")
			{
			line.ScanVariable();
			wstring st2 = line.ScanVariable(); // Variable name

			if(st2.size() == 0)
				throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After bool must follow variable name", iScriptText[i].PositionInOriginalScriptText());

			if(line.NextSymbol() == ';')
				{
				if(variablePool->ExistVariable_bool(st2) == false)
					variablePool->AddLocalVariable(st2, (bool)true);
				continue;
				}

			if(line.NextSymbol() == '(')
				{
				bool* variable(NULL);
				if(variablePool->ExistVariable_bool(st2) == false)
					variablePool->AddLocalVariable(st2, (bool)true);

				variablePool->GetPointerToVariable(st2, variable);
				assert(variable!=NULL);
				
				bool* argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, argument, line);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}
				
				assert(argument!=NULL);

				*variable = *argument;
				CScriptAction* sa = new TScriptAction_Set<bool, bool>(variable, argument);
				curScriptChain->Add(sa);
				continue;							
				}

			if(line.NextSymbol() == '=')
				{
				line.ScanNextSymbol();
				bool* variable(NULL);
				if(variablePool->ExistVariable_bool(st2) == false)
					variablePool->AddLocalVariable(st2, (bool)true);

				variablePool->GetPointerToVariable(st2, variable);
				assert(variable!=NULL);
				
				bool* argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, argument, line);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}
				
				assert(argument!=NULL);

				CScriptAction* sa = new TScriptAction_Set<bool, bool>(variable, argument);
				curScriptChain->Add(sa);
				continue;							
				}

			//undefined symbol
			throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());
			}

//FUNCTION CALL
		if(functionPool->ExistFunction(st1))
			{
			CFunctionDefinition definition = functionPool->GetFunctionDefinition(st1);
			switch(definition.ReturnType())
				{
				case CFunctionDefinition::e_Int:			{
															int* var(NULL);

															try	{
																EvoluteFunction(curScriptChain, var, line);
																}
															catch(CException_ScriptError& Exception)
																{
																Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
																throw Exception;
																}

															assert(var!=NULL);
															continue;
															break;
															}

				case CFunctionDefinition::e_Float:			{
															float* var(NULL);

															try	{
																EvoluteFunction(curScriptChain, var, line);
																}
															catch(CException_ScriptError& Exception)
																{
																Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
																throw Exception;
																}

															assert(var!=NULL);
															continue;
															break;
															}

				case CFunctionDefinition::e_String:			{
															wstring* var(NULL);

															try	{
																EvoluteFunction(curScriptChain, var, line);
																}
															catch(CException_ScriptError& Exception)
																{
																Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
																throw Exception;
																}

															assert(var!=NULL);
															continue;
															break;
															}

				case CFunctionDefinition::e_Bool:			{
															bool* var(NULL);

															try	{
																EvoluteFunction(curScriptChain, var, line);
																}
															catch(CException_ScriptError& Exception)
																{
																Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
																throw Exception;
																}

															assert(var!=NULL);
															continue;
															break;
															}

				case CFunctionDefinition::e_Void:			{

															try	{
																EvoluteFunction(curScriptChain, line);
																}
															catch(CException_ScriptError& Exception)
																{
																Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
																throw Exception;
																}

															continue;
															break;
															}

				default:									{
															//unsuported return type
															assert(false && L"TScript<T>::CompileChain - invalid function return type");
															}
										
				}
			}

//Variable Operations
		if(variablePool->ExistVariable(st1))
			{
			line.ScanVariable();

			//STRING
			if(variablePool->ExistVariable_string(st1))
				{
				wstring st2 = line.ScanBoolean();

				if(st2 == L"=")
					{
					wstring* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					wstring* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<wstring, wstring>(var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"+=")
					{
					wstring* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					wstring* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Sum<wstring, wstring, wstring>(var, var, argument);
					curScriptChain->Add(sa);
					continue;	
					}

				//undefined symbol
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());			
				}

			//BOOL
			if(variablePool->ExistVariable_bool(st1))
				{
				wstring st2 = line.ScanBoolean();

				if(st2 == L"=")
					{
					bool* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					bool* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<bool, bool>(var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"*=")
					{
					bool* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					bool* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Multiply<bool, bool, bool>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				//undefined symbol
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());				
				}

			//INT
			if(variablePool->ExistVariable_int(st1))
				{
				wstring st2 = line.ScanBoolean();

				if(st2 == L"=")
					{
					int* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					int* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<int, int>(var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"+=")
					{
					int* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					int* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Sum<int, int, int>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"-=")
					{
					int* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					int* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Minus<int, int, int>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"*=")
					{
					int* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					int* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Multiply<int, int, int>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"/=")
					{
					int* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					int* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Divide<int, int, int>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"++")
					{
					int* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					int* argument = new int(1);
					variablePool->AddWorkingVariable(argument);					

					CScriptAction* sa = new TScriptAction_Sum<int, int, int>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}


				//undefined symbol
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());	
				}

			//FLOAT
			if(variablePool->ExistVariable_float(st1))
				{
				wstring st2 = line.ScanBoolean();

				if(st2 == L"=")
					{
					float* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					float* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<float, float>(var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"+=")
					{
					float* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					float* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Sum<float, float, float>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"-=")
					{
					float* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					float* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Minus<float, float, float>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"*=")
					{
					float* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					float* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Multiply<float, float, float>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}


				if(st2 == L"/=")
					{
					float* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					float* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
				
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Divide<float, float, float>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				if(st2 == L"++")
					{
					float* var(NULL);
					variablePool->GetPointerToVariable(st1, var);
					assert(var!=NULL);

					float* argument = new float(1);
					variablePool->AddWorkingVariable(argument);					

					CScriptAction* sa = new TScriptAction_Sum<float, float, float>(var, var, argument);
					curScriptChain->Add(sa);
					continue;					
					}

				//undefined symbol
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());	
				}

			//undefined symbol
			throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());	
			}

//CALL
		if(st1 == L"call")
			{
			line.ScanVariable();
			unsigned chainNumber((unsigned)line.ScanFloat());
			
			if(chainNumber > scriptChain.size())
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Calling non existing chain.", iScriptText[i].PositionInOriginalScriptText());	

			CScriptAction* sa = new TScriptAction_RunChain<CScriptChain>(scriptChain[chainNumber]);
			curScriptChain->Add(sa);	
			CompileChain(chainNumber);
			continue;
			}

//IF
		if(st1 == L"if")
			{
			line.ScanVariable();

			if(line.ScanNextSymbol()!='(')
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing ( symbol.", iScriptText[i].PositionInOriginalScriptText());

			wstring leftSide(L"");
			wstring boolean(L"");
			wstring rightSide(L"");

			line.ScanConditional(leftSide, boolean, rightSide);

			CScriptString lSide(leftSide.c_str());
			CScriptString rSide(rightSide.c_str());	

			if(line.ScanNextSymbol()!=')')
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing ) symbol.", iScriptText[i].PositionInOriginalScriptText());

			//Scan IF true part
			wstring ifTrueExp(L"");
			while(true)
				{
				line.Omit();
				ifTrueExp = line.ScanToSymbol(';');
				if(ifTrueExp.size() == 0)
					{
					i++;
					if(i == iScriptText.size())
						throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "After if statement must follow do statement.", iScriptText[i].PositionInOriginalScriptText());

					line = iScriptText[i].c_str();
					}
				else
					{
					line.ScanNextSymbol();
					break;
					}
				}

			wstring ifFalseExp(L"");
				while(ifFalseExp.size() == 0)
				{
				line.Omit();
				if(line.End()==true)
					{
					i++;
					if(i == iScriptText.size())
						break;

					line = iScriptText[i].c_str();
					continue;
					}
				else
					{
					if(line.NextVariable() == L"else")
						{
						line.ScanVariable();

						while(true)
							{
							line.Omit();
							ifFalseExp = line.ScanToSymbol(';');
							if(ifFalseExp.size() == 0)
								{
								i++;
								if(i == iScriptText.size())
									throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "After else statement must follow do statement.", iScriptText[i].PositionInOriginalScriptText());

								line = iScriptText[i].c_str();
								}
							else
								{
								line.ScanNextSymbol();
								break;
								}
							}
						}
					else
						break;


					}
					}

			CScriptChain* truePart = new CScriptChain();
			truePart->AddScriptLine(CScriptLine(ifTrueExp, iScriptText[i].PositionInOriginalScriptText()));
			scriptChain.push_back(truePart);
			CompileChain(scriptChain.size()-1);

			CScriptChain* falsePart = new CScriptChain();
			falsePart->AddScriptLine(CScriptLine(ifFalseExp, iScriptText[i].PositionInOriginalScriptText()));
			scriptChain.push_back(falsePart);	
			CompileChain(scriptChain.size()-1);
	

			CFunctionDefinition::EFunctionArgumentType leftSideExpressionType = GetFirstOccuredVariableType(leftSide);
			CFunctionDefinition::EFunctionArgumentType rightSideExpressionType = GetFirstOccuredVariableType(rightSide);

			if(leftSideExpressionType == CFunctionDefinition::e_Bool || rightSideExpressionType == CFunctionDefinition::e_Bool)
				{
				bool* left_argument(NULL);
				bool* right_argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, left_argument, lSide);
					EvoluteExpression(curScriptChain, right_argument, rSide);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}

				assert(left_argument!=NULL);
				assert(right_argument!=NULL);

				if(boolean == L"==")
					{
					CScriptAction* sa = new TScriptAction_If_Equal<bool, bool>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"!=")
					{
					CScriptAction* sa = new TScriptAction_If_NotEqual<bool, bool>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Invalid comparison sign used for boolean variables.", iScriptText[i].PositionInOriginalScriptText());
				}

			else

			if(leftSideExpressionType == CFunctionDefinition::e_String || rightSideExpressionType == CFunctionDefinition::e_String)
				{
				wstring* left_argument(NULL);
				wstring* right_argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, left_argument, lSide);
					EvoluteExpression(curScriptChain, right_argument, rSide);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}

				assert(left_argument!=NULL);
				assert(right_argument!=NULL);
		
				if(boolean == L"==")
					{
					CScriptAction* sa = new TScriptAction_If_Equal<wstring, wstring>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"!=")
					{
					CScriptAction* sa = new TScriptAction_If_NotEqual<wstring, wstring>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Invalid comparison sign used for string variables.", iScriptText[i].PositionInOriginalScriptText());
				}
			
			else

			if(leftSideExpressionType == CFunctionDefinition::e_Int && rightSideExpressionType == CFunctionDefinition::e_Int)
				{
				int* left_argument(NULL);
				int* right_argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, left_argument, lSide);
					EvoluteExpression(curScriptChain, right_argument, rSide);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}

				assert(left_argument!=NULL);
				assert(right_argument!=NULL);

				if(boolean == L"==")
					{
					CScriptAction* sa = new TScriptAction_If_Equal<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"!=")
					{
					CScriptAction* sa = new TScriptAction_If_NotEqual<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L">=")
					{
					CScriptAction* sa = new TScriptAction_If_GreaterEqual<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<=")
					{
					CScriptAction* sa = new TScriptAction_If_LessEqual<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}


				if(boolean == L">")
					{
					CScriptAction* sa = new TScriptAction_If_Greater<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<")
					{
					CScriptAction* sa = new TScriptAction_If_Less<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}


				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Invalid comparison sign used for int variables.", iScriptText[i].PositionInOriginalScriptText());
				}

			else//for float and int

				{
				float* left_argument(NULL);
				float* right_argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, left_argument, lSide);
					EvoluteExpression(curScriptChain, right_argument, rSide);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}

				assert(left_argument!=NULL);
				assert(right_argument!=NULL);

				if(boolean == L"==")
					{
					CScriptAction* sa = new TScriptAction_If_Equal<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"!=")
					{
					CScriptAction* sa = new TScriptAction_If_NotEqual<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L">=")
					{
					CScriptAction* sa = new TScriptAction_If_GreaterEqual<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<=")
					{
					CScriptAction* sa = new TScriptAction_If_LessEqual<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}


				if(boolean == L">")
					{
					CScriptAction* sa = new TScriptAction_If_Greater<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<")
					{
					CScriptAction* sa = new TScriptAction_If_Less<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(truePart), new TScriptAction_RunChain<CScriptChain>(falsePart));
					curScriptChain->Add(sa);
					continue;
					}


				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Invalid comparison sign used for float or int variables.", iScriptText[i].PositionInOriginalScriptText());
				}


			assert(false && L"TScript<T>::CompileChain - invalid variable type used.");
			}

//WHILE
		if(st1 == L"while")
			{
			line.ScanVariable();

			if(line.ScanNextSymbol()!='(')
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing ( symbol.", iScriptText[i].PositionInOriginalScriptText());

			wstring leftSide(L"");
			wstring boolean(L"");
			wstring rightSide(L"");

			line.ScanConditional(leftSide, boolean, rightSide);

			CScriptString lSide(leftSide.c_str());
			CScriptString rSide(rightSide.c_str());	

			if(line.ScanNextSymbol()!=')')
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing ) symbol.", iScriptText[i].PositionInOriginalScriptText());

			//Scan do part
			wstring doExp(L"");
			while(true)
				{
				line.Omit();
				doExp = line.ScanToSymbol(';');
				if(doExp.size() == 0)
					{
					i++;
					if(i == iScriptText.size())
						throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "After while statement must follow do statement.", iScriptText[i].PositionInOriginalScriptText());

					line = iScriptText[i].c_str();
					}
				else
					{
					line.ScanNextSymbol();
					break;
					}
				}

			CScriptChain* doPart = new CScriptChain();
			doPart->AddScriptLine(CScriptLine(doExp, iScriptText[i].PositionInOriginalScriptText()));
			scriptChain.push_back(doPart);
			CompileChain(scriptChain.size()-1);

			CFunctionDefinition::EFunctionArgumentType leftSideExpressionType = GetFirstOccuredVariableType(leftSide);
			CFunctionDefinition::EFunctionArgumentType rightSideExpressionType = GetFirstOccuredVariableType(rightSide);

			if(leftSideExpressionType == CFunctionDefinition::e_Bool || rightSideExpressionType == CFunctionDefinition::e_Bool)
				{
				CScriptChain* conditionPart = new CScriptChain();
				
				bool* left_argument(NULL);
				bool* right_argument(NULL);

				try	{
					EvoluteExpression(conditionPart, left_argument, lSide);
					EvoluteExpression(conditionPart, right_argument, rSide);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}

				assert(left_argument!=NULL);
				assert(right_argument!=NULL);

				scriptChain.push_back(conditionPart);
				CompileChain(scriptChain.size()-1);

				if(boolean == L"==")
					{
					CScriptAction* sa = new TScriptAction_While_Equal<bool, bool>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"!=")
					{
					CScriptAction* sa = new TScriptAction_While_NotEqual<bool, bool>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Invalid comparison sign used for boolean variables.", iScriptText[i].PositionInOriginalScriptText());
				}

			else

			if(leftSideExpressionType == CFunctionDefinition::e_String || rightSideExpressionType == CFunctionDefinition::e_String)
				{
				CScriptChain* conditionPart = new CScriptChain();

				wstring* left_argument(NULL);
				wstring* right_argument(NULL);

				try	{
					EvoluteExpression(conditionPart, left_argument, lSide);
					EvoluteExpression(conditionPart, right_argument, rSide);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}

				assert(left_argument!=NULL);
				assert(right_argument!=NULL);

				scriptChain.push_back(conditionPart);
				CompileChain(scriptChain.size()-1);

				if(boolean == L"==")
					{
					CScriptAction* sa = new TScriptAction_While_Equal<wstring, wstring>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"!=")
					{
					CScriptAction* sa = new TScriptAction_While_NotEqual<wstring, wstring>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Invalid comparison sign used for string variables.", iScriptText[i].PositionInOriginalScriptText());
				}
			
			else

			if(leftSideExpressionType == CFunctionDefinition::e_Int && rightSideExpressionType == CFunctionDefinition::e_Int)
				{
				CScriptChain* conditionPart = new CScriptChain();

				int* left_argument(NULL);
				int* right_argument(NULL);

				try	{
					EvoluteExpression(conditionPart, left_argument, lSide);
					EvoluteExpression(conditionPart, right_argument, rSide);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}

				assert(left_argument!=NULL);
				assert(right_argument!=NULL);

				scriptChain.push_back(conditionPart);
				CompileChain(scriptChain.size()-1);

				if(boolean == L"==")
					{
					CScriptAction* sa = new TScriptAction_While_Equal<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"!=")
					{
					CScriptAction* sa = new TScriptAction_While_NotEqual<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L">=")
					{
					CScriptAction* sa = new TScriptAction_While_GreaterEqual<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<=")
					{
					CScriptAction* sa = new TScriptAction_While_LessEqual<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}


				if(boolean == L">")
					{
					CScriptAction* sa = new TScriptAction_While_Greater<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<")
					{
					CScriptAction* sa = new TScriptAction_While_Less<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}


				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Invalid comparison sign used for int variables.", iScriptText[i].PositionInOriginalScriptText());
				}

			else//for float and int

				{
				CScriptChain* conditionPart = new CScriptChain();

				float* left_argument(NULL);
				float* right_argument(NULL);

				try	{
					EvoluteExpression(conditionPart, left_argument, lSide);
					EvoluteExpression(conditionPart, right_argument, rSide);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}

				assert(left_argument!=NULL);
				assert(right_argument!=NULL);
			
				scriptChain.push_back(conditionPart);
				CompileChain(scriptChain.size()-1);

				if(boolean == L"==")
					{
					CScriptAction* sa = new TScriptAction_While_Equal<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"!=")
					{
					CScriptAction* sa = new TScriptAction_While_NotEqual<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L">=")
					{
					CScriptAction* sa = new TScriptAction_While_GreaterEqual<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<=")
					{
					CScriptAction* sa = new TScriptAction_While_LessEqual<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}


				if(boolean == L">")
					{
					CScriptAction* sa = new TScriptAction_While_Greater<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<")
					{
					CScriptAction* sa = new TScriptAction_While_Less<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart));
					curScriptChain->Add(sa);
					continue;
					}


				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Invalid comparison sign used for int or float variables.", iScriptText[i].PositionInOriginalScriptText());
				}


			assert(false && L"TScript<T>::CompileChain - invalid variable type used.");
			}

//FOR
		if(st1 == L"for")
			{
			line.ScanVariable();

			if(line.ScanNextSymbol()!='(')
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing ( symbol.", iScriptText[i].PositionInOriginalScriptText());
		
			//Initialization part

			if(line.NextSymbol() == ';')
				{
				//do nothing
				}
			else					
			if(line.NextVariable() == L"int")
				{
				line.ScanVariable();
				wstring st2 = line.ScanVariable(); // Variable name

				if(st2.size() == 0)
					throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After int must follow variable name", iScriptText[i].PositionInOriginalScriptText());

				if(line.ScanNextSymbol() != '=')
					throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing = symbol.", iScriptText[i].PositionInOriginalScriptText());

				int* variable(NULL);
				if(variablePool->ExistVariable_int(st2) == false)
					variablePool->AddLocalVariable(st2, (int)0);

				variablePool->GetPointerToVariable(st2, variable);
				assert(variable!=NULL);
				
				int* argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, argument, line);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}
			
				assert(argument!=NULL);

				CScriptAction* sa = new TScriptAction_Set<int, int>(variable, argument);
				curScriptChain->Add(sa);		
				}
			else					
			if(line.NextVariable() == L"float")
				{
				line.ScanVariable();
				wstring st2 = line.ScanVariable(); // Variable name

				if(st2.size() == 0)
					throw CException_ScriptError_MissingVariableName("TScript<T>::CompileChain", "After float must follow variable name", iScriptText[i].PositionInOriginalScriptText());

				if(line.ScanNextSymbol() != '=')
					throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing = symbol.", iScriptText[i].PositionInOriginalScriptText());

				float* variable(NULL);
				if(variablePool->ExistVariable_int(st2) == false)
					variablePool->AddLocalVariable(st2, (float)0);

				variablePool->GetPointerToVariable(st2, variable);
				assert(variable!=NULL);
				
				float* argument(NULL);

				try	{
					EvoluteExpression(curScriptChain, argument, line);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}
				
				assert(argument!=NULL);

				CScriptAction* sa = new TScriptAction_Set<float, float>(variable, argument);
				curScriptChain->Add(sa);		
				}
			else
			if(variablePool->ExistVariable(line.NextVariable()))
				{
				wstring s3 = line.ScanVariable(); //variable name
				
				if(variablePool->ExistVariable_int(s3))
					{
					if(line.ScanNextSymbol() != '=')
						throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing = symbol.", iScriptText[i].PositionInOriginalScriptText());

					int* variable(NULL);
					variablePool->GetPointerToVariable(s3, variable);
					assert(variable!=NULL);
					
					int* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<int, int>(variable, argument);
					curScriptChain->Add(sa);		
					}
				else
				if(variablePool->ExistVariable_float(s3))
					{
					if(line.ScanNextSymbol() != '=')
						throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing = symbol.", iScriptText[i].PositionInOriginalScriptText());

					float* variable(NULL);
					variablePool->GetPointerToVariable(s3, variable);
					assert(variable!=NULL);
					
					float* argument(NULL);

					try	{
						EvoluteExpression(curScriptChain, argument, line);
						}
					catch(CException_ScriptError& Exception)
						{
						Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
						throw Exception;
						}
					
					assert(argument!=NULL);

					CScriptAction* sa = new TScriptAction_Set<float, float>(variable, argument);
					curScriptChain->Add(sa);		
					}
				else
					throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "For statement support only int and float variables.", iScriptText[i].PositionInOriginalScriptText());			
				}
			else
				throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());	

			if(line.ScanNextSymbol() != ';')
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing ; symbol.", iScriptText[i].PositionInOriginalScriptText());

			
			//Scan conditional part********************
			i++;
			if(i == iScriptText.size())
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Incomplete for statement.", iScriptText[i].PositionInOriginalScriptText());
			line = iScriptText[i].c_str();

			wstring leftSide(L"");
			wstring boolean(L"");
			wstring rightSide(L"");

			line.ScanConditional(leftSide, boolean, rightSide);

			CScriptString lSide(leftSide.c_str());
			CScriptString rSide(rightSide.c_str());	

			if(line.ScanNextSymbol()!=';')
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing ; symbol.", iScriptText[i].PositionInOriginalScriptText());

			//Scan Incriment part***********************
			i++;
			if(i == iScriptText.size())
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Incomplete for statement.", iScriptText[i].PositionInOriginalScriptText());
			line = iScriptText[i].c_str();

			CScriptChain* incrementPart = new CScriptChain();
			
			wstring s3 = line.ScanVariable(); //variable name
			//Variable Operations
			if(variablePool->ExistVariable(s3))
				{
				line.ScanVariable();

				//INT
				if(variablePool->ExistVariable_int(s3))
					{
					wstring st2 = line.ScanBoolean();

					if(st2 == L"+=")
						{
						int* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						int* argument(NULL);

						try	{
							EvoluteExpression(incrementPart, argument, line);
							}
						catch(CException_ScriptError& Exception)
							{
							Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
							throw Exception;
							}
				
						assert(argument!=NULL);

						CScriptAction* sa = new TScriptAction_Sum<int, int, int>(var, var, argument);
						incrementPart->Add(sa);			
						}
					else
					if(st2 == L"-=")
						{
						int* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						int* argument(NULL);

						try	{
							EvoluteExpression(incrementPart, argument, line);
							}
						catch(CException_ScriptError& Exception)
							{
							Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
							throw Exception;
							}
					
						assert(argument!=NULL);

						CScriptAction* sa = new TScriptAction_Minus<int, int, int>(var, var, argument);
						incrementPart->Add(sa);					
						}
					else
					if(st2 == L"*=")
						{
						int* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						int* argument(NULL);

						try	{
							EvoluteExpression(incrementPart, argument, line);
							}
						catch(CException_ScriptError& Exception)
							{
							Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
							throw Exception;
							}
					
						assert(argument!=NULL);

						CScriptAction* sa = new TScriptAction_Multiply<int, int, int>(var, var, argument);
						incrementPart->Add(sa);				
						}
					else
					if(st2 == L"/=")
						{
						int* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						int* argument(NULL);

						try	{
							EvoluteExpression(incrementPart, argument, line);
							}
						catch(CException_ScriptError& Exception)
							{
							Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
							throw Exception;
							}
					
						assert(argument!=NULL);

						CScriptAction* sa = new TScriptAction_Divide<int, int, int>(var, var, argument);
						incrementPart->Add(sa);				
						}
					else
					if(st2 == L"++")
						{
						int* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						int* argument = new int(1);
						variablePool->AddWorkingVariable(argument);					

						CScriptAction* sa = new TScriptAction_Sum<int, int, int>(var, var, argument);
						incrementPart->Add(sa);				
						}
					else
						throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());	
					}
				else
				//FLOAT
				if(variablePool->ExistVariable_float(s3))
					{
					wstring st2 = line.ScanBoolean();

					if(st2 == L"=")
						{
						float* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						float* argument(NULL);

						try	{
							EvoluteExpression(incrementPart, argument, line);
							}
						catch(CException_ScriptError& Exception)
							{
							Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
							throw Exception;
							}
					
						assert(argument!=NULL);

						CScriptAction* sa = new TScriptAction_Set<float, float>(var, argument);
						incrementPart->Add(sa);					
						}
					else
					if(st2 == L"+=")
						{
						float* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						float* argument(NULL);

						try	{
							EvoluteExpression(incrementPart, argument, line);
							}
						catch(CException_ScriptError& Exception)
							{
							Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
							throw Exception;
							}
					
						assert(argument!=NULL);

						CScriptAction* sa = new TScriptAction_Sum<float, float, float>(var, var, argument);
						incrementPart->Add(sa);				
						}
					else
					if(st2 == L"-=")
						{
						float* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						float* argument(NULL);

						try	{
							EvoluteExpression(incrementPart, argument, line);
							}
						catch(CException_ScriptError& Exception)
							{
							Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
							throw Exception;
							}
					
						assert(argument!=NULL);

						CScriptAction* sa = new TScriptAction_Minus<float, float, float>(var, var, argument);
						incrementPart->Add(sa);				
						}
					else
					if(st2 == L"*=")
						{
						float* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						float* argument(NULL);

						try	{
							EvoluteExpression(incrementPart, argument, line);
							}
						catch(CException_ScriptError& Exception)
							{
							Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
							throw Exception;
							}
					
						assert(argument!=NULL);

						CScriptAction* sa = new TScriptAction_Multiply<float, float, float>(var, var, argument);
						incrementPart->Add(sa);				
						}

					else
					if(st2 == L"/=")
						{
						float* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						float* argument(NULL);

						try	{
							EvoluteExpression(incrementPart, argument, line);
							}
						catch(CException_ScriptError& Exception)
							{
							Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
							throw Exception;
							}
					
						assert(argument!=NULL);

						CScriptAction* sa = new TScriptAction_Divide<float, float, float>(var, var, argument);
						incrementPart->Add(sa);				
						}
					else
					if(st2 == L"++")
						{
						float* var(NULL);
						variablePool->GetPointerToVariable(s3, var);
						assert(var!=NULL);

						float* argument = new float(1);
						variablePool->AddWorkingVariable(argument);					

						CScriptAction* sa = new TScriptAction_Sum<float, float, float>(var, var, argument);
						incrementPart->Add(sa);				
						}
					else
						throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());	
					}
				else
					throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "For statement support only int and float variables.", iScriptText[i].PositionInOriginalScriptText());		
				}
				else
					throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Incomplete for statement.", iScriptText[i].PositionInOriginalScriptText());

			scriptChain.push_back(incrementPart);
			CompileChain(scriptChain.size()-1);

			if(line.ScanNextSymbol()!=')')
				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Missing ) symbol.", iScriptText[i].PositionInOriginalScriptText());


			//Scan do part
			wstring doExp(L"");
			while(true)
				{
				line.Omit();
				doExp = line.ScanToSymbol(';');
				if(doExp.size() == 0)
					{
					i++;
					if(i == iScriptText.size())
						throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "After for statement must follow do statement.", iScriptText[i].PositionInOriginalScriptText());

					line = iScriptText[i].c_str();
					}
				else
					{
					line.ScanNextSymbol();
					break;
					}
				}

			CScriptChain* doPart = new CScriptChain();
			doPart->AddScriptLine(CScriptLine(doExp, iScriptText[i].PositionInOriginalScriptText()));
			scriptChain.push_back(doPart);
			CompileChain(scriptChain.size()-1);


			//For float and int
			CFunctionDefinition::EFunctionArgumentType leftSideExpressionType = GetFirstOccuredVariableType(leftSide);
			CFunctionDefinition::EFunctionArgumentType rightSideExpressionType = GetFirstOccuredVariableType(rightSide);


			if(leftSideExpressionType == CFunctionDefinition::e_Int && rightSideExpressionType == CFunctionDefinition::e_Int)
				{
				CScriptChain* conditionPart = new CScriptChain();

				int* left_argument(NULL);
				int* right_argument(NULL);

				try	{
					EvoluteExpression(conditionPart, left_argument, lSide);
					EvoluteExpression(conditionPart, right_argument, rSide);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}

				assert(left_argument!=NULL);
				assert(right_argument!=NULL);

				scriptChain.push_back(conditionPart);
				CompileChain(scriptChain.size()-1);

				if(boolean == L"==")
					{
					CScriptAction* sa = new TScriptAction_For_Equal<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"!=")
					{
					CScriptAction* sa = new TScriptAction_For_NotEqual<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L">=")
					{
					CScriptAction* sa = new TScriptAction_For_GreaterEqual<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<=")
					{
					CScriptAction* sa = new TScriptAction_For_LessEqual<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}


				if(boolean == L">")
					{
					CScriptAction* sa = new TScriptAction_For_Greater<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<")
					{
					CScriptAction* sa = new TScriptAction_For_Less<int, int>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}


				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Invalid comparison sign used for int variables.", iScriptText[i].PositionInOriginalScriptText());
				}

			else//for float and int

				{
				CScriptChain* conditionPart = new CScriptChain();

				float* left_argument(NULL);
				float* right_argument(NULL);

				try	{
					EvoluteExpression(conditionPart, left_argument, lSide);
					EvoluteExpression(conditionPart, right_argument, rSide);
					}
				catch(CException_ScriptError& Exception)
					{
					Exception.SetLineNumber(iScriptText[i].PositionInOriginalScriptText());
					throw Exception;
					}

				assert(left_argument!=NULL);
				assert(right_argument!=NULL);
			
				scriptChain.push_back(conditionPart);
				CompileChain(scriptChain.size()-1);

				if(boolean == L"==")
					{
					CScriptAction* sa = new TScriptAction_For_Equal<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"!=")
					{
					CScriptAction* sa = new TScriptAction_For_NotEqual<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L">=")
					{
					CScriptAction* sa = new TScriptAction_For_GreaterEqual<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<=")
					{
					CScriptAction* sa = new TScriptAction_For_LessEqual<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}


				if(boolean == L">")
					{
					CScriptAction* sa = new TScriptAction_For_Greater<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}

				if(boolean == L"<")
					{
					CScriptAction* sa = new TScriptAction_For_Less<float, float>(left_argument, right_argument, new TScriptAction_RunChain<CScriptChain>(doPart), new TScriptAction_RunChain<CScriptChain>(conditionPart), new TScriptAction_RunChain<CScriptChain>(incrementPart));
					curScriptChain->Add(sa);
					continue;
					}


				throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "Invalid comparison sign used for float or int variables.", iScriptText[i].PositionInOriginalScriptText());
				}

			throw CException_ScriptError_SyntaxError("TScript<T>::CompileChain", "For statement support only int and float variables.", iScriptText[i].PositionInOriginalScriptText());		
			}


		//undefined symbol
		throw CException_ScriptError_UndefinedSymbol("TScript<T>::CompileChain", "", iScriptText[i].PositionInOriginalScriptText());	
		}
	}

//*****************************************************************************

}

}

#endif