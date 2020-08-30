///////////////////////////////////////////////////////////
//  CShadowMap.cpp
//  Created on:      14-11-2009
//  Last modified:   14-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CShadowMap.h>
using namespace Regina;


//*****************************************************************************

CShadowMap::~CShadowMap()
	{
	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

CShadowMap::CShadowMap(LPDIRECT3DDEVICE9 iDevice) : device(NULL)
	{
	if(iDevice == NULL)
		throw invalid_argument("CShadowMap::CShadowMap - argument iDevice == NULL");

	device = iDevice;
	device->AddRef();
	}

//*****************************************************************************