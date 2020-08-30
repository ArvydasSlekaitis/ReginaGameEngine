///////////////////////////////////////////////////////////
//  CSimpleXFileManager.h
//  Created on:      01-11-2009
//  Last modified:   05-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CSIMPLEXFILEMANAGER_H
#define REGINA_CSIMPLEXFILEMANAGER_H

#include <map>
#include <string>
using namespace std;

#include <CSimpleXFile.h>

namespace Regina
{


class CSimpleXFileManager
{
	LPDIRECT3DDEVICE9 device;
	map<string, CSimpleXFile*> simpleXFileMap;

private:
	CSimpleXFileManager();
	CSimpleXFileManager(CSimpleXFileManager&);

public:
	virtual ~CSimpleXFileManager();
	static CSimpleXFileManager* Instance();

	void ReleaseDevice();
	void Clear();
	CSimpleXFile* Create(const string& iName);
	CSimpleXFile* Get(const string& iName);
	void Init(LPDIRECT3DDEVICE9 iDevice);

};

#define SimpleXFileManager CSimpleXFileManager::Instance()

}

#endif 