// Schedule.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Para.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	Para ^ par = gcnew Para();
	par->SetTime("8:20-12:30");
	par->SetAuditorium("�123" , 25);
	par->SetPredmet("����������");

	par->SetTeacher("asd a asd", "�������������");


    return 0;
}
