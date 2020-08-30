///////////////////////////////////////////////////////////
//  Statistics.h
//  Created on:      11-08-2009
//  Last modified:   11-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STATISTICS_H
#define REGINA_STATISTICS_H

#include <string>
#include <map>
#include <fstream>
using namespace std;

#include <StatisticsData.h>
#include <assert.h>
namespace Regina
{

class CStatistics
{
private:
	map<string, CStatisticsData>	data;
	bool							enabled;

	CStatistics();

public:
	static CStatistics* Instance();

	void Enable() { enabled = true; }
	void Disable() { enabled = false; }	
	void Save(const string& iFilename);
	void Begin(const string& iName);
	float End(const string& iName);
	void Clear();

	float GetAverage(const string& iName);
	float GetLast(const string& iName);

};

#define Statistics CStatistics::Instance()


}


#endif