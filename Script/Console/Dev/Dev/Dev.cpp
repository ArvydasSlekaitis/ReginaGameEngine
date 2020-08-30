// Dev.cpp : Defines the entry point for the console application.
//
#pragma warning( disable : 4290 )

#include "stdafx.h"

#include <iostream>
#include <assert.h>
using namespace std;

#include <TFunctionPool.h>
#include <CVariablePool.h>
#include <TScriptAction_Set.h>
#include <TScriptAction_Sum.h>
#include <TScriptAction_Minus.h>
#include <TScriptAction_Multiply.h>
#include <TScriptAction_Divide.h>
#include <TScriptAction_If_Equal.h>
#include <TScriptAction_If_Greater.h>
#include <TScriptAction_If_Less.h>
#include <TScriptAction_If_GreaterEqual.h>
#include <TScriptAction_If_LessEqual.h>
#include <TScriptAction_If_NotEqual.h>
#include <CExpressionEvolutor_Bool.h>
#include <CExpressionEvolutor_Int.h>
#include <CExpressionEvolutor_Float.h>
#include <CExpressionEvolutor_String.h>
#include <TScript.h>
#include <TScriptManager.h>
using namespace Regina::Script;


class MyClass
{
public:
	void Function1() { cout << "Function1" << endl; }
	void Function2() { cout << "Function2" << endl; }
	void Function3(bool iArgument) { cout << "Function3 - Argument bool - " << iArgument << endl; }
	void Function4(int iArgument) { cout << "Function4 - Argument int - " << iArgument << endl; }
	void Function5(float iArgument) { cout << "Function5 - Argument float - " << iArgument << endl; }
	void Function6(string iArgument) { cout << "Function6 - Argument string - " << iArgument << endl; }

	bool Function7() { cout << "Function7 - Argument none - Returning bool" << endl; return true; }
	bool Function8(bool iArgument) { cout << "Function8 - Argument bool - Returning bool - " << iArgument << endl; return iArgument; }
	bool Function9(int iArgument) { cout << "Function9 - Argument int - Returning bool - " << iArgument << endl; return true; }
	bool Function10(float iArgument) { cout << "Function10 - Argument float - Returning bool - " << iArgument << endl; return false; }
	bool Function11(string iArgument) { cout << "Function11 - Argument string - Returning bool - " << iArgument << endl; return true; }

	int Function12() { cout << "Function12 - Argument none - Returning int" << endl; return 12; }
	int Function13(bool iArgument) { cout << "Function13 - Argument bool - Returning int - " << iArgument << endl; return 13; }
	int Function14(int iArgument) { cout << "Function14 - Argument int - Returning int - " << iArgument << endl; return 14; }
	int Function15(float iArgument) { cout << "Function15 - Argument float - Returning int - " << iArgument << endl; return 15; }
	int Function16(string iArgument) { cout << "Function16 - Argument string - Returning int - " << iArgument << endl; return 16; }

	float Function17() { cout << "Function17 - Argument none - Returning float" << endl; return 17.0f; }
	float Function18(bool iArgument) { cout << "Function18 - Argument bool - Returning float - " << iArgument << endl; return 18.0f; }
	float Function19(int iArgument) { cout << "Function19 - Argument int - Returning float - " << iArgument << endl; return 19.0f; }
	float Function20(float iArgument) { cout << "Function20 - Argument float - Returning float - " << iArgument << endl; return 20.0f; }
	float Function21(string iArgument) { cout << "Function21 - Argument string - Returning float - " << iArgument << endl; return 21.0f; }

	string Function22() { cout << "Function22 - Argument none - Returning string" << endl; return "Function22"; }
	string Function23(bool iArgument) { cout << "Function23 - Argument bool - Returning string - " << iArgument << endl; return "Function23"; }
	string Function24(int iArgument) { cout << "Function24 - Argument int - Returning string - " << iArgument << endl; return "Function24"; }
	string Function25(float iArgument) { cout << "Function25 - Argument float - Returning string - " << iArgument << endl; return "Function25"; }
	string Function26(string iArgument) { cout << "Function26 - Argument string - Returning string - " << iArgument << endl; return "Function26"; }
};

int _tmain(int argc, _TCHAR* argv[])
{/*
MyClass mc;
bool oReturnValueBool;
int oReturnValueInt;
float oReturnValueFloat;
string oReturnValueString;
TFunctionPool<MyClass> functionPool(&mc);
functionPool.AddFunction("Function1", &MyClass::Function1);
functionPool.AddFunction("Function2", &MyClass::Function2);
functionPool.AddFunction("Function3", &MyClass::Function3);
functionPool.AddFunction("Function4", &MyClass::Function4);
functionPool.AddFunction("Function5", &MyClass::Function5);
functionPool.AddFunction("Function6", &MyClass::Function6);
functionPool.AddFunction("Function7", &MyClass::Function7);
functionPool.AddFunction("Function8", &MyClass::Function8);
functionPool.AddFunction("Function9", &MyClass::Function9);
functionPool.AddFunction("Function10", &MyClass::Function10);
functionPool.AddFunction("Function11", &MyClass::Function11);
functionPool.AddFunction("Function12", &MyClass::Function12);
functionPool.AddFunction("Function13", &MyClass::Function13);
functionPool.AddFunction("Function14", &MyClass::Function14);
functionPool.AddFunction("Function15", &MyClass::Function15);
functionPool.AddFunction("Function16", &MyClass::Function16);
functionPool.AddFunction("Function17", &MyClass::Function17);
functionPool.AddFunction("Function18", &MyClass::Function18);
functionPool.AddFunction("Function19", &MyClass::Function19);
functionPool.AddFunction("Function20", &MyClass::Function20);
functionPool.AddFunction("Function21", &MyClass::Function21);
functionPool.AddFunction("Function22", &MyClass::Function22);
functionPool.AddFunction("Function23", &MyClass::Function23);
functionPool.AddFunction("Function24", &MyClass::Function24);
functionPool.AddFunction("Function25", &MyClass::Function25);
functionPool.AddFunction("Function26", &MyClass::Function26);

functionPool.RunFunction("Function1");
functionPool.RunFunction("Function2");
functionPool.RunFunction("Function3", true);
functionPool.RunFunction("Function4", 15);
functionPool.RunFunction("Function5", 15.5f);
functionPool.RunFunction("Function6", string("Arvydas"));
functionPool.RunFunction("Function7", &oReturnValueBool);			assert(oReturnValueBool == true);
functionPool.RunFunction("Function8", false, &oReturnValueBool);    assert(oReturnValueBool == false);
functionPool.RunFunction("Function9", 25, &oReturnValueBool);		assert(oReturnValueBool == true);
functionPool.RunFunction("Function10", 25.5f, &oReturnValueBool);	assert(oReturnValueBool == false);
functionPool.RunFunction("Function11", string("Regina"), &oReturnValueBool);	assert(oReturnValueBool == true);

functionPool.RunFunction("Function12", &oReturnValueInt);			assert(oReturnValueInt == 12);
functionPool.RunFunction("Function13", false, &oReturnValueInt);    assert(oReturnValueInt == 13);
functionPool.RunFunction("Function14", 25, &oReturnValueInt);		assert(oReturnValueInt == 14);
functionPool.RunFunction("Function15", 25.5f, &oReturnValueInt);	assert(oReturnValueInt == 15);
functionPool.RunFunction("Function16", string("Regina"), &oReturnValueInt);	assert(oReturnValueInt == 16);

functionPool.RunFunction("Function17", &oReturnValueFloat);			assert(oReturnValueFloat == 17.0f);
functionPool.RunFunction("Function18", false, &oReturnValueFloat);  assert(oReturnValueFloat == 18.0f);
functionPool.RunFunction("Function19", 25, &oReturnValueFloat);		assert(oReturnValueFloat == 19.0f);
functionPool.RunFunction("Function20", 25.5f, &oReturnValueFloat);	assert(oReturnValueFloat == 20.0f);
functionPool.RunFunction("Function21", string("Regina"), &oReturnValueFloat);	assert(oReturnValueFloat == 21.0f);

functionPool.RunFunction("Function22", &oReturnValueString);		assert(oReturnValueString == "Function22");
functionPool.RunFunction("Function23", false, &oReturnValueString); assert(oReturnValueString == "Function23");
functionPool.RunFunction("Function24", 25, &oReturnValueString);	assert(oReturnValueString == "Function24");
functionPool.RunFunction("Function25", 25.5f, &oReturnValueString);	assert(oReturnValueString == "Function25");
functionPool.RunFunction("Function26", string("Regina"), &oReturnValueString);	assert(oReturnValueString == "Function26");

functionPool.RunFunction(functionPool.GetFunctionPosition_void_void("Function1"));
functionPool.RunFunction(functionPool.GetFunctionPosition_void_void("Function2"));
functionPool.RunFunction(functionPool.GetFunctionPosition_void_bool("Function3"), true);
functionPool.RunFunction(functionPool.GetFunctionPosition_void_int("Function4"), 15);
functionPool.RunFunction(functionPool.GetFunctionPosition_void_float("Function5"), 15.5f);
functionPool.RunFunction(functionPool.GetFunctionPosition_void_string("Function6"), string("Arvydas"));
functionPool.RunFunction(functionPool.GetFunctionPosition_bool_void("Function7"), &oReturnValueBool);			assert(oReturnValueBool == true);
functionPool.RunFunction(functionPool.GetFunctionPosition_bool_bool("Function8"), false, &oReturnValueBool);    assert(oReturnValueBool == false);
functionPool.RunFunction(functionPool.GetFunctionPosition_bool_int("Function9"), 25, &oReturnValueBool);		assert(oReturnValueBool == true);
functionPool.RunFunction(functionPool.GetFunctionPosition_bool_float("Function10"), 25.5f, &oReturnValueBool);	assert(oReturnValueBool == false);
functionPool.RunFunction(functionPool.GetFunctionPosition_bool_string("Function11"), string("Regina"), &oReturnValueBool);	assert(oReturnValueBool == true);

functionPool.RunFunction(functionPool.GetFunctionPosition_int_void("Function12"), &oReturnValueInt);			assert(oReturnValueInt == 12);
functionPool.RunFunction(functionPool.GetFunctionPosition_int_bool("Function13"), false, &oReturnValueInt);    assert(oReturnValueInt == 13);
functionPool.RunFunction(functionPool.GetFunctionPosition_int_int("Function14"), 25, &oReturnValueInt);		assert(oReturnValueInt == 14);
functionPool.RunFunction(functionPool.GetFunctionPosition_int_float("Function15"), 25.5f, &oReturnValueInt);	assert(oReturnValueInt == 15);
functionPool.RunFunction(functionPool.GetFunctionPosition_int_string("Function16"), string("Regina"), &oReturnValueInt);	assert(oReturnValueInt == 16);

functionPool.RunFunction(functionPool.GetFunctionPosition_float_void("Function17"), &oReturnValueFloat);			assert(oReturnValueFloat == 17.0f);
functionPool.RunFunction(functionPool.GetFunctionPosition_float_bool("Function18"), false, &oReturnValueFloat);  assert(oReturnValueFloat == 18.0f);
functionPool.RunFunction(functionPool.GetFunctionPosition_float_int("Function19"), 25, &oReturnValueFloat);		assert(oReturnValueFloat == 19.0f);
functionPool.RunFunction(functionPool.GetFunctionPosition_float_float("Function20"), 25.5f, &oReturnValueFloat);	assert(oReturnValueFloat == 20.0f);
functionPool.RunFunction(functionPool.GetFunctionPosition_float_string("Function21"), string("Regina"), &oReturnValueFloat);	assert(oReturnValueFloat == 21.0f);

functionPool.RunFunction(functionPool.GetFunctionPosition_string_void("Function22"), &oReturnValueString);		assert(oReturnValueString == "Function22");
functionPool.RunFunction(functionPool.GetFunctionPosition_string_bool("Function23"), false, &oReturnValueString); assert(oReturnValueString == "Function23");
functionPool.RunFunction(functionPool.GetFunctionPosition_string_int("Function24"), 25, &oReturnValueString);	assert(oReturnValueString == "Function24");
functionPool.RunFunction(functionPool.GetFunctionPosition_string_float("Function25"), 25.5f, &oReturnValueString);	assert(oReturnValueString == "Function25");
functionPool.RunFunction(functionPool.GetFunctionPosition_string_string("Function26"), string("Regina"), &oReturnValueString);	assert(oReturnValueString == "Function26");

//END OF FUNCTION POOL

//BEGIN OF VARIABLE POOL
CVariablePool variablePool;
variablePool.AddLocalVariable("MyBool1", true);
variablePool.GetVariableValue("MyBool1", oReturnValueBool);
/*assert(oReturnValueBool == true);
bool* bp;
variablePool.GetPointerToVariable("MyBool1", bp);
*bp = false;
variablePool.GetVariableValue("MyBool1", oReturnValueBool);
assert(oReturnValueBool == false);


*/
/*

	{
	bool t(true);
	bool f(false);
	bool* finalPointer = new bool();
	vector<CScriptAction*> oScriptAction;
	vector<bool*> oTempVariable;

	CExpressionEvolutor_Bool evolutor;
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	}

	{
	bool t(true);
	bool f(false);
	bool* finalPointer = new bool();
	vector<CScriptAction*> oScriptAction;
	vector<bool*> oTempVariable;

	CExpressionEvolutor_Bool evolutor;
	evolutor.AddParentheses_Opening();
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	}

	{
	bool t(true);
	bool f(false);
	bool* finalPointer = new bool();
	vector<CScriptAction*> oScriptAction;
	vector<bool*> oTempVariable;

	CExpressionEvolutor_Bool evolutor;
	evolutor.AddParentheses_Closing();
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	}

	{
	bool t(true);
	bool f(false);
	bool* finalPointer = new bool();
	vector<CScriptAction*> oScriptAction;
	vector<bool*> oTempVariable;

	CExpressionEvolutor_Bool evolutor;
	evolutor.AddParentheses_Opening();
	evolutor.AddParentheses_Closing();
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	}

	{
	bool t(true);
	bool f(false);
	bool* finalPointer = new bool(false);
	vector<CScriptAction*> oScriptAction;
	vector<bool*> oTempVariable;

	CExpressionEvolutor_Bool evolutor;
	evolutor.AddParentheses_Opening();
	evolutor.AddVariable(&t);
	evolutor.AddParentheses_Closing();
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	for(unsigned i = 0; i<oScriptAction.size(); i++)
		oScriptAction[i]->Execute();
	assert(*finalPointer == true);
	}

	{
	bool t(true);
	bool f(false);
	bool* finalPointer;
	vector<CScriptAction*> oScriptAction;
	vector<bool*> oTempVariable;

	CExpressionEvolutor_Bool evolutor;
	evolutor.AddParentheses_Opening();
	evolutor.AddVariable(&t);
	evolutor.AddParentheses_Closing();
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	for(unsigned i = 0; i<oScriptAction.size(); i++)
		oScriptAction[i]->Execute();
	assert(*finalPointer == true);
	}

	{
	bool t(true);
	bool f(false);
	bool* finalPointer;
	vector<CScriptAction*> oScriptAction;
	vector<bool*> oTempVariable;

	CExpressionEvolutor_Bool evolutor;
	//evolutor.AddParentheses_Opening();
	evolutor.AddVariable(&t);
	evolutor.AddSign_Multiply();
	evolutor.AddVariable(&t);
	//evolutor.AddParentheses_Closing();
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	for(unsigned i = 0; i<oScriptAction.size(); i++)
		oScriptAction[i]->Execute();
	assert(*finalPointer == true);
	}

	{
	bool t(true);
	bool f(false);
	bool* finalPointer;
	vector<CScriptAction*> oScriptAction;
	vector<bool*> oTempVariable;

	CExpressionEvolutor_Bool evolutor;
	evolutor.AddParentheses_Opening();
	evolutor.AddVariable(&t);
	evolutor.AddSign_Multiply();
	evolutor.AddVariable(&t);
	evolutor.AddParentheses_Closing();
	evolutor.AddSign_Multiply();
	evolutor.AddVariable(&f);
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	for(unsigned i = 0; i<oScriptAction.size(); i++)
		oScriptAction[i]->Execute();
	assert(*finalPointer == false);
	}

//////////////////////INT/////////////////////////////////////

	{
	int i1(10);
	int i2(15);
	int* finalPointer = new int();
	vector<CScriptAction*> oScriptAction;
	vector<int*> oTempVariable;

	CExpressionEvolutor_Int evolutor;
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	}

	{
	int i1(10);
	float i2(20);
	int* finalPointer = new int();
	vector<CScriptAction*> oScriptAction;
	vector<int*> oTempVariable;
	CExpressionEvolutor_Int evolutor;

	evolutor.AddParentheses_Opening();
	evolutor.AddVariable(&i1);
	evolutor.AddSign_Multiply();
	evolutor.AddVariable(&i1);
	evolutor.AddParentheses_Closing();
	evolutor.AddSign_Divide();
	evolutor.AddVariable(&i2);
	evolutor.AddSign_Plus();
	evolutor.AddVariable(&i2);
	evolutor.AddSign_Minus();
	evolutor.AddVariable(&i1);



	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);

	for(unsigned i = 0; i<oScriptAction.size(); i++)
		oScriptAction[i]->Execute();

	assert(*finalPointer == 15);
	}

	{
	int i1(10);
	float i2(20);
	int* finalPointer = new int();
	vector<CScriptAction*> oScriptAction;
	vector<int*> oTempVariable;
	CExpressionEvolutor_Int evolutor;
	
	evolutor.AddVariable(&i2);

	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);

	for(unsigned i = 0; i<oScriptAction.size(); i++)
		oScriptAction[i]->Execute();

	assert(*finalPointer == 20);
	}

//////////////////////FLOAT/////////////////////////////////////

	{
	int i1(10);
	float i2(15);
	float* finalPointer = new float();
	vector<CScriptAction*> oScriptAction;
	vector<float*> oTempVariable;

	CExpressionEvolutor_Float evolutor;
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	}

	{
	int i1(10);
	float i2(20);
	float* finalPointer = new float();
	vector<CScriptAction*> oScriptAction;
	vector<float*> oTempVariable;
	CExpressionEvolutor_Float evolutor;

	evolutor.AddParentheses_Opening();
	evolutor.AddVariable(&i1);
	evolutor.AddSign_Multiply();
	evolutor.AddVariable(&i1);
	evolutor.AddParentheses_Closing();
	evolutor.AddSign_Divide();
	evolutor.AddVariable(&i2);
	evolutor.AddSign_Plus();
	evolutor.AddVariable(&i2);
	evolutor.AddSign_Minus();
	evolutor.AddVariable(&i1);



	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);

	for(unsigned i = 0; i<oScriptAction.size(); i++)
		oScriptAction[i]->Execute();

	assert(*finalPointer == 15);
	}

	{
	int i1(10);
	float i2(20);
	float* finalPointer = new float();
	vector<CScriptAction*> oScriptAction;
	vector<float*> oTempVariable;
	CExpressionEvolutor_Float evolutor;
	
	evolutor.AddVariable(&i2);

	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);

	for(unsigned i = 0; i<oScriptAction.size(); i++)
		oScriptAction[i]->Execute();

	assert(*finalPointer == 20);
	}

//////////////////////STRING////////////////////////////////////

	{
	int i1(10);
	float i2(15);
	string i3("Ar");
	bool i4(true);

	string* finalPointer = new string();
	vector<CScriptAction*> oScriptAction;
	vector<string*> oTempVariable;

	CExpressionEvolutor_String evolutor;
	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);
	}

	{
	int i1(10);
	float i2(15);
	string i3("Ar");
	bool i4(true);

	string* finalPointer = new string();
	vector<CScriptAction*> oScriptAction;
	vector<string*> oTempVariable;

	CExpressionEvolutor_String evolutor;

	evolutor.AddVariable(&i1);
	evolutor.AddSign_Plus();
	evolutor.AddVariable(&i2);
	evolutor.AddSign_Plus();
	evolutor.AddVariable(&i3);
	evolutor.AddSign_Plus();
	evolutor.AddVariable(&i4);

	evolutor.Evolute(finalPointer, oScriptAction, oTempVariable);

	for(unsigned i = 0; i<oScriptAction.size(); i++)
		oScriptAction[i]->Execute();

	assert(*finalPointer == "1015Ar1");
	}

/*
	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string myStr(\"Labas\");");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Labas");
	delete varPool;

	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string myStr(\"Labas\"+\" Rytas\");");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Labas Rytas");
	delete varPool;
	}
*/
/*	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string myStr(\"Labas\");");
	scriptText.push_back("string myStr2(\"Rytas\");");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Labas");
	varPool->GetVariableValue("myStr2", s1);
	assert(s1 == "Rytas");
	delete varPool;


	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string myStr(\"Labas\");");
	scriptText.push_back("string myStr2(myStr);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Labas");
	varPool->GetVariableValue("myStr2", s1);
	assert(s1 == "Labas");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string myStr(\"Labas\");");
	scriptText.push_back("string myStr2(myStr + \" Rytas\");");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Labas");
	varPool->GetVariableValue("myStr2", s1);
	assert(s1 == "Labas Rytas");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	varPool->AddLocalVariable("bool1", true);
	vector<string> scriptText;
	scriptText.push_back("string myStr(\"Labas\");");
	scriptText.push_back("string myStr2(myStr + \" Rytas\" + bool1);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Labas");
	varPool->GetVariableValue("myStr2", s1);
	assert(s1 == "Labas Rytas1");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	varPool->AddLocalVariable("bool1", true);
	varPool->AddLocalVariable("int1", (int)10);
	vector<string> scriptText;
	scriptText.push_back("string myStr(\"Labas\");");
	scriptText.push_back("string myStr2(myStr + \" Rytas\" + bool1 + int1);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Labas");
	varPool->GetVariableValue("myStr2", s1);
	assert(s1 == "Labas Rytas110");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	varPool->AddLocalVariable("bool1", true);
	varPool->AddLocalVariable("int1", (int)10);
	varPool->AddLocalVariable("float1", 55.5f);
	vector<string> scriptText;
	scriptText.push_back("string myStr(\"Labas\");");
	scriptText.push_back("string myStr2(myStr + \" Rytas\" + bool1 + int1 + float1);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Labas");
	varPool->GetVariableValue("myStr2", s1);
	assert(s1 == "Labas Rytas11055.5");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string myStr(Function22());");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Function22");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string myStr(Function26(\"Labas\"));");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Function26");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("int myInt(12);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	int s1;
	varPool->GetVariableValue("myInt", s1);
	assert(s1 == 12);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("int myInt(12+15);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	int s1;
	varPool->GetVariableValue("myInt", s1);
	assert(s1 == 27);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("int myInt(12+15*2);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	int s1;
	varPool->GetVariableValue("myInt", s1);
	assert(s1 == 42);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("int myInt(Function12()+15*2);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	int s1;
	varPool->GetVariableValue("myInt", s1);
	assert(s1 == 42);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string myStr(Function26(\"Labas\")+Function12());");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Function2612");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("float myFloat(12.75);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	float s1;
	varPool->GetVariableValue("myFloat", s1);
	assert(s1 == 12.75);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("float myFloat(Function17()+15*2);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	float s1;
	varPool->GetVariableValue("myFloat", s1);
	assert(s1 == 47);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string myStr(Function26(\"Labas\")+Function12() + Function20(15));");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1;
	varPool->GetVariableValue("myStr", s1);
	assert(s1 == "Function261220");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("bool myBool(true);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	bool s1(false);
	varPool->GetVariableValue("myBool", s1);
	assert(s1 == true);
	delete varPool;
	}


	{
	CVariablePool* varPool = new CVariablePool();
	varPool->AddGlobalVariable("myGlobal", new float(15.6));
	vector<string> scriptText;
	scriptText.push_back("bool myBool(true);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	bool s1(false);
	varPool->GetVariableValue("myBool", s1);
	assert(s1 == true);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("global bool myBool(true);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	bool s1(false);
	varPool->GetVariableValue("myBool", s1);
	assert(s1 == true);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("Function26(\"Labas\");");
	scriptText.push_back("Function12();");
	scriptText.push_back("Function20(15);");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	bool s1(false);
	varPool->GetVariableValue("myBool", s1);
	assert(s1 == true);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string MyStr(\"Labas\");");
	scriptText.push_back("MyStr = \"Rytas\";");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1("");
	varPool->GetVariableValue("MyStr", s1);
	assert(s1 == "Rytas");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("string MyStr(\"Labas\");");
	scriptText.push_back("MyStr += \" Rytas\";");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1("");
	varPool->GetVariableValue("MyStr", s1);
	assert(s1 == "Labas Rytas");
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("bool MyBool(false);");
	scriptText.push_back("MyBool = true;");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	bool s1(false);
	varPool->GetVariableValue("MyBool", s1);
	assert(s1 == true);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("bool MyBool(false);");
	scriptText.push_back("MyBool *= true;");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	bool s1(true);
	varPool->GetVariableValue("MyBool", s1);
	assert(s1 == false);
	delete varPool;
	}

	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("float f1(15.00);");
	scriptText.push_back("float f2(2.00);");
	scriptText.push_back("float f3(5);");
	scriptText.push_back("f3+=f1*f2;");
	scriptText.push_back("string MyStr(\"Skaicius: \");");
	scriptText.push_back("MyStr+=f3;");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	string s1("");
	varPool->GetVariableValue("MyStr", s1);
	assert(s1 == "Skaicius: 35");
	delete varPool;
	}


	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("float f1(15.00);{float f2(2.00);");
	scriptText.push_back("float f3(5);}");
	scriptText.push_back("int int1(5);");
	scriptText.push_back("int int2(50);");
	scriptText.push_back("f3+=f1*f2;");
	scriptText.push_back("string MyStr(\"Skaicius: \");");
	scriptText.push_back("MyStr+=f3;");
	scriptText.push_back("global string myStr;");
	scriptText.push_back("global bool myBool2(false);");
	scriptText.push_back("if(myBool!=true)");
	scriptText.push_back("   myBool2=true; ");
	scriptText.push_back("else   myBool2=false;");
	scriptText.push_back("if(MyStr != \"Namas\")");
	scriptText.push_back("MyStr = \"Namas\";");
	scriptText.push_back("if(int2 >= int1)");
	scriptText.push_back("int1 = 36;");
	scriptText.push_back("string MyStr15 = \"Labas\";");
	scriptText.push_back("while(MyStr15!=\"Rytas\")");
	scriptText.push_back("MyStr15=\"Rytas\";");
	scriptText.push_back("int MyInt15 = 0;");
	scriptText.push_back("while(MyInt15<10)");
	scriptText.push_back("MyInt15++;");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.PrintScriptText(cout);
	script.Run();
	
	bool s1(true);
	varPool->GetVariableValue("myBool2", s1);
	assert(s1 == false);

	string s2("");
	varPool->GetVariableValue("MyStr", s2);
	assert(s2 == "Namas");


	int s3(0);
	varPool->GetVariableValue("int1", s3);
	assert(s3 == 36);
	delete varPool;
	}
*/
/*{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	
	scriptText.push_back("int MyInt15 = 0;");
	scriptText.push_back("while(MyInt15<10)");
	scriptText.push_back("MyInt15++;");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.PrintScriptText(cout);
	script.Run();
	}*

/*
	{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	scriptText.push_back("global string myStr;");
	scriptText.push_back("global bool myBool2(false);");
	scriptText.push_back("if(myBool==true) myBool2 = 15;");

	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.Run();

	bool s1(false);
	varPool->GetVariableValue("myBool", s1);
	assert(s1 == true);
	delete varPool;
	}
*/
/*
{
	CVariablePool* varPool = new CVariablePool();
	vector<string> scriptText;
	
	scriptText.push_back("string myStr;");
	scriptText.push_back("for(int i = 0; i<10; i++)");
	scriptText.push_back("myStr+=i");

	try{
	TScript<MyClass> script("MySctipt", varPool, &functionPool, scriptText);
	script.PrintScriptText(cout);
	script.Run();
		}
	catch(CException_ScriptError& Exception)
		{
		cout << Exception.what() << endl;
		}

	//string s2("");
	//varPool->GetVariableValue("myStr", s2);
	//assert(s2 == "0123456789");
}




*/
int m;
cin >> m;

	return 0;
}

