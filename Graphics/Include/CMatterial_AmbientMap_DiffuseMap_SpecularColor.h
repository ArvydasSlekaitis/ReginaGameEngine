///////////////////////////////////////////////////////////
//  CMatterial_AmbientMap_DiffuseMap_SpecularColor.h
//  Created on:      28-01-2010
//  Last modified:   28-01-2010
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CMATTERIAL_AMBIENTMAP_DIFFUSEMAP_SPECULARCOLOR_H
#define REGINA_CMATTERIAL_AMBIENTMAP_DIFFUSEMAP_SPECULARCOLOR_H

#include <sstream>
using namespace std;

#include <CMatterialData.h>
#include <stream_overloading.h>
#include <TMatterialIDGenerator.h>
#include <EMatterialTypeEnumaration.h>
#include <ERenderInstanceTypeEnumaration.h>

namespace Regina
{


class CMatterial_AmbientMap_DiffuseMap_SpecularColor : public CMatterialData
{
	static TMatterialIDGenerator<CMatterial_AmbientMap_DiffuseMap_SpecularColor> idGenerator;

	string		ambientMap;
	string	    diffuseMap;
	D3DXVECTOR3 specularColor;
	
	float		surfaceSmoothness;
	float		transparency;

	CMatterial_AmbientMap_DiffuseMap_SpecularColor(const CMatterial_AmbientMap_DiffuseMap_SpecularColor&);
	CMatterial_AmbientMap_DiffuseMap_SpecularColor& operator=(const CMatterial_AmbientMap_DiffuseMap_SpecularColor&) {}

public:
	virtual ~CMatterial_AmbientMap_DiffuseMap_SpecularColor();
	CMatterial_AmbientMap_DiffuseMap_SpecularColor();

	virtual void	GetProperty(const string& iPropertyName, float& oPropertyValue);
	virtual void	GetProperty(const string& iPropertyName, D3DXVECTOR3& oPropertyValue);
	virtual void	GetProperty(const string& iPropertyName, string& oPropertyValue);
	virtual void	SetProperty(const string& iPropertyName, const float& iPropertyValue);
	virtual void	SetProperty(const string& iPropertyName, const D3DXVECTOR3& iPropertyValue);
	virtual void	SetProperty(const string& iPropertyName, const string& iPropertyValue);

	bool operator==(const CMatterial_AmbientMap_DiffuseMap_SpecularColor& iMatterial);
};

}

#endif 