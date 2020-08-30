///////////////////////////////////////////////////////////
//  PhisicsManager.cpp
//  Created on:      06-03-2008
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <PhisicsManager.h>
using namespace Regina;


//******************************************************************************

CPhisicsManager::CPhisicsManager() : minParticleID(1), maxParticleID(64000)
	{
	particlePhisicsManager = new CParticlePhisicsManager(1, 64000);
	contactResolver = new CContactResolver();
	forceRegistration = new CForceRegistration();
	phisicalLinkRegistration = new CPhisicalLinkRegistration();
	}

//******************************************************************************

CPhisicsManager::~CPhisicsManager()
	{
	Clear();
	delete particlePhisicsManager;
	delete contactResolver;
	delete forceRegistration;
	delete phisicalLinkRegistration;
	}

//******************************************************************************

CPhisicsManager* CPhisicsManager::Instance()
	{
	static CPhisicsManager phisicsMng;
	return &phisicsMng;
	}

//******************************************************************************

void CPhisicsManager::AddParticle(CSpritePhisics* iSpritePhisics)
	{
	assert(iSpritePhisics!=NULL);

	particlePhisicsManager->Add(iSpritePhisics);
	}

//******************************************************************************

void CPhisicsManager::RemoveParticle(unsigned iID)
	{
	if(iID>=minParticleID && iID<=maxParticleID)
		{
		particlePhisicsManager->Remove(iID);
		idToRemove.push_back(iID);
		return;
		}
	assert(false); //ID is out of bounds
	}

//******************************************************************************

bool CPhisicsManager::IDExist(unsigned iID) const
	{
	if(iID>=minParticleID && iID<=maxParticleID)
	return particlePhisicsManager->IDExist(iID);

	assert(false); //ID is out of bounds
	return false;
	}

//******************************************************************************

CSpritePhisics* CPhisicsManager::SpriteFromID(unsigned iID)
	{
	if(iID>=minParticleID && iID<=maxParticleID)
	return particlePhisicsManager->SpriteFromID(iID);

	throw invalid_argument("Such id does not exist");
	return NULL;
	}

//******************************************************************************

CParticlePhisics* CPhisicsManager::ParticleFromID(unsigned iID)
	{
	if(iID>=minParticleID && iID<=maxParticleID)
	return particlePhisicsManager->ParticleFromID(iID);

	throw invalid_argument("Such id does not exist");
	return NULL;
	}

//******************************************************************************

CRotatingParticlePhisics* CPhisicsManager::RotatingParticleFromID(unsigned iID)
	{
	if(iID>=minParticleID && iID<=maxParticleID)
	return particlePhisicsManager->RotatingParticleFromID(iID);

	throw invalid_argument("Such id does not exist");
	return NULL;
	}

//******************************************************************************

void CPhisicsManager::Update(const float& iDuration)
	{
	Update_RemoveRemovedParticles();
	Update_PhisicalLinks(iDuration);
	Update_ContactResolver(iDuration);
	Update_Forces(iDuration);
	Update_Particles(iDuration);
	}

//******************************************************************************

void CPhisicsManager::Clear()
	{
	contactResolver->Clear();
	phisicalLinkRegistration->Clear();
	forceRegistration->Clear();
	particlePhisicsManager->Clear();
	}

//******************************************************************************

void CPhisicsManager::Maintenance()
	{
	phisicalLinkRegistration->Maintanance();
	forceRegistration->Maintanance();
	}

//******************************************************************************

void CPhisicsManager::AddContact(CContactData* iContact)
	{
	contactResolver->AddContact(iContact);
	}

//******************************************************************************

void CPhisicsManager::AddContact(vector<CContactData*>::iterator iBegin, vector<CContactData*>::iterator iEnd)
	{
	contactResolver->AddContact(iBegin, iEnd);
	}

//******************************************************************************

void CPhisicsManager::AddForce(CForceGenerator* iForceGenerator)
	{
	forceRegistration->Add(iForceGenerator);
	}

//******************************************************************************

void CPhisicsManager::RemoveForce(CForceGenerator* iForceGenerator)
	{
	forceRegistration->Remove(iForceGenerator);
	}

//******************************************************************************

void CPhisicsManager::RemoveForce(CParticlePhisics* iObject, string iName)
	{
	forceRegistration->Remove(iObject, iName);
	}

//******************************************************************************

void CPhisicsManager::AddPhisicalLink(CPhisicalLink* iPhisicalLink)
	{
	phisicalLinkRegistration->Add(iPhisicalLink);
	}

//******************************************************************************

void CPhisicsManager::RemovePhisicalLink(CPhisicalLink* iPhisicalLink)
	{
	phisicalLinkRegistration->Remove(iPhisicalLink);
	}

//******************************************************************************

void CPhisicsManager::Update_RemoveRemovedParticles()
	{
	for(unsigned i=0; i<idToRemove.size(); i++)
		{
		forceRegistration->Unregister(idToRemove[i]);
		phisicalLinkRegistration->Unregister(idToRemove[i]);
		}
	idToRemove.clear();

	particlePhisicsManager->RemoveRemoved();
	}

//******************************************************************************

void CPhisicsManager::Update_PhisicalLinks(const float& iDuration)
	{
	phisicalLinkRegistration->Update(iDuration);
	}

//******************************************************************************

void CPhisicsManager::Update_ContactResolver(const float& iDuration)
	{
	contactResolver->Resolve(iDuration);
	}

//******************************************************************************

void CPhisicsManager::Update_Forces(const float& iDuration)
	{
	forceRegistration->Update(iDuration);
	}

//******************************************************************************

void CPhisicsManager::Update_Particles(const float& iDuration)
	{
	particlePhisicsManager->Update(iDuration);
	}

//******************************************************************************







