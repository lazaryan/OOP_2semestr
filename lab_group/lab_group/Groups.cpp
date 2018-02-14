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