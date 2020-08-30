/*
    CFontManager.h - Contains class CFontManager.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CFONTMANAGER
#define REGINA_CFONTMANAGER

#include <string>
#include <vector>
#include <map>
using namespace std;

#include <CFont.h>
#include <CFontDefinition.h>

namespace Regina
{

namespace UI
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

	void Clear();

public:
	CFontManager();
	~CFontManager();

	CFont*	GetFont(CFontDefinition& iFontDefinition);
	bool	ExistFont(CFontDefinition& iFontDefinition);
	bool    Inited() const { return inited; }
	void	Init(LPDIRECT3DDEVICE9 iDevice);
	void	OnDestroyDevice();
	void	OnLostDevice();
	void	OnResetDevice();

};

}

}
#endif 