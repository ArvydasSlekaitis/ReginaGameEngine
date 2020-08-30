/*
    CScriptAction_None.h - Contains class CScriptAction_None.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CSCRIPTACTION_NONE_H
#define REGINA_SCRIPT_CSCRIPTACTION_NONE_H

#include <CScriptAction.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//CScriptAction_None class.													  |
//----------------------------------------------------------------------------|
class CScriptAction_None: public CScriptAction
{
public:
	void Execute() {}
};
//*****************************************************************************


}

}

#endif