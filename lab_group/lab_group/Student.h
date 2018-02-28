#pragma once

#include "PrivateMethodStudent.h"

using namespace System;

ref class Student : PrivateMethodStudent
{
public:
	Student();

	//void SetName();
	void SetName(String^);
	String^ GetName();

	//void SetAge();
	void SetAge(int);
	int GetAge();
private:
	String^ Name;
	int Age;
};

