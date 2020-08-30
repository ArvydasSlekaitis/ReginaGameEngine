/*
    C2DRenderManager.h - Contains class C2DRenderManager implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <C2DRenderManager.h>
using namespace Regina::Graphics;


//*****************************************************************************

C2DRenderManager::~C2DRenderManager()
	{
	Clear();
	if(device != NULL)
		device->Release();
	device = NULL;

	if(sprite != NULL)
		sprite->Release();
	sprite = NULL;
	}

//*****************************************************************************

C2DRenderManager::C2DRenderManager(LPDIRECT3DDEVICE9 iDevice) : device(NULL), sprite(NULL)
  	{
	if(iDevice == NULL)
		throw invalid_argument("C2DRenderManager::C2DRenderManager - argument iDevice == NULL");

	device = iDevice;
	device->AddRef();

	HRESULT hr = D3DXCreateSprite(device, &sprite);

	assert(hr!=D3DERR_INVALIDCALL && L"C2DRenderManager::C2DRenderManager - Cannot create new sprite (D3DERR_INVALIDCALL)");
	if(hr == E_OUTOFMEMORY)
		throw CException_OutOfMemmory("C2DRenderManager::C2DRenderManager", "Cannot create new sprite - not enought memmory ( E_OUTOFMEMORY )");
	}

//*****************************************************************************

void C2DRenderManager::OnLostDevice()
  	{
	sprite->OnLostDevice();
	}

//*****************************************************************************

void C2DRenderManager::OnResetDevice()
  	{
	sprite->OnResetDevice();
	}

//*****************************************************************************

void C2DRenderManager::ReleaseDevice()
  	{
	Clear();

	if(device != NULL)
		device->Release();
	device = NULL;

	if(sprite != NULL)
		sprite->Release();
	sprite = NULL;
	}

//*****************************************************************************

void C2DRenderManager::Clear()
  	{
	for(unsigned i=0; i<renderList.size(); i++;)
		delete renderList[i];
	renderList.clear();
	}

//*****************************************************************************

void C2DRenderManager::RenderText(const wstring& iText, const wstring& iFaceName, const D3DXVECTOR2& iPosition, const unsigned& iHeight, const D3DCOLOR& iColor, const bool& iItalic, const unsigned iWeight)
  	{
	}

//*****************************************************************************

void C2DRenderManager::RenderText(const wstring& iText, const wstring& iFaceName, const D3DXVECTOR2& iPosition, const unsigned& iHeight, const D3DCOLOR& iColor, const bool& iItalic, const unsigned iWeight, RECT iRect, DWORD iFormat)
  	{
	}

//*****************************************************************************

void C2DRenderManager::RenderText(const wstring& iText, LPD3DXFONT iFont, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor)
  	{
	}

//*****************************************************************************

void C2DRenderManager::RenderText(const wstring& iText, LPD3DXFONT iFont, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor, RECT iRect, DWORD iFormat)
  	{
	}

//*****************************************************************************

void C2DRenderManager::RenderImage(const wstring& iTextureName, const D3DXVECTOR2& iPosition, const float iRotation, const float iScale, CColor iColor)
  	{
	}

//*****************************************************************************

void C2DRenderManager::RenderImage(const LPDIRECT3DTEXTURE9 iTexture, const D3DXVECTOR2& iPosition, const float iRotation, const float iScale, CColor iColor)
  	{
	}

//*****************************************************************************

void C2DRenderManager::Render()
	{
	for(unsigned i=0; i<renderList.size(); i++;)
		renderList[i]->Render();
	Clear();
	}

//*****************************************************************************