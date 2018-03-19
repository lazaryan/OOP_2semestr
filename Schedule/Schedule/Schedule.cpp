// Schedule.cpp: главный файл проекта.

#include "stdafx.h"
#include "Para.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	Para ^ par = gcnew Para();
	par->SetTime("8:20-12:30");
	par->SetAuditorium("Г123" , 25);
	par->SetPredmet("Математика");

	par->SetTeacher("asd a asd", "Преподаватель");


    return 0;
}
