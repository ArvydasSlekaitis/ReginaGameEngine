/*
    CExpressionEvolutor_Int.h - Contains class CExpressionEvolutor_Int.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CEXPRESSIONEVOLUTOR_INT_H
#define REGINA_SCRIPT_CEXPRESSIONEVOLUTOR_INT_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <string>
#include <vector>
#include <assert.h>
using namespace std;

#include <CExpressionEvolutor.h>
#include <CScriptAction.h>
#include <CException_ScriptError_SyntaxError.h>
#include <TScriptAction_Multiply.h>
#include <TScriptAction_Minus.h>
#include <TScriptAction_Sum.h>
#include <TScriptAction_Divide.h>
#include <TScriptAction_Set.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------------------------|
//CExpressionEvolutor_Int class is used to evolute integer script expressions.					|
//----------------------------------------------------------------------------------------------|
class CExpressionEvolutor_Int : public CExpressionEvolutor
{
public:
	void AddVariable(int* iVariable)	{ CExpressionEvolutor::AddVariable(iVariable); }
	void AddVariable(float* iVariable)	{ CExpressionEvolutor::AddVariable(iVariable); }
	void AddSign_Multiply()				{ CExpressionEvolutor::AddSign_Multiply(); }
	void AddSign_Minus()				{ CExpressionEvolutor::AddSign_Minus(); }
	void AddSign_Plus()					{ CExpressionEvolutor::AddSign_Plus(); }
	void AddSign_Divide()				{ CExpressionEvolutor::AddSign_Divide(); }
	void Evolute(int*& oFinalPointer, vector<CScriptAction*>& oScriptAction, vector<int*>& oTempVariable) throw(CException_ScriptError_SyntaxError);

};
//*****************************************************************************


}

}

#pragma warning( pop )

#endif