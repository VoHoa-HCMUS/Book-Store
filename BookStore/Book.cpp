#include "Book.h"
#include<fstream>
void Book::SetBook(string _id, string _name, string _publisher, string _author, int _price,int _mode)
{
	id = _id;
	name = _name;
	publisher = _publisher;
	author = _author;
	price = _price;
	isDel = _mode;
}
string Book::GetId()
{
	return id;
}
string Book::GetName()
{
	return name;
}
string Book::GetAuthor()
{
	return author;
}
string Book::GetPublisher()
{
	return publisher;
}
int Book::GetPrice()
{
	return price;
}
int Book::GetMode()
{
	return isDel;
}
void Book::SetMode(int _mode)
{
	isDel = _mode;
}
void Book::OutPut()
{
	cout << left << setw(5) << id << setw(20) << name << setw(30) << publisher << setw(40) << author<< price << endl;
}
void Book::SetPrice(int _price)
{
	price = _price;
}
void Book::OutPutFile(ofstream& f)
{
	f << left << setw(5) << id << setw(20) << name << setw(30) << publisher << setw(40) << author << price << endl;
}