///////////////////////////////////////////////////////////
//  PhisicalLinkCreator_Default.cpp
//  Created on:      26-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <PhisicalLinkCreator_Default.h>
using namespace Regina;


//*****************************************************************************

CPhisicalLink* CPhisicalLinkCreator_Default::Create(string iType, string iDefinition)
{
CPhisicalLink* phisicalLink(NULL);

while(true)
{

if(iType == "Cable_Particle_Particle")	
	{
	phisicalLink = new CPhisicalLink_Cable_Particle_Particle();
	break;
	}

if(iType == "Cable_Particle_Position")	
	{
	phisicalLink = new CPhisicalLink_Cable_Particle_Position();
	break;
	}

if(iType == "Rod_Particle_Particle")	
	{
	phisicalLink = new CPhisicalLink_Rod_Particle_Particle();
	break;
	}

if(iType == "Rod_Particle_Position")	
	{
	phisicalLink = new CPhisicalLink_Rod_Particle_Position();
	break;
	}
																		   
break;
}


if(phisicalLink!=NULL)
phisicalLink->Load(iDefinition);

return phisicalLink;
}

//*****************************************************************************

