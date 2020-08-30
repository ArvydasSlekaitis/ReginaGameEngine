/*
    CTextureManager.h - Contains class CTextureManager.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_GRAPHICS_CTEXTUREMANAGER_H
#define REGINA_GRAPHICS_CTEXTUREMANAGER_H

#include <map>
using namespace std;

#include <CTexture.h>
#include <CCubeTexture.h>
#include <C2DTexture.h>

namespace Regina
{

namespace Graphics
{

class CTextureManager
{
	map<wstring, C2DTexture*>	texture2D;
	map<wstring, CCubeTexture*> textureCube;
	LPDIRECT3DDEVICE9			device;
	bool						inited;

	CTextureManager(const CTextureManager&) {}
	void Clear();

public:
	CTextureManager() : device(NULL), inited(false) {}
	virtual ~CTextureManager();

	static CTextureManager* Instance();
	void Init(LPDIRECT3DDEVICE9 iDevice);
	void OnDestroyDevice();

	void Load2D(const wstring& iName, const unsigned iMipLevels = 0);
	void LoadCube(const wstring& iName, const unsigned iMipLevels = 0);
	
	C2DTexture*		Get2D(const wstring& iName, const unsigned iMipLevels = 0);
	CCubeTexture*	GetCube(const wstring& iName, const unsigned iMipLevels = 0);
	
	bool Inited() const { return inited; }

};

#define TextureManager CTextureManager::Instance()

}

}

#endif 