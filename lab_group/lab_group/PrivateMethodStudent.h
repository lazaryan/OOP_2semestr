#pragma once

using namespace System;

ref class PrivateMethodStudent
{
public:
	PrivateMethodStudent();
protected:
	bool CheckName(String^);
	bool CheckAge(String^);
	int AddNumber(String^);
};

