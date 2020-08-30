/*
    CExpressionEvolutor_Bool.h - Contains class CExpressionEvolutor_Bool.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CEXPRESSIONEVOLUTOR_BOOL_H
#define REGINA_SCRIPT_CEXPRESSIONEVOLUTOR_BOOL_H

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

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------------------------|
//CExpressionEvolutor_Bool class is used to evolute bool script expressions.					|
//----------------------------------------------------------------------------------------------|
class CExpressionEvolutor_Bool : public CExpressionEvolutor
{
public:
	void AddVariable(bool* iVariable)	{ CExpressionEvolutor::AddVariable(iVariable); }
	void AddSign_Multiply()				{ CExpressionEvolutor::AddSign_Multiply(); }
	void Evolute(bool*& oFinalPointer, vector<CScriptAction*>& oScriptAction, vector<bool*>& oTempVariable) throw(CException_ScriptError_SyntaxError);

};
//*****************************************************************************


}

}

#pragma warning( pop )

#endif