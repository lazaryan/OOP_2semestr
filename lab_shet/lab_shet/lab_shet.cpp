﻿// lab_shet.cpp: главный файл проекта.

#include "stdafx.h"
#include "Template.h"

using namespace System;
using namespace System::IO;

int main(array<System::String ^> ^args)
{
	Template^ tm = gcnew Template();//создаем класс с указаным файлом для чтения

	tm->AddCountSymboll(3);//Сколько цифр в шаблоне
	tm->AddTemlate();//Получаем шаблон(Проверка в отдельном методе под копотом)

	if (!(tm->OpenFile("Input.txt")))
		return 0;
	else {
		tm->AddTemlates();//выводим все шаблоны(подходящие)
		tm->CloseFile();//закрываем файл

		Console::ReadLine();
		return 0;
	}
}
