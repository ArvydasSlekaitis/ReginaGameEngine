///////////////////////////////////////////////////////////
//  ContactResolverGroup.h
//  Created on:      26-03-2009
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_CONTACTRESOLVERGROUP_H
#define REGINA_CONTACTRESOLVERGROUP_H

#include <ContactData.h>

#include <d3dx9.h>
#include <assert.h>
#include <set>
#include <deque>
#include <vector>
using namespace std;

namespace Regina
{

class CContactResolverGroup
{
	set<unsigned>			id;
	deque<CContactData*>	contact;
	deque<CContactData*>	immovableContact;
	unsigned maxVelocityIterations;
	unsigned maxPenetrationIterations;
	const float	   maxPenetrationIterationsPerObject;
	const float	   maxVelocityIterationsPerObject;

	void ResolveInterpenetration(float iDuration);
	void ResolveVelocity(float iDuration);
	void ResolveImmovable(float iDuration);
	void RemoveDuplicatesInRemovible();

public:
	CContactResolverGroup(const float& iMaxPenetrationIterationsPerObject, const float& iMaxVelocityIterationsPerObject) : maxVelocityIterations(0), maxPenetrationIterations(0), maxPenetrationIterationsPerObject(iMaxPenetrationIterationsPerObject), maxVelocityIterationsPerObject(iMaxVelocityIterationsPerObject) {}
	~CContactResolverGroup();
	void Add(CContactData* iContact);
	void Transfer(CContactResolverGroup* iContactResolverGroup);
	bool ExistID(unsigned iID);
	void Resolve(float iDuration);
	deque<CContactData*> Contact() { return contact; };

	void SetMaxVelocityIterations(const unsigned& iMaxVelocityIterations) { maxVelocityIterations = iMaxVelocityIterations; }
	void SetMaxPenetrationIterations(const unsigned& iMaxPenetrationIterations) { maxPenetrationIterations = iMaxPenetrationIterations; }
};

}

#endif
