/*
    CText.cpp - Contains class CText implementation.
	Copyright 2007-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#include <CText.h>
using Regina::CText;

//******************************************************************************

void CText::Load(const wstring& iFileName)
	{
	wifstream input(iFileName.c_str());

	if(!input.fail())
	while(!input.eof())
		{
		wstring line;
		getline(input, line);
		push_back(line);
		}
	}

//******************************************************************************

void CText::Save(const wstring& iFileName)
	{
	wofstream output(iFileName.c_str());
	for(unsigned i=0; i<size(); i++)
		if(i<size()-1)
			output << at(i) << '\n';
		else
			output << at(i);
	}

//******************************************************************************

void CText::RemoveEmptyLines()
	{
	vector<wstring>::iterator iter = begin();
	while(iter!=end())
		{
		if(iter->length()==0)
			{
			erase(iter);
			iter = begin();
			}
		iter++;
		}
	}

//******************************************************************************

wostream& CText::operator<<( wostream& Output )
{
copy(begin(), end(), ostream_iterator<wstring, wchar_t>(Output, L"\n"));
return Output;
}

//******************************************************************************

