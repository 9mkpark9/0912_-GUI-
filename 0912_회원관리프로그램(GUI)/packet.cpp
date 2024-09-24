//packet.cpp
#include "std.h"

PACKET packet_SendMessage(const TCHAR* myname, const TCHAR* msg)
{
	PACKET pack;

	_tcscpy_s(pack.name, _countof(pack.name), myname);
	_tcscpy_s(pack.msg, _countof(pack.msg), msg);
	GetLocalTime(&pack.st);

	return pack;
}