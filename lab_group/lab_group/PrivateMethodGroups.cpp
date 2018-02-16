#include "stdafx.h"
#include "PrivateMethodGroups.h"


PrivateMethodGroups::PrivateMethodGroups()
{
}

int PrivateMethodGroups::GetNumber(String^ s) {
	int length = s->Length,
		count = 0;

	for (int i = 0; i < length; i++)
		count = count * 10 + ((int)s[i] - (int)'0');

	return count;
}

bool PrivateMethodGroups::CheckNumber(String^ num) {
	int length = num->Length;

	for (int i = 0; i < length; i++)
		if (!(num[i] >= '0' && num[i] <= '9'))
			return false;

	return true;
}

bool PrivateMethodGroups::CheckName(String^ s) {
	int length = s->Length;

	for (int i = 0; i < length; i++)
		if (!(
			(s[i] >= 'a'  && s[i] <= 'z') ||
			(s[i] >= 'A'  && s[i] <= 'Z') ||
			(s[i] >= L'à' && s[i] <= L'ÿ') ||
			(s[i] >= L'À' && s[i] <= L'ß')
			))
			return false;

	return true;
}

bool PrivateMethodGroups::Equality(String^ out, String^ in) {
	int length = in->Length;

	for (int i = 0; i < length; i++)
		if (out[i] != in[i])
			return false;

	return true;
}
