///////////////////////////////////////////////////////////
//  TMatterialIDGenerator.h
//  Created on:      21-11-2009
//  Last modified:   21-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_TMATTERIALIDGENERATOR_H
#define REGINA_TMATTERIALIDGENERATOR_H

#include <vector>
#include <set>
#include <assert.h>
using namespace std;

namespace Regina
{

template <class T1> 
class TMatterialIDGenerator
{
	set<unsigned>		freeSlots;
	vector<set<T1*> >	objectVariationList;

	void		IncreaseOccurance(const unsigned& iPosition, T1* iObject) { objectVariationList[iPosition].insert(iObject); }
	void		DecreaseOccurance(const unsigned& iPosition, T1* iObject);
	unsigned	VariationListSize() { return objectVariationList.size(); }
	unsigned	GetObjectPosition(T1* iObject);
	unsigned	AddNewVariation(T1* iObject);

public:
	unsigned	Register(T1* iObject);
	unsigned	Register(T1* iObject, const unsigned& iPossibleID);
	unsigned	Update(T1* iObject, const unsigned& iCurID);
	void		Unregister(T1* iObject, const unsigned& iCurID);

};

//*****************************************************************************

template <class T1> 
unsigned TMatterialIDGenerator<T1>::Register(T1* iObject)
	{
	unsigned position = GetObjectPosition(iObject);
	if(position >= VariationListSize())
		{
		return AddNewVariation(iObject);
		}
	else
		{
		IncreaseOccurance(position, iObject);
		return position;
		}
	}

//*****************************************************************************

template <class T1> 
unsigned TMatterialIDGenerator<T1>::Register(T1* iObject, const unsigned& iPossibleID)
	{
	if(iPossibleID >= VariationListSize())
		return Register(iObject);

	if(objectVariationList[iPossibleID].first == NULL)
		return Register(iObject);

	if(*objectVariationList[iPossibleID].first == *iObject)
		{
		IncreaseOccurance(iPossibleID);
		return iPossibleID;
		}
	else
		return Register(iObject);
	}

//*****************************************************************************

template <class T1> 
unsigned TMatterialIDGenerator<T1>::Update(T1* iObject, const unsigned& iCurID)
	{
	unsigned position = GetObjectPosition(iObject);
	
	if(position == iCurID)
		{
		return iCurID;
		}
	else
		{
		DecreaseOccurance(iCurID, iObject);

		if(position >= VariationListSize())
			{
			return AddNewVariation(iObject);
			}
		else
			{
			IncreaseOccurance(position, iObject);
			return position;
			}
		}
	}

//*****************************************************************************

template <class T1> 
void TMatterialIDGenerator<T1>::Unregister(T1* iObject, const unsigned& iCurID)
	{
	DecreaseOccurance(iCurID, iObject);
	}

//*****************************************************************************

template <class T1> 
void TMatterialIDGenerator<T1>::DecreaseOccurance(const unsigned& iPosition, T1* iObject)
	{ 
	assert(objectVariationList[iPosition].size()!=0 && L"TMatterialIDGenerator::DecreaseOccurance"); 
	objectVariationList[iPosition].erase(iObject);

	if(objectVariationList[iPosition].size() == 0)
		{
		freeSlots.insert(iPosition);
		}
	}

//*****************************************************************************

template <class T1> 
unsigned TMatterialIDGenerator<T1>::GetObjectPosition(T1* iObject)
	{
	for(unsigned i=0; i<VariationListSize(); i++)
		if(objectVariationList[i].size()!=0)
			if(*iObject == *(*objectVariationList[i].begin()))
				return i;

	return VariationListSize();
	}

//*****************************************************************************

template <class T1> 
unsigned TMatterialIDGenerator<T1>::AddNewVariation(T1* iObject)
	{
	if(freeSlots.size() > 0)
		{
		unsigned position = *freeSlots.begin();
		assert(objectVariationList[position].size() == 0 && L"TMatterialIDGenerator<T1>::AddNewVariation");
		objectVariationList[position].insert(iObject);
		freeSlots.erase(freeSlots.begin());
		return position;
		}
	else
		{
		objectVariationList.push_back(set<T1*>());
		objectVariationList[objectVariationList.size()-1].insert(iObject);
		return objectVariationList.size()-1;
		}
	}

//*****************************************************************************




}


#endif