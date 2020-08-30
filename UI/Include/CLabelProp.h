/*
    CLabelProp.h - Contains class CLabelProp.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CLABERPROP
#define REGINA_UI_CLABERPROP

#include <assert.h>

#include <CUIObject.h>
#include <CFontDefinition.h>
#include <CColor.h>

#include <CFontManager.h>
#include <CRenderManager_2D.h>
using namespace Regina::Graphics;

namespace Regina
{

namespace UI
{

class CLabelProp
{
protected:
	D3DXVECTOR2		originalScreenResolution;
	D3DXVECTOR2		screenResolution;

public:
	D3DXVECTOR2		offset;
	CColor			color;
	wstring			facename;
	float			height;
	float			weight;
	bool			italic;
	wstring			line;

public:
	CLabelProp(const D3DXVECTOR2& iOriginalScreenResolution, const D3DXVECTOR2& iScreenResolution);

	void Render(const D3DXVECTOR2& iLabelPosition, const D3DXVECTOR2& iGlobalScale = D3DXVECTOR2(1, 1), const D3DXVECTOR2& iOffsetScale = D3DXVECTOR2(1, 1));
	void Render(const D3DXVECTOR2& iLabelPosition, const wstring& iLine, const D3DXVECTOR2& iGlobalScale = D3DXVECTOR2(1, 1), const D3DXVECTOR2& iOffsetScale = D3DXVECTOR2(1, 1));
	bool Intersect(const D3DXVECTOR2& iCursorPosition, const D3DXVECTOR2& iLabelPosition, const D3DXVECTOR2& iGlobalScale = D3DXVECTOR2(1, 1), const D3DXVECTOR2& iOffsetScale = D3DXVECTOR2(1, 1));
	void SetScreenResolution(const D3DXVECTOR2& iScreenResolution) { screenResolution = iScreenResolution; }
	RECT GetTextExtent(const D3DXVECTOR2& iGlobalScale = D3DXVECTOR2(1, 1));
	RECT GetTextExtent(const float& iTextHeight, const D3DXVECTOR2& iGlobalScale = D3DXVECTOR2(1, 1));
};

}

}

#endif
