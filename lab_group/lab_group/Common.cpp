#include "stdafx.h"
#include "Common.h"

int Choice() {

	Console::WriteLine(L"Введите номер запроса");
	Console::WriteLine(L"\t1)Добавить студента");
	Console::WriteLine(L"\t2)Удалить студента");
	Console::WriteLine(L"\t3)Вывод колличества студентов");
	Console::WriteLine(L"\t4)Поиск студента по номеру");
	Console::WriteLine(L"\t5)Поиск студента по фамилии");
	Console::WriteLine(L"\t6)Выход");

	return AddCount(6);

}

int AddCount(int n) {
	String^ num = Console::ReadLine();

	while (num->Length != 1 ||
		!(((int)num[0] - (int)'0') >= 1 && ((int)num[0] - (int)'0') <= n)) {
		Console::WriteLine(L"Ошибка ввода номера. Повторите попытку:");
		num = Console::ReadLine();
	}

	return ((int)num[0] - (int)'0');
}

int ChoiceRepeat() {

	Console::WriteLine(L"Введите номер запроса:");
	Console::WriteLine(L"\t1)Сделать еще один запрос");
	Console::WriteLine(L"\t2)Выход");

	return AddCount(2);
}