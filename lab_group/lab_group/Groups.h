#pragma once

using namespace System;
using namespace System::Collections;

ref class Groups
{
public:
	Groups();
	void AddStudent();

private:
	ArrayList^ gr;
	String^ number_group;
};

