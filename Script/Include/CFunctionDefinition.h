/*
    CFunctionDefinition.h - Contains class CFunctionDefinition.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CFUNCTIONDEFINITION_H
#define REGINA_SCRIPT_CFUNCTIONDEFINITION_H

#include <string>
using namespace std;

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------|
//CFunctionDefinition class keeps information about declared functions. 	  |
//----------------------------------------------------------------------------|
class CFunctionDefinition
{
public:
	enum EFunctionArgumentType{e_Void, e_String, e_Bool, e_Float, e_Int};

private:
	wstring					name;
	unsigned				position;
	EFunctionArgumentType	returnType;
	EFunctionArgumentType	argumentType;

public:
	CFunctionDefinition(const wstring& iName, const unsigned& iPosition, const EFunctionArgumentType& iReturnType, const EFunctionArgumentType& iArgumentType) : name(iName), position(iPosition), returnType(iReturnType), argumentType(iArgumentType) {}
	wstring					Name()			const { return name; }
	unsigned				Position()		const { return position; }
	EFunctionArgumentType	ReturnType()	const { return returnType; }
	EFunctionArgumentType	ArgumentType()  const { return argumentType; }
};
//*****************************************************************************


}

}

#endif