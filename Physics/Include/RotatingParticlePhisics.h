///////////////////////////////////////////////////////////
//  RotatingParticlePhisics.h
//  Created on:      26-05-2009
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_ROTATINGPARTICLEPHISICS_H
#define REGINA_ROTATINGPARTICLEPHISICS_H

#include <d3dx9.h>
#include <sstream>
using namespace std;

#include <ParticlePhisics.h>

namespace Regina
{

class CRotatingParticlePhisics : public CParticlePhisics
{
protected:
	float orientation;
	float angularAcceleration;
	float rotation;
	float angularDamping;

public:
	CRotatingParticlePhisics() : CParticlePhisics(), orientation(0), angularAcceleration(0), rotation(0), angularDamping(1) { type=RotatingParticle; }
	virtual ~CRotatingParticlePhisics(){}

	float Orientation()			const { return orientation; }
	float AngularAcceleration() const { return angularAcceleration; }
	float Rotation()			const { return rotation; }
	float AngularDamping()      const { return angularDamping; }

	void SetOrientation(float iOrientation)			{ orientation = iOrientation; }
	void SetAngularAcceleration(float iAngularAcceleration) { angularAcceleration = iAngularAcceleration; }
	void AddAngularAcceleration(float iAngularAcceleration) { angularAcceleration += iAngularAcceleration; }
	void SetRotation(float iRotation)				{ rotation = iRotation; }
	void SetAngularDamping(float iAngularDamping)	{ angularDamping = iAngularDamping; }

	void ClearAccumulator() { forceAccumulator.x=0; forceAccumulator.y=0; forceAccumulator.z=0; angularAcceleration=0; }

	virtual void Update(float iDuration);
};


}    

#endif


