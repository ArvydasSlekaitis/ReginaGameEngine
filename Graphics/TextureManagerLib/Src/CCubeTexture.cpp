/*
    CCubeTexture.cpp - Contains class CCubeTexture implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CCubeTexture.h>
using namespace Regina::Graphics;


//*****************************************************************************

CCubeTexture::~CCubeTexture()
	{
	if(texture!=NULL)
		texture->Release();
	texture = NULL;
	}

//*****************************************************************************

CCubeTexture::CCubeTexture(LPDIRECT3DDEVICE9 iDevice, const wstring& iName, const unsigned iMipLevels) : CTexture(iDevice, iName, 0), texture(NULL)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CCubeTexture::CCubeTexture - Argument iDevice = NULL");

	wstring fileName(wstring(L"Data\\Textures\\") + iName);

 	HRESULT hr = D3DXCreateCubeTextureFromFileEx(iDevice, fileName.c_str(), D3DX_DEFAULT, iMipLevels, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, NULL, &texture);

	assert(hr != D3DXERR_INVALIDDATA && L"CCubeTexture::CCubeTexture D3DERR_INVALIDDATA");
	assert(hr != D3DERR_NOTAVAILABLE && L"CCubeTexture::CCubeTexture D3DERR_INVALIDDATA");

	if(hr == D3DERR_INVALIDCALL)
		throw CException("CCubeTexture::CCubeTexture", "Cannot create new texture ( file does not exist? )");
	
		if(hr == E_OUTOFMEMORY)
		throw CException_OutOfMemmory("CCubeTexture::CCubeTexture", "Cannot create new texture - not enought memmory");

	if(hr == D3DERR_OUTOFVIDEOMEMORY)
		throw CException_OutOfMemmory("CCubeTexture::CCubeTexture", "Cannot create new texture - not enought video memmory");
	}

//*****************************************************************************
