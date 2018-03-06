#pragma once

#include "Student.h"

using namespace System;
using namespace System::Collections;

ref class ForGroup
{
public:
	ForGroup();
protected:
	String^ AddString(String^, int, int);
	bool CheckPresencesStudent(ArrayList^, Student^);
	bool CheckString(String^);
	bool SearchNameStudent(String^, ArrayList^);
	bool SearchNameStudent(String^, Student^);
private:
	bool CheckName(String^, String^);
};

