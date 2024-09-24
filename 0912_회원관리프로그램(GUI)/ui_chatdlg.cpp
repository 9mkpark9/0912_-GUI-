//ui_chatdlg.cpp
#include "std.h"

HWND hChatDlg_Msg, hChatDlg_Print, hChatDlg_Friend_P, hChatDlg_TargetName, hChatDlg_FriendName;

void ui_ChatDlg_Init(HWND hDlg)
{
	hChatDlg_Print		= GetDlgItem(hDlg, IDC_EDIT5);
	hChatDlg_Friend_P	= GetDlgItem(hDlg, IDC_EDIT1);
	hChatDlg_Msg		= GetDlgItem(hDlg, IDC_EDIT2);
	hChatDlg_TargetName = GetDlgItem(hDlg, IDC_EDIT4);
	hChatDlg_FriendName = GetDlgItem(hDlg, IDC_EDIT6);
}

void ui_ChatDlg_SetTitle(HWND hDlg, LPARAM lParam)
{
	SetWindowText(hDlg, (TCHAR*)lParam);
}

void ui_ChatDlg_GetData(TCHAR* msg, int size)
{
	GetWindowText(hChatDlg_Msg, msg, size);
}

void ui_ChatDlg_SetData(const TCHAR* msg)
{
	SetWindowText(hChatDlg_Msg, msg);
	SetFocus(hChatDlg_Msg);	//<<
}

void ui_ChatDlg_GetMyName(HWND hDlg, TCHAR* myname, int size)
{
	GetWindowText(hDlg, myname, size);
}

void ui_ChatDlg_Print(const TCHAR* msg)
{
	int nLength = GetWindowTextLength(hChatDlg_Print);
	SendMessage(hChatDlg_Print, EM_SETSEL, nLength, nLength);
	SendMessage(hChatDlg_Print, EM_REPLACESEL, FALSE, (LPARAM)msg);
	SendMessage(hChatDlg_Print, EM_REPLACESEL, FALSE, (LPARAM)TEXT("\r\n"));
}
//친구창 출력
void ui_ChatDlg_PrintFriend(const TCHAR* name)
{
	int nLength = GetWindowTextLength(hChatDlg_Friend_P);
	SendMessage(hChatDlg_Friend_P, EM_SETSEL, nLength, nLength);
	SendMessage(hChatDlg_Friend_P, EM_REPLACESEL, FALSE, (LPARAM)name);
	SendMessage(hChatDlg_Friend_P, EM_REPLACESEL, FALSE, (LPARAM)TEXT("\r\n"));

}

void ui_ChatDlg_FriendName(const TCHAR* name)
{
	SetWindowText(hChatDlg_FriendName, name);
}

void ui_ChatDlg_GetTargetName(TCHAR* name, int size)
{
	GetWindowText(hChatDlg_FriendName, name, size);
}

void ui_ChatDlg_RecvInfo(const TCHAR* name)
{
	SetWindowText(hChatDlg_TargetName, name);
}