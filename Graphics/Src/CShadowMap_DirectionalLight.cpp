///////////////////////////////////////////////////////////
//  CShadowMap_DirectionalLight.cpp
//  Created on:      14-11-2009
//  Last modified:   14-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CShadowMap_DirectionalLight.h>
using namespace Regina;


//*****************************************************************************

CShadowMap_DirectionalLight::~CShadowMap_DirectionalLight()
	{
	ReleaseShadowMap();
	}

//*****************************************************************************

CShadowMap_DirectionalLight::CShadowMap_DirectionalLight(LPDIRECT3DDEVICE9 iDevice) : CShadowMap(iDevice), colorTexture(NULL), zTexture(NULL), colorSurface(NULL), zSurface(NULL), inited(false), shadowSettings()
  	{
	InitShadowMap();
	}

//*****************************************************************************

CShadowMap_DirectionalLight::CShadowMap_DirectionalLight(LPDIRECT3DDEVICE9 iDevice, const CShadowSettings_DirectionalLight& iShadowMapSettings) : CShadowMap(iDevice), colorTexture(NULL), zTexture(NULL), colorSurface(NULL), zSurface(NULL), inited(false), shadowSettings(iShadowMapSettings)
  	{
	InitShadowMap();
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::InitShadowMap()
  	{
	if(inited == true)
		{
		ReleaseShadowMap();
		}


	HRESULT hr = device->CreateTexture(shadowSettings.Size(), shadowSettings.Size(), 1, D3DUSAGE_DEPTHSTENCIL, shadowSettings.DepthBufferFormat(), D3DPOOL_DEFAULT , &zTexture, NULL);
	
	if(FAILED(hr))
		{
		if(zTexture!=NULL)
			zTexture->Release();
		zTexture = NULL;

		if(hr == D3DERR_INVALIDCALL)
			throw invalid_argument("CShadowMap_DirectionalLight::InitShadowMap - one of the arguments is invalid ( CreateTexture returns D3DERR_INVALIDCALL )");

		if(hr == E_OUTOFMEMORY)
			throw Exception_OutOfMemmory("CShadowMap_DirectionalLight::InitShadowMap - there is not enough free memmory for shadow map creation ( CreateTexture returns E_OUTOFMEMORY )");

		if(hr == D3DERR_OUTOFVIDEOMEMORY)
			throw Exception_OutOfMemmory("CShadowMap_DirectionalLight::InitShadowMap - there is not enough free video memmory for shadow map creation ( CreateTexture returns D3DERR_OUTOFVIDEOMEMORY )");
		}

	hr = device->CreateTexture(shadowSettings.Size(), shadowSettings.Size(), 1, D3DUSAGE_RENDERTARGET, shadowSettings.RenderTargetFormat(), D3DPOOL_DEFAULT, &colorTexture, NULL);

	if(FAILED(hr))
		{
		if(zTexture!=NULL)
			zTexture->Release();
		zTexture = NULL;

		if(colorTexture!=NULL)
			colorTexture->Release();
		colorTexture = NULL;

		if(hr == D3DERR_INVALIDCALL)
			throw invalid_argument("CShadowMap_DirectionalLight::InitShadowMap - one of the arguments is invalid ( CreateTexture returns D3DERR_INVALIDCALL )");

		if(hr == E_OUTOFMEMORY)
			throw Exception_OutOfMemmory("CShadowMap_DirectionalLight::InitShadowMap - there is not enough free memmory for shadow map ( color texture ) creation ( CreateTexture returns E_OUTOFMEMORY )");

		if(hr == D3DERR_OUTOFVIDEOMEMORY)
			throw Exception_OutOfMemmory("CShadowMap_DirectionalLight::InitShadowMap - there is not enough free video memmory for shadow map ( color texture ) creation ( CreateTexture returns D3DERR_OUTOFVIDEOMEMORY )");
		}

	zTexture->GetSurfaceLevel(0, &zSurface);
	colorTexture->GetSurfaceLevel(0, &colorSurface);

	inited = true;
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::ReleaseShadowMap()
  	{
	if(colorSurface!=NULL)
		colorSurface->Release();
	colorSurface = NULL;

	if(colorTexture!=NULL)
		colorTexture->Release();
	colorTexture = NULL;

	if(zSurface!=NULL)
		zSurface->Release();
	zSurface = NULL;

	if(zTexture!=NULL)
		zTexture->Release();
	zTexture = NULL;

	inited = false;
	}

//*****************************************************************************

LPDIRECT3DTEXTURE9 CShadowMap_DirectionalLight::GetShadowMap()
  	{
	return  zTexture;
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::Begin()
  	{
	if(inited == false)
		InitShadowMap();


	prievousDeviceSettings.Save(device);

	device->SetRenderTarget(0, colorSurface);
	device->SetDepthStencilSurface(zSurface);

	device->SetViewport(&shadowSettings.Viewport());

	float db = shadowSettings.DepthBiass();
	float sl = shadowSettings.BiassSlope();
	device->SetRenderState(D3DRS_DEPTHBIAS, *(DWORD*)&db);
	device->SetRenderState(D3DRS_SLOPESCALEDEPTHBIAS, *(DWORD*)&sl);

	device->SetTransform( D3DTS_VIEW, &shadowSettings.ViewTransform() );
	device->SetTransform( D3DTS_PROJECTION, &shadowSettings.ProjTransform() );

	device->Clear(0L, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x000000ff, 1.0f, 0L);
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::End()
  	{
	prievousDeviceSettings.Restore();
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetPosition(const D3DXVECTOR3& iPosition)
  	{
	shadowSettings.SetPosition(iPosition);
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetDirection(const D3DXVECTOR3& iDirection)
  	{
	shadowSettings.SetDirection(iDirection);
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetDepthBiass(const float& iDepthBiass)
  	{
	shadowSettings.SetDepthBiass(iDepthBiass);
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetBiassSlope(const float& iBiassSlope)
  	{
	shadowSettings.SetBiassSlope(iBiassSlope);
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetNearClip(const float& iNearClip)
  	{
	shadowSettings.SetNearClip(iNearClip);
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetFarClip(const float& iFarClip)
  	{
	shadowSettings.SetFarClip(iFarClip);
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetSize(const unsigned& iSize)
	{
	if(shadowSettings.Size() != iSize)
		{
		shadowSettings.SetSize(iSize);
		ReleaseShadowMap();
		InitShadowMap();
		}
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetBitDepth(const unsigned& iBitDepth)
	{
	shadowSettings.SetBitDepth(iBitDepth);
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetRenderTargetFormat(const D3DFORMAT& iRenderTargetFormat)
	{
	if(shadowSettings.RenderTargetFormat() != iRenderTargetFormat)
		{
		shadowSettings.SetRenderTargetFormat(iRenderTargetFormat);
		ReleaseShadowMap();
		InitShadowMap();
		}
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetDepthBufferFormat(const D3DFORMAT& iDepthBufferFormat)
	{
	if(shadowSettings.DepthBufferFormat() != iDepthBufferFormat)
		{
		shadowSettings.SetDepthBufferFormat(iDepthBufferFormat);
		ReleaseShadowMap();
		InitShadowMap();
		}
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::SetShadowMapSettings(const CShadowSettings_DirectionalLight& iShadowMapSettings)
	{
	if(shadowSettings.Size() != iShadowMapSettings.Size() || shadowSettings.RenderTargetFormat() != iShadowMapSettings.RenderTargetFormat() || shadowSettings.DepthBufferFormat() != iShadowMapSettings.DepthBufferFormat())
		{
		shadowSettings = iShadowMapSettings;
		ReleaseShadowMap();
		InitShadowMap();
		}
	else
		shadowSettings = iShadowMapSettings;
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::OnLostDevice()
	{
	ReleaseShadowMap();
	}

//*****************************************************************************

void CShadowMap_DirectionalLight::OnResetDevice()
	{
	InitShadowMap();
	}

//*****************************************************************************

