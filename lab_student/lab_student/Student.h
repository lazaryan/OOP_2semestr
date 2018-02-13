#pragma once

using namespace System;

ref class Student
{
public:
	Student();
	void SetName();
	String^ GetName();
private:
	bool CheckName(String^);
	String^ Name;
};

