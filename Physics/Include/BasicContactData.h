///////////////////////////////////////////////////////////
//  BasicContactData.h
//  Created on:      29-07-2009
//  Last modified:   29-07-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_BASICCONTACTDATA_H
#define REGINA_BASICCONTACTDATA_H

#include <d3dx9.h>
#include <assert.h>
#include <vector>
using namespace std;

namespace Regina
{

class CBasicContactData
{
protected:
	D3DXVECTOR3		contactPoint;
	D3DXVECTOR3		contactNormal;
	float 			penetration;
	float			restitution;

public:
	CBasicContactData(D3DXVECTOR3 iContactPoint=D3DXVECTOR3(0, 0, 0), D3DXVECTOR3 iContactNormal = D3DXVECTOR3(0, 0, 0), float iPenetration = 0.0f, float iRestitution = 0.0f) : penetration(iPenetration), contactPoint(iContactPoint), contactNormal(iContactNormal), restitution(iRestitution) {}
	virtual ~CBasicContactData(){}
	void	SetContactPoint(D3DXVECTOR3 iContactPoint) 	{ contactPoint = iContactPoint; }
	void 	SetContactNormal(D3DXVECTOR3 iContactNormal){ contactNormal = iContactNormal; }
	void 	SetRestitution(float iRestitution)			{ restitution = iRestitution; }
	void 	SetPenetration(float iPenetration)			{ penetration = iPenetration; }

	D3DXVECTOR3	ContactPoint()	const { return contactPoint; }
	D3DXVECTOR3 ContactNormal()	const { return contactNormal; }
	float 		Penetration()	const { return penetration; }
	float		Restitution()	const { return restitution; }
};

}

#endif
