#pragma once
#include "ForPara.h"
#include "StructForPara.h"

using namespace System;

ref class Para : ForPara
{
public:
	Para();
	/*внесение*/
	bool SetTime(String^);
	bool SetAuditorium(String^);
	bool SetAuditorium(String^, int);
	bool SetGroup(String^);
	bool SetGroup(String^, int);
	bool SetPredmet(String^);
	bool SetTeacher(String^ name_teacher);
	bool SetTeacher(String^ name_teacher, String^ cvalification);
private:
	Date Time;//время пары
	Audit Auditorium;//аудитория
	Group GroupStudents;//группа
	String^ Predmet = "None";//предмет
	Teacher Teach;//преподаватель
};

