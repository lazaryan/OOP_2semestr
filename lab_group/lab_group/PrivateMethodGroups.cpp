#include "stdafx.h"
#include "PrivateMethodGroups.h"


PrivateMethodGroups::PrivateMethodGroups(){}

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

	int age = GetNumber(num);
	if (age < 15 || age > 70) return false;

	return true;
}

bool PrivateMethodGroups::CheckName(String^ st) {
	int length = st->Length,
		space = 0;

	if (length == 0 || st[0] == ' ') return false;
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

bool PrivateMethodGroups::Equality(String^ out, String^ in) {
	int length = in->Length;

	for (int i = 0; i < length; i++)
		if (out[i] != in[i])
			return false;

	return true;
}

bool PrivateMethodGroups::CheckStudent(Student^ s, ArrayList^ g) {
	int length = g->Count;
	Student^ stud = gcnew Student();

	if (length == 0) return true;

	for (int i = 0; i < length; i++) {
		stud = (Student^)g[i];
		if (!(s->GetAge() == stud->GetAge() && s->GetName() == stud->GetName()))
			return true;
	}

	return false;
}

String^ PrivateMethodGroups::AddNameStudent(String^ s , int a) {
	String^ b = "";

	for (int i = 0; i < a; i++) {
		b += s[i];
	}

	return b;
}

String^ PrivateMethodGroups::AddAgeStudent(String^ s, int a) {
	String^ b = "";

	int length = s->Length,
		c = 0;

	if(s[a + 1] == ' ')
		for (int i = a + 2; i < length; i++) {
			b += s[i];
		}
	else
		for (int i = a + 1; i < length; i++) {
			b += s[i];
		}

	return b;
}