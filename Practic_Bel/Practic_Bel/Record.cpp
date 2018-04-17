#include "Record.h"



Record::Record()
{
}

void Record::SetData(String^ name, int bal_d, int bal_e) {
	Name = name;
	BallDop = bal_d;
	BallEx = bal_e;
}

int Record::GetSum() {
	return (BallDop + BallEx);
}

String^ Record::Evaluation() {
	if (BallDop < 38 || BallEx < 22)
		return L"Недопуск";

	int sum = BallDop + BallEx;
	if (sum < 60)
		return L"Недопуск";
	else if (sum < 71)
		return L"Удовлетворительно";
	else if (sum < 85)
		return L"Хорошо";
	else
		return L"Отлично";
}