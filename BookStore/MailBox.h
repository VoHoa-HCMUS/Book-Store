#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class Libary;
class MailBox
{
	vector<string> from;
	vector<string> messagefrom;
	vector<string> time;
public:
	void SendMessages(int type,string name,Libary l);
	void SendToSystem(string name,Libary libary);
	void SendToManyPeople(string name,string to);
	void SendOnePerson(string name,string to);
	bool Check(string s);
	bool CheckManyAccount(string s,Libary l);
	void OpenMail();
	void LoadMail(string name);
};

