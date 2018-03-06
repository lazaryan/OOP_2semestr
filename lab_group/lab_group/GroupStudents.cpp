#include "stdafx.h"
#include "GroupStudents.h"

GroupStudents::GroupStudents() {
	Students = gcnew ArrayList();
}

bool GroupStudents::SetListStudents(String ^name_file) {
	StreamReader^ inp_r;
	int a;

	try {
		inp_r = gcnew StreamReader(name_file);
	}
	catch (...) {
		return false;
	}

	while (!inp_r->EndOfStream) {
		Student^ st = gcnew Student();
		String^ student;

		student = inp_r->ReadLine();

		if (student->Length == 0) continue;
		a = student->IndexOf(';');
		if (a == -1) continue;

		String^ name = AddString(student, 0, a),
			  ^ age  = AddString(student, a + 1, student->Length);

		if (st->SetName(name) && st->SetAge(age)) {
			Students->Add(st);
		}
		
	}

	inp_r->Close();

	return true;
}

bool GroupStudents::SetStudents(String^ inp, Student^ stud) {
	StreamWriter^ inp_w;

	try {
		inp_w = gcnew StreamWriter(inp , true);
	}
	catch (...) {
		return false;
	}

	if (CheckPresencesStudent(Students, stud))
		return false;

	Students->Add(stud);
	inp_w->WriteLine("\n{0};{1}", stud->GetName(), stud->GetAge());

	inp_w->Close();
	
	return true;
}

bool GroupStudents::SetStudents(String^ inp, String^ name, int age) {
	Student^ st = gcnew Student();
	StreamWriter^ inp_w;

	try {
		inp_w = gcnew StreamWriter(inp, true);
	}
	catch (...) {
		return false;
	}

	if ((!(st->SetName(name) && st->SetAge(age))) || CheckPresencesStudent(Students, st))
		return false;

	Students->Add(st);
	inp_w->WriteLine("\n{0};{1}", st->GetName(), st->GetAge());

	inp_w->Close();

	return true;
}

bool GroupStudents::SetStudents(String^ inp, String^ stud) {
	StreamWriter^ inp_w;
	Student^ st = gcnew Student();
	int a;

	try {
		inp_w = gcnew StreamWriter(inp, true);
	}
	catch (...) {
		return false;
	}

	if (stud->Length == 0) return false;

	a = stud->IndexOf(';');
	if (a == -1) return false;

	String^ name = AddString(stud, 0, a),
		  ^ age  = AddString(stud, a + 1, stud->Length);

	if ((st->SetName(name) && st->SetAge(age)) && !CheckPresencesStudent(Students, st)) {
		Students->Add(st);
		inp_w->WriteLine("\n{0};{1}", st->GetName(), st->GetAge());
	}
	else { 
		inp_w->Close();
		return false; 
	}

	inp_w->Close();

	return true;
}

bool GroupStudents::SetStudents(String^ inp, StreamReader^ inp_r) {
	StreamWriter^ inp_w;
	int a;

	try {
		inp_w = gcnew StreamWriter(inp, true);
	}
	catch (...) {
		return false;
	}

	while (!inp_r->EndOfStream) {
		Student^ st = gcnew Student();
		String^ student;

		student = inp_r->ReadLine();

		if (student->Length == 0) continue;

		a = student->IndexOf(';');
		if (a == -1) continue;

		String^ name = AddString(student, 0, a),
			  ^ age = AddString(student, a + 1, student->Length);

		if (st->SetName(name) && st->SetAge(age) && !CheckPresencesStudent(Students, st)) {
			Students->Add(st);
			inp_w->WriteLine("\n12{0};{1}", st->GetName(), st->GetAge());
			
		}

	}

	inp_r->Close();

	return true;
}

bool GroupStudents::RemoveStudent(String^ name) {
	int length = Students->Count;

	if (!CheckString(name)) return false;
	
	for (int i = 0; i < length; i++) {
		Student^ st = gcnew Student();
		st = (Student^)Students[i];
		if (SearchNameStudent(name, Students)) {
			RemoveStudent(i + 1);
			return true;
		}
	}
	
	return false;
}

bool GroupStudents::RemoveStudent(int number) {
	StreamWriter^ inp_w;

	if (number < 1 || number > Students->Count) return false;

	Students->Remove(Students[number - 1]);

	try {
		inp_w = gcnew StreamWriter("Students.txt");
	}
	catch (...) {
		return false;
	}
	int length = Students->Count;

	for (int i = 0; i < length; i++) {
		Student^ st = gcnew Student();
		st = (Student^)Students[i];
		inp_w->WriteLine("{0};{1}", st->GetName(), st->GetAge());
	}

	inp_w->Close();
	return true;
}

Object^ GroupStudents::SearchStudent(int number) {
	if (number < 1 || number > Students->Count) return false;

	return Students[number - 1];
}

ArrayList^ GroupStudents::SearchStudent(String^ name) {
	ArrayList^ list = gcnew ArrayList();
	int length = Students->Count;

	if (!CheckString(name)) return list;

	for (int i = 0; i < length; i++) {
		if (SearchNameStudent(name, (Student^)Students[i])) {
			list->Add(Students[i]);
		}
	}


	return list;
}