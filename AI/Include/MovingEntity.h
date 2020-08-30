///////////////////////////////////////////////////////////
//  MovingEntity.h
//  Created on:      07-09-2009
//  Last modified:   23-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_MOVINGENTITY_H
#define REGINA_MOVINGENTITY_H

#include <BaseEntity.h>

namespace Regina
{

class CMovingEntity : public CBaseEntity
{
	float			maxSpeed;
	
protected:
	void SetMaxSpeed(const float& iMaxSpeed) { maxSpeed = iMaxSpeed; }
	
public:
	CMovingEntity(const string iClassName = "MovingEntity", const unsigned iType = 0);
	virtual ~CMovingEntity(){}

	float			MaxSpeed()				const { return maxSpeed; }
	D3DXVECTOR3		Position()				const { return D3DXVECTOR3(Transformation()._41, Transformation()._42, Transformation()._43); }
	D3DXVECTOR2		PositionXZ()			const { return D3DXVECTOR2(Position().x, Position().z); }
	D3DXVECTOR2		VelocityXZ()			const { return D3DXVECTOR2(Velocity().x, Velocity().z); }

	virtual D3DXMATRIXA16	Transformation()			const = 0;
	virtual D3DXMATRIXA16	InverseTransformation()		const = 0;
	virtual D3DXVECTOR3		Velocity()					const = 0;
	virtual D3DXVECTOR2		Heading()					const = 0;
	virtual float			Speed()						const = 0;
	virtual float			Radius()					= 0;
	virtual float			RadiusXZ()					= 0;

	virtual void			SetPosition(const D3DXVECTOR3& iPosition) = 0;

};

}

#endif