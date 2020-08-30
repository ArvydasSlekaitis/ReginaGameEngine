/*
    CCubeTexture.h - Contains class CCubeTexture.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_CCUBETEXTURE_H
#define REGINA_GRAPHICS_CCUBETEXTURE_H

#include <string>
#include <assert.h>
using namespace std;

#include <CTexture.h>
#include <CException_OutOfMemmory.h>

namespace Regina
{

namespace Graphics
{

class CCubeTexture : public CTexture
{
	LPDIRECT3DCUBETEXTURE9	texture;
	D3DXIMAGE_INFO			info;

	CCubeTexture(const CCubeTexture& iTexture) : CTexture(NULL, L"", 0), texture(NULL) {}

public:
	virtual ~CCubeTexture();
	CCubeTexture(LPDIRECT3DDEVICE9 iDevice, const wstring& iName, const unsigned iMipLevels = 0);

	LPDIRECT3DCUBETEXTURE9 Texture() { return texture; }
	unsigned		Width()		const { return info.Width; }
	unsigned		Height()	const { return info.Height; }
	unsigned		Depth()		const { return info.Depth; }
	unsigned		MipLevels() const { return info.MipLevels; }
	D3DFORMAT		Format()	const { return info.Format; }
	D3DXIMAGE_INFO	Info()		const { return info; }
};

}

}

#endif 