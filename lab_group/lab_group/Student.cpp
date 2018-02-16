#include "stdafx.h"
#include "Student.h"

using namespace System;
using namespace System::IO;

Student::Student() {}

void Student::SetName() {
	String^ name = Console::ReadLine();

	while (name->Length == 0 || !CheckName(name)) {
		Console::WriteLine(L"Ошибка ввода. Некоректно введены данныt. Повторите попытку:");
		name = Console::ReadLine();
	}

	Name = name;
}

void  Student::SetAge() {
	String^ age = Console::ReadLine();

	while (age->Length != 4 || !CheckAge(age)) {
		Console::WriteLine(L"Ошибка ввода. Некоректно введены данныt. Повторите попытку:");
		age = Console::ReadLine();
	}

	Age = AddNumber(age);
}

String^ Student::GetName() { return Name; }

int Student::GetAge() { return Age; }

