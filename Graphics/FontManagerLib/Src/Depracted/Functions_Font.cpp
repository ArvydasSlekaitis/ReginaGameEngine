/*
    Functions_Font.cpp - Contains various font funtions implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#include <Functions_Font.h>
using namespace Regina::Graphics;


//*****************************************************************************

void GetTextExtent(LPD3DXFONT iFont, const wstring& iText, RECT& oRect)
	{
	if(iFont == NULL)
		throw invalid_argument("GetTextExtent - Argument iFont = NULL");

	iFont->DrawTextW(NULL, iText.c_str(), iText.size(), &oRect, DT_CALCRECT, D3DCOLOR_XRGB(0,0,0));
	}

//*****************************************************************************

void DrawTextW(LPD3DXFONT iFont, const wstring& iText, RECT iRect, DWORD iFormat, const D3DCOLOR& iColor)
	{
	if(iFont == NULL)
		throw invalid_argument("GetTextExtent - Argument iFont = NULL");

	iFont->DrawTextW(NULL, iText.c_str(), iText.size(), &iRect, iFormat, iColor);
	}

//*****************************************************************************

void DrawTextW(LPD3DXFONT iFont, const wstring& iText, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor)
	{
	if(iFont == NULL)
		throw invalid_argument("GetTextExtent - Argument iFont = NULL");

	RECT rc;
	rc.left = iPosition.x;
	rc.right = iPosition.x + 1;
	rc.top = iPosition.y;
	rc.bottom = iPosition.y + 1;

	iFont->DrawTextW(NULL, iText.c_str(), iText.size(), &rc, DT_NOCLIP, iColor);
	}

//*****************************************************************************
