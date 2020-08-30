///////////////////////////////////////////////////////////
//  CDeviceSettingsSave.h
//  Created on:      13-11-2009
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CDEVICESETTINGSSAVE_H
#define REGINA_CDEVICESETTINGSSAVE_H

#include <exception>
#include <stdexcept>
#include <assert.h>
using namespace std;

#include <d3dx9.h>

namespace Regina
{


class CDeviceSettingsSave
{
	LPDIRECT3DDEVICE9	device;
	D3DVIEWPORT9		prievousViewport;
	DWORD				prievousDepthBiass;
	DWORD				prievousBiassSlope;
	LPDIRECT3DSURFACE9	prievousColorSurface;
	LPDIRECT3DSURFACE9	prievousZSurface;
	D3DXMATRIXA16		prievousView;
	D3DXMATRIXA16		prievousProj;
	bool				saved;
public:
	virtual ~CDeviceSettingsSave();

	CDeviceSettingsSave();
	void Save(LPDIRECT3DDEVICE9 iDevice);
	void Restore();

};

}

#endif 