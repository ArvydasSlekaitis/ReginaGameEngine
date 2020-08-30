/*
    CFontManager.cpp - Contains class CFontManager implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CFontManager.h>
using namespace Regina::UI;


//*****************************************************************************

CFontManager::CFontManager() : inited(false), state(e_normal)
	{
	}

//*****************************************************************************

CFontManager::~CFontManager()
	{
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

CFont* CFontManager::GetFont(CFontDefinition& iFontDefinition)
  	{
	map<wstring, CFont*>::iterator it = fontMap.find(iFontDefinition.Name());

	if(it!=fontMap.end())
		{
		return it->second;
		}
	else
		{
		assert(inited == true && L"CFontManager::GetFont - Cannot create new font becouse font manager is not inited. Call Init first.");
		CFont* font = new CFont(device, iFontDefinition.Facename(), iFontDefinition.Height(), iFontDefinition.Weight(), iFontDefinition.Italic());
		fontMap.insert(make_pair(font->Name(), font));
		fontVector.push_back(font);
		return font;
		}
	}

//*****************************************************************************

bool CFontManager::ExistFont(CFontDefinition& iFontDefinition)
  	{
	return fontMap.find(iFontDefinition.Name())!=fontMap.end();
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

