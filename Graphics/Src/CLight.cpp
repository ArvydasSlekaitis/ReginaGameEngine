///////////////////////////////////////////////////////////
//  CLight.cpp
//  Created on:      13-11-2009
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CLight.h>
using namespace Regina;


//*****************************************************************************

CLight::~CLight()
	{
	if(device!=NULL)
		device->Release();
	device = NULL;

	if(shadowScene!=NULL)
		delete shadowScene;
	shadowScene=NULL;
	}

//*****************************************************************************

CLight::CLight(LPDIRECT3DDEVICE9 iDevice, const string& iName, const D3DXVECTOR3& iIrriadiance) : device(NULL), name(iName), irriadiance(iIrriadiance), enabled(true), shadowCastingEnabled(true), shadowScene(NULL)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CLight::CLight - argument iDevice == NULL");

	device = iDevice;
	device->AddRef();

	shadowScene = new CScene(iDevice);
	assert(shadowScene!=NULL && L"CLight::CLight - cannot create new CScene");
	}

//*****************************************************************************

void CLight::RenderShadowCasters(const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition)
  	{
	shadowScene->Render(Regina::RenderType_Shadow, iCameraView, iCameraProj, iCameraPosition);
	}

//*****************************************************************************

string CLight::Name() const 
  	{
	return name;
	}

//*****************************************************************************

bool CLight::Enabled() const 
  	{
	return enabled;
	}

//*****************************************************************************

bool CLight::ShadowCastingEnabled() const 
  	{
	return shadowCastingEnabled;
	}

//*****************************************************************************

D3DXVECTOR3 CLight::Irriadiance() const 
  	{
	return  irriadiance;
	}

//*****************************************************************************

void CLight::ClearShadowCasters()
  	{
	ClearStaticShadowCasters();
	ClearDynamicShadowCasters();
	}

//*****************************************************************************

void CLight::ClearStaticShadowCasters()
	{
	shadowScene->ClearStatic();
	}

//*****************************************************************************

void CLight::ClearDynamicShadowCasters()
	{
	shadowScene->ClearDynamic();
	}

//*****************************************************************************

void CLight::AddShadowCaster(CRenderObject_SimpleMesh& iSimpleMesh)
  	{
	shadowScene->AddRenderObject(iSimpleMesh);
	}

//*****************************************************************************

void CLight::Enable()
  	{
	enabled = true;
	}

//*****************************************************************************

void CLight::Disable()
  	{
	enabled = false;
	}

//*****************************************************************************

void CLight::EnableShadowCasting()
  	{
	shadowCastingEnabled = true;
	}

//*****************************************************************************

void CLight::DisableShadowCasting()
  	{
	shadowCastingEnabled = false;
	}

//*****************************************************************************

void CLight::SetIrriadiance(const float& iR, const float& iG, const float& iB)
  	{
	irriadiance.x = iR;
	irriadiance.y = iG;
	irriadiance.z = iB;
	}

//*****************************************************************************

void CLight::OnLostDevice()
	{
	shadowScene->OnLostDevice();
	}

//*****************************************************************************

void CLight::OnResetDevice()
	{
	shadowScene->OnResetDevice();
	}

//*****************************************************************************