///////////////////////////////////////////////////////////
//  CDirectionalLight.cpp
//  Created on:      27-11-2009
//  Last modified:   27-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CDirectionalLight.h>
using namespace Regina;


//*****************************************************************************

CDirectionalLight::CDirectionalLight(CDirectionalLight_Data* iData) : data(iData)
  	{
	if(iData == NULL)
		throw invalid_argument("CDirectionalLight::CDirectionalLight - argument iData==NULL");
	data = iData;
	}

//*****************************************************************************

CDirectionalLight::CDirectionalLight(const CDirectionalLight& iDirectionalLight)
  	{
	data = iDirectionalLight.data;
	}

//*****************************************************************************

CDirectionalLight::~CDirectionalLight()
  	{
	data=NULL;
	}

//*****************************************************************************

D3DXVECTOR3 CDirectionalLight::Direction() const 
  	{
	return data->Direction();
	}

//*****************************************************************************

string CDirectionalLight::Name() const 
  	{
	return data->Name();
	}

//*****************************************************************************

void CDirectionalLight::SetDirection(const D3DXVECTOR3& iDirection)
  	{
	data->SetDirection(iDirection);
	}

//*****************************************************************************

bool CDirectionalLight::Enabled() const 
  	{
	return data->Enabled();
	}

//*****************************************************************************

bool CDirectionalLight::ShadowCastingEnabled() const 
  	{
	return data->ShadowCastingEnabled();
	}

//*****************************************************************************

D3DXVECTOR3 CDirectionalLight::Irriadiance() const 
  	{
	return  data->Irriadiance();
	}

//*****************************************************************************

void CDirectionalLight::Enable()
  	{
	data->Enable();
	}

//*****************************************************************************

void CDirectionalLight::Disable()
  	{
	data->Disable();
	}

//*****************************************************************************

void CDirectionalLight::EnableShadowCasting()
  	{
	data->EnableShadowCasting();
	}

//*****************************************************************************

void CDirectionalLight::DisableShadowCasting()
  	{
	data->DisableShadowCasting();
	}

//*****************************************************************************

void CDirectionalLight::SetIrriadiance(const float& iR, const float& iG, const float& iB)
  	{
	data->SetIrriadiance(iR, iG, iB);
	}

//*****************************************************************************

LPDIRECT3DTEXTURE9 CDirectionalLight::ShadowMap()
  	{
	return  data->ShadowMap();
	}

//*****************************************************************************

D3DXMATRIXA16 CDirectionalLight::ShadowTextureTransform() const
	{
	return data->ShadowTextureTransform();
	}

//*****************************************************************************

void CDirectionalLight::SetShadowMapSettings(const CShadowSettings_DirectionalLight& iShadowMapSettings)
	{
	data->SetShadowMapSettings(iShadowMapSettings);
	}

//*****************************************************************************

CShadowSettings_DirectionalLight CDirectionalLight::ShadowMapSettings() const
	{
	return data->ShadowMapSettings();
	}

//*****************************************************************************


