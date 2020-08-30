/*
    C2DTexture.h - Contains class C2DTexture.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_C2DTEXTURE_H
#define REGINA_GRAPHICS_C2DTEXTURE_H

#include <string>
#include <assert.h>
using namespace std;

#include <CTexture.h>
#include <CException_OutOfMemmory.h>

namespace Regina
{

namespace Graphics
{

class C2DTexture : public CTexture
{
	LPDIRECT3DTEXTURE9	texture;
	D3DXIMAGE_INFO		info;

	C2DTexture(const C2DTexture& iTexture) : CTexture(NULL, L"", 0), texture(NULL) {}

	
	

public:
	virtual ~C2DTexture();
	C2DTexture(LPDIRECT3DDEVICE9 iDevice, const wstring& iName, const unsigned iMipLevels = 0);
	
	LPDIRECT3DTEXTURE9 Texture() { return texture; }

	unsigned		Width()		const { return info.Width; }
	unsigned		Height()	const { return info.Height; }
	unsigned		Depth()		const { return info.Depth; }
	unsigned		MipLevels() const { return info.MipLevels; }
	D3DFORMAT		Format()	const { return info.Format; }
	D3DXIMAGE_INFO	Info()		const { return info; }

	unsigned GetColorR(const unsigned& iPositionX, const unsigned& iPositionY);
	unsigned GetColorG(const unsigned& iPositionX, const unsigned& iPositionY);
	unsigned GetColorB(const unsigned& iPositionX, const unsigned& iPositionY);
	unsigned GetColorA(const unsigned& iPositionX, const unsigned& iPositionY);
	void GetColorRGB(const unsigned& iPositionX, const unsigned& iPositionY, unsigned& oR, unsigned& oG, unsigned& oB);
	void GetColorRGBA(const unsigned& iPositionX, const unsigned& iPositionY, unsigned& oR, unsigned& oG, unsigned& oB, unsigned& oA);
};

}

}

#endif 