// lab_group.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Student.h"
#include "GroupStudents.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections;

int main(array<System::String ^> ^args) {
	GroupStudents ^ gr = gcnew GroupStudents();

	/*��������� ���� ��������� � ������*/
	if (!gr->SetListStudents("Students.txt")) {
		Console::WriteLine("Error");
		return 0;
	}
	
	/*���������� ���������*/
	//---� ������� ������ ��������
	//Student^ st = gcnew Student();
	//st->SetName("qa qa qa");
	//st->SetAge(25);
		//gr->SetStudents("Students.txt", st);

	////---������ ������ ����������
		//gr->SetStudents("Students.txt", "as as a", 26);

	////---�������� ����� �������
		//gr->SetStudents("Students.txt", "si s si;28");

	//---���������� � �����
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

	/*�������� ���������*/
	//---�������� �� ������
		//gr->RemoveStudent(2);

	//---�������� �� �������
		//gr->RemoveStudent("asd");

	/*����� ��������*/
	//---�� ������
		//gr->SearchStudent(1);

	//---�� ����� �����
		//gr->SearchStudent("a");


	return 0;
}
