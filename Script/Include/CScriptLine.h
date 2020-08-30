/*
    CScriptLine.h - Contains class CScriptLine.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTLINE_H
#define REGINA_SCRIPT_TSCRIPTLINE_H

#include <string>
#include <sstream>
using namespace std;

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//CScriptLine class holds script line information.							  |
//----------------------------------------------------------------------------|
class CScriptLine : public wstring
{
	unsigned positionInOriginalScriptText;

public:
	CScriptLine(const wchar_t* iString, const unsigned& iPositionInOriginalScriptText) : wstring(iString), positionInOriginalScriptText(iPositionInOriginalScriptText) {};
	CScriptLine(const wstring& iString, const unsigned& iPositionInOriginalScriptText) : wstring(iString), positionInOriginalScriptText(iPositionInOriginalScriptText) {};
	unsigned PositionInOriginalScriptText() const { return positionInOriginalScriptText; }
};

}

}

#endif
