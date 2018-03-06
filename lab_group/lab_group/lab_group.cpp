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
	
	/*Добавление студентов*/
	//---с помощью класса студента
	//Student^ st = gcnew Student();
	//st->SetName("qa qa qa");
	//st->SetAge(25);
		//gr->SetStudents("Students.txt", st);

	////---Прямая задача аргументов
		//gr->SetStudents("Students.txt", "as as a", 26);

	////---Передача одной строкой
		//gr->SetStudents("Students.txt", "si s si;28");

	//---считывание с файла
	/*bool a = true;
	StreamReader^ inp_r;

	try {
		inp_r = gcnew StreamReader("AddStudents.txt");
	}
	catch (...) {
		a = false;
	}
	
	if (a) {
		gr->SetStudents("Students.txt", inp_r); 
	}
	inp_r->Close();*/

	/*Удаление студентов*/
	//---удаление по номеру
		//gr->RemoveStudent(2);

	//---удаление по фамилии
		//gr->RemoveStudent("asd");

	/*Поиск студента*/
	//---по номеру
		//gr->SearchStudent(1);

	//---по части имени
		//gr->SearchStudent("a");


	return 0;
}
