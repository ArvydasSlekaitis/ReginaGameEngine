/*
    CLabelProp.cpp - Contains class CLabelProp implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CLabelProp.h>
using namespace Regina::UI;


//*****************************************************************************

CLabelProp::CLabelProp(const D3DXVECTOR2& iOriginalScreenResolution, const D3DXVECTOR2& iScreenResolution) : line(L""), facename(L"Arial"), height(12), weight(1), italic(false), originalScreenResolution(iOriginalScreenResolution), screenResolution(iScreenResolution), offset(0, 0)
	{
	}

//*****************************************************************************

void CLabelProp::Render(const D3DXVECTOR2& iLabelPosition, const D3DXVECTOR2& iGlobalScale, const D3DXVECTOR2& iOffsetScale)
	{
	RenderManager_2D->RenderText(line, facename, TransformToUIScreenSpace(originalScreenResolution, screenResolution, iLabelPosition+D3DXVECTOR2(offset.x*iOffsetScale.x, offset.y*iOffsetScale.y)), TransformToUIScreenSpace(originalScreenResolution, screenResolution, UIScaleFont(height, iGlobalScale)), color.RGBA(), italic, weight);
	}

//*****************************************************************************

void CLabelProp::Render(const D3DXVECTOR2& iLabelPosition, const wstring& iLine, const D3DXVECTOR2& iGlobalScale, const D3DXVECTOR2& iOffsetScale)
	{
	RenderManager_2D->RenderText(iLine, facename, TransformToUIScreenSpace(originalScreenResolution, screenResolution, iLabelPosition+D3DXVECTOR2(offset.x*iOffsetScale.x, offset.y*iOffsetScale.y)), TransformToUIScreenSpace(originalScreenResolution, screenResolution, UIScaleFont(height, iGlobalScale)), color.RGBA(), italic, weight);
	}

//******************************************************************************

bool CLabelProp::Intersect(const D3DXVECTOR2& iCursorPosition, const D3DXVECTOR2& iLabelPosition, const D3DXVECTOR2& iGlobalScale, const D3DXVECTOR2& iOffsetScale)
	{
	CFont* font = FontManager->GetFont(facename, TransformToUIScreenSpace(originalScreenResolution, screenResolution, UIScaleFont(height, iGlobalScale)), weight, italic);

	if(font!=NULL)
		{
		D3DXVECTOR2 transformedPosition = TransformToUIScreenSpace(originalScreenResolution, screenResolution, iLabelPosition+D3DXVECTOR2(offset.x*iOffsetScale.x, offset.y*iOffsetScale.y));

		RECT rect;
		rect.bottom = 0;
		rect.left = 0;
		rect.right = 0;
		rect.top = 0;
		font->GetTextExtent(line, rect);
		
		if(iCursorPosition.x > transformedPosition.x - rect.left && iCursorPosition.y > transformedPosition.y - rect.top)
			if(iCursorPosition.x < transformedPosition.x + rect.right && iCursorPosition.y < transformedPosition.y + rect.bottom)
				return true;
		}

	return false;
	}

//******************************************************************************

RECT CLabelProp::GetTextExtent(const D3DXVECTOR2& iGlobalScale)
	{
	RECT rect;
	rect.bottom = 0;
	rect.left = 0;
	rect.right = 0;
	rect.top = 0;

	CFont* font = FontManager->GetFont(facename, TransformToUIScreenSpace(originalScreenResolution, screenResolution, UIScaleFont(height, iGlobalScale)), weight, italic);

	wstring tLine = line;

	if(tLine.size()>0)
		if(*(tLine.end()-1) == ' ')
			tLine.push_back('.');

	if(font!=NULL)
		font->GetTextExtent(tLine, rect);

	return rect;
	}

//******************************************************************************

RECT CLabelProp::GetTextExtent(const float& iTextHeight, const D3DXVECTOR2& iGlobalScale)
	{
	RECT rect;
	rect.bottom = 0;
	rect.left = 0;
	rect.right = 0;
	rect.top = 0;

	CFont* font = FontManager->GetFont(facename, UIScaleFont(iTextHeight, iGlobalScale), weight, italic);

	if(font!=NULL)
		font->GetTextExtent(line, rect);

	return rect;
	}

//******************************************************************************

