#pragma once

#include "PrivateMethodGroups.h"

using namespace System;
using namespace System::Collections;

ref class Groups :  PrivateMethodGroups
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
};

