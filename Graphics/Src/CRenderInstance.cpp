///////////////////////////////////////////////////////////
//  CRenderInstance.cpp
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CRenderInstance.h>
using namespace Regina;


//*****************************************************************************

CRenderInstance::~CRenderInstance()
	{
	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

CRenderInstance::CRenderInstance(LPDIRECT3DDEVICE9 iDevice, const eMatterialType& iMatterialType, const eRenderInstanceType& iRenderInstanceType) : matterialType(iMatterialType), renderInstanceType(iRenderInstanceType), matterialID(0), modified(false)
  	{
	if(iDevice == NULL)
		throw invalid_argument("CRenderInstance::CRenderInstance - argument iDevice==NULL");

	device = iDevice;
	device->AddRef();
	}

//*****************************************************************************

