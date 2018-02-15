#include "stdafx.h"

#include "Groups.h"
#include "Student.h"

Groups::Groups() {gr = gcnew ArrayList();}

void Groups::AddStudent() {
	Student^ st = gcnew Student();

	Console::WriteLine(L"Введите имя в формате: Ф И О!");
	st->SetName();

	Console::WriteLine(L"Введите год рождения студента студента");
	st->SetAge();

	gr->Add(st);
}

void Groups::RemoveStudent() {
	if (gr->Count > 0) {
		Console::WriteLine(L"Введите номер студента, которого хотите удалить:");
		String^ n = Console::ReadLine();

		while (!(CheckNumber(n) && (GetNumber(n) <= gr->Count))) {
			Console::WriteLine(L"Ошибка ввода. Некоректно введены данныt. Повторите попытку:");
			n = Console::ReadLine();
		}

		gr->Remove(gr[GetNumber(n)]);
	}
	else
		Console::WriteLine(L"Список студентов пуст. Удаление невозможно!");
}

int Groups::GetCountStudent() { return gr->Count; }

int Groups::GetNumber(String^ s) {
	int length = s->Length,
		count  = 0;

	for (int i = 0; i < length; i++)
		count = count * 10 + ((int)s[i] - (int)'0');

	return count;
}

bool Groups::CheckNumber(String^ num) {
	int length = num->Length;

	for (int i = 0; i < length; i++)
		if (!(num[i] >= '0' && num[i] <= '9'))
			return false;

	return true;
}