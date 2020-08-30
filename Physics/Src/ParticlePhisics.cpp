///////////////////////////////////////////////////////////
//  ParticlePhisics.cpp
//  Created on:      22-07-2008
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <ParticlePhisics.h>
using namespace Regina;


//*****************************************************************************

void CParticlePhisics::Update(float iDuration)
{
D3DXVECTOR3 acc = acceleration;
acc += forceAccumulator * inverseMass;
position += velocity*iDuration;
velocity = velocity*damping + acc * iDuration;

ClearAccumulator();
}

//*****************************************************************************
