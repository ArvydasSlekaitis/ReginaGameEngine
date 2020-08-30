///////////////////////////////////////////////////////////
//  CAnimationSet.h
//  Created on:      29-11-2009
//  Last modified:   29-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CANIMATIONSET_H
#define REGINA_CANIMATIONSET_H

#include <d3dx9.h>
#include <string>
using namespace std;


namespace Regina
{


class CAnimationSet
{
	const string name;

	LPD3DXANIMATIONCONTROLLER	animationController;
	LPD3DXANIMATIONSET			animationSet;

	float	position;
	float	weight;
	float	speed;
	bool	enabled;
	bool	loop;
	int		track;

private:
	LPD3DXANIMATIONSET			AnimationSet();
	int							Track() const { return track; }	

public:
	virtual ~CAnimationSet();

	CAnimationSet(LPD3DXANIMATIONCONTROLLER iAnimationController, const string& iName);

	string	Name()		const;
	float	Position()	const;
	float	Weight()	const;
	float	Speed()		const;
	bool	Enabled()	const;
	bool	Loop()		const;

	float LocalTime();

	void SetPosition(const float& iPosition);
	void SetSpeed(const float& iSpeed);
	void SetWeight(const float& iWeight);
	void AddWeight(const float& iWeight);
	void Enable();
	void Disable();
	void EnableLooping();
	void DisableLooping();

	void SetTrack(const unsigned& iTrack);
	void Update(const float& iTime);
};

}

#endif 