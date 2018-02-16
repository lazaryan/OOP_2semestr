#pragma once

#include "PrivateMethodStudent.h"

using namespace System;

ref class Student : PrivateMethodStudent
{
public:
	Student();

	void SetName();
	String^ GetName();

	void SetAge();
	int GetAge();
private:
	String^ Name;
	int Age;
};

