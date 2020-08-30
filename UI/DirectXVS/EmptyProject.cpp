//--------------------------------------------------------------------------------------
// File: EmptyProject.cpp
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include "DXUT.h"
#include "DXUTsettingsdlg.h"
#include "SDKmisc.h"
#include "DXUTCamera.h"

#include <time.h>

#include <strsafe.h>

#include <sstream>
#include <string>
using namespace std;

#include <CText.h>
using Regina::CText;

#include <CFont.h>
#include <CLabel.h>
#include <CImage.h>
#include <CInterface.h>
#include <CInterfaceManager.h>
#include <CMessageManager.h>
#include <CUI.h>
#include <CUIManager.h>
using namespace Regina::UI;

#include <CFontManager.h>
#include <CTextureManager.h>
#include <CRenderManager_2D.h>
using namespace Regina::Graphics;

CUIManager* ui(NULL);

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

FontManager->Init(pd3dDevice);
TextureManager->Init(pd3dDevice);
RenderManager_2D->Init(pd3dDevice);


C2DTexture* test = TextureManager->Get2D(L"Alpha Test.png");
//unsigned r = test->GetColorA(14, 1);
//int m(0);
/*
vector<wstring> interface_manager_init_script;
interface_manager_init_script.push_back(L"Interface interface_1");
interface_manager_init_script.push_back(L"{");
interface_manager_init_script.push_back(L"Image image_1");
interface_manager_init_script.push_back(L"{");
interface_manager_init_script.push_back(L"positionX = 75;");
interface_manager_init_script.push_back(L"positionY = 75;");
interface_manager_init_script.push_back(L"textureName = \"Smile.png\";");
interface_manager_init_script.push_back(L"scriptName_OnFrameMove = \"UI_OnFrameMove_Blink.txt\";");
interface_manager_init_script.push_back(L"scriptName_OnLeftClick = \"UI_OnLeftClick.txt\";");
interface_manager_init_script.push_back(L"scriptName_OnRightClick = \"UI_OnRightClick.txt\";");
interface_manager_init_script.push_back(L"}");
interface_manager_init_script.push_back(L"Label label_1");
interface_manager_init_script.push_back(L"{");
interface_manager_init_script.push_back(L"positionX = 145;");
interface_manager_init_script.push_back(L"positionY = 65;");
interface_manager_init_script.push_back(L"height = 24;");
interface_manager_init_script.push_back(L"scriptName_OnMouseFocus = \"UI_OnMouseFocus.txt\";");
interface_manager_init_script.push_back(L"scriptName_OnMouseUnfocus = \"UI_OnMouseUnFocus.txt\";");
interface_manager_init_script.push_back(L"scriptName_OnLeftClick = \"UI_OnLeftClick.txt\";");
interface_manager_init_script.push_back(L"scriptName_OnRightClick = \"UI_OnRightClick.txt\";");
interface_manager_init_script.push_back(L"}");
interface_manager_init_script.push_back(L"Label label_2");
interface_manager_init_script.push_back(L"{");
interface_manager_init_script.push_back(L"positionX = 600;");
interface_manager_init_script.push_back(L"positionY = 500;");
interface_manager_init_script.push_back(L"height = 16;");
interface_manager_init_script.push_back(L"}");
interface_manager_init_script.push_back(L"EditBox editbox_1");
interface_manager_init_script.push_back(L"{");
interface_manager_init_script.push_back(L"positionX = 250;");
interface_manager_init_script.push_back(L"positionY = 500;");
interface_manager_init_script.push_back(L"maxTextSize = 252;");
interface_manager_init_script.push_back(L"text_offsetX = -126;");
interface_manager_init_script.push_back(L"text_offsetY = -15;");
interface_manager_init_script.push_back(L"text_height = 32;");
interface_manager_init_script.push_back(L"backgroundImage_textureName = \"UIEditBox0.png\";");
interface_manager_init_script.push_back(L"markerImage_textureName = \"UIEditBox1.png\";");
interface_manager_init_script.push_back(L"}");
interface_manager_init_script.push_back(L"EditBox editbox_2");
interface_manager_init_script.push_back(L"{");
interface_manager_init_script.push_back(L"positionX = 250;");
interface_manager_init_script.push_back(L"positionY = 600;");
interface_manager_init_script.push_back(L"maxTextSize = 252;");
interface_manager_init_script.push_back(L"text_offsetX = -126;");
interface_manager_init_script.push_back(L"text_offsetY = -15;");
interface_manager_init_script.push_back(L"text_height = 32;");
interface_manager_init_script.push_back(L"backgroundImage_textureName = \"UIEditBox0.png\";");
interface_manager_init_script.push_back(L"markerImage_textureName = \"UIEditBox1.png\";");
interface_manager_init_script.push_back(L"}");
interface_manager_init_script.push_back(L"}");

interfaceManager = new CInterfaceManager(DXUTGetHWND(), D3DXVECTOR2(1024, 768), L"English");
interfaceManager->Load(interface_manager_init_script);

vector<wstring> message_manager_init_script;
message_manager_init_script.push_back(L"MessageBox messageBox_1");
message_manager_init_script.push_back(L"{");
message_manager_init_script.push_back(L"maxMessageTextSize = 254;");
message_manager_init_script.push_back(L"messageText_offsetX = -126;");
message_manager_init_script.push_back(L"messageText_offsetY = -100;");
message_manager_init_script.push_back(L"messageText_height = 32;");
message_manager_init_script.push_back(L"backgroundImage_textureName = \"UIMessageBox0.png\";");
message_manager_init_script.push_back(L"okButtonImage_offsetX = +85;");
message_manager_init_script.push_back(L"okButtonImage_offsetY = -35;");
message_manager_init_script.push_back(L"okButtonImage_textureName = \"UIMessageBox1.png\";");
message_manager_init_script.push_back(L"}");
message_manager_init_script.push_back(L"InputQuery inputQuery_1");
message_manager_init_script.push_back(L"{");
message_manager_init_script.push_back(L"maxInputTextSize = 254;");
message_manager_init_script.push_back(L"maxQuestionTextSize = 254;");
message_manager_init_script.push_back(L"inputText_offsetX = -126;");
message_manager_init_script.push_back(L"inputText_offsetY = -100;");
message_manager_init_script.push_back(L"inputText_height = 24;");
message_manager_init_script.push_back(L"questionText_offsetX = -126;");
message_manager_init_script.push_back(L"questionText_offsetY = -125;");
message_manager_init_script.push_back(L"questionText_height = 28;");
message_manager_init_script.push_back(L"backgroundImage_textureName = \"UIMessageBox0.png\";");
message_manager_init_script.push_back(L"okButtonImage_offsetX = +85;");
message_manager_init_script.push_back(L"okButtonImage_offsetY = -35;");
message_manager_init_script.push_back(L"okButtonImage_textureName = \"UIMessageBox1.png\";");
message_manager_init_script.push_back(L"}");
message_manager_init_script.push_back(L"QuestionBox questionBox_1");
message_manager_init_script.push_back(L"{");
message_manager_init_script.push_back(L"maxQuestionTextSize = 254;");
message_manager_init_script.push_back(L"questionText_offsetX = -126;");
message_manager_init_script.push_back(L"questionText_offsetY = -125;");
message_manager_init_script.push_back(L"questionText_height = 28;");
message_manager_init_script.push_back(L"backgroundImage_textureName = \"UIMessageBox0.png\";");
message_manager_init_script.push_back(L"yesButtonImage_offsetX = +85;");
message_manager_init_script.push_back(L"yesButtonImage_offsetY = -35;");
message_manager_init_script.push_back(L"yesButtonImage_textureName = \"UIMessageBox1.png\";");
message_manager_init_script.push_back(L"noButtonImage_offsetX = -85;");
message_manager_init_script.push_back(L"noButtonImage_offsetY = -35;");
message_manager_init_script.push_back(L"noButtonImage_textureName = \"UIMessageBox1.png\";");
message_manager_init_script.push_back(L"yesButtonText_line = \"Yes\";");
message_manager_init_script.push_back(L"yesButtonText_offsetX = +85;");
message_manager_init_script.push_back(L"yesButtonText_offsetY = -35;");
message_manager_init_script.push_back(L"noButtonText_line = \"No\";");
message_manager_init_script.push_back(L"noButtonText_offsetX = -85;");
message_manager_init_script.push_back(L"noButtonText_offsetY = -35;");
message_manager_init_script.push_back(L"}");

messageManager = new CMessageManager(DXUTGetHWND(), D3DXVECTOR2(1024, 768), L"English");
messageManager->Load(message_manager_init_script);

vector<wstring> interface_manager_init_script_generated;
interfaceManager->GetInitializingText(interface_manager_init_script_generated);

vector<wstring> message_manager_init_script_generated;
messageManager->GetInitializingText(message_manager_init_script_generated);

CText i_text(interface_manager_init_script_generated);
CText m_text(message_manager_init_script_generated);

i_text.Save(L"C:\\i.txt");
m_text.Save(L"C:\\m.txt");*/

ui = new CUIManager(DXUTGetHWND(), D3DXVECTOR2(1024, 768), L"English", L"TestInterface");
//ui->Save(L"temp");

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

if(ui!=NULL)
	ui->SetScreenResolution(D3DXVECTOR2(pBackBufferSurfaceDesc->Width, pBackBufferSurfaceDesc->Height));

FontManager->OnResetDevice();
RenderManager_2D->OnResetDevice();

    return S_OK;
}


//--------------------------------------------------------------------------------------
// Handle updates to the scene.  This is called regardless of which D3D API is used
//--------------------------------------------------------------------------------------
void CALLBACK OnFrameMove( double fTime, float fElapsedTime, void* pUserContext )
{
/*
interfaceManager->SetProperty(L"interface_1", L"label_1", e_UIObjectProperty_Line, DXUTGetFrameStats(true));

wstring intersectingObject(L"");
if(interfaceManager->GetFirstIntersection(L"interface_1", Cursor_Position(DXUTGetHWND()), intersectingObject) == true)
	interfaceManager->SetProperty(L"interface_1", L"label_2", e_UIObjectProperty_Line, L"Intersecting: " + intersectingObject);
else
	interfaceManager->SetProperty(L"interface_1", L"label_2", e_UIObjectProperty_Line, L"Intersecting: none");
*//*
static wstring ans;
if(ui->QuestionBox(L"questionBox_1", L"Do You like me?", &ans))
	{
	ui->MessageBox(L"messageBox_1", ans);
	}
	
/*static wstring ans;
if(ui->InputQuery(L"inputQuery_1", L"What is your name?", &ans))
	{
	ui->MessageBox(L"messageBox_1", ans);
	}
*/



ui->SetProperty(L"interface_1", L"label_1", e_UIObjectProperty_Line, DXUTGetFrameStats(true));
//ui->SetProperty(L"MESSAGE_TEMPLATE", L"questionBox_1", e_UIObjectProperty_ScaleX, (sin(fTime)+1.01)*2);
//ui->SetProperty(L"MESSAGE_TEMPLATE", L"questionBox_1", e_UIObjectProperty_ScaleY, (sin(fTime)+1.01)*2);

wstring intersectingObject(L"");
if(ui->GetFirstIntersection(L"interface_1", Cursor_Position(DXUTGetHWND()), intersectingObject) == true)
	ui->SetProperty(L"interface_1", L"label_2", e_UIObjectProperty_Line, L"Intersecting: " + intersectingObject);
else
	ui->SetProperty(L"interface_1", L"label_2", e_UIObjectProperty_Line, L"Intersecting: none");




/*
static wstring ans;
if(ui->QuestionBox(L"questionBox_1", L"Do You like me?", &ans))
	{
	}
*/

ui->FrameMove(fElapsedTime);
}


//--------------------------------------------------------------------------------------
// Render the scene using the D3D9 device
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9FrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
{
pd3dDevice->Clear( 0L, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,0,255), 1.0f, 0L );
if( SUCCEEDED( pd3dDevice->BeginScene() ) )
{
ui->Begin();

ui->Render(L"interface_1");

ui->End();

RenderManager_2D->Render();

pd3dDevice->EndScene();
}
}


//--------------------------------------------------------------------------------------
// Handle messages to the application 
//--------------------------------------------------------------------------------------
LRESULT CALLBACK MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
                          bool* pbNoFurtherProcessing, void* pUserContext )
{
if(ui!=NULL)
	*pbNoFurtherProcessing = ui->MsgProc(uMsg, wParam);

    return 0;
}


//--------------------------------------------------------------------------------------
// Release D3D9 resources created in the OnD3D9ResetDevice callback 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9LostDevice( void* pUserContext )
{
FontManager->OnLostDevice();
RenderManager_2D->OnLostDevice();
}


//--------------------------------------------------------------------------------------
// Release D3D9 resources created in the OnD3D9CreateDevice callback 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9DestroyDevice( void* pUserContext )
{
FontManager->OnDestroyDevice();
TextureManager->OnDestroyDevice();
RenderManager_2D->OnDestroyDevice();
}


//--------------------------------------------------------------------------------------
// Initialize everything and go into a render loop
//--------------------------------------------------------------------------------------
INT WINAPI wWinMain( HINSTANCE, HINSTANCE, LPWSTR, int )
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

    // Initialize DXUT and create the desired Win32 window and Direct3D device for the application
    DXUTInit( true, true, L"-forcevsync:0" ); // Parse the command line and show msgboxes
    DXUTSetHotkeyHandling( false, true, false );  // handle the default hotkeys
    DXUTSetCursorSettings( true, true ); // Show the cursor and clip it when in full screen
    DXUTCreateWindow( L"UI Demo" );
    DXUTCreateDevice( true, 1024, 768 );



    // Start the render loop
    DXUTMainLoop();

	delete ui;
	ui = NULL;


	 return DXUTGetExitCode();
}


