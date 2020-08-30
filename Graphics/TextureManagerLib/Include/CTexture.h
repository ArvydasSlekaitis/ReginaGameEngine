/*
    CTexture.h - Contains class CTexture.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_CTEXTURE_H
#define REGINA_GRAPHICS_CTEXTURE_H

#include <d3dx9.h>

#include <string>
using namespace std;

#include <CException_OutOfMemmory.h>

namespace Regina
{

namespace Graphics
{

class CTexture
{
	wstring			name;
	unsigned		mipLevels;

protected:
	LPDIRECT3DDEVICE9	device;

public:
	virtual ~CTexture();
	CTexture(LPDIRECT3DDEVICE9 iDevice, const wstring& iName, const unsigned& iMipLevels);

	wstring		Name()		const { return name; }
	unsigned	MipLevels() const { return mipLevels; }
};

}

}

#endif 