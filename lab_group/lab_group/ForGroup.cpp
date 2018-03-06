#include "stdafx.h"
#include "ForGroup.h"


ForGroup::ForGroup(){}

String^ ForGroup::AddString(String^ s, int a, int b) {
	String^ str;

	for (int i = a; i < b; i++) {
		str += s[i];
	}

	return str;
}

bool ForGroup::CheckPresencesStudent(ArrayList^ gr, Student^ st) {
	Student^ stBuf = gcnew Student();
	int length     = gr->Count;

	if (length == 0) return true;

	for (int i = 0; i < length; i++) {
		stBuf = (Student^)gr[i];

		if (st->GetAge() == stBuf->GetAge() && st->GetName() == stBuf->GetName())
			return true;
	}

	return false;
}

bool ForGroup::CheckString(String^ s) {
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

	return true;
}

bool ForGroup::SearchNameStudent(String^ s, ArrayList^ gr) {
	int length = gr->Count;

	for (int i = 0; i < length; i++) {
		Student^ st = (Student^)gr[i];
		if (CheckName(s, st->GetName())) {
			return true;
		}
	}

	return false;
}

bool ForGroup::CheckName(String^ s1, String^ s2) {
	int length = s1->Length;

	for (int i = 0; i < length; i++) {
		if (!(s1[i] == s2[i])) {
			return false;
		}
	}

	return true;
}

bool ForGroup::SearchNameStudent(String^ s, Student^ gr) {
	String^ name = gr->GetName();

	if (!CheckName(s, name))
		return false;

	return true;
}