//member.cpp
#include "std.h"

Member* member_create(const TCHAR* id, const TCHAR* pw, const TCHAR* name)
{
	Member* pmember = (Member*)malloc(sizeof(Member));
	if (pmember == NULL)
		return NULL;

	_tcscpy_s(pmember->id, _countof(pmember->id), id);
	_tcscpy_s(pmember->pw, _countof(pmember->pw), pw);
	_tcscpy_s(pmember->name, _countof(pmember->name), name);

	return pmember;
}

void member_update(Member* pmember)
{

}