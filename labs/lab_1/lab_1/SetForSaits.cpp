#include "stdafx.h"
#include "Saits.h"


bool Saits::SetProtocols(String^ sait) {
	int count = ListProtocols->Count,
		poz = PosSymbol(sait, ':'),
		poz_list;
	String^ prot = GetString(sait, 0, poz),
		^ prot_list;
	ArrayList^ proto = gcnew ArrayList();

	if (count == 0) {
		proto->Add(sait);
		ListProtocols->Add(proto);
		return true;
	}

	for (int i = 0; i < count; i++) {
		ArrayList^ listProt = gcnew ArrayList();
		listProt = (ArrayList^)ListProtocols[i];
		String^ sait_list = (String^)listProt[0];

		poz_list = PosSymbol(sait_list, ':');
		prot_list = GetString(sait, 0, poz_list);

		if (prot_list == prot) {
			listProt->Add(sait);
			return false;
		}
	}

	proto->Add(sait);
	ListProtocols->Add(proto);

	return true;
}

bool Saits::SetServers(String^ sait) {
	int count = ListServers->Count;
	ArrayList^ ser = gcnew ArrayList();

	if (count == 0) {
		ser->Add(sait);
		ListServers->Add(ser);
		return true;
	}

	String^ server = GetServer(sait);

	for (int i = 0; i < count; i++) {
		ArrayList^ server_list = gcnew ArrayList();
		server_list = (ArrayList^)ListServers[i];

		String^ server_li = GetServer((String^)server_list[0]);

		if (server_li == server) {
			server_list->Add(sait);
			return false;
		}
	}

	ser->Add(sait);
	ListServers->Add(ser);

	return true;
}

bool Saits::SetFolders(String^ sait) {
	int count = ListFolders->Count;
	ArrayList^ folder = gcnew ArrayList();

	if (count == 0) {
		folder->Add(sait);
		ListFolders->Add(folder);
		return true;
	}
	String^ way = GetFolders(sait);

	for (int i = 0; i < count; i++) {
		ArrayList^ folder_list = gcnew ArrayList();
		folder_list = (ArrayList^)ListFolders[i];

		String^ way_list = GetFolders((String^)folder_list[0]);
		if (way_list == way) {
			folder_list->Add(sait);
			return false;
		}
	}

	folder->Add(sait);
	ListFolders->Add(folder);

	return true;
}
