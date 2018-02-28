// lab_group.cpp: главный файл проекта.

#include "stdafx.h"
#include <stdlib.h>

#include "Common.h"//Функции для работы главной функции
#include "Groups.h"

using namespace System;
using namespace System::IO;

int main(array<System::String ^> ^args) {
	Groups^		gr = gcnew Groups();//Создаем класс
	ArrayList ^ st = gcnew ArrayList();

	gr->AddListStudents();//Получаем список всех студентов
	/*int n = 1;
	while (n == 1) {
		switch (Choice()) {
		case 1: 
			gr->AddStudent();//добавляем студента
			break;
		case 2:
			gr->RemoveStudent();//Удаляем студента
			break;
		case 3:
			Console::WriteLine(gr->GetCountStudent());//Получаем количество студентов
			break;
		case 4:
			st->Add(gr->SearchStudentNum());//поиск по номеру
			break;
		case 5:
			st->Add(gr->SearchStudentName());//поиск по фомилии
			break;
		case 6:
			exit(0);
		default:
			break;
		}

		n = ChoiceRepeat();//будут ли еще запросы
		system("cls");//очистка консоли
	}*/
	if (!gr->AddStudent()) {
		Console::WriteLine("Error");
	}

	Console::ReadLine();
    return 0;
}
