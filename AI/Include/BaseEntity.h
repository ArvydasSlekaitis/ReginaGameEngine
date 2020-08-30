///////////////////////////////////////////////////////////
//  BaseEntity.h
//  Created on:      17-07-2008
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_BASEENTITY_H
#define REGINA_BASEENTITY_H

#include <d3dx9.h>

#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
using namespace std;

#include <Telegram.h>


namespace Regina
{

class CEntityManager;

class CBaseEntity
{
	unsigned 		id;
	unsigned		type;
	string			className;
	
public:
	CBaseEntity(const string iClassName = "BaseEntity", const unsigned iType = 0) : type(iType), id(0), className(iClassName) { }
	virtual ~CBaseEntity(){ if(id!=0) throw logic_error("Trying to delete entity which was not unregistered with AIManager ( Call AIManager->RemoveEntity instead )");  }

	virtual void Update(float duration) {}
	virtual void HandleMsg(CTelegram* iTelegram) { delete iTelegram; }
	virtual void Load(const vector<string>& iText) {} 

	unsigned ID()			const { return id; }
	unsigned Type()			const { return type; }
	
	friend CEntityManager;
};

}

#endif