/*
    CExpressionEntity.cpp - Contains class CExpressionEntity implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CExpressionEntity.h>
using namespace Regina::Script;

//*****************************************************************************

CExpressionEntity::CExpressionEntity(char iSymbol)
	{
	switch(iSymbol)
		{
		case '(' :	type = eParenthesis; 
					subType = eOpening;
					break;

		case ')' :	type = eParenthesis; 
					subType = eClosing;
					break;

		case '+' :	type = eSign; 
					subType = ePlus;
					break;

		case '-' :	type = eSign; 
					subType = eMinus;
					break;


		case '/' :	type = eSign; 
					subType = eDivide;
					break;

		case '*' :	type = eSign; 
					subType = eMultiply;
					break;

		default: assert(false && L"CExpressionEntity::CExpressionEntity - argument iSymbol - symbol is not recognized");
		}
	}

//*****************************************************************************

CExpressionEntity::CExpressionEntity(bool* iBool)
	{
	data.b = iBool;
	type = eVariable; 
	subType = eBool;
	}

//*****************************************************************************

CExpressionEntity::CExpressionEntity(int* iInt)
	{
	data.i = iInt;
	type = eVariable; 
	subType = eInt;
	}

//*****************************************************************************

CExpressionEntity::CExpressionEntity(float* iFloat)
	{
	data.f = iFloat;
	type = eVariable; 
	subType = eFloat;
	}

//*****************************************************************************

CExpressionEntity::CExpressionEntity(wstring* iString)
	{
	data.s = iString;
	type = eVariable; 
	subType = eString;
	}

//*****************************************************************************

bool* CExpressionEntity::GetPointerToBool()
	{
	assert(type == eVariable && subType == eBool && L"ExpressionEntity::PointerToBool()");
	return data.b;
	}

//*****************************************************************************

int* CExpressionEntity::GetPointerToInt()
	{
	assert(type == eVariable && subType == eInt && L"CExpressionEntity::PointerToInt");
	return data.i;
	}

//*****************************************************************************

wstring* CExpressionEntity::GetPointerToString()
	{
	assert(type == eVariable && subType == eString && L"CExpressionEntity::PointerToString");
	return data.s;
	}

//*****************************************************************************

float* CExpressionEntity::GetPointerToFloat()
	{
	assert(type == eVariable && subType == eFloat && L"CExpressionEntity::PointerToFloat");
	return data.f;
	}

//*****************************************************************************


