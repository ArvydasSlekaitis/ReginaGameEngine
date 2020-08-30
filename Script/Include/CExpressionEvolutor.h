/*
    CExpressionEvolutor.h - Contains class CExpressionEvolutor.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_SCRIPT_CEXPRESSIONEVOLUTOR_H
#define REGINA_SCRIPT_CEXPRESSIONEVOLUTOR_H

#include <string>
#include <vector>
#include <assert.h>
using namespace std;

#include <CExpressionEntity.h>

namespace Regina
{

namespace Script
{

//----------------------------------------------------------------------------------------------|
//CExpressionEvolutor class is a base class of class family used to evolute script expressions.	|
//----------------------------------------------------------------------------------------------|
class CExpressionEvolutor
{
protected:
	vector<CExpressionEntity*>	expressionEntity;

	bool FindWorkingRange(unsigned& oBegin, unsigned& oEnd) const;
	
	bool FindFirst_Divide(const unsigned& iBegin, const unsigned& iEnd, unsigned& oPosition) const;
	bool FindFirst_Minus(const unsigned& iBegin, const unsigned& iEnd, unsigned& oPosition) const;
	bool FindFirst_Multiply(const unsigned& iBegin, const unsigned& iEnd, unsigned& oPosition) const;
	bool FindFirst_Plus(const unsigned& iBegin, const unsigned& iEnd, unsigned& oPosition) const;
	
	bool GetLeftArgumentPosition(const unsigned& iBegin, const unsigned& iEnd, const unsigned& iStartSearch, unsigned& oPosition) const;
	bool GetRightArgumentPosition(const unsigned& iBegin, const unsigned& iEnd, const unsigned& iStartSearch, unsigned& oPosition) const;

	unsigned NumActions() const;

	void AddVariable(bool* iVariable);
	void AddVariable(int* iVariable);
	void AddVariable(float* iVariable);
	void AddVariable(wstring* iVariable);

	void AddSign_Plus();
	void AddSign_Minus();
	void AddSign_Divide();
	void AddSign_Multiply();

public:
	~CExpressionEvolutor();
	void AddParentheses_Opening();
	void AddParentheses_Closing();


};
//*****************************************************************************


}

}

#endif