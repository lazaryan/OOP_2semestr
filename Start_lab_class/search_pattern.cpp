#include "stdafx.h"
#include "search_pattern.h"

using namespace System;
using namespace System::IO;

search_pattern::search_pattern(){}

void search_pattern::add_pattern() { pattern = Console::ReadLine(); }

void search_pattern::check_pattern() {
	int length = pattern->Length;

	while (length != COUNT) {
		Console::WriteLine(L"Ошибка ввода. Повторите попытку: ");
		pattern = Console::ReadLine();
	}

	for (int i = 0; i < length; i++) {
		if (pattern[i] != '*' && !(pattern[i] >= '0' && pattern[i] <= '9')) {
			Console::WriteLine(L"Ошибка ввода. Повторите попытку: ");
			pattern = Console::ReadLine();
			check_pattern();
			break;
		}
	}
	file.add_pattern(pattern);
}

