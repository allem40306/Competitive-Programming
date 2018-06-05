#include <iostream>
#include <cmath>
using namespace std;
#define R(a) (a+4)%4
int main(){
	unsigned long long n,x,a[4]={},ans=0;
	cin>>n;
	for(unsigned long long i=0;i<n;i++){
		cin>>x;
		a[i%4]=x+max(a[R(i%4-2)],a[R(i%4-3)]);
	}
	for(unsigned long long i=0;i<4;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans<<'\n';
}
