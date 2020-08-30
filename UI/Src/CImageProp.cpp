/*
    CImageProp.cpp - Contains class CImageProp implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CImageProp.h>
using namespace Regina::UI;

//******************************************************************************

CImageProp::CImageProp(const D3DXVECTOR2& iOriginalScreenResolution, const D3DXVECTOR2& iScreenResolution) : textureName(L""), scale(1, 1), rotation(0), originalScreenResolution(iOriginalScreenResolution), screenResolution(iScreenResolution), offset(0, 0), alphaIntersectionTest(false)
	{
	}

//******************************************************************************

CImageProp::~CImageProp()
	{
	}

//******************************************************************************

void CImageProp::Render(const D3DXVECTOR2& iImagePosition, const D3DXVECTOR2& iGlobalScale, const D3DXVECTOR2& iOffsetScale)
	{
	if(textureName.size()>0)
		{
		D3DXMATRIX transformation = UIImageTransformation(TransformToUIScreenSpace(originalScreenResolution, screenResolution, iImagePosition + D3DXVECTOR2(offset.x*iOffsetScale.x, offset.y*iOffsetScale.y)), D3DXVECTOR2(scale.x*iGlobalScale.x, scale.y*iGlobalScale.y), rotation, TransformToUIScreenSpace(originalScreenResolution, screenResolution, D3DXVECTOR2(1, 1)));
		RenderManager_2D->RenderImage(textureName, transformation, color.RGBA());
		}
	}

//******************************************************************************

bool CImageProp::Intersect(const D3DXVECTOR2& iCursorPosition, const D3DXVECTOR2& iImagePosition, const D3DXVECTOR2& iGlobalScale, const D3DXVECTOR2& iOffsetScale)
	{
	if(textureName.size()>0)
		{
		C2DTexture* texture(NULL);
		texture = TextureManager->Get2D(textureName, 1);

		if(texture!=NULL)
			{
			D3DXMATRIX inverseTransformation = UIImageTransformationInverse(TransformToUIScreenSpace(originalScreenResolution, screenResolution, iImagePosition + D3DXVECTOR2(offset.x*iOffsetScale.x, offset.y*iOffsetScale.y)), D3DXVECTOR2(scale.x*iGlobalScale.x, scale.y*iGlobalScale.y), rotation, TransformToUIScreenSpace(originalScreenResolution, screenResolution, D3DXVECTOR2(1, 1)));
			D3DXVECTOR2 transformedCursorPosition;
			D3DXVec2TransformCoord(&transformedCursorPosition, &iCursorPosition, &inverseTransformation);
			
			if(transformedCursorPosition.x < -(float)texture->Width() / 2)
				return false;

			if(transformedCursorPosition.y < -(float)texture->Height() / 2)
				return false;

			if(transformedCursorPosition.x > texture->Width() / 2)
				return false;
			
			if(transformedCursorPosition.y > texture->Height() / 2)
				return false;

			if(alphaIntersectionTest == true)
				{
				unsigned alpha(0);

				try
					{
					alpha = texture->GetColorA(transformedCursorPosition.x+(float)texture->Width() / 2, transformedCursorPosition.y + texture->Width() / 2);
					}
				catch(invalid_argument& iException)
					{
					}
				catch(exception& iException)
					{
					alphaIntersectionTest = false;
					}

				if(alpha == 0)
						return false;
				}

			return true;
			}
		}

	return false;
	}

//******************************************************************************

RECT CImageProp::GetBoundingRect(const D3DXVECTOR2& iImagePosition, const D3DXVECTOR2& iGlobalScale, const D3DXVECTOR2& iOffsetScale)
	{
	RECT rect;
	rect.bottom = 0;
	rect.left = 0;
	rect.right = 0;
	rect.top = 0;

	if(textureName.size()>0)
		{
		C2DTexture* texture(NULL);
		texture = TextureManager->Get2D(textureName, 1);

		if(texture!=NULL)
			{
			D3DXVECTOR2 imagePosition = iImagePosition + D3DXVECTOR2(offset.x*iOffsetScale.x, offset.y*iOffsetScale.y);
			D3DXVECTOR2 topLeft;
			D3DXVECTOR2 rightBottom;
			topLeft.x = imagePosition.x - texture->Width()/2*scale.x*iGlobalScale.x;
			topLeft.y = imagePosition.y - texture->Height()/2*scale.y*iGlobalScale.y;
			rightBottom.x = imagePosition.x + texture->Width()/2*scale.x*iGlobalScale.x;
			rightBottom.y = imagePosition.y + texture->Height()/2*scale.y*iGlobalScale.y;

			topLeft = TransformToUIScreenSpace(originalScreenResolution, screenResolution, topLeft);
			rightBottom = TransformToUIScreenSpace(originalScreenResolution, screenResolution, rightBottom);

			rect.top = topLeft.y;
			rect.left = topLeft.x;
			rect.bottom = rightBottom.y;
			rect.right = rightBottom.x;
			}
		}

	return rect;
	}

//******************************************************************************


