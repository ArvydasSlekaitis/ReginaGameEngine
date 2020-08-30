///////////////////////////////////////////////////////////
//  CLight.h
//  Created on:      13-11-2009
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CLIGHT_H
#define REGINA_CLIGHT_H

#include <CDeviceSettingsSave.h>
#include <CRenderObject_SimpleMesh.h>
#include <CScene.h>

namespace Regina
{


class CLight
{
	string				name;
	bool				enabled;
	bool				shadowCastingEnabled;
	D3DXVECTOR3			irriadiance;

	CScene*				shadowScene;

protected:
	LPDIRECT3DDEVICE9	device;

	void RenderShadowCasters(const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition);

public:
	virtual ~CLight();

	CLight(LPDIRECT3DDEVICE9 iDevice, const string& iName, const D3DXVECTOR3& iIrriadiance);
		
	void ClearShadowCasters();
	void ClearStaticShadowCasters();
	void ClearDynamicShadowCasters();
	void AddShadowCaster(CRenderObject_SimpleMesh& iSimpleMesh);
	
	string		Name()					const;
	bool		Enabled()				const;
	bool		ShadowCastingEnabled()	const;
	D3DXVECTOR3 Irriadiance()			const;

	void Enable();
	void Disable();
	void EnableShadowCasting();
	void DisableShadowCasting();
	void SetIrriadiance(const float& iR, const float& iG, const float& iB);

	virtual void CreateShadowMap() =0;
	virtual bool Intersect(const D3DXVECTOR3& iPosition, const float& iRadius) const =0;
	virtual void OnLostDevice();
	virtual void OnResetDevice();

};

}

#endif 