#include<iostream>
#include<string.h>
#include <cstdlib>
using namespace std;

struct node
{
	char data; 
	struct node *pNext; 
};
typedef struct node NODE;

struct stack
{
	NODE *pTop; 
};
typedef struct stack STACK;

void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

NODE *KhoiTaoNode(char x)
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

bool IsEmpty(STACK s)
{
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;
}

bool Push(STACK &s, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	if (IsEmpty(s) == true)
	{
		s.pTop = p; 
	}
	else 
	{
		p->pNext = s.pTop; 
		s.pTop = p; 
	}
	return true;
}

bool Top(STACK &s, char &x) 
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data; 
	return true;
}
bool Pop(STACK &s, char &x) 
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *p = s.pTop;
		x = p->data; 
		s.pTop = s.pTop->pNext; 	
		delete p; 	
	}
}
int main(){
	STACK s;
	KhoiTaoStack(s);
	char str[10];
	cout<<"Nhap chuoi : ";
	cin>>str;
	int len = strlen(str);
	for(int i=0;i<len;i++){
			NODE *p = KhoiTaoNode(str[i]);
			Push(s, p);
	}
	cout<<"Chuoi moi : ";
	char x[1];
	while (Top(s, *x)){
		cout<<x[0];
		Pop(s,*x);
	}
	cout<<endl;
	system("pause");
	return 0;
}






