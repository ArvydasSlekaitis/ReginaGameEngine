///////////////////////////////////////////////////////////
//  FastAccessRegistration.h
//  Created on:      25-03-2009
//  Last modified:   25-03-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef FASTACCESSREGISTRATION_H
#define FASTACCESSREGISTRATION_H

#include <deque>
#include <map>
#include <algorithm>
#include <assert.h>
using namespace std;

namespace Regina
{

//T1 - object ( holds entitys, - must have FillAdditionalDependencys(vector<T2*>& oAdditionalDependencys) && Update(float iDuration) ), T2 - entity
template<class T1, class T2 = unsigned>
class TFastAccessRegistration
{
private:
unsigned curMaintananceSort;
const unsigned maintananceSortCycle;

protected:
deque<T1*>					objects;	// Objects contains entitys, they are dependant on them;
multimap<T2, unsigned>		entityMap;	// Maps entity with position in objects;
deque<unsigned>				freeObjects;

void UnregisterObject(unsigned iPosition);
void RegisterObject(T1* iObject, unsigned iPosition);
void RemoveEntityFromMap(T2 iEntity);
void RemoveEntityFromMap(T2 iEntity, unsigned iPosition);
void AddEntityToMap(T2 iEntity, unsigned iPosition);

void GetEntityPositionList(T2 iEntity, vector<unsigned>& oPositionList);
void MoveObject(unsigned iCurPos, unsigned iDestPos);

public:
TFastAccessRegistration(const unsigned iMaintananceSortCycle = 10);
~TFastAccessRegistration();

void Add(T1* iObject);
void Remove(T1* iObject);
void Unregister(T2 iEntity);
void Clear();
void Update(float iDuration);
void Maintanance();
};

//*****************************************************************************

template<class T1, class T2>
TFastAccessRegistration<T1, T2>::TFastAccessRegistration(const unsigned iMaintananceSortCycle) : curMaintananceSort(0), maintananceSortCycle(iMaintananceSortCycle)
{
}

//*****************************************************************************

template<class T1, class T2>
TFastAccessRegistration<T1, T2>::~TFastAccessRegistration()
{
Clear();
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::UnregisterObject(unsigned iPosition)
{
assert(objects[iPosition]!=NULL);

vector<T2> additionalDependency;
objects[iPosition]->FillAdditionalDependencys(additionalDependency);

for(unsigned i=0; i<additionalDependency.size(); i++)
	{
	RemoveEntityFromMap(additionalDependency[i], iPosition);
	}

freeObjects.push_back(iPosition);
delete objects[iPosition];
objects[iPosition] = NULL;
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::Remove(T1* iObject)
	{
	for(unsigned i=0; i<objects.size(); i++)
		if(iObject == objects[i])
			{
			UnregisterObject(i);
			break;
			}
	}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::RegisterObject(T1* iObject, unsigned iPosition)
{
assert(iObject!=NULL);
assert(objects[iPosition] == NULL);

vector<T2> additionalDependency;
iObject->FillAdditionalDependencys(additionalDependency);

for(unsigned i=0; i<additionalDependency.size(); i++)
	{
	AddEntityToMap(additionalDependency[i], iPosition);
	}

objects[iPosition] = iObject;
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::RemoveEntityFromMap(T2 iEntity)
{
entityMap.erase(iEntity);
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::RemoveEntityFromMap(T2 iEntity, unsigned iPosition)
{
multimap<T2, unsigned>::iterator itend = entityMap.upper_bound(iEntity);
multimap<T2, unsigned>::iterator itbegin = entityMap.lower_bound(iEntity); 

while(itbegin!=itend)
	{
	if(itbegin->second==iPosition)
		{
		entityMap.erase(itbegin);
		break;
		}
	itbegin++;
	}
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::AddEntityToMap(T2 iEntity, unsigned iPosition)
{
entityMap.insert(make_pair(iEntity, iPosition));
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::GetEntityPositionList(T2 iEntity, vector<unsigned>& oPositionList)
{
if(entityMap.size()>0)
	{
	multimap<T2, unsigned>::iterator itend = entityMap.upper_bound(iEntity);
	multimap<T2, unsigned>::iterator itbegin = entityMap.lower_bound(iEntity);

	if(itbegin!=entityMap.end())
	while(itbegin!=itend)
		{
		oPositionList.push_back(itbegin->second);
		itbegin++;
		}

	}
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::Add(T1* iObject)
{
if(freeObjects.size()>0)
	{
	RegisterObject(iObject, freeObjects[freeObjects.size()-1]);
	freeObjects.pop_back();
	}
else
	{
	objects.push_back(NULL);
	RegisterObject(iObject, objects.size()-1);
	}
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::Unregister(T2 iEntity)
{
vector<unsigned> entityPosition;
GetEntityPositionList(iEntity, entityPosition);

for(unsigned i=0; i<entityPosition.size(); i++)
	{
	UnregisterObject(entityPosition[i]);
	}
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::Clear()
{
for(unsigned i=0; i<objects.size(); i++)
delete objects[i];

objects.clear();
entityMap.clear();
freeObjects.clear();
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::Update(float iDuration)
{
for(unsigned i=0; i<objects.size(); i++)
if(objects[i]!=NULL)
objects[i]->Update(iDuration);
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::Maintanance()
{
if(freeObjects.size() > 0)
	{
	if(curMaintananceSort<=0)
		{
		sort(freeObjects.begin(), min(freeObjects.end(), freeObjects.begin()+maintananceSortCycle) , greater<unsigned>());
		curMaintananceSort=maintananceSortCycle;
		return;
		}

	if(freeObjects[0] == objects.size()-1)
		{
		assert(objects[objects.size()-1] == NULL);
		freeObjects.pop_front();
		objects.pop_back();
		}
	else
		{
		MoveObject(objects.size()-1, freeObjects[freeObjects.size()-1]);
		freeObjects.pop_back();
		objects.pop_back();
		}
	curMaintananceSort--;
	}
}

//*****************************************************************************

template<class T1, class T2>
void TFastAccessRegistration<T1, T2>::MoveObject(unsigned iCurPos, unsigned iDestPos)
{
assert(objects[iCurPos]!=NULL);
assert(objects[iDestPos]==NULL);

vector<T2> additionalDependency;
objects[iCurPos]->FillAdditionalDependencys(additionalDependency);

	for(unsigned i=0; i<additionalDependency.size(); i++)
		{
		RemoveEntityFromMap(additionalDependency[i], iCurPos);
		AddEntityToMap(additionalDependency[i], iDestPos);
		}

objects[iDestPos] = objects[iCurPos];
objects[iCurPos]=NULL;
}

//*****************************************************************************


}

#endif
