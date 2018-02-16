#pragma once

using namespace System;
using namespace System::Collections;

ref class Groups
{
public:
	Groups();

	void AddStudent();
	void RemoveStudent();
	int GetCountStudent();
	Object^ SearchStudentNum();
	ArrayList^ SearchStudentName();
private:
	ArrayList^ gr;
	String^ number_group;

	int GetNumber(String^);
	bool CheckNumber(String^);
	bool CheckName(String^);
	bool Equality(String^, String^);
};

