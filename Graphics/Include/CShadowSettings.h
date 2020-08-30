///////////////////////////////////////////////////////////
//  CShadowSettings.h
//  Created on:      01-09-2008
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_CSHADOWSETTINGS_H
#define REGINA_CSHADOWSETTINGS_H

#include <d3dx9.h>

namespace Regina
{


class CShadowSettings
{
unsigned 		size;
unsigned 		bitDepth;
float	 		depthBiass;
float			biassSlope;
D3DFORMAT		renderTargetFormat;
D3DFORMAT		depthBufferFormat;
D3DXMATRIX		shadowScaleTransform;

void CalculateShadowScaleTransform();

public:
CShadowSettings(const unsigned& iSize, const unsigned& iBitDepth, const float& iDepthBiass, const float& iBiassSlope, const D3DFORMAT& iRenderTargetFormat, const D3DFORMAT& iDepthBufferFormat);

unsigned	Size() 					const { return size; }
unsigned 	BitDepth() 				const { return bitDepth; }
float		DepthBiass()			const {	return depthBiass; }
float		BiassSlope()			const { return biassSlope; }
D3DFORMAT	RenderTargetFormat()	const { return renderTargetFormat; }
D3DFORMAT	DepthBufferFormat()		const { return depthBufferFormat; }

D3DXMATRIX	ShadowScaleTransform()	const { return shadowScaleTransform; }
D3DVIEWPORT9  Viewport()				const;

void SetDepthBiass(const float& iDepthBiass);
void SetBiassSlope(const float& iBiassSlope);
void SetSize(const unsigned& iSize);
void SetBitDepth(const unsigned& iBitDepth);
void SetRenderTargetFormat(const D3DFORMAT& iRenderTargetFormat);
void SetDepthBufferFormat(const D3DFORMAT& iDepthBufferFormat);
};

}

#endif
