#include "stdafx.h"
#include "ForPara.h"


ForPara::ForPara()
{
}

int ForPara::PosSumbol(String^ text, char sumbol) {
	int length = text->Length;

	for (int i = 0; i < length; i++) {
		if (text[i] == sumbol)
			return i;
	}

	return -1;
}

String^ ForPara::GetString(String^ text, int pos1, int pos2) {
	if (pos1 < 0 || pos2 > text->Length)
		return "";

	String^ new_str;
	for (int i = pos1; i < pos2; i++) {
		new_str += text[i];
	}

	return new_str;
}

int ForPara::GetNumber(String^ s) {
	if (!(ScheckNumber(s)))
		return -1;

	int length = s->Length,
		number = 0;

	for (int i = 0; i < length; i++) {
		number = number * 10 + ((int)s[i] - (int)'0');
	}

	return number;
}

bool ForPara::ScheckNumber(String^ s) {
	int length = s->Length;

	for (int i = 0; i < length; i++) {
		if (!(s[i] >= '0' && s[i] <= '9'))
			return false;
	}

	return true;
}

bool ForPara::ScheckString(String^ s) {
	int length = s->Length;

	for (int i = 0; i < length; i++) {
		if (!(
			(s[i] >= 'a' && s[i] <= 'z') ||
			(s[i] >= 'A' && s[i] <= 'Z') ||
			(s[i] >= L'à' && s[i] <= L'ÿ') ||
			(s[i] >= L'À' && s[i] <= L'ß') ||
			s[i] == ' ' || s[i] == '-'
			))
			return false;
	}

	return true;
}

bool ForPara::ScheckName(String^ name) {
	int length = name->Length,
		space = 0;

	if (name[0] == ' ') return false;
	for (int i = 1; i < length; i++) {
		if (!(
			(name[i] >= 'a'  && name[i] <= 'z') ||
			(name[i] >= 'A'  && name[i] <= 'Z') ||
			(name[i] >= L'à' && name[i] <= L'ÿ') ||
			(name[i] >= L'À' && name[i] <= L'ß') ||
			name[i] == ' '
			)) return false;
		if (name[i] == ' ') {
			space++;
			if (space > 2 || name[i - 1] == ' ') return false;
		}
	}
	if (space != 2) return false;

	return true;
}