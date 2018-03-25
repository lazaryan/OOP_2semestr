#pragma once
#include "PrivateMethods.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections;

ref class Saits : PrivateMethods
{
public:
	Saits();
	~Saits();

	bool OpenFile(String^);//открыть файл
	void SetListSaits();//получить данные
	void SetSait(String^);
private:
	String ^ NameFile;//имя файла
	ArrayList^ ListSaits;//список всех сайтов
	StreamReader^ inp_r;

	/*списки*/
	ArrayList^ ListProtocols;//с одинаковым протоколом
	ArrayList^ ListServers;//с одинаковым сервером
	ArrayList^ ListFolders;//с одинаковым путем

	//в файле SetForSaits.cpp
	bool SetProtocols(String^);
	bool SetServers(String^);
	bool SetFolders(String^);
};

