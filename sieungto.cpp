#include<iostream>
#include<math.h>
using namespace std;

int KTNguyenTo(long long n)
{
	if(n<2) return 0;
    for(int i=2; i<=sqrt(n); i++) 
    {
        if(n%i==0) return 0;
    }
    return 1;
}
int main(){
	long long a;
	cin>>a;
	if(a<2) cout<<"NO";
	else if(KTNguyenTo(a)&&(KTNguyenTo(a%10))) cout<<"YES";
	else cout<<"NO";
	return 0;
}
