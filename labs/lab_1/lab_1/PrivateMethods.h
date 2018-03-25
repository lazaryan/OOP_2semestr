#pragma once

using namespace System;

ref class PrivateMethods
{
public:
	PrivateMethods();
protected:
	bool ScheckNameFile(String^);
	int PosSymbol(String^, char);
	int PosFinishSymbol(String^, char);
	String^ GetString(String^ text, int pos1, int pos2);
	bool ScheckString(String^);

	String^ GetServer(String^);
	String^ GetFolders(String^);
};

