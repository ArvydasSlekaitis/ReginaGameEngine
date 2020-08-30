/*
    CFont.h - Contains class CFont.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_CFONT_H
#define REGINA_GRAPHICS_CFONT_H

#include <d3dx9.h>

#include <string>
#include <assert.h>
#include <sstream>
using namespace std;

#include <CException_OutOfMemmory.h>

namespace Regina
{

namespace Graphics
{

class CFont
{
	wstring		name;
	wstring		facename;
	unsigned	height;
	unsigned	weight;
	bool		italic;
	LPD3DXFONT	font;

public:
	CFont(LPDIRECT3DDEVICE9 iDevice, const wstring& iFacename, const unsigned& iHeight, const unsigned& iWeight, const bool& iItalic);
	~CFont();

	wstring		Name()		const { return name; }
	wstring		Facename()	const { return facename; }
	unsigned	Height()	const { return height; }
	unsigned	Weight()	const { return weight; }
	bool		Italic()	const { return italic; }
	LPD3DXFONT	Font()			  { return font; }

	void GetTextExtent(const wstring& iText, RECT& oRect);
	void DrawText(const wstring& iText, RECT iRect, DWORD iFormat, const D3DCOLOR& iColor);
	void DrawText(const wstring& iText, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor);
	void DrawText(LPD3DXSPRITE iSprite, const wstring& iText, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor);
	void DrawText(LPD3DXSPRITE iSprite, const wstring& iText, RECT iRect, DWORD iFormat, const D3DCOLOR& iColor);

	void OnLostDevice();
	void OnDestroyDevice();
	void OnResetDevice();
};

}

}

#endif 