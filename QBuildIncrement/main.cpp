#include "main.h"
#include <Windows.h>
#include <stdio.h>
#include "dialog.h"

INT CALLBACK WinMain (HINSTANCE hInst, HINSTANCE, LPSTR szCmdLine, INT nCmdShow)
{
//	RegisterClassEx
	WNDCLASSEX wcex = {};
	wcex.cbSize = sizeof (wcex);
	wcex.hbrBackground = (HBRUSH) COLOR_WINDOW + 1;
	wcex.hInstance = hInst;
	wcex.lpfnWndProc = DefWindowProc;
	wcex.lpszClassName = L"build++";
	if (RegisterClassEx (&wcex) == FALSE)
	{
		MessageBox (NULL, L"RegisterClassEx failed", L"Error", MB_ICONERROR | MB_OK);
		return 0;
	}

//	CreateDialog
	AllocConsole ();
	freopen ("CONIN$", "r", stdin);
	freopen ("CONOUT$", "w", stdout);

//	Create Dialog
	Dialog dlg;

//	Message Loop
	MSG msg;
	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}
	return (INT) msg.wParam;
}
