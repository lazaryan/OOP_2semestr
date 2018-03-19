#pragma once

using namespace System;

ref class ForPara
{
public:
	ForPara();
protected:
	int PosSumbol(String^, char);
	String^ GetString(String^, int, int);
	int GetNumber(String^);
	bool ScheckNumber(String^);
	bool ScheckString(String^);
	bool ScheckName(String^);
};

