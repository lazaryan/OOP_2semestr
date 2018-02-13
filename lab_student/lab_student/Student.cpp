#include "stdafx.h"
#include "Student.h"

using namespace System;
using namespace System::IO;

Student::Student(){}

void Student::SetName() {
	String^ name = Console::ReadLine();

	while (name->Length == 0 || !CheckName(name)) {
		Console::WriteLine(L"Ошибка ввода. Некоректно введены данныt. Повторите попытку:");
		name = Console::ReadLine();
	}

	Name = name;
}

String^ Student::GetName() {return Name;}

bool Student::CheckName(String^ st) {
	int length = st->Length,
		space  = 0;

	if (st[0] == ' ') return false;
	for (int i = 1; i < length; i++) {
		if (!(
			(st[i] >= 'a'  && st[i] <= 'z') ||
			(st[i] >= 'A'  && st[i] <= 'Z') ||
			(st[i] >= L'а' && st[i] <= L'я') ||
			(st[i] >= L'А' && st[i] <= L'Я') ||
			st[i] == ' '
			)) return false;
		if(st[i] == ' ') {
			space++;
			if (space > 2 || st[i - 1] == ' ') return false;
		}
	}
	if (space != 2) return false;

	return true;
}
