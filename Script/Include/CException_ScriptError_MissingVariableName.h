/*
    CException_ScriptError_MissingVariableName.h - Contains class CException_ScriptError_MissingVariableName.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CEXCEPTION_SCRIPTERROR_MISSINGVARIABLENAME_H
#define REGINA_SCRIPT_CEXCEPTION_SCRIPTERROR_MISSINGVARIABLENAME_H

#include <CException_ScriptError.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------|
//CException_ScriptError_MissingVariableName.									|
//------------------------------------------------------------------------------|
class CException_ScriptError_MissingVariableName : public CException_ScriptError
{
public:
	CException_ScriptError_MissingVariableName(const string& iThrowingClass, const string& iMsg, const unsigned iLineNumber = 0) : CException_ScriptError(iThrowingClass, "Missing Variable Name - " + iMsg, iLineNumber) {}
};
//*****************************************************************************


}

}

#endif