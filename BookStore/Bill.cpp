#include "Bill.h"
#include<iomanip>
#include<fstream>
int Bill::CalMoney(Bill bill[],int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += bill[i].book.GetPrice() * num;
	}
	return sum;
}
void Bill::AddBook(Book b,int& n)
{
	book.SetBook(b.GetId(), b.GetName(), b.GetPublisher(), b.GetAuthor(), b.GetPrice(),1);
	n++;
}
void Bill::SetNum(int _num)
{
	num = _num;
}
void Bill::PrintBill(Bill bill[], int n)
{
	cout << left << setw(5) << "STT" << setw(5) << "SL" << setw(5) << "Ma" << setw(20) << "Ten" << setw(30) << "NXB" << setw(40) << "TacGia" << "Gia" << endl;
	int j = 1;
	for (int i = 0; i < n; i++)
	{
		if (bill[i].book.GetId() != "")
		{
			cout << left << setw(5) << j;
			cout << left << setw(5) << bill[i].num;
			bill[i].book.OutPut();
			j++;
		}
	}
}
void Bill::DelteleBook(Bill bill[], int n, string id)
{
	for (int i = 0; i < n; i++)
	{
		if (bill[i].book.GetId() == id)
		{
			bill[i].num=0;
			bill[i].book.~Book();
		}
	}
}
bool Bill::EmptyBill(Bill bill[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (bill[i].book.GetId() != "")
			return false;
	}
	return true;
}
bool Bill::IsBelongToBill(Bill bill[], int n, string id)
{
	for (int i = 0; i < n; i++)
	{
		if (bill[i].book.GetId() == id)
			return true;
	}
	return false;
}
void Bill::OutPutFile(Bill bill[], int n,string name,int x)
{
	ofstream fileout;
	fileout.open("Bill/"+name + ".txt",ios::app);
	fileout << left << setw(5) << "STT" << setw(5) << "SL" << setw(5) << "Ma" << setw(20) << "Ten" << setw(30) << "NXB" << setw(40) << "TacGia" << "Gia" << endl;
	int j = 1;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (bill[i].book.GetId() != "")
		{
			fileout << left << setw(5) << j;
			fileout << left << setw(5) << bill[i].num;
			bill[i].book.OutPutFile(fileout);
			j++;
		}
	}
	fileout << "Tong tien: " << x << endl;
	time_t hientai = time(0);
	string ThoiGianMua = ctime(&hientai);
	fileout << "Thoi gian mua: " << ThoiGianMua;
	fileout.close();
}
Book Bill::GetBook()
{
	return book;
}

