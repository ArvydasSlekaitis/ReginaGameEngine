//--------------------------------------------------------------------------------------
// File: EmptyProject.cpp
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include "DXUT.h"
#include "resource.h"
#include "DXUTsettingsdlg.h"
#include "SDKmisc.h"
#include "DXUTCamera.h"

#include <strsafe.h>

#include <sstream>
#include <string>
using namespace std;


//Regina v1
#include <SimpleMesh.h>
#include <objectinstance.h>
#include <Functions_Math.h>


//Regina v2
#include <PhisicsManager.h>
#include <RotatingParticlePhisics.h>
#include <Statistics.h>
#include <PhisicalLink_Rod_Particle_Particle.h>
#include <ParticleForceGenerator_Gravity.h>
#include <PhisicalLink_Cable_Particle_Particle.h>

#include <AIManager.h>
#include <Settings.h>
#include <Statistics.h>
using namespace Regina;


#include "MeshDefinitions.h"
#include "ObjectInstance_Templates.h"


#include <CustomEntityCreator.h>


float* timee = new float(0);

ID3DXFont*                  g_pFont = NULL;          // Font for drawing text
ID3DXSprite*                g_pTextSprite = NULL;    // Sprite for batching draw text calls
CFirstPersonCamera*			camera=NULL;
CDXUTDialogResourceManager  g_DialogResourceManager; // manager for shared resources of dialogs
CDXUTDialog                 g_SampleUI;             // dialog for sample specific controls
CD3DSettingsDlg             g_SettingsDlg;          // Device settings dialog

CSimpleMesh*							meshRoom = NULL;

CSimpleMesh*							sphereMesh = NULL;
CObjectInstance_World<MATRIX_V4_V4_V4>* sphereInstance = NULL;

CSimpleMesh*							darkSmileMesh = NULL;
CObjectInstance_World<MATRIX_V4_V4_V4>* darkSmileInstance = NULL;


void RenderText();
void InitApp();
void CALLBACK OnGUIEvent( UINT nEvent, int nControlID, CDXUTControl* pControl, void* pUserContext );

vector<CEntity_Sphere*>		sphereObjects;
vector<CEntity_DarkSmile*>	darkSmileObjects;

void LoadScene(int iType);
void RenderScene();
void CollisionDetection();

int sceneType=0;
float emitedParticleSpeed=100;
bool showStat = true;
bool showHelp = false;




//--------------------------------------------------------------------------------------
// UI control IDs
//--------------------------------------------------------------------------------------
#define IDC_BUTTON1    1
#define IDC_SLIDER     2
#define IDC_SHOWHELP   3
#define IDC_SHOWSTAT   4



//--------------------------------------------------------------------------------------
// Rejects any D3D9 devices that aren't acceptable to the app by returning false
//--------------------------------------------------------------------------------------
bool CALLBACK IsD3D9DeviceAcceptable( D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat,
                                      bool bWindowed, void* pUserContext )
{
    // Typically want to skip back buffer formats that don't support alpha blending
    IDirect3D9* pD3D = DXUTGetD3D9Object();
    if( FAILED( pD3D->CheckDeviceFormat( pCaps->AdapterOrdinal, pCaps->DeviceType,
                                         AdapterFormat, D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING,
                                         D3DRTYPE_TEXTURE, BackBufferFormat ) ) )
        return false;

    return true;
}


//--------------------------------------------------------------------------------------
// Before a device is created, modify the device settings as needed
//--------------------------------------------------------------------------------------
bool CALLBACK ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext )
{
    return true;
}


//--------------------------------------------------------------------------------------
// Create any D3D9 resources that will live through a device reset (D3DPOOL_MANAGED)
// and aren't tied to the back buffer size
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D9CreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
                                     void* pUserContext )
{
HRESULT hr;


	V_RETURN( g_DialogResourceManager.OnD3D9CreateDevice( pd3dDevice ) );
    V_RETURN( g_SettingsDlg.OnD3D9CreateDevice( pd3dDevice ) );
	
    V_RETURN( D3DXCreateFont( pd3dDevice, 15, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET,
                              OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
                              L"Arial", &g_pFont ) );

	camera = new CFirstPersonCamera();
	
	camera->SetViewParams(&D3DXVECTOR3(20, 20, 20), &D3DXVECTOR3(0, 0, 0));
		

	TextureHandler->Init(pd3dDevice);
	TextureHandler->Load2D("Pavement.PNG");

	if(sphereMesh==NULL) sphereMesh = new CSimpleMesh(pd3dDevice, "sphere", VE_POS_UV);
	if(darkSmileMesh==NULL) darkSmileMesh = new CSimpleMesh(pd3dDevice, "DarkSmile", VE_POS_UV);
	if(meshRoom==NULL) meshRoom = new CSimpleMesh(pd3dDevice, "room", VE_POS_UV);

	AIManager->Init(pd3dDevice, new CCustomEntityCreator());




    return S_OK;
}


//--------------------------------------------------------------------------------------
// Create any D3D9 resources that won't live through a device reset (D3DPOOL_DEFAULT) 
// or that are tied to the back buffer size 
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D9ResetDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
                                    void* pUserContext )
{
HRESULT hr;

    V_RETURN( g_DialogResourceManager.OnD3D9ResetDevice() );
    V_RETURN( g_SettingsDlg.OnD3D9ResetDevice() );

if( g_pFont )
        V_RETURN( g_pFont->OnResetDevice() );

    // Create a sprite to help batch calls when drawing many lines of text
    V_RETURN( D3DXCreateSprite( pd3dDevice, &g_pTextSprite ) );


  D3DXMATRIXA16 matProj;
	FLOAT fAspect = ((FLOAT)pBackBufferSurfaceDesc->Width) / pBackBufferSurfaceDesc->Height;
	D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/4, fAspect, 1.0f, 20000 );
	pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );


	g_SampleUI.SetLocation( 0, 0 );
    g_SampleUI.SetSize( pBackBufferSurfaceDesc->Width, pBackBufferSurfaceDesc->Height );

	g_SampleUI.GetControl( IDC_BUTTON1 )->SetLocation( 850, 110 );
	g_SampleUI.GetControl( IDC_SHOWHELP )->SetLocation( 850, 10 );
	g_SampleUI.GetControl( IDC_SHOWSTAT )->SetLocation( 850, 60 );
	g_SampleUI.GetControl( IDC_SLIDER )->SetLocation( pBackBufferSurfaceDesc->Width/2 - 100, pBackBufferSurfaceDesc->Height - 45 );


    return S_OK;
}


//--------------------------------------------------------------------------------------
// Handle updates to the scene.  This is called regardless of which D3D API is used
//--------------------------------------------------------------------------------------
void CALLBACK OnFrameMove( double fTime, float fElapsedTime, void* pUserContext )
{
*timee = fElapsedTime; 

Statistics->Begin("AIManager::Update");
AIManager->Update(fElapsedTime);
Statistics->End("AIManager::Update");

Statistics->Begin("PhisicsManager::Update");
PhisicsManager->Update(min(fElapsedTime, 0.016));
Statistics->End("PhisicsManager::Update");

camera->FrameMove(fElapsedTime);
}


//--------------------------------------------------------------------------------------
// Render the scene using the D3D9 device
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9FrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
{

	pd3dDevice->SetTransform( D3DTS_VIEW, camera->GetViewMatrix() );



pd3dDevice->Clear( 0L, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,255,0), 1.0f, 0L );
if( SUCCEEDED( pd3dDevice->BeginScene() ) )
{

pd3dDevice->SetSamplerState( 0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR );
pd3dDevice->SetSamplerState( 0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR );
pd3dDevice->SetRenderState( D3DRS_DITHERENABLE, FALSE );
pd3dDevice->SetRenderState( D3DRS_ZENABLE,      TRUE );
pd3dDevice->SetRenderState( D3DRS_LIGHTING,     FALSE );

pd3dDevice->SetTexture(0, TextureHandler->Get2D("Pavement.PNG")->Texture());
meshRoom->WorkingMesh()->DrawSubset(0);

RenderScene();



RenderText();
g_SampleUI.OnRender( fElapsedTime );

pd3dDevice->EndScene();
}
}


//--------------------------------------------------------------------------------------
// Handle messages to the application 
//--------------------------------------------------------------------------------------
LRESULT CALLBACK MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
                          bool* pbNoFurtherProcessing, void* pUserContext )
{

// Always allow dialog resource manager calls to handle global messages
    // so GUI state is updated correctly
    *pbNoFurtherProcessing = g_DialogResourceManager.MsgProc( hWnd, uMsg, wParam, lParam );
    if( *pbNoFurtherProcessing )
        return 0;

    if( g_SettingsDlg.IsActive() )
    {
        g_SettingsDlg.MsgProc( hWnd, uMsg, wParam, lParam );
        return 0;
    }

    // Give the dialogs a chance to handle the message first
    *pbNoFurtherProcessing = g_SampleUI.MsgProc( hWnd, uMsg, wParam, lParam );
    if( *pbNoFurtherProcessing )
        return 0;




if(camera!=NULL)
	{
	switch( uMsg )
		{
		case WM_LBUTTONDOWN:	CEntity_Sphere* sphere = new CEntity_Sphere(D3DXVECTOR3(camera->GetEyePt()->x, camera->GetEyePt()->y, camera->GetEyePt()->z), 1);
								sphere->Particle()->SetVelocity(D3DXVECTOR3(camera->GetWorldAhead()->x, camera->GetWorldAhead()->y, camera->GetWorldAhead()->z)*emitedParticleSpeed);
								AIManager->AddEntity(sphere);
								sphereObjects.push_back(sphere);
								break;
		}
		}


if(camera!=NULL)
camera->HandleMessages(hWnd, uMsg, wParam, lParam);
    return 0;
}


//--------------------------------------------------------------------------------------
// Release D3D9 resources created in the OnD3D9ResetDevice callback 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9LostDevice( void* pUserContext )
{
    if( g_pFont )
        g_pFont->OnLostDevice();

	g_DialogResourceManager.OnD3D9LostDevice();
    g_SettingsDlg.OnD3D9LostDevice();

    SAFE_RELEASE( g_pTextSprite );
}


//--------------------------------------------------------------------------------------
// Release D3D9 resources created in the OnD3D9CreateDevice callback 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9DestroyDevice( void* pUserContext )
{
    SAFE_RELEASE( g_pFont );
	g_DialogResourceManager.OnD3D9DestroyDevice();
    g_SettingsDlg.OnD3D9DestroyDevice();
	AIManager->ReleaseDevice();

}


//--------------------------------------------------------------------------------------
// Initialize everything and go into a render loop
//--------------------------------------------------------------------------------------
INT WINAPI wWinMain( HINSTANCE, HINSTANCE, LPWSTR, int )
{
	try
		{
    // Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

    // Set the callback functions
    DXUTSetCallbackD3D9DeviceAcceptable( IsD3D9DeviceAcceptable );
    DXUTSetCallbackD3D9DeviceCreated( OnD3D9CreateDevice );
    DXUTSetCallbackD3D9DeviceReset( OnD3D9ResetDevice );
    DXUTSetCallbackD3D9FrameRender( OnD3D9FrameRender );
    DXUTSetCallbackD3D9DeviceLost( OnD3D9LostDevice );
    DXUTSetCallbackD3D9DeviceDestroyed( OnD3D9DestroyDevice );
    DXUTSetCallbackDeviceChanging( ModifyDeviceSettings );
    DXUTSetCallbackMsgProc( MsgProc );
	DXUTSetCallbackFrameMove( ::OnFrameMove );

	InitApp();

    // Initialize DXUT and create the desired Win32 window and Direct3D device for the application
    DXUTInit( true, true, L"-forcevsync:0" ); // Parse the command line and show msgboxes
    DXUTSetHotkeyHandling( false, true, false );  // handle the default hotkeys
    DXUTSetCursorSettings( true, true ); // Show the cursor and clip it when in full screen
    DXUTCreateWindow( L"Particle Phisics Engine Simulation Demo" );
    DXUTCreateDevice( true, 1024, 768 );

	Settings->Load("ReginaEngineSettings.txt");

	LoadScene(sceneType);

	Statistics->Enable();


	

    // Start the render loop
    DXUTMainLoop();

	sphereObjects.clear();
	darkSmileObjects.clear();
	TextureHandler->Clear();
	AIManager->Clear();
	PhisicsManager->Clear();
	delete sphereMesh;
	delete darkSmileMesh;
	delete meshRoom;
	delete camera;
	delete timee;
	delete sphereInstance;
	delete darkSmileInstance;
	camera=NULL;
		}
	catch (const exception& excp)
		{
		ostringstream str;
		str << excp.what();
		
		throw excp;
		}


    return DXUTGetExitCode();
}

//--------------------------------------------------------------------------------------------------

void RenderText()
{
    // The helper object simply helps keep track of text position, and color
    // and then it calls pFont->DrawText( m_pSprite, strMsg, -1, &rc, DT_NOCLIP, m_clr );
    // If NULL is passed in as the sprite object, then it will work however the 
    // pFont->DrawText() will not be batched together.  Batching calls will improves performance.
    CDXUTTextHelper txtHelper( g_pFont, g_pTextSprite, 15 );

    // Output statistics
    txtHelper.Begin();
    txtHelper.SetInsertionPos( 5, 5 );
    txtHelper.SetForegroundColor( D3DXCOLOR( 0.0f, 0.0f, 1.0f, 1.0f ) );
    
if(showStat==true)
	{
	txtHelper.DrawTextLine( DXUTGetFrameStats( DXUTIsVsyncEnabled() ) );
    txtHelper.DrawTextLine( DXUTGetDeviceStats() );

	txtHelper.SetForegroundColor( D3DXCOLOR( 0.0f, 0.1f, 1.0f, 1.0f ) );

	txtHelper.DrawTextLine( L"");

	WCHAR wsz[256];
	StringCchPrintf( wsz, 256, L"Simulating %u Particles", sphereObjects.size() );
	wsz[255] = L'\0';
	txtHelper.DrawTextLine( wsz );

	txtHelper.DrawTextLine( L"");



	switch(sceneType)
		{
		case(0):	txtHelper.DrawTextLine( L"Simulation Type : Integrator" );
					break;

		case(1):	txtHelper.DrawTextLine( L"Simulation Type : Contact Resolver && Phisical Link Rod" );
					break;
	
		case(2):	txtHelper.DrawTextLine( L"Simulation Type : Contact Resolver && Gravity && Phisical Link Rod" );	
					break;

		case(3):	txtHelper.DrawTextLine( L"Simulation Type : Contact Resolver && Gravity && Phisical Link Cable" );	
					break;
					
		};

				/*	
	txtHelper.DrawTextLine( L"");
	WCHAR wsz2[256];
	StringCchPrintf( wsz2, 256, L"Contact Resolver - Penetration Iterations Used: %u", ContactResolver->PenetrationIterationsUsed() );
	wsz2[255] = L'\0';
	txtHelper.DrawTextLine( wsz2 );

	WCHAR wsz3[256];
	StringCchPrintf( wsz3, 256, L"Contact Resolver - Velocity Iterations Used: %u", ContactResolver->VelocityIterationsUsed() );
	wsz3[255] = L'\0';
	txtHelper.DrawTextLine( wsz3 );
*/
	WCHAR wsz4[256];
	StringCchPrintf( wsz4, 256, L"Statistics::AIManager::Update: %f", Statistics->GetAverage("AIManager::Update") );
	wsz4[255] = L'\0';
	txtHelper.DrawTextLine( wsz4 );

	WCHAR wsz5[256];
	StringCchPrintf( wsz5, 256, L"Statistics::PhisicsManager::Update: %f", Statistics->GetAverage("PhisicsManager::Update") );
	wsz5[255] = L'\0';
	txtHelper.DrawTextLine( wsz5 );
	}

if(showHelp==true)
	{
	txtHelper.SetInsertionPos( 5, 500 );
	
	txtHelper.DrawTextLine( L"To enable or disable help press ShowHelp button." );	
	txtHelper.DrawTextLine( L"To enable or disable statistics press ShowStat button." );	
	txtHelper.DrawTextLine( L"");
	txtHelper.DrawTextLine( L"There are four different simulation types."); 
	txtHelper.DrawTextLine( L"First shows integrator performance, second simulates rods," );	
	txtHelper.DrawTextLine( L"third simulates rods with applied gravity force for several particles,");
	txtHelper.DrawTextLine( L"thourth simulates cables with applied gravity force for several particles.");
	txtHelper.DrawTextLine( L"To change simulation type, press ChageSimulationType button.");
	txtHelper.DrawTextLine( L"");
	txtHelper.DrawTextLine( L"You can navigate with WASD keys.");
	txtHelper.DrawTextLine( L"To turn around, press and hold righ mouse, then move mouse");
	txtHelper.DrawTextLine( L"");
	txtHelper.DrawTextLine( L"You can shot a particle at any time by pressing  left mouse button.");
	txtHelper.DrawTextLine( L"To change emitted particle speed, move slider, located at top down of sreen, to left or right");


	}

	txtHelper.SetInsertionPos( 900, 750 );
	txtHelper.DrawTextLine( L"Arvydas Šlekaitis(C)" );

    txtHelper.End();
}

//--------------------------------------------------------------------------------------------------

void LoadScene(int iType)
{
sceneType = iType;
AIManager->Clear();
PhisicsManager->Clear();
sphereObjects.clear();
darkSmileObjects.clear();

AIManager->LoadMap("1", false);

switch(iType)
	{
	case(0): 
			for(unsigned i=0; i<10; i++)
			for(unsigned ii=0; ii<10; ii++)
				{
				CEntity_Sphere* sphere = new CEntity_Sphere(D3DXVECTOR3(2+float(i)*2, 10, 2+float(ii)*2), 0.5);
				AIManager->AddEntity(sphere);
				sphereObjects.push_back(sphere);
				}

			for(unsigned i=0; i<10; i++)
			for(unsigned ii=0; ii<5; ii++)
				{
				CEntity_DarkSmile* darkSmile = new CEntity_DarkSmile(D3DXVECTOR3(2+float(i)*4, 0.5, 10+float(ii)*4));
				AIManager->AddEntity(darkSmile);
				darkSmileObjects.push_back(darkSmile);
				}

			break;

	/*case(1): 
			for(unsigned i=0; i<10; i++)
			for(unsigned ii=0; ii<10; ii++)
				{
				CParticlePhisics* particle = new CParticlePhisics();
				particle->SetPosition(D3DXVECTOR3(float(i)*2, 0, float(ii)*2));
				particle->SetMass(1);
				particle->SetDamping(0.99995);
				PhisicsManager->AddParticle(particle);
				objects.push_back(particle);

				if(ii!=0)
					PhisicsManager->AddPhisicalLink(new CPhisicalLink_Rod_Particle_Particle(objects[objects.size()-1], objects[objects.size()-2], 2.0));
				}

			break;


	case(2): 
			for(unsigned i=0; i<10; i++)
			for(unsigned ii=0; ii<25; ii++)
				{
				CParticlePhisics* particle = new CParticlePhisics();
				particle->SetPosition(D3DXVECTOR3(float(i)*2, 0, float(ii)*2));
				particle->SetMass(1);
				particle->SetDamping(0.99995);
				PhisicsManager->AddParticle(particle);
				objects.push_back(particle);

				if(ii==0 || ii==9 || ii==18 || ii==24)
					PhisicsManager->AddForce(new CParticleForceGenerator_Gravity(objects[objects.size()-1]));

				if(ii!=0)
					{
					PhisicsManager->AddPhisicalLink(new CPhisicalLink_Rod_Particle_Particle(objects[objects.size()-1], objects[objects.size()-2], 2.0));
					}
				}

			break;


	case(3): 
			for(unsigned i=0; i<10; i++)
			for(unsigned ii=0; ii<25; ii++)
				{
				CParticlePhisics* particle = new CParticlePhisics();
				particle->SetPosition(D3DXVECTOR3(float(i)*2, 0, float(ii)*2));
				particle->SetMass(1);
				particle->SetDamping(0.99995);
				PhisicsManager->AddParticle(particle);
				objects.push_back(particle);

				if(ii==0 || ii==9 || ii==18 || ii==24)
					PhisicsManager->AddForce(new CParticleForceGenerator_Gravity(objects[objects.size()-1]));

				if(ii!=0)
					{
					PhisicsManager->AddPhisicalLink(new CPhisicalLink_Cable_Particle_Particle(objects[objects.size()-1], objects[objects.size()-2], 2.0));
					}
				}*/

			break;

	}

AIManager->LoadComplete();


}

//--------------------------------------------------------------------------------------------------

void RenderScene()
{
if(sphereInstance!=NULL) delete sphereInstance;
sphereInstance = new CObjectInstance_World<MATRIX_V4_V4_V4>(sphereMesh, sphereMesh->WorkingMesh(), VE_INSTANCE_POS_UV_WORLD);

for(unsigned i=0; i<sphereObjects.size(); i++)
	{
	sphereInstance->Add(D3DXMATRIXA16(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, sphereObjects[i]->Position().x, sphereObjects[i]->Position().y, sphereObjects[i]->Position().z, 1));
	}
sphereInstance->Render(0);

if(darkSmileInstance!=NULL) delete darkSmileInstance;
darkSmileInstance = new CObjectInstance_World<MATRIX_V4_V4_V4>(darkSmileMesh, darkSmileMesh->WorkingMesh(), VE_INSTANCE_POS_UV_WORLD);

for(unsigned i=0; i<darkSmileObjects.size(); i++)
	{
	darkSmileInstance->Add(D3DXMATRIXA16(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, darkSmileObjects[i]->Position().x, darkSmileObjects[i]->Position().y, darkSmileObjects[i]->Position().z, 1));
	}
darkSmileInstance->Render(0);
}

//--------------------------------------------------------------------------------------------------

void CollisionDetection()
{
/*for(unsigned i=0; i<objects.size(); i++)
for(unsigned ii=i+1; ii<objects.size(); ii++)
	{
	float curLength = D3DXVec3Length(&(objects[i]->Position() - objects[ii]->Position())); 
	if(curLength<1)
		{
		CContactData* contact = new CContactData_ParticleParticle(objects[i], objects[ii]);

		D3DXVECTOR3 contactNormal =  objects[i]->Position() - objects[ii]->Position();
		D3DXVec3Normalize(&contactNormal, &contactNormal);

		contact->SetContactNormal(contactNormal);
		contact->SetPenetration(1-curLength);
		contact->SetRestitution(1);

		PhisicsManager->AddContact(contact);
		}
	}

for(unsigned i=0; i<objects.size(); i++)
	{
	if(objects[i]->Position().x+0.5 > 100)
		{
		PhisicsManager->AddContact(new CContactData_ParticleImmovable(objects[i], D3DXVECTOR3(-1, 0, 0), objects[i]->Position().x-100+0.5, 0.1));
		}
	else

	if(objects[i]->Position().x-0.5 < -100)
		{
		PhisicsManager->AddContact(new CContactData_ParticleImmovable(objects[i], D3DXVECTOR3(1, 0, 0), objects[i]->Position().x+100-0.5, 0.1));
		}
	else

	if(objects[i]->Position().y+0.5 > 100)
		{
		PhisicsManager->AddContact(new CContactData_ParticleImmovable(objects[i], D3DXVECTOR3(0, -1, 0), objects[i]->Position().y-100+0.5, 0.1));
		}
	else

	if(objects[i]->Position().y-0.5 < -100)
		{
		PhisicsManager->AddContact(new CContactData_ParticleImmovable(objects[i], D3DXVECTOR3(0, 1, 0), objects[i]->Position().y+100-0.5, 0.1));
		}
	else

	if(objects[i]->Position().z+0.5 > 100)
		{
		PhisicsManager->AddContact(new CContactData_ParticleImmovable(objects[i], D3DXVECTOR3(0, 0, -1), objects[i]->Position().z-100+0.5, 0.1));
		}
	else

	if(objects[i]->Position().z-0.5 < -100)
		{
		PhisicsManager->AddContact(new CContactData_ParticleImmovable(objects[i], D3DXVECTOR3(0, 0, 1), objects[i]->Position().z+100-0.5, 0.1));
		}
	

	}*/
}

//--------------------------------------------------------------------------------------------------


void InitApp()
{
    // Initialize dialogs
    g_SettingsDlg.Init( &g_DialogResourceManager );
	g_SampleUI.Init( &g_DialogResourceManager );
	g_SampleUI.SetCallback( OnGUIEvent );
    g_SampleUI.AddButton( IDC_BUTTON1, L"Change Simulation Type", 10, 390, 160, 35, L'I' );
	g_SampleUI.AddButton( IDC_SHOWHELP, L"Show Help", 10, 390, 160, 35, L'H' );
	g_SampleUI.AddButton( IDC_SHOWSTAT, L"Show Stat", 10, 390, 160, 35, L'G' );
	g_SampleUI.AddSlider( IDC_SLIDER, 200, 450, 200, 24, 0, 200, 100, false );
}

//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------
// Handles the GUI events
//--------------------------------------------------------------------------------------
void CALLBACK OnGUIEvent( UINT nEvent, int nControlID, CDXUTControl* pControl, void* pUserContext )
{
    WCHAR wszOutput[1024];

    switch( nControlID )
    {
        case IDC_BUTTON1: /*sceneType++; if(sceneType>3) sceneType=0;*/ LoadScene(sceneType);
             break;

        case IDC_SHOWHELP: if(showHelp==false) showHelp=true; else showHelp=false;
             break;

		case IDC_SHOWSTAT: if(showStat==false) showStat=true; else showStat=false;
             break;

		case IDC_SLIDER:
			emitedParticleSpeed = ( ( CDXUTSlider* )pControl )->GetValue();
			break;
	}

}
