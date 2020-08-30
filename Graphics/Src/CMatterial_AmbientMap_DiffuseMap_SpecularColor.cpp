///////////////////////////////////////////////////////////
//  CMatterial_AmbientMap_DiffuseMap_SpecularColor.cpp
//  Created on:      28-01-2010
//  Last modified:   28-01-2010
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CMatterial_AmbientMap_DiffuseMap_SpecularColor.h>
using namespace Regina;


//*****************************************************************************

CMatterial_AmbientMap_DiffuseMap_SpecularColor::~CMatterial_AmbientMap_DiffuseMap_SpecularColor()
	{
	idGenerator.Unregister(this, MatterialID());
	}

//*****************************************************************************

CMatterial_AmbientMap_DiffuseMap_SpecularColor::CMatterial_AmbientMap_DiffuseMap_SpecularColor() : ambientMap(""), diffuseMap(""), specularColor(0, 0, 0), surfaceSmoothness(0), transparency(0), CMatterialData(MatterialType_AmbientMap_DiffuseMap_SpecularColor, RenderInstanceType_AmbientMap_DiffuseMap_SpecularColor)
	{
	SetMatterialID(idGenerator.Register(this));
	}

//*****************************************************************************
	
void CMatterial_AmbientMap_DiffuseMap_SpecularColor::GetProperty(const string& iPropertyName, float& oPropertyValue)
	{
	if(iPropertyName == "transparency")
		oPropertyValue = transparency;
	else
	if(iPropertyName == "surfaceSmoothness")
		oPropertyValue = surfaceSmoothness;
	else
		throw invalid_argument("CMatterial_AmbientMap_DiffuseMap_SpecularColor::GetProperty - trying to get property which does not exist");
	}

//*****************************************************************************

void CMatterial_AmbientMap_DiffuseMap_SpecularColor::GetProperty(const string& iPropertyName, D3DXVECTOR3& oPropertyValue)
	{
	if(iPropertyName == "specularColor")
		oPropertyValue = specularColor;

	else
		throw invalid_argument("CMatterial_AmbientMap_DiffuseMap_SpecularColor::GetProperty - trying to get property which does not exist");
	}

//*****************************************************************************

void CMatterial_AmbientMap_DiffuseMap_SpecularColor::GetProperty(const string& iPropertyName, string& oPropertyValue)
	{
	if(iPropertyName == "ambientMap")
		oPropertyValue = ambientMap;
	else

	if(iPropertyName == "diffuseMap")
		oPropertyValue = diffuseMap;
	
	else
		throw invalid_argument("CMatterial_AmbientMap_DiffuseMap_SpecularColor::GetProperty - trying to get property which does not exist");
	}

//*****************************************************************************

void CMatterial_AmbientMap_DiffuseMap_SpecularColor::SetProperty(const string& iPropertyName, const float& iPropertyValue)
	{
	if(iPropertyName == "transparency")
		{
		transparency = iPropertyValue;
		if(transparency != 1)
			EnableTransparency();
		else
			DisableTransparency();
		}
	else
	if(iPropertyName == "surfaceSmoothness")
		surfaceSmoothness = iPropertyValue;
	else
		throw invalid_argument("CMatterial_AmbientMap_DiffuseMap_SpecularColor::SetProperty - trying to set property which does not exist");

	SetMatterialID(idGenerator.Update(this, MatterialID()));
	}

//*****************************************************************************

void CMatterial_AmbientMap_DiffuseMap_SpecularColor::SetProperty(const string& iPropertyName, const D3DXVECTOR3& iPropertyValue)
	{
	if(iPropertyName == "specularColor")
		specularColor = iPropertyValue;

	else
		throw invalid_argument("CMatterial_AmbientMap_DiffuseMap_SpecularColor::SetProperty - trying to set property which does not exist");

	SetMatterialID(idGenerator.Update(this, MatterialID()));
	}

//*****************************************************************************

void CMatterial_AmbientMap_DiffuseMap_SpecularColor::SetProperty(const string& iPropertyName, const string& iPropertyValue)
	{
	if(iPropertyName == "ambientMap")
		ambientMap = iPropertyValue;
	else

	if(iPropertyName == "diffuseMap")
		diffuseMap = iPropertyValue;
	
	else
		throw invalid_argument("CMatterial_AmbientMap_DiffuseMap_SpecularColor::SetProperty - trying to set property which does not exist");

	SetMatterialID(idGenerator.Update(this, MatterialID()));
	}

//*****************************************************************************

bool CMatterial_AmbientMap_DiffuseMap_SpecularColor::operator==(const CMatterial_AmbientMap_DiffuseMap_SpecularColor& iMatterial)
	{
	return (diffuseMap == iMatterial.diffuseMap && specularColor == iMatterial.specularColor && ambientMap == iMatterial.ambientMap && surfaceSmoothness == iMatterial.surfaceSmoothness && transparency == iMatterial.transparency);
	}

//*****************************************************************************

CMatterial_AmbientMap_DiffuseMap_SpecularColor::CMatterial_AmbientMap_DiffuseMap_SpecularColor(const CMatterial_AmbientMap_DiffuseMap_SpecularColor&) : ambientMap(""), diffuseMap(""), specularColor(0, 0, 0), surfaceSmoothness(0), transparency(0), CMatterialData(MatterialType_AmbientColor_DiffuseColor_SpecularColor, RenderInstanceType_AmbientColor_DiffuseColor_SpecularColor)
	{
	}

//*****************************************************************************

TMatterialIDGenerator<CMatterial_AmbientMap_DiffuseMap_SpecularColor> CMatterial_AmbientMap_DiffuseMap_SpecularColor::idGenerator;

//*****************************************************************************
