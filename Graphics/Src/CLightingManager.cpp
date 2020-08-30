///////////////////////////////////////////////////////////
//  CLightingManager.cpp
//  Created on:      27-11-2009
//  Last modified:   27-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CLightingManager.h>
using namespace Regina;


//*****************************************************************************

CLightingManager::~CLightingManager()
	{
	Clear();
	}

//*****************************************************************************

CLightingManager::CLightingManager() : device(NULL), globalAmbientColor(D3DXVECTOR3(0, 0, 0))
  	{
	}

//*****************************************************************************

CLightingManager* CLightingManager::Instance()
  	{
	static CLightingManager lManager;
	return &lManager;
	}

//*****************************************************************************

void CLightingManager::Init(LPDIRECT3DDEVICE9 iDevice)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CLightingManager::Init - argument iDevice == NULL");

	if(device!=NULL)
		device->Release();
	
	device = iDevice;
	device->AddRef();
	}

//*****************************************************************************

void CLightingManager::CreateShadowMaps()
  	{
	for(unsigned i=0; i<directionalLight.size(); i++)
		{
		directionalLight[i]->CreateShadowMap();
		directionalLight[i]->ClearDynamicShadowCasters();
		}
	}

//*****************************************************************************

void CLightingManager::AddDirectionalLight(const string& iName, const D3DXVECTOR3& iDirection, const D3DXVECTOR3& iColor, const CShadowSettings_DirectionalLight& iShadowMapSettings)
  	{
	if(device==NULL)
		throw logic_error("CLightingManager::AddDirectionalLight - device is not initiated. Call Init(...) before.");

	directionalLight.push_back(new CDirectionalLight_Data(device, iName, iDirection, iColor, iShadowMapSettings));
	}

//*****************************************************************************

void CLightingManager::AddShadowCaster(CRenderObject_SimpleMesh& iSimpleMesh)
  	{
	for(unsigned i=0; i<directionalLight.size(); i++)
		directionalLight[i]->AddShadowCaster(iSimpleMesh);
	}

//*****************************************************************************

void CLightingManager::RemoveLight(const string& iName)
  	{
	for(unsigned i=0; i<directionalLight.size(); i++)
		if(directionalLight[i]->Name()==iName)
			{
			delete directionalLight[i];
			directionalLight[i] = directionalLight[directionalLight.size()-1];
			directionalLight.pop_back();
			i--;
			}
	}

//*****************************************************************************

void CLightingManager::GetDirectionalLights(vector<CDirectionalLight>& oDirectionalLights, const D3DXVECTOR3& iPosition, const float& iRadius)
  	{
	for(unsigned i=0; i<directionalLight.size(); i++)
		if(directionalLight[i]->Intersect(iPosition, iRadius))
			oDirectionalLights.push_back(CDirectionalLight(directionalLight[i]));
	}

//*****************************************************************************

void CLightingManager::Clear()
	{
	if(device!=NULL)
		device->Release();
	device = NULL;

	for(unsigned i=0; i<directionalLight.size(); i++)
		delete directionalLight[i];
	directionalLight.clear();
	}

//*****************************************************************************

void CLightingManager::OnLostDevice()
	{
	for(unsigned i=0; i<directionalLight.size(); i++)
		directionalLight[i]->OnLostDevice();
	}

//*****************************************************************************

void CLightingManager::OnResetDevice()
	{
	for(unsigned i=0; i<directionalLight.size(); i++)
		directionalLight[i]->OnResetDevice();
	}

//*****************************************************************************
