///////////////////////////////////////////////////////////
//  Loader.cpp
//  Created on:      25-07-2008
//  Last modified:   12-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#include <Loader.h>
using namespace Regina;

//*****************************************************************************

CLoader* CLoader::Instance()
	{
	static CLoader loader;
	return &loader;
	}

//*****************************************************************************

void CLoader::Load(const string& iFileName)
	{
	ifstream file(iFileName.c_str());

	if(file.is_open() == false)
		throw runtime_error("Loader::Load - Cannot open specified file");
	
	while(!file.eof())
		{
		string tmpLine;
		string objectType;
		getline(file, tmpLine);
		istringstream line(tmpLine);
		line >> objectType;
		
		if(objectType == "Entity")
			{
			unsigned entityType;
			line >> entityType;

			CBaseEntity* entity = EntityManager->CreateEntity(entityType, false);
			if(entity!=NULL)
				{
				entity->Load(LoadSubset(file));
				EntityManager->Add(entity);
				} 
			else
				throw runtime_error("Loader::Load - Cannot create new entity (Out of memmory?)");
			}
		}
	}

//*****************************************************************************

vector<string>& CLoader::LoadSubset(ifstream &iFile)
	{
	string tmpLine;
	getline(iFile, tmpLine);
	vector<string> subset;

	while(true)
		{
		if(iFile.eof() == true)
			throw runtime_error("Loader::LoadSubset - File format is damaged");

		getline(iFile, tmpLine);
		istringstream line(tmpLine);
		string type;
		line >> type;
		
		if(type != "}")
			subset.push_back(tmpLine);
		else
			break;
		}
	return subset;
	}

//*****************************************************************************


