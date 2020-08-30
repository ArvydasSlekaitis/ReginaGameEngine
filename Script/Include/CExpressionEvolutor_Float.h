/*
    CExpressionEvolutor_Float.h - Contains class CExpressionEvolutor_Float.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CEXPRESSIONEVOLUTOR_FLOAT_H
#define REGINA_SCRIPT_CEXPRESSIONEVOLUTOR_FLOAT_H

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
//CExpressionEvolutor_Float class is used to evolute floating point script expressions.			|
//----------------------------------------------------------------------------------------------|
class CExpressionEvolutor_Float : public CExpressionEvolutor
{
public:
	void AddVariable(int* iVariable)	{ CExpressionEvolutor::AddVariable(iVariable); }
	void AddVariable(float* iVariable)	{ CExpressionEvolutor::AddVariable(iVariable); }
	void AddSign_Multiply()				{ CExpressionEvolutor::AddSign_Multiply(); }
	void AddSign_Minus()				{ CExpressionEvolutor::AddSign_Minus(); }
	void AddSign_Plus()					{ CExpressionEvolutor::AddSign_Plus(); }
	void AddSign_Divide()				{ CExpressionEvolutor::AddSign_Divide(); }
	void Evolute(float*& oFinalPointer, vector<CScriptAction*>& oScriptAction, vector<float*>& oTempVariable) throw(CException_ScriptError_SyntaxError);

};
//*****************************************************************************


}

}

#pragma warning( pop )

#endif