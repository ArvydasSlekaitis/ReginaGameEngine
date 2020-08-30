/*
    CException_OutOfMemmory.h - Contains class CException_OutOfMemmory.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_EXCEPTION_OUTOFMEMMORY_H
#define REGINA_EXCEPTION_OUTOFMEMMORY_H

#include <CException.h>

namespace Regina
{

class CException_OutOfMemmory : public CException
{
public:
	CException_OutOfMemmory(const string& iThrowingObject, const string& iAdditionalInformation) : CException(iThrowingObject, iAdditionalInformation) {}
};

}


#endif