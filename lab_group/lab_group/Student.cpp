#include "stdafx.h"
#include "Student.h"

using namespace System;
using namespace System::IO;

Student::Student() {}

void Student::SetName(String^s) {
	Name = s;
}

void  Student::SetAge(int a) {
	Age = a;
}

String^ Student::GetName() { return Name; }

int Student::GetAge() { return Age; }

