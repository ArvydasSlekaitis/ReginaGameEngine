///////////////////////////////////////////////////////////
//  CMatterial.cpp
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CMatterial.h>
using namespace Regina;


//*****************************************************************************

CMatterial::~CMatterial()
	{
	data=NULL;
	}

//*****************************************************************************

CMatterial::CMatterial(CMatterialData* iMatterialData) : data(NULL)
  	{
	if(iMatterialData == NULL)
		throw invalid_argument("CMatterial::CMatterial - argument iMatterialData==NULL");
	data = iMatterialData;
	}

//*****************************************************************************

CMatterial::CMatterial(const CMatterial& iMatterial)
  	{
	data =  iMatterial.data;
	}

//*****************************************************************************
	
eRenderInstanceType CMatterial::RenderInstanceType() const 
  	{
	return data->RenderInstanceType();
	}

//*****************************************************************************

eMatterialType CMatterial::MatterialType() const 
  	{
	return data->MatterialType();
	}

//*****************************************************************************

unsigned CMatterial::MatterialID() const 
  	{
	return data->MatterialID();
	}

//*****************************************************************************

bool CMatterial::TransparencyEnabled() const 
  	{
	return data->TransparencyEnabled();
	}

//*****************************************************************************

void CMatterial::GetProperty(const string& iPropertyName, float& oPropertyValue) const
	{
	data->GetProperty(iPropertyName, oPropertyValue);
	}

//*****************************************************************************

void CMatterial::GetProperty(const string& iPropertyName, string& oPropertyValue) const
	{
	data->GetProperty(iPropertyName, oPropertyValue);
	}

//*****************************************************************************

void CMatterial::GetProperty(const string& iPropertyName, D3DXVECTOR2& oPropertyValue) const
	{
	data->GetProperty(iPropertyName, oPropertyValue);
	}

//*****************************************************************************

void CMatterial::GetProperty(const string& iPropertyName, D3DXVECTOR3& oPropertyValue) const
	{
	data->GetProperty(iPropertyName, oPropertyValue);
	}

//*****************************************************************************

void CMatterial::GetProperty(const string& iPropertyName, D3DXVECTOR4& oPropertyValue) const
	{
	data->GetProperty(iPropertyName, oPropertyValue);
	}

//*****************************************************************************

void CMatterial::SetProperty(const string& iPropertyName, const string& iPropertyValue)
	{
	data->SetProperty(iPropertyName, iPropertyValue);
	}

//*****************************************************************************

void CMatterial::SetProperty(const string& iPropertyName, const float& iPropertyValue)
	{
	data->SetProperty(iPropertyName, iPropertyValue);
	}

//*****************************************************************************

void CMatterial::SetProperty(const string& iPropertyName, const D3DXVECTOR2& iPropertyValue)
	{
	data->SetProperty(iPropertyName, iPropertyValue);
	}

//*****************************************************************************

void CMatterial::SetProperty(const string& iPropertyName, const D3DXVECTOR3& iPropertyValue)
	{
	data->SetProperty(iPropertyName, iPropertyValue);
	}

//*****************************************************************************

void CMatterial::SetProperty(const string& iPropertyName, const D3DXVECTOR4& iPropertyValue)
	{
	data->SetProperty(iPropertyName, iPropertyValue);
	}

//*****************************************************************************