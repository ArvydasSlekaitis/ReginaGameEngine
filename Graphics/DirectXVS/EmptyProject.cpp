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

#include <CSimpleXFile.h>
#include <CSimpleXFileManager.h>
#include <CRenderObject_SimpleMesh.h>
#include <CScene.h>
#include <CMatterial_AmbientColor_DiffuseColor_SpecularColor.h>
#include <CMatterial_AmbientMap_DiffuseMap_SpecularColor.h>
#include <CDirectionalLight.h>
#include <CLightingManager.h>

#include <CRenderInstanceCreator.h>
#include <CRenderInstanceCreator_Default.h>
using namespace Regina;


#include <MeshDefinitions.h>
#include "ObjectInstance_Templates.h"


#include <CustomEntityCreator.h>





#include <CShadowSettings_DirectionalLight.h>


float* timee = new float(0);

ID3DXFont*                  g_pFont = NULL;          // Font for drawing text
ID3DXSprite*                g_pTextSprite = NULL;    // Sprite for batching draw text calls
CFirstPersonCamera*			camera=NULL;
CDXUTDialogResourceManager  g_DialogResourceManager; // manager for shared resources of dialogs
CDXUTDialog                 g_SampleUI;             // dialog for sample specific controls
CD3DSettingsDlg             g_SettingsDlg;          // Device settings dialog

/*CSimpleMesh*							meshRoom = NULL;

CSimpleMesh*							sphereMesh = NULL;
CObjectInstance_World<MATRIX_V4_V4_V4>* sphereInstance = NULL;

CSimpleMesh*							darkSmileMesh = NULL;
CObjectInstance_World<MATRIX_V4_V4_V4>* darkSmileInstance = NULL;
*/

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

CMatterialData* matData(NULL);
CMatterial* mat(NULL);
CScene* scene(NULL);




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


	if( pCaps->PixelShaderVersion < D3DPS_VERSION( 3, 0 ) )
	 return E_FAIL;
	if( pCaps->VertexShaderVersion < D3DVS_VERSION( 3, 0 ) )
	 return E_FAIL;


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
	
		

	SimpleXFileManager->Init(pd3dDevice);
	SimpleXFileManager->Create("sphere");


	TextureHandler->Init(pd3dDevice);
	/*TextureHandler->Load2D("Pavement.PNG");

	if(sphereMesh==NULL) sphereMesh = new CSimpleMesh(pd3dDevice, "sphere", VE_POS_UV);
	if(darkSmileMesh==NULL) darkSmileMesh = new CSimpleMesh(pd3dDevice, "DarkSmile", VE_POS_UV);
	if(meshRoom==NULL) meshRoom = new CSimpleMesh(pd3dDevice, "room", VE_POS_UV);
*/
	AIManager->Init(pd3dDevice, new CCustomEntityCreator());
	RenderInstanceCreator->Init(new CRenderInstanceCreator_Default());
	LightingManager->Init(pd3dDevice);
	LightingManager->SetGlobalAmbientColor(D3DXVECTOR3(1, 1, 1));

	matData = new CMatterial_AmbientMap_DiffuseMap_SpecularColor();
	mat = new CMatterial(matData);
	scene = new CScene(pd3dDevice);
	//LightingManager->AddDirectionalLight("dirLight1", D3DXVECTOR3(0, -1, 1), D3DXVECTOR3(1, 0.1, 0.1), CShadowSettings_DirectionalLight(1024, 32, 0, 1, D3DXVECTOR3(50, 50, 50), D3DXVECTOR3(0, -1, 1), 0.1, 250, D3DFMT_A8R8G8B8, D3DFMT_D24S8));//D3DFMT_R5G6B5
	
	mat->SetProperty("ambientMap", "DarkSmile.png");
	mat->SetProperty("diffuseMap", "DarkSmile.png");
	mat->SetProperty("specularColor", D3DXVECTOR3(1, 1, 1));
	mat->SetProperty("surfaceSmoothness", 2.5);


	scene->AddRenderObject(CRenderObject_SimpleMesh(CRenderObject::eType::type_Static, *mat, SimpleXFileManager->Get("room")->Mesh(), D3DXMATRIXA16(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1), 100, true, true));








/*
D3DXLoadMeshFromXA( "Data\\X\\Room.X", D3DXMESH_SYSTEMMEM, pd3dDevice, NULL, NULL, NULL, NULL, &Ground );
	D3DXComputeNormals( Ground, NULL );
D3DXCreateEffectFromFileA( pd3dDevice, "Data\\FX\\Shadow.fx", NULL, NULL, D3DXSHADER_NO_PRESHADER | D3DXFX_DONOTSAVESTATE | D3DXFX_DONOTSAVESAMPLERSTATE, NULL, &Shadow_Effect, NULL);
D3DXCreateEffectFromFileA( pd3dDevice, "Data\\FX\\Scene.fx", NULL, NULL, D3DXSHADER_NO_PRESHADER | D3DXFX_DONOTSAVESTATE | D3DXFX_DONOTSAVESAMPLERSTATE, NULL, &Scene_Effect, NULL);

//shadowMap = new CShadowMap_DirectionalLight(pd3dDevice);
*/


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


  //D3DXMATRIXA16 matProj;
	FLOAT fAspect = ((FLOAT)pBackBufferSurfaceDesc->Width) / pBackBufferSurfaceDesc->Height;
	//D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/4, fAspect, 1.0f, 20000 );
	
	camera->SetProjParams(D3DX_PI/4, fAspect, 1.0f, 20000); 

	pd3dDevice->SetTransform( D3DTS_PROJECTION, camera->GetProjMatrix() );


	g_SampleUI.SetLocation( 0, 0 );
    g_SampleUI.SetSize( pBackBufferSurfaceDesc->Width, pBackBufferSurfaceDesc->Height );

	g_SampleUI.GetControl( IDC_BUTTON1 )->SetLocation( 850, 110 );
	g_SampleUI.GetControl( IDC_SHOWHELP )->SetLocation( 850, 10 );
	g_SampleUI.GetControl( IDC_SHOWSTAT )->SetLocation( 850, 60 );
	g_SampleUI.GetControl( IDC_SLIDER )->SetLocation( pBackBufferSurfaceDesc->Width/2 - 100, pBackBufferSurfaceDesc->Height - 45 );

	if(scene!=NULL)
		scene->OnResetDevice();

	LightingManager->OnResetDevice();

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
pd3dDevice->Clear( 0L, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,0,0), 1.0f, 0L );
if( SUCCEEDED( pd3dDevice->BeginScene() ) )
{
//--------------------------------------------------------------------------------------------------
Statistics->Begin("RenderManager::Render");
//--------------------------------------------------------------------------------------------------




vector<CRenderObject_SimpleMesh> renderList;
for(unsigned i=0; i<10; i++)
	{
	renderList.push_back(CRenderObject_SimpleMesh(CRenderObject::eType::type_Dynamic, *mat, SimpleXFileManager->Get("sphere")->Mesh(), D3DXMATRIXA16(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, i*5, 0, 0, 1), 1, true, true));
	scene->AddRenderObject(renderList[i]);
	LightingManager->AddShadowCaster(renderList[i]);
	}

D3DXVECTOR3 LightPos;
	 LightPos.x=abs(cos(fTime*0.5)*10)+25;
	 LightPos.y=abs(sin(fTime*0.5)*10)+25;
	 LightPos.z=abs(cos(fTime*0.5)*10)+25;
D3DXVECTOR3	 LightLookAt=D3DXVECTOR3(0, 0, 0);


vector<CDirectionalLight> oDirectionalLights;
LightingManager->GetDirectionalLights(oDirectionalLights, D3DXVECTOR3(0, 0, 0), 10000);
if(oDirectionalLights.size()>0)
	{
	oDirectionalLights[0].SetDirection(LightLookAt-LightPos);
	oDirectionalLights[0].SetShadowMapSettings(CShadowSettings_DirectionalLight(1024, 32, 0, 1, LightPos, (LightLookAt-LightPos), 0.1, 100, D3DFMT_A8R8G8B8, D3DFMT_D24S8));
	}





//LightingManager->CreateShadowMaps();
scene->Render(RenderType_Default, *camera->GetViewMatrix(), *camera->GetProjMatrix(), *camera->GetEyePt());


scene->ClearDynamic();
//--------------------------------------------------------------------------------------------------
Statistics->End("RenderManager::Render");
//--------------------------------------------------------------------------------------------------


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
		case WM_LBUTTONDOWN:	/*CEntity_Sphere* sphere = new CEntity_Sphere(D3DXVECTOR3(camera->GetEyePt()->x, camera->GetEyePt()->y, camera->GetEyePt()->z), 1);
								sphere->Particle()->SetVelocity(D3DXVECTOR3(camera->GetWorldAhead()->x, camera->GetWorldAhead()->y, camera->GetWorldAhead()->z)*emitedParticleSpeed);
								AIManager->AddEntity(sphere);
								sphereObjects.push_back(sphere);
								break;*/int m; break;
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

	if(scene!=NULL)
		scene->OnLostDevice();

	LightingManager->OnLostDevice();
}


//--------------------------------------------------------------------------------------
// Release D3D9 resources created in the OnD3D9CreateDevice callback 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9DestroyDevice( void* pUserContext )
{
    SAFE_RELEASE( g_pFont );
	g_DialogResourceManager.OnD3D9DestroyDevice();
    g_SettingsDlg.OnD3D9DestroyDevice();
	


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
    DXUTCreateWindow( L"Particle Phisics, AI, Graphics Engine Simulation Demo" );
    DXUTCreateDevice( true, 1024, 768 );

	Settings->Load("ReginaEngineSettings.txt");

	//LoadScene(sceneType);

	Statistics->Enable();


	

    // Start the render loop
    DXUTMainLoop();

	sphereObjects.clear();
	darkSmileObjects.clear();
	TextureHandler->Clear();
	AIManager->Clear();
	PhisicsManager->Clear();
	LightingManager->Clear();
	/*delete sphereMesh;
	delete darkSmileMesh;
	delete meshRoom;*/
	delete camera;
	delete timee;
	/*delete sphereInstance;
	delete darkSmileInstance;*/

	delete scene;
	delete mat;
	delete matData;

	scene = NULL;
	mat = NULL;
	matData = NULL;

	SimpleXFileManager->ReleaseDevice();
	AIManager->ReleaseDevice();

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

	WCHAR wsz6[256];
	StringCchPrintf( wsz6, 256, L"Statistics::RenderManager::Render: %f", Statistics->GetAverage("RenderManager::Render") );
	wsz6[255] = L'\0';
	txtHelper.DrawTextLine( wsz6 );
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














void RenderShadowMap(IDirect3DDevice9* pd3dDevice)
{
/*shadowMap->Begin();


		
scene->Render(RenderType_Shadow, shadowMap->ViewTransform(), shadowMap->ProjTransform(), shadowMap->ShadowMapSettings().Position());



	

	Shadow_Effect->SetMatrix( "matWVP", &(D3DXMATRIXA16(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)*shadowMap->ViewTransform()*shadowMap->ProjTransform() ));

		Shadow_Effect->Begin(0, 0);
		Shadow_Effect->BeginPass(0);
		Ground->DrawSubset( 0 );
		Shadow_Effect->EndPass();
		Shadow_Effect->End();
	  

shadowMap->End();*/
}




