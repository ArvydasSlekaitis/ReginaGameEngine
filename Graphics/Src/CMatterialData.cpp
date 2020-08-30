///////////////////////////////////////////////////////////
//  CMatterialData.cpp
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CMatterialData.h>
using namespace Regina;


//*****************************************************************************

CMatterialData::~CMatterialData()
	{
	}

//*****************************************************************************

CMatterialData::CMatterialData(const eMatterialType& iMatterialType, const eRenderInstanceType&	iRenderInstanceType) : matterialType(iMatterialType), renderInstanceType(iRenderInstanceType), transparencyEnabled(false), matterialID(0)
	{
	}

//*****************************************************************************
	
void CMatterialData::EnableTransparency()
	{
	transparencyEnabled = true;
	}

//*****************************************************************************

void CMatterialData::DisableTransparency()
	{
	transparencyEnabled = false;
	}

//*****************************************************************************

