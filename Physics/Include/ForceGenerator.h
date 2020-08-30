///////////////////////////////////////////////////////////
//  ForceGenerator.h
//  Created on:      22-07-2008
//  Last modified:   25-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_FORCEGENERATOR_H
#define REGINA_FORCEGENERATOR_H

#include <vector>
#include <assert.h>
using namespace std;

namespace Regina
{

class CForceGenerator
{
protected:
string name; 

public:
CForceGenerator(string iName=string("undefined")) : name(iName) {}
virtual ~CForceGenerator(){}
virtual void Update(float iTime) = 0;
virtual void Load(string iDefinition) = 0;
virtual void FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys) = 0;

string Name() const { return name; }
};

}

#endif

