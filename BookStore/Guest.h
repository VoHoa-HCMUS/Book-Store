#ifndef LIB
#define LIB
#include<string>
#include<iostream>
#include"ListBook.h"
#include"MailBox.h"
using namespace std;
class Libary;
class Guest
{
protected:
	string accountname;
	string password;
	MailBox mail;
public:
	virtual void Register(Libary libary);
	virtual void Login(Libary libary,int &op);
	virtual void BuyBook(ListBook list);
	virtual void DeleteBook(ListBook& list, Libary libary);
	virtual void AddBook(ListBook& list, Libary libary);
	virtual void FixPrice(ListBook& list);
	virtual void DeleteAuthor(ListBook& list, Libary libary);
	virtual void DeletePublisher(ListBook& list, Libary libary);
	virtual void DeleteAccount(Libary libary, int op);
    void FindBook(ListBook list);
	virtual void SetNumOfBook(ListBook list);
	virtual void OutPutBook(ListBook list);
	virtual void PrintInfo(ListBook list);
	virtual void SendMessages(Libary libary);
	virtual void OpenMailBox();
};
#endif

