/*
    CFontDefinition.cpp - Contains class CFontDefinition implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CFontDefinition.h>
using namespace Regina::Graphics;


//*****************************************************************************

CFontDefinition::CFontDefinition(const wstring& iFacename, const unsigned& iHeight, const unsigned& iWeight, const bool& iItalic) : facename(iFacename), height(iHeight), weight(iWeight), italic(iItalic), name(L"")
  	{
	RebuildName();
	}

//*****************************************************************************

void CFontDefinition::RebuildName()
	{
	wostringstream os;
	os << facename << "_" << height << "_" << weight << "_" << italic;
	name = os.str();
	}

//*****************************************************************************

