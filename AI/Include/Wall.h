///////////////////////////////////////////////////////////
//  Wall.h
//  Created on:      25-06-2009
//  Last modified:   30-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_WALL_H
#define REGINA_WALL_H


namespace Regina
{

class CWall
{
protected:
	float restitution;

public:
	CWall(const float& iRestitution) : restitution(iRestitution) {}
	
	void SetRestitution(const float& iRestitution) { restitution = iRestitution; }
	float Restitution() const { return restitution; }
};

}

#endif