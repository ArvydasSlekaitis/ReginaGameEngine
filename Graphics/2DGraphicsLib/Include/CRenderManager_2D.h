/*
    CRenderManager_2D.h - Contains class CRenderManager_2D.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_CRENDERMANAGER_2D_H
#define REGINA_GRAPHICS_CRENDERMANAGER_2D_H

#include <d3dx9.h>

#include <string>
#include <vector>
using namespace std;

#include <C2DRenderObject.h>
#include <C2DRenderObject_Text.h>
#include <C2DRenderObject_Image.h>
#include <CFontManager.h>
#include <CTextureManager.h>

namespace Regina
{

namespace Graphics
{

class CRenderManager_2D
{
	LPDIRECT3DDEVICE9			device;
	vector<C2DRenderObject*>	renderList;
	LPD3DXSPRITE				sprite;
	bool						inited;

	CRenderManager_2D();
	CRenderManager_2D(CRenderManager_2D&) {}

public:
	virtual ~CRenderManager_2D();
	static CRenderManager_2D* Instance();

	void Init(LPDIRECT3DDEVICE9 iDevice);
	void Render();			//Render and clear
	void OnLostDevice();
	void OnResetDevice();
	void OnDestroyDevice();	//Clear and release device
	void Clear();	

	void RenderText(const wstring& iText, const wstring& iFaceName, const D3DXVECTOR2& iPosition, const unsigned& iHeight, const D3DCOLOR& iColor, const bool& iItalic, const unsigned iWeight = 1);
	void RenderText(const wstring& iText, const wstring& iFaceName, const unsigned& iHeight, const D3DCOLOR& iColor, const bool& iItalic, const unsigned& iWeight, const RECT& iRect, const DWORD& iFormat);
	void RenderText(const wstring& iText, CFont* iFont, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor) throw(invalid_argument);
	void RenderText(const wstring& iText, CFont* iFont, const D3DCOLOR& iColor, const RECT& iRect, const DWORD& iFormat) throw(invalid_argument);

	void RenderImage(const wstring& iTextureName, const D3DXVECTOR2& iPosition, const float iRotation = 0, const D3DXVECTOR2 iScale = D3DXVECTOR2(1, 1), D3DCOLOR iColor = 0x000000) throw(invalid_argument);
	void RenderImage(const wstring& iTextureName, const D3DXMATRIX& iTransformation, D3DCOLOR iColor = 0x000000) throw(invalid_argument);
	void RenderImage(C2DTexture* iTexture, const D3DXVECTOR2& iPosition, const float iRotation = 0, const D3DXVECTOR2 iScale = D3DXVECTOR2(1, 1), D3DCOLOR iColor = 0x000000) throw(invalid_argument);
	void RenderImage(C2DTexture* iTexture, const D3DXMATRIX& iTransformation, D3DCOLOR iColor = 0x000000) throw(invalid_argument);

};

#define RenderManager_2D CRenderManager_2D::Instance()

}

}

#endif 