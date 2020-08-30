/*
    CScriptString.h - Contains class CScriptString.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTSTRING_H
#define REGINA_SCRIPT_TSCRIPTSTRING_H

#include <string>
#include <sstream>
using namespace std;

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//CScriptString class is used to scan string for variuos script entitys.	  |
//----------------------------------------------------------------------------|
class CScriptString : public wstring
{
	unsigned cur_pos;

public:
	void	Omit();
	wchar_t	ScanSign();
	wchar_t	ScanNextSymbol();
	wstring	ScanVariable();
	wstring	ScanBoolean();
	wstring	ScanToEnd();
	wstring	ScanToSymbol(const wchar_t& iStopSymbol);
	float	ScanFloat();
	void	ScanConditional(wstring& oLeftSide, wstring& oBoolean, wstring& oRighSide);

	wchar_t	NextSymbol();
	wstring	NextVariable();

	CScriptString(const wchar_t* iString) : wstring(iString), cur_pos(0) {};
	
	wstring		GetOriginalString() { return (*this); }
	bool		End()				{ return cur_pos<length() ? false :true; }
	unsigned	CurPosition() const { return cur_pos; }

};

}

}

#endif
