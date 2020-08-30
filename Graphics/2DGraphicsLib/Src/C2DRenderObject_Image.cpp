/*
    C2DRenderObject_Image.h - Contains class C2DRenderObject_Image implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <C2DRenderObject_Image.h>
using namespace Regina::Graphics;


//*****************************************************************************

C2DRenderObject_Image::~C2DRenderObject_Image()
	{

	}

//*****************************************************************************

C2DRenderObject_Image::C2DRenderObject_Image(C2DTexture* iTexture, const D3DXVECTOR2& iPosition, const float iRotation, const D3DXVECTOR2 iScale, D3DCOLOR iColor) : texture(iTexture), color(iColor)
	{
	if(iTexture == NULL)
		throw invalid_argument("C2DRenderObject_Image::C2DRenderObject_Image - argument iTexture == NULL");
	
	D3DXMatrixTransformation2D(&transformation, NULL, 0, &iScale, NULL, iRotation, &iPosition);
	D3DXMatrixIdentity(&transformationIdentity);
	}

//*****************************************************************************

C2DRenderObject_Image::C2DRenderObject_Image(C2DTexture* iTexture, const D3DXMATRIX& iTransformation, D3DCOLOR iColor) : texture(iTexture), color(iColor), transformation(iTransformation)
	{
	if(iTexture == NULL)
		throw invalid_argument("C2DRenderObject_Image::C2DRenderObject_Image - argument iTexture == NULL");

	D3DXMatrixIdentity(&transformationIdentity);
	}

//*****************************************************************************

void C2DRenderObject_Image::Render(LPD3DXSPRITE iSprite)
	{
	iSprite->SetTransform(&transformation);
	iSprite->Draw(texture->Texture(), NULL, &D3DXVECTOR3(texture->Width()/2, texture->Height()/2, 0), NULL, color);
	
	//Reset transform
	iSprite->SetTransform(&transformationIdentity);
	}

//*****************************************************************************
