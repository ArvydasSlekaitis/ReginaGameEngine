/*
    CException.h - Contains class CException.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#ifndef REGINA_CEXCEPTION_H
#define REGINA_CEXCEPTION_H

#include <stdexcept>
using namespace std;

namespace Regina
{

class CException : public std::exception
{
private:
	string throwingObject;
	string additionalInformation;
	string msg;

	void UpdateMsg() { msg = throwingObject + " - " + additionalInformation; }

protected:
	void SetThrowingObject(const string& iThrowingObject) { throwingObject = iThrowingObject; UpdateMsg(); }
	void SetAdditionalInformation(const string& iAdditionalInformation) { additionalInformation = iAdditionalInformation; UpdateMsg(); }

public:
	CException(const string& iThrowingObject, const string& iAdditionalInformation) : throwingObject(iThrowingObject), additionalInformation(iAdditionalInformation) { UpdateMsg(); }

	string ThrowingObject()			const { return throwingObject; }
	string AdditionalInformation()  const { return additionalInformation; }
	virtual const char *__CLR_OR_THIS_CALL what() const _THROW0() { return msg.c_str(); }
};

}


#endif