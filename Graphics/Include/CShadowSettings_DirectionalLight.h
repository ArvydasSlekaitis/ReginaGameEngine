///////////////////////////////////////////////////////////
//  CShadowSettings_DirectionalLight.cpp
//  Created on:      13-11-2009
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_CSHADOWSETTINGS_DIRECTIONALLIGHT_H
#define REGINA_CSHADOWSETTINGS_DIRECTIONALLIGHT_H

#include <d3dx9.h>

#include <CShadowSettings.h>

namespace Regina
{

class CShadowSettings_DirectionalLight : public CShadowSettings
{
	D3DXVECTOR3		position;
	D3DXVECTOR3		direction;
	float			nearClip;
	float			farClip;
	D3DXMATRIX		view;
	D3DXMATRIX		proj;

	void CalculateViewTransform();
	void CalculateProjTransform();

public:
	CShadowSettings_DirectionalLight(const unsigned& iSize, const unsigned& iBitDepth, const float& iDepthBiass, const float& iBiassSlope, const D3DXVECTOR3& iPosition, const D3DXVECTOR3& iDirection, const float& iNearClip, const float& iFarClip, const D3DFORMAT& iRenderTargetFormat, const D3DFORMAT& iDepthBufferFormat);
	CShadowSettings_DirectionalLight();

	D3DXVECTOR3 Position() 	const { return position; }
	D3DXVECTOR3	Direction() const { return direction; }
	float		NearClip()	const {	return nearClip; }
	float		FarClip()	const { return farClip; }

	D3DXMATRIX	ViewTransform() const { return view; }
	D3DXMATRIX	ProjTransform() const { return proj; }
	D3DXMATRIX  ShadowTextureTransform() const { return (view*proj)*ShadowScaleTransform(); }


	void SetPosition(const D3DXVECTOR3& iPosition);
	void SetDirection(const D3DXVECTOR3& iDirection);
	void SetNearClip(const float& iNearClip);
	void SetFarClip(const float& iFarClip);
	};

}

#endif
