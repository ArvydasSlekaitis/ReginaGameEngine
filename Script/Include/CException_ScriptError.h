/*
    CException_ScriptError.h - Contains class CException_ScriptError.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CEXCEPTION_SCRIPTERROR_H
#define REGINA_SCRIPT_CEXCEPTION_SCRIPTERROR_H

#include <CException.h>

#include <String_Functions.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------|
//CException_SyntaxError class is a base class for script  exceptions.			|
//------------------------------------------------------------------------------|
class CException_ScriptError : public Regina::CException
{
	unsigned lineNumber;
	string	 currentMsg;

public:
	CException_ScriptError(const string& iThrowingClass, const string& iMsg, const unsigned iLineNumber = 0) : Regina::CException(iThrowingClass, iMsg + " - At Line: " + ToStr(iLineNumber)), lineNumber(iLineNumber), currentMsg(iMsg) {}
	unsigned LineNumber() const { return lineNumber; }
	void SetLineNumber(const unsigned& iLineNumber) { lineNumber = iLineNumber; SetAdditionalInformation(currentMsg + " - At Line: " + ToStr(iLineNumber)); }
};
//*****************************************************************************


}

}

#endif