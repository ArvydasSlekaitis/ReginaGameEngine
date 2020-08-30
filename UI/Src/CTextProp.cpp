/*
    CTextProp.cpp - Contains class CTextProp implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CTextProp.h>
using namespace Regina::UI;


//*****************************************************************************

CTextProp::CTextProp(const D3DXVECTOR2& iOriginalScreenResolution, const D3DXVECTOR2& iScreenResolution) : facename(L"Arial"), height(12), weight(1), italic(false), originalScreenResolution(iOriginalScreenResolution), screenResolution(iScreenResolution), offset(0, 0), globalScale(1, 1), lineDistance(15), maxTextSizeX(100), maxTextSizeY(100), fileName(L""), lastFileName(L"")
	{
	}

//*****************************************************************************

void CTextProp::Render(const D3DXVECTOR2& iTextPosition, const unsigned& iDisplayLinesFrom, const D3DXVECTOR2& iGlobalScale, const D3DXVECTOR2& iOffsetScale)
	{
	globalScale = iGlobalScale;
	UpdateText();

	unsigned displayLines = min(iDisplayLinesFrom + NumLinesFitInScreen(), formatedText.size());

	for(unsigned i=iDisplayLinesFrom; i<displayLines; i++)
		{
		D3DXVECTOR2 linePos = iTextPosition + D3DXVECTOR2(offset.x*iOffsetScale.x, offset.y*iOffsetScale.y) + D3DXVECTOR2(0, (i-iDisplayLinesFrom) * TransformToUIScreenSpace(originalScreenResolution, screenResolution, D3DXVECTOR2(1, lineDistance)).y*iGlobalScale.y);
		RenderManager_2D->RenderText(formatedText[i], facename, TransformToUIScreenSpace(originalScreenResolution, screenResolution, linePos), TransformToUIScreenSpace(originalScreenResolution, screenResolution, UIScaleFont(height, iGlobalScale)), color.RGBA(), italic, weight);
		}
	}


//******************************************************************************

bool CTextProp::Intersect(const D3DXVECTOR2& iCursorPosition, const D3DXVECTOR2& iTextPosition, const D3DXVECTOR2& iGlobalScale, const D3DXVECTOR2& iOffsetScale)
	{
	globalScale = iGlobalScale;
	UpdateText();

	CFont* font = FontManager->GetFont(facename, TransformToUIScreenSpace(originalScreenResolution, screenResolution, UIScaleFont(height, iGlobalScale)), weight, italic);

	if(font!=NULL)
		{
		D3DXVECTOR2 transformedMaxTextSize = TransformToUIScreenSpace(originalScreenResolution, screenResolution, D3DXVECTOR2(maxTextSizeX*iGlobalScale.x, maxTextSizeY*iGlobalScale.y));
		D3DXVECTOR2 transformedPosition = TransformToUIScreenSpace(originalScreenResolution, screenResolution, iTextPosition + D3DXVECTOR2(offset.x*iOffsetScale.x, offset.y*iOffsetScale.y));

		RECT rect;
		rect.bottom = transformedPosition.y + transformedMaxTextSize.y;
		rect.left = transformedPosition.x;
		rect.right = transformedPosition.x + transformedMaxTextSize.x;
		rect.top = transformedPosition.y;
		
		if(iCursorPosition.x > rect.left && iCursorPosition.y > rect.top)
			if(iCursorPosition.x < rect.right && iCursorPosition.y < rect.bottom)
				return true;
		}

	return false;
	}

//******************************************************************************

void CTextProp::SetScreenResolution(const D3DXVECTOR2& iScreenResolution) 
	{ 
	screenResolution = iScreenResolution; 
	FormatText();
	}

//******************************************************************************

void CTextProp::Load(const wstring& iFileName)
	{
	text.clear();

	if(fileName.size() > 0)
		text.Load(L"Data\\Text\\" + iFileName);
	}

//******************************************************************************

void CTextProp::FormatText()
	{
	formatedText.clear();
	Regina::FormatText(text, formatedText, this, &CTextProp::Predictable);
	}

//******************************************************************************

unsigned CTextProp::NumSliderSteps() const
	{
	return max(0, (int)NumFormatedTextLines() - (int)NumLinesFitInScreen());
	}

//******************************************************************************

unsigned CTextProp::NumLinesFitInScreen() const
	{
	return floor(TransformToUIScreenSpace(originalScreenResolution, screenResolution, D3DXVECTOR2(1, maxTextSizeY)).y / (TransformToUIScreenSpace(originalScreenResolution, screenResolution, D3DXVECTOR2(1, lineDistance)).y));
	}

//******************************************************************************

unsigned CTextProp::NumFormatedTextLines() const
	{
	return formatedText.size();
	}

//******************************************************************************

unsigned CTextProp::NumTextLines() const
	{
	return text.size();
	}

//******************************************************************************

bool CTextProp::Predictable(const wstring& iLine)
	{
	const float curSize			= GetLineExtent(iLine).right;
	const float curMaxTextSize	= TransformToUIScreenSpace(originalScreenResolution, screenResolution, D3DXVECTOR2(maxTextSizeX*globalScale.x, 1)).x;

	if(curSize <= curMaxTextSize)
		return true;
	else
		return false;
	}

//******************************************************************************

RECT CTextProp::GetLineExtent(const wstring& iLine)
	{
	RECT rect;
	rect.bottom = 0;
	rect.left = 0;
	rect.right = 0;
	rect.top = 0;

	CFont* font = FontManager->GetFont(facename, TransformToUIScreenSpace(originalScreenResolution, screenResolution, UIScaleFont(height, globalScale)), weight, italic);

	wstring tLine = iLine;

	if(tLine.size()>0)
		if(*(tLine.end()-1) == ' ')
			tLine.push_back('.');

	if(font!=NULL)
		font->GetTextExtent(tLine, rect);

	return rect;
	}

//******************************************************************************

void CTextProp::UpdateText()
	{
	if(lastFileName != fileName)
		{
		Load(fileName);
		FormatText();
		lastFileName = fileName;
		}
	}

//******************************************************************************
