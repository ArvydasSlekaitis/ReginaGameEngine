///////////////////////////////////////////////////////////
//  ContactData_ParticleImmovable.cpp
//  Created on:      12-03-2009
//  Last modified:   29-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <ContactData_ParticleImmovable.h>
using namespace Regina;


//*****************************************************************************

CContactData_ParticleImmovable::CContactData_ParticleImmovable(CParticlePhisics* iParticle, D3DXVECTOR3 iContactNormal, float iPenetration, float iRestitution) : CContactData(true, iContactNormal, iPenetration, iRestitution)
	{
	assert(iParticle!=NULL);
	particle = iParticle;
	initialPosition = particle->Position();
	}

//*****************************************************************************

CContactData_ParticleImmovable::CContactData_ParticleImmovable(CParticlePhisics* iParticle, const CBasicContactData& iBasicContactData) : CContactData(true, iBasicContactData)
	{
	assert(iParticle!=NULL);
	particle = iParticle;
	initialPosition = particle->Position();
	}

//*****************************************************************************

void CContactData_ParticleImmovable::Resolve(float iDuration)
{
ResolveVelocity(iDuration);
ResolveInterpenetration(iDuration);
}

//*****************************************************************************

void CContactData_ParticleImmovable::ResolveVelocity(float iDuration)
{
float separatingVelocity = CalculateSeparatingVelocity();

if(separatingVelocity > 0 || particle->InverseMass() <= 0) return;

float newSepVelocity = -separatingVelocity*restitution;

float accCousedSepVelocity = D3DXVec3Dot(&(particle->Acceleration()), &(contactNormal*iDuration));

if(accCousedSepVelocity < 0)
	{
	newSepVelocity += restitution*accCousedSepVelocity;
	if(newSepVelocity < 0) newSepVelocity = 0;
	}

particle->SetVelocity(particle->Velocity() + (newSepVelocity-separatingVelocity)*contactNormal);
}

//*****************************************************************************

void CContactData_ParticleImmovable::ResolveInterpenetration(float iDuration)
{
if(penetration <= 0 || particle->InverseMass() <= 0) return;

particle->SetPosition(particle->Position() + contactNormal*penetration);
}

//*****************************************************************************

float CContactData_ParticleImmovable::CalculateSeparatingVelocity()
{
return D3DXVec3Dot(&(particle->Velocity()), &contactNormal);
}

//*****************************************************************************

float CContactData_ParticleImmovable::CalculateIterpenetration()
{
D3DXVECTOR3 distanceMoved = particle->Position() - initialPosition;
float movedLength = D3DXVec3Length(&distanceMoved);

if(movedLength == 0.0f) return penetration;

D3DXVec3Normalize(&distanceMoved, &distanceMoved);
float movedInNormal = D3DXVec3Dot(&distanceMoved, &contactNormal);

return penetration - movedInNormal*movedLength;
}

//*****************************************************************************