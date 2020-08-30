///////////////////////////////////////////////////////////
//  CSimpleXFileManager.cpp
//  Created on:      01-11-2009
//  Last modified:   05-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include "CSimpleXFileManager.h"
using namespace Regina;


//*****************************************************************************

CSimpleXFileManager* CSimpleXFileManager::Instance()
	{
	static CSimpleXFileManager xManager;
	return &xManager;
	}

//*****************************************************************************

CSimpleXFileManager::~CSimpleXFileManager()
	{
	if(device!=NULL)
		throw logic_error("CSimpleXFileManager::~CSimpleXFileManager - device was not released - Call ReleaseDevice first!");
	}

//*****************************************************************************

CSimpleXFileManager::CSimpleXFileManager() : device(NULL)
  	{
	}

//*****************************************************************************

CSimpleXFileManager::CSimpleXFileManager(CSimpleXFileManager&) : device(NULL)
  	{
	}

//*****************************************************************************

void CSimpleXFileManager::ReleaseDevice()
  	{
	//clear && release device
	Clear();
	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

void CSimpleXFileManager::Clear()
  	{
	map<string, CSimpleXFile*>::iterator it = simpleXFileMap.begin();
	while(it!=simpleXFileMap.end())
		{
		delete it->second;
		it++;
		}
	simpleXFileMap.clear();
	}

//*****************************************************************************

CSimpleXFile* CSimpleXFileManager::Create(const string& iName)
  	{
	if(device==NULL)
		throw logic_error("CSimpleXFileManager::Create - device was not initialised - Call Init first!");

	map<string, CSimpleXFile*>::iterator it = simpleXFileMap.find(iName);
	if(it!=simpleXFileMap.end())
		{
		return it->second;
		}
	else
		{
		CSimpleXFile* newX = new CSimpleXFile(device, iName);
		if(newX == NULL)
			throw Exception_OutOfMemmory("CSimpleXFileManager::Create - there is not enough free memmory for CSimpleXFile creating");

		simpleXFileMap.insert(make_pair(newX->Name(), newX));
		return newX;
		}
	}

//*****************************************************************************

CSimpleXFile* CSimpleXFileManager::Get(const string& iName)
  	{
	//If does not exist, creates it
	CSimpleXFile* newX = Create(iName);
	assert(newX!=NULL);
	
	return  newX;
	}

//*****************************************************************************

void CSimpleXFileManager::Init(LPDIRECT3DDEVICE9 iDevice)
  	{
	//Initialize manager - must be called !
	device = iDevice;
	device->AddRef();
	}

//*****************************************************************************