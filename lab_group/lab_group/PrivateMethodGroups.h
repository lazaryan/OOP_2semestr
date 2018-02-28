#pragma once

#include "Student.h"

using namespace System;
using namespace System::Collections;

ref class PrivateMethodGroups
{
public:
	PrivateMethodGroups();
protected:
	int GetNumber(String^);
	bool CheckNumber(String^);
	bool CheckName(String^);
	bool Equality(String^, String^);
	bool CheckStudent(Student^, ArrayList^);
	String^ AddNameStudent(String^, int);
	String^ AddAgeStudent(String^ , int);
};

