#include "std.h"

INT_PTR CALLBACK DlgChatProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
switch (msg)
{
case WM_INITDIALOG:		return con_Chat_Init(hDlg, lParam);
case WM_COPYDATA:		return con_RecvMessage(hDlg, wParam, lParam);
case WM_PAINT:			{ con_AddFriend_Init(hDlg); return 0; }
case WM_COMMAND:
{
	switch (LOWORD(wParam))
	{
	case IDCANCEL:		EndDialog(hDlg, IDCANCEL);  return TRUE;
	case IDC_BUTTON1:	return con_SendData(hDlg);
	case IDC_BUTTON3:	return con_Connect(hDlg);

	case IDC_BUTTON4:	return con_AddFriend(hDlg);
	}
	return FALSE;
}
}
return FALSE;
}
