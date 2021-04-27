#include<iostream>
#include<math.h>
using namespace std ;
int main(){
	long long tong,hieu;
	cin>>tong;
	cin>>hieu;
	if(hieu>=0){
		int tmp = (tong+abs(hieu))/2;
		cout<<tmp<<endl;
		cout<<tong-tmp;
	}
	else{
		int tmp = (tong+abs(hieu))/2;
		cout<<tong-tmp<<endl;
		cout<<tmp;
	}
}
