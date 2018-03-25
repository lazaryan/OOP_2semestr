#include "stdafx.h"
#include "Saits.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	Saits^ sait = gcnew Saits();

	if (!sait->OpenFile("input.txt"))//открываем файл для чтения
		return 0;
	sait->SetListSaits();//получаем все данные из него
	sait->SetSait("https://github.com/lazaryan/Starts.html");//добавление вручную


    return 0;
}
