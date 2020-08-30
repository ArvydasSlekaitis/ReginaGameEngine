///////////////////////////////////////////////////////////
//  PhisicsManager.h
//  Created on:      06-03-2008
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PHISICSMANAGER_H
#define REGINA_PHISICSMANAGER_H

#include <stdexcept>
#include <vector>
using namespace std;

#include <ParticlePhisicsManager.h>
#include <RotatingParticlePhisics.h>
#include <ForceRegistration.h>
#include <PhisicalLinkRegistration.h>
#include <ContactResolver.h>

namespace Regina
{

class CPhisicsManager
{
private:
	vector<unsigned>			idToRemove;

	CParticlePhisicsManager*	particlePhisicsManager;
	CContactResolver*			contactResolver;
	CForceRegistration*			forceRegistration;
	CPhisicalLinkRegistration*	phisicalLinkRegistration;

	unsigned minParticleID;
	unsigned maxParticleID;

	CPhisicsManager();
	CPhisicsManager(const CPhisicsManager&);
	~CPhisicsManager();

public:
	static CPhisicsManager* Instance();

	void AddParticle(CSpritePhisics* iSpritePhisics);  //Warning! Calling this funtion, while all object with pre defined id is not loaded, may couse later loading artifacts!
	void AddContact(CContactData* iContact);
	void AddContact(vector<CContactData*>::iterator iBegin, vector<CContactData*>::iterator iEnd);
	void AddForce(CForceGenerator* iForceGenerator);
	void AddPhisicalLink(CPhisicalLink* iPhisicalLink);
	
	void RemoveParticle(unsigned iID);
	void RemoveForce(CForceGenerator* iForceGenerator);
	void RemoveForce(CParticlePhisics* iObject, string iName);
	void RemovePhisicalLink(CPhisicalLink* iPhisicalLink);
	
	bool IDExist(unsigned iID) const;

	CSpritePhisics* SpriteFromID(unsigned iID);
	CParticlePhisics* ParticleFromID(unsigned iID);
	CRotatingParticlePhisics* RotatingParticleFromID(unsigned iID);

	void Update(const float& iDuration);
	void Clear();
	void Maintenance();

	void SetMinIDForParticle(unsigned iMinParticleID) { assert(iMinParticleID>0);  minParticleID = iMinParticleID; }
	void SetMaxIDForParticle(unsigned iMaxParticleID) { assert(iMaxParticleID>minParticleID);  maxParticleID = iMaxParticleID; } 

	//Use if you are using custom update method
	void Update_RemoveRemovedParticles();
	void Update_PhisicalLinks(const float& iDuration);
	void Update_ContactResolver(const float& iDuration);
	void Update_Forces(const float& iDuration);
	void Update_Particles(const float& iDuration);

friend CParticlePhisicsManager;
};

#define PhisicsManager CPhisicsManager::Instance()


}

#endif
