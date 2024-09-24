//ipc.h
#pragma once

BOOL ipc_Connect(HWND hDlg, const TCHAR* target_name);
int ipc_SendData(HWND hDlg, PACKET pack);

void ipc_TargetHandle(HWND htargt);