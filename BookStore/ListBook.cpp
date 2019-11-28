#include "ListBook.h"
#include"Libary.h"
void ListBook::Input(Book _book)
{
	book.push_back(_book);
}
void ListBook::OutPut()
{
	int j = 1;
	cout << left << setw(5) << "STT" << setw(5) << "Ma" << setw(20) << "Ten" << setw(30) << "NXB" << setw(40) << "TacGia" << "Gia" << endl;
	for (int i = 0; i < book.size(); i++)
	{
		cout << left << setw(5) << j;
		book[i].OutPut();
		j++;
	}
}
int ListBook::CountBook(string name)
{
	int count = 0;
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetName() == name)
			count++;
	}
	return count;
}
Book ListBook::GetBookAtName(string name)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetName() == name)
			return book[i];
	}
}
Book ListBook::GetBookAtID(string id)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetId() == id)
			return book[i];
	}
}
void ListBook::SearchBookAtId(string id)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetId() == id)
		{
			cout << "Tim thay cuon co ma "<<id<<":" << endl;
			book[i].OutPut();
			return;
		}
	}
	cout << "Khong tim thay cuon co ma " << id << endl;
}
void ListBook::OutPutSameBook(string name)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetName() == name)
			book[i].OutPut();
	}
}
void ListBook::OutPutFile(ofstream& booksfile)
{
	for (int i = 0; i < book.size(); i++)
	{
		booksfile << book[i].GetId() << "," << book[i].GetName() << "," << book[i].GetPublisher() << "," << book[i].GetAuthor() << "," << book[i].GetPrice() << "," << book[i].GetMode();
		booksfile << '\n';
	}
}
void ListBook::AddBook(Book b)
{
	book.push_back(b);
}
bool ListBook::CheckBookBelong(int type,string id, string x)
{
	if (type == 1)
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetId() == id && book[i].GetPublisher() == x&&book[i].GetMode())
				return true;
		}
		return false;
	}
	else
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetId() == id && book[i].GetAuthor() == x && book[i].GetMode())
				return true;
		}
		return false;
	}
}
int ListBook::CountBook(int type, string name,string x)
{
	if (type == 1)
	{
		int count = 0;
		for (int i = 0; i < book.size(); i++)
			if (book[i].GetPublisher() == x && book[i].GetName() == name && book[i].GetMode())
				count++;
		return count;
	}
	else
	{
		int count = 0;
		for (int i = 0; i < book.size(); i++)
			if (book[i].GetAuthor() == x && book[i].GetName() == name && book[i].GetMode())
				count++;
		return count;
	}
}
void ListBook::OutPutSameBook(int type, string name, string x)
{
	if (type == 1)
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetPublisher() == x && book[i].GetName() == name && book[i].GetMode())
			{
				book[i].OutPut();
			}
		}
	}
	else
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetAuthor() == x && book[i].GetName() == name && book[i].GetMode())
			{
				book[i].OutPut();
			}
		}
	}
}
Book ListBook::GetBookAtName(int type, string name,string x)
{
	if (type == 1)
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetPublisher() == x && book[i].GetName() == name && book[i].GetMode())
			{
				return book[i];
			}
		}
	}
	else
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetAuthor() == x && book[i].GetName() == name && book[i].GetMode())
			{
				return book[i];
			}
		}
	}
}
Book ListBook::GetBookAtID(int type, string id,string x)
{
	if (type == 1)
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetPublisher() == x && book[i].GetId() == id && book[i].GetMode())
			{
				return book[i];
			}
		}
	}
	else
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetAuthor() == x && book[i].GetId() == id && book[i].GetMode())
			{
				return book[i];
			}
		}
	}
}
void ListBook::UpdateDeleteBook(int type, Book b, int newmode)
{
	if (type == 1)
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetPublisher() == b.GetPublisher()&& book[i].GetId() == b.GetId())
			{
				book[i].SetMode(newmode);
			}
		}
	}
	else
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetAuthor() == b.GetAuthor() && book[i].GetId() == b.GetId())
			{
				book[i].SetMode(newmode);
			}
		}
	}
}
void ListBook::OutPutAs(int type, string x)
{
	if (type == 1)
	{
		int j = 1;
		cout << left << setw(5) << "STT" << setw(5) << "Ma" << setw(20) << "Ten" << setw(30) << "NXB" << setw(40) << "TacGia" << "Gia" << endl;
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetPublisher() == x && book[i].GetMode() == 0)
					continue;
			else
			{
				cout << left << setw(5) << j;
				book[i].OutPut();
				j++;
			}
		}
	}
	else
	{
		int j = 1;
		cout << left << setw(5) << "STT" << setw(5) << "Ma" << setw(20) << "Ten" << setw(30) << "NXB" << setw(40) << "TacGia" << "Gia" << endl;
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetAuthor() == x && book[i].GetMode() == 0)
				continue;
			else
			{
				cout << left << setw(5) << j;
				book[i].OutPut();
				j++;
			}
		}
	}
}
int ListBook::CountBookAs(int type, string x)
{
	int count = 0;
	if (type == 1)
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetPublisher() == x && book[i].GetMode())
				count++;
		}
		return count;
	}
	else
	{
        for (int i = 0; i < book.size(); i++)
		{
			if (book[i].GetAuthor() == x && book[i].GetMode())
				count++;
		}
		return count;
	}
}
void ListBook::DelBookAtName(string name)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetName() == name)
		{
			book.erase(book.begin() + i);
			return;
		}
	}
}
void ListBook::DelBookAtId(string id)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetId() == id)
		{
			book.erase(book.begin() + i);
			return;
		}
	}
}
bool ListBook::DelAuthorBook(string au)
{
	int count = 0;
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetAuthor() == au)
		{
			book.erase(book.begin() + i);
			count++;
		}
	}
	return count > 0;
}
bool ListBook::DelPublisherBook(string pub)
{
	int count = 0;
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetPublisher() == pub)
		{
			book.erase(book.begin() + i);
			count++;
		}
	}
	return count > 0;
}
void ListBook::SetPriceAtName(string name,int _price)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetName() == name)
		{
			book[i].SetPrice(_price);
			return;
		}
	}
}
void ListBook::SetPriceAtId(string id,int _price)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetId() == id)
		{
			book[i].SetPrice(_price);
			return;
		}
	}
}
bool ListBook::CheckExistId(string id)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].GetId() == id)
		{
			return true;
		}
	}
	return false;
}