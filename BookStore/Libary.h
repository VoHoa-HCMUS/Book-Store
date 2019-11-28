#pragma once
#include<fstream>
#include<Windows.h>
#include"Admin.h"
class Libary
{
	Guest *guest;
	vector<string>accountname;
	vector<string>password;
	vector<int> age;
	ListBook l;
public:
	void LoadBook();
	void Out();
	void LoadAccount();
	int CheckValidRegister(string name,string pass);
	int CheckValidLogin(string name, string pass);
	int CheckValidUser(string name, string pass);
	int CheckAdminLogin(string name, string pass);
	bool CheckDelAccount(string name);
	void OverWriteAccount(string name, string pass);
	void DelAccountOnDataBase();
	void LoadAllInfo();
	void OverWriteBook();
	void MenuState();
	bool CheckExistUser(string name);
	vector<string> GetAccountName();
};

