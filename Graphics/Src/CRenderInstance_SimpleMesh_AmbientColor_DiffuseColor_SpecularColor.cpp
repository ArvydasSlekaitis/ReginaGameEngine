///////////////////////////////////////////////////////////
//  CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor.cpp
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor.h>
using namespace Regina;


//*****************************************************************************

CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::~CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor()
	{
	}

//*****************************************************************************

CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor(LPDIRECT3DDEVICE9 iDevice, LPD3DXMESH iMesh) : CRenderInstance_SimpleMesh(iDevice, matterialType, renderInstanceType, effectName, iMesh, instanceVertexElement, instanceDataSize)
  	{
	}

//*****************************************************************************

void CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::SetEffectParams(LPD3DXEFFECT& ioEffect, const vector<CRenderObject_SimpleMesh>& iRenderList)
	{
	ioEffect->SetMatrix( "ViewProjectionXf", &(CameraView()*CameraProj()));
	ioEffect->SetVector( "pv", &D3DXVECTOR4(CameraPosition().x, CameraPosition().y, CameraPosition().z, 1));


	if(RenderType() == Regina::RenderType_Default )
		{

		vector<CDirectionalLight> directionalLight;

		LightingManager->GetDirectionalLights(directionalLight, InstanceCenter(), InstanceRadius());

		if(directionalLight.size()==0)
			{
			ioEffect->SetTechnique("Instance_AmbientOnly");

			assert(iRenderList.size() > 0 && L"CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::SetEffectParams - iRenderList.size() > 0");
    		CMatterial matterial = iRenderList[0].Matterial();

			D3DXVECTOR3 ambientColor;
			matterial.GetProperty("ambientColor", ambientColor);
			ioEffect->SetVector( "Ka", &D3DXVECTOR4(ambientColor.x, ambientColor.y, ambientColor.z,0));

			D3DXVECTOR3 globalAmbientColor = LightingManager->GlobalAmbientColor();
			ioEffect->SetVector( "ambientColor", &D3DXVECTOR4(globalAmbientColor.x, globalAmbientColor.y, globalAmbientColor.z,0));

			return;
			}

	
/*
		ioEffect->SetTechnique("Instance_DirectionalLighting");
			

		assert(iRenderList.size() > 0 && L"CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::SetEffectParams - iRenderList.size() > 0");

		CMatterial matterial = iRenderList[0].Matterial();

		D3DXVECTOR3 ambientColor;
		D3DXVECTOR3 diffuseColor;
		D3DXVECTOR3 specularColor;
		float		surfaceSmoothness; // m

		matterial.GetProperty("ambientColor", ambientColor);
		matterial.GetProperty("diffuseColor", diffuseColor);
		matterial.GetProperty("specularColor", specularColor);
		matterial.GetProperty("surfaceSmoothness", surfaceSmoothness);

		D3DXVECTOR3 Kd = diffuseColor / D3DX_PI;
		D3DXVECTOR3 Ks = ((surfaceSmoothness + 8) / (8*D3DX_PI))*specularColor;
		
		ioEffect->SetVector( "Kd", &D3DXVECTOR4(Kd.x, Kd.y, Kd.z,0));
		ioEffect->SetVector( "Ks", &D3DXVECTOR4(Ks.x, Ks.y, Ks.z,0));
		ioEffect->SetFloat( "m", surfaceSmoothness);

		//Apply Directional Lights
		
		for(unsigned i=0; i<directionalLight.size(); i++)
			{
			//Apply Direction
				{
				ostringstream dldir;
				dldir << "directional_l[" << i << "]";
				ioEffect->SetVector(dldir.str().c_str(), &D3DXVECTOR4(-directionalLight[i].Direction().x, -directionalLight[i].Direction().y, -directionalLight[i].Direction().z, 0));
				}

			//Apply Irradiance
				{
				ostringstream dlir;
				dlir << "directional_El[" << i << "]";
				ioEffect->SetVector(dlir.str().c_str(), &D3DXVECTOR4(directionalLight[i].Irriadiance().x, directionalLight[i].Irriadiance().y, directionalLight[i].Irriadiance().z, 0));
				}

			//Apply Shadow Map
				{
				ostringstream dlshmap;
				dlshmap << "directional_ShadowMap_" << i;
				ioEffect->SetTexture(dlshmap.str().c_str(), directionalLight[i].ShadowMap());
				}

			//Apply Shadow Map Transform
				{
				ostringstream dlshmap;
				dlshmap << "directional_ShadowTransform[" << i << "]";
				ioEffect->SetMatrix(dlshmap.str().c_str(), &directionalLight[i].ShadowTextureTransform());
				}

			}

		//Set directional lights count
		ioEffect->SetInt("directional_NumDirectional", directionalLight.size());
*/


		return;
		}

	else

	if(RenderType() == Regina::RenderType_Shadow )
		{
		ioEffect->SetTechnique("Instance_Shadow");
		return;
		}

	else
		{
		throw invalid_argument("CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::SetEffectParams - RenderType is invalid");
		}
	}

//*****************************************************************************

void CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::FillInstanceVB(LPDIRECT3DVERTEXBUFFER9& ioVertexBuffer, const vector<CRenderObject_SimpleMesh>& iRenderList)
	{
	MATRIX_V4_V4_V4* pVertices;
	ioVertexBuffer->Lock(0, 0, (VOID**)&pVertices, 0);
	
	for(int i=0; i<iRenderList.size(); i++)
		{
		D3DXMATRIXA16 matrix(iRenderList[i].Transformation());

		D3DXMATRIXA16 matrixInverse;

		D3DXMATRIXA16 matTemp;
		D3DXMatrixIdentity( &matTemp );
		D3DXMatrixInverse( &matTemp, NULL, &matrix );
		D3DXMatrixTranspose( &matrixInverse, &matTemp );

		pVertices[i].r1=D3DXVECTOR4(matrix._11, matrix._21, matrix._31, matrix._41);
		pVertices[i].r2=D3DXVECTOR4(matrix._12, matrix._22, matrix._32, matrix._42);
		pVertices[i].r3=D3DXVECTOR4(matrix._13, matrix._23, matrix._33, matrix._43);
		pVertices[i].r4=D3DXVECTOR4(matrixInverse._11, matrixInverse._12, matrixInverse._13, matrixInverse._14);
		pVertices[i].r5=D3DXVECTOR4(matrixInverse._21, matrixInverse._22, matrixInverse._23, matrixInverse._24);
		pVertices[i].r6=D3DXVECTOR4(matrixInverse._31, matrixInverse._32, matrixInverse._33, matrixInverse._34);
		pVertices[i].r7=D3DXVECTOR4(matrixInverse._41, matrixInverse._42, matrixInverse._43, matrixInverse._44);
		}
	ioVertexBuffer->Unlock();
	}

//*****************************************************************************

const eMatterialType		CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::matterialType(MatterialType_AmbientColor_DiffuseColor_SpecularColor);
const eRenderInstanceType	CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::renderInstanceType(RenderInstanceType_AmbientColor_DiffuseColor_SpecularColor);
const string				CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::effectName("SimpleMesh_Instance_AmbientColor_DiffuseColor_SpecularColor");
const unsigned				CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::instanceDataSize = sizeof(MATRIX_V4_V4_V4);
D3DVERTEXELEMENT9*			CRenderInstance_SimpleMesh_AmbientColor_DiffuseColor_SpecularColor::instanceVertexElement(VE_MESH_POS_NORM_BINORM_TAN_UV_INSTANCE_WORLD);

//*****************************************************************************