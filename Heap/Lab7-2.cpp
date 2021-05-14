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
void sinkDown(int k, int mH[], int num){
	int lest = k;
	if(2*k<num && mH[2*k]>mH[lest]) 
		lest = 2*k;
	if(2*k+1<num && mH[2*k+1]>mH[lest]) 
		lest = 2*k+1;
	if(lest != k){
		swap(mH[lest],mH[k]);
		sinkDown(lest,mH,num);
	}
}

int extracMin(int mH[], int &num){
	int max = mH[1];
	mH[1]=mH[num-1];
	num--;
	sinkDown(1,mH, num);
	return max;
}




void heapSort(int A[], int n){
    
    for(int i=n-1;i>=0;i--){
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
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
    cout<<"\n";
//    cout<<"Xoa root la : "<<extracMin(A,a);
//    cout<<endl;
//    
//	for(int i=0;i<n;i++)
//        cout<<A[i]<<" ";
    
    heapSort(A, n);
	cout<<"HeapSort"<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<"\n";
	return 0;
}
