#pragma once

using namespace System;
using namespace System::IO;

ref class Template
{
public:
	Template();
	Template(String^);

	void AddTemlate();
	void OpenFile(String^);
	void AddTemlates();
	void CloseFile();
private:
	const int const COUNT = 3;
	String ^ temlate;
	StreamReader ^ finp;

	bool CheckTemplate(String^);
	bool CheckTemplateOfFile(String^, String^);
};

