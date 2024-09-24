//member.h
#pragma once

typedef struct tagMember
{
	TCHAR id[20];
	TCHAR pw[20];
	TCHAR name[20];
}Member;

Member* member_create(const TCHAR* id, const TCHAR* pw, const TCHAR* name);
void member_update(Member* pmember);
