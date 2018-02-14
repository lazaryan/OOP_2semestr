#include "stdafx.h"
#include "Common.h"

int Choice() {

	Console::WriteLine(L"Ââåäèòå íîìåğ çàïğîñà");
	Console::WriteLine(L"\t1)Äîáàâèòü ñòóäåíòà");
	Console::WriteLine(L"\t2)Óäàëèòü ñòóäåíòà");
	Console::WriteLine(L"\t3)Âûâîä êîëëè÷åñòâà ñòóäåíòîâ");
	Console::WriteLine(L"\t4)Ïîèñê ñòóäåíòà ïî ôîìèëèè");
	Console::WriteLine(L"\t5)Âûõîä");

	return AddCount(5);

}

int AddCount(int n) {
	String^ num = Console::ReadLine();

	while (num->Length != 1 ||
		!(((int)num[0] - (int)'0') >= 1 && ((int)num[0] - (int)'0') <= n)) {
		Console::WriteLine(L"Îøèáêà ââîäà íîìåğà. Ïîâòîğèòå ïîïûòêó:");
		num = Console::ReadLine();
	}

	return ((int)num[0] - (int)'0');
}

int ChoiceRepeat() {

	Console::WriteLine(L"Ââåäèòå íîìåğ çàïğîñà:");
	Console::WriteLine(L"\t1)Ñäåëàòü åùå îäèí çàïğîñ");
	Console::WriteLine(L"\t2)Âûõîä");

	return AddCount(2);
}