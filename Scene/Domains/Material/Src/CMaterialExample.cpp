/*
    CMaterialExample.cpp - Contains class CMaterialExample implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#include <CMaterialExample.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Constructor.
 */
CMaterialExample::CMaterialExample() : CMaterial(L"", L"")
	{
	SetMaterialID(idGenerator.Register(this));

	D3DVERTEXELEMENT9 ve[] =
		{
		D3DDECL_END()
		};

	instanceVertexElement = ve;
	}

//*****************************************************************************

/**
 * Destructor.
 */
CMaterialExample::~CMaterialExample()
	{
	idGenerator.Unregister(this, GetMaterialID());
	}

//*****************************************************************************

/**
 * Private copy constructor.
 */
CMaterialExample::CMaterialExample(const CMaterialExample& iMaterial) : CMaterial(L"", L"")
	{
	}

//*****************************************************************************

/**
 * Private assignment operator.
 */
CMaterialExample& CMaterialExample::operator=(const CMaterialExample& iMaterial)
	{
	return *this;
	}

//*****************************************************************************

/**
* Returns true if material id for both objects matches, otherwise returns false.
*/
bool CMaterialExample::CompareMaterialID(const CMaterialExample& iMaterial)
	{
	return true;
	}

//*****************************************************************************

/**
* Fills instance VB.
*/
void CMaterialExample::FillInstanceVB(D3DXVECTOR4* oInstanceVB, unsigned& ioCurIndex)
	{
	}

//*****************************************************************************

/**
* Sets all effect parameters.
*/
void CMaterialExample::SetEffectParameters(ID3DXEffect* iEffect)
	{
	}

//*****************************************************************************

/**
* Returns instance vertex element structure.
*/
D3DVERTEXELEMENT9* CMaterialExample::GetInstanceVertexElement()
	{
	return instanceVertexElement;
	}

//*****************************************************************************

/**
* Returns instance data size.
*/
unsigned CMaterialExample::GetInstanceDataSize()
	{
	return 0;
	}
