/*
    CFontManager.h - Contains class CFontManager.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_GRAPHICS_CFONTMANAGER_H
#define REGINA_GRAPHICS_CFONTMANAGER_H

#include <string>
#include <vector>
#include <map>
using namespace std;

#include <CFont.h>
#include <CFontDefinition.h>

namespace Regina
{

namespace Graphics
{

class CFontManager
{
public:
	enum e_State{e_normal, e_lost, e_reset};

private:
	map<wstring, CFont*>	fontMap;
	vector<CFont*>			fontVector;
	bool					inited;
	e_State					state;
	LPDIRECT3DDEVICE9		device;

	CFontManager(const CFontManager& iManager) {}
	void Clear();

public:
	CFontManager() : device(NULL), inited(false), state(e_normal) {}
	virtual ~CFontManager();

	static CFontManager* Instance();
	void	Init(LPDIRECT3DDEVICE9 iDevice);
	void	OnDestroyDevice();
	void	OnLostDevice();
	void	OnResetDevice();

	CFont*	GetFont(const wstring& iFacename, const unsigned& iHeight, const unsigned& iWeight, const bool& iItalic);
	void	LoadFont(const wstring& iFacename, const unsigned& iHeight, const unsigned& iWeight, const bool& iItalic);

	bool Inited() const { return inited; }
};

#define FontManager CFontManager::Instance()

}

}
#endif 