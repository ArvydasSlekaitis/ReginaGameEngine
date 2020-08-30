///////////////////////////////////////////////////////////
//  CAnimationBlender_Data.h
//  Created on:      29-11-2009
//  Last modified:   29-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CANIMATIONBLENDER_DATA_H
#define REGINA_CANIMATIONBLENDER_DATA_H

#include <vector>
#include <map>
using namespace std;

#include <CAnimationSet.h>

namespace Regina
{


class CAnimationBlender_Data
{
	map<string, CAnimationSet*> animationMap;
	vector<CAnimationSet*>		animationVector;
	LPD3DXANIMATIONCONTROLLER	animationController;
	bool						modified;

private:
	void CreateAnimationSet(const string& iName);
	void CreateAnimationSets();
	CAnimationSet* AnimationSet(const string& iAnimationSetName);
	bool Modified() const { return modified; }
	void SetModified(const bool& iModified) { modified = iModified; }
	void UpdateTracks();

public:
	virtual ~CAnimationBlender_Data();
	CAnimationBlender_Data(LPD3DXANIMATIONCONTROLLER iAnimationController);

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