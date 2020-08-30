///////////////////////////////////////////////////////////
//  ParticleLink.cpp
//  Created on:      12-03-2009
//  Last modified:   13-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <ParticleLink.h>
using namespace Regina;


//*****************************************************************************

CParticleLink::CParticleLink(CParticlePhisics* iParticle1, CParticlePhisics* iParticle2) 
{ 
particle[0] = iParticle1;
particle[1] = iParticle2;
}

//*****************************************************************************

float CParticleLink::CurrentLength()
{
return D3DXVec3Length(&(particle[0]->Position() - particle[1]->Position()));
}

//*****************************************************************************
