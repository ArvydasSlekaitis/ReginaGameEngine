///////////////////////////////////////////////////////////
//  CDirectionalLight.h
//  Created on:      27-11-2009
//  Last modified:   27-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CDIRECTIONALLIGHT_H
#define REGINA_CDIRECTIONALLIGHT_H

#include <CDirectionalLight_Data.h>

namespace Regina
{


class CDirectionalLight
{
	CDirectionalLight_Data* data;

public:
	virtual ~CDirectionalLight();

	CDirectionalLight(CDirectionalLight_Data* iData);
	CDirectionalLight(const CDirectionalLight& iDirectionalLight);

	D3DXVECTOR3		Direction()				const;
	string			Name()					const;
	bool			Enabled()				const;
	bool			ShadowCastingEnabled()	const;
	D3DXVECTOR3		Irriadiance()			const;
	D3DXMATRIXA16	ShadowTextureTransform()const;

	LPDIRECT3DTEXTURE9 ShadowMap();
	CShadowSettings_DirectionalLight ShadowMapSettings() const;

	void Enable();
	void Disable();
	void EnableShadowCasting();
	void DisableShadowCasting();
	void SetDirection(const D3DXVECTOR3& iDirection);
	void SetIrriadiance(const float& iR, const float& iG, const float& iB);
	void SetShadowMapSettings(const CShadowSettings_DirectionalLight& iShadowMapSettings);
};

}

#endif 