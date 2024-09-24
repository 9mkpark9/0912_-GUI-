//dlgcreateproc.cpp
#include "std.h"

INT_PTR CALLBACK DlgCreateProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:		
	{
		return TRUE;
	}
	case WM_COMMAND:		
	{
		switch (LOWORD(wParam))
		{
		case IDCANCEL:		EndDialog(hDlg, IDCANCEL);  return TRUE;
		case IDC_BUTTON3:	return con_AddMember(hDlg);
		}
		return FALSE;
	}
	}
	return FALSE;
}
