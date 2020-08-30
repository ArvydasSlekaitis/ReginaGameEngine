/*
    CUITexture.h - Contains class CUITexture.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CUITEXTURE
#define REGINA_UI_CUITEXTURE

#include <d3dx9.h>

#include <string>
#include <assert.h>
using namespace std;

#include <CException_OutOfMemmory.h>

namespace Regina
{

namespace UI
{

class CUITexture
{
	wstring				name;
	LPDIRECT3DTEXTURE9	texture;
	D3DXIMAGE_INFO		info;

public:
	virtual ~CUITexture();
	CUITexture(LPDIRECT3DDEVICE9 iDevice, const wstring& iName);

	LPDIRECT3DTEXTURE9 Texture()	  { return texture; }	
	wstring			Name()		const { return name; }
	unsigned		Height()	const { return info.Height; }
	unsigned		Width()		const { return info.Width; }
	D3DXIMAGE_INFO	ImageInfo() const { return info; }
};

}

}

#endif 