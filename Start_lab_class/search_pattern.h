#pragma once

using namespace System;
using namespace System::IO;

ref class search_pattern
{
public:
	search_pattern();
	void add_pattern();
	void check_pattern();
	void open_file();
	void close_file();
	void enter_pinches();
	int check_pinches(String^ pinches, String^ pattern);
private:
	const int const COUNT = 2;
	String ^ pattern;
	StreamReader^ finp;
};

