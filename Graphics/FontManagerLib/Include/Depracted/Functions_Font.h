/*
    Functions_Font.h - Contains various font funtions.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_FUNCTIONS_FONT_H
#define REGINA_GRAPHICS_FUNCTIONS_FONT_H

#include <d3dx9.h>

#include <string>
#include <assert.h>
using namespace std;

#include <CException_OutOfMemmory.h>

namespace Regina
{

namespace Graphics
{

void GetTextExtent(LPD3DXFONT iFont, const wstring& iText, RECT& oRect);
void DrawTextW(LPD3DXFONT iFont, const wstring& iText, RECT iRect, DWORD iFormat, const D3DCOLOR& iColor);
void DrawTextW(LPD3DXFONT iFont, const wstring& iText, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor);

}

}

#endif 