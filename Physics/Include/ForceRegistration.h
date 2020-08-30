///////////////////////////////////////////////////////////
//  ForceRegistration.h
//  Created on:      22-07-2008
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_FORCEREGISTRATION_H
#define REGINA_FORCEREGISTRATION_H

#include <ParticlePhisics.h>
#include <ForceGenerator.h>
#include <FastAccessRegistration.h>

namespace Regina
{

class CForceRegistration : public TFastAccessRegistration<CForceGenerator>
{
public: 
	void Remove(CParticlePhisics* iObject, string iName);
	void Remove(CForceGenerator* iObject) { TFastAccessRegistration<CForceGenerator>::Remove(iObject);  } 
};

}

#endif
