#pragma once
#include"Book.h"
#include<vector>
class Bill
{
	Book book;
	int num;
	int price;
public:
	int CalMoney(Bill bill[], int n);
	void AddBook(Book b, int& n);
	void SetNum(int _num);
	void PrintBill(Bill bill[], int n);
	void DelteleBook(Bill bill[], int n, string id);
	bool EmptyBill(Bill bill[], int n);
	bool IsBelongToBill(Bill bill[], int n, string id);
	void OutPutFile(Bill bill[], int n,string name,int x);
	Book GetBook();
};

