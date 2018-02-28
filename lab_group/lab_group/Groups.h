#pragma once

#include "PrivateMethodGroups.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections;

ref class Groups :  PrivateMethodGroups
{
public:
	Groups();

	bool AddStudent();
	bool AddListStudents();
	void RemoveStudent();
	int GetCountStudent();
	Object^ SearchStudentNum();
	ArrayList^ SearchStudentName();
private:
	ArrayList^ gr;
	String^ number_group;
};

