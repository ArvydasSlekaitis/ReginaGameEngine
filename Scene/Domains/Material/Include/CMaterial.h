/*
    CMaterial.h - Contains class CMaterial.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CMATERIAL_H
#define REGINA_CMATERIAL_H

#include <d3dx9.h>

#include <string>
using namespace std;

#include <TMaterialTypeGenerator.h>

namespace Regina
{

namespace Scene
{

/**
 * This class is used as a base class for materials. 
 */
class CMaterial
{
private:
	/**
	 * Stores material ID.
	 */
	int materialID;
	/**
	 * Stores material type.
	 */
	int materialType;
	/**
	 * Stores effect filename.
	 */
	const wstring effectFilename;
	/**
	 * Stores technique name.
	 */
	const wstring techniqueName;
	/**
	 * Material type generator.
	 */
	static TMaterialTypeGenerator<CMaterial> typeGenerator;

	/**
	 * Private copy constructor.
	 */
	CMaterial(const CMaterial& iMaterial);
	/**
	 * Private assignemnt operator.
	 */
	CMaterial& operator=(const CMaterial& iMaterial);
	/**
	 * Sets material type.
	 */
	void SetMaterialType(int newVal);

protected:
	/**
	 * Sets material ID.
	 */
	void SetMaterialID(const int& iMaterialID);

public:
	/**
	 * Fills instance VB.
	 */
	virtual void FillInstanceVB(D3DXVECTOR4* oInstanceVB, unsigned& ioCurIndex) =0;
	/**
	 * Sets all effect parameters.
	 */
	virtual void SetEffectParameters(ID3DXEffect* iEffect) =0;
	/**
	 * Returns instance vertex element structure.
	 */
	virtual D3DVERTEXELEMENT9* GetInstanceVertexElement() =0;
	/**
	 * Returns instance data size.
	 */
	virtual unsigned GetInstanceDataSize() =0;

public:
	/**
	 * Constructor.
	 */
	CMaterial(const wstring& iEffectFilename, const wstring& iEffectTechniqueName);
	/**
	 * Destructor.
	 */
	virtual ~CMaterial();
	/**
	 * Returns true if material type for both objects matches, otherwise returns false.
	 */
	bool CompareMaterialType(const CMaterial& iMaterial);
	/**
	 * Returns material ID.
	 */
	int GetMaterialID() const;
	/**
	 * Returns material type.
	 */
	int GetMaterialType() const;
	/**
	 * Sets effect filename.
	 */
	wstring GetEffectFilename() const;
	/**
	 * Returns technique name.
	 */
	wstring GetTechniqueName() const;
};

}

}

#endif 