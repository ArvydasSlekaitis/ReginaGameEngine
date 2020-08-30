/*
    TScriptAction_RunChain.h - Contains template TScriptAction_RunChain.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_TSCRIPTACTION_RUNCHAIN_H
#define REGINA_SCRIPT_TSCRIPTACTION_RUNCHAIN_H

#include <string>
#include <sstream>
#include <CScriptAction.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------------------------------------------|
//TScriptAction_RunChain template.																					|
//T1 Script chain type.																								|
//------------------------------------------------------------------------------------------------------------------|
template<class T1>
class TScriptAction_RunChain : public CScriptAction
{
	T1*	scriptChain;
	
	public:
	TScriptAction_RunChain(T1* iScriptChain) throw(invalid_argument); 
	void Execute() { scriptChain->Run(); }		
};

//*****************************************************************************

template<class T1>
TScriptAction_RunChain<T1>::TScriptAction_RunChain(T1* iScriptChain) : scriptChain(iScriptChain)
	{ 
	if(iScriptChain == NULL)
		throw invalid_argument("TScriptAction_RunChain<T1, T2>::TScriptAction_RunChain - argument iScriptChain == NULL");
	}

//*****************************************************************************

}

}

#endif