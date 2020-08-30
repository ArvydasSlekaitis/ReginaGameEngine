/*
    C2DRenderObject_Text.h - Contains class C2DRenderObject_Text.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_C2DRENDEROBJECT_H
#define REGINA_GRAPHICS_C2DRENDEROBJECT_H

#include <d3dx9.h>

namespace Regina
{

namespace Graphics
{

class C2DRenderObject
{
public:
	virtual ~C2DRenderObject() {}

	virtual void Render(LPD3DXSPRITE iSprite) =0;

};

}

}

#endif 