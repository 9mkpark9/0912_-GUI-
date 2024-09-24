//ui_chatdlg.h
#pragma once

void ui_ChatDlg_Init(HWND hDlg);
void ui_ChatDlg_SetTitle(HWND hDlg, LPARAM lParam);

void ui_ChatDlg_GetData(TCHAR* msg, int size);
void ui_ChatDlg_SetData(const TCHAR* msg);
void ui_ChatDlg_GetMyName(HWND hDlg, TCHAR* myname, int size);

void ui_ChatDlg_Print(const TCHAR* msg);
void ui_ChatDlg_PrintFriend(const TCHAR* name);

void ui_ChatDlg_FriendName(const TCHAR* name);

void ui_ChatDlg_GetTargetName(TCHAR* msg, int size);

void ui_ChatDlg_RecvInfo(const TCHAR * name);
