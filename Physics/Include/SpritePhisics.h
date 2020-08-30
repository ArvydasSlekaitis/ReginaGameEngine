///////////////////////////////////////////////////////////
//  SpritePhisics.h
//  Created on:      26-05-2009
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_SPRITEPHISICS_H
#define REGINA_SPRITEPHISICS_H

#include <d3dx9.h>
#include <sstream>
#include <exception>
#include <stdexcept>
using namespace std;

namespace Regina
{

class CParticlePhisicsManager;

class CSpritePhisics 
{
private:
	unsigned	  id;

public:
	enum phisics_type{Sprite, Particle, RotatingParticle};

protected:
	D3DXVECTOR3 position;
	D3DXVECTOR3 velocity;
	D3DXVECTOR3 acceleration;

phisics_type  type;

public:
	CSpritePhisics() : position(0, 0, 0), velocity(0, 0, 0), acceleration(0, 0, 0), id(0), type(Sprite)  {}
	virtual ~CSpritePhisics(){ if(id!=0) throw logic_error("Trying to delete particle which was not unregistered with PhisicsManager ( Call PhisicsManager->RemoveParticle instead )");  }

	D3DXVECTOR3 Position()		const { return position; }
	D3DXVECTOR3 Velocity()		const { return velocity; }
	D3DXVECTOR3 Acceleration()	const { return acceleration; }
	unsigned ID()				const { return id; }

	float Speed()					  { return  D3DXVec3Length(&velocity); }

	void SetPosition(D3DXVECTOR3 iPosition)			{ position = iPosition; }
	void SetVelocity(D3DXVECTOR3 iVelocity)			{ velocity = iVelocity; }
	void SetAcceleration(D3DXVECTOR3 iAcceleration) { acceleration = iAcceleration; }

	void SetPosition(float iX, float iY, float iZ)		{ position.x=iX; position.y=iY; position.z=iZ; }
	void SetVelocity(float iX, float iY, float iZ)		{ velocity.x=iX; velocity.y=iY; velocity.z=iZ; }
	void SetAcceleration(float iX, float iY, float iZ)	{ acceleration.x=iX; acceleration.y=iY; acceleration.z=iZ; }

	virtual void Update(float iDuration);

friend CParticlePhisicsManager;
};


}    

#endif


