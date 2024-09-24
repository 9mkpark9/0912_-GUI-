//ipc.cpp
#include "std.h"

HWND hTarget = 0;
//접속
BOOL ipc_Connect(HWND hDlg, const TCHAR* target_name)
{
	hTarget = FindWindow(0, target_name);
	if (hTarget == 0)
		return FALSE;
	else
		return TRUE;
}

int ipc_SendData(HWND hDlg, PACKET pack)
{
	//FindWindow 찾는과정을 수행

	COPYDATASTRUCT cds;
	cds.lpData = &pack;
	cds.cbData = sizeof(PACKET);
	cds.dwData = (ULONG_PTR)hDlg;

	int ret = (int)SendMessage(hTarget, WM_COPYDATA, 0, (LPARAM)&cds);
	return ret;
}

void ipc_TargetHandle(HWND htargt)
{
	hTarget = htargt;
}