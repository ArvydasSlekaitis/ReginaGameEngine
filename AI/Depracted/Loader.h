///////////////////////////////////////////////////////////
//  Loader.h
//  Created on:      25-07-2008
//  Last modified:   12-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_LOADER_H
#define REGINA_LOADER_H

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
using namespace std;

#include <BaseEntity.h>
#include <EntityManager.h>

namespace Regina
{

class CLoader
{
vector<string>& LoadSubset(ifstream &iFile);
CLoader(){}

public:
static CLoader* Instance();
void Load(const string& iFileName);

};

#define Loader CLoader::Instance()

}

#endif
