#include<iostream>
using namespace std;

void view(int a[], int n){
	cout<<"Sau khi sap xep : ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
void LinearSe(int a[], int n,int tmp){
	int start = 0;
	int end = n-1;
	while(start<=end){
		int mid = (start+end)/2;
		if(tmp==a[mid]){
			cout<<"LinearSearch: vi tri thu : "<<mid<<endl;
			break;
		}
		else
		if(tmp>a[mid]){
			start=mid+1;
		}
		else
		if(tmp<a[mid]){
			end=mid-1;
		}
		if(start>end) cout<<"LinearSearch : Ko co"<<endl;	
	}	
}
int main(){
	int a[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n=10;

	cout<<endl;

	LinearSe(a,n,4);
	return 0;
}
