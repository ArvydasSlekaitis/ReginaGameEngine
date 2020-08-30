///////////////////////////////////////////////////////////
//  CRenderObject.cpp
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CRenderObject.h>
using namespace Regina;


//*****************************************************************************

CRenderObject::~CRenderObject()
	{
	}

//*****************************************************************************

CRenderObject::CRenderObject(const CRenderObject::eType& iType, const CMatterial& iMatterial, const bool& iCastShadows, const bool& iReceiveShadows) : type(iType), castShadows(iCastShadows), receiveShadows(iReceiveShadows), matterial(iMatterial)
  	{
	}

//*****************************************************************************

bool CRenderObject::TransparencyEnabled() const
	{
	return matterial.TransparencyEnabled();
	}

//*****************************************************************************

CRenderObject& CRenderObject::operator=(const CRenderObject& iRenderObject)
	{
	if(this!=&iRenderObject)
		{
		type = iRenderObject.type;
		castShadows = iRenderObject.castShadows;
		receiveShadows = iRenderObject.receiveShadows;
		matterial = iRenderObject.matterial;
		}
	return *this;
	}

//*****************************************************************************