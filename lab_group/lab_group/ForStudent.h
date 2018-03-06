#pragma once

using namespace System;

ref class ForStudent
{
public:
	ForStudent();
protected:
	bool CheckName(String^);
	
	bool CheckAge(String^);
	int GetNumber(String^);
};

