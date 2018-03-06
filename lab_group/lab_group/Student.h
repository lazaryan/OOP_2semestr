#pragma once
#include "ForStudent.h"

using namespace System;

ref class Student : ForStudent
{
public:
	Student();

	bool SetName(String^);
	String^ GetName();

	bool SetAge(String^);
	bool SetAge(int);
	int GetAge();
private:
	String ^ Name;
	int Age;
};

