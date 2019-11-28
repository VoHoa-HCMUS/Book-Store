#include "Libary.h"
void Libary::LoadBook()
{
	ifstream booksfile;
	booksfile.open("Data/books.txt");
	string s1, s2, s3, s4;
	char temp;
	int x,y;
	Book book;
	while (!booksfile.eof())
	{
		getline(booksfile, s1, ',');
		if (s1[0] == '\n')
			s1.erase(0, 1);
		if (s1 == "")
			break;
		getline(booksfile, s2, ',');
		getline(booksfile, s3, ',');
		getline(booksfile, s4, ',');
		booksfile >> x >> temp >> y;
		book.SetBook(s1, s2, s3, s4, x,y);
		l.Input(book);
	}
	booksfile.close();
}
void Libary::Out()
{
	l.OutPut();
	guest = new User;
	guest->Register(*this);
}
void Libary::LoadAccount()
{
	accountname.push_back("AD-Hoa");
	password.push_back("1620");
	age.push_back(19);
	ifstream accfile;
	accfile.open("Data/account.txt");
	string s1, s2;
	while (!accfile.eof())
	{
		getline(accfile, s1, ',');
		if (s1[0] == '\n')
			s1.erase(0, 1);
		if (s1 == "")
			break;
		accfile >> s2;
		if (s1.substr(0, 4) == "NXB-" || s1.substr(0, 3) == "TG-")
			age.push_back(0);
		else
		{
			int x;
			accfile >> x;
			age.push_back(x);
		}
		accountname.push_back(s1);
		password.push_back(s2);
	}
	accfile.close();
}
vector<string> Libary::GetAccountName()
{
	return accountname;
}
int Libary::CheckValidRegister(string name, string pass)
{
	for (int i = 0; i < name.length(); i++)
	{
		if (toascii(name[i]) == 44)
			return -1;
	}
	for (int i = 0; i < pass.length(); i++)
	{
		if (toascii(pass[i]) == 44)
			return -1;
	}
	for (int i = 1; i < accountname.size(); i++)
	{
		if (name == accountname[i])
			return 0;
	}
	return 1;
}
void Libary::OverWriteAccount(string name, string pass)
{
	accountname.push_back(name);
	password.push_back(pass);
	ofstream accfile;
	accfile.open("Data/account.txt",ios::trunc);
	for (int i = 1; i < accountname.size(); i++)
	{

		accfile << accountname[i]+ "," + password[i] + "\n";
	}
	accfile.close();
}
void Libary::OverWriteBook()
{
	ofstream booksfile;
	booksfile.open("Data/books.txt", ios::trunc);
	l.OutPutFile(booksfile);
	booksfile.close();
}
void Libary::LoadAllInfo()
{
	LoadBook();
	LoadAccount();
}
int Libary::CheckValidLogin(string name, string pass)
{
	for (int i = 1; i < accountname.size(); i++)
	{
		if (accountname[i] == name && password[i] != pass)
			return 0;
		if (accountname[i] == name && password[i] == pass)
			return 1;
	}
	return -1;
}
int Libary::CheckAdminLogin(string name, string pass)
{
	if ((accountname[0]!= name && password[0] == pass) || (accountname[0] == name && password[0] != pass))
		return 0;
	if (accountname[0] == name && password[0] == pass)
		return 1;
	return -1;
}
bool Libary::CheckExistUser(string name)
{
	for (int i = 1; i < accountname.size(); i++)
	{
		if (accountname[i] == name)
		{
			return true;
		}
	}
	return false;
}
bool Libary::CheckDelAccount(string name)
{
	for (int i = 1; i < accountname.size(); i++)
	{
		if (accountname[i] == name)
		{
			accountname.erase(accountname.begin() + i);
			password.erase(password.begin() + i);
			DelAccountOnDataBase();
			return true;
		}
	}
	return false;
}
void Libary::DelAccountOnDataBase()
{
	ofstream accfile;
	accfile.open("Data/account.txt", ios::trunc);
	for (int i = 1; i < accountname.size(); i++)
	{

		accfile << accountname[i] + "," + password[i] + "\n";
	}
	accfile.close();
}
int Libary::CheckValidUser(string name, string pass)
{
	for (int i = 1; i < accountname.size(); i++)
	{
		if (accountname[i] == name && password[i] != pass)
			return 0;
		if (accountname[i] == name && password[i] == pass)
			return age[i];
	}
	return -1;
}
void Libary::MenuState()
{
	while (true)
	{
		int op;
	loop:cout << "Chao mung den voi thu vien!" << endl;
		cout << "0.Exit." << endl;
		cout << "1.Dang ki." << endl;
		cout << "2.Dang nhap." << endl;
		cout << "3.Dang nhap voi tai khoan khach." << endl;
		cout << "Nhap lua chon: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{
		}
		break;
		case 1:
		{
			system("CLS");
			while (true)
			{
			loop2:cout << "Chon loai tai khoan:" << endl;
				cout << "0.Exit" << endl;
				cout << "1.User." << endl;
				cout << "2.Nha xuat ban." << endl;
				cout << "3.Tac gia." << endl;
				cout << "Nhap lua chon: ";
				int op1;
				cin.clear();
				cin >> op1;
				switch (op1)
				{
				case 0:
				{
					system("CLS");
					goto loop;
				}
				case 1:
				{
					system("CLS");
					guest = new User;
					guest->Register(*this);
				}
				break;
				case 2:
				{
					system("CLS");
					guest = new Publisher;
					guest->Register(*this);
					goto loop;
				}
				break;
				case 3:
				{
					system("CLS");
					guest = new Author;
					guest->Register(*this);
					goto loop;
				}
				break;
				default:
					cout << "Lua chon ko hop le!" << endl;
					Sleep(500);
					system("CLS");
					break;
				}
			}
		}
		case 2:
		{
			system("CLS");
			while (true)
			{
			loop1:cout << "Ban la:" << endl;
				cout << "0.Exit" << endl;
				cout << "1.User." << endl;
				cout << "2.Admin." << endl;
				cout << "3.Nha xuat ban." << endl;
				cout << "4.Tac gia." << endl;
				cout << "Nhap lua chon: ";
				int op1;
				cin.clear();
				cin >> op1;
				switch (op1)
				{
				case 0:
				{
					system("CLS");
					goto loop;
				}
				break;
				case 1:
				{
					system("CLS");
					int op3;
					guest = new User;
					guest->Login(*this,op3);
					if (op3 == 0)
						goto loop1;
					while (true)
					{
						system("CLS");
						loop6:cout << "0.Dang xuat" << endl;
						cout << "1.In tat ca cac sach" << endl;
						cout << "2.Tim sach" << endl;
						cout << "3.Mua sach" << endl;
						cout << "4.Hop thu den" << endl;
						cout << "5.Gui tin nhan" << endl;
						int op2;
						cout << "Nhap lua chon: ";
						cin.clear();
						cin >> op2;
						switch (op2)
						{
						case 0:
						{
							system("CLS");
							goto loop1;
						}
						break;
						case 1:
						{
							l.OutPut();
						}
						break;
						case 2:
						{
							system("CLS");
							guest->FindBook(l);
						}
						break;
						case 3:
						{
							system("CLS");
							guest->BuyBook(l);
							goto loop6;
						}
						break;
						case 4:
						{
							system("CLS");
							guest->OpenMailBox();
						}
						break;
						case 5:
						{
							system("CLS");
							guest->SendMessages(*this);
						}
						break;
						default:
							cout << "Lua chon ko hop le!" << endl;
							Sleep(500);
							system("CLS");
							break;
						}
					}
				}
				break;
				case 2:
				{
					system("CLS");
					int op3;
					guest = new Admin;
					guest->Login(*this, op3);
					if (op3 == 0)
					{
						system("CLS");
						goto loop1;
					}
				loop4:system("CLS");
					while (true)
					{
						cout << "0.Dang xuat" << endl;
						cout << "1.In tat ca cac sach" << endl;
						cout << "2.Tim sach" << endl;
						cout << "3.Mua sach" << endl;
						cout << "4.Them sach" << endl;
						cout << "5.Xoa sach" << endl;
						cout << "6.Sua sach" << endl;
						cout << "7.Xoa tai khoan" << endl;
						cout << "8.Hop thu den" << endl;
						cout << "9.Gui tin nhan" << endl;
						int op2;
						cout << "Nhap lua chon: ";
						cin.clear();
						cin >> op2;
						switch (op2)
						{
						case 0:
						{
							system("CLS");
							goto loop1;
						}
						break;
						case 1:
						{
							system("CLS");
							l.OutPut();
						}
						break;
						case 2:
						{
							system("CLS");
							guest->BuyBook(l);
						}
						break;
						case 3:
						{
							system("CLS");
							guest->FindBook(l);
						}
						break;
						case 4:
						{
							system("CLS");
							guest->AddBook(l, *this);
							OverWriteBook();
						}
						break;
						case 5:
						{
						loop3:system("CLS");
							while (true)
							{
								int op;
								cout << "Menu:" << endl;
								cout << "0.Exit" << endl;
								cout << "1.Xoa sach cua tac gia" << endl;
								cout << "2.Xoa sach cua nha xuat ban" << endl;
								cout << "3.Xoa sach bat ki" << endl;
								cout << "Nhap lua chon: ";
								cin >> op;
								switch (op)
								{
								case 0:
									break;
								case 1:
								{
									system("CLS");
									guest->DeleteAuthor(l, *this);
									OverWriteBook();
								}
								break;
								case 2:
								{
									system("CLS");
									guest->DeletePublisher(l, *this);
									OverWriteBook();
								}
								break;
								case 3:
								{
									system("CLS");
									guest->DeleteBook(l, *this);
									OverWriteBook();
								}
								break;
								default:
									cout << "Lua chon khong hop le!!!";
									Sleep(500);
									goto loop3;
								}
								if (op == 0)
								{
									goto loop4;
								}
							}
							if (op == 0)
							{
								goto loop4;
							}
						}
						break;
						case 6:
						{
							system("CLS");
							guest->FixPrice(l);
							OverWriteBook();
						}
						break;
						case 7:
						{
						loop5:system("CLS");
							while (true)
							{
								int op;
								cout << "Menu:" << endl;
								cout << "0.Exit" << endl;
								cout << "1.Xoa tai khoan cua tac gia" << endl;
								cout << "2.Xoa tai khoan cua nha xuat ban" << endl;
								cout << "3.Xoa tai khoan cua user" << endl;
								cout << "Nhap lua chon: ";
								cin >> op;
								switch (op)
								{
								case 0:
									break;
								case 1:
								case 2:
								case 3:
								{
									system("CLS");
									guest->DeleteAccount(*this, op);
								}
								break;
								default:
									cout << "Lua chon khong hop le!!!" << endl;
									Sleep(500);
									goto loop5;
								}
							}
						}
						break;
						case 8:
						{
							system("CLS");
							guest->OpenMailBox();
						}
						break;
						case 9:
						{
							system("CLS");
							guest->SendMessages(*this);
						}
						break;
						default:
							cout << "Lua chon ko hop le!" << endl;
							Sleep(500);
							goto loop4;
						}
					}
				}
				break;
				case 3:
				{
					
					system("CLS");
					int op3;
					guest = new Publisher;
					guest->Login(*this, op3);
					if (op3 == 0)
					{
						system("CLS");
						goto loop1;
					}
					system("CLS");
					while (true)
					{
						cout << "0.Dang xuat" << endl;
						cout << "1.In tat ca cac sach" << endl;
						cout << "2.Tim sach" << endl;
						cout << "3.Them sach" << endl;
						cout << "4.Xoa sach" << endl;
						cout << "5.Thong tin nha xuat ban" << endl;
						int op2;
						cout << "Nhap lua chon: ";
						cin.clear();
						cin >> op2;
						switch (op2)
						{
						case 0:
						{
							system("CLS");
							goto loop1;
						}
						break;
						case 1:
						{
							system("CLS");
							guest->OutPutBook(l);
						}
						break;
						case 2:
						{
							system("CLS");
							guest->FindBook(l);
						}
						break;
						case 3:
						{
							system("CLS");
							guest->AddBook(l, *this);
							OverWriteBook();
						}
						break;
						case 4:
						{
							system("CLS");
							guest->DeleteBook(l, *this);
							OverWriteBook();
						}
						break;
						case 5:
						{
							system("CLS");
							guest->PrintInfo(l);
						}
						break;
						default:
							cout << "Lua chon ko hop le!" << endl;
							Sleep(500);
							system("CLS");
							break;
						}
					}

				}
				break;
				case 4:
				{
					system("CLS");
					int op3;
					guest = new Author;
					guest->Login(*this, op3);
					if (op3 == 0)
					{
						system("CLS");
						goto loop1;
					}
					system("CLS");
					while (true)
					{
					
						cout << "0.Dang xuat" << endl;
						cout << "1.In tat ca cac sach" << endl;
						cout << "2.Tim sach" << endl;
						cout << "3.Them sach" << endl;
						cout << "4.Xoa sach" << endl;
						cout << "5.Sua sach" << endl;
						cout << "6.Thong tin tac gia" << endl;
						int op2;
						cout << "Nhap lua chon: ";
						cin.clear();
						cin >> op2;
						switch (op2)
						{
						case 0:
						{
							system("CLS");
							goto loop1;
						}
						break;
						case 1:
						{
							system("CLS");
							guest->OutPutBook(l);
						}
						break;
						case 2:
						{
							system("CLS");
							guest->FindBook(l);	
						}
						break;
						case 3:
						{
							system("CLS");
							guest->AddBook(l, *this);
							OverWriteBook();
						}
						break;
						case 4:
						{
							system("CLS");
							guest->DeleteBook(l, *this);
							OverWriteBook();
						}
						break;
						case 5:
						{
							system("CLS");
						
						}
						break;
						case 6:
						{
							system("CLS");
							guest->PrintInfo(l);
						}
						break;
						default:
							system("CLS");
							cout << "Lua chon ko hop le!" << endl;
							Sleep(500);
							break;
						}
					}
				}
				default:
					cout << "Lua chon ko hop le!" << endl;
					Sleep(500);
					system("CLS");
					break;
				}
			}
		}
		break;
		case 3:
		{
			system("CLS");
			guest = new Guest;
			while (true)
			{
				cout << "0.Exit" << endl;
				cout << "1.In tat ca cac sach" << endl;
				cout << "2.Tim sach" << endl;
				int op1;
				cout << "Nhap lua chon: ";
				cin.clear();
				cin >> op1;
				switch (op1)
				{
				case 0:
				{
					system("CLS");
					goto loop;
				}
				break;
				case 1:
				{
					l.OutPut();
				}
				break;
				case 2:
				{
					system("CLS");
					guest->FindBook(l);
				}
				break;
				default:
					cout << "Lua chon ko hop le!" << endl;
					Sleep(500);
					system("CLS");
					break;
				}
			}
		}
		break;
		default:
			cout << "Lua chon ko hop le!" << endl;
			Sleep(500);
			system("CLS");
			break;
		}
		if (op == 0)
			break;
	}
}
