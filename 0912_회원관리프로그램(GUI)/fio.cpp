//fio.cpp
#include "std.h"

#define FILE_NAME	"members.txt"

void fio_load(vector<Member*>* pmembers)
{
	FILE* fp;
	int ret = fopen_s(&fp, FILE_NAME, "r");
	if (ret != 0)
		return;

	int size;
	_ftscanf_s(fp, _TEXT("%d"), &size);

	for (int i = 0; i < size; i++)
	{
		Member* pmember = (Member*)malloc(sizeof(Member));
		if (pmember == NULL)
			break;

		_ftscanf_s(fp, _TEXT("%s"), pmember->id, (int)_countof(pmember->id));
		_ftscanf_s(fp, _TEXT("%s"), pmember->pw, (int)_countof(pmember->pw));
		_ftscanf_s(fp, _TEXT("%s"), pmember->name, (int)_countof(pmember->name));
		TCHAR dummy;
		_ftscanf_s(fp, _TEXT("%c"), &dummy, (int)sizeof(dummy));	//***

		pmembers->push_back(pmember);
	}
	fclose(fp);
}

void fio_save(const vector<Member*>* pmembers)
{
	FILE* fp;
	int ret = fopen_s(&fp, FILE_NAME, "w");
	if (ret != 0)
		return;

	int size = (int)pmembers->size();
	_ftprintf(fp, _TEXT("%d\n"), size);

	for (int i = 0; i < pmembers->size(); i++)
	{
		Member* pmember = (*pmembers)[i];

		_ftprintf(fp, _TEXT("%s\t"), pmember->id);
		_ftprintf(fp, _TEXT("%s\t"), pmember->pw);
		_ftprintf(fp, _TEXT("%s\t"), pmember->name);
	}
	fclose(fp);

	TCHAR msg[20];
	wsprintf(msg, TEXT("%d명의 회원 저장 완료"), pmembers->size());
	MessageBox(0, msg, TEXT("알림"), MB_OK);
}