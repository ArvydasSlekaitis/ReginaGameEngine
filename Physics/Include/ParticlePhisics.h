///////////////////////////////////////////////////////////
//  ParticlePhisics.h
//  Created on:      22-07-2008
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PARTICLEPHISICS_H
#define REGINA_PARTICLEPHISICS_H

#include <d3dx9.h>
#include <sstream>
#include <stdexcept>
using namespace std;

#include <SpritePhisics.h>

namespace Regina
{

class CParticlePhisics : public CSpritePhisics
{
protected:
	D3DXVECTOR3 forceAccumulator;

	float damping;
	float inverseMass;


public:
	CParticlePhisics() : CSpritePhisics(), damping(1), inverseMass(0), forceAccumulator(0, 0, 0) { type=Particle; }
	virtual ~CParticlePhisics(){}
	float Damping()				const { return damping; }
	float InverseMass()			const { return inverseMass; }
	float Mass()				const { if(inverseMass==0) throw logic_error("Trying to return mass, while inverse mass equals to zero"); return 1/inverseMass; }

	void SetDamping(float iDamping)			{ damping = iDamping; }
	void SetInverseMass(float iInverseMass) { inverseMass = iInverseMass; }
	void SetMass(float iMass)				{ if(iMass==0) throw invalid_argument("Mass equals to zero"); inverseMass = 1/iMass; }

	void ClearAccumulator() { forceAccumulator.x=0; forceAccumulator.y=0; forceAccumulator.z=0;}
	void AddForce(D3DXVECTOR3 iForce) { forceAccumulator += iForce; }
	void AddForce(float iX, float iY, float iZ) { forceAccumulator.x += iX; forceAccumulator.y += iY; forceAccumulator.z += iZ; }

	virtual void Update(float iDuration);

};


}    

#endif


