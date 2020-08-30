///////////////////////////////////////////////////////////
//  Statistics.cpp
//  Created on:      11-08-2009
//  Last modified:   11-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Statistics.h>
using namespace Regina;

//*****************************************************************************

CStatistics::CStatistics()
	{
	#ifdef NDEBUG
	enabled = false;
	#endif
	#ifndef NDEBUG
	enabled = true;
	#endif
	}

//*****************************************************************************

CStatistics* CStatistics::Instance()
	{
	static CStatistics statistics;
	return &statistics;
	}


//*****************************************************************************

void CStatistics::Save(const string& iFilename)
	{
	ofstream file(iFilename.c_str());

	map<string, CStatisticsData>::iterator begin = data.begin();
	while(begin!=data.end())
		{
		file << begin->first << ": " << begin->second.GetAverage() << endl;
		begin++;
		}
	}

//*****************************************************************************

void CStatistics::Begin(const string& iName)
	{
	if(enabled == true)
		{
		map<string, CStatisticsData>::iterator begin = data.find(iName);

		if(begin!=data.end())
			begin->second.Begin();
		else
			{
			CStatisticsData stat;
			stat.Begin();
			data.insert(make_pair(iName, stat));
			}
		}
	}

//*****************************************************************************

float CStatistics::End(const string& iName)
	{
		if(enabled == true)
		{
		map<string, CStatisticsData>::iterator begin = data.find(iName);

		if(begin!=data.end())
			return begin->second.End();
		else
			{
			data.insert(make_pair(iName, CStatisticsData()));
			return 0;
			}
			}
		else
			return 0;
	}

//*****************************************************************************

void CStatistics::Clear()
	{
	map<string, CStatisticsData>::iterator begin = data.begin();
	while(begin!=data.end())
		{
		begin->second.Clear();
		begin++;
		}
	}

//*****************************************************************************

float CStatistics::GetAverage(const string& iName)
	{
		if(enabled == true)
		{
		map<string, CStatisticsData>::iterator begin = data.find(iName);

		if(begin!=data.end())
			return begin->second.GetAverage();
		else
			{
			data.insert(make_pair(iName, CStatisticsData()));
			return 0;
			}
			}
		else
			return 0;
	}

//*****************************************************************************

float CStatistics::GetLast(const string& iName)
	{
	if(enabled == true)
		{
		map<string, CStatisticsData>::iterator begin = data.find(iName);

		if(begin!=data.end())
			return begin->second.GetLast();
		else
			{
			data.insert(make_pair(iName, CStatisticsData()));
			return 0;
			}
		}
	else
		return 0;
	}

//*****************************************************************************
