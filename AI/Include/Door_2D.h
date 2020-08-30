///////////////////////////////////////////////////////////
//  Door_2D.h
//  Created on:      31-08-2009
//  Last modified:   31-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_DOOR_2D_H
#define REGINA_DOOR_2D_H

#include <sstream>
using namespace std;

#include <Door.h>
#include <Wall_2D.h>

namespace Regina
{

class CDoor_2D : public CDoor
{
	CWall_2D* wall_2D;
	unsigned  floorNumber;

public:
	CDoor_2D(const string iClassName = "Door_2D") : CDoor(iClassName, BasicTypeID::type_Door_2D), wall_2D(NULL), floorNumber(0) {}
	CDoor_2D(const D3DXVECTOR2& iBegin, const D3DXVECTOR2& iEnd, const float iRestitution = 1.0f, const unsigned iFloorNumber = 0, const string iClassName = "Door_2D") : CDoor(iClassName, BasicTypeID::type_Door_2D), floorNumber(iFloorNumber) { wall_2D = new CWall_2D(iBegin, iEnd, iRestitution); }
	CDoor_2D(const float& iBeginX, const float& iBeginY, const float& iEndX, const float& iEndY, const float iRestitution = 1.0f, const unsigned iFloorNumber=0, const string iClassName = "Door_2D") : CDoor(iClassName, BasicTypeID::type_Door_2D), floorNumber(iFloorNumber) { wall_2D = new CWall_2D(iBeginX, iBeginY, iEndX, iEndY, iRestitution); }

	virtual void Load(const vector<string>& iText);

	unsigned	FloorNumber() const { return floorNumber; }
	D3DXVECTOR3	Position()			{ assert(wall_2D!=NULL); return wall_2D->Position(); }
	float		Radius()			{ assert(wall_2D!=NULL); return wall_2D->Radius(); }

	CWall_2D	Wall_2D()			{ assert(wall_2D!=NULL); return *wall_2D; }
};


}


#endif
