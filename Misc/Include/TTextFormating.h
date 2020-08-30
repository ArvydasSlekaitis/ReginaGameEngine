/*
    TTextFormating.h - Contains text formating templates.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_TTEXTFORMATING_H
#define REGINA_TTEXTFORMATING_H

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

//------------------------------------------------------------------------------------------------------------------|
//AddWord template function.																						|
//Add word to the output container.																				    |
//oContainerType output container type, iPredictableClass predictable class type.									|
//------------------------------------------------------------------------------------------------------------------|
template<class oContainerType, class iPredictableClass>
void AddWord(const wstring& iWord, oContainerType& oOutput, iPredictableClass* iPointerToPredictableClass, bool (iPredictableClass::* iPointerToPredictable)(const wstring&))
	{
	assert(iPointerToPredictableClass !=NULL && L"AddWord - iPointerToPredictableClass !=NULL");

	//	If iWord size is less then one - discard it.
	if(iWord.size() == 0)
		return; 

	//	If output container is empty, add empty line.
	if(oOutput.size() == 0)
		oOutput.push_back(wstring());

	//	Assign newLine variable last output container line contents.
	wstring newLine = oOutput[oOutput.size()-1];

	//	Concatinate newLine variable with inputed word.
	newLine += iWord;

	//	Apply predictable to newLine, if it returns true - newLine does not exceed maximal line length.
	if((iPointerToPredictableClass->*iPointerToPredictable)(newLine))
		oOutput[oOutput.size()-1] = newLine;		
	else
		{
		// Predictable failed, if this is empty symbol - remove it.
		if(iWord != L" ")
			{
			//	Maybe inputed word does not exceed maximum line length, if so, output it as new line.
			if((iPointerToPredictableClass->*iPointerToPredictable)(newLine))
				oOutput.push_back(iWord);
			else
				{
				oOutput.push_back(wstring());
				//	We've got worst case - inputed word size is greated then maximum, so use recursion.
				if(iWord.size() == 1)
					AddWord(wstring() + iWord[0], oOutput, iPointerToPredictableClass, iPointerToPredictable);
				else
					{
					//	Firstly output first symbol.
					AddWord(wstring() + iWord[0], oOutput, iPointerToPredictableClass, iPointerToPredictable);

					//	And then all what is left.
					AddWord(wstring(iWord.begin()+1, iWord.end()), oOutput, iPointerToPredictableClass, iPointerToPredictable);
					}
					
				}
			}
		}
	}

//*****************************************************************************

//------------------------------------------------------------------------------------------------------------------|
//Scan template function.																							|
//Scan line to find all words.																						|
//oContainerType output container type, iPredictableClass predictable class type.									|
//------------------------------------------------------------------------------------------------------------------|
template<class oContainerType, class iPredictableClass>
void Scan(const wstring& iLine, int& ioCurX, oContainerType& oOutput, iPredictableClass* iPointerToPredictableClass, bool (iPredictableClass::* iPointerToPredictable)(const wstring&))
	{
	assert(iPointerToPredictableClass !=NULL && L"Scan - iPointerToPredictableClass !=NULL");

	//	If we have reached end of line - exit.
	if(ioCurX >= iLine.size())
		return;

	//	Find first ' ' symbol in line, starting from ioCurX.
	int firstSpace = iLine.find_first_of(' ', ioCurX);

	//	Find first symbol in line ( except ' ' ), starting from ioCurX.
	int firstNotSpace = iLine.find_first_not_of(' ', ioCurX);

	//	If no ' ' symbol found set firstSpace variable value to the size of iLine.
	if(firstSpace == -1) firstSpace = iLine.size()+1;

	//	If line is made purly from ' ' symbols set firstNotSpace variable value to the size of iLine.	
	if(firstNotSpace == -1) firstNotSpace = iLine.size()+1;


	if(firstSpace < firstNotSpace)
		{
		//	First symbol is ' '.
		wstring tWord(iLine, firstSpace, firstNotSpace-firstSpace);
		ioCurX = firstNotSpace;
		AddWord(tWord, oOutput, iPointerToPredictableClass, iPointerToPredictable);
		Scan(iLine, ioCurX, oOutput, iPointerToPredictableClass, iPointerToPredictable);
		}
	else
		{
		//	First symbol is not ' '. Find first ' ' symbol after it to know where word ends.
		int firstSpaceAfter = iLine.find_first_of(' ', ioCurX+1);
		
		//	If we will reach end of line, there will not be any ' ' symbol, so set firstSpaceAfter variable value to the size of iLine
		if(firstSpaceAfter == -1) firstSpaceAfter = iLine.size()+1;
		
		wstring tWord(iLine, firstNotSpace, firstSpaceAfter-firstNotSpace);
		ioCurX = firstSpaceAfter;
		AddWord(tWord, oOutput, iPointerToPredictableClass, iPointerToPredictable);
		Scan(iLine, ioCurX, oOutput, iPointerToPredictableClass, iPointerToPredictable);
		} 
	}

//*****************************************************************************

//--------------------------------------------------------------------------------------------------------------------------------------------------------------|
//FormatText template function.																																	|
//This is the main text formating function.																														|	
//iContainerType input container type, oContainerType output container type, iPredictableClass predictable class type.											|
//--------------------------------------------------------------------------------------------------------------------------------------------------------------|
template<class iContainerType, class oContainerType, class iPredictableClass>
void FormatText(const iContainerType& iInputText, oContainerType& oOutputText, iPredictableClass* iPointerToPredictableClass, bool (iPredictableClass::* iPointerToPredictable)(const wstring&))
	{
	if(iPointerToPredictableClass == NULL)
		throw invalid_argument("FormatText - argument - iPredClass ==  NULL");

	//	Process all input text lines.
	for(int i=0; i<iInputText.size(); i++)
		{
		int ioCurX=0;
		oOutputText.push_back(wstring());
		Scan(iInputText[i], ioCurX, oOutputText, iPointerToPredictableClass, iPointerToPredictable);
		}
	}

//******************************************************************************

}

#endif
