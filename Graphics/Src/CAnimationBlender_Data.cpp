///////////////////////////////////////////////////////////
//  CAnimationBlender_Data.cpp
//  Created on:      29-11-2009
//  Last modified:   29-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CAnimationBlender_Data.h>
using namespace Regina;


//*****************************************************************************

CAnimationBlender_Data::~CAnimationBlender_Data()
	{
	if(animationController!=NULL)
		animationController->Release();
	animationController = NULL;

	for(unsigned i=0; i<animationVector.size(); i++)
		delete animationVector[i];

	animationVector.clear();
	animationMap.clear();
	}

//*****************************************************************************

CAnimationBlender_Data::CAnimationBlender_Data(LPD3DXANIMATIONCONTROLLER iAnimationController) : animationController(NULL), modified(true)
  	{
	if(iAnimationController == NULL)
		throw invalid_argument("CAnimationBlender_Data::CAnimationBlender_Data - argument iAnimationController == NULL");

	animationController = iAnimationController;
	animationController->AddRef();

	CreateAnimationSets();
	}

//*****************************************************************************

void CAnimationBlender_Data::CreateAnimationSet(const string& iName)
  	{
	CAnimationSet* set = new CAnimationSet(animationController, iName);
	animationVector.push_back(set);
	animationMap.insert(make_pair(iName, set));
	}

//*****************************************************************************

void CAnimationBlender_Data::CreateAnimationSets()
  	{
	for(unsigned i=0; i<animationController->GetNumAnimationSets(); i++)
		{
		LPD3DXANIMATIONSET animSet(NULL);
		animationController->GetAnimationSet(i, &animSet);
		CreateAnimationSet(animSet->GetName());
		}
	}

//*****************************************************************************

void CAnimationBlender_Data::Update(const float& iTime)
  	{
	if(Modified() == true)
		{
		UpdateTracks();
		SetModified(false);
		}
	
	for(unsigned i=0; i<animationVector.size(); i++)
		if(animationVector[i]->Enabled() && animationVector[i]->Weight()>0)
			animationVector[i]->Update(iTime);
	}

//*****************************************************************************

void CAnimationBlender_Data::EnableAll()
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		animationVector[i]->Enable();

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::DisableAll()
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		animationVector[i]->Enable();

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::EnableLoopingAll()
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		animationVector[i]->EnableLooping();

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::DisableLoopingAll()
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		animationVector[i]->DisableLooping();

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::SetAllPosition(const float& iPosition)
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		animationVector[i]->SetPosition(iPosition);

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::SetAllSpeed(const float& iSpeed)
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		animationVector[i]->SetSpeed(iSpeed);

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::SetAllWeight(const float& iWeight)
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		animationVector[i]->SetWeight(iWeight);

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::AddAllWeight(const float& iWeight)
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		animationVector[i]->AddWeight(iWeight);

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::SetDisabledPosition(const float& iPosition)
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		if(animationVector[i]->Enabled() == false)
			animationVector[i]->SetPosition(iPosition);

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::SetDisabledSpeed(const float& iSpeed)
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		if(animationVector[i]->Enabled() == false)
			animationVector[i]->SetSpeed(iSpeed);

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::SetDisabledWeight(const float& iWeight)
  	{
	for(unsigned i=0; i<animationVector.size(); i++)
		if(animationVector[i]->Enabled() == false)
			animationVector[i]->SetWeight(iWeight);

	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::SetSpeed(const string& iAnimationSetName, const float& iSpeed)
  	{
	AnimationSet(iAnimationSetName)->SetSpeed(iSpeed);
	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::SetPosition(const string& iAnimationSetName, const float& iPosition)
  	{
	AnimationSet(iAnimationSetName)->SetPosition(iPosition);
	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::SetWeight(const string& iAnimationSetName, const float& iWeight)
  	{
	AnimationSet(iAnimationSetName)->SetWeight(iWeight);
	SetModified(true);
	}

//*****************************************************************************

CAnimationSet* CAnimationBlender_Data::AnimationSet(const string& iAnimationSetName)
  	{
	map<string, CAnimationSet*>::iterator it = animationMap.find(iAnimationSetName);
	if(it==animationMap.end())
		throw invalid_argument("CAnimationBlender_Data::AnimationSet - such set does not exist - argument iAnimationSetName");
	return it->second;
	}

//*****************************************************************************

void CAnimationBlender_Data::Enable(const string& iAnimationSetName)
  	{
	AnimationSet(iAnimationSetName)->Enable();
	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::Disable(const string& iAnimationSetName)
  	{
	AnimationSet(iAnimationSetName)->Disable();
	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::EnableLooping(const string& iAnimationSetName)
  	{
	AnimationSet(iAnimationSetName)->EnableLooping();
	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::DisableLooping(const string& iAnimationSetName)
  	{
	AnimationSet(iAnimationSetName)->DisableLooping();
	SetModified(true);
	}

//*****************************************************************************

void CAnimationBlender_Data::UpdateTracks()
	{
	const unsigned maxTracks = min(animationController->GetMaxNumTracks(), animationVector.size());

	for(unsigned i=0; i<maxTracks; i++)
		animationController->SetTrackEnable( i, false );

	unsigned trackIndex = 0;

	for(unsigned i=0; i<animationVector.size(); i++)
		if(animationVector[i]->Enabled() && animationVector[i]->Weight()>0)
			{
			animationVector[i]->SetTrack(trackIndex);
			trackIndex++;
			}
	}

//*****************************************************************************