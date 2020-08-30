// LineTest.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "LineTest.h"
#include <gdiplus.h>
#include <time.h>
using namespace Gdiplus;

#include <Line_2D.h>
using namespace Regina;

static const float screenStartX = 250;
static const float screenStartY = 10;
static const float screenWidth = 750;
static const float screenHeight = 750;
static float cameraPositionX = 0;
static float cameraPositionY = 0;
static float cameraViewScale = 1.0f;

//-------------------------------------------------------------------

void DrawCircle(Graphics& graphics, Pen& pen, float iPositionX, float iPositionY, float iRadius)
	{
	graphics.DrawEllipse(&pen, iPositionX+screenStartX - iRadius/2, screenHeight - iPositionY+screenStartY - iRadius/2, iRadius, iRadius);
	}

//-------------------------------------------------------------------

void DrawLine(Graphics& graphics, Pen& pen, float iBeginX, float iBeginY, float iEndX, float iEndY)
	{
	graphics.DrawLine(&pen, iBeginX+screenStartX, screenHeight-iBeginY+screenStartY, iEndX+screenStartX, screenHeight-iEndY+screenStartY);
	}

//-------------------------------------------------------------------

VOID OnPaint(HDC hdc)
{
   Graphics graphics(hdc);

   Pen      pen(Color(255, 0, 0, 0));
   graphics.SetClip(Rect(screenStartX, screenStartY, screenWidth+1.8, screenHeight+1.8), CombineModeReplace);
   graphics.DrawLine(&pen, screenStartX, screenStartY, screenStartX + screenWidth, screenStartY);
   graphics.DrawLine(&pen, screenStartX + screenWidth, screenStartY, screenStartX + screenWidth, screenStartY + screenHeight);
   graphics.DrawLine(&pen, screenStartX + screenWidth, screenStartY + screenHeight, screenStartX, screenStartY + screenHeight);
   graphics.DrawLine(&pen, screenStartX, screenStartY + screenHeight, screenStartX, screenStartY);
   

   CLine_2D line(50, 0, 100, 200);

   DrawCircle(graphics, pen, 100, 100, 100);
   DrawLine(graphics, pen, line.Begin().x, line.Begin().y, line.End().x, line.End().y);

   float oX1, oY1, oX2, oY2, oPenetration;

   unsigned	num = line.Intersect(100, 100, 100/2, oX1, oY1,  oX2,  oY2,  oPenetration);


   if(num == 1)
	   {
		DrawCircle(graphics, pen, oX1, oY1, 5);
	   }
   if(num == 2)
	   {
	   DrawCircle(graphics, pen, oX1, oY1, 5);
	   DrawCircle(graphics, pen, oX2, oY2, 5);
	   }
}

//-------------------------------------------------------------------



#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_LINETEST, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LINETEST));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
   GdiplusStartupInput gdiplusStartupInput;
   ULONG_PTR           gdiplusToken;

	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);


	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LINETEST));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_LINETEST);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      0, 0, screenStartX + screenWidth + 20, screenStartY + screenHeight + 65, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		      OnPaint(hdc);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
