#include "stdafx.h"
#include "PrivateMethods.h"


PrivateMethods::PrivateMethods()
{
}
bool PrivateMethods::ScheckNameFile(String^ name) {

	if (name == nullptr || name->Length == 0)
		return false;

	int poz = PosSymbol(name, '.');
	if (poz == -1)
		return false;

	String^ expansion = GetString(name, poz + 1, name->Length);
	if (!ScheckString(expansion))
		return false;

	return true;
}

int PrivateMethods::PosSymbol(String^ s, char symboll) {
	int length = s->Length;

	for (int i = 0; i < length; i++) {
		if (s[i] == symboll)
			return i;
	}

	return -1;
}

int PrivateMethods::PosFinishSymbol(String^ s, char symbol) {
	int length = s->Length;

	for (int i = length - 1; i > 0; i--) {
		if (s[i] == symbol)
			return i;
	}

	return -1;
}

String^ PrivateMethods::GetString(String^ text, int pos1, int pos2) {
	if (text == nullptr || pos1 < 0 || pos2 > text->Length)//nullptr - это означает, что строка пустая
		return "";

	String^ new_str;
	for (int i = pos1; i < pos2; i++) {
		new_str += text[i];
	}

	return new_str;
}

bool PrivateMethods::ScheckString(String^ s) {
	int length = s->Length;

	for (int i = 0; i < length; i++) {
		if (!(
			(s[i] >= 'a' && s[i] <= 'z') ||
			(s[i] >= 'A' && s[i] <= 'Z') ||
			(s[i] >= L'а' && s[i] <= L'я') ||
			(s[i] >= L'Я' && s[i] <= L'Я')
			))
			return false;
	}

	return true;
}

String^ PrivateMethods::GetServer(String^ sait) {
	int poz = PosSymbol(sait, ':');
	String^ server = GetString(sait, poz + 3, sait->Length);
	poz = PosSymbol(server, '/');
	server = GetString(server, 0, poz);
	return server;
}

String^ PrivateMethods::GetFolders(String^ sait) {
	int poz = PosFinishSymbol(sait, '/');
	String^ way = GetString(sait, 0, poz);
	return way;
}
