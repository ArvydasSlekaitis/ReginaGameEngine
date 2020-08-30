///////////////////////////////////////////////////////////
//  ContactData_ParticleParticle.cpp
//  Created on:      12-03-2009
//  Last modified:   29-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <ContactData_ParticleParticle.h>
using namespace Regina;


//*****************************************************************************

CContactData_ParticleParticle::CContactData_ParticleParticle(CParticlePhisics* iParticle1, CParticlePhisics* iParticle2, D3DXVECTOR3 iContactNormal, float iPenetration, float iRestitution) : CContactData(false, iContactNormal, iPenetration, iRestitution)
	{
	assert(iParticle1!=NULL);
	assert(iParticle2!=NULL);
	assert(iParticle1!=iParticle2);
	particle[0] = iParticle1;
	particle[1] = iParticle2;
	initialPosition[0] = particle[0]->Position();
	initialPosition[1] = particle[1]->Position();
	}

//*****************************************************************************

CContactData_ParticleParticle::CContactData_ParticleParticle(CParticlePhisics* iParticle1, CParticlePhisics* iParticle2, const CBasicContactData& iBasicContactData) : CContactData(false, iBasicContactData)
	{
	assert(iParticle1!=NULL);
	assert(iParticle2!=NULL);
	assert(iParticle1!=iParticle2);
	particle[0] = iParticle1;
	particle[1] = iParticle2;
	initialPosition[0] = particle[0]->Position();
	initialPosition[1] = particle[1]->Position();
	}

//*****************************************************************************

void CContactData_ParticleParticle::Resolve(float iDuration)
{
ResolveVelocity(iDuration);
ResolveInterpenetration(iDuration);
}

//*****************************************************************************

void CContactData_ParticleParticle::ResolveVelocity(float iDuration)
{
float sepVelocity = CalculateSeparatingVelocity();

if(sepVelocity > 0) return;

float newSepVelocity = -sepVelocity*restitution;

float accCousedSepVelocity = D3DXVec3Dot(&(particle[0]->Acceleration() - particle[1]->Acceleration()), &(contactNormal*iDuration));

if(accCousedSepVelocity < 0)
	{
	newSepVelocity += restitution*accCousedSepVelocity;
	if(newSepVelocity < 0) newSepVelocity = 0;
	}

float deltaVelocity = newSepVelocity - sepVelocity;

float totalInverseMass = particle[0]->InverseMass() + particle[1]->InverseMass();

if(totalInverseMass <= 0) return;

float impulse = deltaVelocity/totalInverseMass;
D3DXVECTOR3 impulsePerIMass = contactNormal*impulse;

particle[0]->SetVelocity(particle[0]->Velocity() + impulsePerIMass*particle[0]->InverseMass());
particle[1]->SetVelocity(particle[1]->Velocity() - impulsePerIMass*particle[1]->InverseMass());
}

//*****************************************************************************

void CContactData_ParticleParticle::ResolveInterpenetration(float iDuration)
{
float tPenetration = CalculateIterpenetration();

if(tPenetration < 0) return;

float totalInverseMass = particle[0]->InverseMass() + particle[1]->InverseMass();

if(totalInverseMass <= 0) return;

D3DXVECTOR3 movePerIMass = contactNormal*(tPenetration/totalInverseMass);

particle[0]->SetPosition(particle[0]->Position() + movePerIMass*particle[0]->InverseMass());
particle[1]->SetPosition(particle[1]->Position() - movePerIMass*particle[1]->InverseMass());
}

//*****************************************************************************

float CContactData_ParticleParticle::CalculateSeparatingVelocity()
{
return D3DXVec3Dot(&(particle[0]->Velocity() - particle[1]->Velocity()), &(contactNormal));
}

//*****************************************************************************

float CContactData_ParticleParticle::CalculateIterpenetration()
{
D3DXVECTOR3 distanceMoved[2];
distanceMoved[0] = particle[0]->Position() - initialPosition[0];
distanceMoved[1] = particle[1]->Position() - initialPosition[1];

float movedLength[2];
movedLength[0] = D3DXVec3Length(&distanceMoved[0]);
movedLength[1] = D3DXVec3Length(&distanceMoved[1]);

if(movedLength[0] == 0.0f && movedLength[1] == 0.0f) return penetration;

D3DXVec3Normalize(&distanceMoved[0], &distanceMoved[0]);
D3DXVec3Normalize(&distanceMoved[1], &distanceMoved[1]);

float movedInNormal[2];
movedInNormal[0] = D3DXVec3Dot(&distanceMoved[0], &contactNormal);
movedInNormal[1] = D3DXVec3Dot(&distanceMoved[1], &contactNormal);

return penetration - movedInNormal[0]*movedLength[0] + movedInNormal[1]*movedLength[1];
}

//*****************************************************************************

CContactData* CContactData_ParticleParticle::GetImmovableVersion(const unsigned iExludedID)
{
CContactData* immovable(NULL);
if(particle[0]->ID()==iExludedID)
	{
	immovable = new CContactData_ParticleImmovable(particle[1]);
	immovable->SetContactNormal(-contactNormal);
	}
if(particle[1]->ID()==iExludedID) 
	{
	immovable = new CContactData_ParticleImmovable(particle[0]);
	immovable->SetContactNormal(contactNormal);
	}

if(immovable==NULL) return NULL;


immovable->SetContactPoint(contactPoint);
immovable->SetPenetration(CalculateIterpenetration());
immovable->SetRestitution(restitution);
return immovable;
}

//*****************************************************************************