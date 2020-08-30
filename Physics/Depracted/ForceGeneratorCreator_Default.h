///////////////////////////////////////////////////////////
//  ForceGeneratorCreator_Default.h
//  Created on:      06-03-2009
//  Last modified:   25-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_FORCEGENERATORCREATOR_DEFAULT_H
#define REGINA_FORCEGENERATORCREATOR_DEFAULT_H

#include <sstream>
using namespace std;

#include <ForceGeneratorCreator.h>
#include <ForceGenerator.h>

//Particle Force Generators
#include <ParticleForceGenerator_Gravity.h>
#include <ParticleForceGenerator_Drag.h>
#include <ParticleForceGenerator_Buoyancy.h>
#include <ParticleForceGenerator_Spring_Bungee_Position.h>
#include <ParticleForceGenerator_Spring_Springlike_Position.h>

//Multiple Force Generators
#include <ForceGenerator_Spring_Bungee_Particle_Particle.h>
#include <ForceGenerator_Spring_Springlike_Particle_Particle.h>


namespace Regina
{

class CForceGeneratorCreator_Default : public CForceGeneratorCreator
{
public:
virtual ~CForceGeneratorCreator_Default(){}
virtual CForceGenerator* Create(string iType, string iDefinition);
};

}


#endif