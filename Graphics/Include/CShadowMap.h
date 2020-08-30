///////////////////////////////////////////////////////////
//  CShadowMap.h
//  Created on:      14-11-2009
//  Last modified:   14-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CSHADOWMAP_H
#define REGINA_CSHADOWMAP_H

#include <d3dx9.h>
#include <stdexcept>
using namespace std;

namespace Regina
{


class CShadowMap
{
protected:
	LPDIRECT3DDEVICE9 device;

public:
	virtual ~CShadowMap();
	CShadowMap(LPDIRECT3DDEVICE9 iDevice);

	virtual void OnLostDevice() = 0;
	virtual void OnResetDevice() = 0;

};

}

#endif 