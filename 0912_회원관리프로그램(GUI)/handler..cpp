//handler.cpp
#include "std.h"

INT_PTR OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_Main_Init(hDlg);

	return TRUE;
}

INT_PTR OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
		//Main윈도우 종료(프로그램 종료)
	case IDCANCEL:		return con_Main_Exit(hDlg);
		//로그인버튼클릭
	case IDC_BUTTON1:   return con_LogIn(hDlg);
		
		//친구추가 버튼클릭
	case IDC_BUTTON3:   return con_AddFriend(hDlg);

		//회원가입버튼클릭
	case IDC_BUTTON2:
	{
		ShowWindow(hDlg, SW_HIDE);
		DialogBoxParam(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG2), 0, DlgCreateProc, 0);
		ShowWindow(hDlg, SW_SHOW);
		

		return TRUE;
	}
	}
	return FALSE;
}