#include "stdafx.h"
#include "search_pattern.h"


int main(array<System::String ^> ^args) {
	search_pattern object;

	Console::WriteLine(L"Введите шаблон: ");
	object.add_pattern();//получаем шаблон
	object.check_pattern();//проверяем его

	object.open_file();//открываем файл
	object.enter_pinches();//выводим все подходящие номера счетов
	object.close_file();//закрываем файл

	Console::ReadLine();//холостой ввод
	return 0;
}
