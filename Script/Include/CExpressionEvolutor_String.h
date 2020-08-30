/*
    CExpressionEvolutor_String.h - Contains class CExpressionEvolutor_String.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CEXPRESSIONEVOLUTOR_STRING_H
#define REGINA_SCRIPT_CEXPRESSIONEVOLUTOR_STRING_H

#pragma warning( push )
#pragma warning( disable : 4290 )

#include <string>
#include <vector>
#include <assert.h>
using namespace std;

#include <CExpressionEvolutor.h>
#include <CScriptAction.h>
#include <CException_ScriptError_SyntaxError.h>
#include <TScriptAction_Sum.h>
#include <TScriptAction_Set.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------------------------|
//CExpressionEvolutor_String class is used to evolute string script expressions.				|
//----------------------------------------------------------------------------------------------|
class CExpressionEvolutor_String : public CExpressionEvolutor
{
public:
	void AddVariable(bool* iVariable)	{ CExpressionEvolutor::AddVariable(iVariable); }
	void AddVariable(int* iVariable)	{ CExpressionEvolutor::AddVariable(iVariable); }
	void AddVariable(float* iVariable)	{ CExpressionEvolutor::AddVariable(iVariable); }
	void AddVariable(wstring* iVariable){ CExpressionEvolutor::AddVariable(iVariable); }
	void AddSign_Plus()					{ CExpressionEvolutor::AddSign_Plus(); }

	void Evolute(wstring*& oFinalPointer, vector<CScriptAction*>& oScriptAction, vector<wstring*>& oTempVariable) throw(CException_ScriptError_SyntaxError);

};
//*****************************************************************************


}

#pragma warning( pop )

}

#endif