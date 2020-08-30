///////////////////////////////////////////////////////////
//  ForceGeneratorCreator.h
//  Created on:      06-03-2009
//  Last modified:   25-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_FORCEGENERATORCREATOR_H
#define REGINA_FORCEGENERATORCREATOR_H

#include <ForceGenerator.h>

namespace Regina
{

class CForceGeneratorCreator
{
public:
virtual ~CForceGeneratorCreator(){}
virtual CForceGenerator* Create(string iType, string iDefinition) = 0;
};

}


#endif