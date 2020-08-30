///////////////////////////////////////////////////////////
//  ObjectInstance_Templates.h
//  Created on:      09-10-2008
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef OBJECTINSTANCE_TEMPLATES_H
#define OBJECTINSTANCE_TEMPLATES_H

#include <ObjectInstance.h>
//#include <GlobalSettings.h>
//#include <LightHandler.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//T1-OBJECT, T3-MATRIX
template<class T1, class T2>
class CObjectInstance_World_UVOffset : public CObjectInstance
{
protected:
virtual void CreateBuffer();
virtual void SetEffectParams();

public:
CObjectInstance_World_UVOffset(CMesh* iMesh, LPD3DXMESH iWorkingMesh, D3DVERTEXELEMENT9* iVertexElementInstance);

virtual ~CObjectInstance_World_UVOffset() {}
};

//*****************************************************************************

template<class T1, class T2>
CObjectInstance_World_UVOffset<T1, T2>::CObjectInstance_World_UVOffset(CMesh* iMesh, LPD3DXMESH iWorkingMesh, D3DVERTEXELEMENT9* iVertexElementInstance) : CObjectInstance(iMesh, iWorkingMesh, iVertexElementInstance)
{

}

//*****************************************************************************

template<class T1, class T2>
void CObjectInstance_World_UVOffset<T1, T2>::CreateBuffer()
{
//Get cam position
D3DXMATRIXA16 view;
device->GetTransform(D3DTS_VIEW, &view);
D3DXMATRIXA16 inverseView;
D3DXMatrixInverse(&inverseView, NULL, &view);


//Create Buffer
device->CreateVertexBuffer( objects.size() * sizeof(T2), D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &vertexBuffer, NULL );

T2* pVertices;
vertexBuffer->Lock(0, 0, (VOID**)&pVertices, 0);
for(int i=0; i<objects.size(); i++)
{
float dist = D3DXVec3Length(&(D3DXVECTOR3(inverseView._41, inverseView._42, inverseView._43) - objects[i].second->Position()));


D3DXMATRIXA16 matrix(*objects[i].first);
pVertices[i].r1=D3DXVECTOR4(matrix._11, matrix._21, matrix._31, matrix._41);
pVertices[i].r2=D3DXVECTOR4(matrix._12, matrix._22, matrix._32, matrix._42);
pVertices[i].r3=D3DXVECTOR4(matrix._13, matrix._23, matrix._33, matrix._43);
pVertices[i].r4=((T1*)objects[i].second)->UVOffset();
}
vertexBuffer->Unlock();
}

//*****************************************************************************

template<class T1, class T2>
void CObjectInstance_World_UVOffset<T1, T2>::SetEffectParams()
{
LightHandler->UpdateEffectParams(effect);

D3DXMATRIXA16 view;
D3DXMATRIXA16 proj;

device->GetTransform(D3DTS_VIEW, &view);
device->GetTransform(D3DTS_PROJECTION, &proj);

effect->SetMatrix( "matVP", &(view*proj));
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//T1-MATRIX
template<class T1>
class CObjectInstance_World_InverseWorld : public CObjectInstance
{
protected:
virtual void CreateBuffer();
virtual void SetEffectParams();

public:
CObjectInstance_World_InverseWorld(CMesh* iMesh, LPD3DXMESH iWorkingMesh, D3DVERTEXELEMENT9* iVertexElementInstance);

virtual ~CObjectInstance_World_InverseWorld() {}
};

//*****************************************************************************

template<class T1>
CObjectInstance_World_InverseWorld<T1>::CObjectInstance_World_InverseWorld(CMesh* iMesh, LPD3DXMESH iWorkingMesh, D3DVERTEXELEMENT9* iVertexElementInstance) : CObjectInstance(iMesh, iWorkingMesh, iVertexElementInstance)
{

}

//*****************************************************************************

template<class T1>
void CObjectInstance_World_InverseWorld<T1>::CreateBuffer()
{
//Get cam position
D3DXMATRIXA16 view;
device->GetTransform(D3DTS_VIEW, &view);
D3DXMATRIXA16 inverseView;
D3DXMatrixInverse(&inverseView, NULL, &view);


//Create Buffer
device->CreateVertexBuffer( objects.size() * sizeof(T1), D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &vertexBuffer, NULL );

T1* pVertices;
vertexBuffer->Lock(0, 0, (VOID**)&pVertices, 0);
for(int i=0; i<objects.size(); i++)
{
float dist = D3DXVec3Length(&(D3DXVECTOR3(inverseView._41, inverseView._42, inverseView._43) - objects[i].second->Position()));


D3DXMATRIXA16 matrix(*objects[i].first);
D3DXMATRIXA16 matrixInverse;
D3DXMATRIXA16 matrixTranspose;

D3DXMATRIXA16 matTemp;
 D3DXMatrixIdentity( &matTemp );
 D3DXMatrixInverse( &matTemp, NULL, &(*objects[i].first) );
 D3DXMatrixTranspose( &matrixInverse, &matTemp );

pVertices[i].r1=D3DXVECTOR4(matrix._11, matrix._21, matrix._31, matrix._41);
pVertices[i].r2=D3DXVECTOR4(matrix._12, matrix._22, matrix._32, matrix._42);
pVertices[i].r3=D3DXVECTOR4(matrix._13, matrix._23, matrix._33, matrix._43);
pVertices[i].r4=D3DXVECTOR4(matrixInverse._11, matrixInverse._12, matrixInverse._13, matrixInverse._14);
pVertices[i].r5=D3DXVECTOR4(matrixInverse._21, matrixInverse._22, matrixInverse._23, matrixInverse._24);
pVertices[i].r6=D3DXVECTOR4(matrixInverse._31, matrixInverse._32, matrixInverse._33, matrixInverse._34);
pVertices[i].r7=D3DXVECTOR4(matrixInverse._41, matrixInverse._42, matrixInverse._43, matrixInverse._44);
}
vertexBuffer->Unlock();
}

//*****************************************************************************

template<class T1>
void CObjectInstance_World_InverseWorld<T1>::SetEffectParams()
{
LightHandler->UpdateEffectParams(effect);

D3DXMATRIXA16 view;
D3DXMATRIXA16 proj;

device->GetTransform(D3DTS_VIEW, &view);
device->GetTransform(D3DTS_PROJECTION, &proj);

effect->SetMatrix( "matVP", &(view*proj));
}

//*****************************************************************************

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//T1-MATRIX
template<class T1>
class CObjectInstance_World : public CObjectInstance
{
protected:
virtual void CreateBuffer();
virtual void SetEffectParams();

public:
CObjectInstance_World(CMesh* iMesh, LPD3DXMESH iWorkingMesh, D3DVERTEXELEMENT9* iVertexElementInstance);

virtual ~CObjectInstance_World() {}
};

//*****************************************************************************

template<class T1>
CObjectInstance_World<T1>::CObjectInstance_World(CMesh* iMesh, LPD3DXMESH iWorkingMesh, D3DVERTEXELEMENT9* iVertexElementInstance) : CObjectInstance(iMesh, iWorkingMesh, iVertexElementInstance)
{

}

//*****************************************************************************

template<class T1>
void CObjectInstance_World<T1>::CreateBuffer()
{
//Get cam position
D3DXMATRIXA16 view;
device->GetTransform(D3DTS_VIEW, &view);
D3DXMATRIXA16 inverseView;
D3DXMatrixInverse(&inverseView, NULL, &view);


//Create Buffer
device->CreateVertexBuffer( objects.size() * sizeof(T1), D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &vertexBuffer, NULL );

T1* pVertices;
vertexBuffer->Lock(0, 0, (VOID**)&pVertices, 0);
for(int i=0; i<objects.size(); i++)
{
//float dist = D3DXVec3Length(&(D3DXVECTOR3(inverseView._41, inverseView._42, inverseView._43) - objects[i].second->Position()));


D3DXMATRIXA16 matrix(*objects[i].first);
pVertices[i].r1=D3DXVECTOR4(matrix._11, matrix._21, matrix._31, matrix._41);
pVertices[i].r2=D3DXVECTOR4(matrix._12, matrix._22, matrix._32, matrix._42);
pVertices[i].r3=D3DXVECTOR4(matrix._13, matrix._23, matrix._33, matrix._43);
}
vertexBuffer->Unlock();
}

//*****************************************************************************

template<class T1>
void CObjectInstance_World<T1>::SetEffectParams()
{
//LightHandler->UpdateEffectParams(effect);

D3DXMATRIXA16 view;
D3DXMATRIXA16 proj;

device->GetTransform(D3DTS_VIEW, &view);
device->GetTransform(D3DTS_PROJECTION, &proj);

effect->SetMatrix( "matVP", &(view*proj));
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//T1-MATRIX
template<class T1, class T2>
class CObjectInstance_World_InverseWorld_UVOffset : public CObjectInstance
{
protected:
virtual void CreateBuffer();
virtual void SetEffectParams();

public:
CObjectInstance_World_InverseWorld_UVOffset(CMesh* iMesh, LPD3DXMESH iWorkingMesh, D3DVERTEXELEMENT9* iVertexElementInstance);

virtual ~CObjectInstance_World_InverseWorld_UVOffset() {}
};

//*****************************************************************************

template<class T1, class T2>
CObjectInstance_World_InverseWorld_UVOffset<T1, T2>::CObjectInstance_World_InverseWorld_UVOffset(CMesh* iMesh, LPD3DXMESH iWorkingMesh, D3DVERTEXELEMENT9* iVertexElementInstance) : CObjectInstance(iMesh, iWorkingMesh, iVertexElementInstance)
{

}

//*****************************************************************************

template<class T1, class T2>
void CObjectInstance_World_InverseWorld_UVOffset<T1, T2>::CreateBuffer()
{
//Get cam position
D3DXMATRIXA16 view;
device->GetTransform(D3DTS_VIEW, &view);
D3DXMATRIXA16 inverseView;
D3DXMatrixInverse(&inverseView, NULL, &view);


//Create Buffer
device->CreateVertexBuffer( objects.size() * sizeof(T2), D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &vertexBuffer, NULL );

T2* pVertices;
vertexBuffer->Lock(0, 0, (VOID**)&pVertices, 0);
for(int i=0; i<objects.size(); i++)
{
float dist = D3DXVec3Length(&(D3DXVECTOR3(inverseView._41, inverseView._42, inverseView._43) - objects[i].second->Position()));


D3DXMATRIXA16 matrix(*objects[i].first);
D3DXMATRIXA16 matrixInverse;
D3DXMatrixInverse(&matrixInverse, NULL, &(*objects[i].first));
D3DXMatrixTranspose(&matrixInverse, &matrixInverse);

pVertices[i].r1=D3DXVECTOR4(matrix._11, matrix._21, matrix._31, matrix._41);
pVertices[i].r2=D3DXVECTOR4(matrix._12, matrix._22, matrix._32, matrix._42);
pVertices[i].r3=D3DXVECTOR4(matrix._13, matrix._23, matrix._33, matrix._43);
pVertices[i].r4=D3DXVECTOR4(matrixInverse._11, matrixInverse._12, matrixInverse._13, matrixInverse._14);
pVertices[i].r5=D3DXVECTOR4(matrixInverse._21, matrixInverse._22, matrixInverse._23, matrixInverse._24);
pVertices[i].r6=D3DXVECTOR4(matrixInverse._31, matrixInverse._32, matrixInverse._33, matrixInverse._34);
pVertices[i].r7=D3DXVECTOR4(matrixInverse._41, matrixInverse._42, matrixInverse._43, matrixInverse._44);
pVertices[i].r8=((T1*)objects[i].second)->UVOffset();
}
vertexBuffer->Unlock();
}

//*****************************************************************************

template<class T1, class T2>
void CObjectInstance_World_InverseWorld_UVOffset<T1, T2>::SetEffectParams()
{
LightHandler->UpdateEffectParams(effect);

D3DXMATRIXA16 view;
D3DXMATRIXA16 proj;

device->GetTransform(D3DTS_VIEW, &view);
device->GetTransform(D3DTS_PROJECTION, &proj);

effect->SetMatrix( "matVP", &(view*proj));
}

//*****************************************************************************

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//No Lighting
//T1-MATRIX
template<class T1, class T2>
class CObjectInstance_Particle : public CObjectInstance
{
protected:
virtual void CreateBuffer();
virtual void SetEffectParams();

public:
CObjectInstance_Particle(CMesh* iMesh, LPD3DXMESH iWorkingMesh, D3DVERTEXELEMENT9* iVertexElementInstance);

virtual ~CObjectInstance_Particle() {}
};

//*****************************************************************************

template<class T1, class T2>
CObjectInstance_Particle<T1, T2>::CObjectInstance_Particle(CMesh* iMesh, LPD3DXMESH iWorkingMesh, D3DVERTEXELEMENT9* iVertexElementInstance) : CObjectInstance(iMesh, iWorkingMesh, iVertexElementInstance)
{

}

//*****************************************************************************

template<class T1, class T2>
void CObjectInstance_Particle<T1, T2>::CreateBuffer()
{
//Create Buffer
device->CreateVertexBuffer( objects.size() * sizeof(T2), D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &vertexBuffer, NULL );

T2* pVertices;
vertexBuffer->Lock(0, 0, (VOID**)&pVertices, 0);
for(int i=0; i<objects.size(); i++)
{
D3DXMATRIXA16 matrix(*objects[i].first);
pVertices[i].r1=D3DXVECTOR4(matrix._41, matrix._42, matrix._43, ((T1*)objects[i].second)->Size());   //position and scale
pVertices[i].r2=D3DXVECTOR4(((T1*)objects[i].second)->Alpha(), ((T1*)objects[i].second)->Texture1Offset(), ((T1*)objects[i].second)->Texture2Offset(), ((T1*)objects[i].second)->TextureBlendPosition());
}
vertexBuffer->Unlock();
}

//*****************************************************************************

template<class T1, class T2>
void CObjectInstance_Particle<T1, T2>::SetEffectParams()
{
D3DXMATRIXA16 view;
D3DXMATRIXA16 proj;

device->GetTransform(D3DTS_VIEW, &view);
device->GetTransform(D3DTS_PROJECTION, &proj);

effect->SetMatrix( "matV", &(view));
effect->SetMatrix( "matP", &(proj));
}





#endif
