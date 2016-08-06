#ifndef DIALOG_H
#define DIALOG_H

#include <Windows.h>

class Dialog
{
public:
	Dialog ();
private:
	HWND hWnd;
	static BOOL CALLBACK DlgProc (HWND, UINT, WPARAM, LPARAM);
};

#endif