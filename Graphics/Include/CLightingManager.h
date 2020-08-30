///////////////////////////////////////////////////////////
//  CLightingManager.h
//  Created on:      27-11-2009
//  Last modified:   27-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CLIGHTINGMANAGER_H
#define REGINA_CLIGHTINGMANAGER_H

#include <CDirectionalLight_Data.h>
#include <CDirectionalLight.h>

namespace Regina
{


class CLightingManager
{
	vector<CDirectionalLight_Data*> directionalLight;
	D3DXVECTOR3						globalAmbientColor;
	LPDIRECT3DDEVICE9	device;

private:
	CLightingManager();
	CLightingManager(CLightingManager& lightingManager) {}

public:
	virtual ~CLightingManager();

	static CLightingManager* Instance();

	void Init(LPDIRECT3DDEVICE9 iDevice);
	void CreateShadowMaps();
	void Clear();
	void OnLostDevice();
	void OnResetDevice();
	void AddDirectionalLight(const string& iName, const D3DXVECTOR3& iDirection, const D3DXVECTOR3& iIrradiance, const CShadowSettings_DirectionalLight& iShadowMapSettings);
	void AddShadowCaster(CRenderObject_SimpleMesh& iSimpleMesh);
	void RemoveLight(const string& iName);
	void GetDirectionalLights(vector<CDirectionalLight>& oDirectionalLights, const D3DXVECTOR3& iPosition, const float& iRadius);
	
	void SetGlobalAmbientColor(const D3DXVECTOR3& iGlobalAmbientColor) { globalAmbientColor = iGlobalAmbientColor; }
	
	CDirectionalLight GetDirectionalLight(const string& iName);
	D3DXVECTOR3 GlobalAmbientColor() const { return globalAmbientColor; }


};

#define LightingManager CLightingManager::Instance()

}

#endif