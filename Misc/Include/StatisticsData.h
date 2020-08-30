///////////////////////////////////////////////////////////
//  StatisticsData.h
//  Created on:      11-08-2009
//  Last modified:   11-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_STATISTICSDATA_H
#define REGINA_STATISTICSDATA_H

#include <deque>
#include <time.h>
using namespace std;

namespace Regina
{

class CStatisticsData
{
private:
	float			beginTime;
	deque<float>	records;
	static const unsigned maxRecords = 10;

	
public:
	CStatisticsData() : beginTime(0) {}

	float GetAverage();
	float GetLast();
	void  Begin();
	float End();
	void  Clear();

};

}


#endif