///////////////////////////////////////////////////////////
//  Settings.h
//  Created on:      08-09-2009
//  Last modified:   08-09-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_SETTINGS_H
#define REGINA_SETTINGS_H

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


#include <assert.h>
namespace Regina
{

class CSettings
{
private:
	map<string, float>	data;
	
	CSettings();

public:
	static CSettings* Instance();

	void Save(const string& iFilename);
	void Load(const string& iFilename);

	void	SetParameter(const string& iParameterName, const float& iParameterValue);
	float	GetParameter(const string& iParameterName);
	
};

#define Settings CSettings::Instance()


}


#endif