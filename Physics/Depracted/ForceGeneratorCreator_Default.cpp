///////////////////////////////////////////////////////////
//  ForceGeneratorCreator_Default.cpp
//  Created on:      06-03-2009
//  Last modified:   25-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <ForceGeneratorCreator_Default.h>
using namespace Regina;


//*****************************************************************************

CForceGenerator* CForceGeneratorCreator_Default::Create(string iType, string iDefinition)
{
CForceGenerator* forceGenerator(NULL);

while(true)
{

//Particle Force Generators
if(iType == "Particle_Gravity")	
	{
	forceGenerator = new CParticleForceGenerator_Gravity();
	break;
	}

if(iType == "Particle_Drag")	
	{
	forceGenerator = new CParticleForceGenerator_Drag();
	break;
	}

if(iType == "Particle_Buoyancy")	
	{
	forceGenerator = new CParticleForceGenerator_Buoyancy();
	break;
	}

if(iType == "Particle_Spring_Bungee_Position")	
	{
	forceGenerator = new CParticleForceGenerator_Spring_Bungee_Position();
	break;
	}

if(iType == "Particle_Spring_Springlike_Position")	
	{
	forceGenerator = new CParticleForceGenerator_Spring_Springlike_Position();
	break;
	}


//Multiple Force Generators
if(iType == "Spring_Bungee_Particle_Particle")	
	{
	forceGenerator = new CParticleForceGenerator_Spring_Bungee_Position();
	break;
	}

if(iType == "Particle_Spring_Springlike_Position")	
	{
	forceGenerator = new CParticleForceGenerator_Spring_Springlike_Position();
	break;
	}

																		   
break;
}


if(forceGenerator!=NULL)
	{
	forceGenerator->Load(iDefinition);
	}

return forceGenerator;
}

//*****************************************************************************

