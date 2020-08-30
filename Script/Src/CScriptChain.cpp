/*
    CScriptChain.cpp - Contains class CScriptChain implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CScriptChain.h>
using namespace Regina::Script;

//*****************************************************************************

CScriptChain::~CScriptChain()
	{
	for(unsigned i=0; i<scriptAction.size(); i++)
		delete scriptAction[i];
	}

//*****************************************************************************

void CScriptChain::Add(CScriptAction* iScriptAction)
	{
	if(iScriptAction == NULL)
		throw invalid_argument("CScriptChain::Add - argument iScriptAction == NULL");

	scriptAction.push_back(iScriptAction);
	}

//*****************************************************************************

void CScriptChain::Run()
	{
	for(unsigned i=0; i<scriptAction.size(); i++)
		scriptAction[i]->Execute();
	}

//*****************************************************************************
