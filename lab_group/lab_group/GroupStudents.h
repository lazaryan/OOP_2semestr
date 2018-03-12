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
	bool SetListStudents(String^);//Студенты, которые есть
	//Функции для внесения студентов в список
	bool SetStudents(String^, StreamReader^);
	bool SetStudents(String^, Student^);
	bool SetStudents(String^, String^);
	bool SetStudents(String^, String^, int);
	//функции для удаления студентов
	bool RemoveStudent(String^);
	bool RemoveStudent(int);
	//функции поиска студента
	Object^    SearchStudent(int);
	ArrayList^ SearchStudent(String^);
	
private:
	ArrayList ^ Students;
	String^ NameGroup;
};

