#include "stdafx.h"
#include "Saits.h"


Saits::Saits()
{
	ListSaits     = gcnew ArrayList();
	ListProtocols = gcnew ArrayList();
	ListServers   = gcnew ArrayList();
	ListFolders   = gcnew ArrayList();
}

Saits::~Saits() {
	inp_r->Close();
}

bool Saits::OpenFile(String^ name_file) {
	if (!ScheckNameFile(name_file))
		return false;

	NameFile = name_file;

	try {
		inp_r = gcnew StreamReader(name_file);
	}
	catch (...) {
		return false;
	}

	return true;
}

void Saits::SetSait(String^ sait) {
	ListSaits->Add(sait);

	SetProtocols(sait);
	SetServers(sait);
	SetFolders(sait);
}


void Saits::SetListSaits() {
	while (!inp_r->EndOfStream) {
		String^ sait = inp_r->ReadLine();
		SetSait(sait);
	}
}
