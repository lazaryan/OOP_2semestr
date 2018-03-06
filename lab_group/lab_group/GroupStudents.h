#pragma once
#include "Student.h"
#include "ForGroup.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections;

ref class GroupStudents : ForGroup
{
public:
	GroupStudents();
	bool SetListStudents(String^);//��������, ������� ����
	//������� ��� �������� ��������� � ������
	bool SetStudents(String^, StreamReader^);
	bool SetStudents(String^, Student^);
	bool SetStudents(String^, String^);
	bool SetStudents(String^, String^, int);
	//������� ��� �������� ���������
	bool RemoveStudent(String^);
	bool RemoveStudent(int);
	//������� ������ ��������
	Object^    SearchStudent(int);
	ArrayList^ SearchStudent(String^);
	
private:
	ArrayList ^ Students;
	String^ NameGroup;
};

