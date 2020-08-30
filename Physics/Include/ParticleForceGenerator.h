///////////////////////////////////////////////////////////
//  ParticleForceGenerator.h
//  Created on:      22-07-2008
//  Last modified:   25-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PARTICLEFORCEGENERATOR_H
#define REGINA_PARTICLEFORCEGENERATOR_H

#include <ForceGenerator.h>
#include <ParticlePhisics.h>

#include <vector>
using namespace std;

namespace Regina
{

class CParticleForceGenerator : public CForceGenerator
{
protected:
CParticlePhisics* owner;

public:
CParticleForceGenerator(CParticlePhisics* iOwner = NULL, string iName=string("undefined")) : owner(iOwner), CForceGenerator(iName) {}
virtual ~CParticleForceGenerator(){}
virtual void Update(float iTime) = 0;
virtual void Load(string iDefinition) = 0;
virtual void FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys) { assert(owner!=NULL); oAdditionalDependencys.push_back(owner->ID()); }

string Name() const { return name; }
};

}

#endif

