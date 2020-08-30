/*
    String_Functions.h - Contains variuos string functions.
	Copyright 2007-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_STRING_FUNCTIONS
#define REGINA_STRING_FUNCTIONS

#include <string>
#include <sstream>
using namespace std;


namespace Regina
{

//*****************************************************************************

static string ToStr(const unsigned& iVariable)
	{
	ostringstream os;
	os << iVariable;
	return os.str();
	}

//*****************************************************************************




}

#endif