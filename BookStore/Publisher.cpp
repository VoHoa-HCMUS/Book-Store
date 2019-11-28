#include "Publisher.h"
#include"Libary.h"
void Publisher::Register(Libary libary)
{
	cout << "Luu y !!!: Ten tai khoan va mat khau khong duoc chua ki tu dac biet." << endl;
	while (true)
	{
		try
		{
			int op;
			cout << "Nhap 1 de dang ki,0 de thoat:";
			cin >> op;
			if (op != 1 && op != 0)
				throw - 1;
			if (op == 0)
			{
				system("CLS");
				break;
			}
			cout << "Nhap ten dang nhap(co dang NXB-Ten Nha Xuat Ban): ";
			cin.clear();
			cin.ignore();
			getline(cin, accountname);
			cout << "Nhap mat khau: ";
			getline(cin, password);
			if (accountname.substr(0,4)!="NXB-"||libary.CheckValidRegister(accountname,password)==-1)
				throw false;
			if (libary.CheckValidRegister(accountname, password) == 0)
				throw 0;
			else
			{
				libary.OverWriteAccount(accountname, password);
				cout << "Dang ki thanh cong!!!";
				Sleep(500);
				system("CLS");
				break;
			}

		}
		catch (bool)
		{
			cout << "Ten tai khoan hoac mat khau khong hop le!" << endl;
		}
		catch (int x)
		{
			if (x == -1)
				cout << "Lua chon khong hop le!!!" << endl;
			else
				cout << "Ten nguoi dung da ton tai,vui long chon ten khac!!!" << endl;
		}
	}
}
void Publisher::Login(Libary libary, int& op)
{
	cin.ignore();
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
			cout << "Nhap ten dang nhap(co dang NXB-Ten Nha Xuat Ban): ";
			cin.clear();
			cin.ignore();
			getline(cin, accountname);
			if (accountname.substr(0,4)!="NXB-")
				throw false;
			else
			{
				cout << "Nhap mat khau: ";
				getline(cin, password);
			}
			if (libary.CheckValidLogin(accountname, password) == 0)
				throw 0;
			else if (libary.CheckValidRegister(accountname, password) == -1)
				throw - 1;
			else
				break;
		}
		catch (bool)
		{
			cout << "Ten tai khoan khong hop le!" << endl;
		}
		catch (int x)
		{
			if (x == 0)
				cout << "Ten dang nhap hoac mat khau sai!!!" << endl;
			else if (x == -1)
				cout << "Tai khoan khong ton tai!!!" << endl;
			else
				cout << "Lua chon khong hop le!!!" << endl;
		}
	}
}
void Publisher::AddBook(ListBook& list,Libary libary)
{
	while (true)
	{
		int op;
		cout << "Nhap 1 de them,0 de thoat: ";
		cin >> op;
		switch (op)
		{
		case 0:
			break;
		case 1:
		{
			string name, id, au;
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
				cout << "Nhap tac gia cua quyen sach: ";
				getline(cin, au);
				cout << "Nhap gia sach: ";
				cin >> price;
				cout << "Thu vien sau khi them cuon sach cua ban." << endl;
				Book b;
				b.SetBook(id, name, GetPubName(), au, price, 1);
				list.AddBook(b);
				list.OutPut();
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
string Publisher::GetPubName()
{
	return(accountname.substr(4, accountname.length()));
}
void Publisher::FixPrice(ListBook& list)
{

}
void Publisher::DeleteBook(ListBook& list,Libary libary)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de xoa, 0 de thoat:";
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
			if (list.CountBook(1,name,GetPubName())==0)
				cout << "Khong tim thay cuon sach nao co ten " <<name<<" thuoc ve ban"<< endl;
			else if (list.CountBook(1, name, GetPubName()) ==1)
			{
				list.UpdateDeleteBook(1, list.GetBookAtName(1, name, GetPubName()), 0);
				cout << "Xoa thanh cong !!!" << endl;
			}
			else
			{
				cout << "Tim thay " << list.CountBook(1, name, GetPubName()) << " cuon " << name << ":" << endl;
				list.OutPutSameBook(1, name, GetPubName());
				string id;
				cout << "Nhap ma sach can xoa: ";
				cin.ignore();
				getline(cin, id);
				list.UpdateDeleteBook(1, list.GetBookAtID(1, id, GetPubName()), 0);
				cout << "Xoa thanh cong !!!" << endl;
			}
		}
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
void Publisher::OutPutBook(ListBook list)
{
	list.OutPutAs(1, GetPubName());
}
void Publisher::SetNumOfBook(ListBook list)
{
	numofbook=list.CountBookAs(1, GetPubName());
}
void Publisher::PrintInfo(ListBook list)
{
	SetNumOfBook(list);
	cout << "Ten NXB: " << GetPubName() << endl;
	cout << "So luong sach trong cua hang: " << numofbook << endl;
}
void Publisher::SendMessages(Libary libary)
{
	mail.SendMessages(1, accountname, libary);
}
void Publisher::OpenMailBox()
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