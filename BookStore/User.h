#ifndef LIST
#define LIST
#include"Guest.h"
#include"Bill.h"
class ListBook;
class User:public virtual Guest
{
	Bill bill[200];
	int age;
public:
	void Register(Libary libary);
	void Login(Libary libary,int &op);
	void BuyBook(ListBook list);
	void UpdateBill(ListBook list, int& n, int type);
	void SendMessages(Libary libary);
	void OpenMailBox();
	float Discount();
};
#endif

