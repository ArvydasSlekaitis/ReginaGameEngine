///////////////////////////////////////////////////////////
//  StatisticsData.cpp
//  Created on:      11-08-2009
//  Last modified:   11-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <StatisticsData.h>
using namespace Regina;

//*****************************************************************************

float CStatisticsData::GetAverage()
	{
	float average = 0;
	
	if(records.size() > 0)
		{
		for(unsigned i=0; i<records.size(); i++)
			{
			average+=records[i];
			}
		average/=float(records.size());
		}

	return average;
	}

//*****************************************************************************

float CStatisticsData::GetLast()
	{
	if(records.size() > 0)
		return records[records.size()-1];
	else
		return 0;
	}

//*****************************************************************************

void CStatisticsData::Begin()
	{
	beginTime = clock();
	}

//*****************************************************************************

float CStatisticsData::End()
	{
	records.push_back(unsigned(clock()) - beginTime);
	if(records.size() > maxRecords)
		records.pop_front();
	return records[records.size()-1]; 
	}

//*****************************************************************************

void CStatisticsData::Clear()
	{
	beginTime = 0;
	records.clear();
	}

//*****************************************************************************
