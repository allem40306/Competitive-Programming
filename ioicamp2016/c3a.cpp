#include <iostream>
#include <cassert>
#include <string>
using namespace std;
#define N 10000

int a(long long a){
	int t=0;
	while(a){
		t++;
		a/=10;
	}
	return t;
}

int b(long long b,int x){
	long long bb=b,c=0;
	while(bb>=10)bb/=10;
	while(x--)c=c*10+1;
	return bb+(c*bb<b);
}

int bb(long long b,int x){
	long long bb=b,c=0;
	while(bb>=10)bb/=10;
	while(x--)c=c*10+1;
	return bb-(c*bb>b);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long l,r;
		cin>>l>>r;
		int x1=a(l),x2=a(r);
		int y1=b(l,x1),y2=bb(r,x2);
		printf("%d\n",x2*9+y2-x1*9-y1+1);
	}
}
