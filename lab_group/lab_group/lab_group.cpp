// lab_group.cpp: главный файл проекта.

#include "stdafx.h"
#include "Student.h"
#include "GroupStudents.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections;

int main(array<System::String ^> ^args) {
	GroupStudents ^ gr = gcnew GroupStudents();

	/*Получение всех студентов в списке*/
	if (!gr->SetListStudents("Students.txt")) {
		Console::WriteLine("Error");
		return 0;
	}

	Student ^ st1 = gcnew Student("asda asd", 22);
	Student ^ st2 = gcnew Student("Student.txt");

	return 0;
}
