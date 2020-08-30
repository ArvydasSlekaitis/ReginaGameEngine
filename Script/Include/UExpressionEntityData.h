/*
    UExpressionEntityData.h - Contains union UExpressionEntityData.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_UEXPRESSIONENTITYDATA_H
#define REGINA_SCRIPT_UEXPRESSIONENTITYDATA_H

#include <string>
using namespace std;

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------|
//UExpressionEntityData union encapsulating pointer of variables used for scipt.|
//------------------------------------------------------------------------------|
union UExpressionEntityData
{
bool*	 b;
int*	 i;
float*	 f;
wstring* s;
};
//*****************************************************************************


}

}

#endif