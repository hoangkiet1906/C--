#include<iostream>
#include<string.h>
using namespace std;
struct STUDENT 
{ 
	char name[30]; 
	char clas[10]; 
	float mMath; 
	float mPhysical;
	float avg; 
}; 
void createArr(struct STUDENT a[], int &n){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].name;
		cin>>a[i].clas;
		cin>>a[i].mMath;
		cin>>a[i].mPhysical;
		cin>>a[i].avg;
	}		
}
void add(struct STUDENT a[], int &n, struct STUDENT tmp){
	
	cout<<"Nhap STUDENT can add : "<<endl;
		cin>>tmp.name;
		cin>>tmp.clas;
		cin>>tmp.mMath;
		cin>>tmp.mPhysical;
		cin>>tmp.avg;
	a[n]=tmp;n++;
}
void search(struct STUDENT a[], int n, char ten[]){
	cout<<"Nhap ten can tim : "; 
	cin>>ten;
	for(int i=0;i<n;i++){
		if(strcmp(a[i].name,ten)== 0){
			cout<<"Thong tin hoc sinh : "<<i<<endl;
			cout<<a[i].name<<endl;
			cout<<a[i].clas<<endl;
			cout<<a[i].mMath<<endl;
			cout<<a[i].mPhysical<<endl;
			cout<<a[i].avg<<endl;
		}
	}
}
void view(struct STUDENT a[], int n){
	for(int i=0;i<n;i++){
		cout<<"Thong tin hoc sinh : "<<i<<endl;
		cout<<a[i].name<<endl;
		cout<<a[i].clas<<endl;
		cout<<a[i].mMath<<endl;
		cout<<a[i].mPhysical<<endl;
		cout<<a[i].avg<<endl;
	}
}
void swap(struct STUDENT &a,struct STUDENT &b){
	struct STUDENT tmp = a;
	a = b;
	b = tmp;
}
void BubbleSo(struct STUDENT a[],int n){
	cout<<"Sap xep giam dan theo AVG "<<endl;
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(a[j].avg>a[j-1].avg) swap(a[j],a[j-1]);
		}
	}
}
int main(){
	struct STUDENT a[100];
	int n;
	createArr(a,n);
	struct STUDENT tmp;
	add(a,n,tmp);
	
	char ten[50];
	search(a,n,ten);
	BubbleSo(a,n);
	view(a,n);
	return 0;
}
