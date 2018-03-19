#ifndef _StructForPara_
#define _StructForPara_

using namespace System;

ref struct Date {
	int HoursStart;
	int MinutesStart;
	int HoursFinish;
	int MinutesFinish;
};

ref struct Audit {
	String^ NumberAuditorium;
	int MaxCountStudent = 20;//по умолчанию пусть будет 20
};

ref struct Group {
	String^ NameGroup;
	int CountStudent;
};

ref struct Name {
	String^ UserName;
	String^ LastName;
	String^ MiddleName;
};

ref struct Teacher {
	Name NameTeacher;
	String^ Status;//студент, доцент....
};
#endif