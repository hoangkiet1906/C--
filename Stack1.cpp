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


int main()
{
	STACK s;
	KhoiTaoStack(s);
	char str[10];
	cin>>str;
	int len = strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]=='+'){
			NODE *p = KhoiTaoNode(str[i]);
			Push(s, p);
		}
	}
	cout<<"Hau to : ";
	for(int i=0;i<len;i++){
		if(str[i]!='+'){
			cout<<str[i];
		}
	}
	char x[1];
	if (Top(s, *x))
	cout<<x[0]<<endl;
	cout<<"Tien to : ";
	cout<<x[0];
	for(int i=0;i<len;i++){
		if(str[i]!='+'){
			cout<<str[i];
		}
	}
	cout<<endl;
	cout<<"Nhap bieu thuc tinh toan : ";
	char tt[3];
	cin>>tt;
	int a;
	a = (int)tt[0]-48;
	int b;
	b = (int)tt[2]-48;
	int c=a+b;
	cout<<tt<<"="<<c;
	cout<<endl;
	system("pause");
	return 0;
}






