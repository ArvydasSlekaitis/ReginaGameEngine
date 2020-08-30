///////////////////////////////////////////////////////////
//  CAnimationBlender.cpp
//  Created on:      29-11-2009
//  Last modified:   29-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <CAnimationBlender.h>
using namespace Regina;


//*****************************************************************************

CAnimationBlender::~CAnimationBlender()
	{

	}

//*****************************************************************************

CAnimationBlender::CAnimationBlender(CAnimationBlender_Data* iData) : data(NULL)
  	{
	if(iData == NULL)
		throw invalid_argument("CAnimationBlender::CAnimationBlender - argument CAnimationBlender_Data == NULL");

	data = iData;
	}

//*****************************************************************************

CAnimationBlender::CAnimationBlender(const CAnimationBlender& iBlender)
	{
	data = iBlender.data;
	}

//*****************************************************************************

void CAnimationBlender::Update(const float& iTime)
  	{
	data->Update(iTime);
	}

//*****************************************************************************

void CAnimationBlender::EnableAll()
  	{
	data->EnableAll();
	}

//*****************************************************************************

void CAnimationBlender::DisableAll()
  	{
	data->DisableAll();
	}

//*****************************************************************************

void CAnimationBlender::EnableLoopingAll()
  	{
	data->EnableLoopingAll();
	}

//*****************************************************************************

void CAnimationBlender::DisableLoopingAll()
  	{
	data->DisableLoopingAll();
	}

//*****************************************************************************

void CAnimationBlender::SetAllPosition(const float& iPosition)
  	{
	data->SetAllPosition(iPosition);
	}

//*****************************************************************************

void CAnimationBlender::SetAllSpeed(const float& iSpeed)
  	{
	data->SetAllSpeed(iSpeed);
	}

//*****************************************************************************

void CAnimationBlender::SetAllWeight(const float& iWeight)
  	{
	data->SetAllWeight(iWeight);
	}

//*****************************************************************************

void CAnimationBlender::AddAllWeight(const float& iWeight)
  	{
	data->AddAllWeight(iWeight);
	}

//*****************************************************************************

void CAnimationBlender::SetDisabledPosition(const float& iPosition)
  	{
	data->SetDisabledPosition(iPosition);
	}

//*****************************************************************************

void CAnimationBlender::SetDisabledSpeed(const float& iSpeed)
  	{
	data->SetDisabledSpeed(iSpeed);
	}

//*****************************************************************************

void CAnimationBlender::SetDisabledWeight(const float& iWeight)
  	{
	data->SetDisabledWeight(iWeight);
	}

//*****************************************************************************

void CAnimationBlender::SetSpeed(const string& iAnimationSetName, const float& iSpeed)
  	{
	data->SetSpeed(iAnimationSetName, iSpeed);
	}

//*****************************************************************************

void CAnimationBlender::SetPosition(const string& iAnimationSetName, const float& iPosition)
  	{
	data->SetPosition(iAnimationSetName, iPosition);
	}

//*****************************************************************************

void CAnimationBlender::SetWeight(const string& iAnimationSetName, const float& iWeight)
  	{
	data->SetWeight(iAnimationSetName, iWeight);
	}

//*****************************************************************************

void CAnimationBlender::Enable(const string& iAnimationSetName)
  	{
	data->Enable(iAnimationSetName);
	}

//*****************************************************************************

void CAnimationBlender::Disable(const string& iAnimationSetName)
  	{
	data->Disable(iAnimationSetName);
	}

//*****************************************************************************

void CAnimationBlender::EnableLooping(const string& iAnimationSetName)
  	{
	data->EnableLooping(iAnimationSetName);
	}

//*****************************************************************************

void CAnimationBlender::DisableLooping(const string& iAnimationSetName)
  	{
	data->DisableLooping(iAnimationSetName);
	}

//*****************************************************************************