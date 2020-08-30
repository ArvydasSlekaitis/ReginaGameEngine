///////////////////////////////////////////////////////////
//  FastAccessManager.h
//  Created on:      22-06-2009
//  Last modified:   22-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_FASTACCESSMANAGERMANAGER_H
#define REGINA_FASTACCESSMANAGERMANAGER_H

#include <deque>
#include <map>
#include <vector>
#include <string>
#include <exception>
#include <assert.h>
using namespace std;


namespace Regina
{

template<class T1>
class TFastAccessManager
{
private:
	map<unsigned, pair<T1*, unsigned> >		objectsMap; // pair<Pointer to T1, Position in object vector
	vector<unsigned>						idToRemove;
	vector<unsigned>						freeObjects; //Not ID, but position in object vector
	vector<unsigned>						freeObjectsID; // Free object id
	deque<T1*>								objects;

	unsigned maxLoadID;  //max object id, which was loaded ( max id ). It will be set at the moment, when LoadComplete() function is called;
	unsigned nextFreeID; 
	unsigned minID;
	unsigned maxID;

	void RemoveObject(unsigned iID);
	unsigned GetNextFreeID();
	unsigned GetNextFreePosition();
	void Destroy(T1* iObject);    //Destroy object ( delete );

protected:
	virtual void SetID(T1* iObject, const unsigned& iID) = 0;

public:
	TFastAccessManager(unsigned iMinID, unsigned iMaxID);
	virtual ~TFastAccessManager() { Clear(); }

	void Add(T1* iObject);  //Warning! Calling this funtion, while all object with pre defined id is not loaded, may couse later loading artifacts!
	void Remove(unsigned iID);
	bool IDExist(unsigned iID) const;

	T1* ObjectFromID(unsigned iID);

	void Update(float iDuration);
	void Clear();
	void RemoveRemoved();

	void SetMinIDForObject(unsigned iMinID) { if(iMinID == 0) throw logic_error("Min id must be greater than zero"); minID = iMinID; }
	void SetMaxIDForObject(unsigned iMaxID) { if(iMaxID<=minID) throw logic_error("Max id must be greater than min id"); maxID = iMaxID; } 

public:
	class ID_Error : public runtime_error
		{
		public:
			ID_Error(const string& msg = "") : runtime_error(msg) {}
		};
};

//******************************************************************************

template<class T1>
TFastAccessManager<T1>::TFastAccessManager(unsigned iMinID, unsigned iMaxID) : maxLoadID(0), nextFreeID(0), minID(iMinID), maxID(iMaxID)
{
}

//******************************************************************************

template<class T1>
void TFastAccessManager<T1>::RemoveObject(unsigned iID)
{
map<unsigned, pair<T1*, unsigned> >::iterator it = objectsMap.find(iID);
if(it!=objectsMap.end())
{
objects[it->second.second] = NULL;
freeObjects.push_back(it->second.second);
SetID(it->second.first, 0);
Destroy(it->second.first);
freeObjectsID.push_back(iID);
objectsMap.erase(iID);
}
}

//******************************************************************************

template<class T1>
void TFastAccessManager<T1>::RemoveRemoved()
{
for(unsigned i=0; i<idToRemove.size(); i++)
	{
	if(idToRemove[i] >= minID && idToRemove[i] <= maxID)	
		{
		RemoveObject(idToRemove[i]);
		continue;
		}
	assert(false); //If fails, then, particle which sould be deleted, can't exist;
	}

idToRemove.clear();
}

//******************************************************************************

template<class T1>
void TFastAccessManager<T1>::Destroy(T1* iObject)
{
delete iObject;
iObject = NULL;
}

//******************************************************************************

template<class T1>
unsigned TFastAccessManager<T1>::GetNextFreeID()
{
if(freeObjectsID.size()>0) 
	{
	unsigned ret = freeObjectsID[freeObjectsID.size()-1];
	freeObjectsID.pop_back();
	return ret;
	}


	nextFreeID++;

	if(nextFreeID>maxID) throw ID_Error("All object ids are used");

	assert(nextFreeID >= minID);
	assert(nextFreeID <= maxID);

return nextFreeID;
}

//******************************************************************************

template<class T1>
unsigned TFastAccessManager<T1>::GetNextFreePosition()
{
if(freeObjects.size()>0) 
	{
	unsigned ret = freeObjects[freeObjects.size()-1];
	freeObjects.pop_back();
	return ret;
	}
else
	{
	objects.push_back(NULL);
	return objects.size()-1;
	}

}

//******************************************************************************

template<class T1>
void TFastAccessManager<T1>::Add(T1* iObject)
{
assert(iObject!=NULL);

if(iObject->ID() == 0) SetID(iObject, GetNextFreeID());
else 
	{
    maxLoadID = max(iObject->ID(), maxLoadID);
	nextFreeID = max(maxLoadID+1, nextFreeID);
	}

unsigned pos = GetNextFreePosition();
assert(objects[pos] == NULL);
objects[pos] = iObject;
objectsMap.insert(make_pair(iObject->ID(), make_pair(iObject, pos)));
}

//******************************************************************************

template<class T1>
void TFastAccessManager<T1>::Remove(unsigned iID)
{
idToRemove.push_back(iID);
}

//******************************************************************************

template<class T1>
bool TFastAccessManager<T1>::IDExist(unsigned iID) const
{
if(objectsMap.find(iID) != objectsMap.end())
return true;
return false;
}

//******************************************************************************

template<class T1>
T1* TFastAccessManager<T1>::ObjectFromID(unsigned iID)
{
T1* ret = NULL;
map<unsigned, pair<T1*, unsigned> >::iterator it = objectsMap.find(iID);
if(it!=objectsMap.end())
ret = it->second.first;
return ret;
}

//******************************************************************************

template<class T1>
void TFastAccessManager<T1>::Update(float iDuration)
{
for(unsigned i=0; i<objects.size(); i++)
if(objects[i]!=NULL)
	{
	objects[i]->Update(iDuration);
	}
}

//******************************************************************************

template<class T1>
void TFastAccessManager<T1>::Clear()
{
for(unsigned i=0; i<objects.size(); i++)
if(objects[i]!=NULL)
{
SetID(objects[i], 0);
Destroy(objects[i]);
}

objectsMap.clear();
objects.clear();
idToRemove.clear();
freeObjects.clear();
freeObjectsID.clear();
maxLoadID=0;
nextFreeID=0;
}

//******************************************************************************










}

#endif
