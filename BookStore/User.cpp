#include "User.h"
#include"Libary.h"
#include"ListBook.h"
void User::Register(Libary libary)
{
	cout << "Luu y !!!: Ten tai khoan va mat khau khong duoc chua ki tu dac biet." << endl;
	while (true)
	{
		try
		{
			int op;
			cout << "Nhap 1 de dang ki,0 de thoat: ";
			cin >> op;
			if (op != 1 && op != 0)
				throw - 2;
			if (op == 0)
			{
				system("CLS");
				break;
			}
			cout << "Nhap ten tai khoan: ";
			cin.ignore();
			getline(cin, accountname);
			if (accountname.substr(0, 3) == "TG-")
				throw 1;
			if (accountname.substr(0, 4) == "NXB-")
				throw 2;
			if (accountname.substr(0, 3) == "AD-")
				throw 3;
			cout << "Nhap mat khau: ";
			getline(cin, password);
			if (libary.CheckValidRegister(accountname, password) == -1)
				throw -1;
			else if (libary.CheckValidRegister(accountname, password) == 0)
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
		catch (int x)
		{
			if (x == 0)
				cout << "Ten nguoi dung da ton tai,vui long chon ten khac!!!" << endl;
			else if (x == 1)
				cout << "Ten tai khoan chi danh rieng cho Tac Gia, vui long chon ten khac!!!" << endl;
			else if (x == 2)
				cout << "Ten tai khoan chi danh rieng cho Nha Xuat Ban, vui long chon ten khac!!!" << endl;
			else if (x == 3)
				 cout << "Ten tai khoan chi danh rieng cho Admin, vui long chon ten khac!!!" << endl;
			else if (x == -1)
				cout << "Ten tai khoan hoac mat khau khong hop le!!!" << endl;
			else
				cout << "Lua chon khong hop le!!!" << endl;
		}
	}
}
void User::Login(Libary libary,int &op)
{
	while (true)
	{
		try
		{
			cout << "Nhap 1 de dang nhap,0 de thoat: ";
			cin >> op;
			if (op != 1 && op != 0)
				throw 0;
			if (op == 0)
				break;
			cout << "Nhap ten dang nhap: ";
			cin.ignore();
			getline(cin, accountname);
			if (accountname.substr(0, 3) == "TG-")
				throw 1;
			if (accountname.substr(0, 4) == "NXB-")
				throw 2;
			cout << "Nhap mat khau: ";
			getline(cin, password);
			if (libary.CheckValidUser(accountname, password) > 0)
			{
				age = libary.CheckValidUser(accountname, password);
				break;
			}
			else if (libary.CheckValidLogin(accountname, password) == 0)
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
			else if (x == 1)
				cout << "Tai khoan chi danh cho Tac Gia!!!" << endl;
			else if (x == 2)
				cout << "Tai khoan chi danh cho Nha Xuat Ban!!!" << endl;
			else
				cout << "Lua chon khong hop le!!!" << endl;
		}
	}
}
void User::BuyBook(ListBook list)
{
	int op,n=0;
	while (true)
	{
		cout << "Nhap 1 de mua, 0 de thoat:";
		cin >> op;
		switch (op)
		{
		case 0:
			break;
		case 1:
		{
			string name;
			int num;
			cout << "Nhap ten sach can mua: ";
			cin.ignore();
			getline(cin, name);
			if (list.CountBook(name) == 0)
			{
				cout << "Khong tim thay sach." << endl;
			}
			else if (list.CountBook(name) == 1)
			{
				cout << "Nhap so luong can mua: ";
				cin >> num;
				bill[n].SetNum(num);
				bill[n].AddBook(list.GetBookAtName(name), n);
			}
			else
			{
				cout << "Tim thay " << list.CountBook(name) << " cuon " << name << ":" << endl;
				list.OutPutSameBook(name);
				string ma;
				cout << "Nhap ma sach can mua: ";
				getline(cin, ma);
				cout << "Nhap so luong can mua: ";
				cin >> num;
				bill[n].SetNum(num);
				bill[n].AddBook(list.GetBookAtID(ma), n);
			}
		}
		break;
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		if (op == 0)
			break;
	}
	if (n)
	{
		int x = Discount();
		string id;
		cout << "Ban da mua:" << endl;
		bill->PrintBill(bill, n);
		cout << "Tong tien: " << bill->CalMoney(bill,n) - (bill->CalMoney(bill, n))*Discount();
		int op2;
		cout << endl;
		while (true)
		{
			cout << "Nhap 1 de xoa sach, 2 de thay doi so luong sach, 3 de them sach, 0 de in hoa don: ";
			cin >> op2;
			switch (op2)
			{
			case 0:
			{
				if (bill->EmptyBill(bill, n))
					cout << "Ban chua mua gi ca!" << endl;
				else
				{
					cout << "Hoa don cua ban: " << endl;
					bill->PrintBill(bill, n);
					int x = bill->CalMoney(bill, n) - bill->CalMoney(bill, n) * Discount();
					cout << "Tong tien phai tra: " << x << endl;
					time_t hientai = time(0);
					string ThoiGianMua = ctime(&hientai);
					cout << "Thoi gian mua: " << ThoiGianMua;
					bill->OutPutFile(bill, n, accountname,x);
				}
			}
			break;
			case 1:
			{
				UpdateBill(list, n, op2);
				cout << "Hoa don sau khi cap nhat:" << endl;
				bill->PrintBill(bill, n);
				cout << "Tong tien: " << bill->CalMoney(bill, n) - bill->CalMoney(bill, n) * Discount();
				cout << endl;
			}
			break;
			case 2:
			{
				UpdateBill(list, n, op2);
				cout << "Hoa don sau khi cap nhat:" << endl;
				bill->PrintBill(bill, n);
				cout << "Tong tien: " << bill->CalMoney(bill, n) - bill->CalMoney(bill, n) * Discount();
				cout << endl;
			}
			break;
			case 3:
			{
				UpdateBill(list, n, op2);
				cout << "Hoa don sau khi cap nhat:" << endl;
				bill->PrintBill(bill, n);
				cout << "Tong tien: " << bill->CalMoney(bill, n) - bill->CalMoney(bill, n) * Discount();
				cout << endl;
			}
			break;
			default:
				cout << "Lua chon khong hop le!" << endl;
				break;
			}
			if (op2 == 0)
			{
				break;
			}
		}
	}
}
void User::UpdateBill(ListBook list, int& n, int type)
{
	switch (type)
	{
	case 1:
	{
		string id;
		cout << "Nhap ma sach can xoa:";
		cin.ignore();
		getline(cin, id);
		bill->DelteleBook(bill, n, id);
	}
	break;
	case 2:
	{
		if (bill->EmptyBill(bill,n))
			cout << "Ban chua mua gi ca!" << endl;
		{
			string id;
			cout << "Nhap ma sach thay doi:";
			cin.ignore();
			getline(cin, id);
			if (!bill->IsBelongToBill(bill, n, id))
				cout << "Khong co cuon nao co ma " << id << " trong hoa don!" << endl;
			else
			{
				int newnum;
				cout << "Nhap so luong moi: ";
				cin >> newnum;
				for (int i = 0; i < n; i++)
				{
					if (bill[i].GetBook().GetId() == id)
					{
						bill[i].SetNum(newnum);
						break;
					}
				}
			}
		}
	}
	break;
	case 3:
	{
		string name;
		int num;
		cout << "Nhap ten sach can them: ";
		cin.ignore();
		getline(cin, name);
		if (list.CountBook(name) == 0)
		{
			cout << "Khong tim thay sach." << endl;
		}
		else if (list.CountBook(name) == 1)
		{
			cout << "Nhap so luong can mua: ";
			cin >> num;
			bill[n].SetNum(num);
			bill[n].AddBook(list.GetBookAtName(name), n);
		}
		else
		{
			cout << "Tim thay " << list.CountBook(name) << " cuon " << name << ":" << endl;
			string ma;
			cout << "Nhap ma sach can them: ";
			getline(cin, ma);
			cout << "Nhap so luong can mua: ";
			cin >> num;
			bill[n].SetNum(num);
			bill[n].AddBook(list.GetBookAtID(ma), n);
		}
	}
	break;
	default:
		break;
	}
}
void User::SendMessages(Libary libary)
{
    mail.SendMessages(1, accountname, libary);
}
void User::OpenMailBox()
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
float User::Discount()
{
	if (age <= 12)
		return 0.3;
	else
		if (age <= 18)
			return 0.2;
	return 0;
}









































































































































































































































