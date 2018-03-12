#include "stdafx.h"
#include "Student.h"


Student::Student(){}

Student::Student(String^ file_name) {
	StreamReader^ f_r;
	bool a = true;

	try {
		f_r = gcnew StreamReader(file_name);
	}
	catch (...) {
		a = false;
	}

	if (a) {
		int i = 0;

		while (!f_r->EndOfStream) {
			i++;
			String^ s;

			if (i == 1 && CheckName(s = f_r->ReadLine()))
				Name = s;
			else if (i == 2 && CheckAge(s = f_r->ReadLine()))
				Age = GetNumber(s);
			else if (i > 2)
				break;

		}

		f_r->Close();
	}
	
}

Student::Student(String^ name, int age) {
	if (age > 15 && age < 60)
		Age = age;

	if (CheckName(name))
		Name = name;
}

bool Student::SetName(String^ s){
	if (!CheckName(s))
		return false;
	
	Name = s;

	return true;
}

bool Student::SetAge(String^ s) {
	if (!CheckAge(s)) 
		return false;

	Age = GetNumber(s);
	
	return true;
}

bool Student::SetAge(int a) {
	if (!(a > 15 && a < 60)) return false;

	Age = a;

	return true;
}

String^ Student::GetName() { return Name; }

int Student::GetAge() { return Age; }