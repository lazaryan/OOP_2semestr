// lab_group.cpp: ������� ���� �������.

#include "stdafx.h"

#include "Common.h"//������� ��� ������ ������� �������
#include "Groups.h"

using namespace System;
using namespace System::IO;

int main(array<System::String ^> ^args) {
	Groups^ gr = gcnew Groups();//������� �����
	
	int n = 1;
	while (n == 1) {
		switch (Choice()) {
		case 1: 
			gr->AddStudent();//��������� ��������
			break;
		default:
			break;
		}
		n = ChoiceRepeat();
	}

	Console::ReadLine();
    return 0;
}
