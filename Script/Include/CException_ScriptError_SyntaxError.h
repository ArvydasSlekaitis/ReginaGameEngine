/*
    CException_ScriptError_SyntaxError.h - Contains class CException_ScriptError_SyntaxError.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CEXCEPTION_SCRIPTERROR_SYNTAXERROR_H
#define REGINA_SCRIPT_CEXCEPTION_SCRIPTERROR_SYNTAXERROR_H

#include <CException_ScriptError.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------|
//CException_ScriptError_SyntaxError.											|
//------------------------------------------------------------------------------|
class CException_ScriptError_SyntaxError : public CException_ScriptError
{
public:
	CException_ScriptError_SyntaxError(const string& iThrowingClass, const string& iMsg, const unsigned iLineNumber = 0) : CException_ScriptError(iThrowingClass, "Syntax Error - " + iMsg, iLineNumber) {}
};
//*****************************************************************************


}

}

#endif