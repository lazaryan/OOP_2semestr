#pragma once
#include "ForStudent.h"

using namespace System;
using namespace System::IO;

ref class Student : ForStudent
{
public:
	Student();
	Student(String^);
	Student(String^, int);

	bool SetName(String^);
	String^ GetName();

	bool SetAge(String^);
	bool SetAge(int);
	int GetAge();
private:
	String ^ Name;
	int Age;
};

