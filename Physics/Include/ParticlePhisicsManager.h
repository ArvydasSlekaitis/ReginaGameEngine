///////////////////////////////////////////////////////////
//  ParticlePhisicsManager.h
//  Created on:      12-03-2008
//  Last modified:   18-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_PARTICLEPHISICSMANAGER_H
#define REGINA_PARTICLEPHISICSMANAGER_H

#include <deque>
#include <map>
#include <vector>
#include <string>
#include <exception>
using namespace std;

#include <RotatingParticlePhisics.h>
#include <FastAccessManager.h>

namespace Regina
{

class CParticlePhisicsManager : public TFastAccessManager<CSpritePhisics>
{
protected:
	virtual void Unregister(CSpritePhisics* iSpritePhisics) {}
	virtual void SetID(CSpritePhisics* iObject, const unsigned& iID) { iObject->id = iID; }

public:
	CParticlePhisicsManager(unsigned iMinID, unsigned iMaxID);
	~CParticlePhisicsManager() { Clear(); }

	CSpritePhisics* SpriteFromID(unsigned iID) { return ObjectFromID(iID); }
	CParticlePhisics* ParticleFromID(unsigned iID);
	CRotatingParticlePhisics* RotatingParticleFromID(unsigned iID);

public:

};


}

#endif
