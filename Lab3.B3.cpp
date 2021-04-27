#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *pNext; 
};
typedef struct node NODE;

struct queue
{
	NODE *pHead; 
	NODE *pTail; 
};
typedef struct queue QUEUE;

void KhoiTaoQueue(QUEUE &q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

bool IsEmpty(QUEUE q)
{
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;
}
bool Push(QUEUE &q, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p;
	}
	else
	{
		q.pTail->pNext = p; 
		q.pTail = p; 
	}
	return true;
}

bool Pop(QUEUE &q, int &x) 
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE *p = q.pHead; 
		x = p->data;	
		q.pHead = q.pHead->pNext; 	
		delete p; 

	}
	return true;
}

bool Top(QUEUE &q, int &x) 
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pHead->data;
	return true;
}

void XuatQueue(QUEUE q)
{
	while (IsEmpty(q) == false)
	{
		int x;
		Pop(q, x);
		cout << x << " ";
	}

	if (IsEmpty(q) == true)
	{
		cout << "\nDANH SACH DANG RONG KIA";
	}
	else
	{
		cout << "\nDANH SACH DANG TON TAI PHAN TU";
	}
}

void NhapQueue(QUEUE &q)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\t1. Them phan tu vao queue - Push";
		cout << "\n\t2. Xuat danh sach queue ra man hinh - Pop";
		cout << "\n\t3. Xem thong tin phan tu dau queue - Top";
		cout << "\n\t0. Ket thuc";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			Push(q, p);
		}
		else if (luachon == 2)
		{
			XuatQueue(q);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			Top(q, x);
			cout << "\nPhan tu dau queue la: " << x;
			system("pause");
		}
		else
		{
			break;
		}
	}
}

int main()
{
	QUEUE q;
	KhoiTaoQueue(q);

	NhapQueue(q);

	system("pause");
	return 0;
}
