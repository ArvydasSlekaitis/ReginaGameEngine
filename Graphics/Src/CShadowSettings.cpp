///////////////////////////////////////////////////////////
//  CShadowSettings.cpp
//  Created on:      01-09-2008
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <CShadowSettings.h>
using namespace Regina;


//*****************************************************************************

CShadowSettings::CShadowSettings(const unsigned& iSize, const unsigned& iBitDepth, const float& iDepthBiass, const float& iBiassSlope, const D3DFORMAT& iRenderTargetFormat, const D3DFORMAT& iDepthBufferFormat) : size(iSize), bitDepth(iBitDepth), depthBiass(iDepthBiass), biassSlope(iBiassSlope), renderTargetFormat(iRenderTargetFormat), depthBufferFormat(iDepthBufferFormat)
	{
	CalculateShadowScaleTransform();
	}

//*****************************************************************************

void CShadowSettings::CalculateShadowScaleTransform()
	{
	float offset = 0.5f + 0.5f/((float)size);

	D3DXMATRIXA16 shadowTT(0.5,		0,		 0,		 0,
						   0,	 -0.5,	 	 0, 	 0,
						   0,		0,		 1,		 0,
						   offset,	offset,  depthBiass,      1);

	shadowScaleTransform = shadowTT;
	}

//*****************************************************************************

D3DVIEWPORT9 CShadowSettings::Viewport() const 
	{
	D3DVIEWPORT9 viewport;
	viewport.X=0;
	viewport.Y=0;
	viewport.Width = size;             
	viewport.Height = size;
	viewport.MinZ = 0;
	viewport.MaxZ = 1;
	return viewport;
	}

//*****************************************************************************

void CShadowSettings::SetDepthBiass(const float& iDepthBiass)
	{ 
	depthBiass = iDepthBiass; 
	CalculateShadowScaleTransform(); 
	}

//*****************************************************************************

void CShadowSettings::SetBiassSlope(const float& iBiassSlope)
	{ 
	biassSlope = iBiassSlope; 
	CalculateShadowScaleTransform(); 
	}

//*****************************************************************************

void CShadowSettings::SetSize(const unsigned& iSize)	
	{ 
	size = iSize; 
	CalculateShadowScaleTransform(); 
	}

//*****************************************************************************

void CShadowSettings::SetBitDepth(const unsigned& iBitDepth)	
	{ 
	bitDepth = iBitDepth; 
	}

//*****************************************************************************

void CShadowSettings::SetRenderTargetFormat(const D3DFORMAT& iRenderTargetFormat)
	{ 
	renderTargetFormat = iRenderTargetFormat; 
	}

//*****************************************************************************

void CShadowSettings::SetDepthBufferFormat(const D3DFORMAT& iDepthBufferFormat)	
	{ 
	depthBufferFormat = iDepthBufferFormat; 
	}

//*****************************************************************************
