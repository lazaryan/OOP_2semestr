#include "stdafx.h"
#include "search_pattern.h"


int main(array<System::String ^> ^args) {
	search_pattern object;

	Console::WriteLine(L"Введите шаблон: ");
	object.add_pattern();//получаем шаблон
	object.check_pattern();//проверяем его

	object.file.fopen();//открываем файл
	object.file.enter_pinches();//выводим все подходящие номера счетов
	object.file.fclose();//закрываем файл

	Console::ReadLine();//холостой ввод
	return 0;
}
