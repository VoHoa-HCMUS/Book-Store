#include "Admin.h"
#include"Libary.h"
void Admin::Login(Libary libary, int& op)
{
	while (true)
	{
		try
		{
			cout << "Nhap 1 de dang nhap,0 de thoat: ";
			cin >> op;
			if (op != 1 && op != 0)
				throw 2;
			if (op == 0)
				break;
			cout << "Nhap ten dang nhap: ";
			cin.ignore();
			getline(cin, accountname);
			cout << "Nhap mat khau: ";
			getline(cin, password);
			if (libary.CheckAdminLogin(accountname,password) == 1)
				break;
			else if (libary.CheckAdminLogin(accountname, password) == 0)
				throw false;
			else
				throw - 1;
		}
		catch (bool)
		{
			cout << "Ten dang nhap hoac mat khau sai!!!" << endl;
		}
		catch (int x)
		{
			if (x == -1)
				cout << "Tai khoan khong ton tai!!!" << endl;
			else
				cout << "Lua chon khong hop le!!!" << endl;
		}
	}
}
void Admin::BuyBook(ListBook list)
{
	User::BuyBook(list);
}
void Admin::DeleteBook(ListBook& list, Libary libary)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de xoa, 0 de thoat: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{

		}
		break;
		case 1:
		{
			string name;
			cout << "Nhap ten sach can xoa: ";
			cin.ignore();
			getline(cin, name);
			if (list.CountBook(name) == 0)
			{
				cout << "Khong tim thay sach." << endl;
			}
			else if (list.CountBook(name) == 1)
			{
				list.DelBookAtName(name);
				cout << "Xoa thanh cong!!!" << endl;
			}
			else
			{
				string id;
				cout << "Tim thay " << list.CountBook(name) << " cuon " << name << ":" << endl;
				list.OutPutSameBook(name);
				cout << "Nhap ma sach can xoa: ";
				getline(cin, id);
				list.DelBookAtId(id);
				cout << "Xoa thanh cong!!!" << endl;
			}
		}
		break;
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		if (op == 0)
		{
			system("CLS");
			break;
		}
	}
}
void Admin::DeleteAuthor(ListBook& list, Libary libary)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de xoa, 0 de thoat: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{

		}
		break;
		case 1:
		{
			string name;
			cout << "Nhap ten tac gia can xoa: ";
			cin.ignore();
			getline(cin, name);
			if (list.DelAuthorBook(name))
			{
				cout << "Da xoa tat ca cuon sach cua tac gia " << name << endl;
			}
			else
				cout << "Khong tim thay tac gia" << endl;
		}
		break;
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		if (op == 0)
		{
			system("CLS");
			break;
		}
	}
}
void Admin::DeletePublisher(ListBook& list, Libary libary)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de xoa, 0 de thoat: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{

		}
		break;
		case 1:
		{
			string name;
			cout << "Nhap ten nha xuat ban can xoa: ";
			cin.ignore();
			getline(cin, name);
			if (list.DelPublisherBook(name))
			{
				cout << "Da xoa tat ca cuon sach cua nha xuat ban " << name << endl;
			}
			else
				cout << "Khong tim thay nha xuat ban" << endl;
		}
		break;
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		if (op == 0)
		{
			system("CLS");
			break;
		}
	}
}
void Admin::DeleteAccount(Libary libary,int op)
{
	switch (op)
	{
	case 1:
	{
		int op1;
		while (true)
		{
			cout << "Nhap 1 de xoa,0 de thoat:";
			cin >> op1;
			switch (op1)
			{
			case 0:
			{

			}
			break;
			case 1:
			{
				string name;
				cout << "Nhap ten tai khoan can xoa(co dang TG-Ten Tac Gia): ";
				cin.ignore();
				getline(cin, name);
				if (name.substr(0, 3) != "TG-")
					cout << "Ten tai khoan khong hop le!!!" << endl;
				else if (!libary.CheckDelAccount(name))
					cout << "Tai khoan khong ton tai!!!" << endl;
				else
				{
					cout << "Xoa thanh cong!!!" << endl;
				}
			}
			break;
			default:
				cout << "Lua chon khong hop le!!!" << endl;
				break;
			}
			if (op == 0)
			{
				system("CLS");
				break;
			}
		}
	}
	break;
	case 2:
	{
		int op1;
		while (true)
		{
			cout << "Nhap 1 de xoa,0 de thoat:";
			cin >> op1;
			switch (op1)
			{
			case 0:
			{

			}
			break;
			case 1:
			{
				string name;
				cout << "Nhap ten tai khoan can xoa(co dang NXB-Ten Nha Xuat Ban): ";
				cin.ignore();
				getline(cin, name);
				if (name.substr(0, 4) != "NXB-")
					cout << "Ten tai khoan khong hop le!!!" << endl;
				else if (!libary.CheckDelAccount(name))
					cout << "Tai khoan khong ton tai!!!" << endl;
				else
				{
					cout << "Xoa thanh cong!!!" << endl;
				}
			}
			break;
			default:
				cout << "Lua chon khong hop le!!!" << endl;
				break;
			}
			if (op1 == 0)
			{
				system("CLS");
				break;
			}
		}
	}
	break;
	case 3:
	{
		int op1;
		while (true)
		{
			cout << "Nhap 1 de xoa,0 de thoat:";
			cin >> op1;
			switch (op1)
			{
			case 0:
			{

			}
			break;
			case 1:
			{
				string name;
				cout << "Nhap ten tai khoan can xoa: ";
				cin.ignore();
				getline(cin, name);
				if (!libary.CheckDelAccount(name))
					cout << "Tai khoan khong ton tai!!!" << endl;
				else
				{
					cout << "Xoa thanh cong!!!" << endl;
				}
			}
			break;
			default:
				cout << "Lua chon khong hop le!!!" << endl;
				break;
			}
			if (op1 == 0)
			{
				system("CLS");
				break;
			}
		}
	}
	break;
	default:
		break;
	}
}
void Admin::AddBook(ListBook& list, Libary libary)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de them,0 de thoat: ";
		cin >> op;
		switch (op)
		{
		case 0:
			break;
		case 1:
		{
			string name, id, pub, au;
			int price;
			cout << "Nhap ten sach can them: ";
			cin.ignore();
			getline(cin, name);
			loop:cout << "Nhap ma sach can them: ";
			getline(cin, id);
			if (list.CheckExistId(id))
			{
				cout << "Ma sach da ton tai, vui long chon ma khac!!!" << endl;
				goto loop;
			}
			else
			{
				cout << "Nhap tac gia cua cuon sach can them: ";
				getline(cin, au);
				cout << "Nhap NXB cua quyen sach: ";
				getline(cin, pub);
				cout << "Nhap gia sach: ";
				cin >> price;
				Book b;
				b.SetBook(id, name, pub, au, price, 1);
				list.AddBook(b);
				cout << "Them thanh cong!!!" << endl;
			}
		}
		break;
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		if (op == 0)
		{
			system("CLS");
			break;
		}
	}
}
void Admin::FixPrice(ListBook& list)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de sua, 0 de thoat: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{

		}
		break;
		case 1:
		{
			string name;
			cout << "Nhap ten sach can sua: ";
			cin.ignore();
			getline(cin, name);
		    if (list.CountBook(name) == 0)
			{
				cout << "Khong tim thay sach." << endl;
			}
			else if (list.CountBook(name) == 1)
			{
				int price;
				cout << "Nhap gia moi: ";
				cin >> price;
				list.SetPriceAtName(name,price);
				cout << "Da sua xong!!!" << endl;
			}
			else
			{
				string id;
				cout << "Tim thay " << list.CountBook(name) << " cuon " << name << ":" << endl;
				list.OutPutSameBook(name);
				cout << "Nhap ma sach can sua: ";
				getline(cin, id);
				int price;
				cout << "Nhap gia moi: ";
				cin >> price;
				list.SetPriceAtId(id, price);
				cout << "Da sua xong!!!" << endl;
			}
		}
		break;
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		if (op == 0)
		{
			system("CLS");
			break;
		}
	}
}
void Admin::SendMessages(Libary libary)
{
	mail.SendMessages(0, accountname, libary);
}
void Admin::OpenMailBox()
{
	int op;
	mail.LoadMail(accountname);
	while (true)
	{
		cout << "Nhap 1 de xem,0 de thoat:";
		cin >> op;
		if (op == 1)
		{
			cout << "Mail da nhan:" << endl;
			mail.OpenMail();
		}
		else
			break;
	}
}
void Admin::Register(Libary libary){}
void Admin::SetNumOfBook(ListBook list){}
void Admin::OutPutBook(ListBook list){}
void Admin::PrintInfo(ListBook list){}