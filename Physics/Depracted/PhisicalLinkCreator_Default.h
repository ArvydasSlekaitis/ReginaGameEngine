///////////////////////////////////////////////////////////
//  PhisicalLinkCreator_Default.h
//  Created on:      26-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PHISICALLINKCREATOR_DEFAULT_H
#define REGINA_PHISICALLINKCREATOR_DEFAULT_H

#include <PhisicalLinkCreator.h>
#include <PhisicalLink.h>

#include <PhisicalLink_Cable_Particle_Particle.h>
#include <PhisicalLink_Cable_Particle_Position.h>
#include <PhisicalLink_Rod_Particle_Particle.h>
#include <PhisicalLink_Rod_Particle_Position.h>

namespace Regina
{

class CPhisicalLinkCreator_Default : public CPhisicalLinkCreator
{
public:
virtual ~CPhisicalLinkCreator_Default(){}
virtual CPhisicalLink* Create(string iType, string iDefinition);
};

}


#endif