#include "stdafx.h"
#include "PrivateMethodStudent.h"


PrivateMethodStudent::PrivateMethodStudent()
{
}

bool PrivateMethodStudent::CheckName(String^ st) {
	int length = st->Length,
		space = 0;

	if (st[0] == ' ') return false;
	for (int i = 1; i < length; i++) {
		if (!(
			(st[i] >= 'a'  && st[i] <= 'z') ||
			(st[i] >= 'A'  && st[i] <= 'Z') ||
			(st[i] >= L'à' && st[i] <= L'ÿ') ||
			(st[i] >= L'À' && st[i] <= L'ß') ||
			st[i] == ' '
			)) return false;
		if (st[i] == ' ') {
			space++;
			if (space > 2 || st[i - 1] == ' ') return false;
		}
	}
	if (space != 2) return false;

	return true;
}

bool PrivateMethodStudent::CheckAge(String^ age) {
	int length = age->Length;

	for (int i = 0; i < length; i++)
		if (!(age[i] >= '0' && age[i] <= '9'))
			return false;

	return true;
}

int PrivateMethodStudent::AddNumber(String^ s) {
	int length = s->Length,
		count = 0;

	for (int i = 0; i < length; i++)
		count = count * 10 + ((int)s[i] - (int)'0');

	return count;
}
