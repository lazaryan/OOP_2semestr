#pragma once

using namespace System;

ref class Student
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

	bool CheckName(String^);
	bool CheckAge(String^);
	int AddNumber(String^);
};

