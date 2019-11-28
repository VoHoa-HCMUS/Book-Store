#pragma once
#include"Guest.h"
class Author:public virtual Guest
{
	int numofbook;
public:
	void Register(Libary libary);
	void Login(Libary libary, int& op);
	void DeleteBook(ListBook& list, Libary libary);
	void AddBook(ListBook& list, Libary libary);
	void FixPrice(ListBook& list);
	void PrintInfo(ListBook list);
	void SetNumOfBook(ListBook list);
	void OutPutBook(ListBook list);
	void SendMessages(Libary libary);
	void OpenMailBox();
	string GetAuName();
};

