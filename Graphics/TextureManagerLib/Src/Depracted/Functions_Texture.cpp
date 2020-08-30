/*
    Functions_Texture.cpp - Contains various texture funtions implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#include <Functions_Texture.h>
using namespace Regina::Graphics;


//*****************************************************************************

unsigned GetTextureColorR(LPDIRECT3DTEXTURE9 iTexture, const unsigned& iTextureSize, const unsigned& iPositionX, const unsigned& iPositionY)
	{
	if(iTexture == NULL)
		throw invalid_argument("GetTextureColorR - Argument iTexture = NULL");

	D3DLOCKED_RECT m_lockedRect;
	HRESULT hr = iTexture->LockRect(0, &m_lockedRect, 0, 0);

	assert(hr != D3DERR_INVALIDCALL && L"GetTextureColorR - texture->LockRect returns D3DERR_INVALIDDATA");
	assert(hr != D3DERR_WASSTILLDRAWING && L"GetTextureColorR - texture->LockRect returns D3DERR_WASSTILLDRAWING");

	BYTE* pSrcTopRow = (BYTE*)m_lockedRect.pBits;
	int pos = (iPositionY - 1)*iTextureSize + (iPositionX-1);
	DWORD c = *((DWORD*)pSrcTopRow+pos);
	int R = GetBValue(c);

	iTexture->UnlockRect(0);

	return R;
	}

//*****************************************************************************

unsigned GetTextureColorG(LPDIRECT3DTEXTURE9 iTexture, const unsigned& iTextureSize, const unsigned& iPositionX, const unsigned& iPositionY)
	{
	if(iTexture == NULL)
		throw invalid_argument("GetTextureColorG - Argument iTexture = NULL");

	D3DLOCKED_RECT m_lockedRect;
	HRESULT hr = iTexture->LockRect(0, &m_lockedRect, 0, 0);

	assert(hr != D3DERR_INVALIDCALL && L"GetTextureColorG - texture->LockRect returns D3DERR_INVALIDDATA");
	assert(hr != D3DERR_WASSTILLDRAWING && L"GetTextureColorG - texture->LockRect returns D3DERR_WASSTILLDRAWING");

	BYTE* pSrcTopRow = (BYTE*)m_lockedRect.pBits;
	int pos = (iPositionY - 1)*iTextureSize + (iPositionX-1);
	DWORD c = *((DWORD*)pSrcTopRow+pos);
	int G = GetGValue(c);

	iTexture->UnlockRect(0);

	return G;
	}

//*****************************************************************************

unsigned GetTextureColorB(LPDIRECT3DTEXTURE9 iTexture, const unsigned& iTextureSize, const unsigned& iPositionX, const unsigned& iPositionY)
	{
	if(iTexture == NULL)
		throw invalid_argument("GetTextureColorB - Argument iTexture = NULL");

	D3DLOCKED_RECT m_lockedRect;
	HRESULT hr = iTexture->LockRect(0, &m_lockedRect, 0, 0);

	assert(hr != D3DERR_INVALIDCALL && L"GetTextureColorB - texture->LockRect returns D3DERR_INVALIDDATA");
	assert(hr != D3DERR_WASSTILLDRAWING && L"GetTextureColorB - texture->LockRect returns D3DERR_WASSTILLDRAWING");

	BYTE* pSrcTopRow = (BYTE*)m_lockedRect.pBits;
	int pos = (iPositionY - 1)*iTextureSize + (iPositionX-1);
	DWORD c = *((DWORD*)pSrcTopRow+pos);
	int B = GetRValue(c);

	iTexture->UnlockRect(0);

	return B;
	}

//*****************************************************************************

void GetTextureColorRGB(LPDIRECT3DTEXTURE9 iTexture, const unsigned& iTextureSize, const unsigned& iPositionX, const unsigned& iPositionY, unsigned& oR, unsigned& oG, unsigned& oB)
	{
	if(iTexture == NULL)
		throw invalid_argument("GetTextureColorRGB - Argument iTexture = NULL");

	D3DLOCKED_RECT m_lockedRect;
	HRESULT hr = iTexture->LockRect(0, &m_lockedRect, 0, 0);

	assert(hr != D3DERR_INVALIDCALL && L"GetTextureColorRGB - texture->LockRect returns D3DERR_INVALIDDATA");
	assert(hr != D3DERR_WASSTILLDRAWING && L"GetTextureColorRGB - texture->LockRect returns D3DERR_WASSTILLDRAWING");

	BYTE* pSrcTopRow = (BYTE*)m_lockedRect.pBits;
	int pos = (iPositionY - 1)*iTextureSize + (iPositionX-1);
	DWORD c = *((DWORD*)pSrcTopRow+pos);

	//Reverse order
	oR = GetBValue(c);
	oG = GetGValue(c);
	oB = GetRValue(c); 

	iTexture->UnlockRect(0);
	}

//*****************************************************************************

