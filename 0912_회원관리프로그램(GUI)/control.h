//control.h
#pragma once

void con_Main_Init(HWND hDlg);
void con_AddFriend_Init(HWND hDlg);
INT_PTR con_Main_Exit(HWND hDlg);

INT_PTR con_Chat_Init(HWND hDlg, LPARAM lParam);


INT_PTR con_LogIn(HWND hDlg);
INT_PTR con_AddMember(HWND hDlg);
INT_PTR con_SendData(HWND hDlg);
INT_PTR con_RecvMessage(HWND hDlg, WPARAM wParam, LPARAM lParam);

INT_PTR con_Connect(HWND hDlg);
//친구추가
INT_PTR con_AddFriend(HWND hDlg);


//-----------------------------------------
Member* con_Find_Friend(const TCHAR* name);
Member* LogIn_Check(const TCHAR* id, const TCHAR* pw);
Member* con_Friend_Prints(const TCHAR* name);