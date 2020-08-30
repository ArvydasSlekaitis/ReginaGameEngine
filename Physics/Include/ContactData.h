///////////////////////////////////////////////////////////
//  ContactData.h
//  Created on:      29-08-2008
//  Last modified:   13-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_CONTACTDATA_H
#define REGINA_CONTACTDATA_H

#include <d3dx9.h>
#include <assert.h>
#include <vector>
using namespace std;

#include <BasicContactData.h>

namespace Regina
{

class CContactData : public CBasicContactData
{
protected:
	bool	immovable;

public:
	CContactData(bool iImmovable, D3DXVECTOR3 iContactNormal = D3DXVECTOR3(0, 0, 0), float iPenetration = 0.0f, float iRestitution = 0.0f, D3DXVECTOR3 iContactPoint = D3DXVECTOR3(0, 0, 0)) : CBasicContactData(iContactPoint, iContactNormal, iPenetration, iRestitution), immovable(iImmovable) {}
	CContactData(bool iImmovable, const CBasicContactData& iBasicContactData) : CBasicContactData(iBasicContactData), immovable(iImmovable) {}
	virtual ~CContactData(){}

	bool Immovable() const { return immovable; }

	virtual void Resolve(float iDuration) = 0;
	virtual void ResolveVelocity(float iDuration) = 0;
	virtual void ResolveInterpenetration(float iDuration) = 0;
	virtual float CalculateSeparatingVelocity() = 0;
	virtual float CalculateIterpenetration() = 0;
	virtual void FillAdditionalDependencys(vector<unsigned>& oAdditionalDependencys) = 0;
	virtual CContactData* GetImmovableVersion(const unsigned iExludedID) { return NULL; }
	
	unsigned GetAdditionalDependencysSize() { vector<unsigned> dep; FillAdditionalDependencys(dep); return dep.size(); }
	unsigned GetAdditionalDependencys(const unsigned& iPosition) { vector<unsigned> dep; FillAdditionalDependencys(dep); return dep[iPosition]; }
};

}

#endif
