/*
    CUITexture.cpp - Contains class CUITexture implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CUITexture.h>
using namespace Regina::UI;


//*****************************************************************************

CUITexture::~CUITexture()
	{
	if(texture!=NULL)
		texture->Release();
	texture = NULL;
	}

//*****************************************************************************

CUITexture::CUITexture(LPDIRECT3DDEVICE9 iDevice, const wstring& iName) : name(iName), texture(NULL)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CUITexture::CUITexture - Argument iDevice = NULL");

	wstring fileName(wstring(L"Data\\Textures\\") + iName);

	HRESULT hr = D3DXCreateTextureFromFileEx(iDevice, fileName.c_str(), D3DX_DEFAULT, D3DX_DEFAULT, 1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, NULL, &texture);
	
	assert(hr != D3DERR_INVALIDCALL && L"CUITexture::CUITexture D3DERR_INVALIDCALL");
	assert(hr != D3DXERR_INVALIDDATA && L"CUITexture::CUITexture D3DERR_INVALIDDATA");
	assert(hr != D3DERR_NOTAVAILABLE && L"CUITexture::CUITexture D3DERR_INVALIDDATA");

	if(hr == E_OUTOFMEMORY)
		throw CException_OutOfMemmory("CUITexture::CUITexture", "Cannot create new font - not enought memmory");

	if(hr == D3DERR_OUTOFVIDEOMEMORY)
		throw CException_OutOfMemmory("CUITexture::CUITexture", "Cannot create new font - not enought video memmory");
	}

//*****************************************************************************
