///////////////////////////////////////////////////////////
//  Entity_Statue.cpp
//  Created on:      25-08-2009
//  Last modified:   25-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Entity_Statue.h>
using namespace Regina;

//*****************************************************************************

CEntity_Statue::CEntity_Statue() : CBaseEntity("Entity_Statue", 1) 
	{
	}

//*****************************************************************************

CEntity_Statue::~CEntity_Statue()
	{
	}

//*****************************************************************************

void CEntity_Statue::Update(float duration) 
	{
	}

//*****************************************************************************

void CEntity_Statue::Load(const vector<string>& iText) 
	{
	for(unsigned i=0; i<iText.size(); i++)
		{		
		istringstream line(iText[i]);
		string type;
		line >> type;
		if(type == "Position")
			{
			line >> position.x >> position.y >> position.z;
			}
	
		}

	AIManager->AddCollisionObject_Static("Statue", D3DXMATRIXA16(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, position.x, position.y, position.z, 1));
	}

//*****************************************************************************