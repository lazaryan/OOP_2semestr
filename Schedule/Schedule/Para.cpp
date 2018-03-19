#include "stdafx.h"
#include "Para.h"


Para::Para()
{
}

bool Para::SetTime(String^ time) {
	int pos = PosSumbol(time, '-');
	if (pos == -1)
		return false;
	
	String^ start_date = GetString(time, 0, pos);
	String^ finish_date = GetString(time, pos + 1, time->Length);

	pos = PosSumbol(start_date, ':');
	if (pos == -1)
		return false;
	Time.HoursStart = GetNumber(GetString(start_date, 0, pos));
	Time.MinutesStart = GetNumber(GetString(start_date, pos + 1, start_date->Length));

	pos = PosSumbol(finish_date, ':');
	if (pos == -1)
		return false;
	Time.HoursFinish = GetNumber(GetString(finish_date, 0, pos));
	Time.MinutesFinish = GetNumber(GetString(finish_date, pos + 1, finish_date->Length));
	
	return true;
}

bool Para::SetAuditorium(String^ audit) {
	if (!((audit[0] >= L'À' && audit[0] <= L'ß' || audit[0] >= L'à' && audit[0] <= L'ÿ') &&
		ScheckNumber(GetString(audit, 1, audit->Length))
		))
		return false;

	Auditorium.NumberAuditorium = audit;

	return true;
}

bool Para::SetAuditorium(String^ audit, int max_count) {
	if (!SetAuditorium(audit))
		return false;

	if (!(max_count > 10 && max_count < 1000))
		return false;
	Auditorium.MaxCountStudent = max_count;

	return true;
}

bool Para::SetGroup(String^ group) {
	if (group->Length == 0)
		return false;

	GroupStudents.NameGroup = group;

	return true;
}

bool Para::SetGroup(String^ name_group, int count_student) {
	if (name_group->Length == 0)
		return false;

	GroupStudents.NameGroup = name_group;

	if (count_student < 1)
		return false;

	GroupStudents.CountStudent = count_student;
	return true;
}

bool Para::SetPredmet(String^ pred) {
	if (!ScheckString(pred))
		return false;

	Predmet = pred;

	return true;
}

bool Para::SetTeacher(String^ name_teacher) {
	if (!ScheckName(name_teacher))
		return false;
	
	int pos_space = PosSumbol(name_teacher, ' ');

	String^ buf = GetString(name_teacher, 0, pos_space);
	Teach.NameTeacher.UserName = buf;

	buf = GetString(name_teacher, pos_space + 1, name_teacher->Length);
	pos_space = PosSumbol(buf, ' ');
	Teach.NameTeacher.LastName = GetString(name_teacher, 0, pos_space);

	buf = GetString(buf, pos_space + 1, buf->Length);
	Teach.NameTeacher.MiddleName = buf;


	return true;
}

bool Para::SetTeacher(String^ name_teacher, String^ cvalification) {
	if (!SetTeacher(name_teacher))
		return false;

	if (!ScheckString(cvalification))
		return false;
	Teach.Status = cvalification;

	return true;
}