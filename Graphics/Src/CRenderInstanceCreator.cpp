///////////////////////////////////////////////////////////
//  CRenderInstanceCreator.cpp
//  Created on:      20-11-2009
//  Last modified:   20-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CRenderInstanceCreator.h>
using namespace Regina;


//*****************************************************************************

CRenderInstanceCreator* CRenderInstanceCreator::Instance()
	{
	static CRenderInstanceCreator riManager;
	return &riManager;
	}

//*****************************************************************************

CRenderInstanceCreator::CRenderInstanceCreator() : renderInstanceCreator(NULL)
	{
	}

//*****************************************************************************

CRenderInstanceCreator::~CRenderInstanceCreator()
	{
	if(renderInstanceCreator!=NULL)
		delete renderInstanceCreator;
	renderInstanceCreator = NULL;
	}

//*****************************************************************************

void CRenderInstanceCreator::Init(CRenderInstanceCreator_Base* iRenderInstanceCreator)
	{
	if(iRenderInstanceCreator == NULL)
		throw invalid_argument("CRenderInstanceCreator::Init - argument iRenderInstanceCreator == NULL");

	renderInstanceCreator=iRenderInstanceCreator;
	}

//*****************************************************************************

CRenderInstance_SimpleMesh* CRenderInstanceCreator::CreateInstance_SimpleMesh(const eRenderInstanceType& iRenderInstanceType, LPDIRECT3DDEVICE9 iDevice, LPD3DXMESH iMesh)
	{
	if(renderInstanceCreator == NULL)
		throw logic_error("CRenderInstanceCreator::CreateInstance_SimpleMesh - render instance creator is not initiated, call Init(...) first");

	return renderInstanceCreator->CreateInstance_SimpleMesh(iRenderInstanceType, iDevice, iMesh);

	/*switch(iRenderInstanceType)
		{
		case RenderInstanceType_AmbientColor_DiffuseColor_SpecularColor:	return new CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor(iDevice, iMesh);
																			break;

		default:															return NULL;
		}*/
	}

//*****************************************************************************
