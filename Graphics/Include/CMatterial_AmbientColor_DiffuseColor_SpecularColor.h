///////////////////////////////////////////////////////////
//  CMatterial_AmbientColor_DiffuseColor_SpecularColor.h
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CMATTERIAL_AMBIENTCOLOR_DIFFUSECOLOR_SPECULARCOLOR_H
#define REGINA_CMATTERIAL_AMBIENTCOLOR_DIFFUSECOLOR_SPECULARCOLOR_H

#include <sstream>
using namespace std;

#include <CMatterialData.h>
#include <stream_overloading.h>
#include <TMatterialIDGenerator.h>
#include <EMatterialTypeEnumaration.h>
#include <ERenderInstanceTypeEnumaration.h>

namespace Regina
{


class CMatterial_AmbientColor_DiffuseColor_SpecularColor : public CMatterialData
{
	static TMatterialIDGenerator<CMatterial_AmbientColor_DiffuseColor_SpecularColor> idGenerator;

	D3DXVECTOR3	diffuseColor;
	D3DXVECTOR3	specularColor;
	D3DXVECTOR3	ambientColor;
	float		surfaceSmoothness;
	float		transparency;

	CMatterial_AmbientColor_DiffuseColor_SpecularColor(const CMatterial_AmbientColor_DiffuseColor_SpecularColor&);
	CMatterial_AmbientColor_DiffuseColor_SpecularColor& operator=(const CMatterial_AmbientColor_DiffuseColor_SpecularColor&) {}

public:
	virtual ~CMatterial_AmbientColor_DiffuseColor_SpecularColor();
	CMatterial_AmbientColor_DiffuseColor_SpecularColor();

	virtual void	GetProperty(const string& iPropertyName, float& oPropertyValue);
	virtual void	GetProperty(const string& iPropertyName, D3DXVECTOR3& oPropertyValue);
	virtual void	SetProperty(const string& iPropertyName, const float& iPropertyValue);
	virtual void	SetProperty(const string& iPropertyName, const D3DXVECTOR3& iPropertyValue);

	bool operator==(const CMatterial_AmbientColor_DiffuseColor_SpecularColor& iMatterial);
};

}

#endif 