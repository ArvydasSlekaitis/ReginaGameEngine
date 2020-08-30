/*
    CText.h - Contains class CText which is designed to work with text files.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CTEXT_H
#define REGINA_CTEXT_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <assert.h>
using namespace std;

namespace Regina
{

class CText : public vector<wstring>
{
public:
	void Save(const wstring& iFileName);
	void Load(const wstring& iFileName);
	void RemoveEmptyLines();
	wostream& operator<<( wostream& Output );
};

}

#endif
