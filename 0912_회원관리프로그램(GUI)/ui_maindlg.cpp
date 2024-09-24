//ui_maindlg.cpp
#include "std.h"

HWND hMainDlg_Id, hMainDlg_Pw;

void ui_MainDlg_Init(HWND hDlg)
{
	hMainDlg_Id = GetDlgItem(hDlg, IDC_EDIT1);
	hMainDlg_Pw = GetDlgItem(hDlg, IDC_EDIT2);
}

void ui_MainDlg_GetData(TCHAR* id, int id_size, TCHAR* pw, int pw_size)
{
	GetWindowText(hMainDlg_Id, id, id_size);
	GetWindowText(hMainDlg_Pw, pw, pw_size);
}

void ui_MadinDlg_SetData(const TCHAR* id, const TCHAR* pw)
{
	SetWindowText(hMainDlg_Id, id);
	SetWindowText(hMainDlg_Pw, pw);
}