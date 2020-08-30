///////////////////////////////////////////////////////////
//  Functions_Text.h
//  Created on:      23-08-2009
//  Last modified:   23-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_FUNCTIONS_TEXT_H
#define REGINA_FUNCTIONS_TEXT_H


#include <vector>
#include <exception>
#include <fstream>
#include <sstream>
using namespace std;


namespace Regina
{

//*****************************************************************************

static vector<string> LoadSubset(ifstream &iFile)
	{
	string tmpLine;
	getline(iFile, tmpLine);
	vector<string> subset;

	unsigned numNewBranch = 1;

	while(true)
		{
		if(iFile.eof() == true)
			throw runtime_error("LoadSubset - File format is damaged");

		getline(iFile, tmpLine);
		istringstream line(tmpLine);
		string type;
		line >> type;
		
		if(type == "}")
			{
			numNewBranch--;
			if(numNewBranch==0)
				break;
			}
		else
			if(type == "{")
				{
				numNewBranch++;
				}
		else
			subset.push_back(tmpLine);
		}
	return subset;
	}

//*****************************************************************************

static vector<string> LoadSubset(const vector<string>& iDefinition, const unsigned& beginPos, unsigned& newPos)
	{
	vector<string> subset;

	unsigned numNewBranch = 1;

	for(unsigned i=beginPos+1; i<iDefinition.size(); i++)
		{
		istringstream line(iDefinition[i]);
		string type;
		line >> type;
		
		if(type == "}")
			{
			numNewBranch--;
			if(numNewBranch==0)
				{
				newPos=i+1;
				break;
				}
			}
		else
			if(type == "{")
				{
				numNewBranch++;
				}
		else
			subset.push_back(iDefinition[i]);
		}
	return subset;
	}

//*****************************************************************************





}

#endif