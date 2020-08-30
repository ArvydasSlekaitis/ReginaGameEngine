/*
    CException_ScriptError_UndefinedSymbol.h - Contains class CException_ScriptError_UndefinedSymbol.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CEXCEPTION_SCRIPTERROR_UNDEFINEDSYMBOL_H
#define REGINA_SCRIPT_CEXCEPTION_SCRIPTERROR_UNDEFINEDSYMBOL_H

#include <CException_ScriptError.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------|
//CException_ScriptError_UndefinedSymbol.										|
//------------------------------------------------------------------------------|
class CException_ScriptError_UndefinedSymbol : public CException_ScriptError
{
public:
	CException_ScriptError_UndefinedSymbol(const string& iThrowingClass, const string& iMsg, const unsigned iLineNumber = 0) : CException_ScriptError(iThrowingClass, "Undefined Symbol - " + iMsg, iLineNumber) {}
};
//*****************************************************************************


}

}

#endif