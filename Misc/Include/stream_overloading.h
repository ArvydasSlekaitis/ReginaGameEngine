///////////////////////////////////////////////////////////
//  stream_overloading.h
//  Created on:      13-11-2009
//  Last modified:   13-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STREAM_OVERLOADING_H
#define REGINA_STREAM_OVERLOADING_H

#include <d3dx9.h>

#include <string>
#include <sstream>
using namespace std;


namespace Regina
{

//*****************************************************************************

static ostream& operator<<(ostream& str, const D3DXVECTOR2& iVec)
	{
	str << iVec.x << " " << iVec.y;
	return str;
	}

//*****************************************************************************

static ostream& operator<<(ostream& str, const D3DXVECTOR3& iVec)
	{
	str << iVec.x << " " << iVec.y << " " << iVec.z;
	return str;
	}

//*****************************************************************************

static ostream& operator<<(ostream& str, const D3DXVECTOR4& iVec)
	{
	str << iVec.x << " " << iVec.y << " " << iVec.z << " " << iVec.w;
	return str;
	}

//*****************************************************************************




}

#endif