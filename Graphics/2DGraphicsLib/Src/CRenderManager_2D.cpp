/*
    CRenderManager_2D.h - Contains class CRenderManager_2D implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CRenderManager_2D.h>
using namespace Regina::Graphics;


//*****************************************************************************

CRenderManager_2D* CRenderManager_2D::Instance()
	{
	static CRenderManager_2D manager;
	return &manager;
	}

//*****************************************************************************

CRenderManager_2D::~CRenderManager_2D()
	{
	OnDestroyDevice();
	}

//*****************************************************************************

CRenderManager_2D::CRenderManager_2D() : device(NULL), sprite(NULL), inited(false)
	{
	}
//*****************************************************************************

void CRenderManager_2D::Init(LPDIRECT3DDEVICE9 iDevice) 
  	{
	if(inited == true)
		OnDestroyDevice();

	if(iDevice == NULL)
		throw invalid_argument("C2DRenderManager::Init - argument iDevice == NULL");

	device = iDevice;
	device->AddRef();

	HRESULT hr = D3DXCreateSprite(device, &sprite);

	assert(hr!=D3DERR_INVALIDCALL && L"C2DRenderManager::C2DRenderManager - Cannot create new sprite (D3DERR_INVALIDCALL)");
	if(hr == E_OUTOFMEMORY)
		throw CException_OutOfMemmory("C2DRenderManager::C2DRenderManager", "Cannot create new sprite - not enought memmory ( E_OUTOFMEMORY )");

	inited = true;
	}

//*****************************************************************************

void CRenderManager_2D::OnLostDevice()
  	{
	if(sprite!=NULL)
		sprite->OnLostDevice();
	}

//*****************************************************************************

void CRenderManager_2D::OnResetDevice()
  	{
	if(sprite!=NULL)
		sprite->OnResetDevice();
	}

//*****************************************************************************

void CRenderManager_2D::OnDestroyDevice()
  	{
	Clear();

	if(device != NULL)
		device->Release();
	device = NULL;

	if(sprite != NULL)
		sprite->Release();
	sprite = NULL;

	inited = false;
	}

//*****************************************************************************

void CRenderManager_2D::Clear()
  	{
	for(unsigned i=0; i<renderList.size(); i++)
		delete renderList[i];
	renderList.clear();
	}

//*****************************************************************************

void CRenderManager_2D::RenderText(const wstring& iText, const wstring& iFaceName, const D3DXVECTOR2& iPosition, const unsigned& iHeight, const D3DCOLOR& iColor, const bool& iItalic, const unsigned iWeight) 
	{
	assert(inited == true && L"C2DRenderManager::RenderText - Cannot render text because 2D render manager is not inited. Call Init first.");

	CFont* font(NULL);
	font = FontManager->GetFont(iFaceName, iHeight, iWeight, iItalic);
	renderList.push_back(new C2DRenderObject_Text(iText, font, iPosition, iColor));
	}

//*****************************************************************************

void CRenderManager_2D::RenderText(const wstring& iText, const wstring& iFaceName, const unsigned& iHeight, const D3DCOLOR& iColor, const bool& iItalic, const unsigned& iWeight, const RECT& iRect, const DWORD& iFormat)
	{
	assert(inited == true && L"C2DRenderManager::RenderText - Cannot render text because 2D render manager is not inited. Call Init first.");

	CFont* font(NULL);
	font = FontManager->GetFont(iFaceName, iHeight, iWeight, iItalic);
	renderList.push_back(new C2DRenderObject_Text(iText, font, iColor, iRect, iFormat));
	}

//*****************************************************************************

void CRenderManager_2D::RenderText(const wstring& iText, CFont* iFont, const D3DXVECTOR2& iPosition, const D3DCOLOR& iColor) 
	{
	assert(inited == true && L"C2DRenderManager::RenderText - Cannot render text because 2D render manager is not inited. Call Init first.");

	if(iFont == NULL)
		throw invalid_argument("C2DRenderManager::RenderText - argument iFont == NULL");

	renderList.push_back(new C2DRenderObject_Text(iText, iFont, iPosition, iColor));
	}

//*****************************************************************************

void CRenderManager_2D::RenderText(const wstring& iText, CFont* iFont, const D3DCOLOR& iColor, const RECT& iRect, const DWORD& iFormat)
	{
	assert(inited == true && L"C2DRenderManager::RenderText - Cannot render text because 2D render manager is not inited. Call Init first.");

	if(iFont == NULL)
		throw invalid_argument("C2DRenderManager::RenderText - argument iFont == NULL");

	renderList.push_back(new C2DRenderObject_Text(iText, iFont, iColor, iRect, iFormat));
	}

//*****************************************************************************

void CRenderManager_2D::RenderImage(const wstring& iTextureName, const D3DXVECTOR2& iPosition, const float iRotation, const D3DXVECTOR2 iScale, D3DCOLOR iColor)
	{
	assert(inited == true && L"C2DRenderManager::RenderImage - Cannot render image because 2D render manager is not inited. Call Init first.");

	C2DTexture* texture(NULL);
	texture = TextureManager->Get2D(iTextureName);
	if(texture!=NULL)
		renderList.push_back(new C2DRenderObject_Image(texture, iPosition, iRotation, iScale, iColor));
	}

//*****************************************************************************

void CRenderManager_2D::RenderImage(const wstring& iTextureName, const D3DXMATRIX& iTransformation, D3DCOLOR iColor)
	{
	assert(inited == true && L"C2DRenderManager::RenderImage - Cannot render image because 2D render manager is not inited. Call Init first.");

	C2DTexture* texture(NULL);
	texture = TextureManager->Get2D(iTextureName);
	if(texture!=NULL)
		renderList.push_back(new C2DRenderObject_Image(texture, iTransformation, iColor));
	}

//*****************************************************************************

void CRenderManager_2D::RenderImage(C2DTexture* iTexture, const D3DXVECTOR2& iPosition, const float iRotation, const D3DXVECTOR2 iScale, D3DCOLOR iColor)
	{
	assert(inited == true && L"C2DRenderManager::RenderImage - Cannot render image because 2D render manager is not inited. Call Init first.");

	if(iTexture == NULL)
		throw invalid_argument("C2DRenderManager::RenderImage - argument iTexture == NULL");

	renderList.push_back(new C2DRenderObject_Image(iTexture, iPosition, iRotation, iScale, iColor));
	}

//*****************************************************************************

void CRenderManager_2D::RenderImage(C2DTexture* iTexture, const D3DXMATRIX& iTransformation, D3DCOLOR iColor)
	{
	assert(inited == true && L"C2DRenderManager::RenderImage - Cannot render image because 2D render manager is not inited. Call Init first.");

	if(iTexture == NULL)
		throw invalid_argument("C2DRenderManager::RenderImage - argument iTexture == NULL");

	renderList.push_back(new C2DRenderObject_Image(iTexture, iTransformation, iColor));
	}

//*****************************************************************************

void CRenderManager_2D::Render()
	{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	
	for(unsigned i=0; i<renderList.size(); i++)
		renderList[i]->Render(sprite);

	sprite->End();
	Clear();
	}

//*****************************************************************************