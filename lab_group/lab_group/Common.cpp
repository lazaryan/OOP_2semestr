#include "stdafx.h"
#include "Common.h"

int Choice() {

	Console::WriteLine(L"������� ����� �������");
	Console::WriteLine(L"\t1)�������� ��������");
	Console::WriteLine(L"\t2)������� ��������");
	Console::WriteLine(L"\t3)����� ����������� ���������");
	Console::WriteLine(L"\t4)����� �������� �� �������");
	Console::WriteLine(L"\t5)�����");

	return AddCount(5);

}

int AddCount(int n) {
	String^ num = Console::ReadLine();

	while (num->Length != 1 ||
		!(((int)num[0] - (int)'0') >= 1 && ((int)num[0] - (int)'0') <= n)) {
		Console::WriteLine(L"������ ����� ������. ��������� �������:");
		num = Console::ReadLine();
	}

	return ((int)num[0] - (int)'0');
}

int ChoiceRepeat() {

	Console::WriteLine(L"������� ����� �������:");
	Console::WriteLine(L"\t1)������� ��� ���� ������");
	Console::WriteLine(L"\t2)�����");

	return AddCount(2);
}