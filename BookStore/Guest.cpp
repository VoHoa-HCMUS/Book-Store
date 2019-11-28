#include "Guest.h"
#include"Libary.h"
#include"ListBook.h"
void Guest::FindBook(ListBook list)
{
	while (true)
	{
		int op;
		cout << "Nhap 1 de bat dau tim, 0 de thoat: ";
		cin >> op;
		switch (op)
		{
		case 0:
			break;
		case 1:
		{
			string s;
			cout << "Nhap ten sach can tim: ";
			cin.ignore();
			getline(cin, s);
			if (list.CountBook(s) == 0)
			{
				cout << "Khong tim thay sach." << endl;
			}
			else if (list.CountBook(s) == 1)
			{
				cout << "Tim thay 1 cuon " << s << ":" << endl;
				list.GetBookAtName(s).OutPut();
			}
			else
			{
				string id;
				cout << "Tim thay " << list.CountBook(s) << " cuon " << s << ":" << endl;
				list.OutPutSameBook(s);
				cout << "Nhap ma sach can tim: ";
				getline(cin, id);
				list.SearchBookAtId(id);
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
void Guest::DeleteBook(ListBook& list, Libary libary) {};
void Guest::AddBook(ListBook& list, Libary libary) {};
void Guest::FixPrice(ListBook& list) {};
void Guest::SetNumOfBook(ListBook list) {};
void Guest::OutPutBook(ListBook list) {};
void Guest::PrintInfo(ListBook list) {};
void Guest::Register(Libary libary) {}
void Guest::Login(Libary libary, int& op) {}
void Guest::BuyBook(ListBook list) {};
void Guest::DeleteAuthor(ListBook& list, Libary libary){}
void Guest::DeletePublisher(ListBook& list, Libary libary){}
void Guest::DeleteAccount(Libary libary, int op){}
void Guest::SendMessages(Libary libary){}
void Guest::OpenMailBox(){}