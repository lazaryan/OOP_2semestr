#pragma once

#include "FIle.h"

using namespace System;
using namespace System::IO;

ref class search_pattern: FIle
{
public:
	search_pattern();
	void add_pattern();
	void check_pattern();
	FIle file;
private:
	String ^ pattern;
};

