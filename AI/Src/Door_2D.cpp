///////////////////////////////////////////////////////////
//  Door_2D.cpp
//  Created on:      31-08-2009
//  Last modified:   31-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Door_2D.h>
using namespace Regina;

//*****************************************************************************

void CDoor_2D::Load(const vector<string>& iText)
	{
	D3DXVECTOR2 iBegin;
	D3DXVECTOR2 iEnd;
	float		iRestitution;

	for(unsigned i=0; i<iText.size(); i++)
		{		
		istringstream line(iText[i]);
		string type;
		line >> type;
		if(type == "Begin")
			line >> iBegin.x >> iBegin.y;
	
		if(type == "End")
			line >> iEnd.x >> iEnd.y;

		if(type == "iRestitution")
			line >> iRestitution;

		if(type == "iFloorNumber")
			line >> floorNumber;
	
		}

	if(wall_2D!=NULL) delete wall_2D;

	wall_2D = new CWall_2D(iBegin, iEnd, iRestitution);
	}

//*****************************************************************************
