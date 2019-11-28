#pragma once
#include"Publisher.h"
#include"Author.h"
#include"User.h"
class Admin:public Publisher,public Author,public User
{
public:
    void Register(Libary libary);
	void Login(Libary libary, int& op);
	void BuyBook(ListBook list);
	void DeleteBook(ListBook& list, Libary libary);
	void DeleteAuthor(ListBook& list, Libary libary);
	void DeletePublisher(ListBook& list, Libary libary);
	void DeleteAccount(Libary libary,int op);
	void AddBook(ListBook& list, Libary libary);
	void FixPrice(ListBook& list);
	void SetNumOfBook(ListBook list);
	void OutPutBook(ListBook list);
	void PrintInfo(ListBook list);
	void SendMessages(Libary libary);
	void OpenMailBox();
};

