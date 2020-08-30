///////////////////////////////////////////////////////////
//  CDirectionalLight_Data.cpp
//  Created on:      04-09-2008
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CDirectionalLight_Data.h>
using namespace Regina;


//*****************************************************************************

CDirectionalLight_Data::~CDirectionalLight_Data()
	{

	}

//*****************************************************************************

CDirectionalLight_Data::CDirectionalLight_Data(LPDIRECT3DDEVICE9 iDevice, const string& iName, const D3DXVECTOR3& iDirection, const D3DXVECTOR3& iIrriadiance, const CShadowSettings_DirectionalLight& iShadowMapSettings) : CLight(iDevice, iName, iIrriadiance), shadowMap(iDevice, iShadowMapSettings)
  	{
	}

//*****************************************************************************

void CDirectionalLight_Data::SetShadowMapSettings(const CShadowSettings_DirectionalLight& iShadowMapSettings)
	{
	shadowMap.SetShadowMapSettings(iShadowMapSettings);
	}

//*****************************************************************************

void CDirectionalLight_Data::CreateShadowMap()
  	{
	shadowMap.Begin();
	RenderShadowCasters(shadowMap.ViewTransform(), shadowMap.ProjTransform(), shadowMap.ShadowMapSettings().Position());
	shadowMap.End();
	}

//*****************************************************************************

bool CDirectionalLight_Data::Intersect(const D3DXVECTOR3& iPosition, const float& iRadius) const 
  	{
	return true;
	}

//*****************************************************************************

void CDirectionalLight_Data::OnLostDevice()
	{
	shadowMap.OnLostDevice();
	CLight::OnLostDevice();
	}

//*****************************************************************************

void CDirectionalLight_Data::OnResetDevice()
	{
	shadowMap.OnResetDevice();
	CLight::OnResetDevice();
	}

//*****************************************************************************

void CDirectionalLight_Data::SetDirection(const D3DXVECTOR3& iDirection)
	{
	shadowMap.SetDirection(iDirection);
	}

//*****************************************************************************

D3DXVECTOR3 CDirectionalLight_Data::Direction() const
	{
	return shadowMap.ShadowMapSettings().Direction();
	}

//*****************************************************************************

D3DXMATRIXA16 CDirectionalLight_Data::ShadowTextureTransform() const
	{
	return shadowMap.ShadowTextureTransform();
	}

//*****************************************************************************

LPDIRECT3DTEXTURE9 CDirectionalLight_Data::ShadowMap()
	{
	return shadowMap.GetShadowMap();
	}

//*****************************************************************************

CShadowSettings_DirectionalLight CDirectionalLight_Data::ShadowMapSettings() const
	{
	return shadowMap.ShadowMapSettings();
	}

//*****************************************************************************


