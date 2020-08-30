/*
    C2DTexture.cpp - Contains class C2DTexture implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <C2DTexture.h>
using namespace Regina::Graphics;


//*****************************************************************************

C2DTexture::~C2DTexture()
	{
	if(texture!=NULL)
		texture->Release();
	texture = NULL;
	}

//*****************************************************************************

C2DTexture::C2DTexture(LPDIRECT3DDEVICE9 iDevice, const wstring& iName, const unsigned iMipLevels) : CTexture(iDevice, iName, iMipLevels), texture(NULL)
  	{
	if(iDevice == NULL)
		throw invalid_argument("C2DTexture::C2DTexture - Argument iDevice = NULL");

	wstring fileName(wstring(L"Data\\Textures\\") + iName);

	HRESULT hr = D3DXCreateTextureFromFileEx(iDevice, fileName.c_str(), D3DX_DEFAULT, D3DX_DEFAULT, iMipLevels, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, NULL, &texture);

	assert(hr != D3DERR_NOTAVAILABLE && L"CUITexture::CUITexture D3DERR_INVALIDDATA");

	if(hr == D3DERR_INVALIDCALL)
		throw CException("C2DTexture::C2DTexture", "Cannot create new texture ( file does not exist? )");

	if(hr == D3DXERR_INVALIDDATA)
		throw CException("C2DTexture::C2DTexture", "Cannot create new texture ( file does not exist? )");
	
		if(hr == E_OUTOFMEMORY)
		throw CException_OutOfMemmory("C2DTexture::C2DTexture", "Cannot create new texture - not enought memmory");

	if(hr == D3DERR_OUTOFVIDEOMEMORY)
		throw CException_OutOfMemmory("C2DTexture::C2DTexture", "Cannot create new texture - not enought video memmory");
	}

//*****************************************************************************

unsigned C2DTexture::GetColorR(const unsigned& iPositionX, const unsigned& iPositionY)
	{
	assert(texture != NULL && L"C2DTexture::GetTextureColorR - texture = NULL");

	if(iPositionX >= Width())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionX - provided position exceeds image boundaries");
	
	if(iPositionY >= Height())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionY - provided position exceeds image boundaries");

	D3DLOCKED_RECT rect;
	HRESULT hr = texture->LockRect(0, &rect, 0, 0);

	assert(hr != D3DERR_INVALIDCALL && L"C2DTexture::GetColorR - texture->LockRect returns D3DERR_INVALIDDATA");
	assert(hr != D3DERR_WASSTILLDRAWING && L"C2DTexture::GetColorR - texture->LockRect returns D3DERR_WASSTILLDRAWING");

	//Access row
	BYTE* pBits = (BYTE*)rect.pBits + iPositionY*rect.Pitch;
//	DWORD color = *((BYTE*)pBits+iPositionX);
	

/*	texture->UnlockRect(0);


	int B = (LOBYTE(color));
	int G = (LOBYTE((color)>>8));
	int R = (LOBYTE((color)>>16));
	int A = (LOBYTE((color)>>24));

	/*B = (LOBYTE(color));
	G = (LOBYTE((color)>>5));2bitai 
	R = (LOBYTE((color)>>11));
	*/

	DWORD	color;
	int		R;
	int		G;
	int		B;
	

	switch(Format())
		{
		//32 Bits
		case D3DFMT_R8G8B8:
		case D3DFMT_A8R8G8B8:	
		case D3DFMT_X8R8G8B8:	
		case D3DFMT_X8B8G8R8:
		case D3DFMT_A8B8G8R8:
		case D3DFMT_A2R10G10B10:
		case D3DFMT_A2B10G10R10:	color = *((DWORD*)pBits+iPositionX);
									texture->UnlockRect(0);	

									B = (LOBYTE(color));
									G = (LOBYTE((color)>>8));
									R = (LOBYTE((color)>>16));
									return R;

		default:					texture->UnlockRect(0);	
									throw exception("C2DTexture::GetColorR - Loaded image format does not support red channel.");
		}

/*
	
	switch(Format())
		{
		case D3DFMT_R8G8B8:
		case D3DFMT_A8R8G8B8:	
		case D3DFMT_X8R8G8B8:	
		case D3DFMT_X8B8G8R8:
		case D3DFMT_A8B8G8R8:		DWORD color = *((DWORD*)pBits+iPositionX);
									texture->UnlockRect(0);	
									return (int)(LOBYTE(color)>>16);

		default:					texture->UnlockRect(0);	
									throw exception("C2DTexture::GetColorR - Loaded image format does not support red channel.");
		}*/


return 0;

	//if(Width() == Height())
	//	{
		/*unsigned iTextureSize = Width();
		D3DLOCKED_RECT m_lockedRect;
		HRESULT hr = texture->LockRect(0, &m_lockedRect, 0, 0);

		assert(hr != D3DERR_INVALIDCALL && L"C2DTexture::GetTextureColorR - texture->LockRect returns D3DERR_INVALIDDATA");
		assert(hr != D3DERR_WASSTILLDRAWING && L"C2DTexture::GetTextureColorR - texture->LockRect returns D3DERR_WASSTILLDRAWING");

		BYTE* pSrcTopRow = (BYTE*)m_lockedRect.pBits;
		int pos = (iPositionY - 1)*iTextureSize + (iPositionX-1);
		DWORD c = *((DWORD*)pSrcTopRow+pos);
		int R = GetBValue(c);

		texture->UnlockRect(0);

		return R;*/


	//	}
	//else
	//	throw CException("C2DTexture::GetTextureColorR", "Texture dimensions must be the same ( Width == Height )");
	
	}

//*****************************************************************************

unsigned C2DTexture::GetColorG(const unsigned& iPositionX, const unsigned& iPositionY)
	{
	assert(texture != NULL && L"C2DTexture::GetColorG - texture = NULL");

	if(iPositionX >= Width())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionX - provided position exceeds image boundaries");
	
	if(iPositionY >= Height())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionY - provided position exceeds image boundaries");

	D3DLOCKED_RECT rect;
	HRESULT hr = texture->LockRect(0, &rect, 0, 0);

	assert(hr != D3DERR_INVALIDCALL && L"C2DTexture::GetColorG - texture->LockRect returns D3DERR_INVALIDDATA");
	assert(hr != D3DERR_WASSTILLDRAWING && L"C2DTexture::GetColorG - texture->LockRect returns D3DERR_WASSTILLDRAWING");

	//Access row
	BYTE* bits = (BYTE*)rect.pBits + iPositionY*rect.Pitch;
	DWORD  color;
	int		G;
	int		B;

	
	switch(Format())
		{
		case D3DFMT_R8G8B8:
		case D3DFMT_A8R8G8B8:	
		case D3DFMT_X8R8G8B8:	
		case D3DFMT_X8B8G8R8:
		case D3DFMT_A8B8G8R8:
		case D3DFMT_A2R10G10B10:
		case D3DFMT_A2B10G10R10:	color = *((DWORD*)bits+iPositionX);
									texture->UnlockRect(0);	

									B = (LOBYTE(color));
									G = (LOBYTE((color)>>8));

									return G;

		default:					texture->UnlockRect(0);	
									throw exception("C2DTexture::GetColorG - Loaded image format does not support green channel.");
		}

	}

//*****************************************************************************

unsigned C2DTexture::GetColorB(const unsigned& iPositionX, const unsigned& iPositionY)
	{
	assert(texture != NULL && L"C2DTexture::GetColorB - texture = NULL");

	if(iPositionX >= Width())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionX - provided position exceeds image boundaries");
	
	if(iPositionY >= Height())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionY - provided position exceeds image boundaries");

	D3DLOCKED_RECT rect;
	HRESULT hr = texture->LockRect(0, &rect, 0, 0);

	assert(hr != D3DERR_INVALIDCALL && L"C2DTexture::GetColorB - texture->LockRect returns D3DERR_INVALIDDATA");
	assert(hr != D3DERR_WASSTILLDRAWING && L"C2DTexture::GetColorB - texture->LockRect returns D3DERR_WASSTILLDRAWING");

	//Access row
	BYTE*	bits = (BYTE*)rect.pBits + iPositionY*rect.Pitch;
	DWORD	color;

	switch(Format())
		{
		case D3DFMT_R8G8B8:
		case D3DFMT_A8R8G8B8:	
		case D3DFMT_X8R8G8B8:	
		case D3DFMT_X8B8G8R8:
		case D3DFMT_A8B8G8R8:
		case D3DFMT_A2R10G10B10:
		case D3DFMT_A2B10G10R10:	color = *((DWORD*)bits+iPositionX);
									texture->UnlockRect(0);	
									return (int)(LOBYTE(color));

		default:					texture->UnlockRect(0);	
									throw exception("C2DTexture::GetColorR - Loaded image format does not support blue channel.");
		}

	}

//*****************************************************************************

unsigned C2DTexture::GetColorA(const unsigned& iPositionX, const unsigned& iPositionY)
	{
	assert(texture != NULL && L"C2DTexture::GetColorA - texture = NULL");

	if(iPositionX >= Width())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionX - provided position exceeds image boundaries");
	
	if(iPositionY >= Height())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionY - provided position exceeds image boundaries");


	D3DLOCKED_RECT rect;
	HRESULT hr = texture->LockRect(0, &rect, 0, 0);

	assert(hr != D3DERR_INVALIDCALL && L"C2DTexture::GetColorA - texture->LockRect returns D3DERR_INVALIDDATA");
	assert(hr != D3DERR_WASSTILLDRAWING && L"C2DTexture::GetColorA - texture->LockRect returns D3DERR_WASSTILLDRAWING");

	//Access row
	BYTE*	bits = (BYTE*)rect.pBits + iPositionY*rect.Pitch;
	DWORD	color;
	int		R;
	int		G;
	int		B;
	int		A;

	switch(Format())
		{
		case D3DFMT_A8R8G8B8:	
		case D3DFMT_X8R8G8B8:	
		case D3DFMT_X8B8G8R8:
		case D3DFMT_A8B8G8R8:
		case D3DFMT_A2R10G10B10:
		case D3DFMT_A2B10G10R10:	color = *((DWORD*)bits+iPositionX);
									texture->UnlockRect(0);	

									B = (LOBYTE(color));
									G = (LOBYTE((color)>>8));
									R = (LOBYTE((color)>>16));
									A = (LOBYTE((color)>>24));
									return A;

		default:					texture->UnlockRect(0);	
									throw exception("C2DTexture::GetColorA - Loaded image format does not support aplha channel.");
		}

	}

//*****************************************************************************

void C2DTexture::GetColorRGB(const unsigned& iPositionX, const unsigned& iPositionY, unsigned& oR, unsigned& oG, unsigned& oB)
	{
	assert(texture != NULL && L"C2DTexture::GetColorRGB - texture = NULL");

	if(iPositionX >= Width())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionX - provided position exceeds image boundaries");
	
	if(iPositionY >= Height())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionY - provided position exceeds image boundaries");


	D3DLOCKED_RECT rect;
	HRESULT hr = texture->LockRect(0, &rect, 0, 0);

	assert(hr != D3DERR_INVALIDCALL && L"C2DTexture::GetColorRGB - texture->LockRect returns D3DERR_INVALIDDATA");
	assert(hr != D3DERR_WASSTILLDRAWING && L"C2DTexture::GetColorRGB - texture->LockRect returns D3DERR_WASSTILLDRAWING");

	//Access row
	BYTE* bits = (BYTE*)rect.pBits + iPositionY*rect.Pitch;
	DWORD  color;
	
	switch(Format())
		{
		case D3DFMT_R8G8B8:
		case D3DFMT_A8R8G8B8:	
		case D3DFMT_X8R8G8B8:	
		case D3DFMT_X8B8G8R8:
		case D3DFMT_A8B8G8R8:
		case D3DFMT_A2R10G10B10:
		case D3DFMT_A2B10G10R10:	color = *((DWORD*)bits+iPositionX);
									texture->UnlockRect(0);	
									oB = (int)(LOBYTE(color));
									oG = (int)(LOBYTE(color)>>8);
									oR = (int)(LOBYTE(color)>>16);
									break;

		default:					texture->UnlockRect(0);	
									throw exception("C2DTexture::GetColorRGB - Loaded image format does not support either red or green or blue channel.");
		}
	}

//*****************************************************************************

void C2DTexture::GetColorRGBA(const unsigned& iPositionX, const unsigned& iPositionY, unsigned& oR, unsigned& oG, unsigned& oB, unsigned& oA)
	{
	assert(texture != NULL && L"C2DTexture::GetColorRGBA - texture = NULL");

	if(iPositionX >= Width())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionX - provided position exceeds image boundaries");
	
	if(iPositionY >= Height())
		throw invalid_argument("C2DTexture::GetColorR - argument iPositionY - provided position exceeds image boundaries");

	D3DLOCKED_RECT rect;
	HRESULT hr = texture->LockRect(0, &rect, 0, 0);

	assert(hr != D3DERR_INVALIDCALL && L"C2DTexture::GetColorRGBA - texture->LockRect returns D3DERR_INVALIDDATA");
	assert(hr != D3DERR_WASSTILLDRAWING && L"C2DTexture::GetColorRGBA - texture->LockRect returns D3DERR_WASSTILLDRAWING");

	//Access row
	BYTE* bits = (BYTE*)rect.pBits + iPositionY*rect.Pitch;
	DWORD  color;

	switch(Format())
		{
		case D3DFMT_A8R8G8B8:	
		case D3DFMT_X8R8G8B8:	
		case D3DFMT_X8B8G8R8:
		case D3DFMT_A8B8G8R8:
		case D3DFMT_A2R10G10B10:
		case D3DFMT_A2B10G10R10:	color = *((DWORD*)bits+iPositionX);
									texture->UnlockRect(0);	
									oB = (int)(LOBYTE(color));
									oG = (int)(LOBYTE(color)>>8);
									oR = (int)(LOBYTE(color)>>16);
									oA = (int)(LOBYTE(color)>>24);
									break;

		default:					texture->UnlockRect(0);	
									throw exception("C2DTexture::GetColorRGBA - Loaded image format does not support either red or green or blue or alpha channel.");
		}
	}

//*****************************************************************************