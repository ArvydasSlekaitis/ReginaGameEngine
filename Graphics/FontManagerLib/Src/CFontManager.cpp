/*
    CFontManager.cpp - Contains class CFontManager implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CFontManager.h>
using namespace Regina::Graphics;


//*****************************************************************************

CFontManager* CFontManager::Instance()
	{
	static CFontManager manager;
	return &manager;
	}

//*****************************************************************************

CFontManager::~CFontManager()
	{
	if(device!=NULL)
		device->Release();
	device = NULL;

	Clear();
	}

//*****************************************************************************

void CFontManager::Clear()
  	{
	for(unsigned i=0; i<fontVector.size(); i++)
		delete fontVector[i];

	fontMap.clear();
	fontVector.clear();
	}

//*****************************************************************************

CFont* CFontManager::GetFont(const wstring& iFacename, const unsigned& iHeight, const unsigned& iWeight, const bool& iItalic)
  	{
	CFontDefinition fontDefinition(iFacename, iHeight, iWeight, iItalic);
	map<wstring, CFont*>::iterator it = fontMap.find(fontDefinition.Name());

	if(it!=fontMap.end())
		{
		return it->second;
		}
	else
		{
		assert(inited == true && L"CFontManager::GetFont - Cannot create new font becouse font manager is not inited. Call Init first.");
		CFont* font = new CFont(device, iFacename, iHeight, iWeight, iItalic);
		fontMap.insert(make_pair(font->Name(), font));
		fontVector.push_back(font);
		return font;
		}
	}

//*****************************************************************************

void CFontManager::LoadFont(const wstring& iFacename, const unsigned& iHeight, const unsigned& iWeight, const bool& iItalic)
  	{
	CFontDefinition fontDefinition(iFacename, iHeight, iWeight, iItalic);
	map<wstring, CFont*>::iterator it = fontMap.find(fontDefinition.Name());

	if(it==fontMap.end())
		{
		assert(inited == true && L"CFontManager::LoadFont - Cannot create new font becouse font manager is not inited. Call Init first.");
		CFont* font = new CFont(device, iFacename, iHeight, iWeight, iItalic);
		fontMap.insert(make_pair(font->Name(), font));
		fontVector.push_back(font);
		}
	}

//*****************************************************************************

void CFontManager::Init(LPDIRECT3DDEVICE9 iDevice)
  	{
	if(inited == false)
		{
		if(iDevice == NULL)
			throw invalid_argument("CFontManager::Init - argument iDevice = NULL");

		device = iDevice;
		device->AddRef();
		inited = true;
		state = e_normal;
		}
	}

//*****************************************************************************

void CFontManager::OnDestroyDevice()
  	{
	for(unsigned i=0; i<fontVector.size(); i++)
		fontVector[i]->OnDestroyDevice();

	if(device != NULL)
		device->Release();
	device = NULL;
	inited = false;
	}

//*****************************************************************************

void CFontManager::OnLostDevice()
  	{
	if(state == e_normal || state == e_reset)
		for(unsigned i=0; i<fontVector.size(); i++)
			fontVector[i]->OnLostDevice();
	state = e_lost;
	}

//*****************************************************************************

void CFontManager::OnResetDevice()
  	{
	if(state == e_normal || state == e_lost)
		for(unsigned i=0; i<fontVector.size(); i++)
			fontVector[i]->OnResetDevice();
	state = e_reset;
	}

//*****************************************************************************

