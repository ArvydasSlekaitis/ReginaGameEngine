///////////////////////////////////////////////////////////
//  PhisicalLinkRegistration.h
//  Created on:      12-03-2009
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PHISICALLINKREGISTRATION_H
#define REGINA_PHISICALLINKREGISTRATION_H

#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

#include <ParticlePhisics.h>
#include <PhisicalLink.h>
#include <FastAccessRegistration.h>

namespace Regina
{

class CPhisicalLinkRegistration : public TFastAccessRegistration<CPhisicalLink>
{
};

}

#endif
