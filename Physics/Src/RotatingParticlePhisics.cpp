///////////////////////////////////////////////////////////
//  RotatingParticlePhisics.cpp
//  Created on:      26-05-2009
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <RotatingParticlePhisics.h>
using namespace Regina;


//*****************************************************************************

void CRotatingParticlePhisics::Update(float iDuration)
{
D3DXVECTOR3 acc = acceleration;
acc += forceAccumulator * inverseMass;
position += velocity*iDuration;
velocity = velocity*damping + acc * iDuration;

orientation += rotation*iDuration;
rotation = rotation*angularDamping + angularAcceleration*iDuration;

ClearAccumulator();
}

//*****************************************************************************

