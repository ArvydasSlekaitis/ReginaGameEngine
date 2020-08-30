/*
    CColor.h - Contains class CColor.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CCOLOR
#define REGINA_UI_CCOLOR

#include <d3dx9.h>

namespace Regina
{

namespace UI
{

class CColor
{
public:
	float r;
	float g;
	float b;
	float a;

	CColor() : r(255), g(255), b(255), a(255) {}
	CColor(const float& iR, const float& iG, const float& iB, const float& iA) : r(iR), g(iG), b(iB), a(iA) {}
	DWORD RGBA() { return D3DCOLOR_RGBA((int)r, (int)g, (int)b, (int)a); } 

};

}

}
#endif

