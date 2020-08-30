///////////////////////////////////////////////////////////
//  CAnimationSet.cpp
//  Created on:      29-11-2009
//  Last modified:   29-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CAnimationSet.h>
using namespace Regina;


//*****************************************************************************

CAnimationSet::~CAnimationSet()
	{
	if(animationController!=NULL)
		animationController->Release();
	animationController = NULL;
	
	if(animationSet!=NULL)
		animationSet->Release();
	animationSet = NULL;
	}

//*****************************************************************************

CAnimationSet::CAnimationSet(LPD3DXANIMATIONCONTROLLER iAnimationController, const string& iName) : name(iName), animationController(NULL), animationSet(NULL), track(-1)
  	{
	if(iAnimationController == NULL)
		throw invalid_argument("CAnimationSet::CAnimationSet - argument iAnimationController == NULL");

	animationController = iAnimationController;
		animationController->AddRef();

	animationController->GetAnimationSetByName(name.c_str(), &animationSet);
	}

//*****************************************************************************

LPD3DXANIMATIONSET CAnimationSet::AnimationSet()
  	{
	return animationSet;
	}

//*****************************************************************************

string CAnimationSet::Name() const 
  	{
	return name;
	}

//*****************************************************************************

float CAnimationSet::Position() const 
  	{
	return position;
	}

//*****************************************************************************

float CAnimationSet::Weight() const 
  	{
	return weight;
	}

//*****************************************************************************

float CAnimationSet::Speed() const 
  	{
	return speed;
	}

//*****************************************************************************

bool CAnimationSet::Enabled() const 
  	{
	return enabled;
	}

//*****************************************************************************

bool CAnimationSet::Loop() const 
  	{
	return loop;
	}

//*****************************************************************************

void CAnimationSet::SetPosition(const float& iPosition)
  	{
	position = iPosition;
	}

//*****************************************************************************

void CAnimationSet::SetSpeed(const float& iSpeed)
  	{
	speed = iSpeed;
	}

//*****************************************************************************

void CAnimationSet::SetWeight(const float& iWeight)
  	{
	weight = iWeight;
	}

//*****************************************************************************

void CAnimationSet::AddWeight(const float& iWeight)
  	{
	weight+=iWeight;
	if(weight > 1) weight = 1;
	if(weight < 0) weight = 0;
	}

//*****************************************************************************

void CAnimationSet::Enable()
  	{
	enabled = true;
	}

//*****************************************************************************

void CAnimationSet::Disable()
  	{
	enabled = false;
	}

//*****************************************************************************

void CAnimationSet::EnableLooping()
  	{
	loop = true;
	}

//*****************************************************************************

void CAnimationSet::DisableLooping()
  	{
	loop = false;
	}

//*****************************************************************************

float CAnimationSet::LocalTime()
  	{
	return animationSet->GetPeriodicPosition(position);
	}

//*****************************************************************************

void CAnimationSet::Update(const float& iTime)
  	{
	if(Enabled() == true && Weight()>0 && Track()>=0)
		{
		position+=iTime*Speed();

		animationController->SetTrackSpeed( Track(), speed );
		animationController->SetTrackWeight( Track(), weight );
		animationController->SetTrackPosition(Track(), position);
		}
	}

//*****************************************************************************

void CAnimationSet::SetTrack(const unsigned& iTrack)
	{
	track = iTrack;
	animationController->SetTrackEnable(iTrack, true);
	animationController->SetTrackAnimationSet(iTrack, animationSet);		
	}

//*****************************************************************************