/*
    CFontDefinition.cpp - Contains class CFontDefinition implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CFontDefinition.h>
using namespace Regina::UI;


//*****************************************************************************

CFontDefinition::CFontDefinition() : facename(L"Arial"), height(12), weight(FW_BOLD), italic(false), aspectRatio(1), name(L"")
	{
	RebuildName();
	}

//*****************************************************************************

CFontDefinition::CFontDefinition(const wstring& iFacename, const float& iHeight, const float& iWeight, const bool& iItalic, const float& iAspectRatio) : facename(iFacename), height(iHeight), weight(iWeight), italic(iItalic), aspectRatio(iAspectRatio), name(L"")
  	{
	RebuildName();
	}

//*****************************************************************************

void CFontDefinition::SetFacename(const wstring& iFacename)
  	{
	facename = iFacename;
	}

//*****************************************************************************

void CFontDefinition::SetHeight(const float& iHeight)
  	{
	height = iHeight;
	}

//*****************************************************************************

void CFontDefinition::SetWeight(const float& iWeight)
  	{
	weight = iWeight;
	}

//*****************************************************************************

void CFontDefinition::SetItalic(const bool& iItalic)
  	{
	italic = iItalic;
	}

//*****************************************************************************

void CFontDefinition::SetAspectRatio(const float& iAspectRatio)
	{
	aspectRatio = iAspectRatio;
	}

//*****************************************************************************

void CFontDefinition::RebuildName()
	{
	wostringstream os;
	os << facename << "_" << height*aspectRatio << "_" << weight << "_" << italic;
	name = os.str();
	}

//*****************************************************************************

