#pragma once

using namespace System;

ref class PrivateMethodGroups
{
public:
	PrivateMethodGroups();
protected:
	int GetNumber(String^);
	bool CheckNumber(String^);
	bool CheckName(String^);
	bool Equality(String^, String^);
};

