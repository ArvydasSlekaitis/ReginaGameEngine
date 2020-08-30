/*
    CUITextureManager.cpp - Contains class CUITextureManager implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CUITextureManager.h>
using namespace Regina::UI;

//*****************************************************************************

CUITextureManager::CUITextureManager() : device(NULL), inited(false)
	{
	}

//*****************************************************************************

CUITextureManager::~CUITextureManager()
	{
	if(device!=NULL) 
		device->Release();
	device = NULL;

	inited = false;

	Clear();
	}

//*****************************************************************************

void CUITextureManager::Clear()
  	{
	map<wstring, CUITexture*>::iterator it = textureMap.begin();

	while(it!=textureMap.end())
		{
		delete it->second;
		it++;
		}
	textureMap.clear();
	}

//*****************************************************************************

CUITexture* CUITextureManager::GetTexture(const wstring& iName)
  	{
	map<wstring, CUITexture*>::iterator it = textureMap.find(iName);

	if(it!=textureMap.end())
		{
		return it->second;
		}
	else
		{
		assert(inited == true && L"CUITextureManager::GetTexture - Cannot create new texture becouse texture manager is not inited. Call Init first.");
		CUITexture* texture = new CUITexture(device, iName);
		textureMap.insert(make_pair(texture->Name(), texture));
		return texture;
		}
	}

//*****************************************************************************

bool CUITextureManager::ExistTexture(const wstring& iName)
  	{
	return textureMap.find(iName)!=textureMap.end();
	}

//*****************************************************************************

void CUITextureManager::Init(LPDIRECT3DDEVICE9 iDevice)
  	{
	if(inited == false)
		{
		if(iDevice == NULL)
			throw invalid_argument("CUITextureManager::Init - argument iDevice = NULL");

		device = iDevice;
		device->AddRef();
		inited = true;
		}
	}

//*****************************************************************************

void CUITextureManager::OnDestroyDevice()
	{
	if(device != NULL)
		device->Release();
	device = NULL;
	inited = false;
	}

//*****************************************************************************