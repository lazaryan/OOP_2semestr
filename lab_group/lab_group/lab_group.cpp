// lab_group.cpp: главный файл проекта.

#include "stdafx.h"

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
		default:
			break;
		}
		n = ChoiceRepeat();
	}

	Console::ReadLine();
    return 0;
}
