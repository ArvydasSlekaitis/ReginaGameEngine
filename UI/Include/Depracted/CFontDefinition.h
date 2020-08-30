/*
    CFontDefinition.h - Contains class CFontDefinition.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CFONTDEFINITION
#define REGINA_CFONTDEFINITION

#include <d3dx9.h>

#include <string>
#include <sstream>
using namespace std;


namespace Regina
{

namespace UI
{

class CFontDefinition
{
	wstring		name;
	wstring		facename;
	float		height;
	float		weight;
	bool		italic;
	float		aspectRatio;

	void RebuildName();
	  	
public:
	CFontDefinition(const wstring& iFacename, const float& iHeight, const float& iWeight, const bool& iItalic, const float& iAspectRatio);
	CFontDefinition();

	wstring		Facename()		const { return facename; }
	float		Height()		const { return height*aspectRatio; }
	float		Weight()		const {	return weight; }
	bool		Italic()		const { return false; }
	wstring		Name()			{ RebuildName(); return name; }
	wstring*	FacenamePtr()	{ return &facename; }
	float*		HeightPtr()		{ return &height; }
	float*		WeightPtr()		{ return &weight; }
	bool*		ItalicPtr()		{ return &italic; }
	
	void SetAspectRatio(const float& iAspectRatio);
	void SetFacename(const wstring& iFacename);
	void SetHeight(const float& iHeight);
	void SetWeight(const float& iWeight);
	void SetItalic(const bool& iItalic);
};

}

}

#endif 