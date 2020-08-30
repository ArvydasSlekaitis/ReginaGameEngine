///////////////////////////////////////////////////////////
//  PhisicalLinkCreator.h
//  Created on:      26-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PHISICALLINKCREATOR_H
#define REGINA_PHISICALLINKCREATOR_H

#include <PhisicalLink.h>

namespace Regina
{

class CPhisicalLinkCreator
{
public:
virtual ~CPhisicalLinkCreator(){}
virtual CPhisicalLink* Create(string iType, string iDefinition) = 0;
};

}


#endif