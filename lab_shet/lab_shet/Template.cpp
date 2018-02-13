#include "stdafx.h"
#include "Template.h"

using namespace System;
using namespace System::IO;

Template::Template(){}

Template::Template(String^ file) {finp = gcnew StreamReader(file);}

void Template::AddTemlate() {
	Console::WriteLine(L"Введите шаблон :");
	String^ tm = Console::ReadLine();

	while (tm->Length != COUNT || !CheckTemplate(tm)) {
		Console::WriteLine(L"Ошибка ввода шаблона! Повторите попытку: ");
		tm = Console::ReadLine();
	}

	temlate = tm;
}

bool Template::CheckTemplate(String^ tm) {
	int length = tm->Length;

	for (int i = 0; i < length; i++)
		if (!(tm[i] == '*' || (tm[i] >= '0' && tm[i] <= '9')))
			return false;

	return true;
}

void Template::OpenFile(String^ file) {finp = gcnew StreamReader(file);}

void Template::CloseFile() {finp->Close();}

void Template::AddTemlates() {
	String^ tm;
	int count = 0;

	while (!finp->EndOfStream) {
		tm = finp->ReadLine();

		if (CheckTemplateOfFile(tm, temlate)) {
			Console::WriteLine(tm);
			count++;
		}
	}
	if(count == 0) Console::WriteLine(L"Подходящие шаблоны не найдены!");
}

bool Template::CheckTemplateOfFile(String^ tm_file, String^ tm_sourse) {
	for (int i = 0; i < COUNT; i++)
		if (!(tm_sourse[i] == '*' || tm_sourse[i] == tm_file[i]))
			return false;

	return true;
}