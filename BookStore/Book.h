#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class Book
{
	string id;
	string name;
	string publisher;
	string author;
	int price;
	int isDel;
public:
	void OutPut();
	void OutPutFile(ofstream &f);
	void SetBook(string _id, string _name, string _publisher, string _author, int _price,int _mode);
	void SetMode(int _mode);
	void SetPrice(int _price);
	string GetId();
	string GetName();
	string GetAuthor();
	string GetPublisher();
	int GetPrice();
	int GetMode();
};

