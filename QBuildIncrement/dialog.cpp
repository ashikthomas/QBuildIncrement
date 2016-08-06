#include "dialog.h"
#include "resource.h"

Dialog::Dialog ()
{
//	CREATE DIALOG
	this->hWnd = CreateDialog (NULL, MAKEINTRESOURCE (IDD_DIALOG1), NULL, DlgProc);
	if (this->hWnd == NULL)
	{
		MessageBox (NULL, L"CreateDialog failed", L"Error", MB_ICONERROR | MB_OK);
		PostQuitMessage (0);
		return;
	}
	ShowWindow (this->hWnd, SW_SHOW);

}

BOOL CALLBACK Dialog::DlgProc (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_CLOSE:
		PostQuitMessage (0);
		break;
	default:
		return FALSE;
	}
	return TRUE;
}
