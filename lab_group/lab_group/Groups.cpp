#include "stdafx.h"
#include "Groups.h"
#include "Student.h"

Groups::Groups() {gr = gcnew ArrayList();}

void Groups::AddStudent() {
	Student^ st = gcnew Student();

	Console::WriteLine(L"������� ��� � �������: � � �!");
	st->SetName();

	Console::WriteLine(L"������� ��� �������� �������� ��������");
	st->SetAge();

	gr->Add(st);
}