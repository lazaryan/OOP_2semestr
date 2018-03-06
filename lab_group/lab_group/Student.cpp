#include "stdafx.h"
#include "Student.h"


Student::Student(){}

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