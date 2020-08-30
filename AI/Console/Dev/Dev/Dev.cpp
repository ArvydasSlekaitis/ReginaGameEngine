// Dev.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#include <BaseEntity.h>
#include <EntityManager.h>
#include <MessageDispatcher.h>
#include <SelfDividingGrid_2D.h>
#include <Wall_2D.h>
#include <Wall_2D_Penetratable.h>
using namespace Regina;

int _tmain(int argc, _TCHAR* argv[])
{
CWall_2D_Penetratable line(10, 2, 10, 100, -1, 0);
cout << line.Normal().x << " " << line.Normal().y << endl;
cout << line.Center().x << " " << line.Center().y << endl;
cout << line.Length() << endl;
cout << line.Length_Sq() << endl;
cout << line.K() << endl;
cout << line.B() << endl;

float x1;
float y1;
float x2;
float y2; 
float penetration;
unsigned np = line.Intersect(10, 1, 10,  x1, y1, x2, y2, penetration);
cout << np << " " << x1 << " " << x2 << " " << x2 << " " << y2 <<  " " << penetration << endl;

int m;
cin >> m;




	return 0;
}

