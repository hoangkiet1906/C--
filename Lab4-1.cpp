#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
void createArr(int a[], int &n){
	cout<<"Nhap so phtu de Random : ";
	cin>>n;
	for(int i=0;i<n;i++) 
		a[i]=random(1,1000);
}
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
void LinearSeRecursive(int a[],int begin,int end,int tmp){
	if(begin > end){
		cout<<"Ko co"<<endl;
		return;
	}
	else{
		int mid = (begin+end)/2;
		if(a[mid]==tmp){
			cout<<"vi tri thu : "<<mid<<endl;
			return;
		}
		else{
			if(tmp>a[mid]){
				return LinearSeRecursive(a,mid+1,end,tmp);
			}
			else
				return LinearSeRecursive(a,begin,mid-1,tmp);
		}
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
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi + 1, high);
    }
}
int main(){
	int a[1000];
	int n;
	createArr(a,n);
//	BubbleSo(a,n);
//	InsertionSo(a,n);
//	SelectionSo(a,n);
	QuickSort(a,0,n-1);	
	view(a,n);
	int tmp;
	cout<<endl;
	cout<<"Nhap tmp can tim : "; cin>>tmp;
	BinarySe(a,n,tmp);
	LinearSe(a,n,tmp);
//	LinearSeRecursive(a,0,n-1,tmp);
	return 0;
}
