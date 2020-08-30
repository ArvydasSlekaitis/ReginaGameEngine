///////////////////////////////////////////////////////////
//  CShadowSettings_DirectionalLight.cpp
//  Created on:      13-11-2009
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <CShadowSettings_DirectionalLight.h>
using namespace Regina;


//*****************************************************************************

CShadowSettings_DirectionalLight::CShadowSettings_DirectionalLight(const unsigned& iSize, const unsigned& iBitDepth, const float& iDepthBiass, const float& iBiassSlope, const D3DXVECTOR3& iPosition, const D3DXVECTOR3& iDirection, const float& iNearClip, const float& iFarClip, const D3DFORMAT& iRenderTargetFormat, const D3DFORMAT& iDepthBufferFormat) : CShadowSettings(iSize, iBitDepth, iDepthBiass, iBiassSlope, iRenderTargetFormat, iDepthBufferFormat), position(iPosition), direction(iDirection), nearClip(iNearClip), farClip(iFarClip)
	{
	D3DXVec3Normalize(&direction, &direction);
	CalculateViewTransform();
	CalculateProjTransform();
	}

//*****************************************************************************

CShadowSettings_DirectionalLight::CShadowSettings_DirectionalLight() : CShadowSettings(2048, 32, 0, 1, D3DFMT_A8R8G8B8, D3DFMT_D24S8), position(0, 0, 0), direction(1, 0, 0), nearClip(0.1), farClip(100)
	{
	CalculateViewTransform();
	CalculateProjTransform();
	}

//*****************************************************************************

void CShadowSettings_DirectionalLight::SetPosition(const D3DXVECTOR3& iPosition)
	{
	position = iPosition;
	CalculateViewTransform();
	}

//*****************************************************************************

void CShadowSettings_DirectionalLight::SetDirection(const D3DXVECTOR3& iDirection)
	{
	direction = iDirection;
	D3DXVec3Normalize(&direction, &direction);
	CalculateViewTransform();
	}

//*****************************************************************************

void CShadowSettings_DirectionalLight::SetNearClip(const float& iNearClip)
	{
	nearClip = iNearClip;
	CalculateProjTransform();
	}

//*****************************************************************************

void CShadowSettings_DirectionalLight::SetFarClip(const float& iFarClip)
	{
	farClip = iFarClip;
	CalculateProjTransform();
	}

//*****************************************************************************

void CShadowSettings_DirectionalLight::CalculateViewTransform()
	{
	D3DXVECTOR3 lookAt = position + direction*10;
	D3DXMatrixLookAtLH( &view, &position, &lookAt, &D3DXVECTOR3( 0.0f, 1.0f, 0.0f ) );
	}

//*****************************************************************************

void CShadowSettings_DirectionalLight::CalculateProjTransform()
	{
	D3DXMatrixPerspectiveFovLH( &proj, D3DX_PI/2, 1, nearClip, farClip);
	}

//*****************************************************************************

