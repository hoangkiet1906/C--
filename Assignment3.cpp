#include<iostream>

using namespace std;

void view(int a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

void swap(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void BubbleSo(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1]) swap(a[j],a[j-1]);
		}
	}
}
void InsertionSo(int a[],int n){
	for(int i=1;i<n;i++){
		int tmp = a[i];
		int j = i-1;
		while(j>=0&&tmp<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=tmp;
	}
}
void SelectionSo(int a[],int n){
	for(int i=0;i<n-1;i++){
		int min = a[i];
		int min_pos = i;
		for(int j=i+i;j<n;j++)
			if(a[j]<min){
				min = a[j];
				min_pos = j;
			}
		swap(a[i],a[min_pos]);
	}
}
int main(){
	int a[10] {10, 8, 2, 7, 3, 4, 9, 1, 6, 5};
	int n=10;
	cout<<"BubbleSort"<<endl;
	BubbleSo(a,n); view(a,n);
	cout<<endl;
	cout<<"InsertionSort"<<endl;
	InsertionSo(a,n); view(a,n);
	cout<<endl;
	cout<<"SelectionSort"<<endl;
	SelectionSo(a,n); view(a,n);
	return 0;
}
