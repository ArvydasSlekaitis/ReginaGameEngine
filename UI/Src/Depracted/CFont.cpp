/*
    CFont.cpp - Contains class CFont implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CFont.h>
using namespace Regina::UI;


//*****************************************************************************

CFont::CFont(LPDIRECT3DDEVICE9 iDevice, const wstring& iFacename, const unsigned& iHeight, const unsigned& iWeight, const bool& iItalic) : facename(iFacename), height(iHeight), weight(iWeight), italic(iItalic), font(NULL)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CFont::CFont - Argument iDevice = NULL");

	HRESULT hr = D3DXCreateFont(iDevice, height, 0, weight, 1, italic, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, facename.c_str(), &font);

	assert(hr != D3DERR_INVALIDCALL && L"CFont::CFont D3DERR_INVALIDCALL");
	assert(hr != D3DXERR_INVALIDDATA && L"CFont::CFont D3DERR_INVALIDDATA");

	if(hr == E_OUTOFMEMORY)
		throw CException_OutOfMemmory("CFont::CFont", "Cannot create new font - not enought memmory");

	wostringstream os;
	os << facename << "_" << height << "_" << weight << "_" << italic;
	name = os.str();
	}

//*****************************************************************************

CFont::~CFont()
	{
	if(font!=NULL)
		font->Release();
	font = NULL;
	}

//*****************************************************************************

void CFont::OnLostDevice()
  	{
	font->OnLostDevice();
	}

//*****************************************************************************

void CFont::OnDestroyDevice()
  	{
	if(font!=NULL)
		font->Release();
	font = NULL;
	}

//*****************************************************************************

void CFont::OnResetDevice()
  	{
	font->OnResetDevice();
	}

//*****************************************************************************

void CFont::GetTextExtent(const wstring& iText, RECT& oRect)
  	{
	font->DrawTextW(NULL, iText.c_str(), iText.size(), &oRect, DT_CALCRECT, D3DCOLOR_XRGB(0,0,0));
	}

//*****************************************************************************

void CFont::DrawText(const wstring& iText, RECT iRect, DWORD iFormat, const D3DCOLOR& iColor)
  	{
	font->DrawTextW(NULL, iText.c_str(), iText.size(), &iRect, iFormat, iColor);
	}

//*****************************************************************************

void CFont::DrawText(const wstring& iText, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor)
	{
	RECT rc;
	rc.left = iPosition.x;
	rc.right = iPosition.x + 1;
	rc.top = iPosition.y;
	rc.bottom = iPosition.y + 1;

	font->DrawTextW(NULL, iText.c_str(), iText.size(), &rc, DT_NOCLIP, iColor);
	}

//*****************************************************************************