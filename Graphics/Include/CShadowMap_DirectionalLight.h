///////////////////////////////////////////////////////////
//  CShadowMap_DirectionalLight.h
//  Created on:      14-11-2009
//  Last modified:   14-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CSHADOWMAP_DIRECTIONALLIGHT_H
#define REGINA_CSHADOWMAP_DIRECTIONALLIGHT_H

#include <CShadowSettings_DirectionalLight.h>
#include <CShadowMap.h>
#include <CDeviceSettingsSave.h>
#include <Exception_OutOfMemmory.h>

namespace Regina
{


class CShadowMap_DirectionalLight : public CShadowMap
{
	LPDIRECT3DTEXTURE9					colorTexture;
	LPDIRECT3DTEXTURE9					zTexture;
	LPDIRECT3DSURFACE9					colorSurface;
	LPDIRECT3DSURFACE9					zSurface;
	bool								inited;
	CShadowSettings_DirectionalLight	shadowSettings;
	CDeviceSettingsSave					prievousDeviceSettings;

private:
	void InitShadowMap();
	void ReleaseShadowMap();

public:
	virtual ~CShadowMap_DirectionalLight();

	CShadowMap_DirectionalLight(LPDIRECT3DDEVICE9 iDevice);
	CShadowMap_DirectionalLight(LPDIRECT3DDEVICE9 iDevice, const CShadowSettings_DirectionalLight& iShadowMapSettings);
	
	void Begin();
	void End();

	void SetShadowMapSettings(const CShadowSettings_DirectionalLight& iShadowMapSettings);
	void SetPosition(const D3DXVECTOR3& iPosition);
	void SetDirection(const D3DXVECTOR3& iDirection);
	void SetDepthBiass(const float& iDepthBiass);
	void SetBiassSlope(const float& iBiassSlope);
	void SetNearClip(const float& iNearClip);
	void SetFarClip(const float& iFarClip);
	void SetSize(const unsigned& iSize);
	void SetBitDepth(const unsigned& iBitDepth);
	void SetRenderTargetFormat(const D3DFORMAT& iRenderTargetFormat);
	void SetDepthBufferFormat(const D3DFORMAT& iDepthBufferFormat);

	CShadowSettings_DirectionalLight	ShadowMapSettings()			const { return shadowSettings; }
	D3DXMATRIX						ViewTransform()				const { return shadowSettings.ViewTransform(); }
	D3DXMATRIX						ProjTransform()				const { return shadowSettings.ProjTransform(); }
	D3DXMATRIX						ShadowTextureTransform()	const { return shadowSettings.ShadowTextureTransform(); }
	LPDIRECT3DTEXTURE9					GetShadowMap();

	void OnLostDevice();
	void OnResetDevice();
};

}

#endif 