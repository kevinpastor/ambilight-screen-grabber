#include <iostream>

#include <windows.h>
#include <Wtsapi32.h>
#include <iostream>

#include "resource.h"
#include "Ambilight.h"
#include "Options.h"

#define ID_TRAY_APP_ICON 1001
#define ID_TRAY_EXIT 1002
#define WM_SYSICON (WM_USER + 1)

HWND hWnd;
HMENU Hmenu;
NOTIFYICONDATA notifyIconData;
Options options;
Ambilight ambilight(options);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		// Window is created
		ShowWindow(hWnd, SW_HIDE);
		Hmenu = CreatePopupMenu();
		AppendMenu(Hmenu, MF_STRING, ID_TRAY_EXIT, TEXT("Exit"));
		break;

	case WM_WTSSESSION_CHANGE:
		switch (wParam)
		{
		case WTS_SESSION_UNLOCK:
			// User unlocked session
			ambilight.start();
			break;

		case WTS_SESSION_LOCK:
			// User locked session
			ambilight.pause();
			break;

		case WTS_SESSION_LOGOFF:
			// User logged off
			ambilight.stop();
			break;
		}
		break;

	case WM_SYSICON:
		// Taskbar icon is focused
		if (lParam == WM_RBUTTONDOWN)
		{
			// Get current mouse position.
			POINT curPoint;
			GetCursorPos(&curPoint);
			SetForegroundWindow(hWnd);

			// TrackPopupMenu blocks the app until TrackPopupMenu returns
			UINT clicked = TrackPopupMenu(Hmenu, TPM_RETURNCMD | TPM_NONOTIFY, curPoint.x, curPoint.y, NULL, hwnd, NULL);

			SendMessage(hwnd, WM_NULL, NULL, NULL); // Send benign message to window to make sure the menu goes away.
			switch (clicked)
			{
			case ID_TRAY_EXIT:
				// Quit the application
				ambilight.stop();
				Shell_NotifyIcon(NIM_DELETE, &notifyIconData);
				PostQuitMessage(0);
				break;
			}
		}
		break;

	case WM_ENDSESSION:
		ambilight.stop();
		break;

	case WM_DESTROY:
		ambilight.stop();
		PostQuitMessage(0);
		break;

	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wincl;
	char appName[ ] = "Ambilight";

	wincl.cbSize = sizeof(WNDCLASSEX);
	wincl.style = NULL;
	wincl.lpfnWndProc = WindowProc; // This function is called by windows
	wincl.cbClsExtra = 0; // No extra bytes after the window class
	wincl.cbWndExtra = 0; // structure or the window instance
	wincl.hInstance = hInstance;
	wincl.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(TASKBAR_ICON));
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.hbrBackground = NULL;
	wincl.lpszMenuName = NULL;
	wincl.lpszClassName = appName;
	wincl.hIconSm = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(TASKBAR_ICON));

	// Register the window class, and if it fails quit the program
	if (!RegisterClassEx(&wincl))
	{
		return 0;
	}

	hWnd = CreateWindowEx(NULL, appName, appName, NULL, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);

	memset(&notifyIconData, 0, sizeof(NOTIFYICONDATA));
	notifyIconData.cbSize = sizeof(NOTIFYICONDATA);
	notifyIconData.hWnd = hWnd;
	notifyIconData.uID = ID_TRAY_APP_ICON;
	notifyIconData.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	notifyIconData.uCallbackMessage = WM_SYSICON;
	notifyIconData.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(TASKBAR_ICON));
	strncpy_s(notifyIconData.szTip, appName, sizeof(appName));

	Shell_NotifyIcon(NIM_ADD, &notifyIconData);
	WTSRegisterSessionNotification(hWnd, NOTIFY_FOR_THIS_SESSION);

	ambilight.start();

	MSG message;

	std::cout << "ici" << std::endl;

	while (!ambilight.isStoppeds())
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&message, NULL, 0, 0))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			else
			{
				ambilight.stop();
				break;
			}
		}
		else
		{
			//ambilight.exec();
		}
	}
	
	//while (GetMessage(&message, NULL, 0, 0))
	//{
	//	TranslateMessage(&message);
	//	DispatchMessage(&message);
	//}

	std::cout << "222" << std::endl;

	// WTSUnRegisterSessionNotification(hWnd);

	ambilight.stop();
	
	return (int)message.wParam;
}

