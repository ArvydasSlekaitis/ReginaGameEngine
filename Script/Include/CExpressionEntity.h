/*
    CExpressionEntity.h - Contains class CExpressionEntity.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CEXPRESSIONENTITY_H
#define REGINA_SCRIPT_CEXPRESSIONENTITY_H

#include <string>
#include <assert.h>
using namespace std;

#include <UExpressionEntityData.h>

namespace Regina
{

namespace Script
{

//------------------------------------------------------------------------------|
//CExpressionEntity class encapsulates script expression entity.				|
//------------------------------------------------------------------------------|
class CExpressionEntity
{
public:
	enum e_type { eVariable, eParenthesis, eSign };
	enum e_subType { eBool, eInt, eFloat, eString, eOpening, eClosing, ePlus, eMinus, eDivide, eMultiply };
	
private:
	e_type type;
	e_subType subType;
	UExpressionEntityData data;

public:
	CExpressionEntity(char iSymbol);
	CExpressionEntity(bool* iBool);
	CExpressionEntity(int* iInt);
	CExpressionEntity(float* iFloat);
	CExpressionEntity(wstring* iString);

	bool*		GetPointerToBool();
	int*		GetPointerToInt();
	wstring*	GetPointerToString();
	float*		GetPointerToFloat();

	e_type		Type()		const { return type; }
	e_subType	SubType()	const { return subType; }
	
};
//*****************************************************************************


}

}

#endif