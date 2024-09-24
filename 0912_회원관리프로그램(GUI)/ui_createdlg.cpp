//ui_createdlg.cpp
#include "std.h"

void ui_CreateDlg_GetData(HWND hDlg, TCHAR* id, int id_size, TCHAR* pw, int pw_size,
	TCHAR* name, int name_size)
{
	GetDlgItemText(hDlg, IDC_EDIT1, id, id_size);
	GetDlgItemText(hDlg, IDC_EDIT2, pw, pw_size);
	GetDlgItemText(hDlg, IDC_EDIT3, name, name_size);
}

void ui_CreateDlg_SetData(HWND hDlg,
	const TCHAR* id, const TCHAR* pw, const TCHAR* name)
{
	SetDlgItemText(hDlg, IDC_EDIT1, id);
	SetDlgItemText(hDlg, IDC_EDIT2, pw);
	SetDlgItemText(hDlg, IDC_EDIT3, name);
}