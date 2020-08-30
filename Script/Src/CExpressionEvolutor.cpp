/*
    CExpressionEvolutor.cpp - Contains class CExpressionEvolutor implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CExpressionEvolutor.h>
using namespace Regina::Script;

//*****************************************************************************

CExpressionEvolutor::~CExpressionEvolutor()
	{
	for(unsigned i=0; i<expressionEntity.size(); i++)
		if(expressionEntity[i]!=NULL)
			delete expressionEntity[i];

	expressionEntity.clear();
	}

//*****************************************************************************

bool CExpressionEvolutor::FindWorkingRange(unsigned& oBegin, unsigned& oEnd) const
	{
	oBegin = 0;
	oEnd = expressionEntity.size()-1;

	for(unsigned i=0; i<expressionEntity.size(); i++)
		if(expressionEntity[i]!=NULL)
			{
			if(expressionEntity[i]->Type() == CExpressionEntity::eParenthesis)
				{
				if(expressionEntity[i]->SubType() == CExpressionEntity::eOpening)
					oBegin = i;
				
				if(expressionEntity[i]->SubType() == CExpressionEntity::eClosing)
					{
					oEnd = i;
					break;
					}			

				}
			}
	return true;
	}

//*****************************************************************************
	
bool CExpressionEvolutor::FindFirst_Divide(const unsigned& iBegin, const unsigned& iEnd, unsigned& oPosition) const
	{
	for(unsigned i=iBegin; i<=iEnd; i++)
	if(expressionEntity[i]!=NULL)
		{
		if(expressionEntity[i]->Type() == CExpressionEntity::eSign)
			{
			if(expressionEntity[i]->SubType() == CExpressionEntity::eDivide)
				{
				oPosition = i;
				return true;
				}
			}
		}

	return false;
	}

//*****************************************************************************

bool CExpressionEvolutor::FindFirst_Minus(const unsigned& iBegin, const unsigned& iEnd, unsigned& oPosition) const
	{
	for(unsigned i=iBegin; i<=iEnd; i++)
	if(expressionEntity[i]!=NULL)
		{
		if(expressionEntity[i]->Type() == CExpressionEntity::eSign)
			{
			if(expressionEntity[i]->SubType() == CExpressionEntity::eMinus)
				{
				oPosition = i;
				return true;
				}
			}
		}

	return false;
	}

//*****************************************************************************

bool CExpressionEvolutor::FindFirst_Multiply(const unsigned& iBegin, const unsigned& iEnd, unsigned& oPosition) const
	{
	for(unsigned i=iBegin; i<=iEnd; i++)
	if(expressionEntity[i]!=NULL)
		{
		if(expressionEntity[i]->Type() == CExpressionEntity::eSign)
			{
			if(expressionEntity[i]->SubType() == CExpressionEntity::eMultiply)
				{
				oPosition = i;
				return true;
				}
			}
		}

	return false;
	}

//*****************************************************************************

bool CExpressionEvolutor::FindFirst_Plus(const unsigned& iBegin, const unsigned& iEnd, unsigned& oPosition) const
	{
	for(unsigned i=iBegin; i<=iEnd; i++)
	if(expressionEntity[i]!=NULL)
		{
		if(expressionEntity[i]->Type() == CExpressionEntity::eSign)
			{
			if(expressionEntity[i]->SubType() == CExpressionEntity::ePlus)
				{
				oPosition = i;
				return true;
				}
			}
		}

	return false;
	}

//*****************************************************************************

bool CExpressionEvolutor::GetLeftArgumentPosition(const unsigned& iBegin, const unsigned&, const unsigned& iStartSearch, unsigned& oPosition) const
	{
	if(iStartSearch == iBegin)
		return false;

	for(int i=iStartSearch; i>=(int)iBegin; i--)
		if(expressionEntity[i]!=NULL)
			if(expressionEntity[i]->Type() == CExpressionEntity::eVariable)
				{
				oPosition = i;
				return true;
				}

	return false;
	}

//*****************************************************************************

bool CExpressionEvolutor::GetRightArgumentPosition(const unsigned&, const unsigned& iEnd, const unsigned& iStartSearch, unsigned& oPosition) const
	{
	for(unsigned i=iStartSearch; i<=iEnd; i++)
		if(expressionEntity[i]!=NULL)
			if(expressionEntity[i]->Type() == CExpressionEntity::eVariable)
				{
				oPosition = i;
				return true;
				}

	return false;
	}

//*****************************************************************************

unsigned CExpressionEvolutor::NumActions() const
	{
	unsigned num(0);
	for(unsigned i=0; i<expressionEntity.size(); i++)
		if(expressionEntity[i]!=NULL)
			num++;
	return num;
	}

//*****************************************************************************

void CExpressionEvolutor::AddVariable(bool* iVariable)
	{
	expressionEntity.push_back(new CExpressionEntity(iVariable));
	}

//*****************************************************************************

void CExpressionEvolutor::AddVariable(int* iVariable)
	{
	expressionEntity.push_back(new CExpressionEntity(iVariable));
	}

//*****************************************************************************

void CExpressionEvolutor::AddVariable(float* iVariable)
	{
	expressionEntity.push_back(new CExpressionEntity(iVariable));
	}

//*****************************************************************************

void CExpressionEvolutor::AddVariable(wstring* iVariable)
	{
	expressionEntity.push_back(new CExpressionEntity(iVariable));
	}

//*****************************************************************************

void CExpressionEvolutor::AddSign_Plus()
	{
	expressionEntity.push_back(new CExpressionEntity('+'));
	}

//*****************************************************************************

void CExpressionEvolutor::AddSign_Minus()
	{
	expressionEntity.push_back(new CExpressionEntity('-'));
	}

//*****************************************************************************

void CExpressionEvolutor::AddSign_Divide()
	{
	expressionEntity.push_back(new CExpressionEntity('/'));
	}

//*****************************************************************************

void CExpressionEvolutor::AddSign_Multiply()
	{
	expressionEntity.push_back(new CExpressionEntity('*'));
	}

//*****************************************************************************

void CExpressionEvolutor::AddParentheses_Opening()
	{
	expressionEntity.push_back(new CExpressionEntity('('));
	}

//*****************************************************************************

void CExpressionEvolutor::AddParentheses_Closing()
	{
	expressionEntity.push_back(new CExpressionEntity(')'));
	}

//*****************************************************************************