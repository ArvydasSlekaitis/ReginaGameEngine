///////////////////////////////////////////////////////////
//  Settings.cpp
//  Created on:      08-09-2009
//  Last modified:   08-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Settings.h>
using namespace Regina;

//*****************************************************************************

CSettings::CSettings()
	{
	//Default settings
	SetParameter("MaxIterationsForStaticObjectGridCreation", 1000);
	SetParameter("MaxIterationsForWallsGridCreation", 1000);
	SetParameter("MaxIterationsForDoorsGridCreation", 1000);
	SetParameter("MaxIterationsForParticlePhisicsGridCreation", 50);
	SetParameter("MaxIterationsForDynamicObjectGridCreation", 50);
	SetParameter("DynamicObjectHorizontalGridCreationEnabled", 1);
	SetParameter("DynamicObjectVerticalGridCreationEnabled", 1);
	SetParameter("DynamicObjectHorizontalVerticalGridCreationEnabled", 1);
	SetParameter("ParticlePhisicsHorizontalGridCreationEnabled", 1);
	SetParameter("ParticlePhisicsVerticalGridCreationEnabled", 1);
	SetParameter("ParticlePhisicsHorizontalVerticalGridCreationEnabled", 1);
	SetParameter("MaxContactResolverPenetrationIterationsPerObject", 3);
	SetParameter("MaxContactResolverVelocityIterationsPerObject", 3);
	SetParameter("MaxContactResolverVelocityIterations", 100);
	SetParameter("MaxContactResolverPenetrationIterations", 100);
	SetParameter("MaxEntityDetectionBoxLength", 10);
	}

//*****************************************************************************

CSettings* CSettings::Instance()
	{
	static CSettings settings;
	return &settings;
	}


//*****************************************************************************

void CSettings::Save(const string& iFilename)
	{
	ofstream file(iFilename.c_str());

	map<string, float>::iterator begin = data.begin();
	while(begin!=data.end())
		{
		file << begin->first << " " << begin->second << endl;
		begin++;
		}
	}

//*****************************************************************************

void CSettings::Load(const string& iFilename)
	{
	ifstream file(iFilename.c_str());

	if(file.is_open() == false)
		throw runtime_error("CSettings::Load - Cannot open specified file");	

	while(!file.eof())
		{
		string tmpLine;
		getline(file, tmpLine);
		istringstream line(tmpLine);

		string	settingName;
		float	settingValue;
		line >> settingName >> settingValue;
		if(settingName.size() > 0)
		SetParameter(settingName, settingValue);
		}		

	}

//*****************************************************************************

void CSettings::SetParameter(const string& iParameterName, const float& iParameterValue)
	{
	map<string, float>::iterator iter = data.find(iParameterName);
	if(iter!=data.end())
		{
		iter->second = iParameterValue; 
		}
	else
		{
		data.insert(make_pair(iParameterName, iParameterValue));
		}
	}

//*****************************************************************************

float CSettings::GetParameter(const string& iParameterName)
	{
	map<string, float>::iterator iter = data.find(iParameterName);
	if(iter!=data.end())
		{
		return iter->second;
		}
	else
		{
		throw invalid_argument("CSettings::GetParameter - argumet iParameterName - such parameter does not exist");	
		}
	}

//*****************************************************************************
