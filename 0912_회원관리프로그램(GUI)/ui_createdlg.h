//ui_createdlg.h
#pragma once

void ui_CreateDlg_GetData(HWND hDlg, TCHAR* id, int id_size, TCHAR* pw, int pw_size, 
	TCHAR *name, int name_size);

void ui_CreateDlg_SetData(HWND hDlg, 
	const TCHAR* id, const TCHAR* pw, const TCHAR* name);