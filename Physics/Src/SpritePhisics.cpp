///////////////////////////////////////////////////////////
//  SpritePhisics.cpp
//  Created on:      26-05-2009
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <SpritePhisics.h>
using namespace Regina;


//*****************************************************************************

void CSpritePhisics::Update(float iDuration)
{
position += velocity*iDuration;
velocity = velocity + acceleration * iDuration;
}

//*****************************************************************************

