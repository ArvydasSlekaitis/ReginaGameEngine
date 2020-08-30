/*
    CTexture.cpp - Contains class CTexture implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CTexture.h>
using namespace Regina::Graphics;


//*****************************************************************************

CTexture::~CTexture()
	{
	if(device != NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

CTexture::CTexture(LPDIRECT3DDEVICE9 iDevice, const wstring& iName, const unsigned& iMipLevels) : name(iName), mipLevels(iMipLevels)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CTexture::CTexture - Argument iDevice = NULL");
	
	device = iDevice;
	device->AddRef();
	}

//*****************************************************************************
