///////////////////////////////////////////////////////////
//  ForceRegistration.cpp
//  Created on:      22-07-2008
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <ForceRegistration.h>
using namespace Regina;


//*****************************************************************************

void CForceRegistration::Remove(CParticlePhisics* iObject, string iName)
{
vector<unsigned> particlePosition;
GetEntityPositionList(iObject->ID(), particlePosition);

for(unsigned i=0; i<particlePosition.size(); i++)
{
assert(objects[particlePosition[i]]!=NULL);
	if(objects[particlePosition[i]]->Name() == iName)
	{
	UnregisterObject(particlePosition[i]);
	}
}
}

//*****************************************************************************
