/*
    C2DRenderObject_Image.h - Contains class C2DRenderObject_Image.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_C2DRENDEROBJECT_IMAGE_H
#define REGINA_C2DRENDEROBJECT_IMAGE_H

#include <string>
using namespace std;

#include <C2DRenderObject.h>
#include <C2DTexture.h>

namespace Regina
{

namespace Graphics
{

class C2DRenderObject_Image : public C2DRenderObject
{
	C2DTexture*	texture;
	D3DXMATRIX	transformation;
	D3DXMATRIX	transformationIdentity; // for transformation reset
	D3DCOLOR	color;

public:
	virtual ~C2DRenderObject_Image();

	C2DRenderObject_Image(C2DTexture* iTexture, const D3DXVECTOR2& iPosition, const float iRotation = 0.0f, const D3DXVECTOR2 iScale = D3DXVECTOR2(1, 1), const D3DCOLOR iColor = 0x000000)  throw(invalid_argument);
	C2DRenderObject_Image(C2DTexture* iTexture, const D3DXMATRIX& iTransformation, const D3DCOLOR iColor = 0x000000)  throw(invalid_argument);
	virtual void Render(LPD3DXSPRITE iSprite);

};

}

}

#endif 