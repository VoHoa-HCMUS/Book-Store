#pragma once
#include"Book.h"
#include<vector>
#include<fstream>
class ListBook
{
	vector<Book> book;
public:
	void Input(Book _book);
	void OutPut();
	int CountBook(string name);
	int CountBookAs(int type, string x);
	Book GetBookAtName(string name);
	Book GetBookAtName(int type, string name,string pub);
	Book GetBookAtID(int type,string id,string pub);
	Book GetBookAtID(string id);
	void SetPriceAtName(string name,int _price);
	void SetPriceAtId(string id,int _price);
	void OutPutSameBook(string name);
	void SearchBookAtId(string id);
	void DelBookAtName(string name);
	void DelBookAtId(string id);
	bool DelAuthorBook(string au);
	bool DelPublisherBook(string pub);
	bool CheckBookBelong(int type,string name, string x);
	bool CheckExistId(string id);
	int CountBook(int type, string name,string x);
	void OutPutSameBook(int type, string name, string x);
	void AddBook(Book b);
	void UpdateDeleteBook(int type, Book b,int newmode);
	void OutPutAs(int type, string x);
	void OutPutFile(ofstream& booksfile);
};

