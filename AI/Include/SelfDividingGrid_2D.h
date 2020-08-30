///////////////////////////////////////////////////////////
//  SelfDividingGrid_2D.h
//  Created on:      18-08-2008
//  Last modified:   23-06-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef REGINA_SELFDIVIDINGGRID_2D_H
#define REGINA_SELFDIVIDINGGRID_2D_H

#include <BoundingCircle.h>
#include <Functions_Math.h>

#include <vector>
using namespace std;

namespace Regina
{

template<class T1>
class TSelfDividingGrid_2D
{
	TSelfDividingGrid_2D<T1>*			parent;
	vector<TSelfDividingGrid_2D<T1>*>	children;
	vector<T1*>							objects;

	D3DXVECTOR2		originalCenter; // Original bounding box center
	CBoundingCircle boundingVolume; // Current bounding volume
	
	float	boundingBoxHX; // Original bounding box halfsize x
	float	boundingBoxHY; // Original bounding box halfsize y
	float	points;        // Catches grid points

public:
	TSelfDividingGrid_2D(D3DXVECTOR2 iCenter, float iBoundingBoxHX, float iBoundingBoxHY, TSelfDividingGrid_2D<T1>* iParent=NULL);
	~TSelfDividingGrid_2D();
	
	void Add(T1* iObject) { objects.push_back(iObject); }
	void Add(typename vector<T1*>::iterator iBegin, typename vector<T1*>::iterator iEnd) { copy(iBegin, iEnd, back_inserter(objects)); }
	void Remove(T1* iObject);
	
	void Clear();
	float Create(const unsigned &iAttempsLeftTotal, const bool iHorizontal = true, const bool iVertical = true, const bool iHorizontalVertical = true);
	void RecalculateBoundingVolume();
	
	unsigned	ObjectsSize()	const { return objects.size(); }
	unsigned	ChildrenSize()	const { return children.size(); }

	T1* Object(unsigned iIndex) { return objects[iIndex]; }

	void CheckCollision(const float iX, const float iY, const float iRadius, vector<T1*>* oCollisions);
	void CheckCollision(const T1* iObject, vector<T1*>* oCollisions) { CheckCollision(iObject->Position().x, iObject->Position().z, iObject->Radius(), oCollisions); }
	void CheckCollision(const D3DXVECTOR3 iPosition, const float iRadius, vector<T1*>* oCollisions) { CheckCollision(iPosition.x, iPosition.z, iRadius, oCollisions); }
	void CheckCollision(const D3DXVECTOR2 iPosition, const float iRadius, vector<T1*>* oCollisions) { CheckCollision(iPosition.x, iPosition.y, iRadius, oCollisions); }
	
};

//*****************************************************************************

template<class T1>
TSelfDividingGrid_2D<T1>::TSelfDividingGrid_2D(D3DXVECTOR2 iCenter, float iBoundingBoxHX, float iBoundingBoxHY, TSelfDividingGrid_2D<T1>* iParent=NULL) : parent(iParent), children(0), objects(0), boundingBoxHX(iBoundingBoxHX), boundingBoxHY(iBoundingBoxHY), points(0.0f), boundingVolume(iCenter), originalCenter(iCenter)
	{
	}

//*****************************************************************************

template<class T1>
TSelfDividingGrid_2D<T1>::~TSelfDividingGrid_2D()
{
	for(unsigned i=0; i<children.size(); i++)
	delete children[i];
}

//*****************************************************************************

template<class T1>
float TSelfDividingGrid_2D<T1>::Create(const unsigned &iAttempsLeftTotal, const bool iHorizontal, const bool iVertical, const bool iHorizontalVertical)
{
if(children.size()!=0) throw logic_error("Trying to call TSelfDividingGrid_2D method Create, while it was prievously called, and not cleaned up");

if(iAttempsLeftTotal>0)
{
unsigned numDiv = 1;
unsigned iAttempsLeft = iAttempsLeftTotal;

if(!iHorizontal && !iVertical && !iHorizontalVertical)
	iAttempsLeft--;
else
	{
	if(iHorizontal)
		numDiv++;
	if(iVertical)
		numDiv++;
	if(iHorizontalVertical)
		numDiv+=2;
	}

iAttempsLeft = iAttempsLeftTotal/numDiv;


if(objects.size()>1)
{
//Calculate Points
float tDivisionPoints(0);
float hDivisionPoints(0);
float vDivisionPoints(0);
float hvDivisionPoints(0);

//Definitions
TSelfDividingGrid_2D<T1>* hGrid1 = NULL;
TSelfDividingGrid_2D<T1>* hGrid2 = NULL;
TSelfDividingGrid_2D<T1>* vGrid1 = NULL;
TSelfDividingGrid_2D<T1>* vGrid2 = NULL;
TSelfDividingGrid_2D<T1>* hvGrid1 = NULL;
TSelfDividingGrid_2D<T1>* hvGrid2 = NULL;
TSelfDividingGrid_2D<T1>* hvGrid3 = NULL;
TSelfDividingGrid_2D<T1>* hvGrid4 = NULL;



//Calculate Total division points
RecalculateBoundingVolume();
tDivisionPoints = objects.size()*boundingVolume.Area();

//Calculate Horizontal division points
if(iHorizontal)
{
float hBranchCount1(0);
float hBranchCount2(0);
hGrid1= new TSelfDividingGrid_2D<T1>(D3DXVECTOR2(boundingVolume.Position().x, boundingVolume.Position().y - boundingBoxHY/2), boundingBoxHX, boundingBoxHY/2);
hGrid2= new TSelfDividingGrid_2D<T1>(D3DXVECTOR2(boundingVolume.Position().x, boundingVolume.Position().y + boundingBoxHY/2), boundingBoxHX, boundingBoxHY/2);
for(unsigned i=0; i<objects.size(); i++)
if(objects[i]->Position().z >= boundingVolume.Position().y) hGrid2->Add(objects[i]);
else  hGrid1->Add(objects[i]);

//Calculate points from 1 Horizontal grid
if(hGrid1->ObjectsSize()==objects.size()) hDivisionPoints=-1;
else
if(hGrid1->ObjectsSize()==0) {}
else
if(hGrid1->ObjectsSize()==1) hBranchCount1++;
else
{
hBranchCount1++;
hDivisionPoints += hGrid1->Create(iAttempsLeft, iHorizontal, iVertical, iHorizontalVertical);
}
if(hDivisionPoints!=-1)
hDivisionPoints += hBranchCount1*boundingVolume.Area();

//Calculate points from 2 Horizontal grid
if(hDivisionPoints!=-1)
if(hGrid2->ObjectsSize()==objects.size()) hDivisionPoints=-1;
else
if(hGrid2->ObjectsSize()==0) {}
else
if(hGrid2->ObjectsSize()==1) hBranchCount2++;
else
{
hBranchCount2++;
hDivisionPoints += hGrid2->Create(iAttempsLeft, iHorizontal, iVertical, iHorizontalVertical);
}
if(hDivisionPoints!=-1)
hDivisionPoints += hBranchCount2*boundingVolume.Area();
}




//Calculate Vertical division points
if(iVertical)
{
float vBranchCount1(0);
float vBranchCount2(0);
vGrid1= new TSelfDividingGrid_2D<T1>(D3DXVECTOR2(boundingVolume.Position().x - boundingBoxHX/2, boundingVolume.Position().y), boundingBoxHX/2, boundingBoxHY);
vGrid2= new TSelfDividingGrid_2D<T1>(D3DXVECTOR2(boundingVolume.Position().x + boundingBoxHX/2, boundingVolume.Position().y), boundingBoxHX/2, boundingBoxHY);
for(unsigned i=0; i<objects.size(); i++)
if(objects[i]->Position().x >= boundingVolume.Position().x)  vGrid2->Add(objects[i]);
else vGrid1->Add(objects[i]);

//Calculate points from 1 Vertical grid
if(vGrid1->ObjectsSize()==objects.size()) vDivisionPoints=-1;
else
if(vGrid1->ObjectsSize()==0) {}
else
if(vGrid1->ObjectsSize()==1) vBranchCount1++;
else
{
vBranchCount1++;
vDivisionPoints += vGrid1->Create(iAttempsLeft, iHorizontal, iVertical, iHorizontalVertical);
}
if(vDivisionPoints!=-1)
vDivisionPoints += vBranchCount1*boundingVolume.Area();

//Calculate points from 2 Vertical grid
if(vDivisionPoints!=-1)
if(vGrid2->ObjectsSize()==objects.size()) vDivisionPoints=-1;
else
if(vGrid2->ObjectsSize()==0) {}
else
if(vGrid2->ObjectsSize()==1) vBranchCount2++;
else
{
vBranchCount2++;
vDivisionPoints += vGrid2->Create(iAttempsLeft, iHorizontal, iVertical, iHorizontalVertical);
}
if(vDivisionPoints!=-1)
vDivisionPoints += vBranchCount2*boundingVolume.Area();
}






//Calculate Horizontal Vertical division points
if(iHorizontalVertical)
{
float hvBranchCount1(0);
float hvBranchCount2(0);
float hvBranchCount3(0);
float hvBranchCount4(0);

hvGrid1= new TSelfDividingGrid_2D<T1>(D3DXVECTOR2(boundingVolume.Position().x - boundingBoxHX/2, boundingVolume.Position().y + boundingBoxHY/2), boundingBoxHX/2, boundingBoxHY/2);
hvGrid2= new TSelfDividingGrid_2D<T1>(D3DXVECTOR2(boundingVolume.Position().x + boundingBoxHX/2, boundingVolume.Position().y + boundingBoxHY/2), boundingBoxHX/2, boundingBoxHY/2);
hvGrid3= new TSelfDividingGrid_2D<T1>(D3DXVECTOR2(boundingVolume.Position().x + boundingBoxHX/2, boundingVolume.Position().y - boundingBoxHY/2), boundingBoxHX/2, boundingBoxHY/2);
hvGrid4= new TSelfDividingGrid_2D<T1>(D3DXVECTOR2(boundingVolume.Position().x - boundingBoxHX/2, boundingVolume.Position().y - boundingBoxHY/2), boundingBoxHX/2, boundingBoxHY/2);

for(unsigned i=0; i<objects.size(); i++)
if(objects[i]->Position().x <= boundingVolume.Position().x)
{
if( objects[i]->Position().z >= boundingVolume.Position().y )  hvGrid1->Add(objects[i]);
else  hvGrid4->Add(objects[i]);
}
else
{
if( objects[i]->Position().z >= boundingVolume.Position().y )  hvGrid2->Add(objects[i]);
else  hvGrid3->Add(objects[i]);
}

//Calculate points from 1 Horizontal Vertical grid
if(hvGrid1->ObjectsSize()==objects.size()) hvDivisionPoints=-1;
else
if(hvGrid1->ObjectsSize()==0) {}
else
if(hvGrid1->ObjectsSize()==1) hvBranchCount1++;
else
{
hvBranchCount1++;
hvDivisionPoints += hvGrid1->Create(iAttempsLeft, iHorizontal, iVertical, iHorizontalVertical);
}
if(hvDivisionPoints!=-1)
hvDivisionPoints += hvBranchCount1*boundingVolume.Area();

//Calculate points from 2 Horizontal Vertical grid
if(hvDivisionPoints!=-1)
if(hvGrid2->ObjectsSize()==objects.size()) hvDivisionPoints=-1;
else
if(hvGrid2->ObjectsSize()==0) {}
else
if(hvGrid2->ObjectsSize()==1) hvBranchCount2++;
else
{
hvBranchCount2++;
hvDivisionPoints += hvGrid2->Create(iAttempsLeft, iHorizontal, iVertical, iHorizontalVertical);
}
if(hvDivisionPoints!=-1)
hvDivisionPoints += hvBranchCount2*boundingVolume.Area();

//Calculate points from 3 Horizontal Vertical grid
if(hvDivisionPoints!=-1)
if(hvGrid3->ObjectsSize()==objects.size()) hvDivisionPoints=-1;
else
if(hvGrid3->ObjectsSize()==0) {}
else
if(hvGrid3->ObjectsSize()==1) hvBranchCount3++;
else
{
hvBranchCount3++;
hvDivisionPoints += hvGrid3->Create(iAttempsLeft, iHorizontal, iVertical, iHorizontalVertical);
}
if(hvDivisionPoints!=-1)
hvDivisionPoints += hvBranchCount3*boundingVolume.Area();

//Calculate points from 4 Horizontal Vertical grid
if(hvDivisionPoints!=-1)
if(hvGrid4->ObjectsSize()==objects.size()) hvDivisionPoints=-1;
else
if(hvGrid4->ObjectsSize()==0) {}
else
if(hvGrid4->ObjectsSize()==1) hvBranchCount4++;
else
{
hvBranchCount4++;
hvDivisionPoints += hvGrid4->Create(iAttempsLeft, iHorizontal, iVertical, iHorizontalVertical);
}
if(hvDivisionPoints!=-1)
hvDivisionPoints += hvBranchCount4*boundingVolume.Area();
}





//Determine a way of division
if(hDivisionPoints==-1 || !iHorizontal)
hDivisionPoints = max(tDivisionPoints, vDivisionPoints) + 1;
if(vDivisionPoints==-1 || !iVertical)
vDivisionPoints = max(tDivisionPoints, hDivisionPoints) + 1;
if(hvDivisionPoints==-1 || !iHorizontalVertical)
hvDivisionPoints = max(hDivisionPoints, vDivisionPoints) + 1;


//Use total division
if(tDivisionPoints<=hDivisionPoints && tDivisionPoints<=vDivisionPoints && tDivisionPoints<=hvDivisionPoints)
{
if(hGrid1!=NULL) delete hGrid1;
if(hGrid2!=NULL) delete hGrid2;
if(vGrid1!=NULL) delete vGrid1;
if(vGrid2!=NULL) delete vGrid2;
if(hvGrid1!=NULL) delete hvGrid1;
if(hvGrid2!=NULL) delete hvGrid2;
if(hvGrid3!=NULL) delete hvGrid3;
if(hvGrid4!=NULL) delete hvGrid4;

points = tDivisionPoints;
}
else
if(hDivisionPoints<tDivisionPoints && hDivisionPoints<=vDivisionPoints && hDivisionPoints<=hvDivisionPoints)
{
//Use horizontal division
objects.clear();

if(vGrid1!=NULL) delete vGrid1;
if(vGrid2!=NULL) delete vGrid2;
if(hvGrid1!=NULL) delete hvGrid1;
if(hvGrid2!=NULL) delete hvGrid2;
if(hvGrid3!=NULL) delete hvGrid3;
if(hvGrid4!=NULL) delete hvGrid4;

//Proccess first Grid
if(hGrid1->ObjectsSize()==0 && hGrid1->ChildrenSize()==0) { delete hGrid1; hGrid1 = NULL; }
else
if(hGrid1->ObjectsSize()==1 && hGrid1->ChildrenSize()==0) { objects.push_back(hGrid1->Object(0)); delete hGrid1; }
else
children.push_back(hGrid1);


//Proccess second Grid
if(hGrid2->ObjectsSize()==0 && hGrid2->ChildrenSize()==0) { delete hGrid2; hGrid2 = NULL; }
else
if(hGrid2->ObjectsSize()==1 && hGrid2->ChildrenSize()==0) { objects.push_back(hGrid2->Object(0)); delete hGrid2; }
else
children.push_back(hGrid2);

points = hDivisionPoints;
}
else
if(vDivisionPoints<tDivisionPoints && vDivisionPoints<hDivisionPoints && vDivisionPoints<=hvDivisionPoints)
{
//Use vertical division
objects.clear();

if(hGrid1!=NULL) delete hGrid1;
if(hGrid2!=NULL) delete hGrid2;
if(hvGrid1!=NULL) delete hvGrid1;
if(hvGrid2!=NULL) delete hvGrid2;
if(hvGrid3!=NULL) delete hvGrid3;
if(hvGrid4!=NULL) delete hvGrid4;

//Proccess first Grid
if(vGrid1->ObjectsSize()==0 && vGrid1->ChildrenSize()==0) { delete vGrid1; vGrid1 = NULL; }
else
if(vGrid1->ObjectsSize()==1 && vGrid1->ChildrenSize()==0) { objects.push_back(vGrid1->Object(0)); delete vGrid1; }
else
children.push_back(vGrid1);

//Proccess second Grid
if(vGrid2->ObjectsSize()==0 && vGrid2->ChildrenSize()==0) { delete vGrid2; vGrid2 = NULL; }
else
if(vGrid2->ObjectsSize()==1 && vGrid2->ChildrenSize()==0) { objects.push_back(vGrid2->Object(0)); delete vGrid2; }
else
children.push_back(vGrid2);

points = vDivisionPoints;
}
else
if(hvDivisionPoints<tDivisionPoints && hvDivisionPoints<hDivisionPoints && hvDivisionPoints<vDivisionPoints)
{
//Use horizontal vertical division
objects.clear();

if(hGrid1!=NULL) delete hGrid1;
if(hGrid2!=NULL) delete hGrid2;
if(vGrid1!=NULL) delete vGrid1;
if(vGrid2!=NULL) delete vGrid2;

//Proccess first Grid
if(hvGrid1->ObjectsSize()==0 && hvGrid1->ChildrenSize()==0) { delete hvGrid1; hvGrid1 = NULL; }
else
if(hvGrid1->ObjectsSize()==1 && hvGrid1->ChildrenSize()==0) { objects.push_back(hvGrid1->Object(0)); delete hvGrid1; }
else
children.push_back(hvGrid1);

//Proccess second Grid
if(hvGrid2->ObjectsSize()==0 && hvGrid2->ChildrenSize()==0) { delete hvGrid2; hvGrid2 = NULL; }
else
if(hvGrid2->ObjectsSize()==1 && hvGrid2->ChildrenSize()==0) { objects.push_back(hvGrid2->Object(0)); delete hvGrid2; }
else
children.push_back(hvGrid2);

//Proccess third Grid
if(hvGrid3->ObjectsSize()==0 && hvGrid3->ChildrenSize()==0) { delete hvGrid3; hvGrid3 = NULL; }
else
if(hvGrid3->ObjectsSize()==1 && hvGrid3->ChildrenSize()==0) { objects.push_back(hvGrid3->Object(0)); delete hvGrid3; }
else
children.push_back(hvGrid3);

//Proccess fourth Grid
if(hvGrid4->ObjectsSize()==0 && hvGrid4->ChildrenSize()==0) { delete hvGrid4; hvGrid4 = NULL; }
else
if(hvGrid4->ObjectsSize()==1 && hvGrid4->ChildrenSize()==0) { objects.push_back(hvGrid4->Object(0)); delete hvGrid4; }
else
children.push_back(hvGrid4);

points = hvDivisionPoints;
}
else
throw runtime_error("Grid unspecified");

}
else
{
RecalculateBoundingVolume();
points = objects.size()*boundingVolume.Area();
}


}

RecalculateBoundingVolume();
return points;
}

//*****************************************************************************

template<class T1>
void TSelfDividingGrid_2D<T1>::RecalculateBoundingVolume()
{
if(objects.size()+children.size()>0)
{
D3DXVECTOR2 totalCenter=D3DXVECTOR2(0, 0);

for(unsigned i=0; i<objects.size(); i++)
totalCenter+=D3DXVECTOR2(objects[i]->Position().x, objects[i]->Position().z);

for(unsigned i=0; i<children.size(); i++)
totalCenter+=children[i]->boundingVolume.Position();

boundingVolume.SetPosition(totalCenter/(float)(objects.size()+children.size()));
}

boundingVolume.SetRadius(0);


for(unsigned i=0; i<objects.size(); i++)
boundingVolume.IncreaseRadius(objects[i]->Position(), objects[i]->Radius());

for(unsigned i=0; i<children.size(); i++)
boundingVolume.IncreaseRadius(children[i]->boundingVolume);
}


//*****************************************************************************

template<class T1>
void TSelfDividingGrid_2D<T1>::Remove(T1* iObject)
{
for(unsigned i=0; i<objects.size(); i++)
if(objects[i] == iObject)
{
objects[i] = objects[objects.size()-1];
objects.pop_back();
}
for(unsigned i=0; i<children.size(); i++)
children[i]->Remove(iObject);

RecalculateBoundingVolume();
}

//*****************************************************************************

template<class T1>
void TSelfDividingGrid_2D<T1>::Clear()
{
for(unsigned i=0; i<children.size(); i++)
delete children[i];

children.clear();
objects.clear();
}

//*****************************************************************************

template<class T1>
void TSelfDividingGrid_2D<T1>::CheckCollision(const float iX, const float iY, const float iRadius, vector<T1*>* oCollisions)
{
if(Distance(iX, iY, boundingVolume.Position().x, boundingVolume.Position().y) <  iRadius + boundingVolume.Radius())
{
for(unsigned i=0; i<objects.size(); i++)
if(Distance(iX, iY, objects[i]->Position().x, objects[i]->Position().z) <  iRadius + objects[i]->Radius())
oCollisions->push_back(objects[i]);

for(unsigned i=0; i<children.size(); i++)
children[i]->CheckCollision(iX, iY, iRadius, oCollisions);
}
}

//*****************************************************************************

}

#endif
