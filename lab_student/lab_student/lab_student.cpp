// lab_student.cpp: главный файл проекта.

#include "stdafx.h"
#include "Student.h"

using namespace System;
using namespace System::IO;

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Введите имя в формате: И Ф О!");
	Student^ st = gcnew Student();
	st->SetName();

	String^ name = st->GetName();
	Console::WriteLine("ваше имя: ");
	Console::WriteLine(name);

	Console::ReadLine();
    return 0;
}
