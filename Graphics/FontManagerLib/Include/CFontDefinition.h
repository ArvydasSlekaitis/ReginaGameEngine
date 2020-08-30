/*
    CFontDefinition.h - Contains class CFontDefinition.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_CFONTDEFINITION_H
#define REGINA_GRAPHICS_CFONTDEFINITION_H

#include <d3dx9.h>

#include <string>
#include <sstream>
using namespace std;


namespace Regina
{

namespace Graphics
{

class CFontDefinition
{
	wstring		name;
	wstring		facename;
	unsigned	height;
	unsigned	weight;
	bool		italic;
  	
	void RebuildName();

public:
	CFontDefinition(const wstring& iFacename, const unsigned& iHeight, const unsigned& iWeight, const bool& iItalic);

	wstring		Facename()		const { return facename; }
	unsigned	Height()		const { return height; }
	unsigned	Weight()		const {	return weight; }
	bool		Italic()		const { return false; }
	wstring		Name()			const { return name; }
};

}

}

#endif 