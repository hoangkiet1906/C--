#include<iostream>
using namespace std;

void view(int a[], int n){
	cout<<"Sau khi sap xep : ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
void BinarySe(int a[], int n, int tmp){
	for(int i=0;i<n;i++){
		if(tmp==a[i]){
			cout<<"BinarySearch : vi tri thu : "<<i<<endl;
			break;
		}
		if(i==n-1) cout<<"BinarySearch : Ko co"<<endl;
	}
}
int main(){
	int a[10]{10, 8, 2, 7, 3, 4, 9, 1, 6, 5};
	int n=10;

	cout<<endl;

	BinarySe(a,n,4);
	return 0;
}
