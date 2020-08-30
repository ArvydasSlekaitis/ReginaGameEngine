///////////////////////////////////////////////////////////
//  MeshDefinitions.h
//  Created on:      04-11-2009
//  Last modified:   04-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_MESHDEFINITIONS_H
#define REGINA_MESHDEFINITIONS_H

#include <d3dx9.h>

namespace Regina
	{

//****************************************************************************************
//This is standart for Regina Engine
//****************************************************************************************

static D3DVERTEXELEMENT9 VE_POS_NORM_BINORM_TAN_UV[] =
	{
		{ 0,  0,  D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_POSITION, 0},
		{ 0,  12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_NORMAL, 0},
		{ 0,  24, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_BINORMAL, 0},
		{ 0,  36, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TANGENT, 0},
		{ 0,  48, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TEXCOORD, 0},
		D3DDECL_END()
	};

//****************************************************************************************
//World + WorldInverse
//****************************************************************************************

static D3DVERTEXELEMENT9 VE_MESH_POS_NORM_BINORM_TAN_UV_INSTANCE_WORLD[] =
	{
		{ 0,  0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_POSITION, 0},
		{ 0,  12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_NORMAL, 0},
		{ 0,  24, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_BINORMAL, 0},
		{ 0,  36, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TANGENT, 0},
		{ 0,  48, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TEXCOORD, 0},
		{ 1,  0, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TEXCOORD, 1},
		{ 1,  16, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TEXCOORD, 2},
		{ 1,  32, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TEXCOORD, 3},
		{ 1,  48, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TEXCOORD, 4},
		{ 1,  64, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TEXCOORD, 5},
		{ 1,  80, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TEXCOORD, 6},
		{ 1,  96, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT,  D3DDECLUSAGE_TEXCOORD, 7},
		D3DDECL_END()
	};

//****************************************************************************************
//Structures
//****************************************************************************************
	   
struct MATRIX_V4_V4_V4
{
	D3DXVECTOR4 r1;
	D3DXVECTOR4 r2;
	D3DXVECTOR4 r3;

	D3DXVECTOR4 r4;
	D3DXVECTOR4 r5;
	D3DXVECTOR4 r6;
	D3DXVECTOR4 r7;

};

};

#endif

	

