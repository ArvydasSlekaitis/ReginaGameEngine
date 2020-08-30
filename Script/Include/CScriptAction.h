/*
    CScriptAction.h - Contains class CScriptAction.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CSCRIPTACTION_H
#define REGINA_SCRIPT_CSCRIPTACTION_H

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//CScriptAction class is base class for all script actions.					  |
//----------------------------------------------------------------------------|
class CScriptAction
{
public:
	virtual ~CScriptAction(){}
	virtual void Execute() = 0;
};
//*****************************************************************************


}

}

#endif