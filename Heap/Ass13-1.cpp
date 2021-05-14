#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int A[], int n, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int large = i;
    if(l < n && A[l] > A[i])
        large = l;
    if(r < n && A[r] > A[large])
        large = r;
    if(large != i){
        swap(A[i], A[large]);
        heapify(A, n, large);
    }
}

void buildHeap(int A[], int n){
    for(int i=(n/2)-1;i>=0;i--)
        heapify(A, n, i);
}

int main() {
    int n, a=0;
    cout<<"Nhap n = ";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        {
        	cout<<"them phtu : ";
		cin>>A[i];}
    buildHeap(A, n);
    cout<<"Tao Heap"<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" "; 
	return 0;
}
