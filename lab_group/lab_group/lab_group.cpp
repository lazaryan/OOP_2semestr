// lab_group.cpp: главный файл проекта.

#include "stdafx.h"
#include <stdlib.h>

#include "Common.h"//Функции для работы главной функции
#include "Groups.h"

using namespace System;
using namespace System::IO;

int main(array<System::String ^> ^args) {
	Groups^ gr = gcnew Groups();//Создаем класс
	
	int n = 1;
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
		case 5:
			exit(0);
		default:
			break;
		}

		n = ChoiceRepeat();//будут ли еще запросы
		system("cls");//очистка консоли
	}

	Console::ReadLine();
    return 0;
}
