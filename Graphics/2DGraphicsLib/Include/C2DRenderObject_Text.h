/*
    C2DRenderObject_Text.h - Contains class C2DRenderObject_Text.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_C2DRENDEROBJECT_TEXT_H
#define REGINA_GRAPHICS_C2DRENDEROBJECT_TEXT_H

#include <string>
using namespace std;

#include <CFont.h>
#include <C2DRenderObject.h>


namespace Regina
{

namespace Graphics
{

class C2DRenderObject_Text : public C2DRenderObject
{
	CFont*		font;
	wstring		text;
	RECT		rect;
	DWORD		format;
	D3DCOLOR	color;

public:
	virtual ~C2DRenderObject_Text() {}
	
	C2DRenderObject_Text(const wstring& iText, CFont* iFont, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor) throw(invalid_argument);
	C2DRenderObject_Text(const wstring& iText, CFont* iFont, const D3DCOLOR& iColor, const RECT& iRect, const DWORD& iFormat) throw(invalid_argument);
	
	virtual void Render(LPD3DXSPRITE iSprite);
};

}

}

#endif 