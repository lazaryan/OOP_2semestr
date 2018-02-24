#pragma once

using namespace System;
using namespace System::IO;

ref class Template
{
public:
	Template();
	Template(String^);

	void AddCountSymboll(int);
	void AddTemlate();
	bool OpenFile(String^);
	void AddTemlates();
	void CloseFile();
private:
	int COUNT;
	String ^ temlate;
	StreamReader ^ finp;

	bool CheckTemplate(String^);
	bool CheckTemplateOfFile(String^, String^);
};

