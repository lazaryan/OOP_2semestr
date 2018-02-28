#include "stdafx.h"

#include "Groups.h"
#include "Student.h"

using namespace System;
using namespace System::IO;

Groups::Groups() {
	gr = gcnew ArrayList();
}

bool Groups::AddListStudents() {
	Student^ stud = gcnew Student();
	StreamReader^ inp_r;
	String  ^s,
			^name;
	int age;

	try {
		inp_r = gcnew StreamReader("Students.txt");
	}
	catch (...) {
		StreamWriter ^ inp_w = gcnew StreamWriter("Students.txt");
		inp_w->Close();
		return false;
	}

	while (!inp_r->EndOfStream) {
		int a;

		s = inp_r->ReadLine();

		try {
			a = s->IndexOf(';');//Позиция точки с запятой
		}
		catch (...) {
			continue;
		}

		if (CheckName(AddNameStudent(s, a)) && CheckNumber(AddAgeStudent(s, a))) {
			name = AddNameStudent(s, a);
			age = GetNumber(AddAgeStudent(s, a));

			stud->SetName(name);
			stud->SetAge(age);

			gr->Add(stud);
		}
	}

	return true;
}

bool Groups::AddStudent() {
	Student^ st = gcnew Student();

	StreamWriter ^ inp;
	StreamReader ^ out;
	try {
		out = gcnew StreamReader("files/AddStudents.txt");//Добавляемые студенты
	}
	catch (...) {
		return false;
	}

	while (!out->EndOfStream) {
		return true;
	}

	return true;
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

