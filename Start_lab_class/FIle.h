#pragma once

using namespace System;
using namespace System::IO;

ref class FIle
{
public:
	FIle();
	void fopen();
	void fclose();
	void enter_pinches();
	int check_pinches(String^ pinches, String^ pattern);
	void add_pattern(String ^ pattern);
	const int const COUNT = 2;
private:
	StreamReader ^ finp;
	String ^ pattern;
};

