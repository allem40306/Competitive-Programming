#include <bits/stdc++.h>
using namespace std;

void print(long long n){
	if(!n)return;
	if(n/10000000){
		print(n/10000000);
		cout<<" kuti";
		n%=10000000;
	}
	if(n/100000){
		print(n/100000);
		cout<<" lakh";
		n%=100000;
	}
	if(n/1000){
		print(n/1000);
		cout<<" hajar";
		n%=1000;
	}
	if(n/100){
		print(n/100);
		cout<<" shata";
		n%=100;
	}
	if(n)cout<<' '<<n;
}

int main(){
	int ti=1;
	long long n;
	while(cin>>n){
		cout<<setw(4)<<ti++<<'.';
		if(n)print(n);
		else cout<<" 0";
		cout<<'\n';
	}
}