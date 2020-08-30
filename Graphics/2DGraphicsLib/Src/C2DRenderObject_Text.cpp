/*
    C2DRenderObject_Text.h - Contains class C2DRenderObject_Text implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <C2DRenderObject_Text.h>
using namespace Regina::Graphics;


//*****************************************************************************

C2DRenderObject_Text::C2DRenderObject_Text(const wstring& iText, CFont* iFont, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor) : text(iText), font(iFont), color(iColor), format(DT_NOCLIP)
  	{
	if(iFont == NULL)
		throw invalid_argument("C2DRenderObject_Text::C2DRenderObject_Text - argument iFont == NULL");

	rect.left = iPosition.x;
	rect.right = iPosition.x + 1;
	rect.top = iPosition.y;
	rect.bottom = iPosition.y + 1;
	}

//*****************************************************************************

C2DRenderObject_Text::C2DRenderObject_Text(const wstring& iText, CFont* iFont, const D3DCOLOR& iColor, const RECT& iRect, const DWORD& iFormat) : text(iText), font(iFont), color(iColor), rect(iRect), format(iFormat)
  	{
	if(iFont == NULL)
		throw invalid_argument("C2DRenderObject_Text::C2DRenderObject_Text - argument iFont == NULL");
	}

//*****************************************************************************

void C2DRenderObject_Text::Render(LPD3DXSPRITE iSprite)
	{
	font->DrawText(iSprite, text, rect, format, color);
	}

//*****************************************************************************