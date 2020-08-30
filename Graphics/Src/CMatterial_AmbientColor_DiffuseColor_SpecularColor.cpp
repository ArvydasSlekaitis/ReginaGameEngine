///////////////////////////////////////////////////////////
//  CMatterial_AmbientColor_DiffuseColor_SpecularColor.cpp
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CMatterial_AmbientColor_DiffuseColor_SpecularColor.h>
using namespace Regina;


//*****************************************************************************

CMatterial_AmbientColor_DiffuseColor_SpecularColor::~CMatterial_AmbientColor_DiffuseColor_SpecularColor()
	{
	idGenerator.Unregister(this, MatterialID());
	}

//*****************************************************************************

CMatterial_AmbientColor_DiffuseColor_SpecularColor::CMatterial_AmbientColor_DiffuseColor_SpecularColor() : ambientColor(0, 0, 0), diffuseColor(0, 0, 0), specularColor(0, 0, 0), surfaceSmoothness(0), transparency(0), CMatterialData(MatterialType_AmbientColor_DiffuseColor_SpecularColor, RenderInstanceType_AmbientColor_DiffuseColor_SpecularColor)
	{
	SetMatterialID(idGenerator.Register(this));
	}

//*****************************************************************************
	
void CMatterial_AmbientColor_DiffuseColor_SpecularColor::GetProperty(const string& iPropertyName, float& oPropertyValue)
	{
	if(iPropertyName == "transparency")
		oPropertyValue = transparency;
	else
	if(iPropertyName == "surfaceSmoothness")
		oPropertyValue = surfaceSmoothness;
	else
		throw invalid_argument("CMatterial_AmbientColor_DiffuseColor_SpecularColor::GetProperty - trying to get property which does not exist");
	}

//*****************************************************************************

void CMatterial_AmbientColor_DiffuseColor_SpecularColor::GetProperty(const string& iPropertyName, D3DXVECTOR3& oPropertyValue)
	{
	if(iPropertyName == "ambientColor")
		oPropertyValue = ambientColor;
	else

	if(iPropertyName == "diffuseColor")
		oPropertyValue = diffuseColor;
	else

	if(iPropertyName == "specularColor")
		oPropertyValue = specularColor;

	else
		throw invalid_argument("CMatterial_AmbientColor_DiffuseColor_SpecularColor::GetProperty - trying to get property which does not exist");
	}

//*****************************************************************************

void CMatterial_AmbientColor_DiffuseColor_SpecularColor::SetProperty(const string& iPropertyName, const float& iPropertyValue)
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
		throw invalid_argument("CMatterial_AmbientColor_DiffuseColor_SpecularColor::SetProperty - trying to set property which does not exist");

	SetMatterialID(idGenerator.Update(this, MatterialID()));
	}

//*****************************************************************************

void CMatterial_AmbientColor_DiffuseColor_SpecularColor::SetProperty(const string& iPropertyName, const D3DXVECTOR3& iPropertyValue)
	{
	if(iPropertyName == "ambientColor")
		ambientColor = iPropertyValue;
	else

	if(iPropertyName == "diffuseColor")
		diffuseColor = iPropertyValue;
	else

	if(iPropertyName == "specularColor")
		specularColor = iPropertyValue;

	else
		throw invalid_argument("CMatterial_AmbientColor_DiffuseColor_SpecularColor::SetProperty - trying to set property which does not exist");

	SetMatterialID(idGenerator.Update(this, MatterialID()));
	}

//*****************************************************************************

bool CMatterial_AmbientColor_DiffuseColor_SpecularColor::operator==(const CMatterial_AmbientColor_DiffuseColor_SpecularColor& iMatterial)
	{
	return (diffuseColor == iMatterial.diffuseColor && specularColor == iMatterial.specularColor && ambientColor == iMatterial.ambientColor && surfaceSmoothness == iMatterial.surfaceSmoothness && transparency == iMatterial.transparency);
	}

//*****************************************************************************

CMatterial_AmbientColor_DiffuseColor_SpecularColor::CMatterial_AmbientColor_DiffuseColor_SpecularColor(const CMatterial_AmbientColor_DiffuseColor_SpecularColor&) : ambientColor(0, 0, 0), diffuseColor(0, 0, 0), specularColor(0, 0, 0), surfaceSmoothness(0), transparency(0), CMatterialData(MatterialType_AmbientColor_DiffuseColor_SpecularColor, RenderInstanceType_AmbientColor_DiffuseColor_SpecularColor)
	{
	}

//*****************************************************************************

TMatterialIDGenerator<CMatterial_AmbientColor_DiffuseColor_SpecularColor> CMatterial_AmbientColor_DiffuseColor_SpecularColor::idGenerator;

//*****************************************************************************
