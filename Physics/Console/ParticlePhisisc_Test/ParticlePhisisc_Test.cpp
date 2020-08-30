// ParticlePhisisc_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <ParticlePhisics.h>
#include <PhisicsManager.h>
#include <ForceRegistration.h>
#include <ParticleForceGenerator_Gravity.h>
#include <ContactData_ParticleParticle.h>
#include <ContactData_ParticleImmovable.h>
#include <PhisicalLink_Rod_Particle_Particle.h>
#include <PhisicalLink_Cable_Particle_Particle.h>
using namespace Regina;

#include <iostream>
#include <time.h>
#include <set>
#include <algorithm>
using namespace std;


class test
	{
	public:
		void update() { throw int(); }
	};

/*
void PhisicsManagerInitialaizePerformanceTest(int iCount)
{
cout << "Initialaizing "<< iCount << " Particles" << endl;
int st = clock(); 
for(int i=1; i<iCount; i++)
PhisicsManager->Add(new CParticlePhisics());
cout << "Initialized In : " << clock() -st << endl<<endl;
}

void PhisicsManagerRemovePerformanceTest(int iCount)
{
cout << "Removing " << iCount << " Particles" << endl;
int st = clock(); 
for(int i=10; i<iCount; i++)
PhisicsManager->Remove(i);
cout << "Removed In : " << clock() - st << endl<<endl;
}

void PhisicsManagerUpdatePerformanceTest(float iDuration)
{
cout << "Updating Particles" << endl;
int st = clock(); 
PhisicsManager->Update(iDuration);
cout << "Updated In : " << clock() - st << endl<<endl;
}*/




int _tmain(int argc, _TCHAR* argv[])
{
const float duration = 0.1f;

vector<CSpritePhisics*> sp;
vector<CParticlePhisics*> pp;
vector<CRotatingParticlePhisics*> rpp;


for(unsigned i=0; i<64000; i++)
	{
	sp.push_back(new CSpritePhisics());
	pp.push_back(new CParticlePhisics());
	rpp.push_back(new CRotatingParticlePhisics());
	}

cout << "Updating Sprites" << endl;
int st = clock();
for(unsigned i=0; i<64000; i++)
for(unsigned ii=0; ii<10; ii++)
sp[i]->Integrate(duration);
cout << "Updated In : " << clock() - st << endl<<endl;

cout << "Updating Sprites with double speed" << endl;
st = clock();
for(unsigned i=0; i<64000; i+=2)
for(unsigned ii=0; ii<10; ii++)
	{
	sp[i]->Integrate(duration);
	sp[i+1]->Integrate(duration);
	}
cout << "Updated In : " << clock() - st << endl<<endl;



cout << "Updating Particles" << endl;
st = clock();
for(unsigned i=0; i<64000; i++)
for(unsigned ii=0; ii<10; ii++)
pp[i]->Integrate(duration);
cout << "Updated In : " << clock() - st << endl<<endl;

cout << "Updating Rotating Particles" << endl;
st = clock();
for(unsigned i=0; i<64000; i++)
for(unsigned ii=0; ii<10; ii++)
rpp[i]->Integrate(duration);
cout << "Updated In : " << clock() - st << endl<<endl;

test tst;
try
	{
	CreateThread(&tst, &test::update);
	}
catch(int& exp)
	{
	cout << "Exception cought" << endl;
		int f;
	cin >>f;
	}
	


/*
PhisicsManagerInitialaizePerformanceTest(60000);
PhisicsManagerUpdatePerformanceTest(duration);
PhisicsManagerRemovePerformanceTest(10000);
PhisicsManagerUpdatePerformanceTest(duration);
PhisicsManagerInitialaizePerformanceTest(5000);
PhisicsManagerUpdatePerformanceTest(duration);
*/
int m;
cin >> m;



	return 0;
}

