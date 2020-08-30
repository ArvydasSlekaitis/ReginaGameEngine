/*
    CTextureManager.cpp - Contains class CTextureManager implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CTextureManager.h>
using namespace Regina::Graphics;


//*****************************************************************************

CTextureManager::~CTextureManager()
	{
	if(device!=NULL)
		device->Release();
	device = NULL;

	inited = false;

	Clear();
	}

//*****************************************************************************

CTextureManager* CTextureManager::Instance()
  	{
	static CTextureManager inst;
	return &inst;
	}

//*****************************************************************************

void CTextureManager::Clear()
  	{
	map<wstring, C2DTexture*>::iterator	it = texture2D.begin();
	while(it!=texture2D.end())
		{
		delete it->second; 
		it++;
		}

	map<wstring, CCubeTexture*>::iterator it2 = textureCube.begin();
	while(it2!=textureCube.end())
		{
		delete it2->second; 
		it2++;
		}

	texture2D.clear();
	textureCube.clear();
	}

//*****************************************************************************

void CTextureManager::Init(LPDIRECT3DDEVICE9 iDevice)
 	{
	if(inited == false)
		{
		if(iDevice == NULL)
			throw invalid_argument("CTextureManager::Init - Argument iDevice = NULL");

		device = iDevice;
		device->AddRef();
		inited = true;
		}
	}

//*****************************************************************************

void CTextureManager::Load2D(const wstring& iName, const unsigned iMipLevels)
  	{
	map<wstring, C2DTexture*>::iterator it = texture2D.find(iName);

	if(it==texture2D.end())
		{
		assert(inited == true && L"CTextureManager::Load2D - Cannot create new texture becouse texture manager is not inited. Call Init first.");

		C2DTexture* texture(NULL);

		try
			{
			texture = new C2DTexture(device, iName, iMipLevels);
			}
		catch(exception& iException)
			{
			return;
			}

		texture2D.insert(make_pair(texture->Name(), texture));
		}
	}

//*****************************************************************************

void CTextureManager::LoadCube(const wstring& iName, const unsigned iMipLevels)
  	{
	map<wstring, CCubeTexture*>::iterator it = textureCube.find(iName);

	if(it==textureCube.end())
		{
		assert(inited == true && L"CTextureManager::LoadCube - Cannot create new texture becouse texture manager is not inited. Call Init first.");

		CCubeTexture* texture(NULL);

		try
			{
			texture = new CCubeTexture(device, iName, iMipLevels);
			}
		catch(exception& iException)
			{
			return;
			}

		textureCube.insert(make_pair(texture->Name(), texture));
		}
	}

//*****************************************************************************

C2DTexture* CTextureManager::Get2D(const wstring& iName, const unsigned iMipLevels)
  	{
	map<wstring, C2DTexture*>::iterator it = texture2D.find(iName);

	if(it!=texture2D.end())
		{
		return it->second;
		}
	else
		{
		assert(inited == true && L"CTextureManager::Get2D - Cannot create new texture becouse texture manager is not inited. Call Init first.");

		C2DTexture* texture(NULL);

		try
			{
			texture = new C2DTexture(device, iName, iMipLevels);
			}
		catch(exception& iException)
			{
			return NULL;
			}

		texture2D.insert(make_pair(texture->Name(), texture));
		return texture;
		}
	}

//*****************************************************************************

CCubeTexture* CTextureManager::GetCube(const wstring& iName, const unsigned iMipLevels)
  	{
	map<wstring, CCubeTexture*>::iterator it = textureCube.find(iName);

	if(it!=textureCube.end())
		{
		return it->second;
		}
	else
		{
		assert(inited == true && L"CTextureManager::GetCube - Cannot create new texture becouse texture manager is not inited. Call Init first.");

		CCubeTexture* texture(NULL);

		try
			{
			texture = new CCubeTexture(device, iName, iMipLevels);
			}
		catch(exception& iException)
			{
			return NULL;
			}

		textureCube.insert(make_pair(texture->Name(), texture));
		return texture;
		}
	}

//*****************************************************************************

void CTextureManager::OnDestroyDevice()
  	{
	if(device!=NULL)
		device->Release();
	device = NULL;

	inited = false;
	}

//*****************************************************************************