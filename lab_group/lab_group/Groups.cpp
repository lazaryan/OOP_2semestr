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

Object^ Groups::SearchStudentNum(){
	Object^ st = gcnew Object();

	if (gr->Count > 0) {
		Console::WriteLine(L"Введите номер студента, которого хотите найти:");
		String^ n = Console::ReadLine();

		while (!(CheckNumber(n) )) {
			Console::WriteLine(L"Ошибка ввода. Некоректно введены данныt. Повторите попытку:");
			n = Console::ReadLine();
		}
		int i = GetNumber(n);
		
		(i < gr->Count) ? st = gr[i] : Console::WriteLine(L"Студент не найден!");
	}else
		Console::WriteLine(L"Список студентов пуст. Поиск невозможен!");

	return st;
}

ArrayList^ Groups::SearchStudentName() {
	ArrayList^ st = gcnew ArrayList();

	int count = gr->Count;

	if(!count)
		Console::WriteLine(L"Список студентов пуст. Поиск невозможен!");
	else {
		Console::WriteLine(L"Введите фамилию студента, которого хотите найти:");
		String^ n = Console::ReadLine();

		while (!(CheckName(n))) {
			Console::WriteLine(L"Ошибка ввода. Некоректно введены данныt. Повторите попытку:");
			n = Console::ReadLine();
		}

		Student^ stud = gcnew Student();

		for (int i = 0; i < count; i++) {
			stud = (Student^)gr[i];
			String^ s = stud->GetName();
			
			if (Equality(s, n))
				st->Add(gr[i]);
		}
	}

	return st;
}

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

bool Groups::CheckName(String^ s) {
	int length = s->Length;

	for (int i = 0; i < length; i++)
		if (!(
			(s[i] >= 'a'  && s[i] <= 'z') ||
			(s[i] >= 'A'  && s[i] <= 'Z') ||
			(s[i] >= L'а' && s[i] <= L'я') ||
			(s[i] >= L'А' && s[i] <= L'Я')
			))
			return false;

	return true;
}

bool Groups::Equality(String^ out, String^ in) {
	int length = in->Length;

	for (int i = 0; i < length; i++)
		if (out[i] != in[i])
			return false;

	return true;
}