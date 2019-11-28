#include "MailBox.h"
#include"Libary.h"
#include<ctime>
time_t hientai = time(0);
void MailBox::SendMessages(int type,string name,Libary l)
{
	int op;
	if (type == 0)
	{
		while (true)
		{   
			try
			{
				cout << "Nhap All/system de gui cho toan he thong" << endl;
				cout << "Nhap 1 de gui, 0 de thoat: ";
				cin >> op;
				if (op == 1)
				{
					string s;
					cout << "To: ";
					cin.ignore();
					getline(cin, s);
					if (s == "All/system")
						SendToSystem(name, l);
					else
						if (Check(s))
						{
							if (!CheckManyAccount(s, l))
							{
								Sleep(500);
								system("CLS");
							}
							SendToManyPeople(name, s);
						}
						else
						{
							if (!l.CheckExistUser(name))
								throw false;
							SendOnePerson(name, s);
						}
				}
				else
					if (op == 0)
						break;
					else
						throw true;
			}
			catch (bool x)
			{
				if (x == false)
				{
					cout << "Khong tim thay nguoi nhan!!!" << endl;
					Sleep(500);
					system("CLS");
				}
				else
					cout << "Lua chon khong hop le!!!" << endl;
			}	
		}
	}
	if (type == 1)
	{
		while (true)
		{
			try
			{
				cout << "Nhap 1 de gui, 0 de thoat: ";
				cin >> op;
				string s;
				if (op == 1)
				{
					cout << "To: ";
					cin.ignore();
					getline(cin, s);
					if (!l.CheckExistUser(name))
						throw false;
					else
						SendOnePerson(name, s);
				}
				else if (op == 0)
					break;
				else
					throw true;
			}
			catch (bool x)
			{
				if (x == false)
				{
					cout << "Khong tim thay nguoi nhan!!!" << endl;
					Sleep(500);
					system("CLS");
				}
				else
					cout << "Lua chon khong hop le!!!" << endl;

			}
		}
	}

}
void MailBox::SendOnePerson(string name,string to)
{
	string s;
	cout << "Message: ";
	getline(cin, s);
	ofstream fileout;
	fileout.open("Message/" + to + ".txt", ios::app);
	fileout << "From: " + name << endl;
	fileout << "Message: " + s << endl;
	string times = ctime(&hientai);
	fileout << "Time: " << times << endl;
	fileout.close();
	cout << "Gui thanh cong!!!" << endl;
}
void MailBox::SendToSystem(string name,Libary libary)
{
	vector<string> temp = libary.GetAccountName();
	string s;
	cout << "Message: ";
	getline(cin, s);
	ofstream fileout;
	for (int i = 1; i < temp.size(); i++)
	{
		fileout.open("Message/" + temp[i] + ".txt",ios::app);
		fileout << "From: " + name << endl;
		fileout << "Message: " + s << endl;
		string times = ctime(&hientai);
		fileout << "Time: " << times << endl;
		fileout.close();
	}
	cout << "Gui thanh cong!!!" << endl;
}
void MailBox::SendToManyPeople(string name,string to)
{
	string s;
	to.append(",");
	cout << "Message: ";
	getline(cin, s);
	ofstream fileout;
	int j = 0;
	for (int i = 0; i < to.length(); i++)
	{
		if (to[i] == ',')
		{
			string temp = to.substr(j, i - j);
			fileout.open("Message/" + temp + ".txt",ios::app);
			fileout << "From: " + name << endl;
			fileout << "Message: " + s << endl;
			string times = ctime(&hientai);
			fileout << "Time: " << times << endl;
			fileout.close();
			j = i + 1;
		}
	}
	cout << "Gui thanh cong!!!" << endl;
}
bool MailBox::Check(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ',')
			return true;
	}
	return false;
}
void MailBox::OpenMail()
{
	for (int i = 0; i < from.size(); i++)
	{
		cout << from[i] << endl;
		cout << messagefrom[i] << endl;
		cout << time[i] << endl << endl;
	}
}
void MailBox::LoadMail(string name)
{
	ifstream filein;
	string s1, s2,s3;
	filein.open("Message/" + name + ".txt");
	while (!filein.eof())
	{
		getline(filein, s1);
		if (s1 == "")
			continue;
		getline(filein, s2);
		getline(filein, s3);
		from.push_back(s1);
		messagefrom.push_back(s2);
		time.push_back(s3);
	}
	filein.close();
}
bool MailBox::CheckManyAccount(string s, Libary l)
{
	s.append(",");
	int j = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ',')
		{
			string temp = s.substr(j, i - j);
			if (!l.CheckExistUser(temp))
			{
				cout << "Khong tim thay nguoi dung co ten " << temp << endl;
				return false;
			}
			j = i + 1;
		}
	}
	return true;
}