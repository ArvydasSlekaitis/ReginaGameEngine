///////////////////////////////////////////////////////////
//  CRenderInstanceCreator_Default.cpp
//  Created on:      28-11-2009
//  Last modified:   28-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CRenderInstanceCreator_Default.h>
using namespace Regina;


//*****************************************************************************

CRenderInstance_SimpleMesh* CRenderInstanceCreator_Default::CreateInstance_SimpleMesh(const eRenderInstanceType& iRenderInstanceType, LPDIRECT3DDEVICE9 iDevice, LPD3DXMESH iMesh)
	{
	switch(iRenderInstanceType)
		{
		case RenderInstanceType_AmbientColor_DiffuseColor_SpecularColor:	return new CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor(iDevice, iMesh);
																			break;

		case RenderInstanceType_AmbientMap_DiffuseMap_SpecularColor:		return new CRenderInstance_SimpleMesh_AmbientMap_DiffuseMap_SpecularColor(iDevice, iMesh);
																			break;

		case RenderInstanceType_Alpha_AmbientMap_DiffuseMap_SpecularColor:	return new CRenderInstance_SimpleMesh_Alpha_AmbientMap_DiffuseMap_SpecularColor(iDevice, iMesh);
																			break;

		default:															return NULL;
		}
	}

//*****************************************************************************
