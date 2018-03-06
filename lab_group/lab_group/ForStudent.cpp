#include "stdafx.h"
#include "ForStudent.h"


ForStudent::ForStudent(){}

bool ForStudent::CheckName(String^ s) {
	int length = s->Length,
		space = 0;

	if (length == 0 || s[0] == ' ') return false;
	for (int i = 1; i < length; i++) {
		if (!(
			(s[i] >= 'a'  && s[i] <= 'z') ||
			(s[i] >= 'A'  && s[i] <= 'Z') ||
			(s[i] >= L'à' && s[i] <= L'ÿ') ||
			(s[i] >= L'À' && s[i] <= L'ß') ||
			s[i] == ' '
			)) return false;
		if (s[i] == ' ') {
			space++;
			if (space > 2 || s[i - 1] == ' ') return false;
		}
	}
	if (space != 2) return false;

	return true;
}

bool ForStudent::CheckAge(String^ s) {
	int length = s->Length;

	if (length == 0) return false;

	for (int i = 0; i < length; i++)
		if (!((int)s[i] >= '0' && (int)s[i] <= '9'))
			return false;

	int a = GetNumber(s);

	if (!(a > 16 && a < 60)) return false;

	return true;
}

int ForStudent::GetNumber(String^ s) {
	int length = s->Length,
		count = 0;

	for (int i = 0; i < length; i++)
		count = 10 * count + ((int)s[i] - (int)'0');

	return count;
}