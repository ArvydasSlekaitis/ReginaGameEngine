/*
    TMaterialTypeGenerator.h - Contains template TMaterialTypeGenerator.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#ifndef REGINA_TMATERIALTYPEGENERATOR_H
#define REGINA_TMATERIALTYPEGENERATOR_H

#include <vector>
#include <set>
#include <assert.h>
using namespace std;

namespace Regina
{

namespace Scene
{

/**
 * This  class is used to generate material type.
 */
template <class T1> 
class TMaterialTypeGenerator
{
private:
	/**
	 * Free slots in variation list.
	 */
	set<unsigned> freeSlots;
	/**
	 * Object variation list.
	 */
	vector<set<T1*> > objectVariationList;
	
	/**
	 * Increase object occurrence.
	 */
	void IncreaseOccurance(const unsigned& iPosition, T1* iObject) 
		{ 
		objectVariationList[iPosition].insert(iObject); 
		}
	/**
	 * Decrease object occurrence.
	 */
	void DecreaseOccurance(const unsigned& iPosition, T1* iObject);
	/**
	 * Returns object variation list size.
	 */
	unsigned GetVariationListSize() const 
		{ 
		return objectVariationList.size(); 
		}
	/**
	 * Returns object position in variation list.
	 */
	unsigned GetObjectPosition(T1* iObject);
	/**
	 * Adds new variation.
	 */
	unsigned AddNewVariation(T1* iObject);

public:
	/**
	 * Destructor.
	 */
	virtual ~TMaterialTypeGenerator() 
		{
		}
	/**
	 * Registers object.
	 */
	unsigned Register(T1* iObject);
	/**
	 * Registers object.
	 */
	unsigned Register(T1* iObject, const unsigned& iPossibleID);
	/**
	 * Updates object.
	 */
	unsigned Update(T1* iObject, const unsigned& iCurID);
	/**
	 * Unregisters object.
	 */
	void Unregister(T1* iObject, const unsigned& iCurID);

};

//*****************************************************************************

/**
* Registers object.
*/
template <class T1> 
unsigned TMaterialTypeGenerator<T1>::Register(T1* iObject)
	{
	const unsigned position = GetObjectPosition(iObject);
	if(position >= GetVariationListSize())
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

/**
* Registers object.
*/
template <class T1> 
unsigned TMaterialTypeGenerator<T1>::Register(T1* iObject, const unsigned& iPossibleID)
	{
	if(iPossibleID >= VariationListSize())
		return Register(iObject);

	if(objectVariationList[iPossibleID].first == NULL)
		return Register(iObject);

	if(*objectVariationList[iPossibleID].first->CompareMaterialType(*iObject) == true)
		{
		IncreaseOccurance(iPossibleID);
		return iPossibleID;
		}
	else
		return Register(iObject);
	}

//*****************************************************************************

/**
* Updates object.
*/
template <class T1> 
unsigned TMaterialTypeGenerator<T1>::Update(T1* iObject, const unsigned& iCurID)
	{
	const unsigned position = GetObjectPosition(iObject);
	
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

/**
* Unregisters object.
*/
template <class T1> 
void TMaterialTypeGenerator<T1>::Unregister(T1* iObject, const unsigned& iCurID)
	{
	DecreaseOccurance(iCurID, iObject);
	}

//*****************************************************************************

/**
* Decrease object occurrence.
*/
template <class T1> 
void TMaterialTypeGenerator<T1>::DecreaseOccurance(const unsigned& iPosition, T1* iObject)
	{ 
	assert(objectVariationList[iPosition].size()!=0 && L"TMaterialTypeGenerator::DecreaseOccurance"); 
	objectVariationList[iPosition].erase(iObject);

	if(objectVariationList[iPosition].size() == 0)
		{
		freeSlots.insert(iPosition);
		}
	}

//*****************************************************************************

/**
* Returns object position in variation list.
*/
template <class T1> 
unsigned TMaterialTypeGenerator<T1>::GetObjectPosition(T1* iObject)
	{
	const unsigned variationListSize(GetVariationListSize());

	for(unsigned i=0; i<variationListSize; i++)
		if(objectVariationList[i].size()!=0)
			if(iObject->CompareMaterialType(*(*objectVariationList[i].begin())) == true)
				return i;

	return variationListSize;
	}

//*****************************************************************************

/**
* Adds new variation.
*/
template <class T1> 
unsigned TMaterialTypeGenerator<T1>::AddNewVariation(T1* iObject)
	{
	if(freeSlots.size() > 0)
		{
		const unsigned position = *freeSlots.begin();
		assert(objectVariationList[position].size() == 0 && L"TMaterialTypeGenerator<T1>::AddNewVariation");
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

}


#endif