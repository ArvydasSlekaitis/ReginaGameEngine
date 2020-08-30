/*
    Functions_Texture.h - Contains various texture funtions.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_FUNCTIONS_TEXTURE_H
#define REGINA_GRAPHICS_FUNCTIONS_TEXTURE_H

#include <d3dx9.h>

#include <string>
#include <assert.h>
using namespace std;

#include <CException_OutOfMemmory.h>

namespace Regina
{

namespace Graphics
{

unsigned GetTextureColorR(LPDIRECT3DTEXTURE9 iTexture, const unsigned& iTextureSize, const unsigned& iPositionX, const unsigned& iPositionY);
unsigned GetTextureColorG(LPDIRECT3DTEXTURE9 iTexture, const unsigned& iTextureSize, const unsigned& iPositionX, const unsigned& iPositionY);
unsigned GetTextureColorB(LPDIRECT3DTEXTURE9 iTexture, const unsigned& iTextureSize, const unsigned& iPositionX, const unsigned& iPositionY);
void GetTextureColorRGB(LPDIRECT3DTEXTURE9 iTexture, const unsigned& iTextureSize, const unsigned& iPositionX, const unsigned& iPositionY, unsigned& oR, unsigned& oG, unsigned& oB);

}

}

#endif 