///////////////////////////////////////////////////////////
//  CAnimationBlender.h
//  Created on:      29-11-2009
//  Last modified:   29-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CANIMATIONBLENDER_H
#define REGINA_CANIMATIONBLENDER_H

#include <CAnimationBlender_Data.h>

namespace Regina
{


class CAnimationBlender
{
	CAnimationBlender_Data* data;
public:
	virtual ~CAnimationBlender();

	CAnimationBlender(CAnimationBlender_Data* iData);
	CAnimationBlender(const CAnimationBlender& iBlender);

	void Update(const float& iTime);
	void EnableAll();
	void DisableAll();
	void EnableLoopingAll();
	void DisableLoopingAll();
	void SetAllPosition(const float& iPosition);
	void SetAllSpeed(const float& iSpeed);
	void SetAllWeight(const float& iWeight);
	void AddAllWeight(const float& iWeight);
	void SetDisabledPosition(const float& iPosition);
	void SetDisabledSpeed(const float& iSpeed);
	void SetDisabledWeight(const float& iWeight);
	void SetSpeed(const string& iAnimationSetName, const float& iSpeed);
	void SetPosition(const string& iAnimationSetName, const float& iPosition);
	void SetWeight(const string& iAnimationSetName, const float& iWeight);
	void Enable(const string& iAnimationSetName);
	void Disable(const string& iAnimationSetName);
	void EnableLooping(const string& iAnimationSetName);
	void DisableLooping(const string& iAnimationSetName);

};

}

#endif 