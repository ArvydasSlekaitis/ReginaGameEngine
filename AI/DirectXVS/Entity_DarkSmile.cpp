///////////////////////////////////////////////////////////
//  Entity_DarkSmile.cpp
//  Created on:      26-08-2009
//  Last modified:   26-08-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#include <Entity_DarkSmile.h>
using namespace Regina;

//*****************************************************************************

CEntity_DarkSmile::CEntity_DarkSmile(const D3DXVECTOR3& iPosition) : CSimpleMovingEntity("DarkSmile", "Entity_DarkSmile", 2), steeringBehaviorManager(NULL)
	{
	particle = new CParticlePhisics();
	particle->SetPosition(iPosition);
	particle->SetMass(1); 
	particle->SetDamping(0.9995);
	PhisicsManager->AddParticle(particle);

	SetMaxSpeed(10);
	steeringBehaviorManager = new CSteeringBehaviorManager(this, 10);

	AIManager->AddCollisionObject_Dynamic("DarkSmile", this); 

	SetTransform(particle->Position(), Heading());
	}

//*****************************************************************************

CEntity_DarkSmile::CEntity_DarkSmile() : CSimpleMovingEntity("DarkSmile", "Entity_Sphere", 2), steeringBehaviorManager(NULL)
	{
	particle = new CParticlePhisics();
	particle->SetMass(1); 
	particle->SetDamping(0);
	PhisicsManager->AddParticle(particle);

	SetMaxSpeed(1);
	steeringBehaviorManager = new CSteeringBehaviorManager(this, 1);

	AIManager->AddCollisionObject_Dynamic("DarkSmile", this); 

	SetTransform(particle->Position(), Heading());
	}

//*****************************************************************************

CEntity_DarkSmile::~CEntity_DarkSmile()
	{
	AIManager->RemoveCollisionObject_Dynamic("DarkSmile", this);
	PhisicsManager->RemoveParticle(particle->ID());
	delete 	steeringBehaviorManager;
	}

//*****************************************************************************

void CEntity_DarkSmile::Update(float duration) 
	{
	//steeringBehaviorManager->Enable_Seek(D3DXVECTOR2(25, 25));
	//steeringBehaviorManager->Enable_Flee(D3DXVECTOR2(25, 25), 10);
	//steeringBehaviorManager->Enable_Arrive(D3DXVECTOR2(25, 25), CSteeringBehaviorManager::Fast);
	
	steeringBehaviorManager->SetMaxForce(15);
	SetMaxSpeed(15);

	if(ID() == 102)
		{
		steeringBehaviorManager->SetMaxForce(5);
		SetMaxSpeed(5);
		//steeringBehaviorManager->Enable_Wander(20, 1, 0.15);
		vector<D3DXVECTOR2> path;
		path.push_back(D3DXVECTOR2(10, 10));
		path.push_back(D3DXVECTOR2(10, 30));
		path.push_back(D3DXVECTOR2(30, 30));
		path.push_back(D3DXVECTOR2(30, 10));

		steeringBehaviorManager->Enable_PathFallow(path, false, 5);
		steeringBehaviorManager->Enable_ObstacleAvoidance();
		steeringBehaviorManager->Enable_WallAvoidance();
		//steeringBehaviorManager->Enable_Arrive(D3DXVECTOR2(-10, -10), CSteeringBehaviorManager::Fast);

		}
	else
		{
		if(ID() == 103)
			{
			//steeringBehaviorManager->Enable_Hide((CMovingEntity*)AIManager->EntityFromID(104), 100);
			steeringBehaviorManager->Enable_OffsetPursuit((CMovingEntity*)AIManager->EntityFromID(102), D3DXVECTOR2(2, -2));
			steeringBehaviorManager->Enable_ObstacleAvoidance();
			steeringBehaviorManager->Enable_WallAvoidance();
			}
		else
		if(ID() == 104)
			{
			//steeringBehaviorManager->Enable_Hide((CMovingEntity*)AIManager->EntityFromID(104), 100);
			steeringBehaviorManager->Enable_OffsetPursuit((CMovingEntity*)AIManager->EntityFromID(102), D3DXVECTOR2(-2, -2));
			steeringBehaviorManager->Enable_ObstacleAvoidance();
			steeringBehaviorManager->Enable_WallAvoidance();
			}
		else
			{
			steeringBehaviorManager->Enable_ObstacleAvoidance();
			steeringBehaviorManager->Enable_WallAvoidance();
			steeringBehaviorManager->Enable_Cohesion(10);
			//steeringBehaviorManager->Enable_Alignment(10);
			steeringBehaviorManager->Enable_Separation(10);
			}
		}


		//steeringBehaviorManager->Enable_Wander(20, 1, 0.15);

		//steeringBehaviorManager->Enable_Separation(100);

	particle->SetVelocity(steeringBehaviorManager->CalculateForce());
	SetTransform(particle->Position(), Heading());
	}

//*****************************************************************************

void CEntity_DarkSmile::Load(const vector<string>& iText) 
	{
	}

//*****************************************************************************

void CEntity_DarkSmile::HandleMsg(CTelegram* iTelegram)
	{
	delete iTelegram;
	}

//*****************************************************************************

void CEntity_DarkSmile::SetPosition(const D3DXVECTOR3& iPosition)
	{
	//particle->SetAcceleration(0, 0, 0);
	particle->SetVelocity(particle->Velocity()*0.5);
	particle->SetPosition(iPosition);
	SetTransform(particle->Position(), Heading());
	}

//*****************************************************************************