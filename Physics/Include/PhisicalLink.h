///////////////////////////////////////////////////////////
//  PhisicalLink.h
//  Created on:      12-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PHISICALLINK_H
#define REGINA_PHISICALLINK_H

#include <assert.h>
#include <vector>
using namespace std;

#include <ParticlePhisics.h>
#include <ContactData.h>

namespace Regina
{

class CPhisicalLink
{
public:
CPhisicalLink() {}
virtual ~CPhisicalLink(){}
virtual void Update(float iTime) = 0;
virtual void Load(string iDefinition) = 0;
virtual void FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys) = 0;
};

}

#endif
