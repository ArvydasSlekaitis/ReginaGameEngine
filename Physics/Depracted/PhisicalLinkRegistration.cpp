///////////////////////////////////////////////////////////
//  PhisicalLinkRegistration.cpp
//  Created on:      12-03-2009
//  Last modified:   26-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <PhisicalLinkRegistration.h>
using namespace Regina;



//*****************************************************************************

CPhisicalLinkRegistration::CPhisicalLinkRegistration()
{
}

//*****************************************************************************

CPhisicalLinkRegistration::~CPhisicalLinkRegistration()
{
}

//*****************************************************************************

CPhisicalLinkRegistration* CPhisicalLinkRegistration::Instance()
{
static CPhisicalLinkRegistration linkReg;
return &linkReg;
}

//*****************************************************************************

void CPhisicalLinkRegistration::LoadLink(string iDefinition)
{
istringstream	def(iDefinition);
string			type;

def >> type;

CPhisicalLink* link(NULL);
link = phisicalLikCreator->Create(type, iDefinition);

assert(link!=NULL); // Phisical link with such name does not exist;

Add(link);
}

//******************************************************************************

void CPhisicalLinkRegistration::LoadLink(vector<string> iDefinitions)
{
for(unsigned i=0; i<iDefinitions.size(); i++)
LoadLink(iDefinitions[i]);
}

//******************************************************************************