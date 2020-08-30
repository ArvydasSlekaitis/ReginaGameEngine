///////////////////////////////////////////////////////////
//  CDeviceSettingsSave.cpp
//  Created on:      13-11-2009
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CDeviceSettingsSave.h>
using namespace Regina;


//*****************************************************************************

CDeviceSettingsSave::~CDeviceSettingsSave()
	{
	if(saved == true)
		{
		assert(device!=NULL && L"CDeviceSettingsSave::~CDeviceSettingsSave - device == NULL");
	
		device->Release();
		device = NULL;

		prievousColorSurface->Release();
		prievousColorSurface = NULL;

		prievousZSurface->Release();
		prievousZSurface = NULL;

		saved = false;
		}
	}

//*****************************************************************************

CDeviceSettingsSave::CDeviceSettingsSave() : device(NULL), prievousDepthBiass(0), prievousBiassSlope(0), prievousColorSurface(NULL), prievousZSurface(NULL), saved(false)
  	{
		
	}

//*****************************************************************************

void CDeviceSettingsSave::Save(LPDIRECT3DDEVICE9 iDevice)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CDeviceSettingsSave::Save - argument iDevice == NULL");

	if(saved == true)
		{
		device->Release();
		device = NULL;
		saved = false;
		}

	device = iDevice;
	device->AddRef();

	device->GetViewport(&prievousViewport);
	device->GetRenderState(D3DRS_DEPTHBIAS, &prievousDepthBiass);
	device->GetRenderState(D3DRS_SLOPESCALEDEPTHBIAS, &prievousBiassSlope);
	device->GetTransform(D3DTS_VIEW, &prievousView);
	device->GetTransform(D3DTS_PROJECTION, &prievousProj);
	device->GetRenderTarget( 0, &prievousColorSurface);
	device->GetDepthStencilSurface(&prievousZSurface);
	

	saved = true;
	}

//*****************************************************************************

void CDeviceSettingsSave::Restore()
  	{
	if(saved == true)
		{
		device->SetViewport(&prievousViewport);
		device->SetRenderState(D3DRS_DEPTHBIAS, prievousDepthBiass);
		device->SetRenderState(D3DRS_SLOPESCALEDEPTHBIAS, prievousBiassSlope);
		device->SetTransform(D3DTS_VIEW, &prievousView);
		device->SetTransform(D3DTS_PROJECTION, &prievousProj);
		device->SetRenderTarget( 0, prievousColorSurface);
		device->SetDepthStencilSurface(prievousZSurface);

		prievousColorSurface->Release();
		prievousColorSurface = NULL;

		prievousZSurface->Release();
		prievousZSurface = NULL;

		device->Release();
		device = NULL;

		saved = false;
		}
	}

//*****************************************************************************