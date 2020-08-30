/*
    CImageProp.h - Contains class CImageProp.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CIMAGEPROP
#define REGINA_UI_CIMAGEPROP

#include <assert.h>
#include <string>
#include <sstream>
using namespace std;

#include <CColor.h>
#include <Functions_UI.h>

#include <CTextureManager.h>
#include <CRenderManager_2D.h>
using namespace Regina::Graphics;

namespace Regina
{

namespace UI
{

class CImageProp
{
protected:
	D3DXVECTOR2		originalScreenResolution;
	D3DXVECTOR2		screenResolution;

public:
	D3DXVECTOR2		offset;
	CColor			color;
	wstring			textureName;
	D3DXVECTOR2		scale;
	float			rotation;
	bool			alphaIntersectionTest;
	
public:
	~CImageProp();
	CImageProp(const D3DXVECTOR2& iOriginalScreenResolution, const D3DXVECTOR2& iScreenResolution);

	void Render(const D3DXVECTOR2& iImagePosition, const D3DXVECTOR2& iGlobalScale = D3DXVECTOR2(1, 1), const D3DXVECTOR2& iOffsetScale = D3DXVECTOR2(1, 1));
	bool Intersect(const D3DXVECTOR2& iCursorPosition, const D3DXVECTOR2& iImagePosition, const D3DXVECTOR2& iGlobalScale = D3DXVECTOR2(1, 1), const D3DXVECTOR2& iOffsetScale = D3DXVECTOR2(1, 1));
	void SetScreenResolution(const D3DXVECTOR2& iScreenResolution) { screenResolution = iScreenResolution; }
	RECT GetBoundingRect(const D3DXVECTOR2& iImagePosition, const D3DXVECTOR2& iGlobalScale = D3DXVECTOR2(1, 1), const D3DXVECTOR2& iOffsetScale = D3DXVECTOR2(1, 1));
};

}

}


#endif
