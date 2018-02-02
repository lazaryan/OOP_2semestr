#include "stdafx.h"
#include "FIle.h"

FIle::FIle(){}

void FIle::fopen() { finp = gcnew  StreamReader("Input.txt"); }

void FIle::add_pattern(String ^ patternIn) { pattern = patternIn; }

void FIle::fclose() { finp->Close(); }

void FIle::enter_pinches() {
	bool count = false;

	while (!finp->EndOfStream) {
		String^ pinches = finp->ReadLine();

		if (check_pinches(pinches, pattern)) {
			count = true;
			Console::WriteLine(pinches);
		}
	}

	if (!count) Console::WriteLine(L"Подходящих номеров нет");
}

int FIle::check_pinches(String^ pinches, String^ pattern) {
	for (int i = 0; i < COUNT; i++) {
		if ((pinches[i] != pattern[i]) && pattern[i] != '*') return 0;
	}
	return 1;
}
