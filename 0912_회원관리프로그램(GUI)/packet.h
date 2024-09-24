//packet.h
#pragma once

//구조체 변수를 선언하면 모든 맴버들의 메모리가 연결되어 있다.!!
typedef struct tagPACKET
{
	TCHAR name[20];
	TCHAR msg[100];
	SYSTEMTIME st;
}PACKET;

PACKET packet_SendMessage(const TCHAR* myname, const TCHAR* msg);