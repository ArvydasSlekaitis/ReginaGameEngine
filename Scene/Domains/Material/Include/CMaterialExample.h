/*
    CMaterialExample.h - Contains class CMaterialExample.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CMATERIALEXAMPLE_H
#define REGINA_CMATERIALEXAMPLE_H

#include <CMaterial.h>
#include <TMaterialIDGenerator.h>

namespace Regina
{

namespace Scene
{

class CMaterialExample : public CMaterial
{
private:
	/**
	 * Material ID generator.
	 */
	static TMaterialIDGenerator<CMaterialExample> idGenerator;

	/**
	 * Private copy constructor.
	 */
	CMaterialExample(const CMaterialExample& iMaterial);
	/**
	 * Private assignment operator.
	 */
	CMaterialExample& operator=(const CMaterialExample& iMaterial);
	/**
	 * Instance vertex element.
	 */
	D3DVERTEXELEMENT9* instanceVertexElement;

public:
	/**
	 * Constructor.
	 */
	CMaterialExample();
	/**
	 * Destructor.
	 */
	virtual ~CMaterialExample();
	/**
	 * Returns true if material id for both objects matches, otherwise returns false.
	 */
	bool CompareMaterialID(const CMaterialExample& iMaterial);
	/**
	 * Fills instance VB.
	 */
	virtual void FillInstanceVB(D3DXVECTOR4* oInstanceVB, unsigned& ioCurIndex);
	/**
	 * Sets all effect parameters.
	 */
	virtual void SetEffectParameters(ID3DXEffect* iEffect);
	/**
	 * Returns instance vertex element structure.
	 */
	virtual D3DVERTEXELEMENT9* GetInstanceVertexElement();
	/**
	 * Returns instance data size.
	 */
	virtual unsigned GetInstanceDataSize();
};

}

}

#endif 