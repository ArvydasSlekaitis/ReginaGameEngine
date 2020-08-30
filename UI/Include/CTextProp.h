/*
    CTextProp.h - Contains class CTextProp.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CTEXTPROP
#define REGINA_UI_CTEXTPROP

#include <assert.h>

#include <CUIObject.h>
#include <CFontDefinition.h>
#include <CColor.h>

#include <CFontManager.h>
#include <CRenderManager_2D.h>
using namespace Regina::Graphics;

#include <CText.h>
#include <TTextFormating.h>

namespace Regina
{

namespace UI
{

class CTextProp
{
protected:
	D3DXVECTOR2		originalScreenResolution;
	D3DXVECTOR2		screenResolution;

public:
	D3DXVECTOR2		offset;
	D3DXVECTOR2		globalScale;		//Save global scale for predictable evolution
	float			lineDistance;
	float			maxTextSizeX;
	float			maxTextSizeY;
	CColor			color;
	wstring			facename;
	float			height;
	float			weight;
	bool			italic;
	CText			text;
	CText			formatedText;
	wstring			fileName;
	wstring			lastFileName;

	void			FormatText();
	void			UpdateText();
	RECT			GetLineExtent(const wstring& iLine);
	bool			Predictable(const wstring& iLine);

public:
	CTextProp(const D3DXVECTOR2& iOriginalScreenResolution, const D3DXVECTOR2& iScreenResolution);

	void		Render(const D3DXVECTOR2& iTextPosition, const unsigned& iDisplayLinesFrom, const D3DXVECTOR2& iGlobalScale = D3DXVECTOR2(1, 1), const D3DXVECTOR2& iOffsetScale = D3DXVECTOR2(1, 1));
	bool		Intersect(const D3DXVECTOR2& iCursorPosition, const D3DXVECTOR2& iTextPosition, const D3DXVECTOR2& iGlobalScale = D3DXVECTOR2(1, 1), const D3DXVECTOR2& iOffsetScale = D3DXVECTOR2(1, 1));
	void		SetScreenResolution(const D3DXVECTOR2& iScreenResolution);
	void		Load(const wstring& iFileName);

	unsigned	NumSliderSteps()		const;
	unsigned	NumLinesFitInScreen()	const;
	unsigned	NumFormatedTextLines()	const;
	unsigned	NumTextLines()			const;
};

}

}

#endif
