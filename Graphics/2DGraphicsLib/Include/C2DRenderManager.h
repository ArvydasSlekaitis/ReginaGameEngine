/*
    C2DRenderManager.h - Contains class C2DRenderManager.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_C2DRENDERMANAGER_H
#define REGINA_GRAPHICS_C2DRENDERMANAGER_H

#include <d3dx9.h>

#include <string>
#include <vector>
using namespace std;

#include <C2DRenderObject.h>

namespace Regina
{

namespace Graphics
{

class C2DRenderManager
{
	LPDIRECT3DDEVICE9			device;
	vector<C2DRenderObject*>	renderList;
	LPD3DXSPRITE				sprite;

public:
	virtual ~C2DRenderManager();

	C2DRenderManager(LPDIRECT3DDEVICE9 iDevice);
	void Render();			//Render and clear
	void OnLostDevice();
	void OnResetDevice();
	void ReleaseDevice();	//Clear and release device
	void Clear();
	void RenderText(const wstring& iText, const wstring& iFaceName, const D3DXVECTOR2& iPosition, const unsigned& iHeight, const D3DCOLOR& iColor, const bool& iItalic, const unsigned iWeight = 1);
	void RenderText(const wstring& iText, const wstring& iFaceName, const D3DXVECTOR2& iPosition, const unsigned& iHeight, const D3DCOLOR& iColor, const bool& iItalic, const unsigned iWeight, RECT iRect, DWORD iFormat);
	void RenderText(const wstring& iText, LPD3DXFONT iFont, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor);
	void RenderText(const wstring& iText, LPD3DXFONT iFont, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor, RECT iRect, DWORD iFormat);
	void RenderImage(const wstring& iTextureName, const D3DXVECTOR2& iPosition, const float iRotation = 0, const float iScale = 1, CColor iColor = CColor());
	void RenderImage(const LPDIRECT3DTEXTURE9 iTexture, const D3DXVECTOR2& iPosition, const float iRotation = 0, const float iScale = 1, CColor iColor = CColor());

};

}

}

#endif 