#include "stdafx.h"

using namespace System;
using namespace System::IO;

const int COUNT = 2;//Количество символов в шаблоне
void check_pattern(String^ pattern);
int check_pinches(String^ pinches , String^ pattern);

int main(array<System::String ^> ^args) {  
	Console::WriteLine(L"Введите шаблон: ");
	String^ pattern = Console::ReadLine();
	check_pattern(pattern);

	StreamReader^ finp = gcnew  StreamReader("Input.txt");
	while (!finp->EndOfStream) {
		String^ pinches = finp->ReadLine();

		if (check_pinches(pinches, pattern)) {
			Console::WriteLine(pinches);
		}
	}

	Console::ReadLine();
    return 0;
}

void check_pattern(String^ pattern) {

	int length = pattern->Length;

	while (length != COUNT) {
		Console::WriteLine(L"Ошибка ввода. Повторите попытку: ");
		pattern = Console::ReadLine();
	}

	for (int i = 0; i < length; i++) {
		if (pattern[i] != '*' && !(pattern[i] >= '0' && pattern[i] <= '9')) {
			Console::WriteLine(L"Ошибка ввода. Повторите попытку: ");
			pattern = Console::ReadLine();
			check_pattern(pattern);
			break;
		}
	}
}

int check_pinches(String^ pinches, String^ pattern) {
	for (int i = 0; i < COUNT; i++) {
		if ((pinches[i] != pattern[i]) && pattern[i] !='*') return 0;
	}
	return 1;
}
