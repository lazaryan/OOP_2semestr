#pragma once

using namespace System;

ref class Student
{
public:
	Student();

	void SetName();
	String^ GetName();

	void SetAge();
	String^ GetAge();
private:
	String^ Name;
	String^ Age;

	bool CheckName(String^);
	bool CheckAge(String^);
};

