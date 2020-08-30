///////////////////////////////////////////////////////////
//  ContactResolver.h
//  Created on:      12-03-2009
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_CONTACTRESOLVER_H
#define REGINA_CONTACTRESOLVER_H

#include <assert.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#include <ContactResolverGroup.h>
#include <ParticlePhisics.h>
#include <ContactData.h>
#include <Threads.h>
#include <Settings.h>

namespace Regina
{

class CContactResolver
{
	deque<CContactResolverGroup*>	group;
	deque<CContactData*>			singleImmovableContact;
	set<unsigned>					registeredID;

	void GetPositionList(const unsigned& iID, set<unsigned>& oPositionInGroup);
	void GetSingleImmovableContactPositionList(const unsigned& iID, set<unsigned>& oPositions);
	void RegisterID(const unsigned& iID);
	void RegisterID(vector<unsigned>::iterator iBegin, vector<unsigned>::iterator iEnd);
	void ResolveSingleImmovableContacts(float iDuration);


public:
	CContactResolver() {}
	~CContactResolver(){ Clear(); }

	void Resolve(float iDuration);
	void Clear();
	void AddContact(CContactData* iContact);
	void AddContact(vector<CContactData*>::iterator iBegin, vector<CContactData*>::iterator iEnd);
};

}

#endif
