///////////////////////////////////////////////////////////
//  CDirectionalLight_Data.h
//  Created on:      04-09-2008
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CDIRECTIONALLIGHT_DATA_H
#define REGINA_CDIRECTIONALLIGHT_DATA_H

#include <CShadowSettings_DirectionalLight.h>
#include <CShadowMap_DirectionalLight.h>
#include <CLight.h>

namespace Regina
{


class CDirectionalLight_Data : public CLight
{
	CShadowMap_DirectionalLight shadowMap;

protected:

public:
	virtual ~CDirectionalLight_Data();

	CDirectionalLight_Data(LPDIRECT3DDEVICE9 iDevice, const string& iName, const D3DXVECTOR3& iDirection, const D3DXVECTOR3& iIrriadiance, const CShadowSettings_DirectionalLight& iShadowMapSettings);
	void SetShadowMapSettings(const CShadowSettings_DirectionalLight& iShadowMapSettings);

	virtual void CreateShadowMap();
	virtual bool Intersect(const D3DXVECTOR3& iPosition, const float& iRadius) const;

	void SetDirection(const D3DXVECTOR3& iDirection);

	D3DXVECTOR3		Direction()				const;
	D3DXMATRIXA16	ShadowTextureTransform()const;

	LPDIRECT3DTEXTURE9 ShadowMap();
	CShadowSettings_DirectionalLight ShadowMapSettings() const;

	void OnLostDevice();
	void OnResetDevice();

};

}

#endif 