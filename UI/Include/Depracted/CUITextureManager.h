/*
    CUITextureManager.h - Contains class CUITextureManager.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_CUITEXTUREMANAGER
#define REGINA_UI_CUITEXTUREMANAGER

#include <map>
#include <string>
using namespace std;

#include <CUITexture.h>

namespace Regina
{

namespace UI
{

class CUITextureManager
{
	map<wstring, CUITexture*>	textureMap;
	LPDIRECT3DDEVICE9			device;
	bool						inited;
	
	void Clear();

public:
	CUITextureManager();
	virtual ~CUITextureManager();

	void Init(LPDIRECT3DDEVICE9 iDevice);

	CUITexture* GetTexture(const wstring& iName);
	bool		ExistTexture(const wstring& iName);
	bool		Inited() const { return inited; }
	void		OnDestroyDevice();
};

}

}

#endif 