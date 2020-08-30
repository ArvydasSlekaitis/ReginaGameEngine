// Dev.cpp : Defines the entry point for the console application.
//




#include "stdafx.h"

#include <iostream>
#include <assert.h>
#include <time.h>
using namespace std;

#include "CTestClass_House.h"

#include <VariablePool.h>
#include <Script.h>

int _tmain(int argc, _TCHAR* argv[])
{
CTestClass_House house;

const double numArthTest = 1000;

double beginTime;
double endTime;
double averageTime(0);

/*
//*******************************************************************************************
//Aritmetiniu veiksmu testas ( 1 veiksmas )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"Aritmetiniu_1.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"Aritmetiniu_1.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Naujas variklis ) esant 1 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	{
	int myInt;
	myInt = 0;
	myInt += 10;
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( c++ ) esant 1 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************
{
VariablePool VP;
CScript Script(&VP, "Aritmetiniu_1.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Senas variklis ) esant 1 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;


//*******************************************************************************************
//Aritmetiniu veiksmu testas ( 10 veiksmu )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"Aritmetiniu_10.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"Aritmetiniu_10.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Naujas variklis ) esant 10 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	{	
	int myInt;
	myInt = 0;
	myInt += 10;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt;
	}


	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( c++ ) esant 10 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
VariablePool VP;
CScript Script(&VP, "Aritmetiniu_10.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Senas variklis ) esant 10 veiksmu: " << averageTime << endl;
}

cout << endl;


//*******************************************************************************************
//Aritmetiniu veiksmu testas ( 100 veiksmu )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"Aritmetiniu_100.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"Aritmetiniu_100.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Naujas variklis ) esant 100 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	{
	int myInt;
	int myInt2;
	myInt = 0;
	myInt2 = 10;
	myInt += 10;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	}


	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( c++ ) esant 100 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
VariablePool VP;
CScript Script(&VP, "Aritmetiniu_100.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Senas variklis ) esant 100 veiksmu: " << averageTime << endl;
}

cout << endl;

//*******************************************************************************************
//Aritmetiniu veiksmu testas ( 1000 veiksmu )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"Aritmetiniu_1000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"Aritmetiniu_1000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Naujas variklis ) esant 1000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	{
	int myInt;
	int myInt2;
	myInt = 0;
	myInt2 = 10;
	myInt += 10;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	}


	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( c++ ) esant 1000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
VariablePool VP;
CScript Script(&VP, "Aritmetiniu_1000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Senas variklis ) esant 1000 veiksmu: " << averageTime << endl;
}

cout << endl;

//*******************************************************************************************
//Aritmetiniu veiksmu testas ( 5000 veiksmu )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"Aritmetiniu_5000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"Aritmetiniu_5000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Naujas variklis ) esant 5000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	{
	int myInt;
	int myInt2;
	myInt = 0;
	myInt2 = 10;
	myInt += 10;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	}


	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( c++ ) esant 5000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
VariablePool VP;
CScript Script(&VP, "Aritmetiniu_5000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Senas variklis ) esant 5000 veiksmu: " << averageTime << endl;
}

cout << endl;

//*******************************************************************************************
//Aritmetiniu veiksmu testas ( 10000 veiksmu )
//*******************************************************************************************
{
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
	airthmetic_scriptManager_1.LoadScript(L"Aritmetiniu_10000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Naujas variklis ) esant 10000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
		
	{
	int myInt;
	int myInt2;
	myInt = 0;
	myInt2 = 10;
	myInt += 10;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	myInt2 = myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt + myInt * 10 * myInt + myInt / 10 * 15 * myInt  + myInt * 10 * myInt + myInt / 10 * 15 * myInt - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 - myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 * myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2 + myInt * 10 * myInt2 + myInt / 10 * 15 * myInt2  + myInt * 10 * myInt + myInt2 / 10 * 15 * myInt2;
	}


	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( c++ ) esant 10000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	VariablePool VP;
	CScript Script(&VP, "Aritmetiniu_10000.txt");
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "Artmetiniu veiksmu vidutinis laikas ( Senas variklis ) esant 10000 veiksmu: " << averageTime << endl;
}

*/

cout << endl;

/*

//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************

//*******************************************************************************************
//IF salygos testas ( 1 veiksmas )
//*******************************************************************************************



{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"IF_Naujo_1.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"IF_Naujo_1.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( Naujas variklis ) esant 1 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int myInt;
	myInt = 0;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( c++ ) esant 1 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************
{
VariablePool VP;
CScript Script(&VP, "IF_Seno_1.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( Senas variklis ) esant 1 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//IF salygos testas ( 10 veiksmu )
//*******************************************************************************************

{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"IF_Naujo_10.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"IF_Naujo_10.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( Naujas variklis ) esant 10 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int myInt;
	myInt = 0;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;									
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( c++ ) esant 10 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
VariablePool VP;
CScript Script(&VP, "IF_Seno_10.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( Senas variklis ) esant 10 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//IF salygos testas ( 100 veiksmu )
//*******************************************************************************************

{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"IF_Naujo_100.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"IF_Naujo_100.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( Naujas variklis ) esant 100 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int myInt;
	myInt = 0;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;									
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( c++ ) esant 100 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
VariablePool VP;
CScript Script(&VP, "IF_Seno_100.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( Senas variklis ) esant 100 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//IF salygos testas ( 1000 veiksmu )
//*******************************************************************************************

{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"IF_Naujo_1000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"IF_Naujo_1000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( Naujas variklis ) esant 1000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int myInt;
	myInt = 0;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;		
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;	
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;
	if(myInt > 0)
		myInt--;
	else
		myInt++;																									
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( c++ ) esant 1000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
VariablePool VP;
CScript Script(&VP, "IF_Seno_1000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( Senas variklis ) esant 1000 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//IF salygos testas ( 5000 veiksmu )
//*******************************************************************************************

{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"IF_Naujo_5000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"IF_Naujo_5000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( Naujas variklis ) esant 5000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

{
int myInt;
myInt = 0;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;		
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;		
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;		
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;		
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;		
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;		
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;	
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;
if(myInt > 0)
	myInt--;
else
	myInt++;																								
}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( c++ ) esant 5000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
VariablePool VP;
CScript Script(&VP, "IF_Seno_5000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	Script.Run();

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "IF salygos vidutinis laikas ( Senas variklis ) esant 5000 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************

*/
/*
cout << endl;


//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************

//*******************************************************************************************
//FOR ciklo testas ( 1 veiksmas )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"FOR_Naujo_1.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"FOR_Naujo_1.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( Naujas variklis ) esant 1 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	for(int i=0; i<1; i++)
		{}
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( c++ ) esant 1 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//FOR ciklo testas ( 10 veiksmu )
//*******************************************************************************************

{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"FOR_Naujo_10.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"FOR_Naujo_10.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( Naujas variklis ) esant 10 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	for(int i=0; i<10; i++)
		{}
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( c++ ) esant 10 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//FOR ciklo testas ( 100 veiksmu )
//*******************************************************************************************

{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"FOR_Naujo_100.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"FOR_Naujo_100.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( Naujas variklis ) esant 100 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	for(int i=0; i<100; i++)
		{}
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( c++ ) esant 100 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//FOR ciklo testas ( 1000 veiksmu )
//*******************************************************************************************

{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"FOR_Naujo_1000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"FOR_Naujo_1000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( Naujas variklis ) esant 1000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	for(int i=0; i<1000; i++)
		{}
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( c++ ) esant 1000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//FOR ciklo testas ( 5000 veiksmu )
//*******************************************************************************************

{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"FOR_Naujo_5000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"FOR_Naujo_5000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( Naujas variklis ) esant 5000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	for(int i=0; i<5000; i++)
		{}
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( c++ ) esant 5000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//FOR ciklo testas ( 25000 veiksmu )
//*******************************************************************************************

{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"FOR_Naujo_25000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"FOR_Naujo_25000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( Naujas variklis ) esant 25000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	for(int i=0; i<25000; i++)
		{}
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( c++ ) esant 25000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//FOR ciklo testas ( 32000 veiksmu )
//*******************************************************************************************

{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"FOR_Naujo_32000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"FOR_Naujo_32000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( Naujas variklis ) esant 32000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	for(int i=0; i<32000; i++)
		{}
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "FOR ciklo vidutinis laikas ( c++ ) esant 32000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

*/

cout << endl;


//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************

//*******************************************************************************************
//WHILE ciklo testas ( 1 veiksmas )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"WHILE_Naujo_1.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"WHILE_Naujo_1.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( Naujas variklis ) esant 1 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int i(0);
	while(i<1)
		i++;
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( c++ ) esant 1 veiksmui: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//WHILE ciklo testas ( 10 veiksmu )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"WHILE_Naujo_10.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"WHILE_Naujo_10.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( Naujas variklis ) esant 10 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int i(0);
	while(i<10)
		i++;
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( c++ ) esant 10 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//WHILE ciklo testas ( 100 veiksmu )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"WHILE_Naujo_100.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"WHILE_Naujo_100.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( Naujas variklis ) esant 100 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int i(0);
	while(i<100)
		i++;
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( c++ ) esant 100 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//WHILE ciklo testas ( 1000 veiksmu )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"WHILE_Naujo_1000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"WHILE_Naujo_1000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( Naujas variklis ) esant 1000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int i(0);
	while(i<1000)
		i++;
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( c++ ) esant 1000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//WHILE ciklo testas ( 5000 veiksmu )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"WHILE_Naujo_5000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"WHILE_Naujo_5000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( Naujas variklis ) esant 5000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int i(0);
	while(i<5000)
		i++;
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( c++ ) esant 5000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//WHILE ciklo testas ( 10000 veiksmu )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"WHILE_Naujo_10000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"WHILE_Naujo_10000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( Naujas variklis ) esant 10000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int i(0);
	while(i<10000)
		i++;
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( c++ ) esant 10000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;

//*******************************************************************************************
//WHILE ciklo testas ( 32000 veiksmu )
//*******************************************************************************************
{
TScriptManager<CTestClass_House> airthmetic_scriptManager_1(&house);
airthmetic_scriptManager_1.LoadScript(L"WHILE_Naujo_32000.txt");

for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();
	
	airthmetic_scriptManager_1.RunScript(L"WHILE_Naujo_32000.txt");

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( Naujas variklis ) esant 32000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************
{
averageTime = 0;
for(unsigned i=0; i<numArthTest; i++)
	{
	beginTime = clock();

	{
	int i(0);
	while(i<32000)
		i++;
	}

	endTime = clock();
	
	averageTime += endTime-beginTime;
	}
averageTime/=numArthTest;

cout << "WHILE ciklo vidutinis laikas ( c++ ) esant 32000 veiksmu: " << averageTime << endl;
}
//*******************************************************************************************

cout << endl;




int m;
cin >> m;



	return 0;
}

