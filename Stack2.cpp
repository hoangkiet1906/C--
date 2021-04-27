#include<iostream>
using namespace std;
struct Note{
	int data;
	Note *next;
};
typedef Note* Top;
void PUSH(int x, Top &Stack){
	Top p = new (Note);
	p->data = x;
	p->next = Stack;
	Stack = p;
}
int POP(Top &Stack){
	Top p = Stack;
	Stack = Stack->next;
	int x = p->data;
	delete(p);
	return x;
}
void Bin(int n){
	Top Stack = NULL;
	while(n>0){
		PUSH(n%2,Stack);
		n/=2;
	}
	while(Stack){
		int x= POP(Stack);
		cout<<x;
	}
}
int main(){
	int n;
	cin>>n;
	Bin(n);
}
