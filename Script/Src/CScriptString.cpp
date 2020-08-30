/*
    CException_ScriptError.cpp - Contains class CException_ScriptError implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CScriptString.h>
using namespace Regina::Script;

//*****************************************************************************

void CScriptString::Omit()
	{
	for(unsigned  i=cur_pos; i<length(); i++)
		{
		if(at(i) == ' ')
			cur_pos++;
		else
			break;
		}
	}

//*****************************************************************************

wchar_t CScriptString::ScanSign()
	{
	if(!End())
		{
		Omit();
		if(at(cur_pos) == '+') {cur_pos++; return '+';}
		if(at(cur_pos) == '-') {cur_pos++; return '-';}
		if(at(cur_pos) == '*') {cur_pos++; return '*';}
		if(at(cur_pos) == '/') {cur_pos++; return '/';}
		if(at(cur_pos) == ';') {cur_pos++; return ';';}
		}
	return ' ';
	}

//*****************************************************************************

wstring CScriptString::ScanVariable()
	{
	wstring r;

	if(!End())
		{
		Omit();
	
		for(unsigned i=cur_pos; i<length(); i++)
			{
			if(at(cur_pos) == ' ' || at(cur_pos) == '+' || at(cur_pos) == '-' || at(cur_pos) == '*' || at(cur_pos) == '/' || at(cur_pos) == '\n' || at(cur_pos) == '\0' || at(cur_pos) == '>' || at(cur_pos) == '<' || at(cur_pos) == '='|| at(cur_pos) == ';' || at(cur_pos) == '(' || at(cur_pos) == ')' )
				break;
			r+=at(cur_pos);
			cur_pos++;
			}
		}

	return r;
	}

//*****************************************************************************

wstring CScriptString::ScanBoolean()
	{
	wstring r;
	if(!End())
		{
		Omit();

		for(unsigned i=cur_pos; i<length(); i++)
			{
			if(at(cur_pos) != '>' && at(cur_pos) != '<' && at(cur_pos) != '=' && at(cur_pos) != '!' && at(cur_pos) != '+'&& at(cur_pos) != '-'&& at(cur_pos) != '*' && at(cur_pos) != '/')
				break;
			r+=at(cur_pos);
			cur_pos++;
			}
		}

	return r;
	}

//*****************************************************************************

wstring CScriptString::ScanToEnd()
	{
	wstring r;
	if(!End())
		{
		Omit();
		for(unsigned i=cur_pos; i<length(); i++)
			r+=at(i);
		}

	cur_pos = length();
	return r;
	}

//*****************************************************************************

wchar_t CScriptString::ScanNextSymbol()
	{
	wchar_t r('\n');

	if(!End())
		{
		Omit();
		r = at(cur_pos);
		cur_pos++;
		}
	return r;
	}

//*****************************************************************************

wchar_t CScriptString::NextSymbol()
	{
	wchar_t r('\n');

	Omit();
	if(!End())
		r = at(cur_pos);

	return r;
	}

//*****************************************************************************

wstring CScriptString::ScanToSymbol(const wchar_t& iStopSymbol)
	{
	wstring r;
	if(!End())
		{
		for(unsigned i=cur_pos; i<length(); i++)
			if(at(i) != iStopSymbol)
				{
				r+=at(i);
				cur_pos++;
				}
			else
				break;
		}

	return r;
	}

//*****************************************************************************

wstring CScriptString::NextVariable()
	{
	wstring r;

	if(!End())
		{
		Omit();
	
		for(unsigned i=cur_pos; i<length(); i++)
			{
			if(at(i) == ' ' || at(i) == '+' || at(i) == '-' || at(i) == '*' || at(i) == '/' || at(i) == '\n' || at(i) == '\0' || at(i) == '>' || at(i) == '<' || at(i) == '='|| at(i) == ';' || at(i) == '(' || at(i) == ')' )
				break;
			r+=at(i);			
			}
		}

	return r;
	}

//*****************************************************************************

float CScriptString::ScanFloat()
	{
	wstring r;
	float ret(0);

	if(!End())
		{
		Omit();
	
		for(unsigned i=cur_pos; i<length(); i++)
			{
			if(at(i) == ' ' || at(i) == '+' || at(i) == '-' || at(i) == '*' || at(i) == '/' || at(i) == '\n' || at(i) == '\0' || at(i) == '>' || at(i) == '<' || at(i) == '='|| at(i) == ';' || at(i) == '(' || at(i) == ')' )
				break;
			r+=at(i);
			cur_pos++;
			}
		}
	wistringstream is(r);
	is >> ret;
	
	return ret;
	}

//*****************************************************************************

void CScriptString::ScanConditional(wstring& oLeftSide, wstring& oBoolean, wstring& oRighSide)
	{
	Omit();

	for(unsigned i = cur_pos; i<length(); i++)
		if(at(i) != '=' && at(i) != '>' && at(i) != '<' && at(i) != '!')
			{
			oLeftSide+=at(i);
			cur_pos++;
			}
		else
			break;

	for(unsigned i = cur_pos; i<length(); i++)
		if(at(i) == '=' || at(i) == '>' || at(i) == '<' || at(i) == '!')
			{
			oBoolean+=at(i);
			cur_pos++;
			}
		else
			break;

	unsigned numOpen(0);

	for(unsigned i = cur_pos; i<length(); i++)
		{
		if(at(i) == ';')
			break;

		if(at(i) == '(')
			numOpen++;
		
		if(at(i) == ')')
			{
			if(numOpen == 0)
				break;

			numOpen--;
			}
		

		oRighSide+=at(i);
		cur_pos++;
		}
		

	}

//*****************************************************************************