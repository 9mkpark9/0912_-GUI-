#include "std.h"

vector<Member*> g_members;

void con_Main_Init(HWND hDlg)
{
	_tsetlocale(LC_ALL, _TEXT("korean")); //#include <locale.h>

	fio_load(&g_members);
	ui_MainDlg_Init(hDlg);
}

void con_AddFriend_Init(HWND hDlg)
{
	for (int i = 0; i < g_members.size(); i++)
	{
		Member* pmember = g_members[i];
		ui_ChatDlg_PrintFriend(pmember->name);
	}
	return;
}

INT_PTR con_Main_Exit(HWND hDlg)
{
	fio_save(&g_members);
	EndDialog(hDlg, IDCANCEL);

	return TRUE;
}

INT_PTR con_Chat_Init(HWND hDlg, LPARAM lParam)
{
	ui_ChatDlg_Init(hDlg);
	ui_ChatDlg_SetTitle(hDlg, lParam);

	return TRUE;
}

//로그인 
INT_PTR con_LogIn(HWND hDlg)
{
	TCHAR id[20], pw[20];
	ui_MainDlg_GetData(id, _countof(id), pw, _countof(pw));

	//id, pw를 저장된 정보랑 비교 -> 참 or 거짓
	Member* pmember = LogIn_Check(id, pw);
	if (pmember == NULL)
	{
		MessageBox(hDlg, TEXT("로그인 실패"), TEXT("알림"), MB_OK);
		return TRUE;
	}
	
	ShowWindow(hDlg, SW_HIDE);

	TCHAR name[20];
	_tcscpy_s(name, _countof(name), pmember->name);
	DialogBoxParam(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG3), 0, DlgChatProc, (LPARAM)name);

	ShowWindow(hDlg, SW_SHOW);

	ui_MadinDlg_SetData(TEXT(""), TEXT(""));

	return TRUE;
}

//회원가입
INT_PTR con_AddMember(HWND hDlg)
{
	TCHAR id[20], pw[20], name[20];

	ui_CreateDlg_GetData(hDlg, id, _countof(id), pw, _countof(pw), name, _countof(name));

	//vector 저장
	Member* pmember = member_create(id, pw, name);
	if (pmember != NULL)
	{
		g_members.push_back(pmember);

		MessageBox(0, TEXT("회원가입성공"), TEXT("알림"), MB_OK);
		ui_CreateDlg_SetData(hDlg, TEXT(""), TEXT(""), TEXT(""));

		EndDialog(hDlg, IDOK);
	}
	else
	{
		MessageBox(0, TEXT("회원가입실패"), TEXT("알림"), MB_OK);
	}
	return TRUE;
}

//데이터 전송
INT_PTR con_SendData(HWND hDlg)
{
	TCHAR myname[20], msg[100];
	ui_ChatDlg_GetData(msg, _countof(msg));
	ui_ChatDlg_GetMyName(hDlg, myname, _countof(myname));

	//상대방에게 전송[내이름/메시지/시간]-------------------------
	PACKET pack = packet_SendMessage(myname, msg);
	int ret = ipc_SendData(hDlg, pack);

	//------------------------------------------------------------
	//내 화면에 출력
	TCHAR name[20];		GetWindowText(hDlg, name, _countof(name));
	SYSTEMTIME st;		GetLocalTime(&st);
	TCHAR buf[100];
	wsprintf(buf, TEXT("[%s] %s (%02d:%02d:%02d)"), name, msg,
		st.wHour, st.wMinute, st.wSecond);
	ui_ChatDlg_Print(buf);
	ui_ChatDlg_SetData(TEXT(""));

	return TRUE;
}

//데이터 수신
INT_PTR con_RecvMessage(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	COPYDATASTRUCT* pcopy = (COPYDATASTRUCT*)lParam;
	PACKET* p = (PACKET*)pcopy->lpData;

	ui_ChatDlg_RecvInfo(p->name);		//*******
	ipc_TargetHandle((HWND)pcopy->dwData);	//*******

	TCHAR buf[100];
	wsprintf(buf, TEXT("[%s] %s (%02d:%02d:%02d)"),
		p->name, p->msg, p->st.wHour, p->st.wMinute, p->st.wSecond);

	ui_ChatDlg_Print(buf);

	return 5;
}

//IPC통신을 위한 연결
INT_PTR con_Connect(HWND hDlg)
{
	TCHAR target_name[100];
	ui_ChatDlg_GetTargetName(target_name, _countof(target_name));

	if (ipc_Connect(hDlg, target_name) == TRUE)
		MessageBox(hDlg, TEXT("연결성공"), TEXT("알림"), MB_OK);
	else
		MessageBox(hDlg, TEXT("연결실패"), TEXT("알림"), MB_OK);

	return TRUE;
}

INT_PTR con_AddFriend(HWND hDlg)
{
	TCHAR target_name[100];
	ui_ChatDlg_GetTargetName(target_name, _countof(target_name));
	if (con_Find_Friend(target_name) != NULL)
	{
		MessageBox(hDlg, TEXT("이미 친구입니다."), TEXT("알림"), MB_OK);
		return TRUE;
	}
	Member* pmember = con_Find_Friend(target_name);
	if (pmember == NULL)
	{
		MessageBox(hDlg, TEXT("친구추가실패"), TEXT("알림"), MB_OK);
		return TRUE;
	}
	g_members.push_back(pmember);
	MessageBox(hDlg, TEXT("친구추가성공"), TEXT("알림"), MB_OK);
	return TRUE;
}

Member* con_Find_Friend(const TCHAR* name)
{
	for (int i = 0; i < g_members.size(); i++)
	{
		Member* pmember = g_members[i];
		if (_tcscmp(pmember->name, name) == 0)
			return pmember;
	}
	return NULL;
}


Member* LogIn_Check(const TCHAR* id, const TCHAR* pw)
{
	for (int i = 0; i < g_members.size(); i++)
	{
		Member* pmember = g_members[i];
		if (_tcscmp(pmember->id, id) == 0 && _tcscmp(pmember->pw, pw) == 0)
			return pmember;
	}
	return NULL;
}

Member* con_Friend_Prints(const TCHAR* name)
{
	for (int i = 0; i < g_members.size(); i++)
	{
		Member* pmember = g_members[i];
		ui_ChatDlg_PrintFriend(pmember->name);
	}
	return NULL;
}